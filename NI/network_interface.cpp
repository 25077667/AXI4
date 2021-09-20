#include "network_interface.h"

Write_Addr::Write_Addr(sc_uint<4> awid,sc_uint<32> awaddr,sc_uint<4>awlen,sc_uint<3>awsize,sc_uint<2>awburst,sc_uint<2>awlock,sc_uint<4>awcache,sc_uint<3>awport)
{
    data = awid;
    data <<= 32;
    data += awaddr;
    data <<= 4;
    data += awlen;
    data <<= 3;
    data += awsize;
    data <<= 2;
    data += awburst;
    data <<= 2;
    data += awlock;
    data <<= 4;
    data += awcache;
    data <<= 3;
    data += awport;
}

Write_Data::Write_Data(sc_uint<4> wid,sc_uint<32> wdata,sc_uint<4> wstrb,sc_uint<1> wlast)
{
    data = wid;
    data <<= 32;
    data += wdata;
    data <<= 4;
    data += wstrb;
    data <<= 1;
    data += wlast;
}

Write_Responce::Write_Responce(sc_uint<4> bid,sc_uint<2> bresp)
{
    data = bid;
    data <<= 2;
    data += bresp;
}

/*Read_Addr::Read_Addr(sc_uint<4> arid,sc_uint<32> araddr,sc_uint<4>arlen,sc_uint<3>arsize,sc_uint<2>arburst,sc_uint<2>arlock,sc_uint<4>arcache,sc_uint<3>arport)
{
    data = arid;
    data <<= 32;
    data += araddr;
    data <<= 4;
    data += arlen;
    data <<= 3;
    data += arsize;
    data <<= 2;
    data += arburst;
    data <<= 2;
    data += arlock;
    data <<= 4;
    data += arcache;
    data <<= 3;
    data += arport;
}

Read_Data::Read_Data(sc_uint<4> rid,sc_uint<32> rdata,sc_uint<4> rstrb,sc_uint<1> rlast)
{
    data = rid;
    data <<= 32;
    data += rdata;
    data <<= 4;
    data += rstrb;
    data <<= 1;
    data += rlast;
}

*/
