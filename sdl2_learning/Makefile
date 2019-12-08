CXX = g++
CC  = gcc

CFLAGS := -O2 -c 
#-Wall 

LDFLAGS += -lm -lSDL2  

src := sdl2_event.cpp

#CFLAGS += -std=c++11

objects=$(patsubst %.cpp,%.o, $(src))
target = sdl2_test

.PHONY:all
all:${target}

${target}:$(objects)
	$(Q) $(CXX) $^ ${LDFLAGS} -o $@
	
%.o:%.cpp
	$(Q) $(CXX) -c $^ ${CFLAGS} ${CFLAGS_FULL} -o $@

.PHONY:clean
clean:
	@rm -f  ${target}
	@find -name "*.o" -execdir rm {} \;

	

