/* 
* CSCE 1040 Homework 3 
* Section: 001
* Name: Mallorie Mackay
* UNT Email: malloriemackay@my.unt.edu
* Date submitted: 4/25/22
 
*File name: Patrons.cpp
*Description:  collects patrons, reads in from file and prints to a file, can add, edit, or remove a patron. can print one or all patrons. can pay fines for a certain patron. has some set/get functions that take in an index to be used by loans.cpp
*/ 

#include "Patrons.h"

Patrons::Patrons(){
  count=0;
}
void Patrons::store(){
  ofstream out("Patrons.dat", ios::trunc);
  for(int x=0; x<patronList.size(); x++)
    {
      if(x==patronList.size()-1)
      {
        out<<patronList.at(x).getName()<<endl;
        out<<patronList.at(x).getIDNum()<<endl;
        out<<patronList.at(x).getFineBalance()<<endl;
        out<<patronList.at(x).getNumBooks();
      }
      else{
        out<<patronList.at(x).getName()<<endl;
        out<<patronList.at(x).getIDNum()<<endl;
        out<<patronList.at(x).getFineBalance()<<endl;
        out<<patronList.at(x).getNumBooks()<<endl;
      }
      
    }
  out.close();
}
void Patrons::load(){
  ifstream in;
  in.open("Patrons.dat");
  if (in.fail())
	{
		cout<<"File error. Please make sure a file named \"Patrons.dat\" is included."<<endl;
		exit(1);
	}
  int c=0;
  while(!in.eof())
    {
      string name;
      int IDNum;
      double fineBalance;
      int numBooks;
      string temp;
      string::size_type sz;
      getline(in, name);
      getline(in, temp);
      IDNum=stoi(temp);
      getline(in, temp);
      fineBalance=stod(temp, &sz);
      getline(in, temp);
      numBooks=stoi(temp);
      patronList.emplace_back(name, IDNum, fineBalance, numBooks);
      c++;
    }
  in.close();
  count=c;
}
int Patrons::searchPatrons(int num){
  for(int x=0; x<count; x++)
    {
      if(patronList.at(x).getIDNum()==num)
      {
        return x;
      }
    }
  return -1;
}
void Patrons::addPatron(){
  string name;
  int IDNum;
  double fineBalance;
  cout<<"Please enter the following for the patron you would like to add:"<<endl<<"Name: ";
  cin.ignore();
  getline(cin, name);
  cout<<"ID number: ";
  cin>>IDNum;
  patronList.emplace_back(name,IDNum);
  count++;
  store();
}
void Patrons::editPatron(){
  int id;
  int ind;
  cout<<"Please enter the ID number of the patron you would like to edit: ";
  cin>>id;
  ind=searchPatrons(id);
  if(ind==-1)
  {
    cout<<"Patron does not exist. Returning to main menu."<<endl;
    return;
  }
  cout<<"What would you like to edit (enter corresponding number):\n";
  cout<<"1. Name\n2. ID number\n";
  int c;
  cin>>c;
  if(c==1)
  {
    cout<<"Enter name: ";
    string name;
    cin.ignore();
    getline(cin, name);
    patronList.at(ind).setName(name);
    cout<<"Name changed. Returning to main menu"<<endl;
  }
  else if(c==2)
  {
    cout<<"Enter ID: ";
    int id;
    cin>>id;
    patronList.at(ind).setIDNum(id);
    cout<<"ID changed. Returning to main menu"<<endl;
  }
  else
  {
    cout<<"Invalid choice. Returning to main menu."<<endl;
  }
  store();
}
void Patrons::deletePatron(){
  cout<<"Please enter the ID of the patron you would like to delete: ";
  int id;
  int ind;
  cin>>id;
  ind=searchPatrons(id);
  if(ind==-1)
  {
    cout<<"Patron does not exist. Returning to the main menu."<<endl;
    return;
  }
  if(patronList.at(ind).getNumBooks()>0)
  {
    cout<<"Patron still has loans taken out. Please clear the loans before deleting this patron."<<endl;
    return;
  }
  patronList.erase(patronList.begin()+ind);
  cout<<"Patron has been deleted. Returning to main menu"<<endl;
  count--;
  store();
}
void Patrons::printAll(){
  for(int x=0; x<count; x++)
    {
      cout<<"#"<<x+1<<endl;
      patronList.at(x).print();
      cout<<endl;
    }
}
void Patrons::printPatron(){
  int id;
  int ind;
  cout<<"Please enter the ID number of the patron to print: ";
  cin>>id;
  ind=searchPatrons(id);
  if(ind==-1)
  {
    cout<<"Patron does not exist. Returning to main menu."<<endl;
    return;
  }
  patronList.at(ind).print();
}
void Patrons::payFines(){
  int id;
  int ind;
  cout<<"Please enter the ID number of the patron paying: ";
  cin>>id;
  ind=searchPatrons(id);
  if(ind==-1)
  {
    cout<<"Patron does not exist. Returning to main menu."<<endl;
    return;
  }
  cout<<"Please enter the ammount the patron has paid: ";
  double paid;
  cin>>paid;
  patronList.at(ind).setFineBalance(patronList.at(ind).getFineBalance()-paid);
  cout<<"Transaction complete, returning to main menu."<<endl;
  store();
}
void Patrons::updatePatronBC(int ind, int add)
{
  int numBook=patronList.at(ind).getNumBooks()+add;
  patronList.at(ind).setNumBooks(numBook);
  store();
}
int Patrons::getNumBooks(int ind)
{
  return patronList.at(ind).getNumBooks();
}
void Patrons::addToBalance(int ind, double fB)
{
  patronList.at(ind).setFineBalance(fB);
  store();
}