#include <systemc.h>

int sc_main(int argc,char* argv[])
{
    sc_uint<4> a;
    a = 1;
    a <<= 1;
    a += 1;
    a <<= 2;
    a +=1;
    for(int i = 0 ; i < 4 ; i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;
    std::cout << a << endl;

    sc_uint<4> b = 7;
    for(int i = 0 ; i < 4 ; i++)
        std::cout << b[i] << " ";
    std::cout << std::endl;
    std::cout << b << endl;

    return 0;
}