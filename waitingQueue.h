/*   Group Number: 1
     Members: Geoffrey, Taylor
     File Description:
          Contains the header for the class
          waitingQueue, which represents a queue
          of printRequestType items. This queue is
          special in one way: it must be able to
          reorganize itself so that it is sorted by
          the priority of each printRequestType item
          before returning to the standard first-in
          first-out model.
     Notes for grading:
*/

#include <iostream>
#include <queue>
#include "printRequestType.h"

using namespace std; 

class waitingQueue: public queue<printRequestType>
{
     public:
          void add(printRequestType pushMe);
          //this function accesses the queue and uses a
          //combination of push and pull to insert a new
          //printRequestType item into the list so that
          //the following rules are used:
               //1. Priority 1 before Priority 2
               //2. Priority 2 before Priority 3
               //3. Items of the same priority are 
               //   first come first served.
          //Postcondition:
               //the queue now contains pushMe in correct
               //priority order.
          bool queueEmpty();
          //calls the emptry() function of queue for waiting
          //postcondition:
               //return waiting.empty()

          unsigned int queueSize();
          //calls the size() function of queue for waiting
          //postcondition:
               //return waiting.size()

          printRequestType queueFront();
          //calls the front() function of queue for waiting
          //postcondition:
               //return waiting.front()

          printRequestType queueBack();
          //calls the back() function of queue for waiting
          //postcondition:
               //return waiting.back()

          void queuePop();
          //calls the pop() function of queue for waiting
          //postcondition:
               //waiting pops its front item

     private:
          queue<printRequestType> waiting;
};
