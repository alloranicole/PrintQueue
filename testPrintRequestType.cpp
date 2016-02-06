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

     cout << "Number of pages:" << endl;
     cout << "requestOne = " << requestOne.getNumberOfPages() << endl;
     cout << "requestTwo = " << requestTwo.getNumberOfPages() << endl;
     cout << "requestThree = " << requestThree.getNumberOfPages() << endl;
     cout << "Priority:" << endl;
     cout << "requestOne = " << requestOne.getPriority() << endl;
     cout << "requestTwo = " << requestTwo.getPriority() << endl;
     cout << "requestThree = " << requestThree.getPriority() << endl;
     cout << "Request Number:" << endl;
     cout << "requestOne = " << requestOne.getRequestNumber() << endl;
     cout << "requestTwo = " << requestTwo.getRequestNumber() << endl;
     cout << "requestThree = " << requestThree.getRequestNumber() << endl;    
}
