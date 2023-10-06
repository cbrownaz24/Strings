# 0 "strp.c"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 0 "<command-line>" 2
# 1 "strp.c"




# 1 "str.h" 1




# 1 "/usr/lib/gcc/aarch64-redhat-linux/11/include/stddef.h" 1 3 4
# 143 "/usr/lib/gcc/aarch64-redhat-linux/11/include/stddef.h" 3 4

# 143 "/usr/lib/gcc/aarch64-redhat-linux/11/include/stddef.h" 3 4
typedef long int ptrdiff_t;
# 209 "/usr/lib/gcc/aarch64-redhat-linux/11/include/stddef.h" 3 4
typedef long unsigned int size_t;
# 321 "/usr/lib/gcc/aarch64-redhat-linux/11/include/stddef.h" 3 4
typedef unsigned int wchar_t;
# 6 "str.h" 2
# 16 "str.h"

# 16 "str.h"
size_t Str_getLength(const char *pcSrc);
# 25 "str.h"
char *Str_copy(char *pcDest, const char *pcSrc);
# 35 "str.h"
char *Str_concat(char *pcDest, const char *pcSrc);







int Str_compare(const char *s1, const char *s2);
# 53 "str.h"
char *Str_search(const char *pcHaystack, const char *pcNeedle);
# 6 "strp.c" 2
# 1 "/usr/include/assert.h" 1 3 4
# 35 "/usr/include/assert.h" 3 4
# 1 "/usr/include/features.h" 1 3 4
# 392 "/usr/include/features.h" 3 4
# 1 "/usr/include/features-time64.h" 1 3 4
# 20 "/usr/include/features-time64.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 21 "/usr/include/features-time64.h" 2 3 4
# 1 "/usr/include/bits/timesize.h" 1 3 4
# 19 "/usr/include/bits/timesize.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 20 "/usr/include/bits/timesize.h" 2 3 4
# 22 "/usr/include/features-time64.h" 2 3 4
# 393 "/usr/include/features.h" 2 3 4
# 490 "/usr/include/features.h" 3 4
# 1 "/usr/include/sys/cdefs.h" 1 3 4
# 551 "/usr/include/sys/cdefs.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 552 "/usr/include/sys/cdefs.h" 2 3 4
# 1 "/usr/include/bits/long-double.h" 1 3 4
# 553 "/usr/include/sys/cdefs.h" 2 3 4
# 491 "/usr/include/features.h" 2 3 4
# 514 "/usr/include/features.h" 3 4
# 1 "/usr/include/gnu/stubs.h" 1 3 4




# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 6 "/usr/include/gnu/stubs.h" 2 3 4


# 1 "/usr/include/gnu/stubs-lp64.h" 1 3 4
# 9 "/usr/include/gnu/stubs.h" 2 3 4
# 515 "/usr/include/features.h" 2 3 4
# 36 "/usr/include/assert.h" 2 3 4
# 64 "/usr/include/assert.h" 3 4




# 67 "/usr/include/assert.h" 3 4
extern void __assert_fail (const char *__assertion, const char *__file,
      unsigned int __line, const char *__function)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));


extern void __assert_perror_fail (int __errnum, const char *__file,
      unsigned int __line, const char *__function)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));




extern void __assert (const char *__assertion, const char *__file, int __line)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));



# 7 "strp.c" 2




# 10 "strp.c"
size_t Str_getLength(const char *pcSrc) {



  const char *pcEnd;

  
# 16 "strp.c" 3 4
 ((
# 16 "strp.c"
 pcSrc != 
# 16 "strp.c" 3 4
 ((void *)0)) ? (void) (0) : __assert_fail (
# 16 "strp.c"
 "pcSrc != NULL"
# 16 "strp.c" 3 4
 , "strp.c", 16, __extension__ __PRETTY_FUNCTION__))
# 16 "strp.c"
                      ;


  pcEnd = pcSrc;


  while (*pcEnd != '\0') {
    pcEnd++;
  }



  return (size_t)(pcEnd - pcSrc);
}



char *Str_copy(char *pcDest, const char *pcSrc) {



  char *pcTemp;

  
# 39 "strp.c" 3 4
 ((
# 39 "strp.c"
 pcDest != 
# 39 "strp.c" 3 4
 ((void *)0)) ? (void) (0) : __assert_fail (
# 39 "strp.c"
 "pcDest != NULL"
# 39 "strp.c" 3 4
 , "strp.c", 39, __extension__ __PRETTY_FUNCTION__))
# 39 "strp.c"
                       ;
  
# 40 "strp.c" 3 4
 ((
# 40 "strp.c"
 pcSrc != 
# 40 "strp.c" 3 4
 ((void *)0)) ? (void) (0) : __assert_fail (
# 40 "strp.c"
 "pcSrc != NULL"
# 40 "strp.c" 3 4
 , "strp.c", 40, __extension__ __PRETTY_FUNCTION__))
# 40 "strp.c"
                      ;



  pcTemp = pcDest;



  while (*pcSrc != '\0') {
    *pcTemp = *pcSrc;
    pcTemp++;
    pcSrc++;
  }


  *pcTemp = '\0';


  return pcDest;
}



char *Str_concat(char *pcDest, const char *pcSrc) {



  char *pcTemp;



  size_t uDestLen;

  
# 73 "strp.c" 3 4
 ((
# 73 "strp.c"
 pcDest != 
# 73 "strp.c" 3 4
 ((void *)0)) ? (void) (0) : __assert_fail (
# 73 "strp.c"
 "pcDest != NULL"
# 73 "strp.c" 3 4
 , "strp.c", 73, __extension__ __PRETTY_FUNCTION__))
# 73 "strp.c"
                       ;
  
# 74 "strp.c" 3 4
 ((
# 74 "strp.c"
 pcSrc != 
# 74 "strp.c" 3 4
 ((void *)0)) ? (void) (0) : __assert_fail (
# 74 "strp.c"
 "pcSrc != NULL"
# 74 "strp.c" 3 4
 , "strp.c", 74, __extension__ __PRETTY_FUNCTION__))
# 74 "strp.c"
                      ;

  uDestLen = Str_getLength(pcDest);



  pcTemp = pcDest + uDestLen;



  while (*pcSrc != '\0') {
    *pcTemp = *pcSrc;
    pcTemp++;
    pcSrc++;
  }


  *pcTemp = '\0';



  return pcDest;
}



int Str_compare(const char *s1, const char *s2) {
  
# 101 "strp.c" 3 4
 ((
# 101 "strp.c"
 s1 != 
# 101 "strp.c" 3 4
 ((void *)0)) ? (void) (0) : __assert_fail (
# 101 "strp.c"
 "s1 != NULL"
# 101 "strp.c" 3 4
 , "strp.c", 101, __extension__ __PRETTY_FUNCTION__))
# 101 "strp.c"
                   ;
  
# 102 "strp.c" 3 4
 ((
# 102 "strp.c"
 s2 != 
# 102 "strp.c" 3 4
 ((void *)0)) ? (void) (0) : __assert_fail (
# 102 "strp.c"
 "s2 != NULL"
# 102 "strp.c" 3 4
 , "strp.c", 102, __extension__ __PRETTY_FUNCTION__))
# 102 "strp.c"
                   ;




  while (*s1 != '\0' && *s2 != '\0') {



    if (*s1 != *s2) {
      return (int) *s1 - (int) *s2;
    }

    s1++;
    s2++;
  }





  return (int) *s1 - (int) *s2;
}



char *Str_search(const char *pcHaystack, const char *pcNeedle) {
  
# 129 "strp.c" 3 4
 ((
# 129 "strp.c"
 pcHaystack != 
# 129 "strp.c" 3 4
 ((void *)0)) ? (void) (0) : __assert_fail (
# 129 "strp.c"
 "pcHaystack != NULL"
# 129 "strp.c" 3 4
 , "strp.c", 129, __extension__ __PRETTY_FUNCTION__))
# 129 "strp.c"
                           ;
  
# 130 "strp.c" 3 4
 ((
# 130 "strp.c"
 pcNeedle != 
# 130 "strp.c" 3 4
 ((void *)0)) ? (void) (0) : __assert_fail (
# 130 "strp.c"
 "pcNeedle != NULL"
# 130 "strp.c" 3 4
 , "strp.c", 130, __extension__ __PRETTY_FUNCTION__))
# 130 "strp.c"
                         ;



  if (*pcHaystack == '\0' && *pcNeedle == '\0')
    return (char *) pcHaystack;



  while(*pcHaystack != '\0') {
# 148 "strp.c"
    char *pcHayTemp = (char *) pcHaystack;
    char *pcNeedTemp = (char *) pcNeedle;




    while (*pcHayTemp != '\0' && *pcHayTemp == *pcNeedTemp) {
      pcHayTemp++;
      pcNeedTemp++;
    }




    if (*pcNeedTemp == '\0')
      return (char *) pcHaystack;



    pcHaystack++;
  }



  return 
# 172 "strp.c" 3 4
        ((void *)0)
# 172 "strp.c"
            ;
}
