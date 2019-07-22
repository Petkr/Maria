SRCDIR = src

src = $(wildcard $(SRCDIR)/*.cpp)
obj = $(src:.cpp=.o)

CFLAGS = -fconcepts -std=c++2a -g -Wall -pedantic
LDFLAGS = $(shell pkg-config --libs sfml-all)

Maria: $(obj)
	$(CXX) -o $@ $^ $(LDFLAGS)

$(SRCDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) -c -o $@ $^ $(CFLAGS)

.PHONY: clean
clean:
	rm -f $(obj) Maria
