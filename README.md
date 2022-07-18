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
## in vigenere.h
3- | // #define RELEASE
3+ | #define RELEASE
```

Compile with *compiler* and **make**,
gcc is the default compiler

```
$ make CC=<compiler>
$ ./evigenere
```

The result will be printed in the console and saved to **output.txt**,
but only if you've built RELEASE

## Issues

I am not quite sure if this program works 100% great, so
it may cause segfaults, other errors or even work improperly

## Plans for future

* Make this program work with command-line arguments (in future release)
