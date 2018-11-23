#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    int count=0;
    if(strsSize == 0){
        char *s = (char*)malloc(sizeof(char));
        s[0]='\0';
        return s;
    }
    if(strsSize == 1)
    {
        int len=strlen(strs[0]);
        char *s = (char*)malloc((1+len)*sizeof(char));
        strcpy(s,strs[0]);
        s[len]='\0';
        return s;
    }
    while(1){
        for(int i=1; i<strsSize; ++i){
            if(strs[i][count]!=strs[0][count]){
                char *s = (char*)malloc((1+count)*sizeof(char));
                strncpy(s,strs[0],count);
                s[count]='\0';
                return s;
            }
        }
        ++count;
    }
}
