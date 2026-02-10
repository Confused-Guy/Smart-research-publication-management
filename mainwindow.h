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

    void on_homeButton_clicked();
    void on_homeButton2_clicked();
    void on_homeButton3_clicked();
    void on_homeButton4_clicked();
    void on_homeButton5_clicked();
    void on_homeButton6_clicked();
    void on_homeButton7_clicked();
    void on_backHome_clicked();

    void on_reveiw_clicked();
    void on_reveiw2_clicked();
    void on_reveiw3_clicked();
    void on_reveiw4_clicked();
    void on_reveiw5_clicked();
    void on_reveiw6_clicked();
    void on_reveiw7_clicked();

    void on_collab_clicked();
    void on_collab2_clicked();
    void on_collab3_clicked();
    void on_collab4_clicked();
    void on_collab5_clicked();
    void on_collab6_clicked();
    void on_collab7_clicked();

    void on_profile_clicked();
    void on_profile2_clicked();
    void on_profile3_clicked();
    void on_profile4_clicked();
    void on_profile5_clicked();
    void on_profile6_clicked();
    void on_profile7_clicked();
    void on_login_clicked();
    void on_cancelBtnFor_clicked();

    void on_conf_clicked();
    void on_conf2_clicked();
    void on_conf3_clicked();
    void on_conf4_clicked();
    void on_conf5_clicked();
    void on_conf6_clicked();
    void on_conf7_clicked();

    void on_publication_clicked();
    void on_publication2_clicked();
    void on_publication3_clicked();
    void on_publication4_clicked();
    void on_publication5_clicked();
    void on_publication6_clicked();
    void on_publication7_clicked();

    void on_Research_clicked();
    void on_Research2_clicked();
    void on_Research3_clicked();
    void on_Research4_clicked();
    void on_Research5_clicked();
    void on_Research6_clicked();
    void on_Research7_clicked();

    void on_mkUser_clicked();

    void toggleDarkMode();

    void on_modeSwitch_clicked(){ toggleDarkMode();}
    void on_modeSwitch2_clicked(){toggleDarkMode();}
    void on_modeSwitch3_clicked(){toggleDarkMode();}
    void on_modeSwitch4_clicked(){toggleDarkMode();}
    void on_modeSwitch5_clicked(){toggleDarkMode();}
    void on_modeSwitch6_clicked(){toggleDarkMode();}
    void on_modeSwitch7_clicked(){toggleDarkMode();}

    void on_temp_clicked();
    void on_temp2_clicked();

    void on_cancelBtnReg_clicked();

    void on_linkFor_linkActivated();

    void on_Browse_pressed();

    void on_addConferenceBtn_clicked();





private:
    Ui::MainWindow *ui;
    bool mode;
};
#endif // MAINWINDOW_H
