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
    TacheUnitaire(QString _titre,QDateTime _disponibilite,QDateTime _echeance,QTime _duree,bool _preemptable=false);
    QTime getDuree() const {return duree;}
    bool getPreemptable(){return preemptable;}
    void setDuree(QTime _duree) {duree=_duree;}
    void setPreemptable(bool _preemptable){preemptable=_preemptable;}
    void afficher(QStandardItem *);
    std::list<Tache *> getUniquePrerequis();

    virtual ~TacheUnitaire();
};

Q_DECLARE_METATYPE(TacheUnitaire *)

#endif // TACHEUNITAIRE_H
