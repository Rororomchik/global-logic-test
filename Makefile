CXX := g++

CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic

OUTPUT := search_app

SRCS := main.cpp find.cpp

OBJS := $(SRCS:.cpp=.o)

LIB_NAME := libfind.a

.PHONY: all clean

all: $(OUTPUT)

$(OUTPUT): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(OUTPUT)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(LIB_NAME): find.o
	ar rcs $(LIB_NAME) find.o

clean:
	rm -f $(OBJS) $(OUTPUT) $(LIB_NAME)
