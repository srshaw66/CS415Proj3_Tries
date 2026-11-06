CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

a.out: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp $(wildcard *.hpp)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) a.out

.PHONY: clean
