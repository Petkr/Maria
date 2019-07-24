SRCDIR = src
OBJDIR = obj
DEPDIR = dep

DISTFILE = Maria.out
SRCFILES = $(wildcard $(SRCDIR)/*.cpp)
OBJFILES = $(subst $(SRCDIR)/,$(OBJDIR)/,$(SRCFILES:.cpp=.o))
DEPFILES = $(subst $(SRCDIR)/,$(DEPDIR)/,$(SRCFILES:.cpp=.d))

INCFLAGS = -IPapo/src
CXXFLAGS = -fconcepts -std=c++2a -g -Wall -pedantic
LDFLAGS = $(shell pkg-config --libs sfml-all)

$(DISTFILE): $(OBJFILES)
	$(CXX) -o $@ $^ $(LDFLAGS)

$(DEPDIR)/%.d: $(SRCDIR)/%.cpp
	mkdir -p $(DEPDIR)
	$(CXX) -MM $^ -MT $(OBJDIR)/$*.o -MF $@ $(INCFLAGS)

$(OBJDIR)/%.o: $(DEPDIR)/%.d

include $(DEPFILES)

$(OBJDIR)/%.o:
	mkdir -p $(OBJDIR)
	$(CXX) -c $< -o $@ $(CXXFLAGS) $(INCFLAGS)

.PHONY: clean
clean:
	$(RM) $(OBJFILES) $(DEPFILES) $(DISTFILE)
