#include "router.h"

void Router::pop()
{
    for(int i = 0 ; i < 5 ; i++)
    {
        io[i].out = buf[i].obuf.back();
        buf->obuf.pop();
    }
}

void Router::push()
{
    for(int i = 0 ; i < POS_NUM ; i++)
    {
        if(!full(buf[i].ibuf))
            buf[i].ibuf.push(io[i].in.package);
    }
}

void Router::route()
{
    AXI4_Stream_package cache(0);
    //input buffer pop back and push to the right output buffer
    for(int i = 0 ; i < POS_NUM ; i++)
    {
        if(!buf[i].ibuf.empty())
        {
            cache = buf[i].ibuf.back();
            buf[i].ibuf.pop();
            position p = find_position(cache.TDEST,now);
            if(!full(buf[p].obuf))
                buf[p].obuf.push(cache);
            else
                local_buf.push(cache);
        }
    }
    if(!local_buf.empty())
    {
        cache = local_buf.back();
        position p = find_position(cache.TDEST,now);
        if(!full(buf[p].obuf))
        {
            buf[p].obuf.push(cache);
            local_buf.pop();
        }   
    }
        
}

position find_position(unsigned t,Point n)
{
    Point pt(t/4,t%4);
    pt.x -= n.x;
    pt.y -= n.y;
    if(pt.x < 0)    //xy routing , x first than y
        return position::W;
    else if(pt.x > 0)
        return position::E;
    else if(pt.y == 0)  //x=0 and y=0
        return position::L;
    else if(pt.y < 0)
        return position::S;
    else
        return position::N;

}