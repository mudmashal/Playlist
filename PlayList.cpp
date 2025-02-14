// Mudasser Mashal September 2024

#include "PlayList.h"
#include <stdexcept>

using std::out_of_range;

// default constructor.
PlayList::PlayList():head(nullptr),songs(0){
}
// copy constructor.
PlayList::PlayList(const PlayList& pl):head(nullptr),songs(0){
    copy(pl);
}
// destructor.
PlayList::~PlayList(){
    clear();
}
// overloaded operator for PlayList.
PlayList& PlayList::operator=(const PlayList& pl){
    if (this == &pl) {
        return *this;
    }
    clear(); // clear the current playlist.
    copy(pl); // copy the contents of the given playlist.
    return *this;
}

// insert a song.
void PlayList::insert(Song sng, unsigned int pos){
    PlayListNode* newSong = new PlayListNode(sng); // create a new node for the song.
    if (pos==0){
    newSong->next = head;
    head = newSong;

    } else{ // find the node before the insertion point.
    PlayListNode* current = head;
    for (unsigned int i = 1; i < pos; ++i){
        if (current == nullptr) {
        throw std::out_of_range("Invalid position.");
}
    current = current->next;
}
    newSong->next = current->next;
    current->next = newSong;
    }
    ++songs;
}

// remove a song.
Song PlayList::remove(unsigned int pos){
    if (pos >= songs){
        throw std::out_of_range("Invalid position.");
    }
    // find the node to be removed and its previous node.
    PlayListNode* temp = head;
    PlayListNode* prev = nullptr;
    for (unsigned int i = 0; i < pos; ++i) {
    prev = temp;
    temp = temp->next;
    }
    // remove the node.
    if (prev){
        prev->next = temp->next;
    } else{
        head = temp->next;
    }
    // update
    Song removedSong = temp->song;
    delete temp;
    --songs;
    return removedSong;
}

// swaps two songs by their positions.
void PlayList::swap(unsigned int pos1, unsigned int pos2){
     if (pos1 >= songs || pos2 >= songs || pos1 == pos2){
        throw std::out_of_range("imvalid positions");
    }
    // pointers to the nodes to be swapped
    PlayListNode* song1 = head;
    PlayListNode* song2 = head;
    PlayListNode* p1 = nullptr;
    PlayListNode* p2 = nullptr; 

    // get song1 and its previous node
    for (unsigned int i = 0; i < pos1; ++i){
        p1 = song1;
        song1 = song1->next;
    }
    // get song2 and its previous node
    for (unsigned int i = 0; i < pos2; ++i){
        p2 = song2;
        song2 = song2->next;
    }
    // adjust the next pointers to swap the nodes
    if (p1){
      p1->next = song2; 
    } else{
    head = song2; 
    }
    if (p2){
     p2->next = song1;
    } else{
     head = song1;
    }
    // swap the next pointers of the 2 songs.
    PlayListNode* temp = song1->next;
    song1->next = song2->next;
    song2->next = temp;
}

// get a song at a position.
Song PlayList::get(unsigned int pos)const{
    PlayListNode* current = head;
    for (unsigned int i = 0; i < pos; ++i){
    current = current->next;
}
    return current->song;
}

// returns the number of songs in the playlist.
unsigned int PlayList::size()const{
    return songs;
}

// deep copies the linked list.
void PlayList::copy(const PlayList& pl) {
    // if orignal playlist is empty, set head to null and return.
    if (pl.head == nullptr) {
        head = nullptr;
        songs = 0;
        return;
    }
    // create the head node with the first song.
    head = new PlayListNode(pl.head->song);
    PlayListNode* current = head;
    // copy the remaining nodes.
    PlayListNode* original = pl.head->next; // start with the node after head
    while (original != nullptr) {
    current->next = new PlayListNode(original->song);
    current = current->next; 
    original = original->next;
}
    songs = pl.songs;
}

// deletes the playlist.
void PlayList::clear(){
    while (head != nullptr){
        PlayListNode* temp = head;
        head = head->next;
        delete temp;
    }
    songs = 0;
}