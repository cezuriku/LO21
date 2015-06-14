#include "window_addprog.h"
#include "ui_window_addprog.h"
#include "model.h"
#include <QMessageBox>

window_addprog::window_addprog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::window_addprog)
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
    ui->treeView->setSelectionMode(QAbstractItemView::ExtendedSelection);

    QDateTime today = QDateTime::currentDateTime();
    ui->t_date->setMinimumDateTime(today);
    ui->t_dateEv->setMinimumDateTime(today);

    connect(ui->b_ok, SIGNAL(clicked()), this, SLOT(click_bok()));
    connect(ui->b_progEv, SIGNAL(clicked()), this, SLOT(click_bprogEv()));
}

window_addprog::~window_addprog()
{
    delete ui;
}

void window_addprog::click_bok()
{
    try
    {
        Model::ajouterProgrammation(new Programmation(ui->t_date->dateTime(), ui->t_titre->text()));
    }
    catch (CalendarException& e)
    {
        QMessageBox::critical(this, "Erreur", e.getInfo());
        return;
    }

    this->close();
}

void window_addprog::click_bprogEv()
{
    try
    {
        Model::ajouterProgrammation(new Programmation(ui->t_dateEv->dateTime(), ui->t_titreEv->text(), false));
    }
    catch (CalendarException& e)
    {
        QMessageBox::critical(this, "Erreur", e.getInfo());
        return;
    }

    this->close();
}
