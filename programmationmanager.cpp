#include "programmationmanager.h"
#include <list>

std::list<Programmation*> ProgrammationManager::getProgrammation(QString titre) {
    std::list<Programmation*> liste;
    for (Programmation *p : ProgrammationManager::getInstance()->getListe())
        if (QString::localeAwareCompare(p->getTache()->getTitre(), titre) == 0)
            liste.push_back(p);

    return liste;
}
