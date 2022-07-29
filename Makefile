SRC=src/main.c src/substring.c src/vigenere.c
HDR=src/substring.h src/vigenere.h
BIN=evigenere
OUT=output.txt
CC=gcc
FLAG=-std=gnu99 -Os

$(BIN): $(SRC) $(HDR)
	env $(CC) $(SRC) $(FLAG) -o $@

clean:
	env rm -f $(BIN) $(OUT)
