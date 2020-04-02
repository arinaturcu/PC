# compiler setup
CC=gcc
CFLAGS=-Wall -Wextra -std=c99

# define targets
TARGETS=star_dust

build:$(TARGETS)

star_dust:
	$(CC) $(CFLAGS) -g main.c task1.c task2.c task3.c -o star_dust

pack:
	zip -FSr 313CA_ArinaEmanuelaTurcu_Tema2.zip README Makefile *.c *.h

clean:
	rm -f $(TARGETS)
