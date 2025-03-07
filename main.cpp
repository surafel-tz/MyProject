#include <iostream>
#include <iomanip>
#include <string>
#include "Booklist.h"
using namespace std;

void PrintMenu(const string booklistTitle) {

  char option;
  string bookName;
  string authorName;
  int yrPublished;
  Booklist *booklist = new Booklist();
  bool success = false;


  cout << "Favorites BOOKLIST MENU" << endl;
  cout << "a - Add book" << endl;
  cout << "d - Remove book" << endl;
  cout << "m - Move book to front" << endl;
  cout << "s - Output books by specific author" << endl;
  cout << "t - Output total number of  books in booklist" << endl;
  cout << "o - Output full booklist" << endl;
  cout << "q = Quit" << endl;

  cout << "\nChoose an option:" << endl;
  cin >> option;

  // Input validation
  while (option != 'a' && option != 'd' && option != 'm' && option != 's' && 
        option != 't' && option != 'o' && option != 'q') {
    cout << "Choose an option:" << endl;
    cin >> option;
  }
  
  if(option == 'a') {
    cout << "ADD BOOK" << endl;
    cout << "Enter book's name:" << endl;
    cin.ignore();
    getline(cin, bookName);
    cout << "Enter author's name:" << endl;
    getline(cin, authorName);
    cout << "Enter year published:" << endl;
    cin >> yrPublished;
    success = booklist->add(bookName, authorName, yrPublished);
    if(!success)        //If a book already exists, it is not added to the list
      cout << "This book already exists" << endl;
  }
  else if(option == 'd') {
    cout << "REMOVE BOOK" << endl;
    cout << "Enter book's name:" << endl;
    cin.ignore();
    getline(cin, bookName);
    success = booklist->remove(bookName);
    if(success)        //Show if the book is removed or not
      cout << "\"" << bookName << "\" removed" << endl;
    else
      cout << "(" << bookName << ") not in list" << endl;
  }
  else if(option == 'm') {
    cout << "MOVE BOOK TO BEGINNING" << endl;
    cout << "Enter book's name:" << endl;
    cin.ignore();
    getline(cin, bookName);
    success = booklist->moveFront(bookName);
    if(success)        //Show if the book is moved to the front or book in not in list
      cout << "\"" << bookName << "\" moved to front of list" << endl;
    else
      cout << "(" << bookName << ") not in list" << endl;
  }
  else if(option == 's') {
    cout << "OUTPUT BOOKS BY SPECIFIC AUTHOR" << endl;
    cout << "Enter author's name:" << endl;
    cin.ignore();
    getline(cin, authorName);
    booklist->displayAuthor(authorName);
  }
  else if(option == 't') {
    cout << "OUTPUT TOTAL NUMBER OF BOOKS IN BOOKLIST" << endl;
    cout << "Number of books: " << booklist->totalBooks() << " books" << endl;
  }
  else if(option == 'o') {
    cout << booklistTitle << " OUTPUT FULL PLAYLIST" << endl;
    if(booklist->totalBooks() == 0)
      cout << "Booklist is empty" << endl;
    else
      booklist->displayList();
  }
  else if(option == 'q') {
    delete booklist;
    exit(0);
  }
  
  PrintMenu(booklistTitle); 
}


int main() {
    string booklistTitle;

    // Prompt user for booklist title
    cout << "Enter booklist's title:" << endl;
    getline(cin, booklistTitle);
    cout << endl;

    // Output book list menu options
    PrintMenu(booklistTitle);

    return 0;
}

