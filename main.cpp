#include "Router/router.h"
#include "NI/network_interface.h"
int sc_main(int argc , char *argv[])
{
           
    int x,y;
    x = 3;
    y = 4;
    //Write Address Channel
    sc_signal<sc_uint<54>,SC_MANY_WRITERS > aw[IO_PORT_NUM][DIRECTION_NUM][3][4+1];
    sc_signal<sc_uint<54>,SC_MANY_WRITERS > aw_local[IO_PORT_NUM][3][4];
    //Write Data Channel
    sc_signal<sc_uint<41>,SC_MANY_WRITERS > w[IO_PORT_NUM][DIRECTION_NUM][3][4+1];
    sc_signal<sc_uint<41>,SC_MANY_WRITERS > w_local[IO_PORT_NUM][3][4];
    //Write Response Channel
    sc_signal<sc_uint<6>,SC_MANY_WRITERS > b[IO_PORT_NUM][DIRECTION_NUM][3][4+1];
    sc_signal<sc_uint<6>,SC_MANY_WRITERS > b_local[IO_PORT_NUM][3][4];
    //Ready signals
    sc_signal<bool> awready[IO_PORT_NUM][DIRECTION_NUM][3][4+1] , awready_local[IO_PORT_NUM][3][4];
    sc_signal<bool> wready[IO_PORT_NUM][DIRECTION_NUM][3][4+1] , wready_local[IO_PORT_NUM][3][4];
    sc_signal<bool> bready[IO_PORT_NUM][DIRECTION_NUM][3][4+1] , bready_local[IO_PORT_NUM][3][4];
    //Valid signals
    sc_signal<bool> awvalid[IO_PORT_NUM][DIRECTION_NUM][3][4+1] , awvalid_local[IO_PORT_NUM][3][4];
    sc_signal<bool> wvalid[IO_PORT_NUM][DIRECTION_NUM][3][4+1] , wvalid_local[IO_PORT_NUM][3][4];
    sc_signal<bool> bvalid[IO_PORT_NUM][DIRECTION_NUM][3][4+1] , bvalid_local[IO_PORT_NUM][3][4];

    sc_clock clock("My_CLOCK",10,5,0,1);

    Router a00("00");
    a00.clk(clock);
    //input
    a00.I[north].write_address_channel(aw[I][u_d][0][0]);
    a00.I[south].write_address_channel(aw[I][u_d][0][1]);
    a00.I[east].write_address_channel(aw[I][l_r][0][0]);
    a00.I[west].write_address_channel(aw[I][l_r][0][1]);
    a00.I[local].write_address_channel(aw_local[I][0][0]);

    a00.I[north].write_data_channel(w[I][u_d][0][0]);
    a00.I[south].write_data_channel(w[I][u_d][0][1]);
    a00.I[east].write_data_channel(w[I][l_r][0][0]);
    a00.I[west].write_data_channel(w[I][l_r][0][1]);
    a00.I[local].write_data_channel(w_local[I][0][0]);

    a00.I[north].write_response_channel(b[I][u_d][0][0]);
    a00.I[south].write_response_channel(b[I][u_d][0][1]);
    a00.I[east].write_response_channel(b[I][l_r][0][0]);
    a00.I[west].write_response_channel(b[I][l_r][0][1]);
    a00.I[local].write_response_channel(b_local[I][0][0]);

    a00.I[north].AWVALID(awvalid[I][u_d][0][0]);
    a00.I[south].AWVALID(awvalid[I][u_d][0][1]);
    a00.I[east].AWVALID(awvalid[I][l_r][0][0]);
    a00.I[west].AWVALID(awvalid[I][l_r][0][1]);
    a00.I[local].AWVALID(awvalid_local[I][0][0]);

    a00.I[north].WVALID(wvalid[I][u_d][0][0]);
    a00.I[south].WVALID(wvalid[I][u_d][0][1]);
    a00.I[east].WVALID(wvalid[I][l_r][0][0]);
    a00.I[west].WVALID(wvalid[I][l_r][0][1]);
    a00.I[local].WVALID(wvalid_local[I][0][0]);

    a00.I[north].BVALID(bvalid[I][u_d][0][0]);
    a00.I[south].BVALID(bvalid[I][u_d][0][1]);
    a00.I[east].BVALID(bvalid[I][l_r][0][0]);
    a00.I[west].BVALID(bvalid[I][l_r][0][1]);
    a00.I[local].BVALID(bvalid_local[I][0][0]);

    a00.I[north].AWREADY(awready[I][u_d][0][0]);
    a00.I[south].AWREADY(awready[I][u_d][0][1]);
    a00.I[east].AWREADY(awready[I][l_r][0][0]);
    a00.I[west].AWREADY(awready[I][l_r][0][1]);
    a00.I[local].AWREADY(awready_local[I][0][0]);

    a00.I[north].WREADY(wready[I][u_d][0][0]);
    a00.I[south].WREADY(wready[I][u_d][0][1]);
    a00.I[east].WREADY(wready[I][l_r][0][0]);
    a00.I[west].WREADY(wready[I][l_r][0][1]);
    a00.I[local].WREADY(wready_local[I][0][0]);

    a00.I[north].BREADY(bready[I][u_d][0][0]);
    a00.I[south].BREADY(bready[I][u_d][0][1]);
    a00.I[east].BREADY(bready[I][l_r][0][0]);
    a00.I[west].BREADY(bready[I][l_r][0][1]);
    a00.I[local].BREADY(bready_local[I][0][0]);

    //output
    
    a00.O[north].write_address_channel(aw[O][u_d][0][0]);
    a00.O[south].write_address_channel(aw[O][u_d][0][1]);
    a00.O[east].write_address_channel(aw[O][l_r][0][0]);
    a00.O[west].write_address_channel(aw[O][l_r][0][1]);
    a00.O[local].write_address_channel(aw_local[O][0][0]);

    a00.O[north].write_data_channel(w[O][u_d][0][0]);
    a00.O[south].write_data_channel(w[O][u_d][0][1]);
    a00.O[east].write_data_channel(w[O][l_r][0][0]);
    a00.O[west].write_data_channel(w[O][l_r][0][1]);
    a00.O[local].write_data_channel(w_local[O][0][0]);
    

    a00.O[north].write_response_channel(b[O][u_d][0][0]);
    a00.O[south].write_response_channel(b[O][u_d][0][1]);
    a00.O[east].write_response_channel(b[O][l_r][0][0]);
    a00.O[west].write_response_channel(b[O][l_r][0][1]);
    a00.O[local].write_response_channel(b_local[O][0][0]);

    a00.O[north].AWVALID(awvalid[O][u_d][0][0]);
    a00.O[south].AWVALID(awvalid[O][u_d][0][1]);
    a00.O[east].AWVALID(awvalid[O][l_r][0][0]);
    a00.O[west].AWVALID(awvalid[O][l_r][0][1]);
    a00.O[local].AWVALID(awvalid_local[O][0][0]);

    a00.O[north].WVALID(wvalid[O][u_d][0][0]);
    a00.O[south].WVALID(wvalid[O][u_d][0][1]);
    a00.O[east].WVALID(wvalid[O][l_r][0][0]);
    a00.O[west].WVALID(wvalid[O][l_r][0][1]);
    a00.O[local].WVALID(wvalid_local[O][0][0]);

    a00.O[north].BVALID(bvalid[O][u_d][0][0]);
    a00.O[south].BVALID(bvalid[O][u_d][0][1]);
    a00.O[east].BVALID(bvalid[O][l_r][0][0]);
    a00.O[west].BVALID(bvalid[O][l_r][0][1]);
    a00.O[local].BVALID(bvalid_local[O][0][0]);

    a00.O[north].AWREADY(awready[O][u_d][0][0]);
    a00.O[south].AWREADY(awready[O][u_d][0][1]);
    a00.O[east].AWREADY(awready[O][l_r][0][0]);
    a00.O[west].AWREADY(awready[O][l_r][0][1]);
    a00.O[local].AWREADY(awready_local[O][0][0]);

    a00.O[north].WREADY(wready[O][u_d][0][0]);
    a00.O[south].WREADY(wready[O][u_d][0][1]);
    a00.O[east].WREADY(wready[O][l_r][0][0]);
    a00.O[west].WREADY(wready[O][l_r][0][1]);
    a00.O[local].WREADY(wready_local[O][0][0]);

    a00.O[north].BREADY(bready[O][u_d][0][0]);
    a00.O[south].BREADY(bready[O][u_d][0][1]);
    a00.O[east].BREADY(bready[O][l_r][0][0]);
    a00.O[west].BREADY(bready[O][l_r][0][1]);
    a00.O[local].BREADY(bready_local[O][0][0]);


    Router a01("01");
    a01.clk(clock);
    //input
    a01.I[north].write_address_channel(aw[I][u_d][0][1]);
    a01.I[south].write_address_channel(aw[I][u_d][0][2]);
    a01.I[east].write_address_channel(aw[I][l_r][0][1]);
    a01.I[west].write_address_channel(aw[I][l_r][0][2]);
    a01.I[local].write_address_channel(aw_local[I][0][1]);

    a01.I[north].write_data_channel(w[I][u_d][0][1]);
    a01.I[south].write_data_channel(w[I][u_d][0][2]);
    a01.I[east].write_data_channel(w[I][l_r][0][1]);
    a01.I[west].write_data_channel(w[I][l_r][0][2]);
    a01.I[local].write_data_channel(w_local[I][0][1]);

    a01.I[north].write_response_channel(b[I][u_d][0][1]);
    a01.I[south].write_response_channel(b[I][u_d][0][2]);
    a01.I[east].write_response_channel(b[I][l_r][0][1]);
    a01.I[west].write_response_channel(b[I][l_r][0][2]);
    a01.I[local].write_response_channel(b_local[I][0][1]);

    a01.I[north].AWVALID(awvalid[I][u_d][0][1]);
    a01.I[south].AWVALID(awvalid[I][u_d][0][2]);
    a01.I[east].AWVALID(awvalid[I][l_r][0][1]);
    a01.I[west].AWVALID(awvalid[I][l_r][0][2]);
    a01.I[local].AWVALID(awvalid_local[I][0][1]);

    a01.I[north].WVALID(wvalid[I][u_d][0][1]);
    a01.I[south].WVALID(wvalid[I][u_d][0][2]);
    a01.I[east].WVALID(wvalid[I][l_r][0][1]);
    a01.I[west].WVALID(wvalid[I][l_r][0][2]);
    a01.I[local].WVALID(wvalid_local[I][0][1]);

    a01.I[north].BVALID(bvalid[I][u_d][0][1]);
    a01.I[south].BVALID(bvalid[I][u_d][0][2]);
    a01.I[east].BVALID(bvalid[I][l_r][0][1]);
    a01.I[west].BVALID(bvalid[I][l_r][0][2]);
    a01.I[local].BVALID(bvalid_local[I][0][1]);

    a01.I[north].AWREADY(awready[I][u_d][0][1]);
    a01.I[south].AWREADY(awready[I][u_d][0][2]);
    a01.I[east].AWREADY(awready[I][l_r][0][1]);
    a01.I[west].AWREADY(awready[I][l_r][0][2]);
    a01.I[local].AWREADY(awready_local[I][0][1]);

    a01.I[north].WREADY(wready[I][u_d][0][1]);
    a01.I[south].WREADY(wready[I][u_d][0][2]);
    a01.I[east].WREADY(wready[I][l_r][0][1]);
    a01.I[west].WREADY(wready[I][l_r][0][2]);
    a01.I[local].WREADY(wready_local[I][0][1]);

    a01.I[north].BREADY(bready[I][u_d][0][1]);
    a01.I[south].BREADY(bready[I][u_d][0][2]);
    a01.I[east].BREADY(bready[I][l_r][0][1]);
    a01.I[west].BREADY(bready[I][l_r][0][2]);
    a01.I[local].BREADY(bready_local[I][0][1]);

    //output
    
    a01.O[north].write_address_channel(aw[O][u_d][0][1]);
    a01.O[south].write_address_channel(aw[O][u_d][0][2]);
    a01.O[east].write_address_channel(aw[O][l_r][0][1]);
    a01.O[west].write_address_channel(aw[O][l_r][0][2]);
    a01.O[local].write_address_channel(aw_local[O][0][1]);

    a01.O[north].write_data_channel(w[O][u_d][0][1]);
    a01.O[south].write_data_channel(w[O][u_d][0][2]);
    a01.O[east].write_data_channel(w[O][l_r][0][1]);
    a01.O[west].write_data_channel(w[O][l_r][0][2]);
    a01.O[local].write_data_channel(w_local[O][0][1]);
    

    a01.O[north].write_response_channel(b[O][u_d][0][1]);
    a01.O[south].write_response_channel(b[O][u_d][0][2]);
    a01.O[east].write_response_channel(b[O][l_r][0][1]);
    a01.O[west].write_response_channel(b[O][l_r][0][2]);
    a01.O[local].write_response_channel(b_local[O][0][1]);

    a01.O[north].AWVALID(awvalid[O][u_d][0][1]);
    a01.O[south].AWVALID(awvalid[O][u_d][0][2]);
    a01.O[east].AWVALID(awvalid[O][l_r][0][1]);
    a01.O[west].AWVALID(awvalid[O][l_r][0][2]);
    a01.O[local].AWVALID(awvalid_local[O][0][1]);

    a01.O[north].WVALID(wvalid[O][u_d][0][1]);
    a01.O[south].WVALID(wvalid[O][u_d][0][2]);
    a01.O[east].WVALID(wvalid[O][l_r][0][1]);
    a01.O[west].WVALID(wvalid[O][l_r][0][2]);
    a01.O[local].WVALID(wvalid_local[O][0][1]);

    a01.O[north].BVALID(bvalid[O][u_d][0][1]);
    a01.O[south].BVALID(bvalid[O][u_d][0][2]);
    a01.O[east].BVALID(bvalid[O][l_r][0][1]);
    a01.O[west].BVALID(bvalid[O][l_r][0][2]);
    a01.O[local].BVALID(bvalid_local[O][0][1]);

    a01.O[north].AWREADY(awready[O][u_d][0][1]);
    a01.O[south].AWREADY(awready[O][u_d][0][2]);
    a01.O[east].AWREADY(awready[O][l_r][0][1]);
    a01.O[west].AWREADY(awready[O][l_r][0][2]);
    a01.O[local].AWREADY(awready_local[O][0][1]);

    a01.O[north].WREADY(wready[O][u_d][0][1]);
    a01.O[south].WREADY(wready[O][u_d][0][2]);
    a01.O[east].WREADY(wready[O][l_r][0][1]);
    a01.O[west].WREADY(wready[O][l_r][0][2]);
    a01.O[local].WREADY(wready_local[O][0][1]);

    a01.O[north].BREADY(bready[O][u_d][0][1]);
    a01.O[south].BREADY(bready[O][u_d][0][2]);
    a01.O[east].BREADY(bready[O][l_r][0][1]);
    a01.O[west].BREADY(bready[O][l_r][0][2]);
    a01.O[local].BREADY(bready_local[O][0][1]);


    Router a02("02");
    a02.clk(clock);
    //input
    a02.I[north].write_address_channel(aw[I][u_d][0][2]);
    a02.I[south].write_address_channel(aw[I][u_d][0][3]);
    a02.I[east].write_address_channel(aw[I][l_r][0][2]);
    a02.I[west].write_address_channel(aw[I][l_r][0][3]);
    a02.I[local].write_address_channel(aw_local[I][0][2]);

    a02.I[north].write_data_channel(w[I][u_d][0][2]);
    a02.I[south].write_data_channel(w[I][u_d][0][3]);
    a02.I[east].write_data_channel(w[I][l_r][0][2]);
    a02.I[west].write_data_channel(w[I][l_r][0][3]);
    a02.I[local].write_data_channel(w_local[I][0][2]);

    a02.I[north].write_response_channel(b[I][u_d][0][2]);
    a02.I[south].write_response_channel(b[I][u_d][0][3]);
    a02.I[east].write_response_channel(b[I][l_r][0][2]);
    a02.I[west].write_response_channel(b[I][l_r][0][3]);
    a02.I[local].write_response_channel(b_local[I][0][2]);

    a02.I[north].AWVALID(awvalid[I][u_d][0][2]);
    a02.I[south].AWVALID(awvalid[I][u_d][0][3]);
    a02.I[east].AWVALID(awvalid[I][l_r][0][2]);
    a02.I[west].AWVALID(awvalid[I][l_r][0][3]);
    a02.I[local].AWVALID(awvalid_local[I][0][2]);

    a02.I[north].WVALID(wvalid[I][u_d][0][2]);
    a02.I[south].WVALID(wvalid[I][u_d][0][3]);
    a02.I[east].WVALID(wvalid[I][l_r][0][2]);
    a02.I[west].WVALID(wvalid[I][l_r][0][3]);
    a02.I[local].WVALID(wvalid_local[I][0][2]);

    a02.I[north].BVALID(bvalid[I][u_d][0][2]);
    a02.I[south].BVALID(bvalid[I][u_d][0][3]);
    a02.I[east].BVALID(bvalid[I][l_r][0][2]);
    a02.I[west].BVALID(bvalid[I][l_r][0][3]);
    a02.I[local].BVALID(bvalid_local[I][0][2]);

    a02.I[north].AWREADY(awready[I][u_d][0][2]);
    a02.I[south].AWREADY(awready[I][u_d][0][3]);
    a02.I[east].AWREADY(awready[I][l_r][0][2]);
    a02.I[west].AWREADY(awready[I][l_r][0][3]);
    a02.I[local].AWREADY(awready_local[I][0][2]);

    a02.I[north].WREADY(wready[I][u_d][0][2]);
    a02.I[south].WREADY(wready[I][u_d][0][3]);
    a02.I[east].WREADY(wready[I][l_r][0][2]);
    a02.I[west].WREADY(wready[I][l_r][0][3]);
    a02.I[local].WREADY(wready_local[I][0][2]);

    a02.I[north].BREADY(bready[I][u_d][0][2]);
    a02.I[south].BREADY(bready[I][u_d][0][3]);
    a02.I[east].BREADY(bready[I][l_r][0][2]);
    a02.I[west].BREADY(bready[I][l_r][0][3]);
    a02.I[local].BREADY(bready_local[I][0][2]);

    //output
    
    a02.O[north].write_address_channel(aw[O][u_d][0][2]);
    a02.O[south].write_address_channel(aw[O][u_d][0][3]);
    a02.O[east].write_address_channel(aw[O][l_r][0][2]);
    a02.O[west].write_address_channel(aw[O][l_r][0][3]);
    a02.O[local].write_address_channel(aw_local[O][0][2]);

    a02.O[north].write_data_channel(w[O][u_d][0][2]);
    a02.O[south].write_data_channel(w[O][u_d][0][3]);
    a02.O[east].write_data_channel(w[O][l_r][0][2]);
    a02.O[west].write_data_channel(w[O][l_r][0][3]);
    a02.O[local].write_data_channel(w_local[O][0][2]);
    

    a02.O[north].write_response_channel(b[O][u_d][0][2]);
    a02.O[south].write_response_channel(b[O][u_d][0][3]);
    a02.O[east].write_response_channel(b[O][l_r][0][2]);
    a02.O[west].write_response_channel(b[O][l_r][0][3]);
    a02.O[local].write_response_channel(b_local[O][0][2]);

    a02.O[north].AWVALID(awvalid[O][u_d][0][2]);
    a02.O[south].AWVALID(awvalid[O][u_d][0][3]);
    a02.O[east].AWVALID(awvalid[O][l_r][0][2]);
    a02.O[west].AWVALID(awvalid[O][l_r][0][3]);
    a02.O[local].AWVALID(awvalid_local[O][0][2]);

    a02.O[north].WVALID(wvalid[O][u_d][0][2]);
    a02.O[south].WVALID(wvalid[O][u_d][0][3]);
    a02.O[east].WVALID(wvalid[O][l_r][0][2]);
    a02.O[west].WVALID(wvalid[O][l_r][0][3]);
    a02.O[local].WVALID(wvalid_local[O][0][2]);

    a02.O[north].BVALID(bvalid[O][u_d][0][2]);
    a02.O[south].BVALID(bvalid[O][u_d][0][3]);
    a02.O[east].BVALID(bvalid[O][l_r][0][2]);
    a02.O[west].BVALID(bvalid[O][l_r][0][3]);
    a02.O[local].BVALID(bvalid_local[O][0][2]);

    a02.O[north].AWREADY(awready[O][u_d][0][2]);
    a02.O[south].AWREADY(awready[O][u_d][0][3]);
    a02.O[east].AWREADY(awready[O][l_r][0][2]);
    a02.O[west].AWREADY(awready[O][l_r][0][3]);
    a02.O[local].AWREADY(awready_local[O][0][2]);

    a02.O[north].WREADY(wready[O][u_d][0][2]);
    a02.O[south].WREADY(wready[O][u_d][0][3]);
    a02.O[east].WREADY(wready[O][l_r][0][2]);
    a02.O[west].WREADY(wready[O][l_r][0][3]);
    a02.O[local].WREADY(wready_local[O][0][2]);

    a02.O[north].BREADY(bready[O][u_d][0][2]);
    a02.O[south].BREADY(bready[O][u_d][0][3]);
    a02.O[east].BREADY(bready[O][l_r][0][2]);
    a02.O[west].BREADY(bready[O][l_r][0][3]);
    a02.O[local].BREADY(bready_local[O][0][2]);


    Router a03("03");
    a03.clk(clock);
    //input
    a03.I[north].write_address_channel(aw[I][u_d][0][3]);
    a03.I[south].write_address_channel(aw[I][u_d][0][4]);
    a03.I[east].write_address_channel(aw[I][l_r][0][3]);
    a03.I[west].write_address_channel(aw[I][l_r][0][4]);
    a03.I[local].write_address_channel(aw_local[I][0][3]);

    a03.I[north].write_data_channel(w[I][u_d][0][3]);
    a03.I[south].write_data_channel(w[I][u_d][0][4]);
    a03.I[east].write_data_channel(w[I][l_r][0][3]);
    a03.I[west].write_data_channel(w[I][l_r][0][4]);
    a03.I[local].write_data_channel(w_local[I][0][3]);

    a03.I[north].write_response_channel(b[I][u_d][0][3]);
    a03.I[south].write_response_channel(b[I][u_d][0][4]);
    a03.I[east].write_response_channel(b[I][l_r][0][3]);
    a03.I[west].write_response_channel(b[I][l_r][0][4]);
    a03.I[local].write_response_channel(b_local[I][0][3]);

    a03.I[north].AWVALID(awvalid[I][u_d][0][3]);
    a03.I[south].AWVALID(awvalid[I][u_d][0][4]);
    a03.I[east].AWVALID(awvalid[I][l_r][0][3]);
    a03.I[west].AWVALID(awvalid[I][l_r][0][4]);
    a03.I[local].AWVALID(awvalid_local[I][0][3]);

    a03.I[north].WVALID(wvalid[I][u_d][0][3]);
    a03.I[south].WVALID(wvalid[I][u_d][0][4]);
    a03.I[east].WVALID(wvalid[I][l_r][0][3]);
    a03.I[west].WVALID(wvalid[I][l_r][0][4]);
    a03.I[local].WVALID(wvalid_local[I][0][3]);

    a03.I[north].BVALID(bvalid[I][u_d][0][3]);
    a03.I[south].BVALID(bvalid[I][u_d][0][4]);
    a03.I[east].BVALID(bvalid[I][l_r][0][3]);
    a03.I[west].BVALID(bvalid[I][l_r][0][4]);
    a03.I[local].BVALID(bvalid_local[I][0][3]);

    a03.I[north].AWREADY(awready[I][u_d][0][3]);
    a03.I[south].AWREADY(awready[I][u_d][0][4]);
    a03.I[east].AWREADY(awready[I][l_r][0][3]);
    a03.I[west].AWREADY(awready[I][l_r][0][4]);
    a03.I[local].AWREADY(awready_local[I][0][3]);

    a03.I[north].WREADY(wready[I][u_d][0][3]);
    a03.I[south].WREADY(wready[I][u_d][0][4]);
    a03.I[east].WREADY(wready[I][l_r][0][3]);
    a03.I[west].WREADY(wready[I][l_r][0][4]);
    a03.I[local].WREADY(wready_local[I][0][3]);

    a03.I[north].BREADY(bready[I][u_d][0][3]);
    a03.I[south].BREADY(bready[I][u_d][0][4]);
    a03.I[east].BREADY(bready[I][l_r][0][3]);
    a03.I[west].BREADY(bready[I][l_r][0][4]);
    a03.I[local].BREADY(bready_local[I][0][3]);

    //output
    
    a03.O[north].write_address_channel(aw[O][u_d][0][3]);
    a03.O[south].write_address_channel(aw[O][u_d][0][4]);
    a03.O[east].write_address_channel(aw[O][l_r][0][3]);
    a03.O[west].write_address_channel(aw[O][l_r][0][4]);
    a03.O[local].write_address_channel(aw_local[O][0][3]);

    a03.O[north].write_data_channel(w[O][u_d][0][3]);
    a03.O[south].write_data_channel(w[O][u_d][0][4]);
    a03.O[east].write_data_channel(w[O][l_r][0][3]);
    a03.O[west].write_data_channel(w[O][l_r][0][4]);
    a03.O[local].write_data_channel(w_local[O][0][3]);
    

    a03.O[north].write_response_channel(b[O][u_d][0][3]);
    a03.O[south].write_response_channel(b[O][u_d][0][4]);
    a03.O[east].write_response_channel(b[O][l_r][0][3]);
    a03.O[west].write_response_channel(b[O][l_r][0][4]);
    a03.O[local].write_response_channel(b_local[O][0][3]);

    a03.O[north].AWVALID(awvalid[O][u_d][0][3]);
    a03.O[south].AWVALID(awvalid[O][u_d][0][4]);
    a03.O[east].AWVALID(awvalid[O][l_r][0][3]);
    a03.O[west].AWVALID(awvalid[O][l_r][0][4]);
    a03.O[local].AWVALID(awvalid_local[O][0][3]);

    a03.O[north].WVALID(wvalid[O][u_d][0][3]);
    a03.O[south].WVALID(wvalid[O][u_d][0][4]);
    a03.O[east].WVALID(wvalid[O][l_r][0][3]);
    a03.O[west].WVALID(wvalid[O][l_r][0][4]);
    a03.O[local].WVALID(wvalid_local[O][0][3]);

    a03.O[north].BVALID(bvalid[O][u_d][0][3]);
    a03.O[south].BVALID(bvalid[O][u_d][0][4]);
    a03.O[east].BVALID(bvalid[O][l_r][0][3]);
    a03.O[west].BVALID(bvalid[O][l_r][0][4]);
    a03.O[local].BVALID(bvalid_local[O][0][3]);

    a03.O[north].AWREADY(awready[O][u_d][0][3]);
    a03.O[south].AWREADY(awready[O][u_d][0][4]);
    a03.O[east].AWREADY(awready[O][l_r][0][3]);
    a03.O[west].AWREADY(awready[O][l_r][0][4]);
    a03.O[local].AWREADY(awready_local[O][0][3]);

    a03.O[north].WREADY(wready[O][u_d][0][3]);
    a03.O[south].WREADY(wready[O][u_d][0][4]);
    a03.O[east].WREADY(wready[O][l_r][0][3]);
    a03.O[west].WREADY(wready[O][l_r][0][4]);
    a03.O[local].WREADY(wready_local[O][0][3]);

    a03.O[north].BREADY(bready[O][u_d][0][3]);
    a03.O[south].BREADY(bready[O][u_d][0][4]);
    a03.O[east].BREADY(bready[O][l_r][0][3]);
    a03.O[west].BREADY(bready[O][l_r][0][4]);
    a03.O[local].BREADY(bready_local[O][0][3]);


    Router a10("10");
    a10.clk(clock);
    //input
    a10.I[north].write_address_channel(aw[I][u_d][1][0]);
    a10.I[south].write_address_channel(aw[I][u_d][1][1]);
    a10.I[east].write_address_channel(aw[I][l_r][1][0]);
    a10.I[west].write_address_channel(aw[I][l_r][1][1]);
    a10.I[local].write_address_channel(aw_local[I][1][0]);

    a10.I[north].write_data_channel(w[I][u_d][1][0]);
    a10.I[south].write_data_channel(w[I][u_d][1][1]);
    a10.I[east].write_data_channel(w[I][l_r][1][0]);
    a10.I[west].write_data_channel(w[I][l_r][1][1]);
    a10.I[local].write_data_channel(w_local[I][1][0]);

    a10.I[north].write_response_channel(b[I][u_d][1][0]);
    a10.I[south].write_response_channel(b[I][u_d][1][1]);
    a10.I[east].write_response_channel(b[I][l_r][1][0]);
    a10.I[west].write_response_channel(b[I][l_r][1][1]);
    a10.I[local].write_response_channel(b_local[I][1][0]);

    a10.I[north].AWVALID(awvalid[I][u_d][1][0]);
    a10.I[south].AWVALID(awvalid[I][u_d][1][1]);
    a10.I[east].AWVALID(awvalid[I][l_r][1][0]);
    a10.I[west].AWVALID(awvalid[I][l_r][1][1]);
    a10.I[local].AWVALID(awvalid_local[I][1][0]);

    a10.I[north].WVALID(wvalid[I][u_d][1][0]);
    a10.I[south].WVALID(wvalid[I][u_d][1][1]);
    a10.I[east].WVALID(wvalid[I][l_r][1][0]);
    a10.I[west].WVALID(wvalid[I][l_r][1][1]);
    a10.I[local].WVALID(wvalid_local[I][1][0]);

    a10.I[north].BVALID(bvalid[I][u_d][1][0]);
    a10.I[south].BVALID(bvalid[I][u_d][1][1]);
    a10.I[east].BVALID(bvalid[I][l_r][1][0]);
    a10.I[west].BVALID(bvalid[I][l_r][1][1]);
    a10.I[local].BVALID(bvalid_local[I][1][0]);

    a10.I[north].AWREADY(awready[I][u_d][1][0]);
    a10.I[south].AWREADY(awready[I][u_d][1][1]);
    a10.I[east].AWREADY(awready[I][l_r][1][0]);
    a10.I[west].AWREADY(awready[I][l_r][1][1]);
    a10.I[local].AWREADY(awready_local[I][1][0]);

    a10.I[north].WREADY(wready[I][u_d][1][0]);
    a10.I[south].WREADY(wready[I][u_d][1][1]);
    a10.I[east].WREADY(wready[I][l_r][1][0]);
    a10.I[west].WREADY(wready[I][l_r][1][1]);
    a10.I[local].WREADY(wready_local[I][1][0]);

    a10.I[north].BREADY(bready[I][u_d][1][0]);
    a10.I[south].BREADY(bready[I][u_d][1][1]);
    a10.I[east].BREADY(bready[I][l_r][1][0]);
    a10.I[west].BREADY(bready[I][l_r][1][1]);
    a10.I[local].BREADY(bready_local[I][1][0]);

    //output
    
    a10.O[north].write_address_channel(aw[O][u_d][1][0]);
    a10.O[south].write_address_channel(aw[O][u_d][1][1]);
    a10.O[east].write_address_channel(aw[O][l_r][1][0]);
    a10.O[west].write_address_channel(aw[O][l_r][1][1]);
    a10.O[local].write_address_channel(aw_local[O][1][0]);

    a10.O[north].write_data_channel(w[O][u_d][1][0]);
    a10.O[south].write_data_channel(w[O][u_d][1][1]);
    a10.O[east].write_data_channel(w[O][l_r][1][0]);
    a10.O[west].write_data_channel(w[O][l_r][1][1]);
    a10.O[local].write_data_channel(w_local[O][1][0]);
    

    a10.O[north].write_response_channel(b[O][u_d][1][0]);
    a10.O[south].write_response_channel(b[O][u_d][1][1]);
    a10.O[east].write_response_channel(b[O][l_r][1][0]);
    a10.O[west].write_response_channel(b[O][l_r][1][1]);
    a10.O[local].write_response_channel(b_local[O][1][0]);

    a10.O[north].AWVALID(awvalid[O][u_d][1][0]);
    a10.O[south].AWVALID(awvalid[O][u_d][1][1]);
    a10.O[east].AWVALID(awvalid[O][l_r][1][0]);
    a10.O[west].AWVALID(awvalid[O][l_r][1][1]);
    a10.O[local].AWVALID(awvalid_local[O][1][0]);

    a10.O[north].WVALID(wvalid[O][u_d][1][0]);
    a10.O[south].WVALID(wvalid[O][u_d][1][1]);
    a10.O[east].WVALID(wvalid[O][l_r][1][0]);
    a10.O[west].WVALID(wvalid[O][l_r][1][1]);
    a10.O[local].WVALID(wvalid_local[O][1][0]);

    a10.O[north].BVALID(bvalid[O][u_d][1][0]);
    a10.O[south].BVALID(bvalid[O][u_d][1][1]);
    a10.O[east].BVALID(bvalid[O][l_r][1][0]);
    a10.O[west].BVALID(bvalid[O][l_r][1][1]);
    a10.O[local].BVALID(bvalid_local[O][1][0]);

    a10.O[north].AWREADY(awready[O][u_d][1][0]);
    a10.O[south].AWREADY(awready[O][u_d][1][1]);
    a10.O[east].AWREADY(awready[O][l_r][1][0]);
    a10.O[west].AWREADY(awready[O][l_r][1][1]);
    a10.O[local].AWREADY(awready_local[O][1][0]);

    a10.O[north].WREADY(wready[O][u_d][1][0]);
    a10.O[south].WREADY(wready[O][u_d][1][1]);
    a10.O[east].WREADY(wready[O][l_r][1][0]);
    a10.O[west].WREADY(wready[O][l_r][1][1]);
    a10.O[local].WREADY(wready_local[O][1][0]);

    a10.O[north].BREADY(bready[O][u_d][1][0]);
    a10.O[south].BREADY(bready[O][u_d][1][1]);
    a10.O[east].BREADY(bready[O][l_r][1][0]);
    a10.O[west].BREADY(bready[O][l_r][1][1]);
    a10.O[local].BREADY(bready_local[O][1][0]);


    Router a11("11");
    a11.clk(clock);
    //input
    a11.I[north].write_address_channel(aw[I][u_d][1][1]);
    a11.I[south].write_address_channel(aw[I][u_d][1][2]);
    a11.I[east].write_address_channel(aw[I][l_r][1][1]);
    a11.I[west].write_address_channel(aw[I][l_r][1][2]);
    a11.I[local].write_address_channel(aw_local[I][1][1]);

    a11.I[north].write_data_channel(w[I][u_d][1][1]);
    a11.I[south].write_data_channel(w[I][u_d][1][2]);
    a11.I[east].write_data_channel(w[I][l_r][1][1]);
    a11.I[west].write_data_channel(w[I][l_r][1][2]);
    a11.I[local].write_data_channel(w_local[I][1][1]);

    a11.I[north].write_response_channel(b[I][u_d][1][1]);
    a11.I[south].write_response_channel(b[I][u_d][1][2]);
    a11.I[east].write_response_channel(b[I][l_r][1][1]);
    a11.I[west].write_response_channel(b[I][l_r][1][2]);
    a11.I[local].write_response_channel(b_local[I][1][1]);

    a11.I[north].AWVALID(awvalid[I][u_d][1][1]);
    a11.I[south].AWVALID(awvalid[I][u_d][1][2]);
    a11.I[east].AWVALID(awvalid[I][l_r][1][1]);
    a11.I[west].AWVALID(awvalid[I][l_r][1][2]);
    a11.I[local].AWVALID(awvalid_local[I][1][1]);

    a11.I[north].WVALID(wvalid[I][u_d][1][1]);
    a11.I[south].WVALID(wvalid[I][u_d][1][2]);
    a11.I[east].WVALID(wvalid[I][l_r][1][1]);
    a11.I[west].WVALID(wvalid[I][l_r][1][2]);
    a11.I[local].WVALID(wvalid_local[I][1][1]);

    a11.I[north].BVALID(bvalid[I][u_d][1][1]);
    a11.I[south].BVALID(bvalid[I][u_d][1][2]);
    a11.I[east].BVALID(bvalid[I][l_r][1][1]);
    a11.I[west].BVALID(bvalid[I][l_r][1][2]);
    a11.I[local].BVALID(bvalid_local[I][1][1]);

    a11.I[north].AWREADY(awready[I][u_d][1][1]);
    a11.I[south].AWREADY(awready[I][u_d][1][2]);
    a11.I[east].AWREADY(awready[I][l_r][1][1]);
    a11.I[west].AWREADY(awready[I][l_r][1][2]);
    a11.I[local].AWREADY(awready_local[I][1][1]);

    a11.I[north].WREADY(wready[I][u_d][1][1]);
    a11.I[south].WREADY(wready[I][u_d][1][2]);
    a11.I[east].WREADY(wready[I][l_r][1][1]);
    a11.I[west].WREADY(wready[I][l_r][1][2]);
    a11.I[local].WREADY(wready_local[I][1][1]);

    a11.I[north].BREADY(bready[I][u_d][1][1]);
    a11.I[south].BREADY(bready[I][u_d][1][2]);
    a11.I[east].BREADY(bready[I][l_r][1][1]);
    a11.I[west].BREADY(bready[I][l_r][1][2]);
    a11.I[local].BREADY(bready_local[I][1][1]);

    //output
    
    a11.O[north].write_address_channel(aw[O][u_d][1][1]);
    a11.O[south].write_address_channel(aw[O][u_d][1][2]);
    a11.O[east].write_address_channel(aw[O][l_r][1][1]);
    a11.O[west].write_address_channel(aw[O][l_r][1][2]);
    a11.O[local].write_address_channel(aw_local[O][1][1]);

    a11.O[north].write_data_channel(w[O][u_d][1][1]);
    a11.O[south].write_data_channel(w[O][u_d][1][2]);
    a11.O[east].write_data_channel(w[O][l_r][1][1]);
    a11.O[west].write_data_channel(w[O][l_r][1][2]);
    a11.O[local].write_data_channel(w_local[O][1][1]);
    

    a11.O[north].write_response_channel(b[O][u_d][1][1]);
    a11.O[south].write_response_channel(b[O][u_d][1][2]);
    a11.O[east].write_response_channel(b[O][l_r][1][1]);
    a11.O[west].write_response_channel(b[O][l_r][1][2]);
    a11.O[local].write_response_channel(b_local[O][1][1]);

    a11.O[north].AWVALID(awvalid[O][u_d][1][1]);
    a11.O[south].AWVALID(awvalid[O][u_d][1][2]);
    a11.O[east].AWVALID(awvalid[O][l_r][1][1]);
    a11.O[west].AWVALID(awvalid[O][l_r][1][2]);
    a11.O[local].AWVALID(awvalid_local[O][1][1]);

    a11.O[north].WVALID(wvalid[O][u_d][1][1]);
    a11.O[south].WVALID(wvalid[O][u_d][1][2]);
    a11.O[east].WVALID(wvalid[O][l_r][1][1]);
    a11.O[west].WVALID(wvalid[O][l_r][1][2]);
    a11.O[local].WVALID(wvalid_local[O][1][1]);

    a11.O[north].BVALID(bvalid[O][u_d][1][1]);
    a11.O[south].BVALID(bvalid[O][u_d][1][2]);
    a11.O[east].BVALID(bvalid[O][l_r][1][1]);
    a11.O[west].BVALID(bvalid[O][l_r][1][2]);
    a11.O[local].BVALID(bvalid_local[O][1][1]);

    a11.O[north].AWREADY(awready[O][u_d][1][1]);
    a11.O[south].AWREADY(awready[O][u_d][1][2]);
    a11.O[east].AWREADY(awready[O][l_r][1][1]);
    a11.O[west].AWREADY(awready[O][l_r][1][2]);
    a11.O[local].AWREADY(awready_local[O][1][1]);

    a11.O[north].WREADY(wready[O][u_d][1][1]);
    a11.O[south].WREADY(wready[O][u_d][1][2]);
    a11.O[east].WREADY(wready[O][l_r][1][1]);
    a11.O[west].WREADY(wready[O][l_r][1][2]);
    a11.O[local].WREADY(wready_local[O][1][1]);

    a11.O[north].BREADY(bready[O][u_d][1][1]);
    a11.O[south].BREADY(bready[O][u_d][1][2]);
    a11.O[east].BREADY(bready[O][l_r][1][1]);
    a11.O[west].BREADY(bready[O][l_r][1][2]);
    a11.O[local].BREADY(bready_local[O][1][1]);


    Router a12("12");
    a12.clk(clock);
    //input
    a12.I[north].write_address_channel(aw[I][u_d][1][2]);
    a12.I[south].write_address_channel(aw[I][u_d][1][3]);
    a12.I[east].write_address_channel(aw[I][l_r][1][2]);
    a12.I[west].write_address_channel(aw[I][l_r][1][3]);
    a12.I[local].write_address_channel(aw_local[I][1][2]);

    a12.I[north].write_data_channel(w[I][u_d][1][2]);
    a12.I[south].write_data_channel(w[I][u_d][1][3]);
    a12.I[east].write_data_channel(w[I][l_r][1][2]);
    a12.I[west].write_data_channel(w[I][l_r][1][3]);
    a12.I[local].write_data_channel(w_local[I][1][2]);

    a12.I[north].write_response_channel(b[I][u_d][1][2]);
    a12.I[south].write_response_channel(b[I][u_d][1][3]);
    a12.I[east].write_response_channel(b[I][l_r][1][2]);
    a12.I[west].write_response_channel(b[I][l_r][1][3]);
    a12.I[local].write_response_channel(b_local[I][1][2]);

    a12.I[north].AWVALID(awvalid[I][u_d][1][2]);
    a12.I[south].AWVALID(awvalid[I][u_d][1][3]);
    a12.I[east].AWVALID(awvalid[I][l_r][1][2]);
    a12.I[west].AWVALID(awvalid[I][l_r][1][3]);
    a12.I[local].AWVALID(awvalid_local[I][1][2]);

    a12.I[north].WVALID(wvalid[I][u_d][1][2]);
    a12.I[south].WVALID(wvalid[I][u_d][1][3]);
    a12.I[east].WVALID(wvalid[I][l_r][1][2]);
    a12.I[west].WVALID(wvalid[I][l_r][1][3]);
    a12.I[local].WVALID(wvalid_local[I][1][2]);

    a12.I[north].BVALID(bvalid[I][u_d][1][2]);
    a12.I[south].BVALID(bvalid[I][u_d][1][3]);
    a12.I[east].BVALID(bvalid[I][l_r][1][2]);
    a12.I[west].BVALID(bvalid[I][l_r][1][3]);
    a12.I[local].BVALID(bvalid_local[I][1][2]);

    a12.I[north].AWREADY(awready[I][u_d][1][2]);
    a12.I[south].AWREADY(awready[I][u_d][1][3]);
    a12.I[east].AWREADY(awready[I][l_r][1][2]);
    a12.I[west].AWREADY(awready[I][l_r][1][3]);
    a12.I[local].AWREADY(awready_local[I][1][2]);

    a12.I[north].WREADY(wready[I][u_d][1][2]);
    a12.I[south].WREADY(wready[I][u_d][1][3]);
    a12.I[east].WREADY(wready[I][l_r][1][2]);
    a12.I[west].WREADY(wready[I][l_r][1][3]);
    a12.I[local].WREADY(wready_local[I][1][2]);

    a12.I[north].BREADY(bready[I][u_d][1][2]);
    a12.I[south].BREADY(bready[I][u_d][1][3]);
    a12.I[east].BREADY(bready[I][l_r][1][2]);
    a12.I[west].BREADY(bready[I][l_r][1][3]);
    a12.I[local].BREADY(bready_local[I][1][2]);

    //output
    
    a12.O[north].write_address_channel(aw[O][u_d][1][2]);
    a12.O[south].write_address_channel(aw[O][u_d][1][3]);
    a12.O[east].write_address_channel(aw[O][l_r][1][2]);
    a12.O[west].write_address_channel(aw[O][l_r][1][3]);
    a12.O[local].write_address_channel(aw_local[O][1][2]);

    a12.O[north].write_data_channel(w[O][u_d][1][2]);
    a12.O[south].write_data_channel(w[O][u_d][1][3]);
    a12.O[east].write_data_channel(w[O][l_r][1][2]);
    a12.O[west].write_data_channel(w[O][l_r][1][3]);
    a12.O[local].write_data_channel(w_local[O][1][2]);
    

    a12.O[north].write_response_channel(b[O][u_d][1][2]);
    a12.O[south].write_response_channel(b[O][u_d][1][3]);
    a12.O[east].write_response_channel(b[O][l_r][1][2]);
    a12.O[west].write_response_channel(b[O][l_r][1][3]);
    a12.O[local].write_response_channel(b_local[O][1][2]);

    a12.O[north].AWVALID(awvalid[O][u_d][1][2]);
    a12.O[south].AWVALID(awvalid[O][u_d][1][3]);
    a12.O[east].AWVALID(awvalid[O][l_r][1][2]);
    a12.O[west].AWVALID(awvalid[O][l_r][1][3]);
    a12.O[local].AWVALID(awvalid_local[O][1][2]);

    a12.O[north].WVALID(wvalid[O][u_d][1][2]);
    a12.O[south].WVALID(wvalid[O][u_d][1][3]);
    a12.O[east].WVALID(wvalid[O][l_r][1][2]);
    a12.O[west].WVALID(wvalid[O][l_r][1][3]);
    a12.O[local].WVALID(wvalid_local[O][1][2]);

    a12.O[north].BVALID(bvalid[O][u_d][1][2]);
    a12.O[south].BVALID(bvalid[O][u_d][1][3]);
    a12.O[east].BVALID(bvalid[O][l_r][1][2]);
    a12.O[west].BVALID(bvalid[O][l_r][1][3]);
    a12.O[local].BVALID(bvalid_local[O][1][2]);

    a12.O[north].AWREADY(awready[O][u_d][1][2]);
    a12.O[south].AWREADY(awready[O][u_d][1][3]);
    a12.O[east].AWREADY(awready[O][l_r][1][2]);
    a12.O[west].AWREADY(awready[O][l_r][1][3]);
    a12.O[local].AWREADY(awready_local[O][1][2]);

    a12.O[north].WREADY(wready[O][u_d][1][2]);
    a12.O[south].WREADY(wready[O][u_d][1][3]);
    a12.O[east].WREADY(wready[O][l_r][1][2]);
    a12.O[west].WREADY(wready[O][l_r][1][3]);
    a12.O[local].WREADY(wready_local[O][1][2]);

    a12.O[north].BREADY(bready[O][u_d][1][2]);
    a12.O[south].BREADY(bready[O][u_d][1][3]);
    a12.O[east].BREADY(bready[O][l_r][1][2]);
    a12.O[west].BREADY(bready[O][l_r][1][3]);
    a12.O[local].BREADY(bready_local[O][1][2]);


    Router a13("13");
    a13.clk(clock);
    //input
    a13.I[north].write_address_channel(aw[I][u_d][1][3]);
    a13.I[south].write_address_channel(aw[I][u_d][1][4]);
    a13.I[east].write_address_channel(aw[I][l_r][1][3]);
    a13.I[west].write_address_channel(aw[I][l_r][1][4]);
    a13.I[local].write_address_channel(aw_local[I][1][3]);

    a13.I[north].write_data_channel(w[I][u_d][1][3]);
    a13.I[south].write_data_channel(w[I][u_d][1][4]);
    a13.I[east].write_data_channel(w[I][l_r][1][3]);
    a13.I[west].write_data_channel(w[I][l_r][1][4]);
    a13.I[local].write_data_channel(w_local[I][1][3]);

    a13.I[north].write_response_channel(b[I][u_d][1][3]);
    a13.I[south].write_response_channel(b[I][u_d][1][4]);
    a13.I[east].write_response_channel(b[I][l_r][1][3]);
    a13.I[west].write_response_channel(b[I][l_r][1][4]);
    a13.I[local].write_response_channel(b_local[I][1][3]);

    a13.I[north].AWVALID(awvalid[I][u_d][1][3]);
    a13.I[south].AWVALID(awvalid[I][u_d][1][4]);
    a13.I[east].AWVALID(awvalid[I][l_r][1][3]);
    a13.I[west].AWVALID(awvalid[I][l_r][1][4]);
    a13.I[local].AWVALID(awvalid_local[I][1][3]);

    a13.I[north].WVALID(wvalid[I][u_d][1][3]);
    a13.I[south].WVALID(wvalid[I][u_d][1][4]);
    a13.I[east].WVALID(wvalid[I][l_r][1][3]);
    a13.I[west].WVALID(wvalid[I][l_r][1][4]);
    a13.I[local].WVALID(wvalid_local[I][1][3]);

    a13.I[north].BVALID(bvalid[I][u_d][1][3]);
    a13.I[south].BVALID(bvalid[I][u_d][1][4]);
    a13.I[east].BVALID(bvalid[I][l_r][1][3]);
    a13.I[west].BVALID(bvalid[I][l_r][1][4]);
    a13.I[local].BVALID(bvalid_local[I][1][3]);

    a13.I[north].AWREADY(awready[I][u_d][1][3]);
    a13.I[south].AWREADY(awready[I][u_d][1][4]);
    a13.I[east].AWREADY(awready[I][l_r][1][3]);
    a13.I[west].AWREADY(awready[I][l_r][1][4]);
    a13.I[local].AWREADY(awready_local[I][1][3]);

    a13.I[north].WREADY(wready[I][u_d][1][3]);
    a13.I[south].WREADY(wready[I][u_d][1][4]);
    a13.I[east].WREADY(wready[I][l_r][1][3]);
    a13.I[west].WREADY(wready[I][l_r][1][4]);
    a13.I[local].WREADY(wready_local[I][1][3]);

    a13.I[north].BREADY(bready[I][u_d][1][3]);
    a13.I[south].BREADY(bready[I][u_d][1][4]);
    a13.I[east].BREADY(bready[I][l_r][1][3]);
    a13.I[west].BREADY(bready[I][l_r][1][4]);
    a13.I[local].BREADY(bready_local[I][1][3]);

    //output
    
    a13.O[north].write_address_channel(aw[O][u_d][1][3]);
    a13.O[south].write_address_channel(aw[O][u_d][1][4]);
    a13.O[east].write_address_channel(aw[O][l_r][1][3]);
    a13.O[west].write_address_channel(aw[O][l_r][1][4]);
    a13.O[local].write_address_channel(aw_local[O][1][3]);

    a13.O[north].write_data_channel(w[O][u_d][1][3]);
    a13.O[south].write_data_channel(w[O][u_d][1][4]);
    a13.O[east].write_data_channel(w[O][l_r][1][3]);
    a13.O[west].write_data_channel(w[O][l_r][1][4]);
    a13.O[local].write_data_channel(w_local[O][1][3]);
    

    a13.O[north].write_response_channel(b[O][u_d][1][3]);
    a13.O[south].write_response_channel(b[O][u_d][1][4]);
    a13.O[east].write_response_channel(b[O][l_r][1][3]);
    a13.O[west].write_response_channel(b[O][l_r][1][4]);
    a13.O[local].write_response_channel(b_local[O][1][3]);

    a13.O[north].AWVALID(awvalid[O][u_d][1][3]);
    a13.O[south].AWVALID(awvalid[O][u_d][1][4]);
    a13.O[east].AWVALID(awvalid[O][l_r][1][3]);
    a13.O[west].AWVALID(awvalid[O][l_r][1][4]);
    a13.O[local].AWVALID(awvalid_local[O][1][3]);

    a13.O[north].WVALID(wvalid[O][u_d][1][3]);
    a13.O[south].WVALID(wvalid[O][u_d][1][4]);
    a13.O[east].WVALID(wvalid[O][l_r][1][3]);
    a13.O[west].WVALID(wvalid[O][l_r][1][4]);
    a13.O[local].WVALID(wvalid_local[O][1][3]);

    a13.O[north].BVALID(bvalid[O][u_d][1][3]);
    a13.O[south].BVALID(bvalid[O][u_d][1][4]);
    a13.O[east].BVALID(bvalid[O][l_r][1][3]);
    a13.O[west].BVALID(bvalid[O][l_r][1][4]);
    a13.O[local].BVALID(bvalid_local[O][1][3]);

    a13.O[north].AWREADY(awready[O][u_d][1][3]);
    a13.O[south].AWREADY(awready[O][u_d][1][4]);
    a13.O[east].AWREADY(awready[O][l_r][1][3]);
    a13.O[west].AWREADY(awready[O][l_r][1][4]);
    a13.O[local].AWREADY(awready_local[O][1][3]);

    a13.O[north].WREADY(wready[O][u_d][1][3]);
    a13.O[south].WREADY(wready[O][u_d][1][4]);
    a13.O[east].WREADY(wready[O][l_r][1][3]);
    a13.O[west].WREADY(wready[O][l_r][1][4]);
    a13.O[local].WREADY(wready_local[O][1][3]);

    a13.O[north].BREADY(bready[O][u_d][1][3]);
    a13.O[south].BREADY(bready[O][u_d][1][4]);
    a13.O[east].BREADY(bready[O][l_r][1][3]);
    a13.O[west].BREADY(bready[O][l_r][1][4]);
    a13.O[local].BREADY(bready_local[O][1][3]);


    Router a20("20");
    a20.clk(clock);
    //input
    a20.I[north].write_address_channel(aw[I][u_d][2][0]);
    a20.I[south].write_address_channel(aw[I][u_d][2][1]);
    a20.I[east].write_address_channel(aw[I][l_r][2][0]);
    a20.I[west].write_address_channel(aw[I][l_r][2][1]);
    a20.I[local].write_address_channel(aw_local[I][2][0]);

    a20.I[north].write_data_channel(w[I][u_d][2][0]);
    a20.I[south].write_data_channel(w[I][u_d][2][1]);
    a20.I[east].write_data_channel(w[I][l_r][2][0]);
    a20.I[west].write_data_channel(w[I][l_r][2][1]);
    a20.I[local].write_data_channel(w_local[I][2][0]);

    a20.I[north].write_response_channel(b[I][u_d][2][0]);
    a20.I[south].write_response_channel(b[I][u_d][2][1]);
    a20.I[east].write_response_channel(b[I][l_r][2][0]);
    a20.I[west].write_response_channel(b[I][l_r][2][1]);
    a20.I[local].write_response_channel(b_local[I][2][0]);

    a20.I[north].AWVALID(awvalid[I][u_d][2][0]);
    a20.I[south].AWVALID(awvalid[I][u_d][2][1]);
    a20.I[east].AWVALID(awvalid[I][l_r][2][0]);
    a20.I[west].AWVALID(awvalid[I][l_r][2][1]);
    a20.I[local].AWVALID(awvalid_local[I][2][0]);

    a20.I[north].WVALID(wvalid[I][u_d][2][0]);
    a20.I[south].WVALID(wvalid[I][u_d][2][1]);
    a20.I[east].WVALID(wvalid[I][l_r][2][0]);
    a20.I[west].WVALID(wvalid[I][l_r][2][1]);
    a20.I[local].WVALID(wvalid_local[I][2][0]);

    a20.I[north].BVALID(bvalid[I][u_d][2][0]);
    a20.I[south].BVALID(bvalid[I][u_d][2][1]);
    a20.I[east].BVALID(bvalid[I][l_r][2][0]);
    a20.I[west].BVALID(bvalid[I][l_r][2][1]);
    a20.I[local].BVALID(bvalid_local[I][2][0]);

    a20.I[north].AWREADY(awready[I][u_d][2][0]);
    a20.I[south].AWREADY(awready[I][u_d][2][1]);
    a20.I[east].AWREADY(awready[I][l_r][2][0]);
    a20.I[west].AWREADY(awready[I][l_r][2][1]);
    a20.I[local].AWREADY(awready_local[I][2][0]);

    a20.I[north].WREADY(wready[I][u_d][2][0]);
    a20.I[south].WREADY(wready[I][u_d][2][1]);
    a20.I[east].WREADY(wready[I][l_r][2][0]);
    a20.I[west].WREADY(wready[I][l_r][2][1]);
    a20.I[local].WREADY(wready_local[I][2][0]);

    a20.I[north].BREADY(bready[I][u_d][2][0]);
    a20.I[south].BREADY(bready[I][u_d][2][1]);
    a20.I[east].BREADY(bready[I][l_r][2][0]);
    a20.I[west].BREADY(bready[I][l_r][2][1]);
    a20.I[local].BREADY(bready_local[I][2][0]);

    //output
    
    a20.O[north].write_address_channel(aw[O][u_d][2][0]);
    a20.O[south].write_address_channel(aw[O][u_d][2][1]);
    a20.O[east].write_address_channel(aw[O][l_r][2][0]);
    a20.O[west].write_address_channel(aw[O][l_r][2][1]);
    a20.O[local].write_address_channel(aw_local[O][2][0]);

    a20.O[north].write_data_channel(w[O][u_d][2][0]);
    a20.O[south].write_data_channel(w[O][u_d][2][1]);
    a20.O[east].write_data_channel(w[O][l_r][2][0]);
    a20.O[west].write_data_channel(w[O][l_r][2][1]);
    a20.O[local].write_data_channel(w_local[O][2][0]);
    

    a20.O[north].write_response_channel(b[O][u_d][2][0]);
    a20.O[south].write_response_channel(b[O][u_d][2][1]);
    a20.O[east].write_response_channel(b[O][l_r][2][0]);
    a20.O[west].write_response_channel(b[O][l_r][2][1]);
    a20.O[local].write_response_channel(b_local[O][2][0]);

    a20.O[north].AWVALID(awvalid[O][u_d][2][0]);
    a20.O[south].AWVALID(awvalid[O][u_d][2][1]);
    a20.O[east].AWVALID(awvalid[O][l_r][2][0]);
    a20.O[west].AWVALID(awvalid[O][l_r][2][1]);
    a20.O[local].AWVALID(awvalid_local[O][2][0]);

    a20.O[north].WVALID(wvalid[O][u_d][2][0]);
    a20.O[south].WVALID(wvalid[O][u_d][2][1]);
    a20.O[east].WVALID(wvalid[O][l_r][2][0]);
    a20.O[west].WVALID(wvalid[O][l_r][2][1]);
    a20.O[local].WVALID(wvalid_local[O][2][0]);

    a20.O[north].BVALID(bvalid[O][u_d][2][0]);
    a20.O[south].BVALID(bvalid[O][u_d][2][1]);
    a20.O[east].BVALID(bvalid[O][l_r][2][0]);
    a20.O[west].BVALID(bvalid[O][l_r][2][1]);
    a20.O[local].BVALID(bvalid_local[O][2][0]);

    a20.O[north].AWREADY(awready[O][u_d][2][0]);
    a20.O[south].AWREADY(awready[O][u_d][2][1]);
    a20.O[east].AWREADY(awready[O][l_r][2][0]);
    a20.O[west].AWREADY(awready[O][l_r][2][1]);
    a20.O[local].AWREADY(awready_local[O][2][0]);

    a20.O[north].WREADY(wready[O][u_d][2][0]);
    a20.O[south].WREADY(wready[O][u_d][2][1]);
    a20.O[east].WREADY(wready[O][l_r][2][0]);
    a20.O[west].WREADY(wready[O][l_r][2][1]);
    a20.O[local].WREADY(wready_local[O][2][0]);

    a20.O[north].BREADY(bready[O][u_d][2][0]);
    a20.O[south].BREADY(bready[O][u_d][2][1]);
    a20.O[east].BREADY(bready[O][l_r][2][0]);
    a20.O[west].BREADY(bready[O][l_r][2][1]);
    a20.O[local].BREADY(bready_local[O][2][0]);


    Router a21("21");
    a21.clk(clock);
    //input
    a21.I[north].write_address_channel(aw[I][u_d][2][1]);
    a21.I[south].write_address_channel(aw[I][u_d][2][2]);
    a21.I[east].write_address_channel(aw[I][l_r][2][1]);
    a21.I[west].write_address_channel(aw[I][l_r][2][2]);
    a21.I[local].write_address_channel(aw_local[I][2][1]);

    a21.I[north].write_data_channel(w[I][u_d][2][1]);
    a21.I[south].write_data_channel(w[I][u_d][2][2]);
    a21.I[east].write_data_channel(w[I][l_r][2][1]);
    a21.I[west].write_data_channel(w[I][l_r][2][2]);
    a21.I[local].write_data_channel(w_local[I][2][1]);

    a21.I[north].write_response_channel(b[I][u_d][2][1]);
    a21.I[south].write_response_channel(b[I][u_d][2][2]);
    a21.I[east].write_response_channel(b[I][l_r][2][1]);
    a21.I[west].write_response_channel(b[I][l_r][2][2]);
    a21.I[local].write_response_channel(b_local[I][2][1]);

    a21.I[north].AWVALID(awvalid[I][u_d][2][1]);
    a21.I[south].AWVALID(awvalid[I][u_d][2][2]);
    a21.I[east].AWVALID(awvalid[I][l_r][2][1]);
    a21.I[west].AWVALID(awvalid[I][l_r][2][2]);
    a21.I[local].AWVALID(awvalid_local[I][2][1]);

    a21.I[north].WVALID(wvalid[I][u_d][2][1]);
    a21.I[south].WVALID(wvalid[I][u_d][2][2]);
    a21.I[east].WVALID(wvalid[I][l_r][2][1]);
    a21.I[west].WVALID(wvalid[I][l_r][2][2]);
    a21.I[local].WVALID(wvalid_local[I][2][1]);

    a21.I[north].BVALID(bvalid[I][u_d][2][1]);
    a21.I[south].BVALID(bvalid[I][u_d][2][2]);
    a21.I[east].BVALID(bvalid[I][l_r][2][1]);
    a21.I[west].BVALID(bvalid[I][l_r][2][2]);
    a21.I[local].BVALID(bvalid_local[I][2][1]);

    a21.I[north].AWREADY(awready[I][u_d][2][1]);
    a21.I[south].AWREADY(awready[I][u_d][2][2]);
    a21.I[east].AWREADY(awready[I][l_r][2][1]);
    a21.I[west].AWREADY(awready[I][l_r][2][2]);
    a21.I[local].AWREADY(awready_local[I][2][1]);

    a21.I[north].WREADY(wready[I][u_d][2][1]);
    a21.I[south].WREADY(wready[I][u_d][2][2]);
    a21.I[east].WREADY(wready[I][l_r][2][1]);
    a21.I[west].WREADY(wready[I][l_r][2][2]);
    a21.I[local].WREADY(wready_local[I][2][1]);

    a21.I[north].BREADY(bready[I][u_d][2][1]);
    a21.I[south].BREADY(bready[I][u_d][2][2]);
    a21.I[east].BREADY(bready[I][l_r][2][1]);
    a21.I[west].BREADY(bready[I][l_r][2][2]);
    a21.I[local].BREADY(bready_local[I][2][1]);

    //output
    
    a21.O[north].write_address_channel(aw[O][u_d][2][1]);
    a21.O[south].write_address_channel(aw[O][u_d][2][2]);
    a21.O[east].write_address_channel(aw[O][l_r][2][1]);
    a21.O[west].write_address_channel(aw[O][l_r][2][2]);
    a21.O[local].write_address_channel(aw_local[O][2][1]);

    a21.O[north].write_data_channel(w[O][u_d][2][1]);
    a21.O[south].write_data_channel(w[O][u_d][2][2]);
    a21.O[east].write_data_channel(w[O][l_r][2][1]);
    a21.O[west].write_data_channel(w[O][l_r][2][2]);
    a21.O[local].write_data_channel(w_local[O][2][1]);
    

    a21.O[north].write_response_channel(b[O][u_d][2][1]);
    a21.O[south].write_response_channel(b[O][u_d][2][2]);
    a21.O[east].write_response_channel(b[O][l_r][2][1]);
    a21.O[west].write_response_channel(b[O][l_r][2][2]);
    a21.O[local].write_response_channel(b_local[O][2][1]);

    a21.O[north].AWVALID(awvalid[O][u_d][2][1]);
    a21.O[south].AWVALID(awvalid[O][u_d][2][2]);
    a21.O[east].AWVALID(awvalid[O][l_r][2][1]);
    a21.O[west].AWVALID(awvalid[O][l_r][2][2]);
    a21.O[local].AWVALID(awvalid_local[O][2][1]);

    a21.O[north].WVALID(wvalid[O][u_d][2][1]);
    a21.O[south].WVALID(wvalid[O][u_d][2][2]);
    a21.O[east].WVALID(wvalid[O][l_r][2][1]);
    a21.O[west].WVALID(wvalid[O][l_r][2][2]);
    a21.O[local].WVALID(wvalid_local[O][2][1]);

    a21.O[north].BVALID(bvalid[O][u_d][2][1]);
    a21.O[south].BVALID(bvalid[O][u_d][2][2]);
    a21.O[east].BVALID(bvalid[O][l_r][2][1]);
    a21.O[west].BVALID(bvalid[O][l_r][2][2]);
    a21.O[local].BVALID(bvalid_local[O][2][1]);

    a21.O[north].AWREADY(awready[O][u_d][2][1]);
    a21.O[south].AWREADY(awready[O][u_d][2][2]);
    a21.O[east].AWREADY(awready[O][l_r][2][1]);
    a21.O[west].AWREADY(awready[O][l_r][2][2]);
    a21.O[local].AWREADY(awready_local[O][2][1]);

    a21.O[north].WREADY(wready[O][u_d][2][1]);
    a21.O[south].WREADY(wready[O][u_d][2][2]);
    a21.O[east].WREADY(wready[O][l_r][2][1]);
    a21.O[west].WREADY(wready[O][l_r][2][2]);
    a21.O[local].WREADY(wready_local[O][2][1]);

    a21.O[north].BREADY(bready[O][u_d][2][1]);
    a21.O[south].BREADY(bready[O][u_d][2][2]);
    a21.O[east].BREADY(bready[O][l_r][2][1]);
    a21.O[west].BREADY(bready[O][l_r][2][2]);
    a21.O[local].BREADY(bready_local[O][2][1]);


    Router a22("22");
    a22.clk(clock);
    //input
    a22.I[north].write_address_channel(aw[I][u_d][2][2]);
    a22.I[south].write_address_channel(aw[I][u_d][2][3]);
    a22.I[east].write_address_channel(aw[I][l_r][2][2]);
    a22.I[west].write_address_channel(aw[I][l_r][2][3]);
    a22.I[local].write_address_channel(aw_local[I][2][2]);

    a22.I[north].write_data_channel(w[I][u_d][2][2]);
    a22.I[south].write_data_channel(w[I][u_d][2][3]);
    a22.I[east].write_data_channel(w[I][l_r][2][2]);
    a22.I[west].write_data_channel(w[I][l_r][2][3]);
    a22.I[local].write_data_channel(w_local[I][2][2]);

    a22.I[north].write_response_channel(b[I][u_d][2][2]);
    a22.I[south].write_response_channel(b[I][u_d][2][3]);
    a22.I[east].write_response_channel(b[I][l_r][2][2]);
    a22.I[west].write_response_channel(b[I][l_r][2][3]);
    a22.I[local].write_response_channel(b_local[I][2][2]);

    a22.I[north].AWVALID(awvalid[I][u_d][2][2]);
    a22.I[south].AWVALID(awvalid[I][u_d][2][3]);
    a22.I[east].AWVALID(awvalid[I][l_r][2][2]);
    a22.I[west].AWVALID(awvalid[I][l_r][2][3]);
    a22.I[local].AWVALID(awvalid_local[I][2][2]);

    a22.I[north].WVALID(wvalid[I][u_d][2][2]);
    a22.I[south].WVALID(wvalid[I][u_d][2][3]);
    a22.I[east].WVALID(wvalid[I][l_r][2][2]);
    a22.I[west].WVALID(wvalid[I][l_r][2][3]);
    a22.I[local].WVALID(wvalid_local[I][2][2]);

    a22.I[north].BVALID(bvalid[I][u_d][2][2]);
    a22.I[south].BVALID(bvalid[I][u_d][2][3]);
    a22.I[east].BVALID(bvalid[I][l_r][2][2]);
    a22.I[west].BVALID(bvalid[I][l_r][2][3]);
    a22.I[local].BVALID(bvalid_local[I][2][2]);

    a22.I[north].AWREADY(awready[I][u_d][2][2]);
    a22.I[south].AWREADY(awready[I][u_d][2][3]);
    a22.I[east].AWREADY(awready[I][l_r][2][2]);
    a22.I[west].AWREADY(awready[I][l_r][2][3]);
    a22.I[local].AWREADY(awready_local[I][2][2]);

    a22.I[north].WREADY(wready[I][u_d][2][2]);
    a22.I[south].WREADY(wready[I][u_d][2][3]);
    a22.I[east].WREADY(wready[I][l_r][2][2]);
    a22.I[west].WREADY(wready[I][l_r][2][3]);
    a22.I[local].WREADY(wready_local[I][2][2]);

    a22.I[north].BREADY(bready[I][u_d][2][2]);
    a22.I[south].BREADY(bready[I][u_d][2][3]);
    a22.I[east].BREADY(bready[I][l_r][2][2]);
    a22.I[west].BREADY(bready[I][l_r][2][3]);
    a22.I[local].BREADY(bready_local[I][2][2]);

    //output
    
    a22.O[north].write_address_channel(aw[O][u_d][2][2]);
    a22.O[south].write_address_channel(aw[O][u_d][2][3]);
    a22.O[east].write_address_channel(aw[O][l_r][2][2]);
    a22.O[west].write_address_channel(aw[O][l_r][2][3]);
    a22.O[local].write_address_channel(aw_local[O][2][2]);

    a22.O[north].write_data_channel(w[O][u_d][2][2]);
    a22.O[south].write_data_channel(w[O][u_d][2][3]);
    a22.O[east].write_data_channel(w[O][l_r][2][2]);
    a22.O[west].write_data_channel(w[O][l_r][2][3]);
    a22.O[local].write_data_channel(w_local[O][2][2]);
    

    a22.O[north].write_response_channel(b[O][u_d][2][2]);
    a22.O[south].write_response_channel(b[O][u_d][2][3]);
    a22.O[east].write_response_channel(b[O][l_r][2][2]);
    a22.O[west].write_response_channel(b[O][l_r][2][3]);
    a22.O[local].write_response_channel(b_local[O][2][2]);

    a22.O[north].AWVALID(awvalid[O][u_d][2][2]);
    a22.O[south].AWVALID(awvalid[O][u_d][2][3]);
    a22.O[east].AWVALID(awvalid[O][l_r][2][2]);
    a22.O[west].AWVALID(awvalid[O][l_r][2][3]);
    a22.O[local].AWVALID(awvalid_local[O][2][2]);

    a22.O[north].WVALID(wvalid[O][u_d][2][2]);
    a22.O[south].WVALID(wvalid[O][u_d][2][3]);
    a22.O[east].WVALID(wvalid[O][l_r][2][2]);
    a22.O[west].WVALID(wvalid[O][l_r][2][3]);
    a22.O[local].WVALID(wvalid_local[O][2][2]);

    a22.O[north].BVALID(bvalid[O][u_d][2][2]);
    a22.O[south].BVALID(bvalid[O][u_d][2][3]);
    a22.O[east].BVALID(bvalid[O][l_r][2][2]);
    a22.O[west].BVALID(bvalid[O][l_r][2][3]);
    a22.O[local].BVALID(bvalid_local[O][2][2]);

    a22.O[north].AWREADY(awready[O][u_d][2][2]);
    a22.O[south].AWREADY(awready[O][u_d][2][3]);
    a22.O[east].AWREADY(awready[O][l_r][2][2]);
    a22.O[west].AWREADY(awready[O][l_r][2][3]);
    a22.O[local].AWREADY(awready_local[O][2][2]);

    a22.O[north].WREADY(wready[O][u_d][2][2]);
    a22.O[south].WREADY(wready[O][u_d][2][3]);
    a22.O[east].WREADY(wready[O][l_r][2][2]);
    a22.O[west].WREADY(wready[O][l_r][2][3]);
    a22.O[local].WREADY(wready_local[O][2][2]);

    a22.O[north].BREADY(bready[O][u_d][2][2]);
    a22.O[south].BREADY(bready[O][u_d][2][3]);
    a22.O[east].BREADY(bready[O][l_r][2][2]);
    a22.O[west].BREADY(bready[O][l_r][2][3]);
    a22.O[local].BREADY(bready_local[O][2][2]);


    Router a23("23");
    a23.clk(clock);
    //input
    a23.I[north].write_address_channel(aw[I][u_d][2][3]);
    a23.I[south].write_address_channel(aw[I][u_d][2][4]);
    a23.I[east].write_address_channel(aw[I][l_r][2][3]);
    a23.I[west].write_address_channel(aw[I][l_r][2][4]);
    a23.I[local].write_address_channel(aw_local[I][2][3]);

    a23.I[north].write_data_channel(w[I][u_d][2][3]);
    a23.I[south].write_data_channel(w[I][u_d][2][4]);
    a23.I[east].write_data_channel(w[I][l_r][2][3]);
    a23.I[west].write_data_channel(w[I][l_r][2][4]);
    a23.I[local].write_data_channel(w_local[I][2][3]);

    a23.I[north].write_response_channel(b[I][u_d][2][3]);
    a23.I[south].write_response_channel(b[I][u_d][2][4]);
    a23.I[east].write_response_channel(b[I][l_r][2][3]);
    a23.I[west].write_response_channel(b[I][l_r][2][4]);
    a23.I[local].write_response_channel(b_local[I][2][3]);

    a23.I[north].AWVALID(awvalid[I][u_d][2][3]);
    a23.I[south].AWVALID(awvalid[I][u_d][2][4]);
    a23.I[east].AWVALID(awvalid[I][l_r][2][3]);
    a23.I[west].AWVALID(awvalid[I][l_r][2][4]);
    a23.I[local].AWVALID(awvalid_local[I][2][3]);

    a23.I[north].WVALID(wvalid[I][u_d][2][3]);
    a23.I[south].WVALID(wvalid[I][u_d][2][4]);
    a23.I[east].WVALID(wvalid[I][l_r][2][3]);
    a23.I[west].WVALID(wvalid[I][l_r][2][4]);
    a23.I[local].WVALID(wvalid_local[I][2][3]);

    a23.I[north].BVALID(bvalid[I][u_d][2][3]);
    a23.I[south].BVALID(bvalid[I][u_d][2][4]);
    a23.I[east].BVALID(bvalid[I][l_r][2][3]);
    a23.I[west].BVALID(bvalid[I][l_r][2][4]);
    a23.I[local].BVALID(bvalid_local[I][2][3]);

    a23.I[north].AWREADY(awready[I][u_d][2][3]);
    a23.I[south].AWREADY(awready[I][u_d][2][4]);
    a23.I[east].AWREADY(awready[I][l_r][2][3]);
    a23.I[west].AWREADY(awready[I][l_r][2][4]);
    a23.I[local].AWREADY(awready_local[I][2][3]);

    a23.I[north].WREADY(wready[I][u_d][2][3]);
    a23.I[south].WREADY(wready[I][u_d][2][4]);
    a23.I[east].WREADY(wready[I][l_r][2][3]);
    a23.I[west].WREADY(wready[I][l_r][2][4]);
    a23.I[local].WREADY(wready_local[I][2][3]);

    a23.I[north].BREADY(bready[I][u_d][2][3]);
    a23.I[south].BREADY(bready[I][u_d][2][4]);
    a23.I[east].BREADY(bready[I][l_r][2][3]);
    a23.I[west].BREADY(bready[I][l_r][2][4]);
    a23.I[local].BREADY(bready_local[I][2][3]);

    //output
    
    a23.O[north].write_address_channel(aw[O][u_d][2][3]);
    a23.O[south].write_address_channel(aw[O][u_d][2][4]);
    a23.O[east].write_address_channel(aw[O][l_r][2][3]);
    a23.O[west].write_address_channel(aw[O][l_r][2][4]);
    a23.O[local].write_address_channel(aw_local[O][2][3]);

    a23.O[north].write_data_channel(w[O][u_d][2][3]);
    a23.O[south].write_data_channel(w[O][u_d][2][4]);
    a23.O[east].write_data_channel(w[O][l_r][2][3]);
    a23.O[west].write_data_channel(w[O][l_r][2][4]);
    a23.O[local].write_data_channel(w_local[O][2][3]);
    

    a23.O[north].write_response_channel(b[O][u_d][2][3]);
    a23.O[south].write_response_channel(b[O][u_d][2][4]);
    a23.O[east].write_response_channel(b[O][l_r][2][3]);
    a23.O[west].write_response_channel(b[O][l_r][2][4]);
    a23.O[local].write_response_channel(b_local[O][2][3]);

    a23.O[north].AWVALID(awvalid[O][u_d][2][3]);
    a23.O[south].AWVALID(awvalid[O][u_d][2][4]);
    a23.O[east].AWVALID(awvalid[O][l_r][2][3]);
    a23.O[west].AWVALID(awvalid[O][l_r][2][4]);
    a23.O[local].AWVALID(awvalid_local[O][2][3]);

    a23.O[north].WVALID(wvalid[O][u_d][2][3]);
    a23.O[south].WVALID(wvalid[O][u_d][2][4]);
    a23.O[east].WVALID(wvalid[O][l_r][2][3]);
    a23.O[west].WVALID(wvalid[O][l_r][2][4]);
    a23.O[local].WVALID(wvalid_local[O][2][3]);

    a23.O[north].BVALID(bvalid[O][u_d][2][3]);
    a23.O[south].BVALID(bvalid[O][u_d][2][4]);
    a23.O[east].BVALID(bvalid[O][l_r][2][3]);
    a23.O[west].BVALID(bvalid[O][l_r][2][4]);
    a23.O[local].BVALID(bvalid_local[O][2][3]);

    a23.O[north].AWREADY(awready[O][u_d][2][3]);
    a23.O[south].AWREADY(awready[O][u_d][2][4]);
    a23.O[east].AWREADY(awready[O][l_r][2][3]);
    a23.O[west].AWREADY(awready[O][l_r][2][4]);
    a23.O[local].AWREADY(awready_local[O][2][3]);

    a23.O[north].WREADY(wready[O][u_d][2][3]);
    a23.O[south].WREADY(wready[O][u_d][2][4]);
    a23.O[east].WREADY(wready[O][l_r][2][3]);
    a23.O[west].WREADY(wready[O][l_r][2][4]);
    a23.O[local].WREADY(wready_local[O][2][3]);

    a23.O[north].BREADY(bready[O][u_d][2][3]);
    a23.O[south].BREADY(bready[O][u_d][2][4]);
    a23.O[east].BREADY(bready[O][l_r][2][3]);
    a23.O[west].BREADY(bready[O][l_r][2][4]);
    a23.O[local].BREADY(bready_local[O][2][3]);

  

    return 0;
}
