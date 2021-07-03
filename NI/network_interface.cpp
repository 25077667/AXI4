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


Write_Data::Write_Data(Byte wid,Int wdata,Byte wstrb,Byte wlast)
{
    WID = wid;
    WDATA = wdata;
    WSTRB = wstrb;
    WLAST = wlast;
}

Write_Responce::Write_Responce(Byte bid,Byte bresp)
{
    BID = bid;
    BRESP = bresp;
}

Read_Addr::Read_Addr(Byte arid,Int araddr,Byte arlen,Byte arsize,Byte arburst,Byte arlock,Byte arcache,Byte arport)
{
    ARID = arid;
    ARADDR = araddr;
    ARLEN = arlen;
    ARSIZE = arsize;
    ARLOCK = arlock;
    ARCACHE = arcache;
    ARPORT = arport;   
}

Read_Data::Read_Data(Byte rid,Int rdata,Byte rstrb,Byte rlast)
{
    RID = rid;
    RDATA = rdata;
    RSTRB = rstrb;
    RLAST = rlast;
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

ostream& operator << (ostream& s, Write_Responce x)
{
    s << "BID\t=\t" << (int)x.BID << endl;
    s << "BRESP\t=\t" << (int)x.BRESP;
    return s;
}

ostream& operator << (ostream& s, Read_Data x)
{
    s << "RID\t=\t" << (int)x.RID << endl;
    s << "RDATA\t=\t" << x.RDATA << endl;
    s << "RSTRB\t=\t" << (int)x.RSTRB << endl;
    s << "RLAST\t=\t" << (int)x.RLAST;
    return s;
}

ostream& operator << (ostream& s, Read_Addr x)
{
    s << "ARID\t=\t" << (int)x.ARID << endl;
    s << "ARADDR\t=\t" << x.ARADDR << endl;
    s << "ARLEN\t=\t" << (int)x.ARLEN << endl;
    s << "ARLOCK\t=\t" << (int)x.ARLOCK << endl;
    s << "ARCACHE\t=\t" << (int)x.ARCACHE << endl;
    s << "ARPROT\t=\t" << (int)x.ARPORT;
    return s;
}

ostream& operator << (ostream& s, Write_Data x)
{
    s << "WID\t=\t" << (int)x.WID << endl;
    s << "WDATA\t=\t" << x.WDATA << endl;
    s << "WSTRB\t=\t" << (int)x.WSTRB << endl;
    s << "WLAST\t=\t" << (int)x.WLAST;
    return s;
}