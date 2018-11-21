#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isMatch(char *s, char *p)
{
    int row = strlen(s),
        col = strlen(p);

    bool **status = (bool **)malloc((row+1) * sizeof(bool *));
    for (int i = 0; i <= row; ++i)
        status[i] = (bool *)malloc((col+1) * sizeof(bool));

    for (int i = 0; i <= row; i++) 
      for (int j = 0; j <= col; j++) 
        status[i][j] = false;
    status[0][0]=true;

    for (int i = 0; i <= row; i++) 
      for (int j = 0; j <= col; j++){ 
        if (i > 0 && (s[i - 1] == p[j - 1] || p[j - 1] == '.')) 
          status[i][j] = status[i - 1][j - 1];        
        if (p[j - 1] == '*') 
          if (i == 0 || (s[i - 1] != p[j - 2] && p[j - 2] != '.')) 
            status[i][j] = status[i][j - 2];
           else 
            status[i][j] = status[i - 1][j] || status[i][j - 1] || status[i][j - 2];
      }

    bool res=status[row][col];
    for (int i = 0; i <= row; ++i)
        free(status[i]);
    free(status);
    return res;
}
