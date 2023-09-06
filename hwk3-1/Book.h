/* 
* CSCE 1040 Homework 3 
* Section: 001
* Name: Mallorie Mackay
* UNT Email: malloriemackay@my.unt.edu
* Date submitted: 4/25/22
 
*File name: book.h 
*Description:  header for book.cpp
*/ 

#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <iostream>
using namespace std;

class Book{
   public:
      Book();
      Book(string a, string t, int isbn, int libID, double c);
      Book(string a, string t, int isbn, int libID, double c, char s);
      string getAuthor();
      void setAuthor(string a);
      string getTitle();
      void setTitle(string t);
      int getISBNNum();
      void setISBNNum(int isbn);
      int getLibIDNum();
      void setLibIDNum(int libID);
      double getCost();
      void setCost(double c);
      char getStatus();
      void setStatus(char s);
      void print();
      
   private:
      string author;
      string title;
      int ISBNNum;
      int libIDNum;
      double cost;
      char status;
};

#endif