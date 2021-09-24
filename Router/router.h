#ifndef __ROUTER_H__
#define __ROUTER_H__
#include <systemc.h>
#include <queue>
#include "../Base/Base.h"

#define MAX_ADDR_SIZE  3
#define MAX_DATA_SIZE  6
#define AXI_NUM_PER_ROUTER 5
#define IO_PORT_NUM 2

using namespace std;

class AXI
{
    public:
        //channel
        sc_inout<sc_uint<54> > write_address_channel;
        sc_inout<sc_uint<41> > write_data_channel;
        sc_inout<sc_uint<6> > write_response_channel;
        //READY
        sc_inout<bool> AWREADY , WREADY , BREADY;
        //VALID
        sc_inout<bool> AWVALID , WVALID , BVALID;
};

class Buffer
{
    public: 
        queue<sc_uint<54> > write_addr;
        queue<sc_uint<41> > write_data;
        queue<sc_uint<6> > write_response;
};

SC_MODULE(Router)
{
    sc_in_clk clk;
    //five direction
    AXI I[AXI_NUM_PER_ROUTER],O[AXI_NUM_PER_ROUTER];
    //buf:buffer [nsewl]:direction [io]:input/output
    Buffer i[AXI_NUM_PER_ROUTER],o[AXI_NUM_PER_ROUTER];
    map<sc_uint<4>,position> register_table;
    void input();
    void output();
    SC_CTOR(Router)
    {
        SC_METHOD(input);
            sensitive << clk.pos();
        SC_METHOD(output);
            sensitive << clk.neg();
    }
};


#endif