#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <vector>

#include <QStandardItemModel>
#include <QVariant>

template<typename Type> class Manager
{
public:
    Manager();
    Manager(const Manager& copy);
    Manager& operator=(const Manager& copy);

    std::list<Type *> liste;
public:
    virtual ~Manager();

    std::list<Type *>& getListe(){return liste;}
    void ajouterElement(Type * element);
    void supprimerElement(Type * element);
    void trier();

    struct typeInferieur
    {
          template<typename T>
          bool operator()(const T* l, const T* r)
          {
            return *l < *r;
          }
    };

};

#include "manager.tpp"

#endif // MANAGER_H
