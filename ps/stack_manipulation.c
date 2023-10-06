#include "push_swap.h"

struct node* circular_doubly_linked_list(int *a, int length) {
    if (length <= 0 || a == NULL) {
        return NULL; // Handle invalid input
    }

    // Create the first node
    struct node* head = (struct node*)malloc(sizeof(struct node));
    if (head == NULL) {
        return NULL; // Memory allocation failed
    }
    head->data = a[0];
    head->next = head;
    head->prev = head;

    struct node* current = head;
    int i = 1; // Start from the second element

    // Create and add the rest of the nodes using a while loop
    while (i < length) {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        if (newNode == NULL) {
            // Handle memory allocation failure by cleaning up and returning NULL
            while (head != NULL) {
                struct node* temp = head;
                head = head->next;
                free(temp);
            }
            return NULL;
        }
        newNode->data = a[i];
        newNode->next = head;
        newNode->prev = current;

        current->next = newNode;
        current = newNode;
        head->prev =current;
        i++;
    }
        return head; // Return a pointer to the head of the circular doubly linked list
}

struct node* initialize_empty_list() {
    // Create a dummy node that acts as the head of the list
    struct node* head = (struct node*)malloc(sizeof(struct node));
    if (head == NULL) {
        return NULL; // Memory allocation failed
    }

    // Initialize the dummy node to make it circular
    head->data = 0; // You can set any data value or leave it as 0
    head->next = head;
    head->prev = head;

    return head;
}
