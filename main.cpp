#include <iostream>
#include "SLL.h"
#include "Node.h"

int main() {
    SLL list;

    // Add elements to the list
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);

    // Print the list
    std::cout << "List: ";
    for (int i = 0; i < list.size(); i++) {
        std::cout << list.get(i) << " ";
    }
    std::cout << std::endl;

    // Insert elements at various positions
    list.addanypos(0, 0);
    list.addanypos(list.size(), 6);
    list.addanypos(2, 2.5);

    // Print the list
    std::cout << "List: ";
    for (int i = 0; i < list.size(); i++) {
        std::cout << list.get(i) << " ";
    }
    std::cout << std::endl;

    // Test contains method
    std::cout << "Does the list contain 2.5? " << (list.contains(2.5) ? "Yes" : "No") << std::endl;

    // Test indexOf method
    std::cout << "Index of 2.5: " << list.indexOf(2.5) << std::endl;

    // Test size method
    std::cout << "Size of list: " << list.size() << std::endl;

    // Test remove methods
    list.removefirst();
    list.removelast();
    list.remove(2);

    // Print the list
    std::cout << "List: ";
    for (int i = 0; i < list.size(); i++) {
        std::cout << list.get(i) << " ";
    }
    std::cout << std::endl;

    // Test isEmpty method
    std::cout << "Is the list empty? " << (list.isEmpty() ? "Yes" : "No") << std::endl;

    // Test reverse method
    list.reverse();
    std::cout << "Reversed list: ";
    for (int i = 0; i < list.size(); i++) {
        std::cout << list.get(i) << " ";
    }
    std::cout << std::endl;

    // Test sort method
    list.sort();
    std::cout << "Sorted list: ";
    for (int i = 0; i < list.size(); i++) {
        std::cout << list.get(i) << " ";
    }
    std::cout << std::endl;

    return 0;
}
