#include "window_addtacheunaire.h"
#include "ui_window_addtacheunaire.h"
#include "QDateTime"
#include "QMessageBox"
#include "model.h"

window_addtacheunaire::window_addtacheunaire(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::window_addtacheunaire)
{
    ui->setupUi(this);
    ui->rb_unaire->setChecked(true);
    ui->gb_unaire->setEnabled(true);
    ui->cb_prereq->setChecked(false);
    ui->gb_prereq->setEnabled(false);

    QDateTime today = QDateTime::currentDateTime();
    ui->dt_dispo->setMinimumDateTime(today);
    ui->dt_ech->setMinimumDateTime(today);

    connect(ui->rb_preemp, SIGNAL(clicked()), this, SLOT(click_tacheunaire()));
    connect(ui->rb_unaire, SIGNAL(clicked()), this, SLOT(click_tachepre()));
    connect(ui->cb_prereq, SIGNAL(clicked()), this, SLOT(click_prerequis()));
    connect(ui->b_ok, SIGNAL(clicked()), this, SLOT(click_ok()));
}

window_addtacheunaire::~window_addtacheunaire()
{
    delete ui;
}

void window_addtacheunaire::click_tacheunaire()
{
    ui->gb_unaire->setEnabled(false);
}

void window_addtacheunaire::click_tachepre()
{
    ui->gb_unaire->setEnabled(true);
}

void window_addtacheunaire::click_prerequis()
{
    if (ui->cb_prereq->isChecked())
        ui->gb_prereq->setEnabled(true);
    else
        ui->gb_prereq->setEnabled(false);
}

/*void window_addtacheunaire::click_ok()
{
    if (ui->t_titre->text().isEmpty())
    {
        QMessageBox::critical(this, "Erreur", "Veuillez entrer un titre");
        return;
    }
    if (ui->dt_dispo>ui->dt_ech)
    {
        QMessageBox::critical(this, "Erreur", "La date de disponibilité est supérieure à la date d'échéance");
        return;
    }

    if (ui->rb_unaire->isChecked())
    {
        //TacheUnitaire newTache = new TacheUnitaire ();
    }
}*/
