#ifndef __AXI4_H__
#define __AXI4_H__

#define DATA_SIZE 1
#define MAX_BUFFER_SIZE 3

#include <queue>
#include "systemc.h"
using namespace std;

enum position
{
    N,E,S,W,L
};

class AXI4_Stream_package
{
    public:
        unsigned TDATA : 8*DATA_SIZE;
        unsigned TSTRB : DATA_SIZE;
        unsigned TKEEP : DATA_SIZE;
        unsigned TLAST : 1;
        unsigned TID : 16;           //同時能有16個封包在4*4 mesh上
        unsigned TDEST : 16;         //4*4 mesh
        //unsigned TUSER : 16;       //還不知道要多大
        AXI4_Stream_package operator =(const AXI4_Stream_package&);        
        void show();                 //for debugging
        AXI4_Stream_package(bool);
};

class AXI4_Stream_protocol
{
    public:
        unsigned ACLK : 1;
        unsigned ARESETn : 1;
        unsigned TVALID : 1;
        unsigned TREADY : 1;
        AXI4_Stream_package *package;
        AXI4_Stream_protocol operator =(const AXI4_Stream_protocol&);
        AXI4_Stream_protocol operator =(const AXI4_Stream_package&);
        void show();                //for debugging
        AXI4_Stream_protocol(bool);
        ~AXI4_Stream_protocol() {delete package;}
};

class IO_Port
{
    public:
        AXI4_Stream_protocol in;
        AXI4_Stream_protocol out;
};

class Buffer
{
    public:
        queue<AXI4_Stream_package> ibuf,obuf;
};

bool full(queue<AXI4_Stream_package> x) { return (x.size() >= MAX_BUFFER_SIZE); }   //when push in to buffer , check if buffer is full

#endif