#include "fen_ajouter_projet.h"
#include "ui_ajouter_projet.h"

ajouter_projet::ajouter_projet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajouter_projet)
{
    ui->setupUi(this);

    connect(ui->b_annuler, SIGNAL(clicked()), this, SLOT(quit()));
}

ajouter_projet::~ajouter_projet()
{
    delete ui;
}
