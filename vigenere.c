#include <stdio.h>
#include <stdlib.h>
#include "substring.h"
#include "vigenere.h"

void
vigenere(char **result, const char *alphabet,
         const char *text, const char *key_s,
         const int way)
{
	int index;
	char *key = NULL;
	const int _length_alphabet = length(alphabet);
	const int _length_text = length(text);
	const int _length_key_s = length(key_s);

	if (_length_key_s < _length_text) {
		setkey(&key, key_s, _length_text);
		for (int i = 0; _length_key_s + i < _length_text; i++)
			key[_length_key_s + i] = key[i];
	} else
		key = (char *)key_s;

	*result = calloc (_length_text + 1, sizeof (char));
	for (int i = 0; i < _length_text; ++i) {
		index = (cindex(alphabet, text[i]) + way * cindex(alphabet, key[i]))
		        % _length_alphabet;
		if (index < 0)
			index = _length_alphabet + index;
		(*result)[i] = alphabet[index];
	}

#ifndef RELEASE
	printf ("alphabet : %s : %d\n", alphabet, length (alphabet));
	printf ("text     : %s : %d\n", text, length (text));
	printf ("key_s    : %s : %d\n", key_s, length (key_s));
	printf ("key      : %s : %d\n", key, length (key));
	puts   ("-----------------------------------------------");
	printf ("result   : %s : %d\n", *result, length (*result));
#endif

	if (key != key_s)
		free (key);

}
