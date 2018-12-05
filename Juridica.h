#ifndef JURIDICA_H
#define JURIDICA_H
#include "Pessoa.h"
#include <iostream>
#include <sstream>
#include <QString>

using namespace std;

class Juridica: public Pessoa
{
protected:
    string cnpj;
    string razaoSocial;
    string nomeContato;
public:
    Juridica();
    friend ostream& operator << (ostream& os, Juridica& Pessoa){
        os   << "CODIGO:" << Pessoa.codigo               <<";"
             << "CNPJ:" << Pessoa.cnpj                 <<";"
             << "RAZÃO SOCIAL:" << Pessoa.razaoSocial    <<";"
             << "NOME CONTATO:"<< Pessoa.nomeContato     <<";"
             << "LOGRADOURO:"<< Pessoa.logradouro        <<";"
             << "SETOR:"<< Pessoa.setor                  <<";"
             << "CIDADE:"<< Pessoa.cidade                <<";"
             << "ESTADO:" << Pessoa.estado               <<";"
             <<"TELEFONE:"<< Pessoa.telefone             <<";"
             << "EMAIL:"<< Pessoa.email                  <<::endl;
        return os;
    }

    bool setCnpj(string x);
    void setRazaoSocial(string razaoSocial){this->razaoSocial=razaoSocial;}
    void setNomeContato(string nomeContato){this->nomeContato=nomeContato;}

    string getCnpj(){return cnpj;}
    string getRazaoSocial(){return razaoSocial;}
    string getNomeContato(){return nomeContato;}

};

#endif // JURIDICA_H
