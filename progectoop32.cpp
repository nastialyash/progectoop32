
#include <iostream>

using namespace std;
class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;
        Node(int value) : data(value), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t size;

public:
  
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    
    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    
    bool insert(int value) {
        Node* newNode = new (std::nothrow) Node(value);
        if (!newNode) {
            cout << "Error: Memory allocation failed." << endl;
            return false; 
        }

        if (!head) {
          
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        ++size;
        return true;
    }

    
    bool remove(int value) {
        if (!head) {
            cout<< "Error: List is empty. Cannot remove element." << endl;
            return false; 
        }

        Node* current = head;
        while (current) {
            if (current->data == value) {
                if (current->prev) {
                    current->prev->next = current->next;
                }
                else {
                    head = current->next; 
                }

                if (current->next) {
                    current->next->prev = current->prev;
                }
                else {
                    tail = current->prev;
                }

                delete current;
                --size;
                return true; 
            }
            current = current->next;
        }

        cout << "Error: Element not found in the list." << endl;
        return false; 
    }

    
    size_t getSize() const {
        return size;
    }

   
    bool isEmpty() const {
        return size == 0;
    }

    bool getFirst(int& value) const {
        if (!head) {
            cout << "Error: List is empty. No first element." << endl;
            return false;
        }
        value = head->data;
        return true;
    }

    
    bool getLast(int& value) const {
        if (!tail) {
            cout << "Error: List is empty. No last element." << endl;
            return false;
        }
        value = tail->data;
        return true;
    }
};

int main() {
    DoublyLinkedList list;

   
    if (!list.insert(10)) return 1;
    if (!list.insert(20)) return 1;
    if (!list.insert(30)) return 1;

    int first, last;
    if (list.getFirst(first)) {
        cout << "First element: " << first << endl;
    }
    if (list.getLast(last)) {
        cout << "Last element: " << last << endl;
    }

   
    if (list.remove(20)) {
        std::cout << "Element 20 removed." << endl;
    }

   
    if (!list.remove(40)) {
        cout << "Element 40 not found." << endl;
    }
cout << "List size: " << list.getSize() << endl;

   
}
