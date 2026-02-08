#ifndef ADDCONFERENCEDIALOG_H
#define ADDCONFERENCEDIALOG_H

#include <QDialog>
#include "conference_model.h"

namespace Ui {
class addconferencedialog;
}

class addconferencedialog : public QDialog
{
    Q_OBJECT

public:
    explicit addconferencedialog(QWidget *parent = nullptr);
    ~addconferencedialog();

    conference_model getConference() const;

private:
    Ui::addconferencedialog *ui;
};

#endif
