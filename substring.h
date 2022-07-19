#ifndef SUBSTRING_H
#define SUBSTRING_H
#define BUFSIZE 512

/* returns the number of first non-zero char array elements */
extern int
length (const char *array);

/* returns 1 (true) if the strings are equal and 0 (false) if they are not */
extern int
equal (const char *s1, const char *s2);

/* returns the index of the second argument char element
 * in the first argument string */
extern int
cindex (const char *string, const char element);

/* copies contents of the second argument string to the first one
 * including \0 at the end */
extern void
copy (char *where, const char *from);

/* allocates the memory and copies contents of
 * the second argument string to pointer of the first one */
extern void
set (char **what, const char *to);

/* does the same as set() but allocates specific amount of memory
 * given in the third argument */
extern void
setkey (char **key, const char *to, const int _length);

/* reads everything before \n or EOF in
 * the second argument file to the first argument string */
extern void
freadline (char **to, FILE *from);

#endif /* SUBSTRING_H */
