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
     printRequestType requestOne, requestTwo, requestThree;
     requestOne.setPrintRequestType(5,1);
     requestTwo.setPrintRequestType(15,2);
     requestThree.setPrintRequestType(25,3);

     requestOne.print();
     requestTwo.print();
     requestThree.print();   
}
