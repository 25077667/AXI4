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

