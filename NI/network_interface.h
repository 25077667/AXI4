#ifndef __NETWORK_INTERFACE_H__
#define __NETWORK_INTERFACE_H__

#include <iostream>
#include <list>
#include "../Base/Base.h"
using namespace std;

typedef unsigned char Byte;
typedef unsigned int Int;


class Base_package
{
    public:
        virtual sc_uint<54> get();
        package_type get_type() {return NULL_TYPE;}
        Base_package() {}        
};

class Write_Addr:public Base_package
{
    private:
        //define signals
        sc_uint<54> data;
    public:
        //define constructors
        sc_uint<54> get() {return data;}
        package_type get_type() {return AW;}
        Write_Addr(sc_uint<4> awid = 0,sc_uint<32> awaddr = 0,sc_uint<4>awlen = 0,sc_uint<3>awsize = 0,sc_uint<2>awburst = 0,sc_uint<2>awlock = 0,sc_uint<4>awcache = 0,sc_uint<3>awport = 0);
        friend bool operator !=(Write_Addr,Write_Addr);
        friend bool operator ==(Write_Addr,Write_Addr);
        friend ostream& operator <<(ostream &,Write_Addr);
};

class Write_Data:public Base_package
{
    private:
        //define signals
        sc_uint<41> data;
    public:
        //define constructors
        sc_uint<54> get() {return ((sc_uint<54>)data << 13);}
        package_type get_type() {return W;}
        Write_Data(sc_uint<4> wid = 0,sc_uint<32> wdata = 0,sc_uint<4> wstrb = 0,sc_uint<1> wlast = 0);
        friend bool operator !=(Write_Data,Write_Data);
        friend bool operator ==(Write_Data,Write_Data);
        friend ostream& operator <<(ostream &,Write_Data);
};

class Write_Responce:public Base_package
{
    private:
        //define signals
        sc_uint<6> data; 
    public:
        //define constructors
        sc_uint<54> get() {return ((sc_uint<54>)data << 48);}
        package_type get_type() {return B;}
        Write_Responce(sc_uint<4> bid = 0,sc_uint<2> bresp = 0);
        friend bool operator !=(Write_Responce,Write_Responce);
        friend bool operator ==(Write_Responce,Write_Responce);
        friend ostream& operator <<(ostream &,Write_Responce);
};


#endif