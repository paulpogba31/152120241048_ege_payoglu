#include <iostream>
#include <string>
#define MAX_SIZE 5

using namespace std;

struct Package {
    string packageID;
    string destinationCity;
    int dimensions[3];
    Package* next;
};

struct Courier {
    string courierName;
    string vehicleType;
};

Courier courierArray[MAX_SIZE];
int qFront = 0, qRear = 0, qCount = 0;
Package* stackTop = NULL;

Package* popPackage();
void pushPackage(string id, string city, int l, int w, int h);
void enqueueCourier(string name, string vehicle);
Courier dequeueCourier();
void dispatch();
void displayAll();



int main() {
    int choice = -1;

    while (choice != 0) {
        cout << "\n--- LOGISTICS MENU ---" << endl;
        cout << "1. Add Package" << endl;
        cout << "2. Add Courier" << endl;
        cout << "3. Dispatch (Send)" << endl;
        cout << "4. Show All" << endl;
        cout << "0. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) ;
        else if (choice == 2) ;
        else if (choice == 3) ;
        else if (choice == 4) ;
    }

    return 0;
}


Package* popPackage() {
    if (stackTop == NULL) {
        cout << "stack is empty!" << endl;
        return NULL;
    }
    Package* temp = stackTop;
    stackTop = stackTop->next;
    return temp;
}


void pushPackage(string id, string city, int l, int w, int h) {
    Package* newPkg = new Package();
    newPkg->packageID = id;
    newPkg->destinationCity = city;
    newPkg->dimensions[0] = l;
    newPkg->dimensions[1] = w;
    newPkg->dimensions[2] = h;

    newPkg->next = stackTop;
    stackTop = newPkg;

    cout << "package added -> " << id << endl;
}


void enqueueCourier(string name, string vehicle) {
    if (qCount == MAX_SIZE) {
        cout << "queue full, wait!" << endl;
        return;
    }
    courierArray[qRear].courierName = name;
    courierArray[qRear].vehicleType = vehicle;

    qRear = (qRear + 1) % MAX_SIZE;
    qCount++;

    cout << "courier added -> " << name << endl;
}


Courier dequeueCourier() {
    Courier c = courierArray[qFront];
    qFront = (qFront + 1) % MAX_SIZE;
    qCount--;
    return c;
}

void dispatch() {

    if (stackTop == NULL || qCount == 0) {
        cout << "cant dispatch. need package and courier." << endl;
        return;
    }

    Package* p = popPackage();
    Courier c = dequeueCourier();

    cout << "DISPATCH: " << c.courierName << " (" << c.vehicleType
         << ") is delivering " << p->packageID << " to "
         << p->destinationCity << endl;

    delete p;
}

void displayAll() {
    cout << "\n--- PACKAGES ---" << endl;
    Package* curr = stackTop;
    if (curr == NULL) cout << "no packages" << endl;
    while (curr != NULL) {
        cout << curr->packageID << " | " << curr->destinationCity
             << " | " << curr->dimensions[0] << "x" << curr->dimensions[1] << "x" << curr->dimensions[2] << endl;
        curr = curr->next;
    }

    cout << "\n--- COURIERS ---" << endl;
    if (qCount == 0) cout << "no couriers" << endl;
    for (int i = 0; i < qCount; i++) {
        int idx = (qFront + i) % MAX_SIZE;
        cout << courierArray[idx].courierName << " | " << courierArray[idx].vehicleType << endl;
    }
}

