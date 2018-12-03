#ifndef PRODUTO_H
#define PRODUTO_H
#include<QString>
using namespace std;

class Produto
{
private:
    int codigo;
    string descricao;
    float preco;
    int quantidade;
public:
    Produto();
    friend ostream& operator << (ostream& saida,Produto &Product)
    {
        saida<<Product.codigo<<";"
             <<Product.descricao<<";"
             <<Product.preco<<";"
             <<Product.quantidade<<std::endl;

        return saida;

    }
    void setCodigo(int codigo){this->codigo=codigo;}
    void setDescricao(string descricao){this->descricao=descricao;}
    void setPreco(float preco){this->preco=preco;}
    void setQuantidade(int quantidade){this->quantidade=quantidade;}

    int getCodigo(){return codigo;}
    string getDescricao(){return descricao;}
    float getPreco(){return preco;}
    int getQuantidade(){return quantidade;}


};

#endif // PRODUTO_H
