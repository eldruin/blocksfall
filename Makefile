EXE = main
CPPSOURCE = main.cpp pieza.cpp matriztetris.cpp contador.cpp controlTetris.cpp
HPPSOURCE = matriz.h pieza.h matriztetris.h contador.h controlTetris.h
OBJETO = main.o pieza.o matriztetris.o contador.o controlTetris.o
FLAGS = -lncurses
COMP = g++

all: $(EXE)

$(EXE): $(OBJETO)
	$(COMP) $(OBJETO) $(FLAGS) -o $(EXE)

$(OBJETO): $(CPPSOURCE) $(HPPSOURCE)
	$(COMP) -c $(CPPSOURCE)
	
clean:
	rm *.o *~ $(EXE)

run:
	./$(EXE)
