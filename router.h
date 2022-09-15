#ifndef __ROUTER_H__
#define __ROUTER_H__
#include "AXI4.h"
#include "systemc.h"


SC_MODULE(Router)
{
    sc_in_clk clk;
    IO_Port N,E,S,W,L;  //north,east,south,west,local;
    Buffer b_N,b_E,b_S,b_W,b_L;
    void push();    //push package of all position
    void pop();     //pop package of all position
    void route();   //放入正確方向的buffer等待push出去下一個router
    void initialize()   //instead of using SC_CTOR as constructor
    SC_CTOR(Router)
    {
        initialize();
        SC_METHOD(push);
            sensitive << clk;
        SC_METHOD(pop);
            sensitive << clk;
        SC_METHOD(route);
            sensitive << clk;
    }
};

#endif