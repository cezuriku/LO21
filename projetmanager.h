#ifndef PROJETMANAGER_H
#define PROJETMANAGER_H

#include "singleton.h"
#include "manager.h"
#include "projet.h"
#include <QStandardItem>

class ProjetManager : public Singleton<Manager<Projet> >
{
public:
    void afficher(QStandardItemModel * model);
};

#endif // PROJETMANAGER_H
