CFLAGS=-Wall -Wextra -std=c99

TARGETS=nomogram ninel codeinvim vectsecv

build: $(TARGETS)

ninel: ninel.c
	gcc $(CFLAGS) ninel.c -o ninel

codeinvim: codeinvim.c
	gcc $(CFLAGS) codeinvim.c -o codeinvim

vectsecv: vectsecv.c
	gcc $(CFLAGS) vectsecv.c -o vectsecv

nomogram: nomogram.c
	gcc $(CFLAGS) nomogram.c -o nomogram

pack:
	zip -FSr 313CA_TurcuArinaEmanuela_Tema1.zip README Makefile *.c *.h

clean:
	rm -f $(TARGETS)
