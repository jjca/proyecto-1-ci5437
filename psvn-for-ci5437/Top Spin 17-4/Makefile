CC = gcc
CXX = g++
OPT = -Wall -O3 -Wno-unused-function -Wno-unused-variable
PSVNOPT = --no_state_map --no_abstraction --backwards_moves --history_len=1

psvn2c_core.c:
	cp ../src/psvn2c_core.c ./psvn2c_core.c

psvn2c_state_map.c:
	cp ../src/psvn2c_state_map.c ./psvn2c_state_map.c

psvn2c_abstraction.c:
	cp ../src/psvn2c_abstraction.c ./psvn2c_abstraction.c

%.c: %.psvn psvn2c_core.c psvn2c_state_map.c psvn2c_abstraction.c
	../bin/psvn2c $(PSVNOPT) --name=$(*F) < $< > $@
	rm -f ./psvn2c_core.c ./psvn2c_state_map.c ./psvn2c_abstraction.c

.PRECIOUS: %.c

abstractor:
	@echo "**** Constructing abstractor ..."
	@$(CXX) $(OPT) ../src/abstractor.cpp ../src/psvn.cpp -o $@

%.pdb: abstractor
	@rm -f `basename $*`.abst `basename $*`.pdb `basename $*`.psvn
	@echo "**** Running abstractor on `dirname $*`.psvn with `basename $*`.txt ..."
	@./abstractor `dirname $*`.psvn `basename $*` < `basename $*`.txt > /dev/null
	@make `basename $*`.distSummary
	@echo "**** Constructing PDB `basename $*`.pdb ..."
	@./`basename $*`.distSummary `basename $*`.pdb
	@rm -f abstractor `basename $*`.distSummary

%.succ: %.c ../global/succ.c
	$(CC) $(OPT) ../global/succ.c -include $< -o $@
	rm -f $*.c

%.dist: %.c ../global/dist.cpp
	$(CXX) $(OPT) ../global/dist.cpp -include $< -o $@
	rm -f $*.c

%.distSummary: %.c ../global/distSummary.cpp
	$(CXX) $(OPT) ../global/distSummary.cpp -include $< -o $@
	rm -f $*.c

%.astar: %.c ../global/astar.cpp
	$(CXX) $(OPT) ../global/astar.cpp -include $< -include ../global/heuristic.cpp -o $@
	rm -f $*.c

%.idastar: %.c ../global/idastar.cpp
	$(CXX) $(OPT) ../global/idastar.cpp -include $< -include ../global/heuristic.cpp -o $@
	rm -f $*.c

%.bfs: %.c ../global/bfs.cpp
	$(CXX) $(OPT) ../global/bfs.cpp -include $< -o $@
	rm -f $*.c


.PHONY: clean
clean:
	rm -fr *.succ *.dist *.distSummary *.astar psvn2c_core.c psvn2c_state_map.c psvn2c_abstraction.c *.dSYM *.o *~