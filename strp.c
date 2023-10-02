#include "str.h"
#include <assert.h>

size_t Str_getLength(const char *pcSrc) {
    const char *pcEnd;

    assert(pcSrc != NULL);

    pcEnd = pcSrc;

    while (*pcEnd !=  '\0') {
        pcEnd++;
    }
    
    return (size_t)(pcEnd - pcSrc);
}

char *Str_copy(char *pcDest, const char *pcSrc) {
    char *pcTemp;
    size_t uSrcLen, i;

    assert(pcDest != NULL);
    assert(pcSrc != NULL);

    uSrcLen = Str_getLength(pcSrc);
    pcTemp = pcDest;

    for (i = 0; i < uSrcLen; i++) {
        *pcTemp = *pcSrc;
        pcTemp++;
        pcSrc++;
    }

    *pcTemp = '\0';

    return pcDest;
}

char *Str_concat(char *pcDest, const char *pcSrc) {
    char *pcTemp;
    size_t uDestLen, uSrcLen, i;

    assert(pcDest != NULL);
    assert(pcSrc != NULL);

    uDestLen = Str_getLength(pcDest);
    pcTemp = pcDest + uDestLen;

    uSrcLen = Str_getLength(pcSrc);
    for (i = 0; i < uSrcLen; i++) {
        *pcTemp = *pcSrc;
        pcTemp++;
        pcSrc++;
    }

    *pcTemp = '\0';

    return pcDest;
}

int Str_compare(const char *s1, const char *s2) {
    assert(s1 != NULL);
    assert(s2 != NULL);

    while (*s1 != '\0' && *s2 != '\0') {
        if (*s1 != *s2) {
            return *s1 - *s2;
        }
        s1++;
        s2++;
    }

    return *s1 - *s2;
}

char *Str_search(const char *pcHaystack, const char *pcNeedle) {
    assert(pcHaystack != NULL);
    assert(pcNeedle != NULL);

    if (*pcHaystack == '\0' && *pcNeedle == '\0') 
        return (char *) pcHaystack;

    while(*pcHaystack != '\0') {
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

    return NULL;
}