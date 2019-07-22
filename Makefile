SRCDIR = Maria/src
OBJDIR = Maria/obj

SRCFILES = $(wildcard $(SRCDIR)/*.cpp)
x = $(SRCFILES:.cpp=.o)
OBJFILES = $(subst $(SRCDIR)/,$(OBJDIR)/,$(x))

CFLAGS = -fconcepts -std=c++2a -g -Wall -pedantic
LDFLAGS = $(shell pkg-config --libs sfml-all)

Maria: $(OBJFILES)
	$(CXX) -o $(OBJDIR)/$@ $^ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) -c -o $@ $^ $(CFLAGS)

.PHONY: clean
clean:
	rm -f $(OBJFILES) Maria
