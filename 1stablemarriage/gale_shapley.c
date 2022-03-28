#include <stdio.h>
#include <stdlib.h>

typedef struct listItem listItem;
typedef struct list list;
typedef struct pairList pairList;

struct listItem
{
    int man;
    listItem *next;
};

struct pairList
{
    int man;
    int woman;
    pairList *next;
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

int noPartner(pairList* list, int w) {
    while(list != NULL) {
        if ( w == list->woman) {
            return 0;
        }
        list = list->next;
    }
    return 1;
}

int prefersNewMan(int woman , int* prefs, int man, pairList* list) {
    while(list != NULL) {
        if ( woman == list->woman) {
            //found our pair
            if (prefs[man] > prefs[list->man]) {
                return 1; 
            } else {
                return 0;
            }
        }
        list = list->next;
    }
}

int swapPartner(pairList* list, int woman, int newMan) {
    pairList* tempList = list;
    pairList* head = tempList;
    int removedMan = -1; 

    while(tempList != NULL) {
        if ( woman == tempList->woman) {
            //skip the pair
           removedMan = tempList->man;
           tempList->man = newMan;
           return removedMan;
        }
        tempList = tempList->next;
    }
    return removedMan;
}

void gs(int **men_prefs, int **women_prefs, int n)
{
    listItem *head = malloc(sizeof(listItem));
    listItem *temp = head;
    int *propsedList = calloc(n, sizeof(int));
    pairList* pairs = malloc(sizeof(int));
    int m;
    int w;
    pairs = NULL;
    pairList* tempPairs;

    // init list, should return head
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
    while (head != NULL)
    {
        m = head->man;
        head = head->next;
        w = men_prefs[m][propsedList[m]];
        if(noPartner(pairs, w)) {
            tempPairs = pairs;
            pairList* newPair = malloc(sizeof(pairList));
            newPair->man = m; 
            newPair->woman = w;
            pairs = newPair;
            pairs->next = tempPairs;
        } else if(prefersNewMan(w,women_prefs[w],m, pairs)) {
           int removedMan = swapPartner(pairs, w, m);
           temp = head;
           listItem* newMan = malloc(sizeof(listItem));
           head = newMan;
           head->next = temp;
        }
    }


    while(pairs != NULL) {
        printf("woman: %d, man: %d \n", pairs->woman, pairs->man);
        pairs = pairs->next;
        //free
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
