#ifndef __PE_H__
#define __PE_H__

#define PE_SIZE 4

#include <systemc.h>

class Convolution
{
    public:
        int data[5][5],kernel[5][5];
        int output;
        void f();
};

class Pooling
{
    public:
        int data[4];
        int output;
        void f();
};

SC_MODULE(Layer12)
{
    sc_in_clk clk;
    sc_in<int[4][5][5]> input_data;
    sc_in<int[5][5]> input_kernel;
    sc_out<int> output_data;
    Convolution conv[4];
    Pooling pool;
    void f();
    SC_CTOR(Layer12)
    {
        SC_METHOD(f);
        sensitive << clk.pos();
    }
};

SC_MODULE(Layer34)
{
    sc_in_clk clk;
    SC_CTOR(Layer34)
    {

    }
};
/*SC_MODULE(Convolution)
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
};*/

#endif