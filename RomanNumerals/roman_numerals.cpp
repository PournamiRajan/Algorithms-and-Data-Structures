#include "RomanNumeral.h"
#include <cstring>
#include <iostream>
using namespace std;

// constructors

RomanNumeral::RomanNumeral() : roman(""), decimal(0)
{
   //Empty
}
RomanNumeral::RomanNumeral(string roman_value) : roman(roman_value) 
{
   decimal = to_decimal(roman);
}
RomanNumeral::RomanNumeral(int decimal_value) : decimal(decimal_value)
{
   roman = to_roman(decimal);
}

// getters

string RomanNumeral::get_roman() const {   return roman; }
int RomanNumeral::get_decimal() const { return decimal; }

// conversions (roman to decimal) & (decimal to roman)

string RomanNumeral::to_roman(int value)
{
    string roman="";
    int decimal=value;
    int quotient=0;
    if (decimal >= 1000)
    {  
      quotient = decimal / 1000;
    	for (int i=0; i < quotient; i++) roman.append("M");
    	decimal = decimal%1000;
    }
    
    if (decimal >= 900)
    {
    	roman.append("CM");
    	decimal = decimal%900;
    }
    else if (decimal >= 500)
    {
	   quotient = decimal / 500;
	   for (int i=0; i < quotient; i++) roman.append("D");
      decimal = decimal%500;
    }
   
    if (decimal >= 400)
    {
    	roman.append("CD");
    	decimal = decimal%400;
    }       
    else if (decimal >= 100)
	 {
      quotient = decimal / 100;
      for (int i=0; i < quotient; i++) roman.append("C");
		decimal = decimal%100;
	 }
    
    if (decimal >= 90)
    {
       roman.append("XC");
       decimal = decimal%90;
    }
    
    else if (decimal >= 50)
	 {
        quotient = decimal / 50;
        for (int i=0; i < quotient; i++) roman.append("L");
		  decimal = decimal%50;
	 }
    if (decimal >= 40)
    {
        roman.append("XL");
        decimal = decimal%40;
    }
	 else if (decimal >= 10)
	 {
        quotient = decimal / 10;
        for (int i=0; i < quotient; i++) roman.append("X");
		 decimal = decimal%10;
	 }

    if (decimal >= 9)
    {
        roman.append("IX");
        decimal = decimal%9;
    }
    
    else if (decimal >= 5)
	 {
        quotient = decimal / 5;
        for (int i=0; i < quotient; i++) roman.append("V");
	 	  decimal = decimal%5;
	 }
    if (decimal >= 4)
    {
        roman.append("IV");
        decimal = decimal%4;
    }
	else if (decimal >= 1)
	{
        quotient = decimal;
        for (int i=0; i < quotient; i++) roman.append("I");
	}
    
   return roman;
}

int RomanNumeral::find_int_value(char a)
{
    switch(a)
    {
        case 'I':   return 1;
                    break;
        case 'V':   return 5;
                    break;
        case 'X':   return 10;
                    break;
        case 'L':   return 50;
                    break;
        case 'C':   return 100;
                    break;
        case 'D':   return 500;
                    break;
        case 'M':   return 1000;
                    break;
    }
    return 0;
}


int RomanNumeral::to_decimal(string roman_value)
{
   
   int decimal_value =0;
   decimal_value     = find_int_value(roman_value.at(roman_value.length()-1));
   for(int i=roman_value.length()-2; i>=0; i--)
   {
     int current   = find_int_value(roman_value.at(i));
     int prev      = find_int_value(roman_value.at(i+1));
     int multiplier = current >= prev ? 1 : -1;
     decimal_value += (current*multiplier);
   }
   return decimal_value;
}

// operator overloading

int operator -(const RomanNumeral& r1, const RomanNumeral& r2)
{
   return (r1.decimal - r2.decimal);
    
}

int operator +(const RomanNumeral& r1, const RomanNumeral& r2)
{
    return (r1.decimal + r2.decimal);
}

int operator *(const RomanNumeral& r1, const RomanNumeral& r2)
{
    return (r1.decimal * r2.decimal);
}

int operator /(const RomanNumeral& r1, const RomanNumeral& r2)
{
    int result = r1.decimal / r2.decimal;
    return result;
}

bool operator ==(const RomanNumeral& r1, const RomanNumeral& r2)
{
   return (r1.decimal == r2.decimal);
}

bool operator !=(const RomanNumeral& r1, const RomanNumeral& r2)
{
   return (r1.decimal != r2.decimal);
}

// output and input overloading

ostream& operator <<(ostream& outs, const RomanNumeral& r)
{
    outs << "[" << r.decimal << ":" << r.roman << "]";
    return outs;

}

istream& operator >>(istream& ins, RomanNumeral& r)
{
    string roman_value;
    ins >> roman_value;
    r.roman = roman_value;
    r.decimal = r.to_decimal(roman_value);
    return ins;
}


RomanNumeral::~RomanNumeral()
{
   //Empty
}


/***** Complete this class implementation. *****/