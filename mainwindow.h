#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QFileDialog>
#include "collaboration.h"
#include "publication.h"
#include "submission.h"



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

    void on_collab_clicked();

    void on_profile_clicked();


    void on_publication_clicked();


    void on_Research_clicked();



    void toggleDarkMode();

    void on_modeSwitch_clicked(){ toggleDarkMode();}

    void on_temp_clicked();



    void on_linkFor_linkActivated();

    /*************************************** USER START *************************************************************/

    void on_editUser_2_clicked();
    void on_deleteUser_2_clicked();
    void on_addUser_clicked();
    void on_login_clicked();
    void on_cancelBtnFor_clicked();
    void on_searchUserBTN_clicked();
    void on_userSearchBackBTN_2_clicked();
    void on_cancelBtnReg_clicked();
    void on_editUserPage_clicked();
    void on_cancelEditBTN_2_clicked();
    void on_backLoginBTN_2_clicked();
    void on_temp2_clicked();
    void on_mkUser_clicked();
    void on_searchString_clicked();
    void on_Viewer_checkStateChanged(const Qt::CheckState &arg1);
    void on_Reviewer_checkStateChanged(const Qt::CheckState &state);
    void on_Researcher_checkStateChanged(const Qt::CheckState &state);
    void exportTableToPDF(const QString &fileName);
    void on_exportUserPDF_clicked();



    /***************************************   USER END   **********************************************************/


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
    //************PUBLICATION START***************************//
    void on_addButton_clicked();
    void on_deleteButton_clicked();
    void on_searchbt_clicked();
    void on_summaryButton_clicked();
    void on_emailButton_clicked();
    void on_publication_clicked();
    //************PUBLICATION END***************************//

    //************SUBMISSION START***************************//
    void on_addSubmissionBtn_clicked();
    void on_deleteSubmissionBtn_clicked();
    void on_searchSubmissionBtn_clicked();
    void on_refreshSubmissionBtn_clicked();
    void on_editSubmissionBtn_clicked();
    void on_submissionStatusChanged(const QString &newStatus);
    //************SUBMISSION END***************************//

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
    void buildCreateReviewUI();

    //************REVIEW END***************************//

    //************collabs start*********//
    bool loadCollabs();
    std::vector<Collaboration> collaborations;
    //************collabs end**********//
    //************PUBLICATION START***************************//

    Publication pubTmp;

    void loadPublications(const QString &searchFilter = "");
    void showPublicationDialog(int            pubId  = -1,
                               int           authId  = 0,
                               int            subId  = 0,
                               const QString  &desc  = "",
                               const QDate    &date  = QDate(),
                               const QString &field  = "");
    void exportPublicationPDF(int            pubId,
                              int           authId,
                              int            subId,
                              const QString  &desc,
                              const QDate    &date,
                              const QString &field);
    void showpublicationstats();
    //************PUBLICATION END***************************//

    //************SUBMISSION START***************************//
    Submission submissionTmp;
    int editingSubmissionId = -1;
    QTableWidget *submissionTableWidget = nullptr;
    QString selectedManuscriptPath;
    QString selectedCitationPath;

    void loadSubmissions(const QString &searchFilter = "");
    void showSubmissionDialog(int submissionId = -1,
                              const QString &title = "",
                              const QString &status = "Draft",
                              const QString &citation = "",
                              int authorID = 0,
                              int topicID = 0,
                              const QString &manuscript = "");
    void refreshSubmissionTable();
    void clearSubmissionForm();
    //************SUBMISSION END***************************//
};
#endif // MAINWINDOW_H
