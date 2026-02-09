#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_label_3_linkActivated(const QString &link);



    void on_verifyBtnForgot_clicked();

    void on_cancelFogotBTN_clicked();

    void on_CancelBTNCode_clicked();

    void on_cancelBTNRegister_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
