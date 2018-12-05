#ifndef CPF_H
#define CPF_H
#include <string>
#include <iostream>
#include <ostream>
#include <QString>
#include "Pessoa.h"

using namespace std;

class Pesfisica : public Pessoa
{
private:
    string cdpessoafis;
    string nome;
    long celular;

public:
    Pesfisica();
    friend ostream& operator << (ostream& saida,Pesfisica& Pessoa)
    {
       saida  << "CODIGO:"<<Pessoa.codigo <<";"
             << "NOME:"<< Pessoa.nome       <<";"
             << "CPF:"<< Pessoa.cdpessoafis<<";"
            << "CELULAR:" << Pessoa.celular    <<";"
             << "LOGRADOURO:"<< Pessoa.logradouro <<";"
            << "SETOR:" << Pessoa.setor      <<";"
            << "CIDADE:" << Pessoa.cidade     <<";"
             << "ESTADO:" << Pessoa.estado     <<";"
             << "TELEFONE:"<< Pessoa.telefone   <<";:"
             << "EMAIL:"<< Pessoa.email      <<endl;

        return saida;
    }
    bool validacpf(string);
    void setnome(string x){nome=x;}
    string getnome(){return nome;}
    void setcelular(long num){celular=num;}
    long getcelular(){return celular;}

};
#endif // CPF_H
