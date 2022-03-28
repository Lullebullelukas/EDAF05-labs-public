#include <stdio.h>
#include <stdlib.h>

typedef struct listItem listItem;
typedef struct list list;

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
    free(temp);
    return val;
}

int peek()
{
    if (head == NULL)
    {
        return -1;
    }
    else
    {
        return head->content;
    }
}

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

// int noPartner(int *list, int w)
// {
//     return list[w] == -1;
// }

int prefersNewMan(int woman, int *prefs, int man, int *pairs)
{
    // prefs[pairs[woman]] current pair pref
    // prefs[man] new man prio
    // lower prio better

    if (prefs[man] < prefs[pairs[woman]])
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
    for (i = 0; i < n; ++i)
    {
        push(i);
    }
    while (peek() != -1)
    {
        m = pop();
        w = men_prefs[m][propsedList[m]];
        propsedList[m] = propsedList[m] + 1;
        if (pairs[w] == -1)
        {
            pairs[w] = m;
        }
        else if (prefersNewMan(w, women_prefs[w], m, pairs))
        {
            int oldMan = pairs[w];
            pairs[w] = m;
            push(oldMan);
        }
        else
        {
            push(m);
        }
    }

    for (i = 0; i < n; ++i)
    {
        printf("%d \n", pairs[i] + 1);
    }
}

int main(int argc, char **argv)
{
    int n;
    int **women;
    int **men;
    int index;

    scanf("%d\n", &n);
    // printf("%d\n", n);
    women = make_sq_matrix(n);
    men = make_sq_matrix(n);

    for (int i = 0; i < 2 * n; ++i)
    {
        scanf("%d", &index);
        --index; // hack for 0-index
        if (women[index][0] == -1)
        {
            for (int k = 0; k < n; ++k)
            {
                // woman not read
                int temp;
                scanf("%d ", &temp);
                women[index][temp - 1] = k;
            }
        }
        else
        {
            // woman already read, write to man
            for (int k = 0; k < n; ++k)
            {
                int temp;
                scanf("%d ", &temp);
                men[index][k] = temp - 1;
            }
        }
    }
    print_sq_matrix(men, n);
    print_sq_matrix(women, n);

    gs(men, women, n);
}
