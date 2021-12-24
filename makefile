SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin
SDL_DIR := C:/msys64/mingw64/x86_64-w64-mingw32

EXE := $(BIN_DIR)/main.exe
SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

CXX      := g++
CPPFLAGS := -I inc -I $(SDL_DIR)/include/SDL2 -MMD -MP
CXXFLAGS := -Wall -Wextra -std=c++17 -ggdb
LDFLAGS  := -L lib -L $(SDL_DIR)/lib/
LDLIBS   := -l mingw32 -l SDL2main -l SDL2 -l SDL2_mixer -l SDL2_image -l SDL2_ttf

.PHONY: all clean run

all: $(EXE)

$(EXE): $(OBJ) | $(BIN_DIR)
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

clean:
	@$(RM) -rv $(BIN_DIR) $(OBJ_DIR)

run:
	$(EXE)

-include $(OBJ:.o=.d)
