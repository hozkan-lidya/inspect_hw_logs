CC := g++-8
CXX      := -c++
CXXFLAGS := -std=c++2a -Ofast -pedantic-errors -Wall -Wunused -Wextra -Werror
# LDFLAGS  := -L/usr/lib -lstdc++ -lm
BUILD    := ./build
# OBJ_DIR  := $(BUILD)/objects
# APP_DIR  := $(BUILD)/apps
TARGET   := program
INCLUDE  := -I.
# $(TARGET): 


.PHONY: all run clean
all: 
	$(CC) $(CXXFLAGS) src/main.cc -o $(BUILD)/$(TARGET)

run: all
	$(BUILD)/$(TARGET)

clean:
	rm -f $(BUILD)/**