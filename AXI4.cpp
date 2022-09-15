#include "AXI4.h"

AXI4_Stream_package AXI4_Stream_package::operator =(const AXI4_Stream_package &x)
{
    AXI4_Stream_package cache(0);
    cache.TDATA = x.TDATA;
    cache.TSTRB = x.TSTRB;
    cache.TKEEP = x.TKEEP;
    cache.TLAST = x.TLAST;
    cache.TID = x.TID;
    cache.TDEST = x.TDEST;
    //cache.TUSER = x.TUSER;
    return cache;
}

AXI4_Stream_protocol AXI4_Stream_protocol::operator =(const AXI4_Stream_protocol &x)
{
    AXI4_Stream_protocol cache(0);
    cache.ACLK = x.ACLK;
    cache.ARESETn = x.ARESETn;
    cache.TVALID = x.TVALID;
    cache.TREADY = x.TREADY;
    cache.package = x.package;
    return cache;
}

void AXI4_Stream_package::show()
{
    cout << "TDATA : " << this->TDATA << endl;
    cout << "TSTRB : " << this->TSTRB << endl;
    cout << "TKEEP : " << this->TKEEP << endl;
    cout << "TLAST :" << this->TLAST << endl;
    cout << "TID : " << this->TID << endl;
    cout << "TDEST : " << this->TDEST << endl;
}

void AXI4_Stream_protocol::show()
{
    this->package->show();
    cout << "ACLK : " << this->ACLK << endl;
    cout << "TVALID : " << this->TVALID << endl;
    cout << "TREADY : " << this->TREADY << endl;
}

AXI4_Stream_package::AXI4_Stream_package(bool x)
{
    if(x)
    {
        TDATA = 511;
        TSTRB = 1;
        TKEEP  = 1;
        TLAST = 1;
        TID = 131071;
        TDEST = 131071;
    }
    else
    {
        TDATA = 0;
        TSTRB = 0;
        TKEEP  = 0;
        TLAST = 0;
        TID = 0;
        TDEST = 0;
    }
    
}


AXI4_Stream_protocol::AXI4_Stream_protocol(bool x)
{
    if(x)
    {
        ACLK = 1;
        ARESETn = 1;
        TVALID = 1;
        TREADY = 1;
        package = new AXI4_Stream_package(1);
    }
    else
    {
        ACLK = 0;
        ARESETn = 0;
        TVALID = 0;
        TREADY = 0;
        package = new AXI4_Stream_package(0);
    }
}

