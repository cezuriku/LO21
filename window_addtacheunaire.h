#ifndef WINDOW_ADDTACHEUNAIRE_H
#define WINDOW_ADDTACHEUNAIRE_H

#include "QStringListModel"
#include <QWidget>

namespace Ui {
class window_addtacheunaire;
}

class window_addtacheunaire : public QWidget
{
    Q_OBJECT

public:
    explicit window_addtacheunaire(QWidget *parent = 0);
    ~window_addtacheunaire();

private:
    Ui::window_addtacheunaire *ui;
    QStringListModel *modele;
    QStringListModel *modele2;

private slots:
    void click_tacheunaire();
    void click_tachepre();
    void click_prerequis();
    void click_bok();
    void click_tachecomp();
};

#endif // WINDOW_ADDTACHEUNAIRE_H
