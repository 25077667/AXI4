#include "NI/network_interface.h"
#include "Router/router.h"
#include "Router/routing.cpp"
int sc_main(int argc, char *argv[])
{
    sc_clock clock("My_CLOCK", 10, 5, 0, 1);
    Routing test("test");
    test.clock(clock);
    sc_start(100, SC_NS);
    return 0;
}
