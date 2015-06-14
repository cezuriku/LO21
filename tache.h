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
    /// Les taches prérequise
    std::vector<Tache*> prerequis;

    /**
     * @brief Constructeur par défaut
     * @param _titre
     * @param _disponibilite
     * @param _echeance
     */
    Tache(QString _titre,QDateTime _disponibilite,QDateTime _echeance);

    /**
     * @brief Constructeur de copie privé pour empecher la copie
     * @param source
     */
    Tache(const Tache& source);

    /**
     * @brief operateur d'affectation privé pour empecher la copie
     * @param source
     */
    Tache& operator=(const Tache& source);

public:
    /**
     * @brief setter parent
     * @param _parent
     */
    void setParent(Tache * _parent){parent=_parent;}

    /**
     * @brief getter parent
     * @param _parent
     */
    Tache* getParent()const{ return parent;}

    /**
     * @brief getter titre
     * @return
     */
    QString getTitre()const{return titre;}

    /**
     * @brief setter titre
     * @param title
     */
    void setTitle(QString title){titre=title;}

    /**
     * @brief getter disponibilite
     * @return disponibilite
     */
    QDateTime getDisponibilite()const{return disponibilite;}

    /**
     * @brief setDisponibilite
     * @param disponibilite
     */
    void setDisponibilite(QDateTime disponibilite){disponibilite=disponibilite;}

    /**
     * @brief getEcheance
     * @return echeance
     */
    QDateTime getEcheance() const{return echeance;}

    /**
     * @brief setter echeance
     * @param _echeance
     */
    void setEcheance(QDateTime _echeance){echeance=_echeance;}

    /**
     * @brief getPrerequis
     * @return
     */
    std::vector<Tache*>& getPrerequis(){return prerequis;}

    /**
     * @brief setStatut
     * @param _statut
     */
    void setStatut(bool _statut){statut=_statut;}

    /**
     * @brief getStatut
     * @return
     */
    bool getStatut(){return statut;}

    /**
     * @brief ajoute une tache prérequise
     * @param prerequis
     */
    void ajouterPrerequis(Tache * prerequis);

    /**
     * @brief affiche dans un QStandardItem
     * @param parent
     */
    virtual void afficher(QStandardItem * parent)=0;

    /**
     * @brief verifie si les prerequis sont programmés
     * @return
     */
    bool isPrerequisProgramme();

    /**
     * @brief verifie si la tache peut etre un prerequis
     * @param task
     * @param prerequisTask
     * @return
     */
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
