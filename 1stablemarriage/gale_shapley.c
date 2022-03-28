#include <stdio.h>
#include <stdlib.h>

typedef struct listItem listItem;
typedef struct list list;

struct listItem
{
    int man;
    listItem *next;
};

int **make_sq_matrix(int n)
{
    int **a;
    a = calloc(n, sizeof(int *));
    for (int i = 0; i < n; ++i)
    {
        a[i] = calloc(1, sizeof(int));
        a[i][0] = -1;
    }
    return a;
}

void print_sq_matrix(int **mat, int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", i + 1);
        for (int k = 0; k < n; ++k)
        {
            printf("%d ", mat[i][k] + 1);
        }
        printf("\n");
    }
}

int noPartner(int *list, int w)
{
    return list[w] == -1;
}

int prefersNewMan(int woman, int *prefs, int man, int *pairs)
{
    if (prefs[man] > prefs[pairs[woman]])
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void gs(int **men_prefs, int **women_prefs, int n)
{
    listItem *men = malloc(sizeof(listItem));
    listItem *temp = men;
    int *propsedList = calloc(n, sizeof(int));
    int *pairs = malloc(n * sizeof(int));
    int i;
    int m;
    int w;

    for (i = 0; i < n; ++i)
    {
        pairs[i] = -1;
    }

    // init list, should return men
    for (int i = 0; i < n; ++i)
    {
        temp->man = i;
        if (i == n - 1)
        {
            temp->next = NULL;
        }
        else
        {
            temp->next = malloc(sizeof(listItem));
            temp = temp->next;
        }
    }
    while (men != NULL)
    {
        m = men->man;
        men = men->next;
        w = men_prefs[m][propsedList[m]];
        propsedList[m]++;
        if (noPartner(pairs, w))
        {
            pairs[w] = m;
        }
        else if (prefersNewMan(w, women_prefs[w], m, pairs))
        {
            int oldMan = pairs[w];
            pairs[w] = m;

            // put man back into the thing
            temp = men;
            listItem *newMan = malloc(sizeof(listItem));
            men = newMan;
            newMan->man = oldMan;
            men->next = temp;
        }
        else
        {
            temp = men;
            listItem *newMan = malloc(sizeof(listItem));
            men = newMan;
            newMan->man = m;
            men->next = temp;
        }
    }

    for (i = 0; i < n; ++i)
    {
        printf("woman: %d, man: %d \n", i, pairs[i]);
    }
}

int main(int argc, char **argv)
{
    int n;
    int **women;
    int **men;
    int index;

    scanf("%d\n", &n);
    printf("%d\n", n);
    women = make_sq_matrix(n);
    men = make_sq_matrix(n);

    for (int i = 0; i < 2 * n; ++i)
    {
        scanf("%d", &index);
        --index;
        if (men[index][0] == -1)
        {
            for (int k = 0; k < n; ++k)
            {
                // man not read
                int temp;
                scanf("%d ", &temp);
                men[index][k] = temp - 1;
            }
        }
        else
        {
            // man already read, write to women
            for (int k = 0; k < n; ++k)
            {
                int temp;
                scanf("%d ", &temp);
                women[index][temp - 1] = k;
            }
        }
    }
    print_sq_matrix(men, n);
    print_sq_matrix(women, n);

    gs(men, women, n);
}
