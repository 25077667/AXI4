#include "Router/router.h"
#include "NI/network_interface.h"

int sc_main(int argc , char *argv[])
{   
    //sc_signal<sc_bv<32>,SC_MANY_WRITERS > b1,b2,b3,b4,b5,b6;
    sc_signal<sc_uint<54>,SC_MANY_WRITERS > a_aw[AXI_NUM_PER_ROUTER],a_ar[AXI_NUM_PER_ROUTER],b_aw[AXI_NUM_PER_ROUTER],b_ar[AXI_NUM_PER_ROUTER];
    sc_signal<sc_uint<41>,SC_MANY_WRITERS > a_w[AXI_NUM_PER_ROUTER],a_r[AXI_NUM_PER_ROUTER],b_w[AXI_NUM_PER_ROUTER],b_r[AXI_NUM_PER_ROUTER];
    sc_signal<sc_uint<6>,SC_MANY_WRITERS > a_wr[AXI_NUM_PER_ROUTER],b_wr[AXI_NUM_PER_ROUTER];
    sc_signal<sc_bit> a_awready[AXI_NUM_PER_ROUTER],a_wready[AXI_NUM_PER_ROUTER],a_arready[AXI_NUM_PER_ROUTER],a_rready[AXI_NUM_PER_ROUTER],a_bready[AXI_NUM_PER_ROUTER];
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

    A.W_I.write_address_channel(a_aw[1]);
    A.W_I.write_data_channel(a_w[1]);
    A.W_I.read_address_channel(a_ar[1]);
    A.W_I.read_data_channel(a_r[1]);
    A.W_I.write_response_channel(a_wr[1]);
    A.W_I.AWREADY(a_awready[1]);
    A.W_I.WREADY(a_wready[1]);
    A.W_I.ARREADY(a_arready[1]);
    A.W_I.RREADY(a_rready[1]);
    A.W_I.BREADY(a_bready[1]);
    A.W_I.BVALID(bvalid[1]);

    A.N_I.write_address_channel(a_aw[2]);
    A.N_I.write_data_channel(a_w[2]);
    A.N_I.read_address_channel(a_ar[2]);
    A.N_I.read_data_channel(a_r[2]);
    A.N_I.write_response_channel(a_wr[2]);
    A.N_I.AWREADY(a_awready[2]);
    A.N_I.WREADY(a_wready[2]);
    A.N_I.ARREADY(a_arready[2]);
    A.N_I.RREADY(a_rready[2]);
    A.N_I.BREADY(a_bready[2]);
    A.N_I.BVALID(bvalid[2]);

    A.S_I.write_address_channel(a_aw[3]);
    A.S_I.write_data_channel(a_w[3]);
    A.S_I.read_address_channel(a_ar[3]);
    A.S_I.read_data_channel(a_r[3]);
    A.S_I.write_response_channel(a_wr[3]);
    A.S_I.AWREADY(a_awready[3]);
    A.S_I.WREADY(a_wready[3]);
    A.S_I.ARREADY(a_arready[3]);
    A.S_I.RREADY(a_rready[3]);
    A.S_I.BREADY(a_bready[3]);
    A.S_I.BVALID(bvalid[3]);

    A.L_I.write_address_channel(a_aw[4]);
    A.L_I.write_data_channel(a_w[4]);
    A.L_I.read_address_channel(a_ar[4]);
    A.L_I.read_data_channel(a_r[4]);
    A.L_I.write_response_channel(a_wr[4]);
    A.L_I.AWREADY(a_awready[4]);
    A.L_I.WREADY(a_wready[4]);
    A.L_I.ARREADY(a_arready[4]);
    A.L_I.RREADY(a_rready[4]);
    A.L_I.BREADY(a_bready[4]);
    A.L_I.BVALID(bvalid[4]);

    A.E_O.write_address_channel(a_aw[5]);
    A.E_O.write_data_channel(a_w[5]);
    A.E_O.read_address_channel(a_ar[5]);
    A.E_O.read_data_channel(a_r[5]);
    A.E_O.write_response_channel(a_wr[5]);
    A.E_O.AWREADY(a_awready[5]);
    A.E_O.WREADY(a_wready[5]);
    A.E_O.ARREADY(a_arready[5]);
    A.E_O.RREADY(a_rready[5]);
    A.E_O.BREADY(a_bready[5]);
    A.E_O.BVALID(bvalid[5]);

    A.W_O.write_address_channel(a_aw[6]);
    A.W_O.write_data_channel(a_w[6]);
    A.W_O.read_address_channel(a_ar[6]);
    A.W_O.read_data_channel(a_r[6]);
    A.W_O.write_response_channel(a_wr[6]);
    A.W_O.AWREADY(a_awready[6]);
    A.W_O.WREADY(a_wready[6]);
    A.W_O.ARREADY(a_arready[6]);
    A.W_O.RREADY(a_rready[6]);
    A.W_O.BREADY(a_bready[6]);
    A.W_O.BVALID(bvalid[6]);

    A.N_O.write_address_channel(a_aw[7]);
    A.N_O.write_data_channel(a_w[7]);
    A.N_O.read_address_channel(a_ar[7]);
    A.N_O.read_data_channel(a_r[7]);
    A.N_O.write_response_channel(a_wr[7]);
    A.N_O.AWREADY(a_awready[7]);
    A.N_O.WREADY(a_wready[7]);
    A.N_O.ARREADY(a_arready[7]);
    A.N_O.RREADY(a_rready[7]);
    A.N_O.BREADY(a_bready[7]);
    A.N_O.BVALID(bvalid[7]);
    
    A.S_O.write_address_channel(a_aw[8]);
    A.S_O.write_data_channel(a_w[8]);
    A.S_O.read_address_channel(a_ar[8]);
    A.S_O.read_data_channel(a_r[8]);
    A.S_O.write_response_channel(a_wr[8]);
    A.S_O.AWREADY(a_awready[8]);
    A.S_O.WREADY(a_wready[8]);
    A.S_O.ARREADY(a_arready[8]);
    A.S_O.RREADY(a_rready[8]);
    A.S_O.BREADY(a_bready[8]);
    A.S_O.BVALID(bvalid[8]);

    A.L_O.write_address_channel(a_aw[9]);
    A.L_O.write_data_channel(a_w[9]);
    A.L_O.read_address_channel(a_ar[9]);
    A.L_O.read_data_channel(a_r[9]);
    A.L_O.write_response_channel(a_wr[9]);
    A.L_O.AWREADY(a_awready[9]);
    A.L_O.WREADY(a_wready[9]);
    A.L_O.ARREADY(a_arready[9]);
    A.L_O.RREADY(a_rready[9]);
    A.L_O.BREADY(a_bready[9]);
    A.L_O.BVALID(bvalid[9]);


    /*Router b("21");
    b.channel_north(b1);
    b.channel_south(b2);
    b.channel_east(b6);
    b.channel_west(b3);
    b.channel_local(b5);
    sc_start();
    a.set_position(2,2);
    b.set_position(2,1);
    b4.write("11111111111111111111111111111111");
    sc_start();
    cout << b6.read() << endl;*/
    //b.print();
        
    //Write_Addr test = Write_Addr((Byte)3,(Int)12);
    //cout << test << endl;

    return 2;
}
