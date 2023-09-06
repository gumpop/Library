/*
* CSCE 1040 Homework 3
* Section: 001
* Name: Mallorie Mackay
* UNT Email: malloriemackay@my.unt.edu
* Date submitted: 4/25/22

*File name: Patron.cpp
*Description:  creates patrons, and acesses all variables of a patrons. prints
patrons.
*/

#include "Patron.h"

Patron::Patron() {
  name = "";
  IDNum = 0;
  fineBalance = 0;
  numBooks = 0;
}
Patron::Patron(string n, int ID) {
  name = n;
  IDNum = ID;
  fineBalance = 0;
  numBooks = 0;
}
Patron::Patron(string n, int ID, double fB, int nB) {
  name = n;
  IDNum = ID;
  fineBalance = fB;
  numBooks = nB;
}
string Patron::getName() { return name; }
void Patron::setName(string n) { name = n; }
int Patron::getIDNum() { return IDNum; }
void Patron::setIDNum(int ID) { IDNum = ID; }
double Patron::getFineBalance() { return fineBalance; }
void Patron::setFineBalance(double fB) { fineBalance = fB; }
int Patron::getNumBooks() { return numBooks; }
void Patron::setNumBooks(int nB) { numBooks = nB; }
void Patron::print() {
  cout << "\nPATRON INFO" << endl;
  cout << "Name: " << name << endl;
  cout << "ID: " << IDNum << endl;
  cout << "Fine balance: $" << fineBalance << endl;
  cout << "Number of books out: " << numBooks << endl;
}