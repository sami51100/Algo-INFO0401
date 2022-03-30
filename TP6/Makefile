#commentaire

CC = gcc
EXEC = prog 
SRC= $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all : $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^

%.o : %.c 
	$(CC) -o $@ -c $<

