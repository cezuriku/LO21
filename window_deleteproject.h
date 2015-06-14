#ifndef WINDOW_DELETEPROJECT_H
#define WINDOW_DELETEPROJECT_H
#include <QStringListModel>
#include <QWidget>

namespace Ui {
class window_deleteProject;
}

class window_deleteProject : public QWidget
{
    Q_OBJECT

public:
    explicit window_deleteProject(QWidget *parent = 0);
    ~window_deleteProject();

private:
    Ui::window_deleteProject *ui;
    QStringListModel *modele;
private slots:
    void click_suppr();
};

#endif // WINDOW_DELETEPROJECT_H
