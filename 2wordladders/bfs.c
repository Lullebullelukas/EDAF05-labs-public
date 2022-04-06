#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int n;
static int q;

typedef struct listItem listItem;

struct listItem
{
    int content;
    listItem *next;
} * head, *tail;

void push(int item)
{
    struct listItem *temp;
    temp = (struct listItem *)malloc(sizeof(struct listItem));
    temp->content = item;
    temp->next = NULL;
    if (tail == NULL)
    {
        head = tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

int pop()
{
    // no null saftey needed since peek is used
    int val = head->content;
    struct listItem *temp;
    temp = head;
    head = head->next;
    if (head == NULL)
    {
        tail = NULL;
    }
    free(temp);
    return val;
}

int path_count(int *pred, int s, int t)
{
    int count = 0;
    int nodeIndex = t;
    while (nodeIndex != s)
    {
        ++count;
        nodeIndex = pred[nodeIndex];
    }
    return count;
}

// s and t is
void bfs(char (*words)[n], int (*edges)[n], int s, int t)
{
    int i;
    int w;
    int visited[n];
    int pred[n];
    int v;
    // q is our list which we pop and push to
    push(s);
    for (i = 0; i < n; ++i)
    {
        visited[i] = 0;
    }
    visited[s] = 1;

    while (head != NULL)
    {
        v = pop();
        for (w = 0; w < n; ++w)
        {
            if (edges[v][w])
            {
                // all neighbors are inside this if statement
                if (!visited[w])
                {
                    visited[w] = 1;
                    push(w);
                    pred[w] = v;
                    if (w == t)
                    {
                        // printf("\n");
                        printf("%d\n", path_count(pred, s, t));
                        // empty list here
                        while (head != NULL)
                        {
                            pop();
                        }
                        return;
                    }
                }
            }
        }
    }
    printf("Impossible\n");
}

int main(int argc, char *argv[])
{
    int i;
    int j;
    int k;
    int h;
    int sIndex;
    int tIndex;
    int found;
    char dummy[6];
    char s[6];
    char t[6];
    scanf("%d", &n);
    scanf("%d", &q);
    char words[n][6];

    // printf("n is : %d\n", n);
    // printf("q is : %d\n", q);

    for (i = 0; i < n; ++i)
    {
        // words[i] = malloc(6 * sizeof(char));
        scanf("%6s", words[i]);
    }
    int edges[n][n];
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            edges[i][j] = 0;
            // iterate through the words
            // words[i] is u
            // words[j] is v
            // for loop for last 4 digits
            found = 0;
            strcpy(dummy, words[j]);
            for (k = 1; k < 5; ++k)
            {
                // dummy char here to work on
                for (h = 0; h < 5; ++h)
                {
                    if (words[i][k] == dummy[h])
                    {
                        memmove(&dummy[h], &dummy[h + 1], strlen(dummy) - h);
                        ++found;
                        break;
                    }
                }
                // printf("%s\n", dummy);
            }
            if (found < 4)
            {
                edges[i][j] = 0;
            }
            else
            {
                edges[i][j] = 1;
            }
        }
    }

    // fetch Query
    for (j = 0; j < q; ++j)
    {
        tIndex = 0;
        sIndex = 0;
        scanf("%s", s);
        scanf("%s", t);
        // printf("%d\n", q);
        // printf("looping...\n");
        for (i = 0; i < n; ++i)
        {
            if (!strcmp(words[i], s))
            {
                sIndex = i;
            }
            if (!strcmp(words[i], t))
            {
                tIndex = i;
            }
        }
        if (tIndex == sIndex)
        {
            printf("0\n");
        }
        else
        {
            bfs(words, edges, sIndex, tIndex);
        }
    }
    // freeing the input list
    // for (i = 0; i < n; ++i)
    //     free(words[i]);
}