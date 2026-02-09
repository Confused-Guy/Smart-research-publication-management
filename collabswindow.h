#ifndef COLLABSWINDOW_H
#define COLLABSWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class collabsWindow;
}
QT_END_NAMESPACE

class collabsWindow : public QMainWindow
{
    Q_OBJECT

public:
    collabsWindow(QWidget *parent = nullptr);
    ~collabsWindow();

private slots:


private:
    Ui::collabsWindow *ui;
};
#endif // COLLABSWINDOW_H
