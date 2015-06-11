#ifndef TACHEMANAGER_H
#define TACHEMANAGER_H

#include "singleton.h"
#include "manager.h"
#include "tache.h"
#include "tacheunitaire.h"

class TacheManager : public Singleton<Manager<Tache> >
{
public:
    /**
     * @brief Recherche une tache dans le tachemanager grace à son titre
     * @param titre
     * @return La tache si elle à été trouvée nullptr sinon
     */
    static TacheUnitaire* getTache(QString titre);
};

#endif // TACHEMANAGER_H
