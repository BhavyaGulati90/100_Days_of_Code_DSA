//

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* detectCycle(struct Node* head) {
    struct Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) { 
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow; 
        }
    }

    return NULL; 
}

int main() {
    int n, pos;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    struct Node *cycleNode = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;

        if (i == pos) {
            cycleNode = newNode;
        }
    }

    scanf("%d", &pos);

    if (pos != -1) {
        temp = head;
        for (int i = 0; i < pos; i++) {
            temp = temp->next;
        }
        cycleNode = temp;

        newNode->next = cycleNode;
    }

    struct Node* result = detectCycle(head);

    if (result != NULL)
        printf("Cycle starts at node with value: %d", result->data);
    else
        printf("No cycle");

    return 0;
}