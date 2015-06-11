#ifndef PROGRAMMATIONMANAGER_H
#define PROGRAMMATIONMANAGER_H

#include "singleton.h"
#include "manager.h"
#include "programmation.h"

class ProgrammationManager : public Singleton<Manager<Programmation> >
{
public:
    /**
     * @brief récupère les programmation d'une tache
     * @param titre
     * @return la liste des programmations
     */
    static std::list<Programmation*> getProgrammation(QString titre);
};

#endif // PROGRAMMATIONMANAGER_H
