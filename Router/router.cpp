#include "router.h"

void Router::input()
{

    if((I[north].write_address_channel.read() != i[north].write_addr.back()))
        i[north].write_addr.push(I[north].write_address_channel.read());
    if((bool)(I[north].WREADY.read()) && (bool)(I[north].WVALID.read()))
        i[north].write_data.push(I[north].write_data_channel.read());
    if(I[south].write_address_channel.read() != i[south].write_addr.back())
        i[south].write_addr.push(I[south].write_address_channel.read());
    if((bool)(I[south].WREADY.read()) && (bool)(I[south].WVALID.read()))    
        i[south].write_data.push(I[south].write_data_channel.read());

    if(I[east].write_address_channel.read() != i[east].write_addr.back());
        i[east].write_addr.push(I[east].write_address_channel.read());
    if((bool)(I[east].WREADY.read()) && (bool)(I[east].WVALID.read()))    
        i[east].write_data.push(I[east].write_data_channel.read());
    
    if(I[west].write_address_channel.read() != i[west].write_addr.back())
        i[west].write_addr.push(I[west].write_address_channel.read());
    if((bool)(I[west].WREADY.read()) && (bool)(I[west].WVALID.read()))
        i[west].write_data.push(I[west].write_data_channel.read());

    if(I[local].write_address_channel.read() != i[local].write_addr.back())
        i[local].write_addr.push(I[local].write_address_channel.read());
    if((bool)(I[local].WREADY.read()) && (bool)(I[local].WVALID.read()))        
        i[local].write_data.push(I[local].write_data_channel.read());
   
}

void Router::output()
{
    if(O[north].write_address_channel.read() != o[north].write_addr.front())
    {
        O[north].write_address_channel.write(o[north].write_addr.front());
        o[north].write_addr.pop();
    }
    if((bool)(O[north].WREADY.read()) && (bool)(O[north].WVALID.read()))
    {
        O[north].write_data_channel.write(o[north].write_data.front());
        o[north].write_data.pop();
    }
    
    if(O[south].write_address_channel.read() != o[south].write_addr.front())
    {
        O[south].write_address_channel.write(o[south].write_addr.front());
        o[south].write_addr.pop();
    }
    if((bool)(O[south].WREADY.read()) && (bool)(O[south].WVALID.read()))
    {
        O[south].write_data_channel.write(o[south].write_data.front());
        o[south].write_data.pop();
    }
    

    if(O[east].write_address_channel.read() != o[east].write_addr.front())
    {
        O[east].write_address_channel.write(o[east].write_addr.front());
        o[east].write_addr.pop();
    }
    if((bool)(O[east].WREADY.read()) && (bool)(O[east].WVALID.read()))
    {
        O[east].write_data_channel.write(o[east].write_data.front());
        o[east].write_data.pop();
    }
    

    if(O[west].write_address_channel.read() != o[west].write_addr.front())
    {
        O[west].write_address_channel.write(o[west].write_addr.front());
        o[west].write_addr.pop();
    }
    if((bool)(O[west].WREADY.read()) && (bool)(O[west].WVALID.read()))
    {
        O[west].write_data_channel.write(o[west].write_data.front());
        o[west].write_data.pop();
    }
    

    if(O[local].write_address_channel.read() != o[local].write_addr.front())
    {
        O[local].write_address_channel.write(o[local].write_addr.front());
        o[local].write_addr.pop();
    }
    if((bool)(O[local].WREADY.read()) && (bool)(O[local].WVALID.read()))
    {
        O[local].write_data_channel.write(o[local].write_data.front());
        o[local].write_data.pop();
    }
}

void Router::ready()
{
    for(int j = 0 ; j < AXI_NUM_PER_ROUTER ; j++)
    {
        if(i[j].write_addr.size() < MAX_ADDR_SIZE)
            I[j].AWREADY = true;
        if(i[j].write_data.size() < MAX_DATA_SIZE)
            I[j].AWREADY = true;
    }
}

void Router::valid()
{
    for(int j = 0 ; j < AXI_NUM_PER_ROUTER ; j++)
    {
        if(o[j].write_addr.size() < MAX_ADDR_SIZE)
            I[j].AWVALID = true;
        else
            I[j].AWVALID = false;
    
        if(o[j].write_data.size() < MAX_DATA_SIZE)
            I[j].WVALID = true;
        else
            I[j].WVALID = false;
    }
}

void Router::rout(sc_uint<54> x,package_type t)
{
    Package_data cache = unpack(t,x); 
    if(register_table.find(cache.id) == register_table.end())
    {
        if(t == AW)
        {
            if((int)(this->name()[0])-48 < cache.data/16 )
                register_table[cache.id].pos = north;
            else if((int)(this->name()[0])-48 > cache.data/16)
                register_table[cache.id].pos = south;
            else
            {
                if((int)(this->name()[1])-48 < cache.data%16 )
                    register_table[cache.id].pos = west;
                else if((int)(this->name()[1])-48 > cache.data%16)
                    register_table[cache.id].pos = east;
                else
                    register_table[cache.id].pos = local;
            }
        }
        register_table[cache.id].pkg_list.push_back(cache);
    }
    else
        register_table[cache.id].pkg_list.push_back(cache);
    if(t == W)
        register_table[cache.id].last = cache.is_last;
}

void Router::f()
{
    this->valid();
    this->ready();
    this->input();
    sc_uint<54> cache_AW;
    sc_uint<41> cache_W;
    sc_uint<6> cache_B;
    for(int j = 0 ; j < AXI_NUM_PER_ROUTER ; j++)
    {
        if(!(i[j].write_addr.empty()))
        {
            cache_AW = i[j].write_addr.front();
            i[j].write_addr.pop();
            rout(cache_AW,AW);
        }
        if(!(i[j].write_data.empty()))
        {
            cache_W = i[j].write_data.front();
            i[j].write_data.pop();
            rout(cache_W,W);
        }
        if(!(i[j].write_data.empty()))
        {
            cache_W = i[j].write_data.front();
            i[j].write_data.pop();
            rout(cache_B,B);
        }  
    }
    this->push_out();
    this->output();
    return;
}

void Router::push_out()
{
    auto p = register_table.begin();

    if(p != register_table.end())
    {
        if(p->second.last)
        {
            if(p->second.pkg_list.front().type == AW)
            {
                if(o[p->second.pos].write_addr.size() < MAX_ADDR_SIZE)
                {
                    o[p->second.pos].write_addr.push(pack_addr(p->second.pkg_list.front()));
                    p->second.pkg_list.pop_front();
                }
            }
            for(auto q = p->second.pkg_list.begin() ; q != p->second.pkg_list.end() ; q++)
            {
                if(o[p->second.pos].write_data.size() < MAX_DATA_SIZE)
                {
                    o[p->second.pos].write_data.push(pack_data(p->second.pkg_list.front()));
                    p->second.pkg_list.pop_front();
                }
                else
                    break;
            }
            if(p->second.pkg_list.empty())
                register_table.erase(p);
        }
    }
}