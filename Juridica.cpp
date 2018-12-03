#include "Juridica.h"

Juridica::Juridica()
{
    cnpj=razaoSocial=nomeContato="";
}
bool Juridica::setCnpj(string x)
{
    unsigned int i,y,z;

        if(x.length()!=14)
        {
            cout<<"\nTamanho invalido\n";
            cnpj=x;
            return false;
        }
        else
        {
            int vet[13]{6,5,4,3,2,9,8,7,6,5,4,3,2};
            int aux[x.length()];
            for(i=0;i!=x.length();i++)
            {
                std::string u=x.substr(i,1);
                aux[i]=std::stoi(u);
            }
            int resmultip1=0;

            z=1;
            for(y=0;y<12;y++)
            {
                resmultip1=resmultip1+(aux[y]*vet[z]);
                z++;
            }

            resmultip1=resmultip1%11;

            if(resmultip1<2)
            {
                resmultip1=0;
            }
            else
            {
                resmultip1=11-resmultip1;
            }

            int resmultip2=0;
            z=0;
            for(int t=0;t<13;t++)
            {

                resmultip2=resmultip2+(aux[t]*vet[z]);
                z++;

            }
            resmultip2=resmultip2%11;

            if(resmultip2<2)
            {
                resmultip2=0;
            }
            else
            {
                resmultip2=11-resmultip2;
            }

            if(resmultip1==aux[12]&&resmultip2==aux[13])
            {
                std::cout<<"\nvalido\n";
                cnpj=x;
                return true;
            }
            else
            {
                std::cout<<"\ninvalido\n";
                cnpj=x;
                return false;
            }
    }
}
