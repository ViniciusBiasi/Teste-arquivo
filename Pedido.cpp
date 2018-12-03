#include "Pedido.h"

Pedido::Pedido()
{
    numero=0;
    status="";
    valortotal=0;
}
std::string Pedido::getdata()
{
    int y,m,d;
    std::string y1,m1,d1;
    data.getDate(&y,&m,&d);
    y1=std::to_string(y);
    m1=std::to_string(m);
    d1=std::to_string(d);

    return (d1+"/"+m1+"/"+y1);
}
