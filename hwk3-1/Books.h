/* 
* CSCE 1040 Homework 3 
* Section: 001
* Name: Mallorie Mackay
* UNT Email: malloriemackay@my.unt.edu
* Date submitted: 4/25/22
 
*File name: Books.h
*Description:  header file for Books.cpp
*/  

#ifndef BOOKS_H
#define BOOKS_H
#include <string>
#include "Book.h"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class Books{
   public:
      Books();
      void store();
      void load();
      int searchBooks(int num);
      void addBook();
      void editBook();
      void deleteBook();
      void printAll();
      void printOne();
      void printOne(int id);
      void updateBookStatus(int ind, char status);
      char getBookStatus(int ind);
      double getBookCost(int ind);
   private:
      int count;
      vector<Book> bookList;
};

#endif