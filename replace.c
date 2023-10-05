/*--------------------------------------------------------------------*/
/* replace.c                                                          */
/* Author: Connor Brown                                               */
/*--------------------------------------------------------------------*/

#include "str.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/*--------------------------------------------------------------------*/

/* If pcFrom is the empty string, then write string pcLine to stdout
   and return 0.  Otherwise write string pcLine to stdout with each
   distinct occurrence of string pcFrom replaced with string pcTo,
   and return a count of how many replacements were made.  Make no
   assumptions about the maximum number of replacements or the
   maximum number of characters in strings pcLine, pcFrom, or pcTo. */

static size_t replaceAndWrite(const char *pcLine,
                              const char *pcFrom, const char *pcTo)
{
   /* Increment variable to track the number of search hits for finding 
   pcFrom in pcLine. */
   size_t counter;

   /* Stores the length of pcFrom to skip that many elements ahead when 
   printing the updated pcLine. This effectively removes pcFrom from the
   printed output of pcLine. */
   size_t uFromLen;

   assert(pcLine != NULL);
   assert(pcFrom != NULL);
   assert(pcTo != NULL);

   uFromLen = Str_getLength(pcFrom);
   counter = 0;

   /* If theres an empty string to replace, don't do anything and
   just print pcLine. Return counter = 0 as the number of 
   replacements. */
   if (uFromLen == 0) {
      printf("%s", pcLine);
      return counter;
   }

   /* Continue to traverse pcLine until end of line. */
   while (*pcLine != '\0') {
      /* Find the next occurance of pcFrom in pcLine. */
      char *searchHit = Str_search(pcLine, pcFrom);

      /* Traverse toward the first hit, but print each character 
      (UNCHANGED) to output. This maintains pcLine in all cases where 
      pcFrom does NOT occur. If search hit was NULL, this will end up
      printing up until the end of pcLine. */
      while (pcLine != searchHit && *pcLine != '\0') {
         printf("%c", *pcLine);
         pcLine++;
      }

      /* Once the search hit is found, print pcTo in place of pcFrom. 
      Skip pcLine ahead by the length of pcFrom in order to repeat the
      search for the next occurance without printing pcFrom. Increment 
      the counter because the search hit was a success and a replacment
      was made. */
      if (pcLine == searchHit) {
         printf("%s", pcTo);
         pcLine += uFromLen;
         counter++;
      }
   }

   /* Return the number of replacements made within pcLine. */
   return counter;
}

/*--------------------------------------------------------------------*/

/* If argc is unequal to 3, then write an error message to stderr and
   return EXIT_FAILURE.  Otherwise...
   If argv[1] is the empty string, then write each line of stdin to
   stdout, write a message to stderr indicating that 0 replacements
   were made, and return 0.  Otherwise...
   Write each line of stdin to stdout with each distinct occurrence of
   argv[1] replaced with argv[2], write a message to stderr indicating
   how many replacements were made, and return 0.
   Assume that no line of stdin consists of more than MAX_LINE_SIZE-1
   characters. */

int main(int argc, char *argv[])
{
   enum {MAX_LINE_SIZE = 4096};
   enum {PROPER_ARG_COUNT = 3};

   char acLine[MAX_LINE_SIZE];
   char *pcFrom;
   char *pcTo;
   size_t uReplaceCount = 0;

   if (argc != PROPER_ARG_COUNT)
   {
      fprintf(stderr, "usage: %s fromstring tostring\n", argv[0]);
      return EXIT_FAILURE;
   }

   pcFrom = argv[1];
   pcTo = argv[2];

   while (fgets(acLine, MAX_LINE_SIZE, stdin) != NULL) {
      uReplaceCount += replaceAndWrite(acLine, pcFrom, pcTo);
   }

   fprintf(stderr, "%lu replacements\n", (unsigned long)uReplaceCount);
   return 0;
}
