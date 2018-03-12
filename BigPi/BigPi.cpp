#include <iostream>
#include <iomanip>
#include <mpir.h>
#include <stdlib.h>
#include <string.h>
#include <chrono>
#include <cmath>

using namespace std;
using namespace std::chrono;

const int MAX_ITERATIONS = 12;
const int PLACES         = 1000000;        // desired decimal places
const int PRECISION      = PLACES + 1;  // +1 for the digit 3 before the decimal

const int BASE       = 10;  // base 10 numbers
const int BIT_COUNT  = 8;   // bits per machine word

const int BLOCK_SIZE = 10;                // print digits in blocks
const int LINE_SIZE  = 100;               // digits to print per line
const int LINE_COUNT = PLACES/LINE_SIZE;  // lines to print
const int GROUP_SIZE = 5;                 // line grouping size

/***** Complete this file. *****/

void display(const mpf_t &Bigpi);

/**
 * The main.
 */
int main()
{
    mpf_set_default_prec(BIT_COUNT*PRECISION);  // precision in bits

    // Variable declarations and initializations
    //Declarations         		Initializations
    //------------              ----------------
    mpf_t ai;					mpf_init(ai); 			//to store ai
    mpf_t yi;					mpf_init(yi);			//to store yi
    mpf_t sq_2;					mpf_init(sq_2);			//sqrt(2)
    mpf_t temp1;				mpf_init(temp1);		// to -
    mpf_t temp2;				mpf_init(temp2);		// store temp -
    mpf_t temp3;				mpf_init(temp3);		// values
    mpf_t temp_yi;				mpf_init(temp_yi);		//to store base value of yi
    mpf_t temp_ai;				mpf_init(temp_ai);		// to store base value of ai
    mpf_t numerator;			mpf_init(numerator);	//numerator of yi
    mpf_t denominator;			mpf_init(denominator);	// denominator of yi
    mpf_t BigPi; 				mpf_init(BigPi);		//to store Big Pi value


    mpf_sqrt_ui(sq_2,2u); 								//sqrt(2)
    mpf_mul_ui(ai,sq_2,4); 								// 4*sqrt(2)
    mpf_ui_sub(ai,6,ai); 								// 6-4*sqrt(2)
    mpf_sub_ui(yi,sq_2,1u);								// sqrt(2)-1

    auto start_time = std::chrono::system_clock::now(); // starting time

    for (int i = 1; i <= MAX_ITERATIONS; i++)
    {
    	mpf_pow_ui(temp1,yi,4u); 			// temp1=pow(yi,4)
    	mpf_ui_sub(temp1,1u,temp1); 		//temp1=1-pow(yi,4)
    	mpf_sqrt(temp1,temp1); 				//temp1=sqrt(1-pow(yi,4))
    	mpf_sqrt(temp1,temp1);				//temp1=sqrt(sqrt(1-pow(yi,4)))
    	mpf_ui_sub(numerator,1u,temp1); 	//numerator=1-sqrt(sqrt(1-pow(yi,4)))
    	mpf_add_ui(denominator,temp1,1u); 	//denominator=sqrt(sqrt(1-pow(yi,4)))+1
    	mpf_div(yi,numerator,denominator);	//yi=numerator/denominator
    	double super = (2*i)+1;
    	double value=pow(2,super); 			//2^(2i+1)
    	mpf_set(temp_yi,yi);				// storing base value of yi
    	mpf_pow_ui(temp3,yi,2u);			// temp3=yi^2
    	mpf_add(yi,temp3,yi);				//yi=yi+yi^2
    	mpf_add_ui(yi,yi,1u);				//yi=yi+(yi^2)+1
    	mpf_mul(yi,yi,temp_yi);				//yi=(yi+(yi^2)+1)*yi
    	mpf_mul_ui(yi,yi,value);			//yi=2^(2i+1)*(yi+(yi^2)+1)*yi
    	mpf_set(temp_ai,ai);				//storing base value of ai
    	mpf_add_ui(ai,temp_yi,1u);			//ai=yi+1
    	mpf_pow_ui(ai,ai,4u);				//ai=(yi+1)^4
    	mpf_mul(ai,ai,temp_ai);				//ai=ai*(yi+1)^4
    	mpf_sub(ai,ai,yi);					//ai=ai*(yi+1)^4 - 2^(2i+1)*(yi+(yi^2)+1)*yi
    	mpf_set(yi,temp_yi);				// setting yi back



    }
    auto end_time = std::chrono::system_clock::now(); // ending time
    std::chrono::duration<double> tot_time= end_time - start_time;

	mpf_ui_div(BigPi,1u,ai); 				// BigPi=1/ai
	cout<<"  pi to 1000 places: \n\n";
    display(BigPi);

    cout<<"\n \tElapsed time : "<< tot_time.count()<<endl;
    return 0;
}

void display(const mpf_t &BigPi) 			//displaying in correct format
{
	int count=0;
	char *str=NULL, *ptr;
	mp_exp_t e;
	ptr=mpf_get_str(str, &e, BASE, PLACES+1, BigPi);
	cout<<"  "<<ptr[0]<<".";
	for(int i=1;i<PLACES+1;i++)
	{
		cout<<ptr[i];
		if(i%BLOCK_SIZE==0)
		{
			cout<<"\t";
			if(i%LINE_SIZE==0)
			{
				cout<<endl;
				cout<<"\t";
				count++;
				if(count%GROUP_SIZE==0)
				{
					cout<<endl;
					cout<<"\t";
				}
			}
		}
	}
}

