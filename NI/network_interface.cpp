#include "network_interface.h"

Write_Addr::Write_Addr(Byte awid,Int awaddr,Byte awlen,Byte awsize,Byte awburst,Byte awlock,Byte awcache,Byte awport)
{
    AWID = awid;
    AWADDR = awaddr;
    AWLEN = awlen;
    AWSIZE = awsize;
    AWLOCK = awlock;
    AWCACHE = awcache;
    AWPORT = awport;   
}

ostream& operator << (ostream& s, Write_Addr x)
{
    s << "AWID\t=\t" << (int)x.AWID << endl;
    s << "AWADDR\t=\t" << x.AWADDR << endl;
    s << "AWLEN\t=\t" << (int)x.AWLEN << endl;
    s << "AWLOCK\t=\t" << (int)x.AWLOCK << endl;
    s << "AWCACHE\t=\t" << (int)x.AWCACHE << endl;
    s << "AWPROT\t=\t" << (int)x.AWPORT;
    return s;
}