#ifndef AJOUTER_PROJET_H
#define AJOUTER_PROJET_H

#include <QDialog>

namespace Ui {
class ajouter_projet;
}

class ajouter_projet : public QDialog
{
    Q_OBJECT

public:
    explicit ajouter_projet(QWidget *parent = 0);
    ~ajouter_projet();

private:
    Ui::ajouter_projet *ui;
};

#endif // AJOUTER_PROJET_H
