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

    /**
     * @brief getProgrammationParDate
     * @param debut
     * @param fin
     * @return
     */
    static std::list<Programmation*> getProgrammationParDate(QDateTime debut, QDateTime fin);
};

#endif // PROGRAMMATIONMANAGER_H
