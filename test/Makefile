PROG = ../run_tests
SRCS = $(wildcard *.cpp)
LIBS = catch.h
OBJS = $(patsubst %.cpp,%.o,$(SRCS))
SRCOBJS = $(filter-out ../src/main.o, $(wildcard ../src/*.o)) $(wildcard ../src/*/*.o)
DEPFILES = $(patsubst %.cpp,%.d,$(SRCS))

CC = g++
CFLAGS = -Wall -g -O2 -I ../src -std=c++11  -lncurses

VPATH = ../src

all: $(PROG) $(OBJS)

-include $(DEPFILES)

%.d: %.cpp
	$(CXX) $(CFLAGS) -MM -MT '$(patsubst %.cpp,%.o,$<)' $< -MF $@

$(OBJS): %.o: %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

$(PROG): $(OBJS) $(SRCOBJS)
	$(CC) $(CFLAGS) $(OBJS) $(SRCOBJS) -o $(PROG) -lncurses

clean:
	rm -f run_tests $(OBJS)