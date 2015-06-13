#ifndef WINDOW_ADDPROJECT_H
#define WINDOW_ADDPROJECT_H

#include <QWidget>

namespace Ui {
class window_addProject;
}

class window_addProject : public QWidget
{
    Q_OBJECT

public:
    explicit window_addProject(QWidget *parent = 0);
    ~window_addProject();

private:
    Ui::window_addProject *ui;

private slots:
    void click_ok();
};

#endif // WINDOW_ADDPROJECT_H
