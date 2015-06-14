#ifndef WINDOW_ADDPROG_H
#define WINDOW_ADDPROG_H

#include <QWidget>
#include <QStandardItemModel>

namespace Ui {
class window_addprog;
}

class window_addprog : public QWidget
{
    Q_OBJECT

public:
    explicit window_addprog(QWidget *parent = 0);
    ~window_addprog();

private:
    Ui::window_addprog *ui;
    QStandardItemModel *modele;

private slots:
    void click_bok();
    void click_bprogEv();
};

#endif // WINDOW_ADDPROG_H
