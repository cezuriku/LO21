#include "programmation.h"
#include "programmationmanager.h"
#include "tachemanager.h"

Programmation::Programmation(QDateTime _date, QString _titre, bool isTache):
    date(_date),duree(),titre(_titre),tache(NULL)
{
    if(date < QDateTime::currentDateTime())
        throw CalendarException("La date de la programmation est déjà passée !");
    if (isTache) {
        tache = TacheManager::getTache(titre);
        if (tache == NULL)
            throw CalendarException("Le titre ne correspond à aucune tache");
        duree = tache->getDuree();
        verifierDureePossible();
    } else {
        std::list<Programmation*> liste = ProgrammationManager::getProgrammation(_titre);
        if (liste.size() > 0)
            throw CalendarException("La tache ou l'evenement est déjà programmée avec ce titre");
    }

}

Programmation::Programmation(QDateTime _date, QTime _duree, QString _titre):
    date(_date),duree(_duree),titre(_titre),tache(NULL)
{
    if(date < QDateTime::currentDateTime())
        throw CalendarException("La date de la programmation est déjà passée !");
    tache = TacheManager::getTache(_titre);
    if (tache == NULL)
        throw CalendarException("Le titre ne correspond à aucune tache");
    verifierDureePossible();
}

Programmation::Programmation(QDateTime _date,QTime _duree,TacheUnitaire *_tache):
    date(_date),duree(_duree), tache(_tache)
{
    if(_date < QDateTime::currentDateTime())
        throw CalendarException("La date de la programmation est déjà passée !");
    if(duree > tache->getDuree())
        throw CalendarException("La durée ne peut être supérieure à la durée de la tache !");
    if(tache->getPreemptable() == false && duree != tache->getDuree())
        throw CalendarException("La durée ne peut être différente à la durée de la tache si elle est non préemptable!");

    titre=_tache->getTitre();
    verifierDureePossible();
}

void Programmation::verifierDureePossible() {
    std::list<Programmation*> liste = ProgrammationManager::getProgrammation(titre);
    if(tache->getPreemptable() == false && liste.size() > 0)
        throw CalendarException("La tache est déjà programmée");
    else {
        QTime tempsTotal = duree;
        for (Programmation* p : liste)
            tempsTotal.addMSecs(p->getDuree().msec());
        if(tempsTotal > tache->getDuree())
            throw CalendarException("La tache est déjà programmée plus longtemps que nécessaire");
    }
}

Programmation::~Programmation()
{

}

bool Programmation::operator<(const Programmation &b) const
{
    if(this->getDate()<=b.getDate())
    {
        return true;
    }
    return false;
}

