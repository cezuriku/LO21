#ifndef TACHECOMPOSITE_H
#define TACHECOMPOSITE_H

#include <vector>
#include "tache.h"
#include "tacheunitaire.h"
#include <QVariant>


class TacheComposite: public Tache
{

protected:
    std::vector<Tache *> element;

public:
    /**
     * @brief Constructeur par défaut
     * @param _titre
     * @param _disponibilite
     * @param _echeance
     */
    TacheComposite(QString _titre,QDateTime _disponibilite,QDateTime _echeance);

    /**
     * @brief ajoute un élément à la tache composite
     * @param element
     */
    void addElement(Tache * element);

    /**
     * @brief récupère la liste des taches de cette tache composite
     * @return
     */
    std::vector<Tache *>& getElement(){return element;}

    /**
     * @brief affiche cette tache dans une QStandardItem
     * @param parent
     */
    void afficher(QStandardItem * parent);

    /**
     * @brief recupère la liste des prérequis
     * @return
     */
    std::list<Tache*> getUniquePrerequis();

    /**
     * @brief récupère la liste des taches unitaires que comporte la tache composite (les feuilles de l'arbre)
     * @return
     */
    std::list<Tache*> getTachesUnitaires();

    /**
     * @brief Destructeur virtuel
     */
    virtual ~TacheComposite();
};

Q_DECLARE_METATYPE(TacheComposite *)

#endif // TACHECOMPOSITE_H
