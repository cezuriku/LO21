#ifndef MODEL_H
#define MODEL_H

#include "tachemanager.h"
#include "tacheunitaire.h"
#include "tachecomposite.h"
#include "projetmanager.h"
#include "programmationmanager.h"

class Model {
private:

public:
    Model();

    /**
     * @brief ajoute une tache dans le tache manager
     * @param tache la tache à ajouter
     */
    static void ajouterTache(Tache* tache) {
        TacheManager::getInstance()->ajouterElement(tache);
    }

    /**
     * @brief ajoute un projet dans le projet manager
     * @param projet le projet à ajouter
     */
    static void ajouterProjet(Projet* projet) {
        ProjetManager::getInstance()->ajouterElement(projet);
    }

    /**
     * @brief ajoute une programmation dans le programmation manager
     * @param programmation la programmation à ajouter
     */
    static void ajouterProgrammation(Programmation* programmation) {
        ProgrammationManager::getInstance()->ajouterElement(programmation);
    }

    /**
     * @brief Recupere la liste des taches
     * @return la liste des taches
     */
    static std::list<Tache*> getTaches() {
        return TacheManager::getInstance()->getListe();
    }

    /**
     * @brief Recupere la liste des projets
     * @return la liste des projets
     */
    static std::list<Projet*> getProjets() {
        return ProjetManager::getInstance()->getListe();
    }

    /**
     * @brief Recupere la liste des programmations
     * @return la liste des programmations
     */
    static std::list<Programmation*> getProgrammations() {
        return ProgrammationManager::getInstance()->getListe();
    }

    /**
     * @brief supprime une tache dans le tache manager
     * @param tache la tache à supprimer
     */
    static void supprimerTache(Tache* tache) {
        TacheManager::getInstance()->supprimerElement(tache);
    }

    /**
     * @brief supprime un projet dans le projet manager
     * @param projet le projet à supprimer
     */
    static void supprimerProjet(Projet* projet) {
        ProjetManager::getInstance()->supprimerElement(projet);
    }


    /**
     * @brief supprime une programmation dans le programmation manager
     * @param programmation la programmation à supprimer
     */
    static void supprimerProgrammation(Programmation* programmation) {
        ProgrammationManager::getInstance()->supprimerElement(programmation);
    }


};

#endif // MODEL_H
