#include "tache.h"

Tache::Tache(QString _titre,QDateTime _disponibilite,QDateTime _echeance):
    titre(_titre), disponibilite(_disponibilite), echeance(_echeance), statut(false), parent(NULL)
{
    if(echeance < QDateTime::currentDateTime())
    {
        throw CalendarException("L'échéance est dépassée");
    }
    else if(echeance < disponibilite)
    {
        throw CalendarException("La disponibilité est après l'échéance");
    }
}

Tache::~Tache()
{

}

void Tache::ajouterPrerequis(Tache * _prerequis)
{
    verifierPrerequis(this,_prerequis);
    prerequis.push_back(_prerequis);
    std::sort(prerequis.begin(),prerequis.end(),compareTache());
}

bool Tache::isPrerequisProgramme()
{
    for(std::vector<Tache *>::iterator it=this->prerequis.begin();it!=this->prerequis.end();++it)
    {
        if((*it)->getStatut()!=true)
        {
            return false;
        }
    }
    if(getParent()==NULL)
    {
        return true;
    }
    if(getParent()->isPrerequisProgramme()==false)
    {
        return false;
    }
    return true;
}

bool Tache::verifierPrerequis(Tache* tache, Tache * tachePrerequise)
{
    if(tache==NULL)
    {
        return true;
    }
    if(tache==tachePrerequise)
    {
        throw CalendarException("La tache ne peut pas être prérequise par elle-même");
    }
    else if(tache->getDisponibilite()<=tachePrerequise->getDisponibilite())
    {
        throw CalendarException("La date de disponibilité de la tache prérequise est supérieure à celle de la tache");
    }

    Tache* ptr_tache=tache->getParent();
    while(ptr_tache!=NULL)
    {
        if(ptr_tache==tachePrerequise)
        {
            throw CalendarException("La tache ne peut pas avoir une tache parente en prérequis");
        }
        ptr_tache=ptr_tache->getParent();
    }
    return true;

}

bool Tache::verifierAttache(Tache* tache, Tache * tacheParente)
{
    if(tache==NULL)
    {
        return true; //Creation case
    }
    if(tache==tacheParente)
    {
        throw CalendarException("Une tache ne peut être parente à elle même");
    }
    else if(tache->getDisponibilite()>=tacheParente->getEcheance())
    {
        throw CalendarException("La disponibilite de la tache est supérieure à son échéance");
    }
    //TODO nom déjà utilisé ?
    return true;

}

bool Tache::operator<(const Tache &t) const
{
    if(this->getEcheance()<=t.getEcheance())
    {
        return true;
    }
    return false;
}
