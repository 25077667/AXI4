#ifndef __NETWORK_INTERFACE_H__
#define __NETWORK_INTERFACE_H__

typedef unsigned char Byte;

typedef struct package_write_addr
{
    Byte AWID : 4;
    Byte AWDDR : 32;
    Byte AWLEN : 4;
    Byte AWSIZE : 3;
    Byte AWBURST : 2;
    Byte AWLOCK : 2;
    Byte AWCACHE : 4;
    Byte AWPORT : 3;
}Write_Addr;

typedef struct package_write_data
{
    Byte WID : 4;
    Byte WDATA : 32;
    Byte WSTRB : 4;
    Byte WLAST : 1;
}Write_Data;

typedef struct package_write_responce
{
    Byte BID : 4;
    Byte BRESP : 2;
}Write_Responce;

#endif