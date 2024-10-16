# src/Makefile

TESTFILES = tests/*.cpp
CPP_FLAGS = -lstdc++ -std=c++17 -Wall -Werror -Wextra
G_STYLE = headers/*.h $(TESTFILES)

all: test style ;

clean: ;
	rm -f *.gc* test

build: clean ;
	g++ $(TESTFILES) $(CPP_FLAGS) -lgtest -o test

test: build ;
	./test
	valgrind --tool=memcheck --leak-check=yes ./test

prepare: ;
	sudo apt-get update
	sudo apt-get install build-essential libgtest-dev clang-format

style: ;
#	clang-format -i --style=google $(G_STYLE)
	clang-format -n --style=google $(G_STYLE)
