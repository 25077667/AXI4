#include "router.h"

void Router::input()
{
    if(N_I.write_address_channel.read() != buf_ni.write_addr.back())
        buf_ni.write_addr.push(N_I.write_address_channel.read());
    buf_ni.write_data.push(N_I.write_data_channel.read());
    
    if(S_I.write_address_channel.read() != buf_si.write_addr.back())
        buf_si.write_addr.push(S_I.write_address_channel.read());
    buf_si.write_data.push(S_I.write_data_channel.read());

    if(E_I.write_address_channel.read() != buf_ei.write_addr.back());
        buf_ei.write_addr.push(E_I.write_address_channel.read());
    buf_ei.write_data.push(E_I.write_data_channel.read());
    
    if(W_I.write_address_channel.read() != buf_wi.write_addr.back())
        buf_wi.write_addr.push(W_I.write_address_channel.read());
    buf_wi.write_data.push(W_I.write_data_channel.read());

    if(L_I.write_address_channel.read() != buf_li.write_addr.back())
        buf_li.write_addr.push(L_I.write_address_channel.read());
    buf_li.write_data.push(L_I.write_data_channel.read());
   
}

void Router::output()
{
    N_O.write_address_channel.write(buf_no.write_addr.front());
    buf_no.write_addr.pop();
    N_O.write_data_channel.write(buf_no.write_data.front());
    buf_no.write_data.pop();

    S_O.write_address_channel.write(buf_so.write_addr.front());
    buf_so.write_addr.pop();
    S_O.write_data_channel.write(buf_so.write_data.front());
    buf_so.write_data.pop();

    E_O.write_address_channel.write(buf_eo.write_addr.front());
    buf_eo.write_addr.pop();
    E_O.write_data_channel.write(buf_eo.write_data.front());
    buf_eo.write_data.pop();

    W_O.write_address_channel.write(buf_wo.write_addr.front());
    buf_wo.write_addr.pop();
    W_O.write_data_channel.write(buf_wo.write_data.front());
    buf_wo.write_data.pop();

    L_O.write_address_channel.write(buf_lo.write_addr.front());
    buf_lo.write_addr.pop();
    L_O.write_data_channel.write(buf_lo.write_data.front());
    buf_lo.write_data.pop();
}

