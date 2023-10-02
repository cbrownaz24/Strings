#include <assert.h>
#include <stddef.h>

size_t Str_getLength(const char pcSrc[]);
char *Str_copy(char pcDest[], const char pcSrc[]);
char *Str_concat(char pcDest[], const char pcSrc[]);
int Str_compare(const char s1[], const char s2[]);
char *Str_search(const char pcHaystack[], const char pcNeedle[]);