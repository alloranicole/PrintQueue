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
          waitingQueue(int numQueues);
          //Default constructor with input.
          //Post condition:
               //NumberOfPriorities = numQueues
               //list is initialized to be an array with numQueues elements

          waitingQueue();
          //Default constructor without input.
          //Post condition:
               //NumberOfPriorities = 1
               //list is initialized to be an array with 1 element

          void push(printRequestType pushMe);
          //places pushMe in the queue representing
          //the same priority
          //Postcondition:
               //pushMe is pushed onto the correct queue based on its priority
          bool empty();
          //uses emptry() to test if all three queues are
          //emptry. if any queue has an item, false is returned
          //postcondition:
               //return true if all queues are emptry
               //return false if any queue has an item

          unsigned int size();
          //adds the size of the three queues using size()
          //postcondition:
               //return the sum of the queues' sizes

          printRequestType front();
          //searches the queues from first to last to find 
          //the first queue with an item. The front item of 
          //that queue is returned.
          //postcondition:
               //front of first non-empty queue is returned
               //message is given if queue was empty

          printRequestType back();
          //searches the queues from last to first to find 
          //the first queue with an item. The back item of 
          //that queue is returned.
          //postcondition:
               //back of first non-empty queue is returned
               //message is given if queue was empty

          void pop();
          //searches the queues from first to last to find 
          //the first queue with an item. The front item of 
          //that queue is popped.
          //postcondition:
               //front of first non-empty queue is popped
               //message is given if queue was empty

     private:
          int NumberOfPriorities;
          queue<printRequestType> *list;
};
