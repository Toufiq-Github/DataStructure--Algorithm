
#include <iostream>
#include <stack>
#include <string>


class Stack {
private:
    std::stack<int> items;

public:

    void push(int newData) {
        items.push(newData);
    }


    int pop() {
        if (isEmpty()) {
            std::cerr << "Stack is empty. Cannot pop." << std::endl;
            return -1;
        }
        int poppedData = items.top();
        items.pop();
        return poppedData;
    }


    int size() {
        return items.size();
    }


    bool isEmpty() {
        return items.empty();
    }


    int getTop() {
        if (isEmpty()) {
            std::cerr << "Stack is empty. No top element." << std::endl;
            return -1;
        }
        return items.top();
    }

    void destroy() {
        while (!isEmpty()) {
            items.pop();
        }
    }

    void copyStack(Stack& source) {
        Stack tempStack;
        while (!source.isEmpty()) {
            tempStack.push(source.pop());
        }
        while (!tempStack.isEmpty()) {
            int data = tempStack.pop();
            items.push(data);
            source.push(data);
        }
    }


    void reverseStack() {
        Stack tempStack;
        while (!isEmpty()) {
            tempStack.push(pop());
        }
        while (!tempStack.isEmpty()) {
            push(tempStack.pop());
        }
    }
};

std::string decimalToBinary(int decimal) {
    std::stack<int> binaryStack;

    while (decimal > 0) {
        binaryStack.push(decimal % 2);
        decimal /= 2;
    }

    std::string binaryString = "";
    while (!binaryStack.empty()) {
        binaryString += std::to_string(binaryStack.top());
        binaryStack.pop();
    }

    return binaryString;
}

bool parseParentheses(std::string expression) {
    std::stack<char> parenthesesStack;

    for (char& c : expression) {
        if (c == '(') {
            parenthesesStack.push(c);
        } else if (c == ')') {
            if (parenthesesStack.empty()) {
                return false;
            }
            parenthesesStack.pop();
        }
    }

    return parenthesesStack.empty();
}

int main() {
    Stack stack1;

    int choice;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Push element\n";
        std::cout << "2. Pop element\n";
        std::cout << "3. Size of stack\n";
        std::cout << "4. Check if stack is empty\n";
        std::cout << "5. Copy stack to another\n";
        std::cout << "6. Reverse stack\n";
        std::cout << "7. Convert decimal to binary\n";
        std::cout << "8. Check parentheses matching\n";
        std::cout << "9. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                int newData;
                std::cout << "Enter element to push: ";
                std::cin >> newData;
                stack1.push(newData);
                break;
            case 2:
                if (!stack1.isEmpty()) {
                    std::cout << "Popped element: " << stack1.pop() << std::endl;
                }
                break;
            case 3:
                std::cout << "Size of stack: " << stack1.size() << std::endl;
                break;
            case 4:
                std::cout << "Stack is " << (stack1.isEmpty() ? "empty" : "not empty") << std::endl;
                break;
            case 5:
                {
                    Stack stack2;
                    stack2.copyStack(stack1);
                    std::cout << "Contents of stack copied to another stack." << std::endl;
                }
                break;
            case 6:
                stack1.reverseStack();
                std::cout << "Stack reversed." << std::endl;
                break;
            case 7:
                int decimal;
                std::cout << "Enter decimal number: ";
                std::cin >> decimal;
                std::cout << "Binary representation: " << decimalToBinary(decimal) << std::endl;
                break;
            case 8:
                {
                    std::string expression;
                    std::cout << "Enter expression: ";
                    std::cin >> expression;
                    if (parseParentheses(expression)) {
                        std::cout << "Parentheses matched." << std::endl;
                    } else {
                        std::cout << "Parentheses not matched." << std::endl;
                    }
                }
                break;
            case 9:
                std::cout << "Exiting program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 9);

    return 0;
}
