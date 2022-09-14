#ifndef __ROUTER_H__
#define __ROUTER_H__

#include "systemc.h"
#include <queue>

#define DATA_SIZE 1
#define MAX_BUFFER_SIZE 3

class AXI4_Stream_protocol
{
    public:
        unsigned ACLK : 1;
        unsigned ARESETn : 1;
        unsigned TVALID : 1;
        unsigned TREADY : 1;
        unsigned TDATA : 8*DATA_SIZE;
        unsigned TSTRB : DATA_SIZE;
        unsigned TKEEP : DATA_SIZE;
        unsigned TLAST : 1;
        unsigned TID : 16           //同時能有16個封包在4*4 mesh上
        unsigned TDEST : 16         //4*4 mesh
        //unsigned TUSER : 16       //還不知道要多大
};

class AXI4_Stream_package
{
    public:
        unsigned TDATA : 8*DATA_SIZE;
        unsigned TSTRB : DATA_SIZE;
        unsigned TKEEP : DATA_SIZE;
        unsigned TLAST : 1;
        unsigned TID : 16           //同時能有16個封包在4*4 mesh上
        unsigned TDEST : 16         //4*4 mesh
        //unsigned TUSER : 16       //還不知道要多大
}

class IO_Port
{
    public:
        AXI4_Stream_protocol in;
        AXI4_Stream_protocol out;
};

class Buffer
{
    public:
        queue<AXI4_Stream_package> buf;
        bool full()
        {
            return (buf.size() >= MAX_BUFFER_SIZE) ? true : false;
        }
};

SC_MODULE(router)
{
    sc_in_clk clk;
    IO_Port N,E,S,W,L;  //north,east,south,west,local;
    Buffer b_N,b_E,b_S,b_W,b_L;
    void push();    //push package of all position
    void pop();     //pop package of all position
    void route();   //放入正確方向的buffer等待push出去下一個router
    SC_CTOR(router)
    {
        SC_METHOD(push);
            sensitive << clk;
        SC_METHOD(pop);
            sensitive << clk;
        SC_METHOD(route);
            sensitive << clk;
    }
};