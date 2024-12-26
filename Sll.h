// SLL.h

#ifndef SLL_H
#define SLL_H

#include "Node.h"
#include <iostream>

class SLL {
private:
    Node* head;
    int size;

public:
    SLL() : head(nullptr), size(0) {}

    void add(int item) {
        Node* newNode = new Node(item);
        if (isEmpty()) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
    }

    void addbegin(int item) {
        Node* newNode = new Node(item);
        newNode->next = head;
        head = newNode;
        size++;
    }

    void addanypos(int pos, int item) {
        if (pos < 0 || pos > size) {
            std::cout << "Error: Invalid position" << std::endl;
            return;
        }
        if (pos == 0) {
            addbegin(item);
            return;
        }
        Node* newNode = new Node(item);
        Node* temp = head;
        for (int i = 0; i < pos - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        size++;
    }

    bool contains(int item) {
        Node* temp = head;
        while (temp) {
            if (temp->data == item) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    int size() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    int get(int pos) {
        if (pos < 0 || pos >= size) {
            std::cout << "Error: Invalid position" << std::endl;
            return -1;
        }
        Node* temp = head;
        for (int i = 0; i < pos; i++) {
            temp = temp->next;
        }
        return temp->data;
    }

    int indexOf(int item) {
        Node* temp = head;
        int index = 0;
        while (temp) {
            if (temp->data == item) {
                return index;
            }
            temp = temp->next;
            index++;
        }
        return -1;
    }

    void removefirst() {
        if (isEmpty()) {
            std::cout << "Error: List is empty" << std::endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    void removelast() {
        if (isEmpty()) {
            std::cout << "Error: List is empty" << std::endl;
            return;
        }
        if (size == 1) {
            removefirst();
            return;
        }
        Node* temp = head;
        while (temp->next->next) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
        size--;
    }

    void remove(int pos) {
        if (pos < 0 || pos >= size) {
            std::cout << "Error: Invalid position" << std::endl;
            return;
        }
        if (pos == 0) {
            removefirst();
            return;
        }
        Node* temp = head;
        for (int i =
