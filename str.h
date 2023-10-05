/*--------------------------------------------------------------------*/
/* str.h                                                              */
/* Author: Connor Brown                                               */
/*--------------------------------------------------------------------*/
#include <stddef.h>

#ifndef STR_INCLUDED
#define STR_INCLUDED

/*--------------------------------------------------------------------*/

/* Calculates the length of the string pointed to by pcSrc, excluding 
  the terminating null byte ('\0'). Returns a size_t value 
  corresponding to the length of the string. */

size_t Str_getLength(const char *pcSrc);

/*--------------------------------------------------------------------*/

/* Copies the string pointed to by pcSrc, including the terminating null
  byte ('\0'), to the memory pointed to by pcDest. The strings may not 
  overlap, and pcDest must be large enough to receive the copy. Returns
  the address of the first element of the copied string. */

char *Str_copy(char *pcDest, const char *pcSrc);

/*--------------------------------------------------------------------*/

/* Appends the pcSrc string to the pcDest string, overwriting the 
  terminating null byte ('\0') at the end of pcDest, and then adds a
  terminating null byte. The strings may not overlap, and the pcDest 
  string must have enough space for the result. Returns the address of 
  the first element of the total concatenated string. */

char *Str_concat(char *pcDest, const char *pcSrc);

/*--------------------------------------------------------------------*/

/* Compares the two strings s1 and s2. Done using unsigned characters. 
  Returns a negative int if s1 < s2, a positive int if s1 > s2, and 0 if
  the strings are equal. */

int Str_compare(const char *s1, const char *s2);

/*--------------------------------------------------------------------*/

/* Finds the first occurrence of the substring pcNeedle in the string 
  pcHaystack. The terminating null bytes ('\0') are not compared. 
  If search hit, returns the address corresponding to the first element
  of the first search hit. Otherwise, returns a NULL pointer. If both 
  strings are empty, returns the address of pcHaystack. */
   
char *Str_search(const char *pcHaystack, const char *pcNeedle);

#endif