#ifndef PROJET_H
#define PROJET_H

#include <vector>
#include <QString>
#include <QDateTime>
#include <QStandardItem>
#include <QStandardItemModel>
#include "tache.h"
#include "tachecomposite.h"


class Projet
{
protected:
    QString titre;
    QDateTime disponibilite;
    QDateTime echeance; //TODO virer echeance (calculée)
    std::vector<Tache *> taches;

    Projet(const Projet& source);
    Projet& operator=(const Projet& source);

public:
    Projet(QString titre, QDateTime disponibilite, QDateTime echeance);
    ~Projet();

    void addElement(Tache * element);
    void removeElement(Tache * element);
    void afficher(QStandardItemModel * treeModel);
    QString getTitre(){return titre;}
    void setTitle(QString title){titre=title;}
    QDateTime getDisponibility(){return disponibilite;}
    void setDisponibility(QDateTime _disponibilite){disponibilite=_disponibilite;}
    QDateTime getEcheance()const {return echeance;}
    void setEcheance(QDateTime Echeance){echeance=Echeance;}

    bool operator < (const Projet& b) const;
    bool operator == (const Projet& b) const;


};

Q_DECLARE_METATYPE(Projet *)

#endif // PROJET_H
