/*   Group Number: 1
     Members: Geoffrey, Taylor
     File Description:
          Contains the header for the class
          waitingQueue, which represents a queue
          of printRequestType items. This queue is
          special in one way: it must be able to
          reorganize itself so that it is sorted by
          the priority of each printRequestType item.
     Notes for grading:
*/

#include <iostream>
#include <queue>
#include "printRequestType"

template <class Type>
class waitingQueue : public queue<Type>
{
     public:
          void push(printRequestType pushMe);
          //Overrides Queue's push function.
          //The new push function should take into account
          //pushMe's priority so that priority 1 comes before
          //priority 2, priority 2 comes before priority 3, and
          //items of the same priority are first-come-first-serve
          //Postcondition:
               //the queue now contains pushMe in correct
               //priority order.

     private:
          Type *list;
};
