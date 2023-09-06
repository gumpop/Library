/* 
* CSCE 1040 Homework 3 
* Section: 001
* Name: Mallorie Mackay
* UNT Email: malloriemackay@my.unt.edu
* Date submitted: 4/25/22
 
*File name: Loans.h
*Description:  header file for loans.cpp 
*/ 

#ifndef LOANS_H
#define LOANS_H
#include "Patrons.h"
#include <string>
#include "Loan.h"
#include "Books.h"
#include <vector>
#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;

class Loans{
   public:
      Loans();
      void store();
      void load();
      int searchLoans(int num);
      int searchByPatron(int id);
      void addLoan(int lID, int bID, int pID);
      void editLoan();
      void deleteLoan(Books& b, Patrons& p);
      void deleteLoan(Books& b);
      void printAll();
      void printLoan();
      void checkOutBook(Books& b, Patrons& p);
      void updateLoan(int ID);
      void checkInBook(Books& b, Patrons& p);
      void listOverdue();
      bool checkOverdue(int id);
      void listBooksForPatron(Books& b);
      void recheckBook();
      void reportLost(Books& b, Patrons& p);
   private:
      int count;
      vector<Loan> loanList;
};

#endif