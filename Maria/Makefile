SRCDIR = src

SRCFILES = $(wildcard $(SRCDIR)/*.cpp)
OBJFILES = $(SRCFILES:.cpp=.o)

CFLAGS = -fconcepts -std=c++2a -g -Wall -pedantic
LDFLAGS = $(shell pkg-config --libs sfml-all)

Maria: $(OBJFILES)
	$(CXX) -o $@ $^ $(LDFLAGS)

$(SRCDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) -c -o $@ $^ $(CFLAGS)

.PHONY: clean
clean:
	rm -f $(OBJFILES) Maria
