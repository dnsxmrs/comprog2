//This is a C program that implements a doubly linked list. The program provides a menu-
//driven interface to create a doubly linked list, display the list in normal or reverse order, sort 
//the list in ascending or descending order, insert a node into the list, delete a node from the
//list, and search for a node with a given data value in the list.

#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the doubly linked list
struct Node {
    struct Node* prev;  // Pointer to the previous node
    int data;           // Data stored in the node
    struct Node* next;  // Pointer to the next node
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));  // Allocate memory for the new node
    newNode->prev = NULL;  // Set the previous pointer to NULL
    newNode->data = data;  // Set the data of the node
    newNode->next = NULL;  // Set the next pointer to NULL
    return newNode;
}

// Function to display the doubly linked list in normal order
void displayNormal(struct Node* head) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    struct Node* current = head;
    printf("Linked list in normal order: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to display the doubly linked list in reverse order
void displayReverse(struct Node* tail) {
    if (tail == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    struct Node* current = tail;
    printf("Linked list in reverse order: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

// Function to insert a node with the given data into the doubly linked list
void insertNode(struct Node** head, struct Node** tail, int data) {
    struct Node* newNode = createNode(data);  // Create a new node with the given data

    if (*head == NULL) {
        // If the list is empty, make the new node the head and tail of the list
        *head = newNode;
        *tail = newNode;
    } else if (data <= (*head)->data) {
        // If the data is less than or equal to the data in the current head node,
        // insert the new node at the beginning of the list and update the head
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    } else if (data >= (*tail)->data) {
        // If the data is greater than or equal to the data in the current tail node,
        // insert the new node at the end of the list and update the tail
        newNode->prev = *tail;
        (*tail)->next = newNode;
        *tail = newNode;
    } else {
        // Find the appropriate position to insert the new node in the sorted list
        struct Node* current = (*head)->next;
        while (current->data < data) {
            current = current->next;
        }
        newNode->prev = current->prev;
        newNode->next = current;
        current->prev->next = newNode;
        current->prev = newNode;
    }

    printf("Node with data %d has been inserted.\n", data);
}

// Function to delete the node with the given data from the doubly linked list
void deleteNode(struct Node** head, struct Node** tail, int data) {
    if (*head == NULL) {
        printf("Linked list is empty. Cannot delete a node.\n");
        return;
    }

    struct Node* current = *head;
    while (current != NULL) {
        if (current->data == data) {
            if (current == *head && current == *tail) {
                // If the node to be deleted is both the head and tail,
                // update the head and tail pointers to NULL
                *head = NULL;
                *tail = NULL;
            } else if (current == *head) {
                // If the node to be deleted is the head, update the head pointer
                *head = current->next;
                (*head)->prev = NULL;
            } else if (current == *tail) {
                // If the node to be deleted is the tail, update the tail pointer
                *tail = current->prev;
                (*tail)->next = NULL;
            } else {
                // If the node to be deleted is neither the head nor the tail,
                // update the next and previous pointers of the adjacent nodes
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }

            free(current);  // Free the memory of the node to be deleted
            printf("Node with data %d has been deleted.\n", data);
            return;
        }

        current = current->next;
    }

    printf("Node with data %d not found. Cannot delete.\n", data);
}

// Function to search for a node with the given data in the doubly linked list
int searchNode(struct Node* head, int data) {
    if (head == NULL) {
        printf("Linked list is empty. Cannot search for a node.\n");
        return 0;
    }

    struct Node* current = head;
    int position = 1;
    while (current != NULL) {
        if (current->data == data) {
            printf("Node with data %d found at position %d.\n", data, position);
            return 1;
        }

        current = current->next;
        position++;
    }

    printf("Node with data %d not found.\n", data);
    return 0;
}

// Function to sort the doubly linked list in ascending or descending order
void sortList(struct Node** head, struct Node** tail, int order) {
    if (*head == NULL) {
        printf("Linked list is empty. Cannot sort.\n");
        return;
    }

    int swapped;
    struct Node* current;
    struct Node* temp;

    do {
        swapped = 0;
        current = *head;

        while (current->next != NULL) {
            if ((order == 1 && current->data < current->next->data) ||
                (order == 2 && current->data > current->next->data)) {
                // Swap adjacent nodes if they are in the wrong order
                if (current == *head) {
                    // If the current node is the head, update the head pointer
                    *head = current->next;
                    (*head)->prev = NULL;
                } else {
                    // If the current node is not the head, update the next and previous pointers of the adjacent nodes
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }

                // Perform the swapping
                temp = current->next->next;
                current->next->next = current;
                current->prev = current->next;
                current->next = temp;
                if (temp != NULL) {
                    temp->prev = current;
                }

                swapped = 1;
            }

            current = current->next;
        }
    } while (swapped);

    printf("Linked list has been sorted in %s order.\n", order == 1 ? "ascending" : "descending");
}

// Function to free the memory allocated for the doubly linked list
void freeList(struct Node** head) {
    struct Node* current = *head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    struct Node* tail = NULL;

    int choice, data;
    int listCreated = 0;

    do {
        printf("\nMAIN MENU\n");
        printf("1. Create a Doubly Linked List\n");
        printf("2. Display a Doubly Linked List\n");
        printf("3. Sort a Doubly Linked List\n");
        printf("4. Insert a Node\n");
        printf("5. Delete a Node\n");
        printf("6. Search a Number in the List\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (listCreated) {
                    printf("Doubly Linked List has already been created.\n");
                } else {
                    int n;
                    printf("Enter the number of elements: ");
                    scanf("%d", &n);

                    printf("Enter the elements: ");
                    for (int i = 0; i < n; i++) {
                        scanf("%d", &data);
                        insertNode(&head, &tail, data);
                    }

                    printf("Doubly Linked List created successfully.\n");
                    listCreated = 1;
                }
                break;
            case 2:
                if (!listCreated) {
                    printf("Doubly Linked List has not been created yet.\n");
                } else {
                    int displayChoice;
                    printf("2. Display a Doubly Linked List\n");
                    printf("   2.1. Normal order\n");
                    printf("   2.2. Reverse order\n");
                    printf("Enter choice: ");
                    scanf("%d", &displayChoice);

                    switch (displayChoice) {
                        case 1:
                            displayNormal(head);
                            break;
                        case 2:
                            displayReverse(tail);
                            break;
                        default:
                            printf("Invalid choice.\n");
                    }
                }
                break;
            case 3:
                if (!listCreated) {
                    printf("Doubly Linked List has not been created yet.\n");
                } else {
                    int sortChoice;
                    printf("3. Sort a Doubly Linked List\n");
                    printf("   3.1. Ascending\n");
                    printf("   3.2. Descending\n");
                    printf("Enter choice: ");
                    scanf("%d", &sortChoice);

                    switch (sortChoice) {
                        case 1:
                            sortList(&head, &tail, 1);
                            break;
                        case 2:
                            sortList(&head, &tail, 2);
                            break;
                        default:
                            printf("Invalid choice.\n");
                    }
                }
                break;
            case 4:
                if (!listCreated) {
                    printf("Doubly Linked List has not been created yet.\n");
                } else {
                    printf("4. Insert a Node\n");
                    printf("Enter the number you want to insert: ");
                    scanf("%d", &data);
                    insertNode(&head, &tail, data);
                }
                break;
            case 5:
                if (!listCreated) {
                    printf("Doubly Linked List has not been created yet.\n");
                } else {
                    printf("5. Delete a Node\n");
                    printf("Enter the number you want to delete: ");
                    scanf("%d", &data);
                    deleteNode(&head, &tail, data);
                }
                break;
            case 6:
                if (!listCreated) {
                    printf("Doubly Linked List has not been created yet.\n");
                } else {
                    printf("6. Search a Number in the List\n");
                    printf("Enter the number you want to search: ");
                    scanf("%d", &data);
                    searchNode(head, data);
                }
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 7);

    freeList(&head);

    return 0;
}
