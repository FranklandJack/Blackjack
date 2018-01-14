# Makefile for the Blackjack Game

SRC_DIR=src
HEADERS=$(wildcard $(SRC_DIR)/*.hpp)
SRC_FILES=$(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES=$(patsubst $(SRC_DIR)/%.cpp, %.o, $(SRC_FILES))


TEST_DIR=test
TEST_HEADERS=$(wildcard $(TEST_DIR)/*.hpp)
TEST_SRC_FILES=$(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJ_FILES=$(patsubst $(TEST_DIR)/%.cpp, %.o, $(TEST_SRC_FILES))

CXX=g++
CPPSTD=-std=c++11 
DEBUG=-g
OPT=-O2
LFLAGS=-lcppunit -lboost_program_options -lboost_system -lboost_filesystem
INC=-I$(SRC_DIR) -I$(TEST_DIR) -I$(HOME)/include

DOC_DIR=Documentation

EXE_FILE=blackjack
EXE_TEST=blackjack-cppunittests

## all       : Compile code and create executible 
.PHONY : all
all : $(EXE_FILE)

$(EXE_FILE) : $(OBJ_FILES)
	$(CXX) $(CPPSTD) $(OPT) $(LFLAGS) $^ -o $@

$(EXE_TEST): $(TEST_OBJ_FILES) Card.o Deck.o
	$(CXX) $(CPPSTD) $(OPT) -o $@  $^ $(LFLAGS) 
## objs      : create object files
.PHONY : objs
objs : $(OBJ_FILES) $(TEST_OBJ_FILES)

%.o : $(SRC_DIR)/%.cpp $(HEADERS)
	$(CXX) $(CPPSTD) $(OPT) -c $< -o $@ $(INC)

%.o : $(TEST_DIR)/%.cpp $(TEST_HEADERS)
	$(CXX) $(CPPSTD) $(OPT) -c $< -o $@ $(INC)

## test    : create and run unit tests
.PHONY : test
test : $(EXE_TEST)
	./$<

## doc      : create documentation
.PHONY : docs
docs : $(SRC_FILES)
	doxygen Doxyfile



## clean     : remove auto generated files
.PHONY : clean
clean :
	rm -f $(OBJ_FILES)
	rm -f $(TEST_OBJ_FILES)

	rm -f $(EXE_FILE)
	rm -f $(EXE_TEST)

	rm -r $(DOC_DIR)

## variables : Print variables
.PHONY :variables
variables:
	@echo SRC_DIR:   $(SRC_DIR)
	@echo SRC_FILES: $(SRC_FILES)
	@echo OBJ_FILES: $(OBJ_FILES)

	@echo TEST_DIR:       $(TEST_DIR)
	@echo TEST_SRC_FILES: $(TEST_SRC_FILES)
	@echo TEST_OBJ_FILES: $(TEST_OBJ_FILES)
	


## help      : Print help
.PHONY : help
help : Makefile
	@sed -n 's/^##//p' $<