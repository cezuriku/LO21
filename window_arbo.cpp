#include "window_arbo.h"
#include "ui_window_arbo.h"
#include "model.h"
#include <QColor>

window_arbo::window_arbo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::window_arbo)
{
    ui->setupUi(this);
    modele =  new QStandardItemModel;
    for (Projet* p : Model::getProjets())
    {
        QString titre = p->getTitre();
        QStandardItem *item = new QStandardItem(titre);
        item->setBackground(QBrush(Qt::GlobalColor::black));
        item->setForeground(QBrush(Qt::GlobalColor::white));
        modele->appendRow(item);
        p->afficher(modele);
    }

    ui->treeView->header()->hide();
    ui->treeView->setModel(modele);
}

window_arbo::~window_arbo()
{
    delete ui;
}
