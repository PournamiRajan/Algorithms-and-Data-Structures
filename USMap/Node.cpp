#include <math.h>
#include "Node.h"
#include "Coordinate.h"


int Node::i = 0;
int Node::j = 0;
/*
 * Constructor
 */
Node::Node(Coordinate& cor)
{
   name = "";
   state = "";
   convert_coordinate(cor);
}
Node::Node(City& city)
{
   name = city.getname();
   state = city.getstate();
   convert_coordinate(city.getcoordinate());
}
/*
 * Getters
 */
int Node::getrow() const
{
	return row;
}
int Node::getcol() const
{
	return col;
}
/*
 * Convert coordinates according to scale
 */
void Node::convert_coordinate(const Coordinate& coordinate)
{
    row = round(2*(Coordinate::MAX_LATITUDE - coordinate.getlatitude()));
    col = round(2*(coordinate.getlongitude() - Coordinate::MIN_LONGITUDE));
}
/*
 * Overloaded Greater than (>) operator
 */
bool Node::operator >(const Node& other) const
{
	if(other.row < row) return true;
	else if(other.row > row) return false;
	else if(other.col < col) return true;

	return false;

}
/*
 * Overloaded output operator
 */
ostream& operator <<(ostream& outs, const Node node)
{
   if (node.row == Node::i && (node.col + 1) == Node::j) return outs;
   static int length = 0;
   while(Node::i < Coordinate::MAX_LATITUDE)
   {
      while(Node::j < (-1*Coordinate::MIN_LONGITUDE))
      {
         if(Node::i == node.row && Node::j == node.col)
         {
           	 if(!node.name.empty() )
   			 {
   			    if (length > 0) return outs;
           		 outs<<"*"<<node.name<<" "<<node.state;
           		 length = node.name.length() + node.state.length() +2;
           		 return outs;
   			 }
             if (length == 0) outs<<"#";
             else length--;
             Node::j++;
             return outs;
         }
         else
         {
            if (length == 0) outs<<" ";
            else length--;
            Node::j++;
         }
      }
      outs<<endl;
      Node::i++;
      Node::j=0;
      length = 0;
   }
   return outs;
}

Node::~Node()
{

}
