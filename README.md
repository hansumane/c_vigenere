# Vigenère encoder and decoder in C

## How to use

Put contents into **input.txt**

```
<alphabet>
<text to encrypt or decrypt>
<key>
<action: encrypt or decrypt>
```

Edit source code if you want a release version
without debug information (optional)

```
## in vigenere.c
4- | // #define RELEASE
4+ | #define RELEASE
```

Compile with *compiler* and **make**,
gcc is the default compiler

```
$ make CC=<compiler>
$ ./out-vigenere
```

The result will be printed in the console and saved to **output.txt**

## Issues

I am not quite sure if this program works 100% great, so
it may cause segfaults, other errors or even work improperly
