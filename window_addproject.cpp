#include <QDateTime>
#include <QMessageBox>
#include "window_addproject.h"
#include "ui_window_addproject.h"
#include "model.h"

window_addProject::window_addProject(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::window_addProject)
{
    ui->setupUi(this);
    QDateTime today = QDateTime::currentDateTime();
    ui->t_date_ech->setMinimumDateTime(today);
    ui->t_date_dispo->setMinimumDateTime(today);

    connect(ui->b_ok, SIGNAL(clicked()), this, SLOT(click_ok()));
}

window_addProject::~window_addProject()
{
    delete ui;
}

void window_addProject::click_ok()
{
    if (ui->t_titre->text().isEmpty())
       {
            QMessageBox::critical(this, "Erreur", "Veuillez entrer un titre");
            return;
        }
    Projet * newProject = new Projet(ui->t_titre->text(), ui->t_date_dispo->dateTime(), ui->t_date_ech->dateTime());
    Model::ajouterProjet(newProject);
    QMessageBox msgBox;
    msgBox.setText("Le projet a été ajouté.");
    msgBox.exec();
    this->close();
}
