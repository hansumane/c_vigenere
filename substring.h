#ifndef SUBSTRING_H
#define SUBSTRING_H
#define BUFSIZE 512

/* returns the number of first non-zero char array elements */
int length(const char *);

/* returns 1 (true) if the strings are equal and 0 (false) if they are not */
int equal(const char *, const char *);

/* returns the index of the second argument char element
 * in the first argument string */
int cindex(const char *, const char);

/* copies contents of the second argument string to the first one */
void copy(char *, const char *);

/* allocates the memory and copies contents of
 * the second argument string to pointer of the first one */
void set(char **, const char *);

/* does the same as set() but allocates specific amount of memory
 * given in the third argument */
void setkey(char **, const char *, const int);

/* reads everything before \n or EOF in
 * the second argument file to the first argument string */
void freadline(char **, FILE *);

#endif /* SUBSTRING_H */
