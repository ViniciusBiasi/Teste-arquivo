#include "Item.h"

Item::Item()
{
    quantidade=0;
    pcounitario=valortotal=0;
}
bool Item::buscaprod(Produto* aux)
{

    if(aux->getDescricao()!=objproduto||aux==nullptr)
    {
        return false;
    }
    else
    {
        busca=aux;
        return true;
    }
}
