#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    /***** Complete this program. *****/
	// Name: Pournami Puthenpurayil Rajan


	double pi=4*atan(1); // using 4*arctan(1) formula
    std::cout << "pi   = "<<std::setprecision(16) << pi << " = 4*arctan(1)" << endl;

    cout << endl;

    cout << "Ramanujan's pi formulas:" << endl;

    double pi15=(12/sqrt(130))*(log((2+sqrt(5))*(3+sqrt(13))/sqrt(2)));
    double pi16=(24/sqrt(142))*(log(sqrt((10+11*sqrt(2))/4)+sqrt((10+7*sqrt(2))/4)));
    double pi18=(12/sqrt(190))*(log((2*sqrt(2)+sqrt(10))*(3+sqrt(10))));
    double pi22=(12/sqrt(310))*(log((3+sqrt(5))*(2+sqrt(2))*((5+2*sqrt(10))+(sqrt(61+20*sqrt(10))))/4));
    double pi31=(4/sqrt(522))*(log((pow(((5+sqrt(29))/sqrt(2)),3))*(5*sqrt(29)+11*sqrt(6))*  (pow( (sqrt( (9 + 3*sqrt(6))/4) +sqrt((5+3*sqrt(6))/4)),6))));


    std::cout << "pi15  = "<<std::setprecision(16) << pi15<< endl;
    std::cout << "pi16  = "<<std::setprecision(16) << pi16<< endl;
    std::cout << "pi18  = "<<std::setprecision(16) << pi18<< endl;
    std::cout << "pi22  = "<<std::setprecision(16) << pi22<< endl;
    std::cout << "pi31  = "<<std::setprecision(16) << pi31<< endl;
    cout<< endl;
    cout << "Euler's infinite sum for pi*pi/6 = " << std::setprecision(8)<< (pi*pi/6) << endl;

    float i=2; // odd number increment
    float n=1.0; // base value of denominator
    float sum=0.0; // sum
    int count=0; // No:of iterations
    while((1.0/n)>(1.0/float(pow(10,8)))){
    	count++;
    	sum+=(1.0/n);
    	n+=(i+1.0);
    	i+=2.0;

    }


    std::cout << "                      Converged to " << std::setprecision(8) <<sum;
       cout<< " after " << count << " iterations" << endl;

       cout<< endl;

    cout << "Euler's estimate for pi = " << sqrt(sum*6) << endl;
    cout << "                  error = " << std::setprecision(7) <<abs(sqrt(sum*6)-pi) << endl;
}
