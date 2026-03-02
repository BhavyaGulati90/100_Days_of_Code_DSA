// Add Two Numbers II

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

struct Node* insert(struct Node* head, int val) {
    struct Node* newNode = createNode(val);
    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

struct Node* reverse(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

struct Node* addTwoNumbers(struct Node* l1, struct Node* l2) {
    l1 = reverse(l1);
    l2 = reverse(l2);

    int carry = 0;
    struct Node* result = NULL;

    while (l1 != NULL || l2 != NULL || carry) {
        int sum = carry;

        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        result = insert(result, sum % 10);
        carry = sum / 10;
    }

    return reverse(result);
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
}

int main() {
    int n, m, x;
    struct Node* l1 = NULL;
    struct Node* l2 = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        l1 = insert(l1, x);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        l2 = insert(l2, x);
    }

    struct Node* result = addTwoNumbers(l1, l2);
    printList(result);

    return 0;
}