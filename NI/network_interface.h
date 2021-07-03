#ifndef __NETWORK_INTERFACE_H__
#define __NETWORK_INTERFACE_H__

#include <iostream>
using namespace std;

typedef unsigned char Byte;
typedef unsigned int Int;

class Write_Addr
{
    private:
        //define signals
        Byte AWID : 4;
        Int AWADDR : 32;
        Byte AWLEN : 4;
        Byte AWSIZE : 3;
        Byte AWBURST : 2;
        Byte AWLOCK : 2;
        Byte AWCACHE : 4;
        Byte AWPORT : 3;
    public:
        //define constructors
        Write_Addr(Byte awid = 0,Int awaddr = 0,Byte awlen = 0,Byte awsize = 0,Byte awburst = 0,Byte awlock = 0,Byte awcache = 0,Byte awport = 0);
        friend ostream& operator << (ostream&, Write_Addr);
};

class Write_Data
{
    Byte WID : 4;
    Int WDATA : 32;
    Byte WSTRB : 4;
    Byte WLAST : 1;
};

class Write_Responce
{
    Byte BID : 4;
    Byte BRESP : 2;
};

ostream& operator << (ostream&, Write_Addr);

#endif