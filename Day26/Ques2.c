// Design Linked List

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

struct Node* head = NULL;
int size = 0;

int get(int index) {
    if (index < 0 || index >= size)
        return -1;

    struct Node* temp = head;
    for (int i = 0; i < index; i++)
        temp = temp->next;

    return temp->val;
}

void addAtHead(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = head;
    head = newNode;
    size++;
}

void addAtTail(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    size++;
}

void addAtIndex(int index, int val) {
    if (index < 0 || index > size)
        return;

    if (index == 0) {
        addAtHead(val);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;

    struct Node* temp = head;
    for (int i = 0; i < index - 1; i++)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
    size++;
}

void deleteAtIndex(int index) {
    if (index < 0 || index >= size)
        return;

    struct Node* temp = head;

    if (index == 0) {
        head = temp->next;
        free(temp);
    } else {
        for (int i = 0; i < index - 1; i++)
            temp = temp->next;

        struct Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        free(nodeToDelete);
    }
    size--;
}

void display() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, val, index;

    while (1) {
        printf("\n1. Add at Head");
        printf("\n2. Add at Tail");
        printf("\n3. Add at Index");
        printf("\n4. Get value at Index");
        printf("\n5. Delete at Index");
        printf("\n6. Display");
        printf("\n7. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scanf("%d", &val);
                addAtHead(val);
                break;

            case 2:
                scanf("%d", &val);
                addAtTail(val);
                break;

            case 3:
                scanf("%d %d", &index, &val);
                addAtIndex(index, val);
                break;

            case 4:
                scanf("%d", &index);
                printf("Value: %d\n", get(index));
                break;

            case 5:
                scanf("%d", &index);
                deleteAtIndex(index);
                break;

            case 6:
                display();
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}