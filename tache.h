#ifndef TACHE_H
#define TACHE_H

#include <vector>
#include <QString>
#include <QDateTime>
#include <QStandardItem>
#include <QVariant>

#include "calendarexception.h"

class Tache
{

protected:
    QString titre;
    QDateTime disponibilite;
    QDateTime echeance;
    bool statut;
    Tache* parent;
    std::vector<Tache*> prerequis;
    Tache(QString _titre,QDateTime _disponibilite,QDateTime _echeance);

    Tache(const Tache& source);
    Tache& operator=(const Tache& source);

public:
    void setParent(Tache * _parent){parent=_parent;}
    Tache* getParent()const{ return parent;}
    QString getTitre()const{return titre;}
    void setTitle(QString title){titre=title;}
    QDateTime getDisponibilite()const{return disponibilite;}
    void setDisponibilite(QDateTime disponibilite){disponibilite=disponibilite;}
    QDateTime getEcheance() const{return echeance;}
    void setEcheance(QDateTime _echeance){echeance=_echeance;}
    std::vector<Tache*>& getPrerequis(){return prerequis;}
    void setStatut(bool _statut){statut=_statut;}
    bool getStatut(){return statut;}
    void ajouterPrerequis(Tache * prerequis);
    virtual void afficher(QStandardItem * parent)=0;
    bool isPrerequisProgramme();

    static bool verifierPrerequis(Tache* task,Tache * prerequisTask);
    static bool verifierAttache(Tache* tache,Tache * tacheParente);
    bool operator<(const Tache& b) const;

    struct compareTache
    {
          bool operator()(const Tache* t1, const Tache* t2)
          {
            return *t1 < *t2;
          }
    };

    virtual ~Tache()=0;
};

Q_DECLARE_METATYPE(Tache *)

#endif // TACHE_H
