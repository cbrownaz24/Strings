/*--------------------------------------------------------------------*/
/* stra.c                                                             */
/* Author: Connor Brown                                               */
/*--------------------------------------------------------------------*/

#include "str.h"
#include <assert.h>

/*--------------------------------------------------------------------*/

size_t Str_getLength(const char pcSrc[]) {
  /* Stores the computed length. */
  size_t uLen; 

  assert(pcSrc != NULL);
  uLen = 0;
  
  /* Increment the length with each successive character in the array
  and stop at the null terminating character. */
  while(pcSrc[uLen] != '\0') {
    uLen++;
  }

  /* Return the computed length. */
  return uLen;
}

/*--------------------------------------------------------------------*/

char *Str_copy(char pcDest[], const char pcSrc[]) {
  /* Store the pcSrc string's length to check that program only goes up 
  to its null terminating character. */
  size_t uSrcLen; 

  /* Increment variable to match corresponding positions between pcDest 
  and pcSrc. */
  size_t i; 

  assert(pcDest != NULL);
  assert(pcSrc != NULL);

  uSrcLen = Str_getLength(pcSrc); 

  /* Iterate through pcSrc and replace each element of pcDest with 
  corresponding index of pcSrc. */
  for (i = (size_t) 0; i < uSrcLen; i++) {
    pcDest[i] = pcSrc[i];
  }

  /* Add terminating null character to end of copied string. */
  pcDest[uSrcLen] = '\0'; 

  /* Return a reference to the copied string. */
  return &pcDest[0]; 
}

/*--------------------------------------------------------------------*/

char *Str_concat(char pcDest[], const char pcSrc[]) {
  /* Store the pcSrc and pcDest's strings' length to check that program 
  only concatenates starting at pcDest's null terminating character and 
  ends with pcSrc's last character. */
  size_t uDestLen, uSrcLen;

  /* Increment variable to index pcSrc string. */
  size_t i;

  assert(pcDest != NULL);
  assert(pcSrc != NULL);


  uDestLen = Str_getLength(pcDest);
  uSrcLen = Str_getLength(pcSrc);

  /* Starting from the null terminating character of pcDest, replace
  each index with the corresponding index of pcSrc */
  for(i = (size_t) 0; i < uSrcLen; i++) {
    pcDest[uDestLen + i] = pcSrc[i];
  }

  /* Add terminating null character to end of concatenated string. */
  pcDest[uDestLen + uSrcLen] = '\0';

  /* Return the address of the first character in total concatenated 
  string. */
  return &pcDest[0];
}

/*--------------------------------------------------------------------*/

int Str_compare(const char s1[], const char s2[]) {
  /* Increment variable to traverse both strings at the same time. */
  int i;

  assert(s1 != NULL);
  assert(s2 != NULL);

  i = 0; /* Start at the 0th index of both strings. */

  /* Conitnue comparing strings until null terminating character found. 
  This is the exit condition for strings that are the same, or one is 
  the substring of the other.*/
  while (s1[i] != '\0' && s2[i] != '\0') {
    /* While comparing, if two characters are different, return the 
    unsigned integer difference between s1's character and s2's 
    character. */
    if (s1[i] != s2[i]) {
      return (int) s1[i] - (int) s2[i];
    }
    /* Otherwise, continue traversing and comparing both strings. */
    i++;
  }

  /* If a null-terminating character found in either string, return the 
  difference between the presently indexed characters. This returns a 0 
  if the strings were the same (two null-terminating characters), and a 
  non-zero integer if one string was a substring starting at the first 
  index of the other string. */
  return (int) s1[i] - (int) s2[i];
}

/*--------------------------------------------------------------------*/

char *Str_search(const char pcHaystack[], const char pcNeedle[]) {
  /* Store the pcSrc and pcDest's strings' length to check that program 
  only searches through pcHaystack's length minus pcNeedle's length 
  (anything greater wouldn't be possible). */
  size_t uNeedleLen, uHaystackLen;

  /* Increment variable to traverse pcHaystack during search. */
  size_t i;

  assert(pcHaystack != NULL);
  assert(pcNeedle != NULL);

  uNeedleLen = Str_getLength(pcNeedle);
  uHaystackLen = Str_getLength(pcHaystack);

  i = 0; /* Begin the search at the start of pcHaystack. */

  /* Continue traversing pcHaystack while the index is within 
  pcHaystack's bounds but still leaves room for a possible occurance of 
  pcNeedle. */
  while (i + uNeedleLen <= uHaystackLen) {
    /* Increment variable to traverse pcNeedle for comparison during 
    search. */
    size_t j = 0;

    /* Compare the substring of pcHaystack to pcNeedle as long as 
    corrresponding index values match. */
    while (i + j < uHaystackLen && pcHaystack[i + j] == pcNeedle[j]) {
      j++;
    }

    /* if the traversed search ended with the null terminating character
    of pcNeedle, then there was a search hit. */
    if (j == uNeedleLen) {
      /* Return the address of the first element in pcHaystack where the 
      first search hit starts. */
      return (char *) &pcHaystack[i];
    }

    /* If match is not found, the outer loop's index in pcHaystack will 
    increment, and search restarts. */
    i++;
  }

  /* If pcHaystack was iterated through entirely with no search hit, 
  return a NULL pointer. */
  return NULL;
}