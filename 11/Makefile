# WARNING: This makefile is configured for UNIX (Linux/MacOSX).
# 	To make it work on Windows, you have to replace the commands 
# 	in the %.o and $(MAIN_EXECUTABLE) targets (with cl and link), 
#	and change the clean target's command to use `del`.


MAIN_EXECUTABLE = main
CXX = clang++
LD = clang++
CXXFLAGS = -Wall -Wextra -g
OBJS = \
	main.o\
	sort.o

all: $(MAIN_EXECUTABLE)
.PHONY: all

$(MAIN_EXECUTABLE): $(OBJS) 
	$(LD) -o $@ $^

%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS) 

clean:
	rm -f *.o

distclean: clean
	rm -f $(MAIN_EXECUTABLE)

.PHONY: clean distclean
