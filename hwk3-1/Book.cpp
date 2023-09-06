/* 
* CSCE 1040 Homework 3 
* Section: 001
* Name: Mallorie Mackay
* UNT Email: malloriemackay@my.unt.edu
* Date submitted: 4/25/22
 
*File name: book.cpp
*Description:  creates books, and acesses all variables of a book. prints books
*/ 

#include "Book.h"

Book::Book(){
  author = "";
  title = "";
  ISBNNum = 0;
  libIDNum = 0;
  cost = 0.0;
  status = ' ';
}
Book::Book(string a, string t, int isbn, int libID, double c){
  author = a;
  title = t;
  ISBNNum = isbn;
  libIDNum = libID;
  cost = c;
  status = 'i';
}
Book::Book(string a, string t, int isbn, int libID, double c, char s)
{
  author = a;
  title = t;
  ISBNNum = isbn;
  libIDNum = libID;
  cost = c;
  status = s;
}
string Book::getAuthor(){
  return author;
}
void Book::setAuthor(string a){
  author=a;
}
string Book::getTitle(){
  return title;
}
void Book::setTitle(string t){
  title = t;
}
int Book::getISBNNum(){
  return ISBNNum;
}
void Book::setISBNNum(int isbn){
  ISBNNum = isbn;
}
int Book::getLibIDNum(){
  return libIDNum;
}
void Book::setLibIDNum(int libID){
  libIDNum=libID;
}
double Book::getCost(){
  return cost;
}
void Book::setCost(double c){
  cost=c;
}
char Book::getStatus(){
  return status;
}
void Book::setStatus(char s){
  status=s;
}
void Book::print(){
  cout<<"\nBOOK INFO"<<endl;
  cout<<"Author: "<<author<<endl;
  cout<<"Title: "<<title<<endl;
  cout<<"ISBN number: "<<ISBNNum<<endl;
  cout<<"Library ID number: "<<libIDNum<<endl;
  cout<<"Cost: $"<<cost<<endl;
  cout<<"Status: "<<status<<endl;
}