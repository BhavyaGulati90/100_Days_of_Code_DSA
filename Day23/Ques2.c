//Linked List Cycle.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int data;
    struct ListNode* next;
};

struct ListNode* createNode(int data) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct ListNode* insertEnd(struct ListNode* head, int data) {
    struct ListNode* newNode = createNode(data);

    if (head == NULL)
        return newNode;

    struct ListNode* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

bool hasCycle(struct ListNode* head) {
    if (head == NULL)
        return false;

    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
}

int main() {
    int n, value, pos;
    struct ListNode* head = NULL;
    struct ListNode* temp = NULL;
    struct ListNode* cycleNode = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    scanf("%d", &pos);

    if (pos >= 0) {
        temp = head;
        for (int i = 0; i < pos; i++)
            temp = temp->next;

        cycleNode = temp;

        temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = cycleNode; 
    }

    if (hasCycle(head))
        printf("true");
    else
        printf("false");

    return 0;
}