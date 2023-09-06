/* 
* CSCE 1040 Homework 3 
* Section: 001
* Name: Mallorie Mackay
* UNT Email: malloriemackay@my.unt.edu
* Date submitted: 4/25/22
 
*File name: Loan.h
*Description: header file for Loan.cpp
*/ 

#ifndef LOAN_H
#define LOAN_H
#include <string>
#include <ctime>
#include <iostream>
using namespace std;

class Loan{
   public:
      Loan();
      Loan(int lID, int bID, int pID);
      Loan(int lID, int bID, int pID, time_t dD, bool s, bool rC);
      int getLoanID();
      void setLoanID(int lID);
      int getBookID();
      void setBookID(int bID);
      int getPatronID();
      void setPatronID(int pID);
      time_t getDueDT();
      void setDueDT(time_t dD);
      bool getStatus();
      void setStatus(bool s);
      bool getRecheck();
      void setRecheck(bool rC);
      void print();
   private:
      int loanID;
      int bookID;
      int patronID;
      time_t dueDT;
      bool status;
      bool recheck;
};

#endif