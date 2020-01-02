# WARNING: This makefile is configured for UNIX (Linux/MacOSX).
# 	To make it work on Windows, you have to replace the commands 
# 	in the %.o and $(MAIN_EXECUTABLE) targets.


MAIN_EXECUTABLE = main
CXX = g++
LD = g++
CXXFLAGS = -Wall -Wextra
OBJS = \
	main.o\
	sort.o

all: $(MAIN_EXECUTABLE)
.PHONY: all

$(MAIN_EXECUTABLE): $(OBJS) 
	$(LD) -o $@ *.o

%.o: %.cpp %.h
	$(CXX) -c $< -o $@ $(CXXFLAGS)

clean:
	rm *.o

distclean: clean
	rm main

.PHONY: clean distclean
