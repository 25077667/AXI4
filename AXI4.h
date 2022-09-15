#define DATA_SIZE 1
#define MAX_BUFFER_SIZE 3

class AXI4_Stream_protocol
{
    public:
        unsigned ACLK : 1;
        unsigned ARESETn : 1;
        unsigned TVALID : 1;
        unsigned TREADY : 1;
        AXI4_Stream_package package;
};

class AXI4_Stream_package
{
    public:
        unsigned TDATA : 8*DATA_SIZE;
        unsigned TSTRB : DATA_SIZE;
        unsigned TKEEP : DATA_SIZE;
        unsigned TLAST : 1;
        unsigned TID : 16           //同時能有16個封包在4*4 mesh上
        unsigned TDEST : 16         //4*4 mesh
        //unsigned TUSER : 16       //還不知道要多大
}

class IO_Port
{
    public:
        AXI4_Stream_protocol in;
        AXI4_Stream_protocol out;
};

class Buffer
{
    public:
        queue<AXI4_Stream_package> buf;
        bool full()
        {
            return (buf.size() >= MAX_BUFFER_SIZE) ? true : false;
        }
};
