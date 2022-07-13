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
@@ -1,7 +1,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #define BUFSIZE 512
-// #define RELEASE
+#define RELEASE
 
 /* returns length of the string without \0 at the end */
 int length(const char *);
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
