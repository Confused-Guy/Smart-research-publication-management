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
#include <QCoreApplication>

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
    // Use Python with PyMuPDF to extract PDF text
    QProcess process;
    process.setProcessChannelMode(QProcess::MergedChannels);
    
    // Get the path to the Python script (same directory as executable)
    QString scriptPath = QCoreApplication::applicationDirPath() + "/extract_pdf.py";
    
    // Run Python script
    process.start("python", QStringList() << scriptPath << path);
    
    if (!process.waitForFinished(30000)) {  // 30 second timeout
        process.kill();
        return "⚠️ PDF Extraction Timeout\n\n"
               "The extraction took too long.\n\n"
               "Make sure PyMuPDF is installed:\n"
               "pip install PyMuPDF";
    }
    
    QString output = QString::fromUtf8(process.readAllStandardOutput()).trimmed();
    int exitCode = process.exitCode();
    
    if (exitCode != 0 || output.isEmpty()) {
        QString error = QString::fromUtf8(process.readAllStandardError());
        return "⚠️ PDF Extraction Failed\n\n"
               "Make sure PyMuPDF is installed:\n"
               "pip install PyMuPDF\n\n"
               "Error: " + error;
    }
    
    return output;
}

QString FilePreviewDialog::loadDocxFile(const QString &path)
{
    return extractTextFromDocx(path);
}

QString FilePreviewDialog::extractTextFromDocx(const QString &path)
{
    // Use Python with python-docx to extract DOCX text
    QProcess process;
    process.setProcessChannelMode(QProcess::MergedChannels);
    
    // Get the path to the Python script (same directory as executable)
    QString scriptPath = QCoreApplication::applicationDirPath() + "/extract_docx.py";
    
    // Run Python script
    process.start("python", QStringList() << scriptPath << path);
    
    if (!process.waitForFinished(30000)) {  // 30 second timeout
        process.kill();
        return "⚠️ DOCX Extraction Timeout\n\n"
               "The extraction took too long.\n\n"
               "Make sure python-docx is installed:\n"
               "pip install python-docx";
    }
    
    QString output = QString::fromUtf8(process.readAllStandardOutput()).trimmed();
    int exitCode = process.exitCode();
    
    if (exitCode != 0 || output.isEmpty()) {
        QString error = QString::fromUtf8(process.readAllStandardError());
        return "⚠️ DOCX Extraction Failed\n\n"
               "Make sure python-docx is installed:\n"
               "pip install python-docx\n\n"
               "Error: " + error;
    }
    
    return output;
}

void FilePreviewDialog::onRefreshClicked()
{
    loadFile();
}
