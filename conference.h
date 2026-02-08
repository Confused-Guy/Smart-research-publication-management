#ifndef CONFERENCE_H
#define CONFERENCE_H

#include <QMainWindow>

namespace Ui {
class conference;
}

class conference : public QMainWindow
{
    Q_OBJECT

public:
    explicit conference(QWidget *parent = nullptr);
    ~conference();

private slots:
    void on_addConferenceBtn_clicked();

private:
    Ui::conference *ui;
};

#endif
