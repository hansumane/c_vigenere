#include <stdio.h>
#include <stdlib.h>
#include "substring.h"

int length(const char *array)
{
  int i = 0;
  while (array[i++] != 0)
    continue;
  return --i;
}

int equal(const char *first, const char *second)
{
  const int _length_first = length(first),
            _length_second = length(second);

  if (_length_first == _length_second)
    {
      for (int i = 0; i < _length_first; ++i)
        {
          if (first[i] != second[i])
            return 0;
        }
      return 1;
    }
  return 0;
}

int cindex(const char *array, const char element)
{
  const int _length = length(array);

  for (int i = 0; i < _length; ++i)
    if (array[i] == element)
      return i;
  return 0;
}

void copy(char *to, const char *from)
{
  const int _length = length(from);

  for (int i = 0; i < _length + 1; ++i)
    to[i] = from[i];
}

void set(char **to, const char *from)
{
  free(*to);
  *to = calloc(length(from) + 1, sizeof(char));
  copy(*to, from);
}

void setkey(char **key, const char *from, const int _length)
{
  free(*key);
  *key = calloc(_length + 1, sizeof(char));
  copy(*key, from);
}

void freadline(char **to, FILE *from)
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
  *to = calloc(length(string_buffer) + 1, sizeof(char));
  copy(*to, string_buffer);
}
