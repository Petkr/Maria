src = $(wildcard src/*.cpp)
obj = $(src:.cpp=.o)

LDFLAGS = $(pkg-config --libs sfml-all)

Maria: $(obj)
	$(CXX) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(obj) Maria
