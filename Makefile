SRC=vigenere.c
BIN=out-vigenere
OUT=output.txt
CC=gcc
FLAG=-std=c99 -Os

$(BIN): $(SRC)
	$(CC) $(SRC) $(FLAG) -o $@

clear:
	rm -f $(BIN) $(OUT)
