/*   Group Number: 1
     Members: Geoffrey, Taylor
     File Description:
          This file is designed to prove the correctness
          of the waitingQueue class.
     Notes for grading:
*/

#include <iostream>
#include <queue>
#include "waitingQueue.h"
#include "printRequestType.h"

using namespace std; 

int main()
{
     waitingQueue testWaiting;

     cout << "Is testWaiting emptry? " << testWaiting.queueEmpty() << endl;

     printRequestType testOne;
     testOne.setPrintRequestType(5,1);

     testOne.print();

     testWaiting.add(testOne);

     cout << "testWaiting's front item is: " << endl;
     testWaiting.queueFront().print();
}
