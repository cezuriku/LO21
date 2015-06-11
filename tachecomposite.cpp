#include "tachecomposite.h"

TacheComposite::TacheComposite(QString _titre, QDateTime _disponibilite, QDateTime _echeance):
    Tache(_titre,_disponibilite,_echeance)
{

}

TacheComposite::~TacheComposite()
{
    for(unsigned long i=0;i<element.size();i++)
    {
        delete(element[i]);
        element[i]=0;
    }
}

void TacheComposite::addElement(Tache * _element)
{
    if(_element==this)
    {
        throw CalendarException("Tentative d'auto inclusion");
    }
    element.push_back(_element);
    std::sort(element.begin(),element.end(),compareTache());
    _element->setParent(this);
}

void TacheComposite::afficher(QStandardItem * parent)
{
    QStandardItem *item;

    for(std::vector<Tache *>::iterator it=this->element.begin();it!=this->element.end();++it)
    {
        item=new QStandardItem((*it)->getTitre());
        item->setData(QVariant::fromValue((*it)),Qt::UserRole+2);
        parent->appendRow(item);
        (*it)->afficher(item);

    }
}


std::list<Tache *> TacheComposite::getUniquePrerequis()
{
    std::list<Tache*> result,part;
    for(std::vector<Tache *>::iterator it=this->prerequis.begin();it!=this->prerequis.end();++it)
    {
        if(dynamic_cast<TacheUnitaire*>((*it))!=NULL)
        {
            result.push_back((*it));
        }
        else
        {
            part=dynamic_cast<TacheComposite*>((*it))->getTachesUnitaires();
            result.merge(part);
        }
    }

    if(getParent()!=NULL)
    {
        part=dynamic_cast<TacheComposite*>(getParent())->getUniquePrerequis();
        result.merge(part);
    }

    return result;
}

std::list<Tache *> TacheComposite::getTachesUnitaires()
{
    std::list<Tache*> result,part;
    foreach(Tache* ptr,this->element)
    {
        if(dynamic_cast<TacheUnitaire*>(ptr)!=NULL)
        {
            result.push_back(ptr);
        }
        else
        {
            part=dynamic_cast<TacheComposite*>(ptr)->getTachesUnitaires();
            result.merge(part);
        }
    }
    return result;
}
