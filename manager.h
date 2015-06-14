#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <vector>

#include <QStandardItemModel>
#include <QVariant>

/**
 * Classe gérant une liste d'objets
 */
template<typename Type> class Manager
{
public:
    /**
     * @brief Constructeur par défaut
     */
    Manager();

    /**
     * @brief Constructeur de copie
     * @param copy le manager à copier
     */
    Manager(const Manager& copy);

    /// La liste concrète des objets
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
