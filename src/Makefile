# Makefile to compile shox, the fox shell.
############################# Makefile ##########################
SRC=main.c shox.c
EXEC=shox
CC=gcc
REMOVE=rm -rf

all: $(EXEC)

$(EXEC):
	$(CC) -o $(EXEC) $(SRC)

remove:
	$(REMOVE) $(EXEC)
