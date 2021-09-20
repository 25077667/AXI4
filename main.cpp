#include "Router/router.h"
#include "NI/network_interface.h"

int sc_main(int argc , char *argv[])
{   
    int x,y;
    cout << "(x,y) :" ;
    //cin >> x >> y;
    cout << "(0,0)" << endl;
    x = y = 1;
    //Write Address Channel
    sc_signal<sc_uint<54>,SC_MANY_WRITERS > aw[IO_PORT_NUM][DIRECTION_NUM][x][y+1];
    sc_signal<sc_uint<54>,SC_MANY_WRITERS > aw_local[IO_PORT_NUM][x][y];
    //Write Data Channel
    sc_signal<sc_uint<41>,SC_MANY_WRITERS > w[IO_PORT_NUM][DIRECTION_NUM][x][y+1];
    sc_signal<sc_uint<41>,SC_MANY_WRITERS > w_local[IO_PORT_NUM][x][y];
    //Write Response Channel
    sc_signal<sc_uint<6>,SC_MANY_WRITERS > b[IO_PORT_NUM][DIRECTION_NUM][x][y+1];
    sc_signal<sc_uint<6>,SC_MANY_WRITERS > b_local[IO_PORT_NUM][x][y];
    //Ready signals
    sc_signal<bool> awready[IO_PORT_NUM][DIRECTION_NUM][x][y+1] , awready_local[IO_PORT_NUM][x][y];
    sc_signal<bool> wready[IO_PORT_NUM][DIRECTION_NUM][x][y+1] , wready_local[IO_PORT_NUM][x][y];
    sc_signal<bool> arready[IO_PORT_NUM][DIRECTION_NUM][x][y+1] , arready_local[IO_PORT_NUM][x][y];
    sc_signal<bool> rready[IO_PORT_NUM][DIRECTION_NUM][x][y+1] , rready_local[IO_PORT_NUM][x][y];
    sc_signal<bool> bready[IO_PORT_NUM][DIRECTION_NUM][x][y+1] , bready_local[IO_PORT_NUM][x][y];
    //Valid signals
    sc_signal<bool> awvalid[IO_PORT_NUM][DIRECTION_NUM][x][y+1] , awvalid_local[IO_PORT_NUM][x][y];
    sc_signal<bool> wvalid[IO_PORT_NUM][DIRECTION_NUM][x][y+1] , wvalid_local[IO_PORT_NUM][x][y];
    sc_signal<bool> arvalid[IO_PORT_NUM][DIRECTION_NUM][x][y+1] , arvalid_local[IO_PORT_NUM][x][y];
    sc_signal<bool> rvalid[IO_PORT_NUM][DIRECTION_NUM][x][y+1] , rvalid_local[IO_PORT_NUM][x][y];
    sc_signal<bool> bvalid[IO_PORT_NUM][DIRECTION_NUM][x][y+1] , bvalid_local[IO_PORT_NUM][x][y];

    Router a00("00");
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

    a00.I[north].ARVALID(arvalid[I][u_d][0][0]);
    a00.I[south].ARVALID(arvalid[I][u_d][0][1]);
    a00.I[east].ARVALID(arvalid[I][l_r][0][0]);
    a00.I[west].ARVALID(arvalid[I][l_r][0][1]);
    a00.I[local].ARVALID(arvalid_local[I][0][0]);


    a00.I[north].RVALID(rvalid[I][u_d][0][0]);
    a00.I[south].RVALID(rvalid[I][u_d][0][1]);
    a00.I[east].RVALID(rvalid[I][l_r][0][0]);
    a00.I[west].RVALID(rvalid[I][l_r][0][1]);
    a00.I[local].RVALID(rvalid_local[I][0][0]);

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

    a00.I[north].ARREADY(arready[I][u_d][0][0]);
    a00.I[south].ARREADY(arready[I][u_d][0][1]);
    a00.I[east].ARREADY(arready[I][l_r][0][0]);
    a00.I[west].ARREADY(arready[I][l_r][0][1]);
    a00.I[local].ARREADY(arready_local[I][0][0]);


    a00.I[north].RREADY(rready[I][u_d][0][0]);
    a00.I[south].RREADY(rready[I][u_d][0][1]);
    a00.I[east].RREADY(rready[I][l_r][0][0]);
    a00.I[west].RREADY(rready[I][l_r][0][1]);
    a00.I[local].RREADY(rready_local[I][0][0]);

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

    a00.O[north].ARVALID(arvalid[O][u_d][0][0]);
    a00.O[south].ARVALID(arvalid[O][u_d][0][1]);
    a00.O[east].ARVALID(arvalid[O][l_r][0][0]);
    a00.O[west].ARVALID(arvalid[O][l_r][0][1]);
    a00.O[local].ARVALID(arvalid_local[O][0][0]);


    a00.O[north].RVALID(rvalid[O][u_d][0][0]);
    a00.O[south].RVALID(rvalid[O][u_d][0][1]);
    a00.O[east].RVALID(rvalid[O][l_r][0][0]);
    a00.O[west].RVALID(rvalid[O][l_r][0][1]);
    a00.O[local].RVALID(rvalid_local[O][0][0]);

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

    a00.O[north].ARREADY(arready[O][u_d][0][0]);
    a00.O[south].ARREADY(arready[O][u_d][0][1]);
    a00.O[east].ARREADY(arready[O][l_r][0][0]);
    a00.O[west].ARREADY(arready[O][l_r][0][1]);
    a00.O[local].ARREADY(arready_local[O][0][0]);


    a00.O[north].RREADY(rready[O][u_d][0][0]);
    a00.O[south].RREADY(rready[O][u_d][0][1]);
    a00.O[east].RREADY(rready[O][l_r][0][0]);
    a00.O[west].RREADY(rready[O][l_r][0][1]);
    a00.O[local].RREADY(rready_local[O][0][0]);

    a00.O[north].BREADY(bready[O][u_d][0][0]);
    a00.O[south].BREADY(bready[O][u_d][0][1]);
    a00.O[east].BREADY(bready[O][l_r][0][0]);
    a00.O[west].BREADY(bready[O][l_r][0][1]);
    a00.O[local].BREADY(bready_local[O][0][0]);

    
    return 0;
}
