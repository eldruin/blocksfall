CXX = g++
LDFLAGS = -lncurses
EXE = blocksfall
OBJS = main.o pieza.o matriztetris.o contador.o controlTetris.o

all: $(EXE)

$(EXE): $(OBJS)
	$(CXX) $(OBJS) $(LDFLAGS) -o $(EXE)

clean:
	$(RM) *.o *~ $(EXE)

run:
	./$(EXE)
