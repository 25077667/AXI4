#ifndef __BASE_H__
#define __BASE_H__

#define DIRECTION_NUM 2

#include <map>

enum position
{
    east,
    south,
    west,
    north,
    local 
};

enum direction
{
    u_d,    //up_down
    l_r     //left_right
};

enum io_port
{
    I,      //input
    O       //output
};

enum package_type
{
    AW,
    W,
    B,
    NULL_TYPE
};

class Addr_pair
{
    public:
        sc_uint<32> source , target;
};

map<sc_uint<4>,Addr_pair> id_table;
bool id_legal(sc_uint<4> id,sc_uint<32> addr)
{
    if(id_table.find(id) != id_table.end())
        if(id_table[id].target == addr)
            return false;
    else
        return true;
}



#endif