#include "tachemanager.h"

TacheUnitaire* TacheManager::getTache(QString titre)
{
    for(Tache* tache : TacheManager::getInstance()->getListe())
        if (QString::localeAwareCompare(tache->getTitre(), titre) == 0)
            return dynamic_cast<TacheUnitaire*>(tache);
    return nullptr;
}
