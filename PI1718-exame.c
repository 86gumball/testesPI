#include <stdio.h>
#include "default.h"

// Parte A

// 1

char *strstr(char s1[], char s2[]){
    if (s2[0] == '\0') {
        return s1;
    }
    int i, j, k;
    for (i = 0; s1[i] != '\0'; i++) {
        if (s1[i] == s2[0]) {
           for (j = 0, k = i; s1[k] == s2[j] && s1[k] != '\0' && s2[j] != '\0'; j++, k++);

           if (s2[j] == '\0') {
                return (s1 + i);
           }
        }
    }
    return NULL;
}

// 2

void truncW(char t[], int n){
    int len = n;
    int i, dif = 1;
    for (i = 0; t[0] != '\0'; i++){
        if (!isspace(t[i])) {
            if (len > 0) {
                t[i + 1] = t[i + dif];
                len--;
            } 
        }
        len = n;
    }
}
