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
