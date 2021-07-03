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
    private:
        Byte WID : 4;
        Int WDATA : 32;
        Byte WSTRB : 4;
        Byte WLAST : 1;
    public:
        Write_Data(Byte wid = 0,Int wdata = 0,Byte wstrb = 0,Byte wlast = 0);
        friend ostream& operator << (ostream&,Write_Data);
};

class Write_Responce
{
    Byte BID : 4;
    Byte BRESP : 2;
    Write_Responce(Byte bid = 0,Byte bresp = 0);
    friend ostream& operator << (ostream&,Write_Responce);
};

class Read_Addr
{
    private:
        //define signals
        Byte ARID : 4;
        Int ARADDR : 32;
        Byte ARLEN : 4;
        Byte ARSIZE : 3;
        Byte ARBURST : 2;
        Byte ARLOCK : 2;
        Byte ARCACHE : 4;
        Byte ARPORT : 3;
    public:
        //define constructors
        Read_Addr(Byte arid = 0,Int araddr = 0,Byte arlen = 0,Byte arsize = 0,Byte arburst = 0,Byte arlock = 0,Byte arcache = 0,Byte arport = 0);
        friend ostream& operator << (ostream&, Read_Addr);
};

class Read_Data
{
    private:
        Byte RID : 4;
        Int RDATA : 32;
        Byte RSTRB : 4;
        Byte RLAST : 1;
    public:
        Read_Data(Byte rid = 0,Int rdata = 0,Byte rstrb = 0,Byte rlast = 0);
        friend ostream& operator << (ostream&,Read_Data);
};

ostream& operator << (ostream&, Write_Addr);
ostream& operator << (ostream&, Write_Data);
ostream& operator << (ostream&, Write_Responce);
ostream& operator << (ostream&, Read_Addr);
ostream& operator << (ostream&, Read_Data);

#endif