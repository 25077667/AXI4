#ifndef __AXI_H__
#define __AXI_H__
#include <systemc.h>
#include <queue>

#define MAX_ADDR_SIZE  3
#define MAX_DATA_SIZE  6

using namespace std;

class AXI
{
    public:
        //channel
        sc_inout<sc_bv<32> > read_address_channel, read_data_channel , write_address_channel , write_data_channel , write_response_channel;
        //READY
        sc_inout<sc_bit> AWREADY , WREADY , ARREADY , RREADY , BREADY;
        //VALID
        sc_inout<sc_bit> AWVALID , WVALID , ARVALID , RVALID , BVALID;
};

class Buffer
{
    public:
        queue<sc_bv<32> > write_data , read_data , write_addr , read_addr; 
};

SC_MODULE(Router)
{
    sc_in_clk clk;
    //five direction
    AXI N_I , N_O , S_I , S_O , E_I , E_O , W_I , W_O , L_I , L_O;
    //buf:buffer [nsewl]:direction [io]:input/output
    Buffer buf_ni , buf_no , buf_si , buf_so , buf_ei , buf_eo , buf_wi , buf_wo , buf_li , buf_lo;
    void input();
    void output();
    SC_CTOR(Router)
    {
        SC_METHOD(input);
            sensitive << clk.pos();
        SC_METHOD(output);
            sensitive << clk.pos();
    }
};


#endif