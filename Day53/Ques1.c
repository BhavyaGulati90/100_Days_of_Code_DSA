/*Problem Statement:
Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

Output Format:
- Print nodes column by column from leftmost to rightmost vertical line */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct QNode {
    struct Node *node;
    int hd;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node* root = createNode(arr[0]);
    struct Node** queue = (struct Node**)malloc(n * sizeof(struct Node*));
    int front = 0, rear = 0;
    queue[rear++] = root;

    int i = 1;
    while (i < n) {
        struct Node* curr = queue[front++];

        if (i < n && arr[i] != -1) {
            curr->left = createNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    free(queue);
    return root;
}

void verticalOrder(struct Node* root, int n) {
    if (root == NULL)
        return;

    struct QNode* queue = (struct QNode*)malloc(n * sizeof(struct QNode));
    int front = 0, rear = 0;

    int cols[200][200];
    int count[200] = {0};
    int offset = 100;
    int minHD = 0, maxHD = 0;

    queue[rear].node = root;
    queue[rear].hd = 0;
    rear++;

    while (front < rear) {
        struct QNode temp = queue[front++];
        struct Node* curr = temp.node;
        int hd = temp.hd;

        cols[hd + offset][count[hd + offset]++] = curr->data;

        if (hd < minHD) minHD = hd;
        if (hd > maxHD) maxHD = hd;

        if (curr->left) {
            queue[rear].node = curr->left;
            queue[rear].hd = hd - 1;
            rear++;
        }

        if (curr->right) {
            queue[rear].node = curr->right;
            queue[rear].hd = hd + 1;
            rear++;
        }
    }

    for (int i = minHD; i <= maxHD; i++) {
        for (int j = 0; j < count[i + offset]; j++) {
            printf("%d", cols[i + offset][j]);
            if (j < count[i + offset] - 1)
                printf(" ");
        }
        printf("\n");
    }

    free(queue);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);
    verticalOrder(root, n);

    return 0;
}