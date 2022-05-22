BINARY=bin
CODEDIRS=. lib
INCDIRS=. ./include/

CC=g++ # clang++
VERSION=c++17
OPT=-O0
DEPFLAGS=-MP -MD
CFLAGS=-Wall -Werror  -std=$(VERSION) -g $(foreach D,$(INCDIRS),-I$(D)) $(OPT) $(DEPFLAGS)

CFILES=$(foreach D,$(CODEDIRS),$(wildcard $(D)/*.cpp))

OBJECTS=$(patsubst %.cpp,%.o,$(CFILES))
DEPFILES=$(patsubst %.cpp,%.d,$(CFILES))

all:$(BINARY)

$(BINARY):$(OBJECTS)
	$(CC) -o $@ $^

%.o:%.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(BINARY) $(OBJECTS) $(DEPFILES)

run: bin
	./bin