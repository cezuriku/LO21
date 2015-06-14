#ifndef WINDOW_ADDELEMENTS_H
#define WINDOW_ADDELEMENTS_H
#include "model.h"
#include <QStringListModel>

#include <QWidget>

namespace Ui {
class window_addelements;
}

class window_addelements : public QWidget
{
    Q_OBJECT

public:
    explicit window_addelements(TacheComposite *newTache, QWidget *parent = 0);
    ~window_addelements();

private:
    Ui::window_addelements *ui;
    QStringListModel *modele;

private slots:
    void click_ok();
};

#endif // WINDOW_ADDELEMENTS_H
