
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a stack node
struct Node {
    int data;
    struct Node *next;
};

// Initialize the top pointer
struct Node *top = NULL;

// Function prototypes
void push(int data);
void pop();
void display();

void push(int data) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (!temp) {
        printf("Heap Overflow\n");
        return;
    }
    temp->data = data;
    temp->next = top;
    top = temp;
    printf("%d pushed to stack\n", data);
}

void pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    struct Node *temp = top;
    printf("%d popped from stack\n", top->data);
    top = top->next;
    free(temp);
}

void display() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    struct Node *temp = top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    push(60);
    push(30);
    push(10);
    push(15);
    display();
    pop();
    display();
    return 0;
}

