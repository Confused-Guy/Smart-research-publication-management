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

    void on_backHome_clicked();

    void on_collab_clicked();



    void on_profile_clicked();

    void on_login_clicked();
    void on_cancelBtnFor_clicked();
    void on_searchUserBTN_clicked();
    void on_userSearchBackBTN_clicked();

    void on_publication_clicked();


    void on_Research_clicked();


    void on_mkUser_clicked();

    void toggleDarkMode();

    void on_modeSwitch_clicked(){ toggleDarkMode();}

    void on_temp_clicked();
    void on_temp2_clicked();

    void on_cancelBtnReg_clicked();

    void on_linkFor_linkActivated();

    void on_Browse_pressed();

    //************CONFERENCE START***************************//
    void on_addConferenceBtn_clicked();
    void      on_saveConfBtn_clicked();
    void    on_cancelConfBtn_clicked();
    void      on_sortConfBtn_clicked();
    void    on_searchConfBtn_clicked();
    void     on_confStatsBtn_clicked();
    void  on_viewCalendarBtn_clicked();

    void  on_conf_clicked();

    //************CONFERENCE END***************************//

    //************Reveiw Start***************************//

    void on_exportPDF_clicked();

    void  on_reveiw_clicked();

    //************Reveiw Start***************************//





private:
    Ui::MainWindow *ui;
    bool mode;

    //************CONFERENCE START***************************//
    //Variables
    int editingConferenceId = -1;
    bool sortAscending = true;

    //Functions
    void showConferenceStats();
    void showConferenceCalendar();
    void showConferenceMap(const QString& location,
                           const QString& title);
    void loadConferences(bool ascending = true,
                         QString searchFilter = "");
    void exportConferencePDF(int id,
                             const QString& title,
                             const QDate& date,
                             const QString& location,
                             double price);
    //************CONFERENCE END***************************//
};
#endif // MAINWINDOW_H
