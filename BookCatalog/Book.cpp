#include "Book.h"

using namespace std;

/***** Complete this file. *****/

// Default constructor

Book::Book()
{
   isbn = "";
   last = "";
   first = "";
   title = "";
}

// Parameterised constructor

Book::Book(string isbn, string last, string first, string title, Category category)
{
   this->isbn = isbn;
   this->last = last;
   this->first = first;
   this->title = title;
   this->category = category;
}

// Destructor 

Book::~Book()
{
   // empty
}
// Getter Function definitions

string Book::get_isbn() const
{
   return isbn;
}
string Book::get_last() const
{
   return last;
}
string Book::get_first() const
{
   return first;
}
string Book::get_title() const
{
   return title;
}
string Book::get_category() const
{
   
   if(category == Category::FICTION)
   {
      return "fiction";
   }else if(category == Category::TECHNICAL )
   {
      return "technical";
   }else if(category == Category::HISTORY )
   {
      return "history";
   }else 
   {
      return "";
   }

}

// Insertion operator overloading

istream& operator >>(istream &ins, Book& new_book)
{
   string cat;
   getline ( ins, new_book.isbn, ',');
   new_book.isbn.erase(0,1);
   getline ( ins, new_book.last, ',');
   getline ( ins, new_book.first, ',');
   getline ( ins, new_book.title, ',');
   getline ( ins, cat);
   
   if(cat == "fiction")
   {
      new_book.category = Book::Category::FICTION;
   }else if(cat == "technical")
   {
      new_book.category = Book::Category::TECHNICAL;
   }else if(cat == "history")
   {
      new_book.category = Book::Category::HISTORY;
   }else 
   {
      new_book.category = Book::Category::NONE;
   }

   return ins;
}

// Extraction operator overloading

ostream& operator <<(ostream &outs, const Book& book)
{
   string cat;
   if(book.category == Book::Category::FICTION)
   {
      cat = "fiction";
   }else if(book.category == Book::Category::TECHNICAL )
   {
      cat = "technical";
   }else if(book.category == Book::Category::HISTORY )
   {
      cat = "history";
   }else 
   {
      cat = "";
   }
    
    outs << "ISBN=" + book.isbn + ", last=" + book.last + ", first=" + book.first + ", title="
                                    + book.title+", category=" + cat ;
    return outs;
}
