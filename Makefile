# variabile
CC = gcc

# -Wall și -Wextra = arata multe warnings
# -Werror = transforma warnings in erori
CFLAGS = -Wall -Wextra -Werror -g -Iinclude

# executabil fina
TARGET = usersched

# surse (fara stats.c)
SRC = src/main.c src/scheduler.c src/process.c
OBJ = $(SRC:.c=.o)

# tintele nu sunt fisiere reale, sunt comenzi(ca sa ruleze mereu comanda)
.PHONY: all clean test run

# ce face make -> ruleaza target-ul all
all: $(TARGET)

# cum se construieste exacutabilul final
# $@ = numelel target-ului curent
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

# regula de compilare .c -> .o
# $< = primul fisier din dependente(.c)
# $@ = fisierul rezultat(.o)
src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# ruleaza programul
run: $(TARGET)
	./$(TARGET)

# compliare teste separat -> un program de teste
test: $(TARGET) tests/test_basic.c
	$(CC) $(CFLAGS) -o test_runner tests/test_basic.c src/scheduler.c src/process.c
	./test_runner

clean:
	rm -f $(TARGET) test_runner $(OBJ)
