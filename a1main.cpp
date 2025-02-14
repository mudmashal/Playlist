/* 

Mudasser Mashal September 2024

PlayList Methods
******************************************
Default constructor: O(1)

Destructor: O(n)
Because the destructor iterates through the entire linked list to delete each node.

Copy constructor: O(n)
the copy constructor creates a new linked list by 
iterating through the original list and copying each node.

Insert: O(n)
Worst case scenario, the insert method traverses the entire list to find the insertion position.

Remove: O(n)
Worst case scenario, the remove method traverses the entire list to find the node to be removed.

Get: O(n)
Worst case scenario, the get method traverses the entire list to find the node at the specified position.

Swap: O(n)
Worst case scenario, the swap method traverses the list twice to find the nodes to be swapped.

Size: O(1)
The size method simply returns how many songs are in the list.

Main Function
******************************************
Enter a song: O(n)
calling the insert method, which has a time complexity of O(n)

Remove a song: O(n)
Removing a song involves calling the remove method, which has a time complexity of O(n)

Swap two songs: O(n)
Swapping two songs involves calling the swap method, which  has a time complexity of O(n)

Print the songs: O(n)
Printing all songs involves iterating through the entire list to access each song

*/

#include "PlayList.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// function to print the menu.
void printMenu(){

cout << "\nMenu:\n"
<< "1. Enter a song in the playlist at a given position\n"
<< "2. Remove a song from the playlist at a given position\n"
<< "3. Swap two songs in the playlist\n"
<< "4. Print the songs in the playlist\n"
<< "5. Quit\n";

}

int main(){

PlayList playlist;
int option = 0; // initialize the option for menu

 while (option != 5){ // loops until quit option is chosen.
    printMenu(); 
    cout << "Enter, 1.Insert, 2.Remove, 3.Swap, 4.Print or 5.Quit: ";
    cin >> option; 
  
    // Check for valid menu option
    if (option < 1 || option > 5) {
        cout << "Invalid. Please enter an option between 1 and 5.\n";
        continue; // Prompt user again if input is invalid
    }

    // cases for options.
    switch (option){
    case 1:{

    string name, artist;
    int length, position; 
    
    cin.ignore(); // clear input buffer
    cout << "Song name: ";
    getline(cin, name); 
    cout << "Artist: ";
    getline(cin, artist); 
    cout << "Length in seconds: ";
    cin >> length; 
    cout << "Position (1 to " << playlist.size()+1 << "): ";
    cin >> position;

    // check for valid position
    if (position < 1 || position > playlist.size()+1){
        cout << "Invalid position. Enter a position between 1 - " << playlist.size() + 1 << ".\n";
        break; // exit case if position is invalid
    }

    Song newSong(name, artist, length); 
    playlist.insert(newSong, position - 1); 
    cout << "Added " << name << " at position " << position << " in the playlist\n";
    break; // exit case 1
}
    
    case 2: {
 
    unsigned int position; 
    cout << "Position (1 - " << playlist.size() << "): ";
    cin >> position;

    // check for valid position
    if (position < 1 || position > playlist.size() + 1){
        cout << "Invalid position. Enter a position between 1 to " << playlist.size() + 1 << ".\n";
        break;
    }
    Song removedSong = playlist.remove(position-1); 
    cout << "Removed " << removedSong.getName() << " from the playlist\n";
    break;
}
        
    case 3:{
    unsigned int pos1, pos2;
    cout << "Swap songs at position (1 to " << playlist.size() << "): ";
    cin >> pos1; 

    // check for valid first position
    if (pos1 < 1 || pos1 > playlist.size()){
    cout << "Invalid position. enter a position between 1 and " << playlist.size() << ".\n";
    break; // exit case for invald postion
    }

    cout << "with the song at position (1 to " << playlist.size() << "): ";
    cin >> pos2; // get second position for swapping

    // check for validity
    if (pos2 < 1 || pos2 > playlist.size() || pos1 == pos2){
        cout << "Invalid position. Enter a position between 1 and " << playlist.size() << "\n";
        break; // exit if invalid
    }
        playlist.swap(pos1 - 1, pos2 - 1); // swap.
        cout << "Swapped the songs at position " << pos1 << " and " << pos2 << "\n";
        break;
}
            
    case 4:{
   
    if (playlist.size()== 0){
        cout << "Playlist is empty.\n";
    } else{
      for (unsigned int i = 0; i < playlist.size(); ++i){ 
        Song song = playlist.get(i); 
        cout << (i + 1) << " " << song.getName() << " (" << song.getArtist() << ") " 
        << song.getLength() << "s\n"; 
        }
        cout << "There are " << playlist.size() << " songs in the playlist.\n";
    }
    break; 
}
    case 5:
    cout << "You quit the program, Goodbye.\n";
    break; 
    }
}
    return 0; // end of program
}