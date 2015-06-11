#ifndef PROGRAMMATION_H
#define PROGRAMMATION_H

#include <QString>
#include <QDateTime>
#include "tacheunitaire.h"

class Programmation
{
private:
    void verifierDureePossible();

protected:
    QDateTime date;
    QTime duree;
    QString titre;
    TacheUnitaire *tache;

public:
    /**
     * @brief Programmation d'une tache unitaire non préemptable
     * @param date la date de la programmation
     * @param titre le titre de la tache à ajouter
     */
    Programmation(QDateTime _date, QString _titre, bool isTache = true);

    Programmation(QDateTime _date,QTime _duree,QString _titre);
    Programmation(QDateTime _date,QTime _duree,TacheUnitaire *_tache);

    ~Programmation();

    QDateTime getDate()const {return date;}
    QString getTitre()const{return titre;}
    QTime getDuree(){return duree;}
    TacheUnitaire* getTache(){return tache;}
    bool operator < (const Programmation& b) const;
    bool operator == (const Programmation& b) const;

};

#endif // PROGRAMMATION_H
