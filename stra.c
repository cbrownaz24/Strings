#include <assert.h>
#include <stddef.h>
#include "str.h"

size_t Str_getLength(const char pcSrc[]) {
  size_t uLen;

  assert(pcSrc != NULL);
  uLen = 0;
  
  while(pcSrc[uLen] != '\0') {
    uLen++;
  }
  return uLen;
}

char *Str_copy(char pcDest[], const char pcSrc[]) {
  size_t uSrcLen;
  size_t i;

  assert(pcDest != NULL);
  assert(pcSrc != NULL);

  uSrcLen = Str_getLength(pcSrc);

  for (i = (size_t) 0; i < uSrcLen; i++) {
    pcDest[i] = pcSrc[i];
  }

  pcDest[uSrcLen] = '\0';

  return &pcDest[0];
}

char *Str_concat(char pcDest[], const char pcSrc[]) {
  size_t uDestLen, uSrcLen;
  size_t i;

  assert(pcDest != NULL);
  assert(pcSrc != NULL);

  uDestLen = Str_getLength(pcDest);
  uSrcLen = Str_getLength(pcSrc);

  for(i = (size_t) 0; i < uSrcLen; i++) {
    pcDest[uDestLen + i] = pcSrc[i];
  }
  pcDest[uDestLen + uSrcLen] = '\0';

  return &pcDest[0];
}

int Str_compare(const char s1[], const char s2[]) {
  int i;

  assert(s1 != NULL);
  assert(s2 != NULL);

  i = 0;
  while (s1[i] != '\0' && s2[i] != '\0') {
    if (s1[i] != s2[i]) {
      return (int) s1[i] - (int) s2[i];
    }
    i++;
  }
  return (int) s1[i] - (int) s2[i];
}

char *Str_search(const char pcHaystack[], const char pcNeedle[]) {
  size_t uNeedleLen = Str_getLength(pcNeedle);
  size_t uHaystackLen = Str_getLength(pcHaystack);
  size_t i = 0;

  assert(pcHaystack != NULL);
  assert(pcNeedle != NULL);

  while (i + uNeedleLen <= uHaystackLen) {
    size_t j = 0;

    while (i + j < uHaystackLen && pcHaystack[i + j] == pcNeedle[j]) {
      j++;
    }
    if (j == uNeedleLen) {
      return (char *) &pcHaystack[i];
    }
    i++;
  }
  return NULL;
}