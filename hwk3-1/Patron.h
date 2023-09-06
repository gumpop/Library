/* 
* CSCE 1040 Homework 3 
* Section: 001
* Name: Mallorie Mackay
* UNT Email: malloriemackay@my.unt.edu
* Date submitted: 4/25/22
 
*File name: Patron.h
*Description:  Header file for Patron.cpp 
*/ 

#ifndef PATRON_H
#define PATRON_H
#include <string>
#include <iostream>
using namespace std;

class Patron{
   public:
      Patron();
      Patron(string n, int ID);
      Patron(string n, int ID, double fB, int nB);
      string getName();
      void setName(string n);
      int getIDNum();
      void setIDNum(int ID);
      double getFineBalance();
      void setFineBalance(double fB);
      int getNumBooks();
      void setNumBooks(int nB);
      void print();
   private:
      string name;
      int IDNum;
      double fineBalance;
      int numBooks;
};

#endif