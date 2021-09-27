#include "package.h"
#include <cstdlib>
Base_package& pack(package_type t,int data,sc_uint<32> addr)
{
    Base_package *real_package;
    sc_uint<4> id = 0;
    do
    {
        id = rand()%16;
    }while(!id_legal(id,addr));
    switch(t)
    {
        case AW:
            real_package = new Write_Addr(id,data);
            break;
        case W:
            real_package = new Write_Data(id,data);
        case B:
            real_package = new Write_Responce(id,data);
        default:
            break;
    }
    return *real_package;
}

Package_data unpack(Base_package &p)
{
    switch(p.get_type())
    {
        case AW:
            return Package_data(AW,p.get().range(54,51),p.get().range(50,19));
            break;
        case W:
            return Package_data(W,p.get().range(54,51),p.get().range(50,19));
            break;
        case B:
            return Package_data(B,p.get().range(54,51),0);
        default:
            return Package_data(NULL_TYPE,0,0);
            break;
    }
}