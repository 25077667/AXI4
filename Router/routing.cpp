#include "Router/router.h"
#include "NI/network_interface.h"
SC_MODULE(Routing)
{
    sc_in_clk clock;
    void routing()
    {
               
        int x,y;
        x = 3;
        y = 2;
        //Write Address Channel
        sc_signal<sc_uint<54>,SC_MANY_WRITERS > aw[IO_PORT_NUM][DIRECTION_NUM][3][2+1];
        sc_signal<sc_uint<54>,SC_MANY_WRITERS > aw_local[IO_PORT_NUM][3][2];
        //Write Data Channel
        sc_signal<sc_uint<41>,SC_MANY_WRITERS > w[IO_PORT_NUM][DIRECTION_NUM][3][2+1];
        sc_signal<sc_uint<41>,SC_MANY_WRITERS > w_local[IO_PORT_NUM][3][2];
        //Write Response Channel
        sc_signal<sc_uint<6>,SC_MANY_WRITERS > b[IO_PORT_NUM][DIRECTION_NUM][3][2+1];
        sc_signal<sc_uint<6>,SC_MANY_WRITERS > b_local[IO_PORT_NUM][3][2];
        //Ready signals
        sc_signal<bool> awready[IO_PORT_NUM][DIRECTION_NUM][3][2+1] , awready_local[IO_PORT_NUM][3][2];
        sc_signal<bool> wready[IO_PORT_NUM][DIRECTION_NUM][3][2+1] , wready_local[IO_PORT_NUM][3][2];
        sc_signal<bool> bready[IO_PORT_NUM][DIRECTION_NUM][3][2+1] , bready_local[IO_PORT_NUM][3][2];
        //Valid signals
        sc_signal<bool> awvalid[IO_PORT_NUM][DIRECTION_NUM][3][2+1] , awvalid_local[IO_PORT_NUM][3][2];
        sc_signal<bool> wvalid[IO_PORT_NUM][DIRECTION_NUM][3][2+1] , wvalid_local[IO_PORT_NUM][3][2];
        sc_signal<bool> bvalid[IO_PORT_NUM][DIRECTION_NUM][3][2+1] , bvalid_local[IO_PORT_NUM][3][2];


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

  

        return;
    }
    SC_CTOR(Routing)
    {
        routing();
    }
};
