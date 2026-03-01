CC ?= gcc
CFLAGS ?= -g -Wall

EXEC ?= main
OBJ ?= main.o header.o
DEPS ?= header.h

$(EXEC) : $(OBJ)
	$(CC) $(CFLAGS) $^ -o $(EXEC)

%.o : %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean run
clean:
	rm -f $(OBJ)
	rm $(EXEC)

run:
	@echo "Rularea programului /.$(EXEC)"
	@./$(EXEC)
