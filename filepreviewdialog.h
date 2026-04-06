#ifndef FILEPREVIEWDIALOG_H
#define FILEPREVIEWDIALOG_H

#include <QDialog>
#include <QString>
#include <memory>

class QTextEdit;
class QLabel;
class QPushButton;
class QScrollArea;

class FilePreviewDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FilePreviewDialog(const QString &filePath, QWidget *parent = nullptr);
    ~FilePreviewDialog();

private slots:
    void loadFile();
    void onRefreshClicked();

private:
    QString filePath;
    QString fileExtension;
    QTextEdit *textDisplay;
    QLabel *statusLabel;
    QScrollArea *scrollArea;
    QPushButton *refreshBtn;

    // File loading helpers
    QString loadTextFile(const QString &path);
    QString loadPdfFile(const QString &path);
    QString loadDocxFile(const QString &path);
    QString extractTextFromDocx(const QString &path);
    void setupUI();
};

#endif // FILEPREVIEWDIALOG_H
