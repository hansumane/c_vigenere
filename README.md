# Vigenère encoder and decoder in C

## How to use

Put contents into **input.txt**

```
<alphabet>
<text to encrypt or decrypt>
<key>
<action: encrypt or decrypt>
```

Compile and run program

```
$ gcc -std=c99 -Os vigenere.c -o out-vigenere # or
$ clang -std=c99 -Os vigenere.c -o out-vigenere
$ ./out-vigenere
```

The result will be printed in the console

## Issues

I am not quite sure if this program works 100% great, so
it may cause segfaults, other errors or even work improperly
