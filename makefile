SOURCE = main
SYSTEMC_HOME = /usr/systemc
MY_SYSTEMC_HOME = /usr
ALL = *
all:
	g++ -I. -I$(MY_SYSTEMC_HOME)/include -L. -L$(MY_SYSTEMC_HOME)/lib-linux64 -o $(SOURCE) $(ALL).cpp -lsystemc -lm -DSC_INCLUDE_FX

ignore:
	g++ -w -I. -I$(MY_SYSTEMC_HOME)/include -L. -L$(MY_SYSTEMC_HOME)/lib-linux64 -o $(SOURCE) $(SOURCE).cpp NI/network_interface.cpp -lsystemc -lm -DSC_INCLUDE_FX
test_make:
	g++ -I. -I$(MY_SYSTEMC_HOME)/include -L. -L$(MY_SYSTEMC_HOME)/lib-linux64 -o $(SOURCE) $(SOURCE).cpp -lsystemc -lm -DSC_INCLUDE_FX
clean:
	rm $(SOURCE)
