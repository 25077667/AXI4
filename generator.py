import sys
file = open("\\\\wsl$\\Arch\\home\\daven\\NSYSU_Project\\Router\\routing.cpp","w")
#file = open("./Router/routing.cpp","w")
x = sys.argv[1]
y = sys.argv[2]
print(x,y)
str4replace = "B"
str2write = '''#include \"Router/router.h\"
#include \"NI/network_interface.h\"
SC_MODULE(Routing)
{
    sc_in_clk clock;
    void routing()
    {
        '''
file.write(str2write)
str2write = '''       
        int x,y;
        x = {x};
        y = {y};
        //Write Address Channel
        sc_signal<sc_uint<54>,SC_MANY_WRITERS > aw[IO_PORT_NUM][DIRECTION_NUM][{x}][{y}+1];
        sc_signal<sc_uint<54>,SC_MANY_WRITERS > aw_local[IO_PORT_NUM][{x}][{y}];
        //Write Data Channel
        sc_signal<sc_uint<41>,SC_MANY_WRITERS > w[IO_PORT_NUM][DIRECTION_NUM][{x}][{y}+1];
        sc_signal<sc_uint<41>,SC_MANY_WRITERS > w_local[IO_PORT_NUM][{x}][{y}];
        //Write Response Channel
        sc_signal<sc_uint<6>,SC_MANY_WRITERS > b[IO_PORT_NUM][DIRECTION_NUM][{x}][{y}+1];
        sc_signal<sc_uint<6>,SC_MANY_WRITERS > b_local[IO_PORT_NUM][{x}][{y}];
        //Ready signals
        sc_signal<bool> awready[IO_PORT_NUM][DIRECTION_NUM][{x}][{y}+1] , awready_local[IO_PORT_NUM][{x}][{y}];
        sc_signal<bool> wready[IO_PORT_NUM][DIRECTION_NUM][{x}][{y}+1] , wready_local[IO_PORT_NUM][{x}][{y}];
        sc_signal<bool> bready[IO_PORT_NUM][DIRECTION_NUM][{x}][{y}+1] , bready_local[IO_PORT_NUM][{x}][{y}];
        //Valid signals
        sc_signal<bool> awvalid[IO_PORT_NUM][DIRECTION_NUM][{x}][{y}+1] , awvalid_local[IO_PORT_NUM][{x}][{y}];
        sc_signal<bool> wvalid[IO_PORT_NUM][DIRECTION_NUM][{x}][{y}+1] , wvalid_local[IO_PORT_NUM][{x}][{y}];
        sc_signal<bool> bvalid[IO_PORT_NUM][DIRECTION_NUM][{x}][{y}+1] , bvalid_local[IO_PORT_NUM][{x}][{y}];

'''
file.write(str2write.format(x=x,y=y))

str2write = '''
        Router a{i}{j}("{i}{j}");
        a{i}{j}.clk(clock);
        //input
        a{i}{j}.I[north].write_address_channel(aw[I][u_d][{i}][{j}]);
        a{i}{j}.I[south].write_address_channel(aw[I][u_d][{i}][{k}]);
        a{i}{j}.I[east].write_address_channel(aw[I][l_r][{i}][{j}]);
        a{i}{j}.I[west].write_address_channel(aw[I][l_r][{i}][{k}]);
        a{i}{j}.I[local].write_address_channel(aw_local[I][{i}][{j}]);

        a{i}{j}.I[north].write_data_channel(w[I][u_d][{i}][{j}]);
        a{i}{j}.I[south].write_data_channel(w[I][u_d][{i}][{k}]);
        a{i}{j}.I[east].write_data_channel(w[I][l_r][{i}][{j}]);
        a{i}{j}.I[west].write_data_channel(w[I][l_r][{i}][{k}]);
        a{i}{j}.I[local].write_data_channel(w_local[I][{i}][{j}]);

        a{i}{j}.I[north].write_response_channel(b[I][u_d][{i}][{j}]);
        a{i}{j}.I[south].write_response_channel(b[I][u_d][{i}][{k}]);
        a{i}{j}.I[east].write_response_channel(b[I][l_r][{i}][{j}]);
        a{i}{j}.I[west].write_response_channel(b[I][l_r][{i}][{k}]);
        a{i}{j}.I[local].write_response_channel(b_local[I][{i}][{j}]);

        a{i}{j}.I[north].AWVALID(awvalid[I][u_d][{i}][{j}]);
        a{i}{j}.I[south].AWVALID(awvalid[I][u_d][{i}][{k}]);
        a{i}{j}.I[east].AWVALID(awvalid[I][l_r][{i}][{j}]);
        a{i}{j}.I[west].AWVALID(awvalid[I][l_r][{i}][{k}]);
        a{i}{j}.I[local].AWVALID(awvalid_local[I][{i}][{j}]);

        a{i}{j}.I[north].WVALID(wvalid[I][u_d][{i}][{j}]);
        a{i}{j}.I[south].WVALID(wvalid[I][u_d][{i}][{k}]);
        a{i}{j}.I[east].WVALID(wvalid[I][l_r][{i}][{j}]);
        a{i}{j}.I[west].WVALID(wvalid[I][l_r][{i}][{k}]);
        a{i}{j}.I[local].WVALID(wvalid_local[I][{i}][{j}]);

        a{i}{j}.I[north].BVALID(bvalid[I][u_d][{i}][{j}]);
        a{i}{j}.I[south].BVALID(bvalid[I][u_d][{i}][{k}]);
        a{i}{j}.I[east].BVALID(bvalid[I][l_r][{i}][{j}]);
        a{i}{j}.I[west].BVALID(bvalid[I][l_r][{i}][{k}]);
        a{i}{j}.I[local].BVALID(bvalid_local[I][{i}][{j}]);

        a{i}{j}.I[north].AWREADY(awready[I][u_d][{i}][{j}]);
        a{i}{j}.I[south].AWREADY(awready[I][u_d][{i}][{k}]);
        a{i}{j}.I[east].AWREADY(awready[I][l_r][{i}][{j}]);
        a{i}{j}.I[west].AWREADY(awready[I][l_r][{i}][{k}]);
        a{i}{j}.I[local].AWREADY(awready_local[I][{i}][{j}]);

        a{i}{j}.I[north].WREADY(wready[I][u_d][{i}][{j}]);
        a{i}{j}.I[south].WREADY(wready[I][u_d][{i}][{k}]);
        a{i}{j}.I[east].WREADY(wready[I][l_r][{i}][{j}]);
        a{i}{j}.I[west].WREADY(wready[I][l_r][{i}][{k}]);
        a{i}{j}.I[local].WREADY(wready_local[I][{i}][{j}]);

        a{i}{j}.I[north].BREADY(bready[I][u_d][{i}][{j}]);
        a{i}{j}.I[south].BREADY(bready[I][u_d][{i}][{k}]);
        a{i}{j}.I[east].BREADY(bready[I][l_r][{i}][{j}]);
        a{i}{j}.I[west].BREADY(bready[I][l_r][{i}][{k}]);
        a{i}{j}.I[local].BREADY(bready_local[I][{i}][{j}]);

        //output
        
        a{i}{j}.O[north].write_address_channel(aw[O][u_d][{i}][{j}]);
        a{i}{j}.O[south].write_address_channel(aw[O][u_d][{i}][{k}]);
        a{i}{j}.O[east].write_address_channel(aw[O][l_r][{i}][{j}]);
        a{i}{j}.O[west].write_address_channel(aw[O][l_r][{i}][{k}]);
        a{i}{j}.O[local].write_address_channel(aw_local[O][{i}][{j}]);

        a{i}{j}.O[north].write_data_channel(w[O][u_d][{i}][{j}]);
        a{i}{j}.O[south].write_data_channel(w[O][u_d][{i}][{k}]);
        a{i}{j}.O[east].write_data_channel(w[O][l_r][{i}][{j}]);
        a{i}{j}.O[west].write_data_channel(w[O][l_r][{i}][{k}]);
        a{i}{j}.O[local].write_data_channel(w_local[O][{i}][{j}]);
        

        a{i}{j}.O[north].write_response_channel(b[O][u_d][{i}][{j}]);
        a{i}{j}.O[south].write_response_channel(b[O][u_d][{i}][{k}]);
        a{i}{j}.O[east].write_response_channel(b[O][l_r][{i}][{j}]);
        a{i}{j}.O[west].write_response_channel(b[O][l_r][{i}][{k}]);
        a{i}{j}.O[local].write_response_channel(b_local[O][{i}][{j}]);

        a{i}{j}.O[north].AWVALID(awvalid[O][u_d][{i}][{j}]);
        a{i}{j}.O[south].AWVALID(awvalid[O][u_d][{i}][{k}]);
        a{i}{j}.O[east].AWVALID(awvalid[O][l_r][{i}][{j}]);
        a{i}{j}.O[west].AWVALID(awvalid[O][l_r][{i}][{k}]);
        a{i}{j}.O[local].AWVALID(awvalid_local[O][{i}][{j}]);

        a{i}{j}.O[north].WVALID(wvalid[O][u_d][{i}][{j}]);
        a{i}{j}.O[south].WVALID(wvalid[O][u_d][{i}][{k}]);
        a{i}{j}.O[east].WVALID(wvalid[O][l_r][{i}][{j}]);
        a{i}{j}.O[west].WVALID(wvalid[O][l_r][{i}][{k}]);
        a{i}{j}.O[local].WVALID(wvalid_local[O][{i}][{j}]);

        a{i}{j}.O[north].BVALID(bvalid[O][u_d][{i}][{j}]);
        a{i}{j}.O[south].BVALID(bvalid[O][u_d][{i}][{k}]);
        a{i}{j}.O[east].BVALID(bvalid[O][l_r][{i}][{j}]);
        a{i}{j}.O[west].BVALID(bvalid[O][l_r][{i}][{k}]);
        a{i}{j}.O[local].BVALID(bvalid_local[O][{i}][{j}]);

        a{i}{j}.O[north].AWREADY(awready[O][u_d][{i}][{j}]);
        a{i}{j}.O[south].AWREADY(awready[O][u_d][{i}][{k}]);
        a{i}{j}.O[east].AWREADY(awready[O][l_r][{i}][{j}]);
        a{i}{j}.O[west].AWREADY(awready[O][l_r][{i}][{k}]);
        a{i}{j}.O[local].AWREADY(awready_local[O][{i}][{j}]);

        a{i}{j}.O[north].WREADY(wready[O][u_d][{i}][{j}]);
        a{i}{j}.O[south].WREADY(wready[O][u_d][{i}][{k}]);
        a{i}{j}.O[east].WREADY(wready[O][l_r][{i}][{j}]);
        a{i}{j}.O[west].WREADY(wready[O][l_r][{i}][{k}]);
        a{i}{j}.O[local].WREADY(wready_local[O][{i}][{j}]);

        a{i}{j}.O[north].BREADY(bready[O][u_d][{i}][{j}]);
        a{i}{j}.O[south].BREADY(bready[O][u_d][{i}][{k}]);
        a{i}{j}.O[east].BREADY(bready[O][l_r][{i}][{j}]);
        a{i}{j}.O[west].BREADY(bready[O][l_r][{i}][{k}]);
        a{i}{j}.O[local].BREADY(bready_local[O][{i}][{j}]);

'''

for i in range(int(x)):
    for j in range(int(y)):
        k = str(j+1)
        file.write(str2write.format(i=str(i),j=str(j),k=k))    

str2write = '''  

        return;
    }
    SC_CTOR(Routing)
    {
        routing();
    }
};
'''
file.write(str2write)

file.close()
