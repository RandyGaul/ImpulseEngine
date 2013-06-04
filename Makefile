CXXFLAGS=-O3 -std=c++0x -D_DEBUG -Wall -g 

SOURCES= $(wildcard *.cpp)

OBJECTS=$(patsubst %.cpp, %.o, $(SOURCES))

TARGET=$(lastword $(subst /, ,$(realpath .)))

LINKS= -lglut -lGL 

CXX=g++

all: $(TARGET)
	@echo ImpulseEngine built

$(TARGET): $(OBJECTS)
	@$(CXX) $(CXXFLAGS) -o sketch $(OBJECTS) $(LINKS)

clean:
	rm -rf $(OBJECTS) $(TARGET)
