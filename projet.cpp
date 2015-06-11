#include "projet.h"

Projet::Projet(QString titre, QDateTime disponibilite, QDateTime echeance):
    titre(titre),disponibilite(disponibilite),echeance(echeance)
{
    if(echeance < QDateTime::currentDateTime())
    {
        throw CalendarException("Echéance du projet déjà passée !");
    }
    else if(echeance < disponibilite)
    {
        throw CalendarException("La disponibilité entrée pour le projet est ultérieure à l'échéance !");
    }
}

Projet::~Projet()
{
    for(std::vector<Tache*>::iterator it=taches.begin(); it!=taches.end(); ++it)
    {
        delete(*it);
    }
}

void Projet::addElement(Tache * element)
{
    taches.push_back(element);
    std::sort(taches.begin(),taches.end(),Tache::compareTache());
}

void Projet::removeElement(Tache * element)
{
    taches.erase(std::remove(taches.begin(),taches.end(),element),taches.end());
    std::sort(taches.begin(),taches.end());
}

void Projet::afficher(QStandardItemModel * treeModel)
{
    QStandardItem *item;

    for(std::vector<Tache *>::iterator it=this->taches.begin();it!=this->taches.end();++it)
    {
        item=new QStandardItem((*it)->getTitre());
        item->setData(QVariant::fromValue((*it)),Qt::UserRole+2);
        treeModel->appendRow(item);
        (*it)->afficher(item);

    }
}

bool Projet::operator<(const Projet &b) const
{
    if(this->getEcheance()<=b.getEcheance())
    {
        return true;
    }
    return false;
}
