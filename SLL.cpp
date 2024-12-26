#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int da) {
        data = da;
        next =NULL;
    }

    void Display() {
        cout << data;
    }
};

class SLL {
public:
    Node *head = NULL, *ptr;
    void create(int da){
    ptr= new Node(da);
    if(head==NULL)
    head=ptr;

    else{
        Node*temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=ptr;
    }
    }

    void add(int da) {
        Node *newptr = new Node(da);
        if (head == NULL) {
            head = newptr;
        } else {
            Node *temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newptr;
        }
    }

    void addbegin(int da) {
        Node *newptr = new Node(da);
        if (head == NULL)
            head = newptr;
        else {
            newptr->next = head;
            head = newptr;
        }
    }

    void addanypos(int pos, int da) {
        Node *newptr = new Node(da);
        Node *temp = head, *temp1 = NULL;
        for (int i = 0; i < pos && temp != NULL; i++) {
            temp1 = temp;
            temp = temp->next;
        }
        if (temp1 == NULL) {
            newptr->next = head;
            head = newptr;
        } else {
            temp1->next = newptr;
            newptr->next = temp;
        }
    }

    bool contains(int da) {
        Node *temp = head;
        while (temp != NULL) {
            if (temp->data == da) {
                cout << "True" << endl;
                return true;
            }
            temp = temp->next;
        }
        cout << "False" << endl;
        return false;
    }

    void sizeofList() {
        int count = 0;
        Node *temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        cout << "Size: " << count << endl;
    }

    bool isEmpty() {
        if (head == NULL) {
            cout << "True" << endl;
            return true;
        } else {
            cout << "False" << endl;
            return false;
        }
    }

    int get(int pos) {
        int count = 0;
        Node *temp = head;
        while (temp != NULL && count < pos) {
            temp = temp->next;
            count++;
        }
        if (count == pos && temp != NULL) {
            cout << temp->data << " is at index " << pos << endl;
            return temp->data;
        } else {
            cout << "Error: Index out of bounds" << endl;
            return -1;
        }
    }

    int indexOf(int da) {
        Node *temp = head;
        int pos = 0;
        while (temp != NULL) {
            if (temp->data == da) {
                cout << da << " is at index: " << pos << endl;
                return pos;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Element not found" << endl;
        return -1;
    }

    void removefirst() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    void removelast() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        Node *temp = head, *prev = NULL;
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        if (prev == NULL) {
            delete head;
            head = NULL;
        } else {
            prev->next = NULL;
            delete temp;
        }
    }

    void removefromanypos(int pos) {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        Node *temp = head, *prev = NULL;
        int count = 0;
        while (temp != NULL && count < pos) {
            prev = temp;
            temp = temp->next;
            count++;
        }
        if (count != pos || temp == NULL) {
            cout << "Error: Index out of bounds" << endl;
            return;
        }
        if (prev == NULL) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }
        delete temp;
    }

    void reverse() {
        Node *prev = NULL;
        Node *current = head;
        Node *next = NULL;
        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    void sort() {
        for (Node *i = head; i != NULL; i = i->next) {
            for (Node *j = i->next; j != NULL; j = j->next) {
                if (i->data > j->data) {
                    int temp = i->data;
                    i->data = j->data;
                    j->data = temp;
                }
            }
        }
    }

    void Display() {
        Node *temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    int input, data, pos;

    SLL *s=new SLL;
    s->create(24);
    s->create(34);
    s->create(44);
    while (true) {
        cout << "Press 1 for add at last" << endl;
        cout << "Press 2 for add at begin" << endl;
        cout << "Press 3 for add at any Position" << endl;
        cout << "Press 4 for contains" << endl;
        cout << "Press 5 for size" << endl;
        cout << "Press 6 for isEmpty" << endl;
        cout << "Press 7 for get" << endl;
        cout << "Press 8 for indexOf" << endl;
        cout << "Press 9 for remove from first" << endl;
        cout << "Press 10 for remove from last" << endl;
        cout << "Press 11 for remove from any Position" << endl;
        cout << "Press 12 for reverse" << endl;
        cout << "Press 13 for sort" << endl;
        cout << "Press 14 for Display" << endl;
        cout << "Press 15 for Exit" << endl << endl;
        cout << "Press Option: ";
        cin >> input;
        cout << endl;
        switch (input) {
            case 1:
                cout << "Enter Data: ";
                cin >> data;
                s->add(data);
                break;
            case 2:
                cout << "Enter Data: ";
                cin >> data;
                s->addbegin(data);
                break;
            case 3:
                cout << "Enter Position: ";
                cin >> pos;
                cout << "Enter Data: ";
                cin >> data;
                s->addanypos(pos, data);
                break;
            case 4:
                cout << "Enter Data: ";
                cin >> data;
                s->contains(data);
                break;
            case 5:
                s->sizeofList();
                break;
            case 6:
                s->isEmpty();
                break;
            case 7:
                cout << "Enter Position: ";
                cin >> pos;
                s->get(pos);
                break;
            case 8:
                cout << "Enter Data: ";
                cin >> data;
                s->indexOf(data);
                break;
            case 9:
                s->removefirst();
                break;
            case 10:
                s->removelast();
                break;
            case 11:
                cout << "Enter Position: ";
                cin >> pos;
                s->removefromanypos(pos);
                break;
            case 12:
                s->reverse();
                cout << "After Reverse: ";
                s->Display();
                break;
            case 13:
                s->sort();
                cout << "After Sorting in ascending order: ";
                s->Display();
                break;
            case 14:
                s->Display();
                break;
            case 15:
                delete s;
                return 0;
            default:
                cout << "Wrong Key" << endl << endl;
                break;
        }
    }
}
