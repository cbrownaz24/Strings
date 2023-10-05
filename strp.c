/*--------------------------------------------------------------------*/
/* strp.c                                                             */
/* Author: Connor Brown                                               */
/*--------------------------------------------------------------------*/
#include "str.h"
#include <assert.h>

/*--------------------------------------------------------------------*/

size_t Str_getLength(const char *pcSrc) {
  /* Stores the memory address of last element in pcSrc string to 
  compute the total difference in memory addresses relative to the start 
  element of pcSrc string. This difference is the length of pcSrc. */
  const char *pcEnd;

  assert(pcSrc != NULL);

  /* Initialize pcEnd as pcSrc and increment accordingly. */
  pcEnd = pcSrc; 

  /* Increment pcEnd until null terminating character is read. */
  while (*pcEnd !=  '\0') {
    pcEnd++;
  }
    
  /* Return the size_t difference between the start and end memory 
  addresses in pcSrc. */
  return (size_t)(pcEnd - pcSrc);
}

/*--------------------------------------------------------------------*/

char *Str_copy(char *pcDest, const char *pcSrc) {
  /* Starting address of destination to copy to. Stores a separate 
  reference since pcDest will need to be returned by end of method, so 
  it should be preserved. */
  char *pcTemp; 

  assert(pcDest != NULL);
  assert(pcSrc != NULL);

  /* Initialize pcTemp as a reference to the starting index of pcDest 
  string. */
  pcTemp = pcDest; 

  /* Copy each element of pcSrc string into the correpsonding index of
  pcDest string. Stop when the end of pcSrc string is read. */
  while (*pcSrc != '\0') {
    *pcTemp = *pcSrc;
    pcTemp++;
    pcSrc++;
  }

  /* End the copied string with a null terminating character. */
  *pcTemp = '\0';

  /* Return the address of the first element of the copied string. */
  return pcDest;
}

/*--------------------------------------------------------------------*/

char *Str_concat(char *pcDest, const char *pcSrc) {
  /* Starting address of destination to copy to. Stores a separate 
  reference since pcDest will need to be returned by end of method, so 
  it should be preserved. */
  char *pcTemp;

  /* Stores the length of the first string, pcDest, in concatenation to 
  determine the starting point for adding the second string, pcSrc. */
  size_t uDestLen;

  assert(pcDest != NULL);
  assert(pcSrc != NULL);

  uDestLen = Str_getLength(pcDest);

  /* Jump to the null terminating character of pcDest string to start 
  concatenation process. */
  pcTemp = pcDest + uDestLen;

  /* Concatenate each element of pcSrc string to the end of pcDest
  string until the end of pcSrc string is read. */ 
  while (*pcSrc != '\0') {
    *pcTemp = *pcSrc;
    pcTemp++;
    pcSrc++;
  }

  /* End the concatenated string with a null terminating character. */
  *pcTemp = '\0';

  /* Return the address of the first element of the total concatenated
  string. */
  return pcDest;
}

/*--------------------------------------------------------------------*/

int Str_compare(const char *s1, const char *s2) {
  assert(s1 != NULL);
  assert(s2 != NULL);

  /* Continue comparing strings until null terminating character found. 
  This is the exit condition for strings that are the same, or one is 
  the substring of the other. */
  while (*s1 != '\0' && *s2 != '\0') {
    /* While comparing, if two characters are different, return the 
    unsigned integer difference between s1's character and s2's 
    character. */
    if (*s1 != *s2) {
      return (int) *s1 - (int) *s2;
    }
    /* Otherwise, continue traversing and comparing both strings. */
    s1++;
    s2++;
  }
  /* If a null-terminating character found in either string, return the 
  difference between the presently indexed characters. This returns a 0 
  if the strings were the same (two null-terminating characters), and a 
  non-zero integer if one string was a substring starting at the first 
  index of the other string. */
  return (int) *s1 - (int) *s2;
}

/*--------------------------------------------------------------------*/

char *Str_search(const char *pcHaystack, const char *pcNeedle) {
  assert(pcHaystack != NULL);
  assert(pcNeedle != NULL);

  /* If both strings are empty, return the address of the pcHaystack 
  string. */
  if (*pcHaystack == '\0' && *pcNeedle == '\0') 
    return (char *) pcHaystack;

  /* Continue traversing pcHaystack while the index is within 
  pcHaystack's bounds. */
  while(*pcHaystack != '\0') {
    /* Create temporary references to pcHaystack and pcNeedle because
    method needs to iterate from pcHaystack's current index and from 
    pcNeedle's starting index in order to determine if pcHaystack's 
    current index is the start of a substring matching pcNeedle. 
    
    If there isn't a match, method will need to restart the search from 
    an incremented pcHaystack value and from pcNeedle's first index. So 
    preserving these values is necessary. */
    char *pcHayTemp = (char *) pcHaystack;
    char *pcNeedTemp = (char *) pcNeedle;

    /* As long as within bounds of pcHaystack's string and pcHaystack's 
    element value continues to match with pcNeedle's corresponding 
    element value continue traversing the possible search hit. */
    while (*pcHayTemp != '\0' && *pcHayTemp == *pcNeedTemp) {
      pcHayTemp++;
      pcNeedTemp++;
    }

    /* If we continued searching up to the end of pcNeedle, then there
    is a search hit. Return the address of the first element for this 
    search in pcHaystack. */
    if (*pcNeedTemp == '\0') 
      return (char *) pcHaystack;
        
    /* If there was not a search hit, then repeat the search starting at 
    the next element in pcHaystack. */
    pcHaystack++;
  }

  /* If traversed all of pcHaystack with no search hit, then return a 
  NULL pointer. */
  return NULL;
}