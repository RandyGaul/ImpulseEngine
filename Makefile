UNAME_S := $(shell uname -s)

#OpenGL behaves a bit differently on MacOS
OSFLAG = 
ifeq ($(OS),Windows_NT)
    OSFLAG += -D WIN32
else
ifeq ($(UNAME_S),Darwin)
    OSFLAG += -D OSX
endif
endif

CXXFLAGS=-O3 -std=c++0x -Wall $(OSFLAG)

SOURCES= $(wildcard *.cpp)

OBJECTS=$(patsubst %.cpp, %.o, $(SOURCES))

TARGET=$(lastword $(subst /, ,$(realpath .)))

LINKS = 
ifeq ($(UNAME_S),Darwin)
    LINKS= -framework OpenGL -framework GLUT
else
    LINKS= -lglut -lGL -lGLU
endif

CXX=g++

all: $(TARGET)
	@echo ImpulseEngine built

$(TARGET): $(OBJECTS)
	$(info OSFLAG is $(OSFLAG))
	$(info OBJECTS is $(OBJECTS))
	$(CXX) $(CXXFLAGS) $(OSFLAG) -o impulseengine $(OBJECTS) $(LINKS)

clean:
	echo $(CCFLAGS)
	rm -rf $(OBJECTS) $(TARGET)
