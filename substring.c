#include <stdio.h>
#include <stdlib.h>
#include "substring.h"

int
length (const char *string)
{
  int i = 0;
  while (string[i++] != 0)
    continue;
  return --i;
}

int
equal (const char *s1, const char *s2)
{
  const int _length_s1 = length (s1);
  const int _length_s2 = length (s2);

  if (_length_s1 == _length_s2)
    {
      for (int i = 0; i < _length_s1; ++i)
        {
          if (s1[i] != s2[i])
            return 0;
        }
      return 1;
    }
  return 0;
}

int
cindex (const char *string, const char element)
{
  const int _length = length (string);

  for (int i = 0; i < _length; ++i)
    if (string[i] == element)
      return i;
  return 0;
}

void
copy (char *where, const char *from)
{
  const int _length = length (from);

  for (int i = 0; i < _length + 1; ++i)
    where[i] = from[i];
}

void
set (char **what, const char *to)
{
  free (*what);
  *what = calloc (length (to) + 1, sizeof (char));
  copy (*what, to);
}

void
setkey (char **key, const char *to, const int _length)
{
  free (*key);
  *key = calloc (_length + 1, sizeof (char));
  copy (*key, to);
}

void
freadline (char **to, FILE *from)
{
  int left = BUFSIZE - 1;
  char char_buffer, string_buffer[BUFSIZE] = {};

  while ((fread (&char_buffer, sizeof (char), 1, from)) > 0)
    {
      if (char_buffer == '\n')
        break;
      string_buffer[length (string_buffer)] = char_buffer;
      if (!(--left))
        break;
    }

  free (*to);
  *to = calloc (length (string_buffer) + 1, sizeof (char));
  copy (*to, string_buffer);
}
