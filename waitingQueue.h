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

class waitingQueue
{
     public:
          void add(printRequestType pushMe);
          //places pushMe in the queue representing
          //the same priority
          //Postcondition:
               //pushMe is in priorityOne if priority = 1
               //pushMe is in priorityTwo if priority = 2
               //pushMe is in priorityThree if priority = 3
          bool queueEmpty();
          //uses emptry() to test if all three queues are
          //emptry. if any queue has an item, false is returned
          //postcondition:
               //return true if all queues are emptry
               //return false if any queue has an item

          unsigned int queueSize();
          //adds the size of the three queues using size()
          //postcondition:
               //return the sum of the three queues' sizes

          printRequestType queueFront();
          //searches the queues from first to last to find 
          //the first queue with an item. The front item of 
          //that queue is returned.
          //postcondition:
               //front of first non-empty queue is returned
               //message is given if queue was empty

          printRequestType queueBack();
          //searches the queues from last to first to find 
          //the first queue with an item. The back item of 
          //that queue is returned.
          //postcondition:
               //back of first non-empty queue is returned
               //message is given if queue was empty

          void queuePop();
          //searches the queues from first to last to find 
          //the first queue with an item. The front item of 
          //that queue is popped.
          //postcondition:
               //front of first non-empty queue is popped
               //message is given if queue was empty

     private:
          queue<printRequestType> priorityOne;
          queue<printRequestType> priorityTwo;
          queue<printRequestType> priorityThree;
};
