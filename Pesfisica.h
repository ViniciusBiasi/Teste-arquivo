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
    int celular;

public:
    Pesfisica();
    friend ostream& operator << (ostream& saida,Pesfisica& Pessoa)
    {
       saida <<Pessoa.codigo <<";"
            << Pessoa.nome       <<";"
            << Pessoa.cdpessoafis<<";"
            << Pessoa.celular    <<";"
            << Pessoa.logradouro <<";"
            << Pessoa.setor      <<";"
            << Pessoa.cidade     <<";"
            << Pessoa.estado     <<";"
            << Pessoa.telefone   <<";:"
            << Pessoa.email      <<endl;

        return saida;
    }
    bool validacpf(string);
    void setnome(string x){nome=x;}
    string getnome(){return nome;}
    void setcelular(int num){celular=num;}
    int getcelular(){return celular;}

};
#endif // CPF_H
