PROG = ../elis
SRCS = $(filter-out main.cpp, $(wildcard *.cpp)) $(wildcard */*.cpp)
HDRS = $(wildcard *.h) $(wildcard */*.h)
OBJS = $(patsubst %.cpp,%.o,$(SRCS))
DEPFILES = $(patsubst %.cpp,%.d,$(SRCS))

CC = g++
CFLAGS = -Wall -g -O2 -I. -std=c++11


all: $(PROG) $(OBJS)

-include $(DEPFILES)

%.d: %.cpp
	$(CXX) $(CFLAGS) -MM -MT '$(patsubst %.cpp,%.o,$<)' $< -MF $@

$(OBJS): %.o: %.cpp $(SRCS) $(HDRS)
	$(CC) -c $(CFLAGS) $< -o $@

$(PROG): $(OBJS) main.cpp
	$(CC) $(CFLAGS) $(OBJS) main.cpp -o $(PROG) -lncurses 

clean:
	rm -f $(OBJS) $(PROG)