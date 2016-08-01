#makefile

PROGRAM = main.exe
SRC = main.c lrndata.c lrnproc.c cvp1.c
OBJS = $(SRC:%.c=%.o)
CC = gcc

$(PROGRAM): $(OBJS)
	$(CC) -o $(PROGRAM) $(OBJS)

.c.o:
	$(CC) -c $<

clean:
	rm -f $(PROGRAM) $(OBJS)

