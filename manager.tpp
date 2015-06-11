template<typename Type>
Manager<Type>::Manager()
{

}

template<typename Type>
Manager<Type>::~Manager()
{

}

template<typename Type>
void Manager<Type>::ajouterElement(Type * element)
{
    liste.push_back(element);
    trier();
}

template<typename Type>
void Manager<Type>::supprimerElement(Type * element)
{
    liste.erase(std::remove(liste.begin(),liste.end(),element),liste.end());
}

template<typename Type>
void Manager<Type>::trier()
{
    liste.sort(typeInferieur());
}
