//#include "router.h"
#include <systemc.h>
#include "NI/network_interface.h"
int sc_main(int argc , char *argv[])
{   
    /*sc_signal<sc_bv<32>,SC_MANY_WRITERS > b1,b2,b3,b4,b5,b6;
    Router a("00");
    a.channel_north(b1);
    a.channel_south(b2);
    a.channel_east(b3);
    a.channel_west(b4);
    a.channel_local(b5);
    Router b("01");
    b.channel_north(b1);
    b.channel_south(b2);
    b.channel_east(b6);
    b.channel_west(b3);
    b.channel_local(b5);
    sc_start();
    a.set_position(0,0);
    b.set_position(0,1);
    b4.write("11111111111111111111111111111111");
    sc_start();
    cout << b6.read() << endl;*/
    //b.print();
        
    Write_Addr test = Write_Addr((Byte)3,(Int)12);
    cout << test << endl;
    return 0;
}
