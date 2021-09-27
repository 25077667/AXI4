#include "../PE/pe.h"
#include "../NI/network_interface.h"


class Package_data
{
    public:
        //aw : address ; w : data , b : responece
        package_type type;
        int id;
        int data;
        Package_data(package_type t,int i,int d):type(t),id(i),data(d) {}
        Package_data() {}
};

Base_package& pack(package_type,int);
Package_data unpack(package_type,Base_package &);