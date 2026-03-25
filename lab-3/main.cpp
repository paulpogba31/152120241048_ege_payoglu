#include <iostream>
#include <string>

using namespace std;

struct Song{
    string title;
    string artist;
    int ratings[3];
    Song *next;
    Song *prev;
};
Song* head= nullptr;
Song* tail= nullptr;
Song* CurrentSong = nullptr;

void addSong();
void nextSong();
void prevSong();
void removeCurrent();
void display();


int main()
{
    addSong("Muptela", "Joker", 9, 10, 10);
    addSong("Zalim", "Sezen aksu", 8, 7, 8);
    addSong("Anahtar", "Allame", 10, 9, 9);
    display();
    nextSong();
    display();
    removeCurrent();
    display();

    return 0;
}

void addSong(string title,string artist,int r1,int r2,int r3){

    Song* newSong == newSong();
    newSong -> title=title;
    newSong -> artist=artist;
    newSong -> ratings[0]=r1;
    newSong -> ratings[1]=r2;
    newSong -> ratings[2]=r3;
    newSong -> next = nullptr;
    newSong -> prev = nullptr;

    if(head == nullptr){
        head = newSong;
        tail = newSong;
        CurrentSong= newSong;
    }else{
        tail ->next = newSong;
        newSong ->prev = tail;
        tail = newSong;
    }


}
void nextSong(){
    if(CurrentSong != nullptr && CurrentSong ->next !=nullptr){
        CurrentSong = CurrentSong->next;
    }else{
        cout << "System: playlist already finished\n";
    }
}
void prevSong() {
    if (CurrentSong != nullptr && CurrentSong->prev != nullptr) {
        CurrentSong = CurrentSong->prev;
    }
}
void removeCurrent(){
    if (CurrentSong == nullptr) return;
        Song* toDelete = CurrentSong;
    if (toDelete->prev != nullptr) {
        toDelete->prev->next = toDelete->next;
    } else {
        head = toDelete->next;
    }


    if (toDelete->next != nullptr) {
        toDelete->next->prev = toDelete->prev;
        CurrentSong = toDelete->next;
    } else {
        CurrentSong = toDelete->prev;
    }

    delete toDelete;
}


}
void display(){
    Song* temp = head;
    cout << "\n--- Play List ---\n";

    while (temp != nullptr) {
        if (temp == CurrentSong) cout << "-> ";
        else cout << "   ";

        cout << temp->title << " - " << temp->artist << " [";
        for (int i = 0; i < 3; i++) {
            cout << temp->ratings[i];
            if (i < 2) cout << ",";
        }
        cout << "]\n";

        temp = temp->next;
    }
}

}
