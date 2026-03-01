CC ?= gcc
CFLAGS ?= -g -Wall

EXEC ?= main
DEPS ?= header.h
OBJ ?= main.o header.o

$(EXEC) : $(OBJ)
	$(CC) $(CFLAGS) $^ -o $(EXEC)

%.o : %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean run
clean:
	rm -f %(OBJ)
	rm $(EXEC)

run: $(EXEC)
	@echo "Rulam programul : ./$(EXEC)"
	@./$(EXEC)

