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

sc_uint<54> pack_addr(Package_data x)
{
    sc_uint<54> package;
    package.range(53,50) = x.id;
    package.range(49,18) = x.data;
    package.range(17,0) = 0;
    return package;
}

sc_uint<41> pack_data(Package_data x)
{
    sc_uint<41> package;
    package.range(40,37) = x.id;
    package.range(36,5) = x.data;
    package.range(4,1) = 0;
    package[0] = x.is_last;
    return package;
}

sc_uint<6> pack_resp(Package_data x)
{
    sc_uint<6> package;
    package.range(5,2) = x.id;
    package.range(1,0) = x.data;
    return package;
}

Package_data unpack(package_type t,sc_uint<54> data)
{
    switch(t)
    {
        case AW:
            return Package_data(AW,data.range(53,50),data.range(49,18),false);
            break;
        case W:
            return Package_data(W,data.range(40,37),data.range(36,5),bool(data[0]));
            break;
        case B:
            return Package_data(B,data.range(5,2),0,false);
        default:
            return Package_data(NULL_TYPE,0,0,false);
            break;
    }
}