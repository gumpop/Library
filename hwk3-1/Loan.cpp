/* 
* CSCE 1040 Homework 3 
* Section: 001
* Name: Mallorie Mackay
* UNT Email: malloriemackay@my.unt.edu
* Date submitted: 4/25/22
 
*File name: Loan.cpp
*Description: creates loans, and acesses all variables of a loan. prints loans. uses ctime to determine some variables
*/ 

#include "Loan.h"

Loan::Loan(){
  loanID=0;
  bookID=0;
  patronID=0;
  dueDT= time(0)+ (10*24*60*60);
  status=false; //false is not overdue!
  recheck=false;
}
Loan::Loan(int lID, int bID, int pID){
  loanID=lID;
  bookID=bID;
  patronID=pID;
  dueDT= time(0)+ (10*24*60*60); //current date and time +10days
  status=false;
  recheck=false;
}
Loan::Loan(int lID, int bID, int pID, time_t dD, bool s, bool rC){
  loanID=lID;
  bookID=bID;
  patronID=pID;
  dueDT= dD;
  status=s;
  recheck=rC;
}
int Loan::getLoanID(){
  return loanID;
}
void Loan::setLoanID(int lID){
  loanID=lID;
}
int Loan::getBookID(){
  return bookID;
}
void Loan::setBookID(int bID){
  bookID=bID;
}
int Loan::getPatronID(){
  return patronID;
}
void Loan::setPatronID(int pID){
  patronID=pID;
}
time_t Loan::getDueDT(){
  return dueDT;
}
void Loan::setDueDT(time_t dD){
  dueDT=dD;
}
bool Loan::getStatus(){
  return status;
}
void Loan::setStatus(bool s){
  status=s;
}
bool Loan::getRecheck(){
  return recheck;
}
void Loan::setRecheck(bool rC){
  recheck=rC;
}
void Loan::print(){
  cout<<"\nLOAN INFO"<<endl;
  cout<<"Loan ID: "<<loanID<<endl;
  cout<<"Book ID: "<<bookID<<endl;
  cout<<"Patron ID: "<<patronID<<endl;
  tm* time = localtime(&dueDT);
  cout<<"Due date and time: "<<asctime(time)<<endl;
  cout<<"Overdue status: "<<status<<endl;
  cout<<"Recheck status: "<<recheck<<endl;
}