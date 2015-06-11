#include <list>
#include "projetmanager.h"

void ProjetManager::afficher(QStandardItemModel * model)
{
    QStandardItem *item;

    for(std::list<Projet *>::iterator it=getInstance()->getListe().begin();it!=getInstance()->getListe().end();++it)
    {
        item=new QStandardItem((*it)->getTitre());
        item->setData(QVariant::fromValue((*it)),Qt::UserRole+1);
        model->appendRow(item);
    }
}
