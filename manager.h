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
    /**
     * @brief ~Manager
     */
    virtual ~Manager();
    /**
     * @brief recupère la liste interne des objets
     * @return la liste
     */
    std::list<Type *>& getListe(){return liste;}

    /**
     * @brief ajoute un élément à la liste
     * @param element le nouvel élément
     */
    void ajouterElement(Type * element);

    /**
     * @brief supprime un élément de la liste
     * @param element l'élément à supprimer
     */
    void supprimerElement(Type * element);

    /**
     * @brief trie les éléments de la liste
     */
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
