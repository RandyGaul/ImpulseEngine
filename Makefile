CXXFLAGS=-O3 -std=c++0x -Wall

SOURCES= $(wildcard *.cpp)

OBJECTS=$(patsubst %.cpp, %.o, $(SOURCES))

TARGET=$(lastword $(subst /, ,$(realpath .)))

LINKS= -lglut -lGL -lGLU

CXX=g++

all: $(TARGET)
	@echo ImpulseEngine built

$(TARGET): $(OBJECTS)
	@$(CXX) $(CXXFLAGS) -o impulseengine $(OBJECTS) $(LINKS)

clean:
	rm -rf $(OBJECTS) $(TARGET)
