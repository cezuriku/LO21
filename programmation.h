#ifndef PROGRAMMATION_H
#define PROGRAMMATION_H

#include <QString>
#include <QDateTime>
#include "tacheunitaire.h"

class Programmation
{
private:
    void verifierDureePossible();

    /**
     * @brief Constructeur de copie privé pour empecher la copie
     * @param source
     */
    Programmation(const Programmation& source);

    /**
     * @brief operateur d'affectation privé pour empecher la copie
     * @param source
     */
    Programmation& operator=(const Programmation& source);

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

    /**
     * @brief Programmation d'une tache préemptable (on précise la durée
     * @param _date la date et l'heure de la programmation
     * @param _duree la durée de la programmation
     * @param _titre le titre de la tache
     */
    Programmation(QDateTime _date,QTime _duree,QString _titre);

    /**
     * @brief Programmation d'une tache préemptable (on précise la durée
     * @param _date la date et l'heure de la programmation
     * @param _duree la durée de la programmation
     * @param _tache La tache à programmer
     */
    Programmation(QDateTime _date,QTime _duree,TacheUnitaire *_tache);

    /**
     * Destructeur par défaut
     */
    ~Programmation();

    /**
     * @brief getter date
     * @return la date
     */
    QDateTime getDate()const {return date;}

    /**
     * @brief getter titre
     * @return la titre
     */
    QString getTitre()const{return titre;}

    /**
     * @brief getter duree
     * @return la duree
     */
    QTime getDuree(){return duree;}

    /**
     * @brief getter tache
     * @return la tache
     */
    TacheUnitaire* getTache(){return tache;}

    /**
     * @brief comparateur infériorité entre 2 programmation
     * @param b la seconde tache à comparer
     * @return si la tache est programmé avant la b
     */
    bool operator < (const Programmation& b) const;

};

#endif // PROGRAMMATION_H
