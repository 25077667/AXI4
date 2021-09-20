#include <systemc.h>

SC_MODULE(Gen)
{
    sc_in_clk clock;
    sc_inout<bool> out;
    void buf()
    {
        out = true;
    }
    SC_CTOR(Gen)
    {
        SC_METHOD(buf);
        sensitive << clock.pos();
    }
};

SC_MODULE(Test)
{
    sc_in_clk clock;
    sc_inout<bool > VALID , READY;
    void f() {VALID.write(READY.read()); cout << VALID.read() << endl;}
    SC_CTOR(Test)
    {
        SC_METHOD(f);
        sensitive << clock.neg();
    }
};

SC_MODULE(Buf)
{
    sc_in_clk clock;
    sc_inout<bool> in,out;
    void f() {out.write(in.read());}
    SC_CTOR(Buf)
    {
        SC_METHOD(f);
        sensitive << clock.neg();
    } 
};

int sc_main(int argc , char *argv[])
{   
    sc_clock clock("My_CLOCK",10,5,0,1);
    sc_signal<bool,SC_MANY_WRITERS> a,b,c;
    Gen always1("always true");
    
    Test test("test");
        
        

        always1.clock(clock);
        always1.out(test.READY);

        test.clock(clock);
        test.VALID(c);
        test.READY(always1.out);
    sc_start(100,SC_NS);
    cout << "c=" << c << endl;
    return 0;
}
