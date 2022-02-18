CXX = g++
CXXFLAGS = -g -Wall

SRCS = array.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.hpp)

all: main

main: $(OBJS) main.o
	$(CXX) $(CXXFLAGS) $^ -o $@

run:
	./main

clean:
	rm -f main *.o

$(OBJS): $(DEPS)

.o.cpp:
	$(CXX) -c $(CXXFLAGS) $<
