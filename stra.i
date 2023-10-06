# 0 "stra.c"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 0 "<command-line>" 2
# 1 "stra.c"





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
# 7 "stra.c" 2
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



# 8 "stra.c" 2




# 11 "stra.c"
size_t Str_getLength(const char pcSrc[]) {

  size_t uLen;

  
# 15 "stra.c" 3 4
 ((
# 15 "stra.c"
 pcSrc != 
# 15 "stra.c" 3 4
 ((void *)0)) ? (void) (0) : __assert_fail (
# 15 "stra.c"
 "pcSrc != NULL"
# 15 "stra.c" 3 4
 , "stra.c", 15, __extension__ __PRETTY_FUNCTION__))
# 15 "stra.c"
                      ;
  uLen = 0;



  while(pcSrc[uLen] != '\0') {
    uLen++;
  }


  return uLen;
}



char *Str_copy(char pcDest[], const char pcSrc[]) {


  size_t uSrcLen;



  size_t i;

  
# 39 "stra.c" 3 4
 ((
# 39 "stra.c"
 pcDest != 
# 39 "stra.c" 3 4
 ((void *)0)) ? (void) (0) : __assert_fail (
# 39 "stra.c"
 "pcDest != NULL"
# 39 "stra.c" 3 4
 , "stra.c", 39, __extension__ __PRETTY_FUNCTION__))
# 39 "stra.c"
                       ;
  
# 40 "stra.c" 3 4
 ((
# 40 "stra.c"
 pcSrc != 
# 40 "stra.c" 3 4
 ((void *)0)) ? (void) (0) : __assert_fail (
# 40 "stra.c"
 "pcSrc != NULL"
# 40 "stra.c" 3 4
 , "stra.c", 40, __extension__ __PRETTY_FUNCTION__))
# 40 "stra.c"
                      ;

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

  
# 68 "stra.c" 3 4
 ((
# 68 "stra.c"
 pcDest != 
# 68 "stra.c" 3 4
 ((void *)0)) ? (void) (0) : __assert_fail (
# 68 "stra.c"
 "pcDest != NULL"
# 68 "stra.c" 3 4
 , "stra.c", 68, __extension__ __PRETTY_FUNCTION__))
# 68 "stra.c"
                       ;
  
# 69 "stra.c" 3 4
 ((
# 69 "stra.c"
 pcSrc != 
# 69 "stra.c" 3 4
 ((void *)0)) ? (void) (0) : __assert_fail (
# 69 "stra.c"
 "pcSrc != NULL"
# 69 "stra.c" 3 4
 , "stra.c", 69, __extension__ __PRETTY_FUNCTION__))
# 69 "stra.c"
                      ;

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

  
# 94 "stra.c" 3 4
 ((
# 94 "stra.c"
 s1 != 
# 94 "stra.c" 3 4
 ((void *)0)) ? (void) (0) : __assert_fail (
# 94 "stra.c"
 "s1 != NULL"
# 94 "stra.c" 3 4
 , "stra.c", 94, __extension__ __PRETTY_FUNCTION__))
# 94 "stra.c"
                   ;
  
# 95 "stra.c" 3 4
 ((
# 95 "stra.c"
 s2 != 
# 95 "stra.c" 3 4
 ((void *)0)) ? (void) (0) : __assert_fail (
# 95 "stra.c"
 "s2 != NULL"
# 95 "stra.c" 3 4
 , "stra.c", 95, __extension__ __PRETTY_FUNCTION__))
# 95 "stra.c"
                   ;

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



  size_t uNeedleLen, uHaystackLen;


  size_t i;

  
# 132 "stra.c" 3 4
 ((
# 132 "stra.c"
 pcHaystack != 
# 132 "stra.c" 3 4
 ((void *)0)) ? (void) (0) : __assert_fail (
# 132 "stra.c"
 "pcHaystack != NULL"
# 132 "stra.c" 3 4
 , "stra.c", 132, __extension__ __PRETTY_FUNCTION__))
# 132 "stra.c"
                           ;
  
# 133 "stra.c" 3 4
 ((
# 133 "stra.c"
 pcNeedle != 
# 133 "stra.c" 3 4
 ((void *)0)) ? (void) (0) : __assert_fail (
# 133 "stra.c"
 "pcNeedle != NULL"
# 133 "stra.c" 3 4
 , "stra.c", 133, __extension__ __PRETTY_FUNCTION__))
# 133 "stra.c"
                         ;

  uNeedleLen = Str_getLength(pcNeedle);
  uHaystackLen = Str_getLength(pcHaystack);

  i = 0;




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



  return 
# 169 "stra.c" 3 4
        ((void *)0)
# 169 "stra.c"
            ;
}
