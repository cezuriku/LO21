#include "window_arbo.h"
#include "ui_window_arbo.h"
#include "model.h"

window_arbo::window_arbo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::window_arbo)
{
    ui->setupUi(this);
    modele =  new QStandardItemModel;
    std::list<Projet*> projets = Model::getProjets();
    std::list<Projet*>::iterator it = projets.begin();
    for (unsigned int i = 0 ; i < projets.size() ; i++)
    {
        QString titre = (*it)->getTitre();
        QStandardItem *item = new QStandardItem(titre);
        modele->appendRow(item);
        //(*it)->afficher(item);
    }

    ui->treeView->header()->hide();
    ui->treeView->setModel(modele);
}

window_arbo::~window_arbo()
{
    delete ui;
}
