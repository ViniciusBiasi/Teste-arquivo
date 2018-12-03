#ifndef ITEM_H
#define ITEM_H
#include <list>
#include "Produto.h"

class Item
{
private:

    Produto objproduto;
    int quantidade;
    float pcounitario,valortotal; //pcounitario = Preço unitario;


public:
    Item();
    void setproduto(Produto *aux)
    {
        if(aux!=nullptr)
        {
            objproduto=*aux;
        }
    }
    int getquanti() { return quantidade;}
    float getpcounitario() { return pcounitario;}
    float getvalortotal() { return valortotal;}
    void setquanti(int x) { quantidade=x;}
    void setpcounitario(float x) { pcounitario=x;}
    void setvalortotal() { valortotal=pcounitario*quantidade;}    
    Item* criaitem(std::string linha)
    {
        Item* p=new Item();
        std::string delimitador=";", atributo;
        int pos=0;

        atributo = linha.substr(0, linha.find(delimitador));
        p->setquanti(std::stoi(atributo));
        pos=atributo.length()+1;
        linha = linha.substr(pos);
        atributo.erase();

        atributo = linha.substr(0, linha.find(delimitador));
        p->setpcounitario(std::stof(atributo));
        pos=atributo.length()+1;
        linha = linha.substr(pos);
        atributo.erase();

        p->setvalortotal();

        return p;

    }



};

#endif // ITEM_H
