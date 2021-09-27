#include "router.h"

void Router::input()
{

    if(I[position::north].write_address_channel.read() != i[position::north].write_addr.back())
        i[position::north].write_addr.push(I[position::north].write_address_channel.read());
    if((bool)(I[position::north].WREADY.read()) && (bool)(I[position::north].WVALID.read()))
        i[position::north].write_data.push(I[position::north].write_data_channel.read());
    if(I[position::south].write_address_channel.read() != i[position::south].write_addr.back())
        i[position::south].write_addr.push(I[position::south].write_address_channel.read());
    if((bool)(I[position::south].WREADY.read()) && (bool)(I[position::south].WVALID.read()))    
        i[position::south].write_data.push(I[position::south].write_data_channel.read());

    if(I[position::east].write_address_channel.read() != i[position::east].write_addr.back());
        i[position::east].write_addr.push(I[position::east].write_address_channel.read());
    if((bool)(I[position::east].WREADY.read()) && (bool)(I[position::east].WVALID.read()))    
        i[position::east].write_data.push(I[position::east].write_data_channel.read());
    
    if(I[position::west].write_address_channel.read() != i[position::west].write_addr.back())
        i[position::west].write_addr.push(I[position::west].write_address_channel.read());
    if((bool)(I[position::west].WREADY.read()) && (bool)(I[position::west].WVALID.read()))
        i[position::west].write_data.push(I[position::west].write_data_channel.read());

    if(I[position::local].write_address_channel.read() != i[position::local].write_addr.back())
        i[position::local].write_addr.push(I[position::local].write_address_channel.read());
    if((bool)(I[position::local].WREADY.read()) && (bool)(I[position::local].WVALID.read()))        
        i[position::local].write_data.push(I[position::local].write_data_channel.read());
   
}

void Router::output()
{
    if(O[position::north].write_address_channel.read() != o[position::north].write_addr.front())
    {
        O[position::north].write_address_channel.write(o[position::north].write_addr.front());
        o[position::north].write_addr.pop();
    }
    if((bool)(O[position::north].WREADY.read()) && (bool)(O[position::north].WVALID.read()))
    {
        O[position::north].write_data_channel.write(o[position::north].write_data.front());
        o[position::north].write_data.pop();
    }
    
    if(O[position::south].write_address_channel.read() != o[position::south].write_addr.front())
    {
        O[position::south].write_address_channel.write(o[position::south].write_addr.front());
        o[position::south].write_addr.pop();
    }
    if((bool)(O[position::south].WREADY.read()) && (bool)(O[position::south].WVALID.read()))
    {
        O[position::south].write_data_channel.write(o[position::south].write_data.front());
        o[position::south].write_data.pop();
    }
    

    if(O[position::east].write_address_channel.read() != o[position::east].write_addr.front())
    {
        O[position::east].write_address_channel.write(o[position::east].write_addr.front());
        o[position::east].write_addr.pop();
    }
    if((bool)(O[position::east].WREADY.read()) && (bool)(O[position::east].WVALID.read()))
    {
        O[position::east].write_data_channel.write(o[position::east].write_data.front());
        o[position::east].write_data.pop();
    }
    

    if(O[position::west].write_address_channel.read() != o[position::west].write_addr.front())
    {
        O[position::west].write_address_channel.write(o[position::west].write_addr.front());
        o[position::west].write_addr.pop();
    }
    if((bool)(O[position::west].WREADY.read()) && (bool)(O[position::west].WVALID.read()))
    {
        O[position::west].write_data_channel.write(o[position::west].write_data.front());
        o[position::west].write_data.pop();
    }
    

    if(O[position::local].write_address_channel.read() != o[position::local].write_addr.front())
    {
        O[position::local].write_address_channel.write(o[position::local].write_addr.front());
        o[position::local].write_addr.pop();
    }
    if((bool)(O[position::local].WREADY.read()) && (bool)(O[position::local].WVALID.read()))
    {
        O[position::local].write_data_channel.write(o[position::local].write_data.front());
        o[position::local].write_data.pop();
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
        if(o[j].write_data.size() < MAX_DATA_SIZE)
            I[j].AWVALID = true;
    }
}

void Router::rout(Base_package &x,package_type t)
{
    Package_data cache = unpack(t,x); 
    if(register_table.find(cache.id) == register_table.end())
    {
        if(t == AW)
        {
            if((int)(this->name()[0])-48 < cache.data/16 )
                register_table[cache.id] = north;
            else if((int)(this->name()[0])-48 > cache.data/16)
                register_table[cache.id] = south;
            else
            {
                if((int)(this->name()[1])-48 < cache.data%16 )
                    register_table[cache.id] = west;
                else if((int)(this->name()[1])-48 > cache.data%16)
                    register_table[cache.id] = east;
                else
                    register_table[cache.id] = local;
            }
        }
    }
}

void Router::f()
{
    Write_Addr cache_AW;
    Write_Data cache_W;
    Write_Responce cache_B;
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
}