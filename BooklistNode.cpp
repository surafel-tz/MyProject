#include<iostream>
#include<string>

#include "BooklistNode.h"

//Default constructor
BooklistNode::BooklistNode() {
    bookName = "none";
    authorName = "none";
    yearPublished = 0;
    nextNodePtr = nullptr;
}

//Constructor with args
BooklistNode::BooklistNode(string initBookName, string initAuthorName, int yearPublished, BooklistNode* nextLoc =0) {
    bookName = initBookName;
    authorName = initAuthorName;
    this->yearPublished = yearPublished;
    nextNodePtr = nextLoc;
}

//Destructor
BooklistNode::~BooklistNode() {
  
}

//Setting the next pointer reference
void BooklistNode::SetNext(BooklistNode *nodePtr) {
  nextNodePtr = nodePtr;
}

//Getter for book name
string BooklistNode::GetBookName() const {
  return bookName;
}

//Getter for author name
string BooklistNode::GetAuthorName() const {
  return authorName;
}

//Getter for year published
int BooklistNode::GetYearPublished() const {
  return yearPublished;
}

//Getter for next pointer
BooklistNode *BooklistNode::GetNext() {
  return nextNodePtr;
}

//Print the booklist data
string BooklistNode::PrintBooklistNode() {
  string str = "";

  str += bookName + "\n";
  str += "Author Name: " + authorName + "\n";
  str += "Year Published: " + to_string(yearPublished) + "\n";

  return str;
}