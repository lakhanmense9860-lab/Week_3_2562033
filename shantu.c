#include <stdio.h>
#include <stdlib.h>

// Structure of node
struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

// Create linked list
void create() {
    struct node *newnode, *temp;
    int choice;

    do {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
        } else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
        }

        printf("Do you want to add more nodes? (1/0): ");
        scanf("%d", &choice);
    } while (choice == 1);
}

// Insert at beginning
void insert_begin() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter data to insert at beginning: ");
    scanf("%d", &newnode->data);

    newnode->next = head;
    head = newnode;
}

// Display linked list
void display() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Delete node at end
void delete_end() {
    struct node *temp, *prev;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Last node deleted\n");
        return;
    }

    temp = head;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
    printf("Last node deleted\n");
}

int main() {
    int choice;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Create List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Display List\n");
        printf("4. Delete at End\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                printf("\nBefore Insertion:\n");
                display();
                insert_begin();
                printf("\nAfter Insertion:\n");
                display();
                break;
            case 3:
                display();
                break;
            case 4:
                delete_end();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}