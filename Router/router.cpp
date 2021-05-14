#include "router.h"

void Router::input()
{

    if(N_I.write_address_channel.read() != buf_ni.write_addr.back())
        buf_ni.write_addr.push(N_I.write_address_channel.read());
    if((bool)(N_I.WREADY.read()) && (bool)(N_I.WVALID.read()))
        buf_ni.write_data.push(N_I.write_data_channel.read());
    if(S_I.write_address_channel.read() != buf_si.write_addr.back())
        buf_si.write_addr.push(S_I.write_address_channel.read());
    if((bool)(S_I.WREADY.read()) && (bool)(S_I.WVALID.read()))    
        buf_si.write_data.push(S_I.write_data_channel.read());

    if(E_I.write_address_channel.read() != buf_ei.write_addr.back());
        buf_ei.write_addr.push(E_I.write_address_channel.read());
    if((bool)(E_I.WREADY.read()) && (bool)(E_I.WVALID.read()))    
        buf_ei.write_data.push(E_I.write_data_channel.read());
    
    if(W_I.write_address_channel.read() != buf_wi.write_addr.back())
        buf_wi.write_addr.push(W_I.write_address_channel.read());
    if((bool)(W_I.WREADY.read()) && (bool)(W_I.WVALID.read()))
        buf_wi.write_data.push(W_I.write_data_channel.read());

    if(L_I.write_address_channel.read() != buf_li.write_addr.back())
        buf_li.write_addr.push(L_I.write_address_channel.read());
    if((bool)(L_I.WREADY.read()) && (bool)(L_I.WVALID.read()))        
        buf_li.write_data.push(L_I.write_data_channel.read());
   
}

void Router::output()
{
    if(N_O.write_address_channel.read() != buf_no.write_addr.front())
    {
        N_O.write_address_channel.write(buf_no.write_addr.front());
        buf_no.write_addr.pop();
    }
    if((bool)(N_O.WREADY.read()) && (bool)(N_O.WVALID.read()))
    {
        N_O.write_data_channel.write(buf_no.write_data.front());
        buf_no.write_data.pop();
    }
    
    if(S_O.write_address_channel.read() != buf_so.write_addr.front())
    {
        S_O.write_address_channel.write(buf_so.write_addr.front());
        buf_so.write_addr.pop();
    }
    if((bool)(S_O.WREADY.read()) && (bool)(S_O.WVALID.read()))
    {
        S_O.write_data_channel.write(buf_so.write_data.front());
        buf_so.write_data.pop();
    }
    

    if(E_O.write_address_channel.read() != buf_eo.write_addr.front())
    {
        E_O.write_address_channel.write(buf_eo.write_addr.front());
        buf_eo.write_addr.pop();
    }
    if((bool)(E_O.WREADY.read()) && (bool)(E_O.WVALID.read()))
    {
        E_O.write_data_channel.write(buf_eo.write_data.front());
        buf_eo.write_data.pop();
    }
    

    if(W_O.write_address_channel.read() != buf_wo.write_addr.front())
    {
        W_O.write_address_channel.write(buf_wo.write_addr.front());
        buf_wo.write_addr.pop();
    }
    if((bool)(W_O.WREADY.read()) && (bool)(W_O.WVALID.read()))
    {
        W_O.write_data_channel.write(buf_wo.write_data.front());
        buf_wo.write_data.pop();
    }
    

    if(L_O.write_address_channel.read() != buf_lo.write_addr.front())
    {
        L_O.write_address_channel.write(buf_lo.write_addr.front());
        buf_lo.write_addr.pop();
    }
    if((bool)(L_O.WREADY.read()) && (bool)(L_O.WVALID.read()))
    {
        L_O.write_data_channel.write(buf_lo.write_data.front());
        buf_lo.write_data.pop();
    }
}

