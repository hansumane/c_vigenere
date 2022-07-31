#include <stdio.h>
#include <stdlib.h>
#include "substring.h"
#include "vigenere.h"

static char *filename = NULL;
static int exit_code = 0;

int
main (int argc, char **argv)
{
	if (argc < 2)
		filename = "input.txt";
	else
		filename = argv[1];

	FILE *input = fopen(filename, "rb");
	if (input == NULL) {
		fprintf(stderr, "Cannot open %s\n", filename);
		exit(exit_code = 1);
	}

	char *alphabet = NULL;
	freadline(&alphabet, input);

	char *text = NULL;
	freadline(&text, input);

	char *key = NULL;
	freadline(&key, input);

	char *command = NULL;
	freadline(&command, input);

	char *result = NULL;

	if (equal(command, "encrypt"))
		vigenere(&result, alphabet, text, key, 1);
	else if (equal(command, "decrypt"))
		vigenere(&result, alphabet, text, key, -1);
	else {
		fputs("Wrong encrypt / decrypt argument!\n", stderr);
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
	fclose (input);

	free(alphabet);
	free(text);
	free(key);
	free(command);
	free(result);

	return exit_code;
}
