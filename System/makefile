CC = g++
CFLAGS = -Wall -Wextra -std=c++23
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
TARGET = app
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
HDR = $(wildcard *.h)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

%.o: %.cpp $(HDR)
	$(CC) $(CFLAGS) -c $<

run:
	./$(TARGET)

fast: 
	make -j$(nproc)

clean:
	rm -f *.o $(TARGET)

.PHONY: all run clean
