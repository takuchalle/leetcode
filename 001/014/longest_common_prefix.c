#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * longestCommonPrefix(char ** strs, int strsSize){
    if(strs == NULL || strsSize <= 0) return "";

    /* これを基準にする */
    char *first = strs[0];
    int end = 0;

    while(*first != '\0') {
        for(int i = 1; i < strsSize; i++) {
            if(*first != *strs[i]) {
                end = 1;
                break;
            }
            strs[i]++;
        }

        if(end == 1) break;

        first++;
    }

    int count = first - strs[0];

    if(count <= 0) {
        return "";
    }

    char* answer = malloc(count + 1);
    if (answer == NULL) return "";
    memcpy(answer, strs[0], count);
    answer[count] = '\0';
    return answer;
}

int main(int argc, char* argv[]) {
    char * strs[] = {"flower","flow","flight"};

    printf("%s\n", longestCommonPrefix(strs ,3));

    char * strs2[] = {"dog","racecar","car"};

    printf("%s\n", longestCommonPrefix(strs2 ,3));

    return 0;
}
