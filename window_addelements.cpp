#include "window_addelements.h"
#include "ui_window_addelements.h"
#include "model.h"

window_addelements::window_addelements(TacheComposite* newTache, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::window_addelements)
{
    ui->setupUi(this);

    std::list<Tache*> taches = Model::getTaches();
    QStringList listeTaches;

    std::list<Tache*>::iterator it = taches.begin();
    for (unsigned int i = 0 ; i < taches.size() ; i++)
    {
        listeTaches << (*it)->getTitre();
        it++;
    }

    modele = new QStringListModel(listeTaches);

    ui->list_taches->setModel(modele);
    ui->list_taches->setSelectionMode(QAbstractItemView::ExtendedSelection);

    connect(ui->b_ok, SIGNAL(clicked()), this, SLOT(click_ok()));
}

window_addelements::~window_addelements()
{
    delete ui;
}

void window_addelements::click_ok()
{
    QItemSelectionModel *selection = ui->list_taches->selectionModel();
    QModelIndexList listeSelections = selection->selectedIndexes();

    for (int i = 0 ; i < listeSelections.size() ; i++)
    {
        QVariant elementSelectionne = modele->data(listeSelections[i], Qt::DisplayRole);
        //getTache ne renvoie pas de tache
        //TacheUnitaire * selectedTache = TacheManager::getTache(elementSelectionne.toString());
        //if (selectedTache!=NULL)
        //    newTache->ajouterPrerequis(selectedTache);
    }
}
