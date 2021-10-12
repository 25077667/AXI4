#include "Router/router.h"
#include "NI/network_interface.h"
SC_MODULE(Routing)
{
    sc_in_clk clock;
    void routing()
    {
               
        int x,y;
        x = 1;
        y = 2;
        //Write Address Channel
        sc_signal<sc_uint<54>,SC_MANY_WRITERS > aw[IO_PORT_NUM][DIRECTION_NUM][1][2+1];
        sc_signal<sc_uint<54>,SC_MANY_WRITERS > aw_local[IO_PORT_NUM][1][2];
        //Write Data Channel
        sc_signal<sc_uint<41>,SC_MANY_WRITERS > w[IO_PORT_NUM][DIRECTION_NUM][1][2+1];
        sc_signal<sc_uint<41>,SC_MANY_WRITERS > w_local[IO_PORT_NUM][1][2];
        //Write Response Channel
        sc_signal<sc_uint<6>,SC_MANY_WRITERS > b[IO_PORT_NUM][DIRECTION_NUM][1][2+1];
        sc_signal<sc_uint<6>,SC_MANY_WRITERS > b_local[IO_PORT_NUM][1][2];
        //Ready signals
        sc_signal<bool> awready[IO_PORT_NUM][DIRECTION_NUM][1][2+1] , awready_local[IO_PORT_NUM][1][2];
        sc_signal<bool> wready[IO_PORT_NUM][DIRECTION_NUM][1][2+1] , wready_local[IO_PORT_NUM][1][2];
        sc_signal<bool> bready[IO_PORT_NUM][DIRECTION_NUM][1][2+1] , bready_local[IO_PORT_NUM][1][2];
        //Valid signals
        sc_signal<bool> awvalid[IO_PORT_NUM][DIRECTION_NUM][1][2+1] , awvalid_local[IO_PORT_NUM][1][2];
        sc_signal<bool> wvalid[IO_PORT_NUM][DIRECTION_NUM][1][2+1] , wvalid_local[IO_PORT_NUM][1][2];
        sc_signal<bool> bvalid[IO_PORT_NUM][DIRECTION_NUM][1][2+1] , bvalid_local[IO_PORT_NUM][1][2];


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

  

        return;
    }
    SC_CTOR(Routing)
    {
        routing();
    }
};
