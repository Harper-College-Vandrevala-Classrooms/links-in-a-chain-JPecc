#include <iostream>
#include <string>
using namespace std;


class ChainLink {
private:
    string color;

public:
    ChainLink(string color) {
        this->color = color;
    }

    string get_color() {
        return this->color;
    }
};

class Node {
public:
    ChainLink* data; 
    Node* next;      

    Node(ChainLink* link) {
        this->data = link;
        this->next = nullptr; 
    }

    Node(ChainLink* link, Node* nextNode) {
        this->data = link;
        this->next = nextNode;
    }

    ChainLink* get_data() {
        return this->data;
    }
 
    Node* get_next() {
        return this->next;
    }
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    void append(ChainLink* newLink) {
        Node* newNode = new Node(newLink);

        if (head == nullptr) {
            head = newNode; 
        } else {
            Node* current = head;
            while (current->get_next() != nullptr) {
                current = current->get_next();
            }
            current->next = newNode;
        }
    }

    ChainLink* get_link_at(int index) {
        Node* current = head;
        int currentIndex = 0;

        while (current != nullptr) {
            if (currentIndex == index) {
                return current->get_data();
            }
            current = current->get_next();
            currentIndex++;
        }

        return nullptr;
    }
};

int main() {
    ChainLink link_one("red");
    ChainLink link_two("blue");
    ChainLink link_three("green");

    SinglyLinkedList list;

    list.append(&link_one);
    list.append(&link_two);
    list.append(&link_three);

    ChainLink* retrieved_link = list.get_link_at(1);
    if (retrieved_link != nullptr) {
        cout << "The second link color: " << retrieved_link->get_color() << endl;
    } else {
        cout << "No link found at the specified index." << endl;
    }

    retrieved_link = list.get_link_at(2);
    if (retrieved_link != nullptr) {
        cout << "The third link color: " << retrieved_link->get_color() << endl;
    } else {
        cout << "No link found at the specified index." << endl;
    }

    return 0;
}