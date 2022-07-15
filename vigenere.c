#include <stdio.h>
#include <stdlib.h>
#define BUFSIZE 512
// #define RELEASE

/* returns the length of the string without \0 at the end */
int length(const char *);

/* returns 1 if the strings are equal and 0 if they are not.
   there may probably be a more efficient way to do it... */
int equal(const char *, const char *);

/* copies contents of the second argument string to the first one */
void copy(char *, const char *);

/* allocates the memory and copies contents of
   the second argument string to pointer of the first one */
void set(char **, const char *);

/* returns the index of the second argument element
   in the first argument string */
int char_index(const char *, const char);

/* reads everything before \n or EOF in
   the second argument file to the first argument string */
void char_readline(char **, FILE *);

/* function that encrypts or decrypts everything */
void vigenere(const char *, const char *, const char *, char **, const int);

int length(const char *array)
{
  int i = 0;
  while (array[i++] != 0)
    continue;
  return --i;
}

int equal(const char *first, const char *second)
{
  int _length = length(first);
  if (_length == length(second))
    {
      for (int i = 0; i < length(first); ++i)
        {
          if (first[i] != second[i])
            return 0;
        }
      return 1;
    }
  return 0;
}

void copy(char *to, const char *from)
{
  for (int i = 0; i < length(from) + 1; ++i)
    to[i] = from[i];
}

void set(char **to, const char *from)
{
  free(*to);
  *to = malloc((length(from) + 1) * sizeof(char));
  copy(*to, from);
}

int char_index(const char *where, const char element)
{
  for (int i = 0; i < length(where); ++i)
    if (where[i] == element)
      return i;
  return 0;
}

void char_readline(char **to, FILE *from)
{
  int left = BUFSIZE - 1;
  char char_buffer, string_buffer[BUFSIZE] = {};

  while ((fread(&char_buffer, sizeof(char), 1, from)) > 0)
    {
      if (char_buffer == '\n')
        break;
      string_buffer[length(string_buffer)] = char_buffer;
      if (!(--left))
        break;
    }

  free(*to);
  *to = malloc((length(string_buffer) + 1) * sizeof(char));
  copy(*to, string_buffer);
}

void vigenere(const char *alphabet, const char *text, const char *key_s, char **result, const int way)
{
  int index;
  char *key = NULL;
  set(&key, key_s);

  if (length(key_s) < length(text))
    {
      key = realloc(key, (length(text) + 1) * sizeof(char));
      key[length(text)] = 0;
      for (int i = 0; length(key_s) + i < length(text); i++)
        key[length(key_s) + i] = key[i];
    }

  *result = malloc((length(text) + 1) * sizeof(char));
  for (int i = 0; i < length(text); ++i)
  {
    index = (char_index(alphabet, text[i]) + way * char_index(alphabet, key[i])) % length(alphabet);
    if (index < 0)
      index = length(alphabet) + index;
    *(*result + i) = alphabet[index];
  }

#ifndef RELEASE
  printf("alphabet : %s : %d\n", alphabet, length(alphabet));
  printf("text     : %s : %d\n", text, length(text));
  printf("key_s    : %s : %d\n", key_s, length(key_s));
  printf("key      : %s : %d\n", key, length(key));
  puts  ("-----------------------------------------------");
  printf("result   : %s : %d\n", *result, length(*result));
#endif
}

int main(void)
{
  FILE *input = fopen("input.txt", "rb");
  FILE *output = fopen("output.txt", "w");
  if (input == NULL)
    {
      fputs("Cannot open input.txt\n", stderr);
      exit(1);
    }

  char *alphabet = NULL,
       *text = NULL,
       *key = NULL,
       *command = NULL,
       *result = NULL;

  char_readline(&alphabet, input);
  char_readline(&text, input);
  char_readline(&key, input);
  char_readline(&command, input);

  if (equal(command, "encrypt"))
    vigenere(alphabet, text, key, &result, 1);
  else if (equal(command, "decrypt"))
    vigenere(alphabet, text, key, &result, -1);
  else
    {
      fputs("Wrong encrypt / decrypt command!\n", stderr);
      exit(1);
    }

#ifdef RELEASE
  puts(result);
#endif

  fputs(result, output);
  fputc('\n', output);

  fclose(input);
  fclose(output);

  free(alphabet);
  free(text);
  free(key);
  free(command);
  free(result);

  return 0;
}
