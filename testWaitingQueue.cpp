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

     printRequestType testOne, testTwo, testThree, testFour;
     testOne.setPrintRequestType(5,1);
     testTwo.setPrintRequestType(25,2);
     testThree.setPrintRequestType(15,3);
     testFour.setPrintRequestType(17,4);

     testOne.print();
     testTwo.print();
     testThree.print();
     testFour.print();

     testWaiting.add(testOne);
     testWaiting.add(testTwo);
     testWaiting.add(testThree);
     testWaiting.add(testFour);

     cout << "The queue's size is: " << testWaiting.queueSize() << endl;
     unsigned int size = testWaiting.queueSize();
     cout << "This is the order they print out:" << endl;
     for(int i = 0; i < size; i++)
     {
          testWaiting.queueFront().print();
          testWaiting.queuePop();
     }
}
