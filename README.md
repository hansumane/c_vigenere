# Vigenère encoder and decoder in C

## How to use

Put contents into **input.txt** or rename the file
as you wish

```
<alphabet>
<text to encrypt or decrypt>
<key>
<action: encrypt or decrypt>
```

**Warning!** Please make sure that every symbol from
your text or your key is in the alphabet, even space

Edit source code if you want a release version
without debug information (optional)

```
## in src/vigenere.h
3- | // #define RELEASE
3+ | #define RELEASE
```

Compile with *compiler*, *flags* and **make**,
"gcc" is default compiler, and "-std=gnu99 -Os"
are default flags. Run providing input *filename*,
the default one is "input.txt"

```
$ make CC=<compiler> FLAG=<flags>
$ ./evigenere <filename>
```

The result will be printed in the console and saved to **output.txt**,
but only if you've built RELEASE

## Issues

I am not quite sure if this program works 100% great, so
it may cause segfaults, other errors or even work improperly

## Plans for future

* Make this program work with command-line arguments (in future release)
now it can only accept input filename as an argument
