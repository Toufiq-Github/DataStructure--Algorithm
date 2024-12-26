#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

int gcd(int a, int b);
void printNumbersDescending(int n);
void printNumbersAscending(int n);
int fibonacciSum(int n);
void deleteNthNode(Node* &head, int n);
void sortLinkedList(Node* &head);

void displayLinkedList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    char choice;
    Node* head = nullptr;

    // Inserting some initial data into the linked list
    head = new Node(5);
    head->next = new Node(3);
    head->next->next = new Node(8);
    head->next->next->next = new Node(2);

    do {
        cout << "Menu:\n";
        cout << "1. Find GCD of two numbers\n";
        cout << "2. Print numbers in descending order\n";
        cout << "3. Print numbers in ascending order\n";
        cout << "4. Calculate summation up to n-element of Fibonacci sequence\n";
        cout << "5. Delete n-th node of a linked list\n";
        cout << "6. Sort a linked list\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case '1': {
                int a, b;
                cout << "Enter two numbers separated by space: ";
                cin >> a >> b;
                cout << "GCD of " << a << " and " << b << " is: " << gcd(a, b) << endl;
                break;
            }
            case '2': {
                int n;
                cout << "Enter a number: ";
                cin >> n;
                cout << "Numbers in descending order: ";
                printNumbersDescending(n);
                cout << endl;
                break;
            }
            case '3': {
                int n;
                cout << "Enter a number: ";
                cin >> n;
                cout << "Numbers in ascending order: ";
                printNumbersAscending(n);
                cout << endl;
                break;
            }
            case '4': {
                int n;
                cout << "Enter a number: ";
                cin >> n;
                cout << "Sum of Fibonacci sequence up to " << n << " elements is: " << fibonacciSum(n) << endl;
                break;
            }
            case '5': {
                int n;
                cout << "Enter the position of node to delete: ";
                cin >> n;
                deleteNthNode(head, n);
                cout << "Linked list after deletion: ";
                displayLinkedList(head);
                break;
            }
            case '6': {
                cout << "Sorting linked list...\n";
                sortLinkedList(head);
                cout << "Linked list after sorting: ";
                displayLinkedList(head);
                break;
            }
            case '7': {
                cout << "Exiting program. Goodbye!\n";
                break;
            }
            default: {
                cout << "Invalid choice! Please enter a valid option.\n";
            }
        }
    } while (choice != '7');

    // Freeing memory allocated for linked list
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void printNumbersDescending(int n) {
    if (n == 0)
        return;
    cout << n << " ";
    printNumbersDescending(n - 1);
}

void printNumbersAscending(int n) {
    if (n == 0)
        return;
    printNumbersAscending(n - 1);
    cout << n << " ";
}

int fibonacciSum(int n) {
    if (n <= 1)
        return n;
    return fibonacciSum(n - 1) + fibonacciSum(n - 2);
}

void deleteNthNode(Node* &head, int n) {
    if (head == nullptr)
        return;

    if (n == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* prev = nullptr;
    Node* curr = head;
    int count = 1;

    while (curr != nullptr && count != n) {
        prev = curr;
        curr = curr->next;
        count++;
    }

    if (curr == nullptr)
        return;

    prev->next = curr->next;
    delete curr;
}

void sortLinkedList(Node* &head) {
    if (head == nullptr || head->next == nullptr)
        return;

    Node* current = head;
    Node* index = nullptr;
    int temp;

    while (current != nullptr) {
        index = current->next;
        while (index != nullptr) {
            if (current->data > index->data) {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
            index = index->next;
        }
        current = current->next;
    }
}
