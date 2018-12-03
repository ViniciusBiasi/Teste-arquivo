#ifndef PESSOA_H
#define PESSOA_H
//#include <QString>
#include <string>

class Pessoa
{
protected:
    std::string codigo,logradouro,setor,cidade,estado,email;
    int telefone;

public:
    Pessoa();
    std::string getcodigo() {return codigo;}
    std::string getlogradouro() {return logradouro;}
    std::string getsetor() {return setor;}
    std::string getcidade() {return cidade;}
    std::string getestado() {return estado;}
    std::string getemail() {return email;}
    int gettelefone() {return telefone;}
    void setcodigo(std::string aux) {codigo=aux;}
    void setlogradouro(std::string aux) {logradouro=aux;}
    void setsetor(std::string aux) {setor=aux;}
    void setcidade(std::string aux) {cidade=aux;}
    void setestado(std::string aux) {estado=aux;}
    void setemail(std::string aux) {email=aux;}
    void settelefone(int aux) {telefone=aux;}

};

#endif // PESSOA_H
