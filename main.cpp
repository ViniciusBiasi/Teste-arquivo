#include <iostream>
#include "Pesfisica.h"
#include "Juridica.h"
#include "Pessoa.h"
#include "Pedido.h"
#include <list>
#include <queue>
#include <fstream>
//arq : CLIENTE , ITEM DE PEDIDO , PRODUTO , PEDIDO

int main()
{
    int escolha=0,choose=0;
    Pessoa pess;
    Pesfisica pfis;
    Juridica pjuri;
    Produto prod;
    std::string auxstr;
    int auxint;
    float auxfloat;
    fstream arqfis,arqjuri,arqprod,arqpedi;
    list<Item*> listaItems;
    Item* itmbijeto=nullptr;
    Item itm;
    queue<Pedido*> filapedidos;
    Pedido *pedibijeto=nullptr;
    Pedido pedi;


    string nomeArquivolist = "listaitems.txt", delimitador=";", linha;

    ifstream arquivoi(nomeArquivolist.c_str());
    if(arqfis.fail())
    {
        cout<<"--Arquivo Lista nao aberto--"<<endl;
    }
    else
    {
        getline(arquivoi, linha);
        while(!arquivoi.fail())
        {
            itmbijeto= itmbijeto->criaitem(linha);
            listaItems.push_back(itmbijeto);
            itmbijeto=nullptr;
            getline(arquivoi, linha);
        }
        arquivoi.close();
        cout<<"==Arquivo lido com sucesso=="<<endl;
    }

    string nomeArquivofila = "filapedidos.txt", delimitadorpedidos=";", linhapedi;

    ifstream arquivopedids(nomeArquivofila.c_str());
    if(arqfis.fail())
    {
        cout<<"--Arquivo fila nao aberto--"<<endl;
    }
    else
    {
        getline(arquivopedids, linha);
        while(!arquivopedids.fail())
        {
            pedibijeto= pedibijeto->criapedi(linhapedi);
            filapedidos.push(pedibijeto);
            pedibijeto=nullptr;
            getline(arquivopedids,linhapedi);

        }
        arquivoi.close();
        cout<<"==Arquivo lido com sucesso=="<<endl;
    }



    do
    {
        puts("1-Inserir ou remover cliente");
        puts("2-Inserir produto");
        puts("0-Sair");
        std::cin>>choose;

        switch (choose)
        {
            case 1:

                puts("1 - Fazer pedido para uma Pessoa Fisica ");
                puts("2 - Fazer pedido para uma Pessoa Juridica \n0 - Para sair");
                puts("3 - Excluir pessoa Fisica ");
                puts("4 - Excluir pessoa Juridica ");
                std::cin>>escolha;
                switch (escolha)
                {
                    case 1:

                        arqfis.open("Pedidos Fis.txt",ios::out|ios::in|ios::app);
                        if(arqfis.is_open())
                        {
                            cin.ignore();
                            puts("Insira o codigo ");
                            std::getline(std::cin,auxstr);
                            pfis.setcodigo(auxstr);
                            pedi.setcliente(auxstr);

                            puts("Insira o logradouro");
                            std::getline(std::cin,auxstr);
                            pfis.setlogradouro(auxstr);

                            puts("Insira o setor ");
                            std::getline(std::cin,auxstr);
                            pfis.setsetor(auxstr);

                            puts("Insira o cidade");
                            std::getline(std::cin,auxstr);
                            pfis.setcidade(auxstr);

                            puts("Insira o estado");
                            std::getline(std::cin,auxstr);
                            pfis.setestado(auxstr);

                            puts("Insira o email");
                            std::getline(std::cin,auxstr);
                            pfis.setemail(auxstr);

                            puts("Insira o telefone ");
                            std::cin>>auxint;
                            pfis.settelefone(auxint);

                            puts("Insira o cpf");
                            std::cin.ignore();
                            std::getline(std::cin,auxstr);
                            pfis.validacpf(auxstr);

                            puts("Insira o nome");
                            std::getline(std::cin,auxstr);
                            pfis.setnome(auxstr);

                            puts("Insira o celular");
                            std::cin>>auxint;
                            pfis.setcelular(auxint);

                            puts("Insira o numero do pedido");
                            std::cin>>auxint;
                            pedi.setnumero(auxint);

                            puts("Insira o status do pedido");
                            std::cin.ignore();
                            std::getline(std::cin,auxstr);
                            pedi.setstatus(auxstr);

                            pedi.setdata();

                            puts("Insira a quantidade de Itens");                            
                            std::cin>>auxint;
                            itm.setquanti(auxint);

                            puts("Insira o preço unitario do item");
                            std::cin.ignore();
                            std::cin>>auxfloat;
                            itm.setpcounitario(auxfloat);
                            itm.setvalortotal();
                            pedi.setvalortotal(itm.getvalortotal());

                            puts("Insira o nome do Produto pedido");
                            std::getline(std::cin,auxstr);

                            pedi.setitem(&itm);
                            filapedidos.push(&pedi);
                            listaItems.push_back(&itm);

                            arqfis<<pfis;
                            arqfis<<pedi;
                            arqfis.close();
                        }
                        else
                        {
                            puts("Arquivo não aberto");
                        }
                        break;

                    case 2:


                        arqjuri.open("Pedidos Juri.txt",ios::out|ios::in|ios::app);
                        if(arqjuri.is_open())
                        {
                            cin.ignore();
                            puts("Insira o codigo ");
                            std::getline(std::cin,auxstr);
                            pjuri.setcodigo(auxstr);
                            pedi.setcliente(auxstr);

                            puts("Insira o logradouro");
                            std::getline(std::cin,auxstr);
                            pjuri.setlogradouro(auxstr);

                            puts("Insira o setor ");
                            std::getline(std::cin,auxstr);
                            pjuri.setsetor(auxstr);

                            puts("Insira o cidade");
                            std::getline(std::cin,auxstr);
                            pjuri.setcidade(auxstr);

                            puts("Insira o estado");
                            std::getline(std::cin,auxstr);
                            pjuri.setestado(auxstr);

                            puts("Insira o email");
                            std::getline(std::cin,auxstr);
                            pjuri.setemail(auxstr);

                            puts("Insira o telefone ");

                            std::cin>>auxint;
                            pjuri.settelefone(auxint);

                            puts("Insira o cnpj");
                            std::cin.ignore();
                            std::getline(std::cin,auxstr);
                            pjuri.setCnpj(auxstr);

                            puts("Insira o nome do contato");
                            std::getline(std::cin,auxstr);
                            pjuri.setNomeContato(auxstr);

                            puts("Insira a razão social");
                            std::getline(std::cin,auxstr);
                            pjuri.setRazaoSocial(auxstr);

                            puts("Insira o numero do pedido");
                            std::cin>>auxint;
                            pedi.setnumero(auxint);

                            puts("Insira o status do pedido");
                            std::cin.ignore();
                            std::getline(std::cin,auxstr);
                            pedi.setstatus(auxstr);

                            pedi.setdata();



                            puts("Insira a quantidade de Itens");
                            std::cin>>auxint;
                            itm.setquanti(auxint);

                            puts("Insira o preço unitario do item");
                            std::cin.ignore();
                            std::cin>>auxfloat;
                            itm.setpcounitario(auxfloat);
                            itm.setvalortotal();

                            listaItems.push_back(&itm);
                            pedi.setitem(&itm);

                            listaItems.push_back(&itm);

                            arqjuri<<pjuri;
                            arqjuri<<pedi;
                            arqjuri.close();

                        }
                        else
                        {
                            puts("Arquivo não aberto");
                        }

                        break;

                    default:

                        break;
                }
                break;

            case 2:

                arqprod.open("Produtos.txt",ios::out|ios::in|ios::app);
                if(arqprod.is_open())
                {
                    puts("Digite o codigo do produto");
                    std::cin>>auxint;
                    prod.setCodigo(auxint);

                    puts("Digite a descrição do produto");
                    std::cin.ignore();
                    std::getline(std::cin,auxstr);
                    prod.setDescricao(auxstr);

                    puts("Digite o preço do produto");
                    std::cin>>auxfloat;
                    prod.setPreco(auxfloat);

                    puts("Digite a quantidade de produtos");
                    std::cin>>auxint;
                    prod.setQuantidade(auxint);

                    arqprod<<prod;
                    arqprod.close();

                }
                else
                {
                    puts("Arquivo não aberto");
                }
                break;

            default:

                break;
        }

    }while(escolha!=0&&choose!=0);

}
