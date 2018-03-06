#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

const int SIMULATION_COUNT = 100;

void print_heading();
int find_car_door();
int find_first_choice();
int find_opened_door(int car_here, int first_choice);
int find_second_choice(int first_choice, int opened_door);
string find_win_first(int car_here, int first_choice, int& win_first_count);
string find_win_second(int car_here, int first_choice, int& win_second_count);
void print_output(int i, int car_here, int first_choice, int opened_door,
                        int second_choice, string win_first, string win_second);
void print_result(int win_first_count, int win_second_count);

int main()
{
   srand(time(NULL));
   int i=1;
   int win_first_count=0;
   int win_second_count=0;
   print_heading();
   while(i <= SIMULATION_COUNT)
   {
      int car_here      = find_car_door();
      int first_choice  = find_first_choice();
      int opened_door   = find_opened_door(car_here,first_choice);
      int second_choice = find_second_choice(first_choice,opened_door);
      string win_first  = find_win_first(car_here,first_choice,win_first_count);
      string win_second = find_win_second(car_here,first_choice,win_second_count);
      
      print_output(i,car_here,first_choice,opened_door,
                                    second_choice,win_first,win_second);
      i++;
   }
   print_result(win_first_count, win_second_count);
   return 0;
}


void print_heading()
{
   cout<<"  "<<"#"<<"\t"<<"Car"<<"\t"<<"First"<<"\t"<<"Opened"<<"\t"
                                    <<"Second"<<"\t"<<"Win"<<"\t"<<"Win";
   cout<<endl;
   cout<<"\t"<<"here"<<"\t"<<"choice"<<"\t"<<"door"<<"\t"
                                    <<"choice"<<"\t"<<"first"<<"\t"<<"second";
   cout<<endl;
   cout<<endl;
}

int find_car_door()
{
   return (rand()%3 + 1);
}

int find_first_choice()
{
   return (rand()%3 + 1);
}

int find_opened_door(int car_here, int first_choice)
{
   int opened_door=0;
   if(first_choice == car_here)
   {
      opened_door = (first_choice%3 + 1) + (rand()%2);
      if (opened_door > 3)
      {
         opened_door = opened_door%3;
      }
   }
   else
   {
      opened_door = 6-(car_here + first_choice);
   }
   return opened_door;
}

int find_second_choice(int first_choice, int opened_door){
   
   return 6-(first_choice + opened_door);
}

string find_win_first(int car_here, int first_choice, int& win_first_count)
{
   if (car_here == first_choice)
   {
      win_first_count++;
      return " Yes ";
   }
   else
   {
      return "     ";
   }
}

string find_win_second(int car_here, int first_choice, int& win_second_count)
{
   if (car_here != first_choice)
   {
      win_second_count++;
      return " Yes ";
   }
   else
   {
      return "     ";
   }
}

void print_output(int i, int car_here, int first_choice, int opened_door,
                        int second_choice, string win_first, string win_second)
{
   cout<<"  "<<i<<" \t "<<car_here<<" \t "<<first_choice<<" \t "<<opened_door<<" \t "
               <<second_choice<<"\t"<<win_first<<"\t"<<win_second;

   cout<<endl;
}

void print_result(int win_first_count, int win_second_count)
{
   cout<<endl;
   cout<<"  "<<win_first_count<<" wins if stay with the first choice"<<endl;
   cout<<"  "<<win_second_count<<" wins if switch to the second choice"<<endl;
   cout<<endl;
   cout<<"Win ratio of switch over stay: "<<float(win_second_count)/win_first_count<<endl;
}











