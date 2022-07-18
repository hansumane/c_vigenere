SRC=main.c substring.c vigenere.c
HDR=substring.h vigenere.h
BIN=evigenere
OUT=output.txt
CC=gcc
FLAG=-std=c99 -Os

$(BIN): $(SRC) $(HDR)
	env $(CC) $(SRC) $(FLAG) -o $@

clear:
	env rm -f $(BIN) $(OUT)
