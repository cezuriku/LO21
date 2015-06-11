#include "tacheunitaire.h"
#include <iostream>

TacheUnitaire::TacheUnitaire(QString _titre, QDateTime _disponibilite, QDateTime _echeance, QTime _duree, bool _preemptable):
    Tache(_titre,_disponibilite,_echeance),duree(_duree),preemptable(_preemptable)
{
    if(_preemptable && _duree>QTime::fromString("12:00:00"))
    {
        throw CalendarException("La tache unitaire non preemptable ne peut exceder 12h");
    }
}

TacheUnitaire::~TacheUnitaire()
{
    this->setDuree(QTime::fromString("15:00:00"));
}

void TacheUnitaire::afficher(QStandardItem *)
{
    //TODO parametre inutilisé
}

std::list<Tache*> TacheUnitaire::getUniquePrerequis()
{
    std::list<Tache*> result,part;
    for(std::vector<Tache *>::iterator it=this->prerequis.begin();it!=this->prerequis.end();++it)
    {
        if(dynamic_cast<TacheUnitaire*>((*it))!=NULL)
        {
            result.push_back((*it));
        }
        else
        {
            part=dynamic_cast<TacheComposite*>((*it))->getTachesUnitaires();
            result.merge(part);
        }
    }

    if(getParent()!=NULL)
    {
        part=dynamic_cast<TacheComposite*>(getParent())->getUniquePrerequis();
        result.merge(part);
    }

    return result;
}
