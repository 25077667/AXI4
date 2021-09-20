#include "../PE/pe.h"
#include "../NI/network_interface.h"


class Package_data
{
    public:
        package_type type;
        int id;
        //aw : address ; w : data , b : responece
        int data;
        Package_data(package_type t,int i,int d):type(t),id(i),data(d) {}
};

Base_package& pack(package_type,int);
Package_data unpack(package_type,Base_package &);