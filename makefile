SOURCE = main
SYSTEMC_HOME = /usr/systemc
all:
	g++ -I. -I$(SYSTEMC_HOME)/include -L. -L$(SYSTEMC_HOME)/lib-linux64 -o $(SOURCE) $(SOURCE).cpp -lsystemc -lm -DSC_INCLUDE_FX

ignore:
	g++ -w -I. -I$(SYSTEMC_HOME)/include -L. -L$(SYSTEMC_HOME)/lib-linux64 -o $(SOURCE) $(SOURCE).cpp -lsystemc -lm -DSC_INCLUDE_FX
clean:
	rm $(SOURCE)
