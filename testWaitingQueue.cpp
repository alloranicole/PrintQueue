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
     int cutoffs[4] = {5,10,15,20};
     int priorities = 5;
     int max = 25;

     waitingQueue testWaiting(priorities);

     cout << "Is testWaiting emptry? " << testWaiting.empty() << endl;
     
     printRequestType One(cutoffs,priorities,max,4,1);
     printRequestType Two(cutoffs,priorities,max,10,2); 
     printRequestType Three(cutoffs,priorities,max,13,3); 
     printRequestType Four(cutoffs,priorities,max,16,4); 
     printRequestType Five(cutoffs,priorities,max,22,5);

     testWaiting.push(Three);
     testWaiting.push(Four);
     testWaiting.push(Two);
     testWaiting.push(Five);
     testWaiting.push(One);

     cout << "Is testWaiting emptry? " << testWaiting.empty() << endl;

     int size = testWaiting.size();

     cout << "The queue's size is: " << size << endl;
     cout << "This is the order they print out:" << endl;
     for(int i = 0; i < size; i++)
     {
          cout << "Front:-----" << endl;
          testWaiting.front().print();
          testWaiting.pop();
     }
}
