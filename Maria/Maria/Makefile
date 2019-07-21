src = $(wildcard src/*.cpp)
obj = $(src:.cpp=.o)

CFLAGS = -fconcepts -std=c++2a -g -Wall -pedantic
LDFLAGS = $(shell pkg-config --libs sfml-all)

Maria: $(obj)
	$(CXX) -o $@ $^ $(CFLAGS) $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(obj) Maria
