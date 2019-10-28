CXXFLAGS += -std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: mainwin

mainwin: main.cpp mainwin.cpp *h
	$(CXX) $(CXXFLAGS) main.cpp mainwin.cpp $(GTKFLAGS) -o mainwin
clean:
	rm -f *.o *.gch mainwin


