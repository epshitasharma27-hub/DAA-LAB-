// huffman code 
#include <stdio.h>
#include <stdlib.h>
struct Node {
    char ch;
    int freq;
    struct Node *left, *right;
};
struct Node* create(char ch, int freq) {
    struct Node* n = malloc(sizeof(struct Node));
    n->ch = ch;
    n->freq = freq;
    n->left = n->right = NULL;
    return n;
}
void printCode(struct Node* root, char code[], int top) {
    if (root->left) {
        code[top] = '0';
        printCode(root->left, code, top + 1);
    }
    if (root->right) {
        code[top] = '1';
        printCode(root->right, code, top + 1);
    }
    if (!root->left && !root->right) {
        code[top] = '\0';
        printf("%c : %s\n", root->ch, code);
    }
}
int main() {
    int n, i, j;
    char ch[20], code[20];
    int freq[20];
    struct Node* a[20];
    printf("Enter number of characters: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter character and frequency: ");
        scanf(" %c %d", &ch[i], &freq[i]);
        a[i] = create(ch[i], freq[i]);
    }
    while (n > 1) {
        for (i = 0; i < n - 1; i++) {
            for (j = i + 1; j < n; j++) {
                if (a[i]->freq > a[j]->freq) {
                    struct Node* temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
        struct Node* left = a[0];
        struct Node* right = a[1];
        struct Node* parent = create(
            '#', left->freq + right->freq
        );
        parent->left = left;
        parent->right = right;
        a[0] = parent;
        for (i = 1; i < n - 1; i++)
            a[i] = a[i + 1];

        n--;
    }
    printf("\nHuffman Codes:\n");
    printCode(a[0], code, 0);
    return 0;
}