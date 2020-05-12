BUILD_DIR := "./build"
CC := g++
INC_DIR := -I ./include

# $(wildcard *.cpp /xxx/xxx/*.cpp): get all .cpp files from the current directory and dir "/xxx/xxx/"
CPP_SRCS := $(wildcard *.cpp)
# $(patsubst %.cpp,%.o,$(SRCS)): substitute all ".cpp" file name strings to ".o" file name strings
OBJS := $(patsubst %.cpp,%.o,$(CPP_SRCS))

HPP_SRCS := $(wildcard $(INC_DIR)/*.hpp)

CXXFLAGS := $(INC_DIR)
# Linux (default)
EXE = $(BUILD_DIR)/game

# Windows (cygwin)
ifeq ($(OS), "Windows_NT")
	EXE = $(BUILD_DIR)/$(EXE).exe
endif
# OS X

all: $(EXE)

$(EXE): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS)  -o $@ $(OBJS)

$(OBJS): $(HPP_SRCS)

clean:
	rm -rf $(TARGET) $(OBJS)

.PHONY: all clean
