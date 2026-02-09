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

    void on_quit_clicked();

    void on_reveiw1_clicked();
    void on_reveiw2_clicked();
    void on_reveiw3_clicked();
    void on_reveiw4_clicked();

    void on_profile1_clicked();
    void on_profile2_clicked();
    void on_profile3_clicked();
    void on_profile4_clicked();

    void on_homeButton_clicked();
    void on_homeButton2_clicked();
    void on_homeButton3_clicked();
    void on_homeButton4_clicked();

    void on_temp_clicked();


    void on_Browse_pressed();

    void on_addConferenceBtn_clicked();

    void toggleDarkMode();

    void on_modeSwitch_clicked(){ toggleDarkMode();}
    void on_modeSwitch2_clicked(){ toggleDarkMode();}
    void on_modeSwitch3_clicked(){ toggleDarkMode();}
    void on_modeSwitch4_clicked(){ toggleDarkMode();}




private:
    Ui::MainWindow *ui;
    bool mode;
};
#endif // MAINWINDOW_H
