#ifndef BOOK_H_
#define BOOK_H_

#include <string>
#include <istream>
#include <ostream>
using namespace std;

/***** Complete this file. *****/

//The Book class.
 
class Book
{
public:
    /***** Complete the public members. *****/
    // Book categories.
     
    enum class Category { FICTION, HISTORY, TECHNICAL, NONE };

    // Default constructor.
     
    Book();

    // Constructor.
     
    Book(string isbn, string last, string first, string title, Category category);

    // Destructor.
     
    ~Book();
    
    // Getter functions
    
    string get_isbn() const;
    string get_last() const;
    string get_first() const;
    string get_title() const;
    string get_category() const;
    
    //Operator overloaded friend functions
    
    friend istream& operator >>(istream &input, Book& book);
    friend ostream& operator <<(ostream& output, const Book& book);

private:
    
    /***** private members *****/
    
    string isbn, last, first, title;
    Category  category;
};

#endif /* EMPLOYEE_H_ */