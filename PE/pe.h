#ifndef __PE_H__
#define __PE_H__

#define PE_SIZE 4

#define PIXEL_SIZE 8 //2 hexical per pixel
#include <systemc.h>



SC_MODULE(Convolution)
{
    sc_in_clk clk;
    sc_in<int[2][5][5]> input_data;
    sc_out<int> output_data;
    void f();
    SC_CTOR(Convolution)
    {
        SC_METHOD(f);
        sensitive << clk.pos();
    }
    
};

SC_MODULE(Pooling)
{
    sc_in_clk clk;
    sc_in<int> input_data;
    int counter,data[4]; 
    sc_out<int> output_data;
    void f();
    void input();
    SC_CTOR(Pooling)
    {
        counter = 0;
        SC_METHOD(f);
        sensitive << clk.pos();
    }
};

#endif