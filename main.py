file = open("test.cpp","w")
str2write = '''#include "Router/router.h"
#include "NI/network_interface.h"

int sc_main(int argc , char *argv[])
{   
    sc_signal<sc_uint<54>,SC_MANY_WRITERS > aw[AXI_NUM_PER_ROUTER],ar[AXI_NUM_PER_ROUTER];
    sc_signal<sc_uint<41>,SC_MANY_WRITERS > w[AXI_NUM_PER_ROUTER],r[AXI_NUM_PER_ROUTER];
    sc_signal<sc_uint<6>,SC_MANY_WRITERS > wr[AXI_NUM_PER_ROUTER];
    sc_signal<sc_bit> awready[AXI_NUM_PER_ROUTER],wready[AXI_NUM_PER_ROUTER],arready[AXI_NUM_PER_ROUTER],rready[AXI_NUM_PER_ROUTER],bready[AXI_NUM_PER_ROUTER];
    sc_signal<sc_bit> awvalid[AXI_NUM_PER_ROUTER],wvalid[AXI_NUM_PER_ROUTER],arvalid[AXI_NUM_PER_ROUTER],rvalid[AXI_NUM_PER_ROUTER],bvalid[AXI_NUM_PER_ROUTER];


    Router A("00");
    A.E_I.write_address_channel(a_aw[0]);
    A.E_I.write_data_channel(a_w[0]);
    A.E_I.read_address_channel(a_ar[0]);
    A.E_I.read_data_channel(a_r[0]);
    A.E_I.write_response_channel(a_wr[0]);
    A.E_I.AWREADY(a_awready[0]);
    A.E_I.WREADY(a_wready[0]);
    A.E_I.ARREADY(a_arready[0]);
    A.E_I.RREADY(a_rready[0]);
    A.E_I.BREADY(a_bready[0]);
    A.E_I.BVALID(bvalid[0]);

    

  

    return 0;
}
'''
file.write(str2write)
file.close()