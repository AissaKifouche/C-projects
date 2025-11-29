#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ==================== Exercise 01: Linked List of Integers ====================

// Data structure for a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to insert a new value at the beginning of the list
Node* insertAtBeginning(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = head;
    return newNode;
}

// Function to insert a new value at the end of the list
Node* insertAtEnd(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to traverse the list and display the values
void traverseAndDisplay(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to delete the node at position k (1-based indexing)
Node* deleteAtPosition(Node* head, int k) {
    if (head == NULL) {
        return NULL;
    }

    if (k == 1) {
        Node* temp = head->next;
        free(head);
        return temp;
    }

    Node* temp = head;
    for (int i = 1; i < k - 1; i++) {
        if (temp->next == NULL) {
            return head; // Position out of bounds
        }
        temp = temp->next;
    }

    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
    return head;
}

// Function to delete nodes with a specific value x
Node* deleteNodesWithValue(Node* head, int x) {
    while (head != NULL && head->data == x) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }

    if (head == NULL) {
        return NULL;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        if (temp->next->data == x) {
            Node* nodeToDelete = temp->next;
            temp->next = nodeToDelete->next;
            free(nodeToDelete);
        } else {
            temp = temp->next;
        }
    }
    return head;
}

// Function to reverse the linked list
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// ==================== Exercise 02: Linked List of Persons ====================

// Data structure for a person
typedef struct Person {
    char firstName[50];
    char lastName[50];
    int age;
    struct Person* next;
} Person;

// Function to find the oldest person in the linked list
Person* findOldestPerson(Person* head) {
    if (head == NULL) {
        return NULL;
    }

    Person* oldest = head;
    Person* temp = head->next;

    while (temp != NULL) {
        if (temp->age > oldest->age) {
            oldest = temp;
        }
        temp = temp->next;
    }
    return oldest;
}

// ==================== Main Function to Test the Code ====================

int main() {
    // Test Exercise 01: Linked List of Integers
    Node* head = NULL;
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtBeginning(head, 5);

    printf("Initial List: ");
    traverseAndDisplay(head);

    head = deleteAtPosition(head, 2);
    printf("After deleting node at position 2: ");
    traverseAndDisplay(head);

    head = deleteNodesWithValue(head, 10);
    printf("After deleting nodes with value 10: ");
    traverseAndDisplay(head);

    head = reverseList(head);
    printf("After reversing the list: ");
    traverseAndDisplay(head);

    // Test Exercise 02: Linked List of Persons
    Person* person1 = (Person*)malloc(sizeof(Person));
    strcpy(person1->firstName, "John");
    strcpy(person1->lastName, "Doe");
    person1->age = 25;
    person1->next = NULL;

    Person* person2 = (Person*)malloc(sizeof(Person));
    strcpy(person2->firstName, "Jane");
    strcpy(person2->lastName, "Smith");
    person2->age = 30;
    person2->next = NULL;

    Person* person3 = (Person*)malloc(sizeof(Person));
    strcpy(person3->firstName, "Alice");
    strcpy(person3->lastName, "Johnson");
    person3->age = 22;
    person3->next = NULL;

    person1->next = person2;
    person2->next = person3;

    Person* oldestPerson = findOldestPerson(person1);
    if (oldestPerson != NULL) {
        printf("Oldest Person: %s %s, Age: %d\n", oldestPerson->firstName, oldestPerson->lastName, oldestPerson->age);
    }

    // Free memory for persons
    free(person1);
    free(person2);
    free(person3);

    return 0;
}
