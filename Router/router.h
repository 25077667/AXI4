#ifndef __ROUTER_H__
#define __ROUTER_H__
#include <systemc.h>
#include <queue>
#include "../PKG/package.h"


#define MAX_ADDR_SIZE  3
#define MAX_DATA_SIZE  6
#define AXI_NUM_PER_ROUTER 5
#define IO_PORT_NUM 2

using namespace std;

class AXI
{
    public:
        //channel
        sc_inout<Write_Addr> write_address_channel;
        sc_inout<Write_Data> write_data_channel;
        sc_inout<Write_Responce> write_response_channel;
        //READY
        sc_inout<bool> AWREADY , WREADY , BREADY;
        //VALID
        sc_inout<bool> AWVALID , WVALID , BVALID;
};

class Buffer
{
    public: 
        queue<Write_Addr> write_addr;
        queue<Write_Data> write_data;
        queue<Write_Responce> write_response;
};

SC_MODULE(Router)
{
    sc_in_clk clk;
    //five direction
    AXI I[AXI_NUM_PER_ROUTER],O[AXI_NUM_PER_ROUTER];
    //buf:buffer [nsewl]:direction [io]:input/output
    Buffer i[AXI_NUM_PER_ROUTER],o[AXI_NUM_PER_ROUTER];
    map<sc_uint<4>,Pkg_pair> register_table;
    void input();
    void output();
    void rout(Base_package &,package_type t);
    void ready();
    void valid();
    void f();
    SC_CTOR(Router)
    {
        SC_METHOD(input);
            sensitive << clk.pos();
        SC_METHOD(output);
            sensitive << clk.neg();
    }
};


#endif