#include <stdio.h>
#include <stdlib.h>
#include "substring.h"
#include "vigenere.h"

static int exit_code = 0;

int main(void)
{
  FILE *input = fopen("input.txt", "rb");
  if (input == NULL)
    {
      fputs("Cannot open input.txt\n", stderr);
      exit_code = 1;
      exit(exit_code);
    }

  char *alphabet = NULL,
       *text = NULL,
       *key = NULL,
       *command = NULL,
       *result = NULL;

  freadline(&alphabet, input);
  freadline(&text, input);
  freadline(&key, input);
  freadline(&command, input);

  if (equal(command, "encrypt"))
    vigenere(&result, alphabet, text, key, 1);
  else if (equal(command, "decrypt"))
    vigenere(&result, alphabet, text, key, -1);
  else
    {
      fputs("Wrong encrypt / decrypt command!\n", stderr);
      exit_code = 2;
      goto END;
    }

#ifdef RELEASE
  puts(result);
  FILE *output = fopen("output.txt", "w");
  fputs(result, output);
  fputc('\n', output);
  fclose(output);
#endif

END:
  fclose(input);

  free(alphabet);
  free(text);
  free(key);
  free(command);
  free(result);

  return exit_code;
}
