CC := g++
CFLAGS := -Wall -g

SRC = src
OBJ = obj
SRCS = $(wildcard $(SRC)/*.cpp)
OBJS = $(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SRCS))

BINDIR = bin
BIN = bin/myVensim
RM = rm

all: clean
all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	-del /q $(OBJ)\* $(BINDIR)\*

run: 
	.\$(BIN).exe

submit:
	$(RM) $(SUBMITNAME)
	zip $(SUBMITNAME) $(BIN)