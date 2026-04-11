#include "filepreviewdialog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QLabel>
#include <QPushButton>
#include <QFileInfo>
#include <QFile>
#include <QTextStream>
#include <QScrollArea>
#include <QMessageBox>
#include <QDebug>
#include <QDesktopServices>
#include <QUrl>
#include <QProcess>
#include <QDir>
#include <QTime>

FilePreviewDialog::FilePreviewDialog(const QString &filePath, QWidget *parent)
    : QDialog(parent), filePath(filePath), textDisplay(nullptr), statusLabel(nullptr)
{
    setWindowTitle("File Preview");
    setGeometry(100, 100, 800, 600);

    // Get file extension
    QFileInfo fileInfo(filePath);
    fileExtension = fileInfo.suffix().toLower();

    setupUI();
    loadFile();
}

FilePreviewDialog::~FilePreviewDialog()
{
}

void FilePreviewDialog::setupUI()
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Header with title and refresh button
    QHBoxLayout *headerLayout = new QHBoxLayout();
    QLabel *titleLabel = new QLabel("File Preview: " + QFileInfo(filePath).fileName());
    titleLabel->setStyleSheet("font-weight: bold; font-size: 12pt;");
    refreshBtn = new QPushButton("Refresh");
    headerLayout->addWidget(titleLabel);
    headerLayout->addStretch();
    headerLayout->addWidget(refreshBtn);
    mainLayout->addLayout(headerLayout);

    // Status label
    statusLabel = new QLabel("");
    statusLabel->setStyleSheet("color: gray; font-size: 10pt;");
    mainLayout->addWidget(statusLabel);

    // Text display
    scrollArea = new QScrollArea();
    textDisplay = new QTextEdit();
    textDisplay->setReadOnly(true);
    textDisplay->setLineWrapMode(QTextEdit::WidgetWidth);
    scrollArea->setWidget(textDisplay);
    mainLayout->addWidget(scrollArea);

    // Footer with close button
    QHBoxLayout *footerLayout = new QHBoxLayout();
    footerLayout->addStretch();
    QPushButton *closeBtn = new QPushButton("Close");
    footerLayout->addWidget(closeBtn);
    mainLayout->addLayout(footerLayout);

    connect(refreshBtn, &QPushButton::clicked, this, &FilePreviewDialog::onRefreshClicked);
    connect(closeBtn, &QPushButton::clicked, this, &QDialog::accept);
}

void FilePreviewDialog::loadFile()
{
    if (filePath.isEmpty()) {
        statusLabel->setText("No file selected.");
        textDisplay->setText("");
        return;
    }

    QFileInfo fileInfo(filePath);
    if (!fileInfo.exists()) {
        statusLabel->setText("File not found: " + filePath);
        textDisplay->setText("");
        return;
    }

    QString content;

    if (fileExtension == "txt") {
        content = loadTextFile(filePath);
        statusLabel->setText("TXT file loaded - " + QString::number(fileInfo.size() / 1024) + " KB");
    }
    else if (fileExtension == "pdf") {
        content = loadPdfFile(filePath);
        statusLabel->setText("PDF file loaded (text extraction)");
    }
    else if (fileExtension == "docx") {
        content = loadDocxFile(filePath);
        statusLabel->setText("DOCX file loaded (text extraction)");
    }
    else {
        content = "Unsupported file type: " + fileExtension.toUpper() + "\n\nSupported formats: TXT, PDF, DOCX";
        statusLabel->setText("Unsupported file type");
    }

    textDisplay->setPlainText(content);
}

QString FilePreviewDialog::loadTextFile(const QString &path)
{
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return "Error: Could not open file for reading.";
    }

    QTextStream in(&file);
    QString content = in.readAll();
    file.close();
    return content;
}

QString FilePreviewDialog::loadPdfFile(const QString &path)
{
    // For PDFs, open with system default viewer
    QUrl fileUrl = QUrl::fromLocalFile(QFileInfo(path).absoluteFilePath());
    if (QDesktopServices::openUrl(fileUrl)) {
        return "PDF File: " + QFileInfo(path).fileName() + "\n\n"
               "✓ Opening in default PDF viewer...\n\n"
               "The file has been opened in your system's default PDF viewer.\n"
               "This preview window shows that the file was successfully located and opened.";
    }
    else {
        return "PDF File: " + QFileInfo(path).fileName() + "\n\n"
               "⚠ Could not open with default viewer.\n\n"
               "The file exists but your system doesn't have a default PDF viewer configured.\n"
               "Please:\n"
               "1. Install a PDF reader (Adobe Reader, Foxit, etc.)\n"
               "2. Or manually open the file from: " + path;
    }
}

QString FilePreviewDialog::loadDocxFile(const QString &path)
{
    return extractTextFromDocx(path);
}

QString FilePreviewDialog::extractTextFromDocx(const QString &path)
{
    // DOCX files are ZIP archives - use PowerShell to extract
    QProcess process;
    process.setProcessChannelMode(QProcess::MergedChannels);
    
    // Create a non-const copy of path to avoid const issues
    QString pathCopy = path;
    QString escapedPath = pathCopy.replace("'", "''");
    QString tempDir = QDir::temp().path() + "/docx_extract_" + QString::number(QTime::currentTime().msec());
    
    // PowerShell command to extract document.xml from DOCX zip
    QString psCommand = QString(
        "[System.IO.Compression.ZipFile]::ExtractToDirectory('%1', '%2', $true); "
        "$xml = [xml](Get-Content '%2\\word\\document.xml' -Raw); "
        "$text = @(); "
        "$xml.SelectNodes('//w:t', @{w='http://schemas.openxmlformats.org/wordprocessingml/2006/main'}) | ForEach-Object { $text += $_.InnerText }; "
        "Write-Output ($text -join '')"
    ).arg(escapedPath, tempDir);
    
    process.start("powershell.exe", QStringList() << "-NoProfile" << "-Command" << psCommand);
    
    if (!process.waitForFinished(10000)) {  // 10 second timeout
        process.kill();
        qDebug() << "PowerShell DOCX extraction timeout";
        return "⚠️ DOCX Extraction Timeout\n\nThe extraction took too long.\nPlease convert to TXT format.";
    }
    
    QString output = QString::fromUtf8(process.readAllStandardOutput()).trimmed();
    int exitCode = process.exitCode();
    
    qDebug() << "PowerShell exit code:" << exitCode;
    qDebug() << "Extracted text length:" << output.length();
    
    if (exitCode != 0 || output.isEmpty()) {
        qDebug() << "DOCX extraction failed or empty result";
        return "⚠️ Could not extract text from DOCX\n\n"
               "The file may be:\n"
               "• Corrupted or invalid\n"
               "• Contains only images/tables\n"
               "• Using unusual formatting\n\n"
               "Workaround: Convert to TXT and try again";
    }
    
    return output;
}

void FilePreviewDialog::onRefreshClicked()
{
    loadFile();
}
