#ifndef VIGENERE_H
#define VIGENERE_H
#define RELEASE

/* function that encrypts or decrypts everything */
extern void
vigenere(char **result, const char *alphabet,
         const char *text, const char *key_s,
         const int way);

#endif /* VIGENERE_H */
