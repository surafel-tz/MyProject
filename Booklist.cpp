#include "Booklist.h"


//Default constructor
Booklist::Booklist() {
  head = nullptr;
  tail = nullptr;
}

//Destructor
Booklist::~Booklist() {
  
  while(head != nullptr) {
  
    BooklistNode *next = head->GetNext();    //Pointer to the next node
    delete head;                             //Deleting the allocated memory
    head = next;                             //Moving to the next node
  }

  //Setting the tail to null as the list is now empty
  head = tail = nullptr;
}

//Inserting a new book to the list
bool Booklist::add(string name, string artist, int yearPublished) {

  //Duplicate book not allowed
  if(found(name))
    return false;
  
  // Create a new node
  BooklistNode *newNode = new BooklistNode(name, artist, yearPublished);
  
  if (head == nullptr) {
    head = newNode; // If the list is empty, the new node is the head
    tail = newNode; // Set tail to the new node
    return true;
  } else {
    tail->SetNext(newNode);  // If the list is not empty, the new node is set to the tail
    tail = newNode; // Set tail to the last node
    return true;
  }
}

//Search the list for a book
BooklistNode* Booklist::found(string bookName) {
  
  //Create a temporary node to traverse the list
  BooklistNode* curr = head;

  while(curr != nullptr) {       //Traverse the list while the current pointer node is not null
    if(curr->GetBookName() == bookName)    //If current node's book name is found
      return curr;                         //Return the current node

    curr = curr->GetNext();                //Moving to the next node
  }
  
  //Book not found
  return nullptr;
}

// Remove a book from the list
bool Booklist::remove(string bookName) {

  // Create a temp node
  BooklistNode *nodePtr;
  // Create a pointer for the previous node
  BooklistNode *previous;

  // If the list is empty, return false
  if (head == nullptr)
    return false;
  else {
    // Determine if the first node is the book to be removed
    if (head->GetBookName() == bookName) {
      nodePtr = head->GetNext();
      delete head;
      head = nodePtr;
      return true;
    } else {

        // Initialize nodePtr to head of list
        nodePtr = head;

        // Traverse the list until the book is found
        while (nodePtr != nullptr && nodePtr->GetBookName() != bookName) {

        // Keep track of the previous node and moving to the next node
        previous = nodePtr;
        nodePtr = nodePtr->GetNext();
      }

      // If the book is found, remove book
      if (nodePtr) {
        //Setting the previous node's next pointer to the node after the current node
        previous->SetNext(nodePtr->GetNext());
        delete nodePtr;
        
        //If the removed book is the tail, update tail to the previous node
        if(previous->GetNext() == nullptr)
          tail = previous;

        return true;
      }
    }
  }
  //Book not found
  return false;
}

// Moving the named book to the top of the list
bool Booklist::moveFront(string bookName) {

  BooklistNode *nodePtr = found(bookName); // Searching for the book
  BooklistNode *previous = head;

  // If the book is not found, return false
  if (nodePtr == nullptr)
    return false;
  
  // If the book is found, move it to the front of the list
  if (nodePtr == head)
    return false;
  else {
    // Remove node containing the found book from its position
    previous->SetNext(nodePtr->GetNext());

    // Move the found book to the front of the list
    nodePtr->SetNext(head);
    head = nodePtr;

    // If the book is at the tail, update the tail
    if (nodePtr == tail)
      tail = previous;

    return true;
  }
  
}

//This method displays the book/s this author have published
string Booklist::displayAuthor(string authorName) {

  string str = "";
  int count = 0;
  BooklistNode *curr = head;

  //Going through the list to find the author's book/s
  while(curr != nullptr) {
    if(curr->GetAuthorName() == authorName) {
      count++;
      str += to_string(count) + "\n";
      str += curr->PrintBooklistNode() + "\n";
    }
    //Moving to the next list
    curr = curr->GetNext();
  }
  return str;
}

//Count the number of books in the list
int Booklist::totalBooks() {

  int count = 0;             //Counter for the number of books
  BooklistNode *curr = head; //Create a temporary node to traverse the list

  //Count the number of books
  while(curr != nullptr) {
    count++;
    curr = curr->GetNext();
  }

  return count;
}

//This functions displays all the books in the list
string Booklist::displayList() {
  
  string str = "";    //To store the book list
  int count = 0;      //Counter for each list
  BooklistNode *curr = head; //Create a temporary node to traverse the list
  
  //Traverse the list and display each book
  while(curr != nullptr) {
    count++;
    str +="\n" + to_string(count) + ".\n";
    str += curr->PrintBooklistNode() + "\n";
    curr = curr->GetNext();
  }
  return str;
}

//Return the head of the list
BooklistNode* Booklist::getHead() {
  return head;
}

//Return the tail of the list
BooklistNode* Booklist::getTail() {
  return tail;
}