#include "../PE/pe.h"
#include "../NI/network_interface.h"


class Package_data
{
    public:
        //aw : address ; w : data , b : responece
        package_type type;
        int id;
        int data;
        bool is_last;
        Package_data(package_type t,int i,int d,bool l):type(t),id(i),data(d),is_last(l) {}
        Package_data() {}
};

class Pkg_pair
{
    public:
        list<Package_data> pkg_list;
        position pos;
        bool last;
    Pkg_pair() {last = false;}
};

Base_package& pack(package_type,int);
sc_uint<54> pack_addr(Package_data);
sc_uint<41> pack_data(Package_data);
sc_uint<6> pack_resp(Package_data);
Package_data unpack(package_type,sc_uint<54>);