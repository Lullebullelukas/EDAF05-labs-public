#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **men;
    int **women;
    int i;
    int j;
    int index;

    int n = 0;


    scanf("%d", &n);
    men = calloc(n, sizeof(int*));
    women = 
    for (i = 0; i < n; ++i)
    {
        scanf("%d", &index);
        for (j = 0; j < n; ++j)
        {
            scanf("%d", &men[index][j]);
        }
    }
    return 1;
}