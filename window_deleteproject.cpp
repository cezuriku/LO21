#include "window_deleteproject.h"
#include "ui_window_deleteproject.h"
#include "model.h"
#include <QStringListModel>
#include <QMessageBox>

window_deleteProject::window_deleteProject(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::window_deleteProject)
{
    ui->setupUi(this);

    /*
    std::list<Projet*> projets = Model::getProjets();
    QStringList listeProjets;

    std::list<Projet*>::iterator it = projets.begin();
    for (unsigned int i = 0 ; i < projets.size() ; i++)
    {
        listeProjets << (*it)->getTitre();
        it++;
    }

    QStringListModel * modele = new QStringListModel(listeProjets);
    ui->list_project->setModel(modele);
    */
    std::list<Projet*> projets = Model::getProjets();
    QStringList listeProjet;

    std::list<Projet*>::iterator it = projets.begin();
    for (unsigned int i = 0 ; i < projets.size() ; i++)
    {
        listeProjet << (*it)->getTitre();
        it++;
    }

    modele = new QStringListModel(listeProjet);

    ui->list_project->setModel(modele);

    connect(ui->t_suppr, SIGNAL(clicked()), this, SLOT(click_suppr()));
}

window_deleteProject::~window_deleteProject()
{
    delete ui;
}

void window_deleteProject::click_suppr(){
    QItemSelectionModel *selection = ui->list_project->selectionModel();
    QModelIndex indexElementSelectionne = selection->currentIndex();
    QVariant elementSelectionne = modele->data(indexElementSelectionne, Qt::DisplayRole);

    std::list<Projet*> projets = Model::getProjets();

    std::list<Projet*>::iterator it = projets.begin();
    for (unsigned int i = 0 ; i < projets.size() ; i++)
    {
        if ((*it)->getTitre()==elementSelectionne.toString())
             (*it)->
        it++;
    }

    /*
    QItemSelectionModel *selection = ui->list_project->selectionModel();
    QModelIndex indexElementSelectionne = selection->currentIndex();
    QVariant elementSelectionne = modele->data(indexElementSelectionne, Qt::DisplayRole);
    QMessageBox::information(this, "Elément sélectionné", elementSelectionne.toString());
    */
}
