/* 
* CSCE 1040 Homework 3 
* Section: 001
* Name: Mallorie Mackay
* UNT Email: malloriemackay@my.unt.edu
* Date submitted: 4/25/22
 
*File name: books.cpp
*Description:  collects books, and stores this data in a file. can be created from a file. can search through books, and contains sub menus and/or ways to check out books, check in books, edit books, delete books, and ways to print all or one book. Has 2 get functions based on index of book to be accessed by loans and 1 set function of a similar nature
*/ 

#include "Books.h"

Books::Books(){
  count=0;
}
void Books::store(){
  ofstream out("Books.dat", ios::trunc);
  for(int x=0; x<bookList.size(); x++)
    {
      if(x==bookList.size()-1)
      {
        out<<bookList.at(x).getAuthor()<<endl;
        out<<bookList.at(x).getTitle()<<endl;
        out<<bookList.at(x).getISBNNum()<<endl;
        out<<bookList.at(x).getLibIDNum()<<endl;
        out<<bookList.at(x).getCost()<<endl;
        out<<bookList.at(x).getStatus();
      }
      else{
        out<<bookList.at(x).getAuthor()<<endl;
        out<<bookList.at(x).getTitle()<<endl;
        out<<bookList.at(x).getISBNNum()<<endl;
        out<<bookList.at(x).getLibIDNum()<<endl;
        out<<bookList.at(x).getCost()<<endl;
        out<<bookList.at(x).getStatus()<<endl;
      }
    }
}
void Books::load(){
  ifstream in;
  in.open("Books.dat");
  if (in.fail())
	{
		cout<<"File error. Please make sure a file named \"Patrons.dat\" is included."<<endl;
		exit(1);
	}
  int c=0;
  while(!in.eof())
    {
      string author;
      string title;
      int ISBNNum;
      int libIDNum;
      double cost;
      char status;
      getline(in, author);
      getline(in, title);
      string temp;
      getline(in, temp);
      ISBNNum=stoi(temp);
      getline(in, temp);
      libIDNum=stoi(temp);
      getline(in, temp);
      string::size_type sz;
      cost=stod(temp, &sz);
      getline(in, temp);
      status=temp[0];
      //in.ignore(4, '\n');
      bookList.emplace_back(author, title, ISBNNum, libIDNum, cost, status);
      c++;
    }
  in.close();
  count=c;
}
int Books::searchBooks(int num){
  for(int x=0; x<count; x++)
    {
      if(bookList.at(x).getISBNNum()==num)
      {
        return x;
      }
    }
  return -1;
}
void Books::addBook(){
  string author;
  string title;
  int isbn;
  int libID;
  double cost;
  cout<<"Please enter the following for the book you would like to add:"<<endl<<"Author: ";
  cin.ignore();
  getline(cin, author);
  cout<<"Title: ";
  getline(cin, title);
  cout<<"ISBN number: ";
  cin>>isbn;
  cout<<"Library ID number: ";
  cin>>libID;
  cout<<"Cost: ";
  cin>>cost;
  //Book temp(author,title,isbn,libID,cost);
  bookList.emplace_back(author,title,isbn,libID,cost);
  count++;
  store();
}
void Books::editBook(){
  int ISBN;
  int ind;
  cout<<"Please enter the ISBN number of the book you would like to edit: ";
  cin>>ISBN;
  ind=searchBooks(ISBN);
  if(ind==-1)
  {
    cout<<"Book does not exist. Returning to main menu."<<endl;
    return;
  }
  cout<<"What would you like to edit (enter corresponding number):\n";
  cout<<"1. Author\n2. Title\n3. ISBN Number\n4. Library ID\n5. Cost\n6. Status\n";
  int c;
  cin>>c;
  if(c==1)
  {
    string author;
    cout<<"Enter author: ";
    cin.ignore();
    getline(cin, author);
    bookList.at(ind).setAuthor(author);
    cout<<"Author changed. Returning to main menu."<<endl;
  }
  else if(c==2)
  {
    string title;
    cin.ignore();
    cout<<"Enter title: ";
    getline(cin, title);
    bookList.at(ind).setTitle(title);
    cout<<"Title changed. Returning to main menu."<<endl;
  }
  else if(c==3)
  {
    int isbn;
    cout<<"Enter ISBN: ";
    cin>>isbn;
    bookList.at(ind).setISBNNum(isbn);
    cout<<"ISBN changed. Returning to main menu."<<endl;
  }
  else if(c==4)
  {
    int libID;
    cout<<"Enter Library ID: ";
    cin>>libID;
    bookList.at(ind).setLibIDNum(libID);
    cout<<"Library ID changed. Returning to main menu."<<endl;
  }
  else if(c==5)
  {
    double cost;
    cout<<"Enter cost: ";
    cin>>cost;
    bookList.at(ind).setCost(cost);
    cout<<"Cost changed. Returning to main menu."<<endl;
  }
  else if(c==6)
  {
    char status;
    cout<<"If book is being repaired, enter 'r', if book is being returned from repair, enter 'i': ";
    cin>>status;
    if(status!='i'&&status!='r') 
    {
      cout<<"Invalid status, returning to main menu."<<endl;
      return;
    }
    bookList.at(ind).setStatus(status);
    cout<<"Status changed. Returning to main menu."<<endl;
  }
  else
  {
    cout<<"Invalid choice. Returning to main menu.";
  }
  store();
}
void Books::deleteBook(){
  int ISBN;
  int ind;
  cout<<"Please enter the ISBN number of the book you would like to delete: ";
  cin>>ISBN;
  ind=searchBooks(ISBN);
  if(ind==-1)
  {
    cout<<"Book does not exist. Returning to main menu."<<endl;
    return;
  }
  if(bookList.at(ind).getStatus()=='o')
  {
    cout<<"Book is currently checked out. Please report lost instead within the main menu"<<endl;
    return;
  }
  bookList.erase(bookList.begin()+ind);
  cout<<"Book deleted. Returning to main menu."<<endl;
  count--;
  store();
}
void Books::printAll(){
  for(int x=0; x<count; x++)
    {
      cout<<"#"<<x+1<<endl;
      bookList.at(x).print();
      cout<<endl;
    }
}
void Books::printOne(){
  int ISBN;
  int ind;
  cout<<"Please enter the ISBN number of the book you would like to print: ";
  cin>>ISBN;
  ind=searchBooks(ISBN);
  if(ind==-1)
  {
    cout<<"Book does not exist. Returning to main menu."<<endl;
    return;
  }
  bookList.at(ind).print();
}
void Books::printOne(int id){
  int ISBN=id;
  int ind;
  ind=searchBooks(ISBN);
  bookList.at(ind).print();
}
void Books::updateBookStatus(int ind, char status){
  bookList.at(ind).setStatus(status);
  store();
}
char Books::getBookStatus(int ind){
  return bookList.at(ind).getStatus();
}
double Books::getBookCost(int ind){
  return bookList.at(ind).getCost();
}