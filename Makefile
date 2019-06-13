ifeq ($(OS),Windows_NT)
    CXXFLAGS += -D WIN32
endif

ifeq ($(UNAME_S),Darwin)
    CCFLAGS += -D OSX
endif

CXXFLAGS=-O3 -std=c++0x -Wall

SOURCES= $(wildcard *.cpp)

OBJECTS=$(patsubst %.cpp, %.o, $(SOURCES))

TARGET=$(lastword $(subst /, ,$(realpath .)))

ifeq ($(UNAME_S),Darwin)
    LINKS= -framework OpenGL -framework GLUT
else
    LINKS= -lglut -lGL -lGLU
endif

CXX=g++

all: $(TARGET)
	@echo ImpulseEngine built

$(TARGET): $(OBJECTS)
	@$(CXX) $(CXXFLAGS) -o impulseengine $(OBJECTS) $(LINKS)

clean:
	rm -rf $(OBJECTS) $(TARGET)
