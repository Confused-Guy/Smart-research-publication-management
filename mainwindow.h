#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "collaboration.h"

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
    void      on_sortConfBtn_clicked();
    void    on_searchConfBtn_clicked();
    void     on_confStatsBtn_clicked();
    void  on_viewCalendarBtn_clicked();

    void  on_conf_clicked();

    //************CONFERENCE END***************************//

    //************Reveiw Start***************************//


    void on_review_clicked();
    void on_reviewSub_clicked();
    void on_sortReviewBtn_clicked();
    void on_searchReviewBtn_clicked();

    void loadReviews(bool Rascending, QString RsearchFilter);
    void loadReviewsReadOnly();

    //************Reveiw Start***************************//

    //***********Collabs Start*****************//

    void on_collabsList_clicked();
    void on_collaborationCreationNewButton_clicked();
    void on_collaborationCreationConfirmButton_clicked();
    void on_collaborationCreationSortSwitch_clicked();
    void on_collaborationCreationDescSwitch_clicked();
    void on_collaborationCreationCancelButton_clicked();
    void on_collabsDeleteButton_clicked();
    void on_collaborationCreationCollaborationDescriptionEdit_textChanged();
    void on_collaborationCreationCollaborationTitileEdit_textChanged();
    void on_collabsEditButton_clicked();
    void on_collabsSearchBox_textChanged();

    //***********Collabs End*******************//




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
    void showConferenceDialog(int conferenceId = -1);
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

    //************REVIEW START***************************//
    //Variables
    bool reviewSortAscending = true;

    //Functions
    void showReviewDialog(int reviewId = -1);
    void exportReviewPDF(int reviewId, const QString& reviewerName, const QDate& reviewDate,
                         int submissionId, int publicationId, const QString& comment,
                         const QString& status);

    //************REVIEW END***************************//

    //************collabs start*********//
    bool loadCollabs();
    std::vector<Collaboration> collaborations;
    //************collabs end**********//
};
#endif // MAINWINDOW_H
