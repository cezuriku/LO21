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
    TacheComposite(QString _titre,QDateTime _disponibilite,QDateTime _echeance);
    void addElement(Tache * element);
    std::vector<Tache *>& getElement(){return element;}
    void afficher(QStandardItem * parent);
    std::list<Tache*> getUniquePrerequis();
    std::list<Tache*> getTachesUnitaires();
    virtual ~TacheComposite();
};

Q_DECLARE_METATYPE(TacheComposite *)

#endif // TACHECOMPOSITE_H
