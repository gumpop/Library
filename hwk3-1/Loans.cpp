/* 
* CSCE 1040 Homework 3 
* Section: 001
* Name: Mallorie Mackay
* UNT Email: malloriemackay@my.unt.edu
* Date submitted: 4/25/22
 
*File name: Loans.cpp
*Description: stores loans, reads in from files, and prints to files. checks out books, checks in books, rechecks, reports books lost, and updates the overdue status of a loan. prints all books for a patron, and prints all loans, as well as printing a single loan based on the ID. operates with ctime to see which books are overdue, and what a recheck loan period will look like. interacts with both patrons and books to update them accordingly 
*/ 

#include "Loans.h"


Loans::Loans(){
  count=0;
}
void Loans::store(){
  ofstream out;
  out.open("Loans.dat");
  for(int x=0; x<loanList.size(); x++)
    {
      if(x==loanList.size()-1)
      {
        out<<loanList.at(x).getLoanID()<<endl;
        out<<loanList.at(x).getBookID()<<endl;
        out<<loanList.at(x).getPatronID()<<endl;
        out<<loanList.at(x).getDueDT()<<endl;
        out<<loanList.at(x).getStatus()<<endl;
        out<<loanList.at(x).getRecheck();
      }
      else{
        out<<loanList.at(x).getLoanID()<<endl;
        out<<loanList.at(x).getBookID()<<endl;
        out<<loanList.at(x).getPatronID()<<endl;
        out<<loanList.at(x).getDueDT()<<endl;
        out<<loanList.at(x).getStatus()<<endl;
        out<<loanList.at(x).getRecheck()<<endl;
      }
    }
}
void Loans::load(){
  ifstream in;
  in.open("Loans.dat");
  if (in.fail())
	{
		cout<<"File error. Please make sure a file named \"Loans.dat\" is included."<<endl;
		exit(1);
	}
  int c=0;
  while(!in.eof())
    {
      int loanID;
      int bookID;
      int patronID;
      time_t dueDT;
      bool status;
      bool recheck;
      string temp;
      getline(in, temp);
      loanID=stoi(temp);
      getline(in, temp);
      bookID=stoi(temp);
      getline(in, temp);
      patronID=stoi(temp);
      getline(in, temp);
      dueDT=stoi(temp);
      getline(in, temp);
      if(temp=="1") status=true;
      else status=false;
      getline(in, temp);
      if(temp=="1") recheck=true;
      else recheck=false;
      loanList.emplace_back(loanID, bookID, patronID, dueDT, status, recheck);
      c++;
    }
  in.close();
  count=c;
}
int Loans::searchLoans(int num){
  for(int x=0; x<count; x++)
    {
      if(loanList.at(x).getLoanID()==num)
      {
        return x;
      }
    }
  return -1;
}
int Loans::searchByPatron(int id){
  for(int x=0; x<count; x++)
    {
      if(loanList.at(x).getPatronID()==id)
      {
        return x;
      }
    }
  return -1;
}
void Loans::addLoan(int lID, int bID, int pID){
  loanList.emplace_back(lID, bID, pID);
  count++;
  store();
}
void Loans::printAll(){
  for(int x=0; x<count; x++)
    {
      cout<<"#"<<x+1<<endl;
      loanList.at(x).print();
      cout<<endl;
    }
}
void Loans::printLoan(){
  int id;
  int ind;
  cout<<"Please enter the ID number of the Loan to print: ";
  cin>>id;
  ind=searchLoans(id);
  if(ind==-1)
  {
    cout<<"Loan does not exist. Returning to main menu."<<endl;
    return;
  }
  loanList.at(ind).print();
}
void Loans::checkOutBook(Books& b, Patrons& p){
  cout<<"Please enter the ID of the patron taking out the loan: ";
  int pID;
  cin>>pID;
  int pInd=p.searchPatrons(pID);
  if(pInd==-1)
  {
    cout<<"Patron does not exist. Returning to main menu."<<endl;
    return;
  }
  if(checkOverdue(pID))
  {
    cout<<"Patron has overdue books, and is unable to check out a new one. Returning to main menu."<<endl; 
    return;
  }
  if(p.getNumBooks(pInd)>5)
  {
    cout<<"Patron has too many books out, and is unable to check out a new one. Returning to main menu."<<endl;
    return;
  }
  cout<<"Please enter the ID of the book being checked out: ";
  int bID;
  cin>>bID;
  int bInd=b.searchBooks(bID);
  if(bInd==-1)
  {
    cout<<"Book does not exist. Returning to main menu."<<endl;
    return;
  }
  if(b.getBookStatus(bInd)!='i')
  {
    cout<<"Book is not currently availible for checkout. Returning to main menu"<<endl;
    return;
  }
  cout<<"Please enter the loan ID: ";
  int ID;
  cin>>ID;
  loanList.emplace_back(ID, bID, pID);
  p.updatePatronBC(pInd, 1);
  b.updateBookStatus(bInd, 'o');
  p.store();
  b.store();
  store();
  count++;
}
void Loans::updateLoan(int ID){
  //compare curent time to the time indicated in loan
  time_t currTime= time(0);
  double tIS=difftime(currTime, loanList.at(searchLoans(ID)).getDueDT());
  //divide the difference by 60 to get mins, then by 60 for hrs, then by 24
  //concat that number and check if it is greater than 10
  int days=(((tIS/60)/60)/24);
  
  if(days>10)
  {
    loanList.at(searchLoans(ID)).setStatus(true); //set the overdue to true
  }
  store();
}
void Loans::checkInBook(Books& b, Patrons& p){
  cout<<"Please enter the loan ID: ";
  int ID;
  cin>>ID;
  int ind=searchLoans(ID);
  if(ind==-1)
  {
    cout<<"Loan does not exist, returning to main menu."<<endl;
  }
  int pID=loanList.at(ind).getPatronID();
  int bID=loanList.at(ind).getBookID();
  int pInd=p.searchPatrons(pID);
  int bInd=b.searchBooks(bID);
  p.updatePatronBC(pInd, -1);
  b.updateBookStatus(bID, 'i');
  updateLoan(ID);
  if(loanList.at(ind).getStatus())
  {
      //compare curent time to the time indicated in loan
    time_t currTime= time(0);
    double tIS=difftime(currTime, loanList.at(searchLoans(ID)).getDueDT());
    //divide the difference by 60 to get mins, then by 60 for hrs, then by 24
    //concat that number and check if it is greater than 10
    int days=(((tIS/60)/60)/24);
    double fineAmmount=days*0.25;
    cout<<"The book is overdue and the patron has been charged accordingly.";
    p.addToBalance(pInd, fineAmmount);
  }
  loanList.erase(loanList.begin()+ind);
  p.store();
  b.store();
  count--;
  store();
}
void Loans::listOverdue(){
  for(int x=0; x<count; x++)
    {
      if(loanList.at(x).getStatus())
      {
        loanList.at(x).print();
      }
    }
}
bool Loans::checkOverdue(int id){
  for(int x=0; x<count; x++)
    {
      if(loanList.at(x).getPatronID()==id)
      {
        if(loanList.at(x).getStatus())
        {
          return true;
        }
      }
    }
  return false;
}
void Loans::listBooksForPatron(Books& b){
  cout<<"Please enter patron ID: ";
  int pID;
  int c=0;
  for(int x=0; x<count; x++)
    {
      if(loanList.at(x).getPatronID()==pID)
      {
        cout<<"\nPrinting book #"<<c+1<<endl;
        b.printOne(loanList.at(x).getBookID());
        c++;
      }
    }
  cout<<endl;
  if(c==0) 
  {
    cout<<"No books for patron, returning to main menu."<<endl;
    return;
  }
}
void Loans::recheckBook(){
  cout<<"Please enter Loan ID to recheck: ";
  int id;
  cin>>id;
  int ind=searchLoans(id);
  if(ind==-1)
  {
    cout<<"Loan does not exist, returning to main menu"<<endl;
    return;
  }
  if(loanList.at(ind).getRecheck()==true)
  {
    cout<<"This book has already been rechecked. returning to main menu"<<endl;
    return;
  }
  loanList.at(ind).setRecheck(true);
  //add 10*24*60*60 to the current time_t
  time_t newDD= loanList.at(ind).getDueDT() + (10*24*60*60) ;
  loanList.at(ind).setDueDT(newDD);
  store();
}
void Loans::reportLost(Books& b, Patrons& p){
  cout<<"Enter the ID of the loan the lost book is under: ";
  int id;
  cin>>id;
  int ind=searchLoans(id);
  b.updateBookStatus(b.searchBooks(loanList.at(ind).getBookID()), 'l');
  p.addToBalance(p.searchPatrons(loanList.at(ind).getPatronID()), b.getBookCost(b.searchBooks(loanList.at(ind).getBookID())));
  loanList.erase(loanList.begin()+ind);
  store();
}