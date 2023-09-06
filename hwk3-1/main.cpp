/*
* CSCE 1040 Homework 3
* Section: 001
* Name: Mallorie Mackay
* UNT Email: malloriemackay@my.unt.edu
* Date submitted: 4/25/22

*File name: main.cpp
*Description: my main function holds the menu to access all other functions, and
checks if files are empty before loading
*/

#include "Book.h"
#include "Books.h"
#include "Loan.h"
#include "Loans.h"
#include "Patron.h"
#include "Patrons.h"
#include <iostream>
using namespace std;
// access all book functions
void booksMenu(Books &b) {
  cout << "\nWhich would you like to do?\n";
  cout << "1. add a book\n2. edit a book\n3. delete a book\n4. print all "
          "books\n5. print a book\n6. exit"
       << endl;
  int c;
  cin >> c;
  if (c == 1) {
    b.addBook();
  } else if (c == 2) {
    b.editBook();
  } else if (c == 3) {
    b.deleteBook();
  } else if (c == 4) {
    b.printAll();
  } else if (c == 5) {
    b.printOne();
  } else if (c == 6)
    return;
  else
    cout << "Invalid choice. Returning to main menu.";
};
// access all patron functions
void patronsMenu(Patrons &p) {
  cout << "\nWhich would you like to do?\n";
  cout << "1. add a patron\n2. edit a patron\n3. delete a patron\n4. print all "
          "patrons\n5. print a patron\n6. pay fines\n7. exit"
       << endl;
  int c;
  cin >> c;
  if (c == 1) {
    p.addPatron();
  } else if (c == 2) {
    p.editPatron();
  } else if (c == 3) {
    p.deletePatron();
  } else if (c == 4) {
    p.printAll();
  } else if (c == 5) {
    p.printPatron();
  } else if (c == 6) {
    p.payFines();
  } else if (c == 7)
    return;
  else
    cout << "Invalid choice. Returning to main menu.";
};
// access all loan functions
void loansMenu(Books &b, Loans &l, Patrons &p) {
  cout << "\nWhich would you like to do?\n";
  cout << "1. check out a book\n2. check in a book\n3. recheck book\n4. report "
          "lost\n5. list overdue\n6. list books for a patron\n7. print all "
          "loans\n8. print a loan\n9. quit"
       << endl;
  int c;
  cin >> c;
  if (c == 1) {
    l.checkOutBook(b, p);
  } else if (c == 2) {
    l.checkInBook(b, p);
  } else if (c == 3) {
    l.recheckBook();
  } else if (c == 4) {
    l.reportLost(b, p);
  } else if (c == 5) {
    l.listOverdue();
  } else if (c == 6) {
    l.listBooksForPatron(b);
  } else if (c == 7) {
    l.printAll();
  } else if (c == 8) {
    l.printLoan();
  } else if (c == 9)
    return;
  else
    cout << "Invalid choice. Returning to main menu.";
};
// print out 3 menu types
void printmenu(Books &b, Loans &l, Patrons &p) {
  int menu;
  do {
    cout << "\nPlease choose a menu: \n";
    cout << "1. Books\n2. Patrons\n3. Loans\n4. exit" << endl;
    cin >> menu;
    if (menu == 1) {
      booksMenu(b);
    } else if (menu == 2) {
      patronsMenu(p);
    } else if (menu == 3) {
      loansMenu(b, l, p);
    } else if (menu > 4) {
      cout << "\nInvalid choice. Please try again." << endl;
    }

  } while (menu != 4);
};
int main() {
  Books b;
  Loans l;
  Patrons p;
  ifstream in;
  // load all data in
  b.load();

  in.open("Loans.dat");
  string temp;
  getline(in, temp);
  if (temp != "") {
    l.load();
  }
  in.close();
  in.open("Patrons.dat");
  getline(in, temp);
  if (temp != "") {
    p.load();
  }
  in.close();
  // p.load();
  // open up menu
  printmenu(b, l, p);
  return 0;
}