#include <stdio.h>
#include <stdlib.h>

// typedef struct node node; 

// struct node {
//     int elem; 
//     int* next;
// };

// void add_node(node* nod, int el) {
//     nod->next = calloc(1, sizeof(node));
//     nod->elem = el; 
// }

// int pop_node(node* nodes, node* poped) {
//     if (nodes != NULL) {
        
//     }
//     else {
//         return 1; 
//     }
// }

int** make_sq_matrix(int n) {
    int** a; 
    a = calloc(n, sizeof(int*));
    for (int i = 0; i < n; ++i) {
        a[i] = calloc(n, sizeof(int));
    }
    return a; 
}

void print_sq_matrix(int** mat, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", i+1);
        for (int k = 0; k < n; ++k) {
            printf("%d ", mat[i][k]);
        }
        printf("\n");
    }
}

void read_prefs() {
    int n;
    int** women;
    int** men; 


    scanf("%d\n", &n);
    printf("%d\n", n);
    women = make_sq_matrix(n+1);
    men = make_sq_matrix(n+1);
    
    for (int i = 1; i <= n; ++i) {
        //skip first 
        scanf("%*d");
        for (int k = 1; k <= n; ++k) {
            scanf("%d ", &men[i][k]);
        }
    }
    print_sq_matrix(men, n);
    for (int i = 1; i <= n; ++i) {
        //skip first 
        scanf("%*d");
        for (int k = 1; k <= n; ++k) {
            int temp; 
            scanf("%d ", &temp);
            women[i][temp] = k;
        }
    }
    print_sq_matrix(women, n);
}

int main(int argc, char** argv)  {
    printf("Number of inputs: %d\n", argc);
    read_prefs();
}