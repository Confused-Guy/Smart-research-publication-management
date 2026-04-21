#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QFileDialog>
#include "collaboration.h"
#include "publication.h"
#include "submission.h"
#include "filepreviewdialog.h"
#include "ollamaintegration.h"
#include "user.h"

#include <QSerialPort>
#include <QSerialPortInfo>

#include <QTextToSpeech>

#include <QSystemTrayIcon>

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

    void on_collab_clicked();

    void on_profile_clicked();

    void on_publication_clicked();

    void on_Research_clicked();

    void toggleDarkMode();

    void on_modeSwitch_clicked(){ toggleDarkMode();}

    void on_temp_clicked();

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
    void on_logOut_clicked();

    void onArduinoDataReceived();
    void on_rfidLoginBtn_clicked();
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
    void on_collabsExportButton_clicked();
    void on_ReadCollabDesc_clicked();
    void on_collabsAddButton_clicked();
    void on_collabsRemoveButton_clicked();
    void on_collabsMessageSendButton_clicked();
    //***********Collabs End*******************//

    //************PUBLICATION START***************************//
    void on_addButton_clicked();
    void on_deleteButton_clicked();
    void on_searchbt_clicked();
    void on_summaryButton_clicked();
    void on_emailButton_clicked();
    void on_pubStatsBtn_clicked();
    void showPublicationStats();
    //************PUBLICATION END***************************//

    //************SUBMISSION START***************************//
    void on_addSubmissionBtn_clicked();
    void on_deleteSubmissionBtn_clicked();
    void on_searchSubmissionBtn_clicked();
    void on_refreshSubmissionBtn_clicked();
    void on_editSubmissionBtn_clicked();
    void on_submissionStatusChanged(const QString &newStatus);
    void on_previewSubmissionBtn_clicked();
    void on_pushButton_8_clicked();  // AI Checker button (was on_aiChecker_clicked)
    //************SUBMISSION END***************************//

private:
    Ui::MainWindow *ui;
    bool mode;

    //************ARDUINO START****************************//
    QSerialPort *arduino;
    void setupArduino();
    void clearArduinoLCD();
    void handleRFIDLogin(const QString &rfidCode);
    bool rfidLoginActive = false;
    //************ARDUINO END*****************************//

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
    QSystemTrayIcon* m_trayIcon = nullptr;
    QString getManuscriptTextForSubmission(int submissionId);
    int     detectAIContentPercentage(const QString& text);

    //Functions
    void showReviewDialog(int reviewId = -1);
    void exportReviewPDF(int reviewId, const QString& reviewerName, const QDate& reviewDate,
                         int submissionId, int publicationId, const QString& comment,
                         const QString& status);
    void buildCreateReviewUI();
    void initTrayIcon();
    void showTrayNotification(const QString& title, const QString& message);

    //************REVIEW END***************************//

    //************collabs start*********//
    bool loadCollabs();
    std::vector<Collaboration> collaborations;
    std::vector<User> collabsUsersToAdd;
    std::vector<User> collabsUsersAdded;
    // void on_collabsExportButton_clicked();
    // void on_ReadCollabDesc_clicked();
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

    void extracted(QList<Submission> &submissions, int &row);
    void loadSubmissions(const QString &searchFilter = QString());
    void showSubmissionDialog(int            submissionId = -1,
                              const QString &title        = QString(),
                              const QString &status       = QString(),
                              const QString &citation     = QString(),
                              int            authorID     = 0,
                              const QString &topic        = QString(),
                              const QString &manuscript   = QString());
    void refreshSubmissionTable();
    void clearSubmissionForm();
    void setupAndFillSubmissionTable(QTableWidget *table, const QList<Submission> &submissions);
    void showReviewTrackerDialog(int submissionId);
    void markReviewAsResolved(int reviewId);
    OllamaIntegration *ollamaIntegration;
    QLabel *aiStatusLabel = nullptr;  // Status messages for AI Checker
    QTextEdit *aiResultDisplay = nullptr;  // Display for AI results

    //************SUBMISSION END***************************//
};
#endif // MAINWINDOW_H
