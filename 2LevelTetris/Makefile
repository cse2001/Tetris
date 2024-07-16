COMPILER := g++
SRC_FILES := $(wildcard *.cpp)
OBJ_FILES := $(SRC_FILES:%.cpp=%.o)
.PHONY  : all clean
EXE := Tetris
all : $(EXE)

# Tetris: Tetris.cpp Board.cpp ActivePiece.cpp
# 	g++ -o Tetris Tetris.cpp Board.cpp ActivePiece.cpp


%.o : %.cpp
	$(COMPILER) -c `fltk-config --cxxflags` -MMD -MP $< -o $@

### include all dependency files

-include $(SRC_FILES:.cpp=.d)
   
$(EXE) : $(OBJ_FILES)

	g++ -o $@ $(OBJ_FILES) `fltk-config --ldflags`

clean :
	rm -rf $(OBJ_FILES) $(EXE) *.d