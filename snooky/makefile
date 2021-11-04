CC=clang++

EXECUTABLE=snekysnek # Name of the final executable file: ./demo

MAIN_SRC=main.cpp # The 'main' source files
OTHER_SRC:=$(shell find src -name '*.cpp') # Find all .cpp in the directory src/

# These are automatic
MAIN_OBJ=$(MAIN_SRC:.cpp=.o)
OTHER_OBJ=$(OTHER_SRC:.cpp=.o)

INCLUDE_DIRS=include # Add more directories if needed, separate with space
INCLUDE_PARAMS=$(foreach d, $(INCLUDE_DIRS), -I$d)

COMPILE_FLAGS=-c $(INCLUDE_PARAMS) -std=c++11 # Change to -std=c++17 if needed
LINK_FLAGS=-lncurses # Add more if needed

all: $(SRC) $(OTHER_SRC) $(EXECUTABLE)

$(EXECUTABLE): $(MAIN_OBJ) $(OTHER_OBJ)
	# How it's written in the terminal
	# clang -lstdc++ -lm -lncurses demo.o -o demo
	$(CC) $(LINK_FLAGS) $(MAIN_OBJ) $(OTHER_OBJ) -o $@
	
.cpp.o:
	# How it's written in the terminal
	# clang -x c++ -c -std=c++11 demo.cpp -o demo.o
	$(CC) $(COMPILE_FLAGS) $< -o $@

.PHONY: run
run:
	./$(EXECUTABLE)

.PHONY: clean
clean:
	-rm -f demo.o
	-rm -f demo

.PHONY: install
install:
	sudo apt-get update
	sudo apt-get install libncurses5-dev
	sudo apt-get install libncursesw5-dev