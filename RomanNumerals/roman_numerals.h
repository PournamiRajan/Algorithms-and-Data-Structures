#ifndef ROMANNUMERAL_H_
#define ROMANNUMERAL_H_
#include <cstring>
#include <iostream>
using namespace std;

class RomanNumeral
{
private:
   string roman;
   int decimal;
   string to_roman(int value);
   int to_decimal(string value);
   int find_int_value(char a);
public:
   RomanNumeral(); // Default constructor
   RomanNumeral(string roman_value);
   RomanNumeral(int decima_value);
   string get_roman() const;
   int get_decimal() const;
   
   friend int operator -(const RomanNumeral& r1, const RomanNumeral& r2);
   friend int operator +(const RomanNumeral& r1, const RomanNumeral& r2);
   friend int operator *(const RomanNumeral& r1, const RomanNumeral& r2);
   friend int operator /(const RomanNumeral& r1, const RomanNumeral& r2);
   
   friend bool operator ==(const RomanNumeral& r1, const RomanNumeral& r2);
   friend bool operator !=(const RomanNumeral& r1, const RomanNumeral& r2);
   
   friend ostream& operator <<(ostream& outs, const RomanNumeral& r);
   friend istream& operator >>(istream& ins, RomanNumeral& r);
   
   
   ~RomanNumeral(); 
};

#endif /* ROMANNUMERAL_H_ */