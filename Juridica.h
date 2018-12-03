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
        os  << Pessoa.codigo    <<";"
            << Pessoa.cnpj         <<";"
            << Pessoa.razaoSocial    <<";"
            << Pessoa.nomeContato    <<";"
            << Pessoa.logradouro     <<";"
            << Pessoa.setor          <<";"
            << Pessoa.cidade         <<";"
            << Pessoa.estado         <<";"
            << Pessoa.telefone       <<";"
            << Pessoa.email          <<::endl;
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
