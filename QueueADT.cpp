#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class QueueADT {
private:
    queue<int> q;

public:
    void enqueue(int data) {
        q.push(data);
    }

    void dequeue() {
        if (!q.empty()) {
            q.pop();
        }
    }

    int size() {
        return q.size();
    }

    bool isEmpty() {
        return q.empty();
    }

    void destroy() {
        while (!q.empty()) {
            q.pop();
        }
    }

    int top() {
        if (!q.empty()) {
            return q.front();
        }
        return -1;
    }

    void copyQueue(queue<int>& q2) {
        q2 = q;
    }

    void categorizeElements() {
        queue<int> group1, group2, group3, group4;
        while (!q.empty()) {
            int num = q.front();
            q.pop();
            if (num < 18)
                group1.push(num);
            else if (num >= 18 && num <= 35)
                group2.push(num);
            else if (num >= 36 && num <= 45)
                group3.push(num);
            else
                group4.push(num);
        }
        displayGroup("Group1", group1);
        displayGroup("Group2", group2);
        displayGroup("Group3", group3);
        displayGroup("Group4", group4);
    }

    void displayGroup(string groupName, queue<int>& group) {
        cout << groupName << ": ";
        if (group.empty())
            cout << "NULL";
        else {
            while (!group.empty()) {
                cout << group.front() << " ";
                group.pop();
            }
        }
        cout << endl;
    }

    void deleteNegativeIntegers() {
        queue<int> temp;
        while (!q.empty()) {
            if (q.front() >= 0)
                temp.push(q.front());
            q.pop();
        }
        q = temp;
    }

    void stackToQueue(stack<int>& s) {
        while (!s.empty()) {
            q.push(s.top());
            s.pop();
        }
    }

    void reverseQueue() {
        stack<int> s;
        while (!q.empty()) {
            s.push(q.front());
            q.pop();
        }
        while (!s.empty()) {
            q.push(s.top());
            s.pop();
        }
    }

    void queueToStack(stack<int>& s) {
        queue<int> temp = q;
        while (!temp.empty()) {
            s.push(temp.front());
            temp.pop();
        }
    }

    void display() {
        cout << "Queue: ";
        queue<int> temp = q;
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    QueueADT queueADT;
    int choice, data;

    do {
        cout << "Menu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Size\n";
        cout << "4. IsEmpty\n";
        cout << "5. Destroy\n";
        cout << "6. Top\n";
        cout << "7. CopyQueue\n";
        cout << "8. Categorize elements in Queue\n";
        cout << "9. Delete all Negative Integer\n";
        cout << "10. StackToQueue\n";
        cout << "11. Reverse Queue\n";
        cout << "12. QueueToStack\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to enqueue: ";
                cin >> data;
                queueADT.enqueue(data);
                break;
            case 2:
                queueADT.dequeue();
                break;
            case 3:
                cout << "Size of the queue: " << queueADT.size() << endl;
                break;
            case 4:
                if (queueADT.isEmpty())
                    cout << "Queue is empty\n";
                else
                    cout << "Queue is not empty\n";
                break;
            case 5:
                queueADT.destroy();
                cout << "Queue destroyed\n";
                break;
            case 6:
                cout << "Top element of the queue: " << queueADT.top() << endl;
                break;
            case 7: {
                queue<int> q2;
                queueADT.copyQueue(q2);
                cout << "Copied queue: ";
                while (!q2.empty()) {
                    cout << q2.front() << " ";
                    q2.pop();
                }
                cout << endl;
                break;
            }
            case 8:
                queueADT.categorizeElements();
                break;
            case 9:
                queueADT.deleteNegativeIntegers();
                cout << "Negative integers deleted from queue\n";
                break;
            case 10: {
                stack<int> s;

                queueADT.stackToQueue(s);
                cout << "Stack converted to queue\n";
                break;
            }
            case 11:
                queueADT.reverseQueue();
                cout << "Queue reversed\n";
                break;
            case 12: {
                stack<int> s;
                queueADT.queueToStack(s);
                cout << "Queue converted to stack\n";
                break;
            }
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }

        queueADT.display();
        cout << endl;
    } while (choice != 0);

    return 0;
}

