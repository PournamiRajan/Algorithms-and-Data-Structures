#include "Book.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <istream>
#include <ostream>
#include <typeinfo>
#include <cstring>

using namespace std;

// Status codes.
enum class StatusCode {OK, DUPLICATE, NOT_FOUND, INVALID_COMMAND};

/**
 * Find the book in the catalog with the given ISBN.
 * Use a binary search.
 * @param isbn the ISBN.
 * @param catalog the vector of book records.
 * @return the vector index of the book if found, else return -1.
 */
int find(const string isbn, const vector<Book>& catalog);
/**
 * Add book to the catalog
 * @param book the Book object
 * @param catalog the vector of book records.
 * @return the vector index of the book if added, else return -1.
 */
int add_book(Book& book, vector<Book> &catalog);
/**
 * To display error codes
 */
void error_display(const StatusCode code);

const string INPUT_FILE_NAME = "commands.in";

// main function

int main()
{
    // Open the input file.
    ifstream input;
    input.open(INPUT_FILE_NAME);
    if (input.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }
    vector<Book> catalog;  // book catalog

              // first command od the line
    char command;
    string line;
    string field,value;
    // Loop to read commands until the end of file.
    while (!input.eof())
    {
        input >> command;
        if(input.eof()) break;
        cout << endl << command << " ";
        //check for invalid commands
        if(command != '?' && command != '+' && command != '-')
        {
           StatusCode status = StatusCode::INVALID_COMMAND;
           error_display(status);
           getline (input, line);
        }
        
        if(command == '?') // Display command
        {
           getline (input, line);
           //cout<<"line is :"<<line<<endl;
           if(line.length() <= 2 ) // Display All
           {
              cout<<"All books in the catalog:"<<endl;
              for(int i=0; i < catalog.size(); i++)
              {
                 cout<<"Book{";
                 cout<<catalog[i];
                 cout<<"}"<<endl;
              }
           }
           field = line.substr(0,line.find("="));
           field.erase(0,1);

           if(field.compare("isbn") == 0) // Display books with given ISBN
           {
              value = line.substr(line.find("=")+1, line.find("\n")-line.find("="));
              cout<<"Book with ISBN "<< value <<":"<<endl;
              int pos = find(value, catalog);
              if(pos >= 0)
              {
                 cout<<"Book{";
                 cout<<catalog[pos];
                 cout<<"}"<<endl;
              }
              
           }
           if(field == "author") // Display books with given author
           {
              value = line.substr(line.find("=")+1, line.find("\n")-line.find("="));
              cout<<"Books by author "<< value <<":"<<endl;
              for(int i=0; i<catalog.size(); i++)
              {
                  if(catalog[i].get_last() == value)
                  {
                     cout<<"Book{";
                     cout<<catalog[i];
                     cout<<"}"<<endl;
                  }
              }
              
           }
           if(field == "category") // Display books with given category
           {
              value = line.substr(line.find("=")+1, line.find("\n")-line.find("="));
              cout<<"Books in category "<< value <<":"<<endl;
              for(int i=0; i<catalog.size(); i++)
              {
                  if(catalog[i].get_category() == value)
                  {
                     cout<<"Book{";
                     cout<<catalog[i];
                     cout<<"}"<<endl;
                  }
              }
           }
           
        }
        else if(command == '+') // New book object addition
        {
           Book new_book;
           input>>new_book;
           int pos = find(new_book.get_isbn(), catalog);
           if(pos < 0)
           {
              int i = add_book(new_book, catalog);
              cout<<"Inserted at index "<<i<<": ";
              cout<<"Book{";
              cout<<catalog[i];
              cout<<"}"<<endl;
           }
           else
           {
              cout<<"Inserted at index "<<pos<<": ";
              cout<<"Book{";
              cout<<catalog[pos];
              cout<<"}"<<endl; 
              StatusCode status = StatusCode::DUPLICATE;
              error_display(status);
              
           }
        }
        else if(command == '-') // Book object deletion
        {
           string isbn;
           input>>isbn;
           int pos = find(isbn, catalog);
           if (pos == -1)
           {
             StatusCode status = StatusCode::NOT_FOUND;
             cout<<"Removed Book{ISBN="<<isbn<<", last=, first=, title=, category=none}";
             cout<<endl;
             error_display(status);
           }
           else
           {
              cout<<"Removed Book{";
              cout<<catalog[pos];
              catalog.erase(catalog.begin()+pos);
              cout<<"}"<<endl;
           }
        }
    }

    return 0;
}

// Binary search function definition

int find(const string isbn, const vector<Book>& catalog)
{
   int low = 0;
   int high = catalog.size()-1;
   int mid;
   while (low <= high)
   {
      mid = (low + high)/2;
      if(catalog[mid].get_isbn() == isbn) return mid;
      else
      {
         if(catalog[mid].get_isbn() < isbn) low = mid+1;
         else high = mid - 1;
      }
   }
   return -1;
}

// Book object addition to book catalog

int add_book(Book& book, vector<Book> &catalog)
{
   int i=0;
   while(i < catalog.size())
   {
      if(book.get_isbn() < catalog[i].get_isbn()) break;
      i++;
   }
   catalog.insert(catalog.begin()+i, book);
   return i;
}

// Display error message

void error_display(const StatusCode code)
{
    switch (code)
    {
        case StatusCode::DUPLICATE:
            cout << "*** Duplicate ISDN ***" << endl;
            break;
        case StatusCode::NOT_FOUND:
            cout << "*** Book not found ***" << endl;
            break;
        case StatusCode::INVALID_COMMAND:
            cout << "*** Invalid command ***" << endl;
            break;
    }
}

