/*   Group Number: 1
     Members: Geoffrey, Taylor
     File Description:
          This file is designed to prove the correctness
          of the waitingQueue class.
     Notes for grading:
*/

#include <iostream>
#include "waitingQueue.h"
#include "printRequestType.h"

int main()
{
     waitingQueue testWaiting;

     cout << "Is testWaiting emptry? " << testWaiting.queueEmpty() << endl;

     printRequestType testOne(5,1);

     testWaiting.add(testOne);
}
