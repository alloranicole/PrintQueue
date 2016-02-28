/*   Group Number: 1
     Members: Geoffrey, Taylor
     File Description:
          Used to test the correctness of the
          printRequestType class.
     Notes for grading:
*/

#include<iostream>
#include "printRequestType.h"

using namespace std;

int main()
{
     ostream* out = &cout;
     int cutoffs[5] = {5,10,15,20,25};
     int priorities = 5;
     
     printRequestType One(cutoffs,priorities,4,1);
     printRequestType Two(cutoffs,priorities,10,2); 
     printRequestType Three(cutoffs,priorities,13,3); 
     printRequestType Four(cutoffs,priorities,16,4); 
     printRequestType Five(cutoffs,priorities,22,5);

     One.print(*out);
     Two.print(*out); 
     Three.print(*out); 
     Four.print(*out); 
     Five.print(*out);
}
