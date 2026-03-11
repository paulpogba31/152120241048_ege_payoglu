#include <iostream>
#include <string>

using namespace std;

struct Node {

    string data;
    Node* next;

};

Node*head = nullptr;
void addWord(string x);
void undo();
void display();




int main() {
    string ent;
    cout << "Enter A WORD: \n";
    while (true) {
        cin >> ent;

        if (ent == "EXIT") {
            break;
        } 
        else if (ent == "UNDO") {
            undo();
        } 
        else {
            addWord(ent);
        }

        display();
    }

    return 0;
}
void addWord(string x){

    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = nullptr;

    if(Node == nullptr){
        head = newNode;
    } else {
        Node* iter = head;
    } while (iter->next != nullptr) {
            iter = iter->next;
     }
        iter->next = newNode;

}

void undo() {
    if (head == nullptr) {
        return; 
    }
     if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* iter = head;

    while (iter->next->next != nullptr) {
        iter = iter->next;
    }
    delete iter->next;
    iter->next==nullptr;
    
}


void display() {
    Node* y = head;
    while (y != nullptr) {
        cout << "[" << y->data << "] -> ";
        y = y->next;
    }
    cout << "NULL\n";
}






       



