#ifndef PEDIDO_H
#define PEDIDO_H
#include "Pessoa.h"
#include <queue>
#include <QDate>
#include "Item.h"
#include <iostream>

class Pedido: public Pessoa
{
private:
    Item objitem;
    int numero;
    Pessoa cliente;
    std::string status;
    QDate data;
    float valortotal;

public:
    Pedido();
    friend ostream& operator << (ostream& saida,Pedido& pedid)
    {
        saida << "NUMERO DO PEDIDO:"<<pedid.numero<<";"
             << "STATUS:" <<pedid.status<<";"
             << "DATA:" <<pedid.getdata()<<";"
              << "VALOR TOTAL:"<<pedid.valortotal<<";"
             << "QUANTIDADE:" <<pedid.objitem.getquanti()<<";"
              << "PREÇO UNITARIO:"<<pedid.objitem.getpcounitario()<<";"
              << "VALOR TOTAL:"<<pedid.objitem.getvalortotal()<<std::endl;


        return saida;
    }
    void setnumero(int x){numero=x;}
    int getnumero(){return numero;}
    std::string getcliente(){return cliente.getcodigo();}
    void setvalortotal(float x){valortotal=x;}
    float getvalortotal(){return valortotal;}
    void setstatus(std::string status){ this->status=status;}
    std::string getstatus(){return status;}
    void setdata(){data=QDate::currentDate();}
    void setdata(int y,int m,int d);
    std::string getdata();
    void setitem(Item *aux){ objitem=*aux;}
    void setcliente(std::string x)
    {
        cliente.setcodigo(x);
    }

    Pedido* criapedi(std::string linha)
    {
        Pedido* p=new Pedido();
        std::string delimitador=";", atributo;
        unsigned long pos=0;

        atributo = linha.substr(0, linha.find(delimitador));
        p->setnumero(std::stoi(atributo));
        pos=atributo.length()+1;
        linha = linha.substr(pos);
        atributo.erase();

        atributo = linha.substr(0, linha.find(delimitador));
        p->setstatus(atributo);
        pos=atributo.length()+1;
        linha = linha.substr(pos);
        atributo.erase();

        atributo = linha.substr(0, linha.find(delimitador));
        p->setdata();
        pos=atributo.length()+1;
        linha = linha.substr(pos);
        atributo.erase();

        atributo = linha.substr(0, linha.find(delimitador));
        p->setvalortotal(std::stof(atributo));
        pos=atributo.length()+1;
        linha = linha.substr(pos);
        atributo.erase();

        atributo = linha.substr(0, linha.find(delimitador));
        p->objitem.setquanti(std::stoi(atributo));
        pos=atributo.length()+1;
        linha = linha.substr(pos);
        atributo.erase();

        atributo = linha.substr(0, linha.find(delimitador));
        p->objitem.setpcounitario(std::stof(atributo));
        pos=atributo.length()+1;
        linha = linha.substr(pos);
        atributo.erase();

        atributo = linha.substr(0, linha.find(delimitador));
        p->objitem.setvalortotal();
        pos=atributo.length()+1;
        linha = linha.substr(pos);
        atributo.erase();

        return p;

    }
};

#endif // PEDIDO_H
