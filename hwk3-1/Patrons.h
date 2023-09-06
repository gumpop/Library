/* 
* CSCE 1040 Homework 3 
* Section: 001
* Name: Mallorie Mackay
* UNT Email: malloriemackay@my.unt.edu
* Date submitted: 4/25/22
 
*File name: Patrons.h
*Description:  Header file for patrons.cpp
*/ 

#ifndef PATRONS_H
#define PATRONS_H
#include <string>
#include <vector>
#include "Patron.h"
#include <iostream>
#include <fstream>
using namespace std;

class Patrons{
   public:
      Patrons();
      void store();
      void load();
      int searchPatrons(int num);
      void addPatron();
      void editPatron();
      void deletePatron();
      void printAll();
      void printPatron();
      void payFines();
      void updatePatronBC(int ind, int add);
      int getNumBooks(int ind);
      void addToBalance(int ind, double fB);
   private:
      int count;
      vector<Patron> patronList;
};

#endif