#ifndef __NETWORK_INTERFACE_H__
#define __NETWORK_INTERFACE_H__

#include <iostream>
#include <systemc.h>
using namespace std;

typedef unsigned char Byte;
typedef unsigned int Int;


class Write_Addr
{
    private:
        //define signals
        sc_uint<54> data;
    public:
        //define constructors
        sc_uint<54> get() {return data;}
        Write_Addr(sc_uint<4> awid = 0,sc_uint<32> awaddr = 0,sc_uint<4>awlen = 0,sc_uint<3>awsize = 0,sc_uint<2>awburst = 0,sc_uint<2>awlock = 0,sc_uint<4>awcache = 0,sc_uint<3>awport = 0);
};

class Write_Data
{
    private:
        //define signals
        sc_uint<41> data;
    public:
        //define constructors
        sc_uint<41> get() {return data;}
        Write_Data(sc_uint<4> wid = 0,sc_uint<32> wdata = 0,sc_uint<4> wstrb = 0,sc_uint<1> wlast = 0);
};

class Write_Responce
{
    private:
        //define signals
        sc_uint<6> data; 
    public:
        //define constructors
        sc_uint<6> get() {return data;}
        Write_Responce(sc_uint<4> bid = 0,sc_uint<2> bresp = 0);
};

class Read_Addr
{
    private:
        //define signals
        sc_uint<54> data;
    public:
        //define constructors
        sc_uint<54> get() {return data;}
        Read_Addr(sc_uint<4> arid = 0,sc_uint<32> araddr = 0,sc_uint<4>arlen = 0,sc_uint<3>arsize = 0,sc_uint<2>arburst = 0,sc_uint<2>arlock = 0,sc_uint<4>arcache = 0,sc_uint<3>arport = 0);
};

class Read_Data
{
    private:
        //define signals
        sc_uint<41> data;
    public:
        //define constructors
        sc_uint<41> get() {return data;}
        Read_Data(sc_uint<4> rid = 0,sc_uint<32> rdata = 0,sc_uint<4> rstrb = 0,sc_uint<1> rlast = 0);
};


#endif