#Compiler Flags
DC ?= g++
DCFLAGS ?= -g3 -O0 -I.. -Wall
LDFLAGS ?=
OBJEXT ?=

#Target
OBJ_NAME = appx-calc
.PHONY: $(OBJ_NAME) clean
$(OBJ_NAME) : $(SOURCES)
	$(DC) $(DCFLAGS) $(LDFLAGS) -o $(OBJ_NAME) $(SOURCES)

clean:
	rm $(OBJ_NAME)

SOURCES = \
	src/main.cpp
