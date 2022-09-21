#ifndef __ROUTER_H__
#define __ROUTER_H__
#include "AXI4.h"
#include "systemc.h"

#define POS_NUM 5

class Point
{
    public:
        int x,y;
        Point() {x=y=0;}
        Point(int a,int b) {x=a;y=b;}
};

SC_MODULE(Router)
{
    sc_in_clk clk;
    IO_Port io[POS_NUM];  //north,east,south,west,local;
    Buffer buf[POS_NUM]; 
    queue<AXI4_Stream_package>local_buf;    //when package pop from input buffer and the output buffer is full,the pacakge push to this buffer
    void push();    //push package of all position
    void pop();     //pop package of all position
    void route();   //放入正確方向的buffer等待push出去下一個router
    void initialize();  //instead of using SC_CTOR as constructor
    Point now;
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

position find_position(unsigned);

#endif