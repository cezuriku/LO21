#ifndef TACHEUNITAIRE_H
#define TACHEUNITAIRE_H

#include "tache.h"
#include "tachecomposite.h"
#include <QVariant>


class TacheUnitaire: public Tache
{

protected:
    QTime duree;
    bool preemptable;

public:
    /**
     * @brief Constructeur par défaut de TacheUnitaire
     * @param _titre
     * @param _disponibilite
     * @param _echeance
     * @param _duree
     * @param _preemptable
     */
    TacheUnitaire(QString _titre,QDateTime _disponibilite,QDateTime _echeance,QTime _duree,bool _preemptable=false);

    /**
     * @brief getter durée
     * @return
     */
    QTime getDuree() const {return duree;}

    /**
     * @brief getter Preemptable
     * @return
     */
    bool getPreemptable(){return preemptable;}

    /**
     * @brief setter Duree
     * @param _duree
     */
    void setDuree(QTime _duree) {duree=_duree;}

    /**
     * @brief setter Preemptable
     * @param _preemptable
     */
    void setPreemptable(bool _preemptable){preemptable=_preemptable;}

    /**
     * @brief affiche la tache unitaire dans un QStandardItem
     */
    void afficher(QStandardItem *);

    /**
     * @brief recupere la liste des prérequis
     * @return
     */
    std::list<Tache *> getUniquePrerequis();

    /**
     * @brief Destructeur par défaut
     */
    virtual ~TacheUnitaire();
};

Q_DECLARE_METATYPE(TacheUnitaire *)

#endif // TACHEUNITAIRE_H
