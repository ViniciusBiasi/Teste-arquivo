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
    int escolha,choose;
    Pessoa pess;
    Pesfisica pfis;
    Juridica pjuri;
    std::string auxstr;
    int auxint;
    float auxfloat;
    fstream arqfis,arqjuri,arqprod,arqpedi,arquivolist;
    list<Produto> plist;
    Produto prod;
    list<Item*> listaItems;
    Item* itmbijeto=nullptr;
    Item itm;
    queue<Pedido*> filapedidos;
    Pedido *pedibijeto=nullptr;
    Pedido pedi;
    long telefone;



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
            throw std::invalid_argument("Invalid syntax.");
            itmbijeto= itmbijeto->criaitem(linha);
            listaItems.push_back(itmbijeto);
            itmbijeto=nullptr;
            getline(arquivoi, linha);
        }
        arquivoi.close();
        cout<<"==Arquivo Lista lido com sucesso=="<<endl;
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
            try
            {
                pedibijeto= pedibijeto->criapedi(linhapedi);
            }
            catch(invalid_argument)
            {
                filapedidos.push(pedibijeto);
                pedibijeto=nullptr;
                getline(arquivopedids,linhapedi);
            }

        }
        arquivoi.close();
        cout<<"==Arquivo Fila lido com sucesso=="<<endl;
    }



    do
    {
        choose=escolha=0;
        puts("1-Inserir ou remover cliente");
        puts("2-Inserir produto");
        puts("3-Apagar dados do arquivo");

        puts("0-Sair");
        std::cin>>choose;

        switch (choose)
        {

            case 1:

                puts("1 - Fazer pedido para uma Pessoa Fisica ");
                puts("2 - Fazer pedido para uma Pessoa Juridica ");
                puts("3 - Excluir pessoa Fisica ");
                puts("4 - Excluir pessoa Juridica \n0 - Para sair");
                std::cin>>escolha;
                switch (escolha)
                {
                    case 1:

                        arqfis.open("Pesssoas Fis.txt",ios::out|ios::in|ios::app);
                        arqpedi.open("filapedidos.txt",ios::out|ios::in|ios::app);
                        arquivolist.open("listaitems.txt",ios::out|ios::in|ios::app);
                        if(arqfis.is_open())
                        {
                            if(arqpedi.is_open())
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
                                std::cin>>telefone;
                                pfis.settelefone(telefone);

                                puts("Insira o cpf");
                                std::cin.ignore();
                                std::getline(std::cin,auxstr);
                                pfis.validacpf(auxstr);

                                puts("Insira o nome");
                                std::getline(std::cin,auxstr);
                                pfis.setnome(auxstr);

                                puts("Insira o celular");
                                std::cin>>telefone;
                                pfis.setcelular(telefone);

                                puts("Insira o numero do pedido");
                                std::cin>>auxint;
                                pedi.setnumero(auxint);

                                puts("Insira o status do pedido");
                                std::cin.ignore();
                                std::getline(std::cin,auxstr);
                                pedi.setstatus(auxstr);

                                pedi.setdata();

                                if(arquivolist.is_open())
                                {
                                    puts(" Insira a quantidade de Itens");
                                    std::cin>>auxint;
                                    itm.setquanti(auxint);

                                    puts(" Insira o preço unitario do item");
                                    std::cin.ignore();
                                    std::cin>>auxfloat;
                                    itm.setpcounitario(auxfloat);
                                    itm.setvalortotal();
                                    pedi.setvalortotal(itm.getvalortotal());

                                    puts(" Insira o nome do Produto pedido");
                                    std::cin.ignore();
                                    std::getline(std::cin,auxstr);

                                    //itm.buscaprod() precisa buscar o item para saber se ele existe.



                                    pedi.setitem(&itm);
                                    filapedidos.push(&pedi);
                                    listaItems.push_back(&itm);

                                    arqpedi<<pedi;
                                    arqfis<<pfis;
                                    arqfis.close();
                                }
                            }
                        }
                        else
                        {
                            puts("Arquivo não aberto");
                        }
                        break;

                    case 2:


                        arqjuri.open("Pessoas Juri.txt",ios::out|ios::in|ios::app);
                        arqpedi.open("filapedidos.txt",ios::out|ios::in|ios::app);
                        if(arqjuri.is_open())
                        {
                            if(arqpedi.is_open())
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
                                std::cin>>telefone;
                                pjuri.settelefone(telefone);

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

                                for(auto i=plist.begin();i!=plist.end();i++)
                                {

                                    listaItems.push_back(&itm);
                                }


                                pedi.setitem(&itm);
                                listaItems.push_back(&itm);

                                arqpedi<<pedi;
                                arqjuri<<pjuri;
                                arqjuri.close();
                            }

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

                    plist.push_back(prod);
                    arqprod<<prod;
                    arqprod.close();

                }
               else
                {
                    puts("Arquivo não aberto");
                }
                break;

        case 3:

            // EXCLUSÃO DOS DADOS DOS ARQUIVOS

            puts("DIGITE A LETRA: w PARA APAGAR TODOS OS DADOS ARMAZENADOS NOS ARQUIVOS... \n");

            fclose(fopen("filapedidos.txt", "w"));
            fclose(fopen("Pessoas Juri.txt","w"));
            fclose(fopen("listaitems.txt", "w"));
            fclose(fopen("Pesssoas Fis.txt", "w"));
            fclose(fopen("Produtos.txt", "w"));

            break;


            default:

                break;
        }


    }while(escolha!=0||choose!=0);


}


