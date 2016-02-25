/*   Group Number: 1
     Members: Geoffrey, Taylor
     File Description:
          Used to test the correctness of the
          printRequestType class.
     Notes for grading:
*/

#include <iostream>
#include "printRequestType.h"

using namespace std;

int main()
{
     int cutoffs[4] = {5,10,15,20};
     int priorities = 5;
     int max = 25;
     
     printRequestType One(cutoffs,priorities,max,4,1);
     printRequestType Two(cutoffs,priorities,max,10,2); 
     printRequestType Three(cutoffs,priorities,max,13,3); 
     printRequestType Four(cutoffs,priorities,max,16,4); 
     printRequestType Five(cutoffs,priorities,max,22,5);

     One.print();
     Two.print(); 
     Three.print(); 
     Four.print(); 
     Five.print();
}
