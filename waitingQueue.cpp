/*   Group Number: 1
     Members: Geoffrey, Taylor
     File Description:
          Contains the implimentation for the class
          waitingQueue, which represents a queue
          of printRequestType items. This queue is
          special in one way: it must be able to
          reorganize itself so that it is sorted by
          the priority of each printRequestType item
          before returning to the standard first-in
          first-out model.
     Notes for grading:
*/

#include "printRequestType.h"

void waitingQueue::add(printRequestType pushMe)
{
     queue<printRequestType> temp;
     bool spotFound = false;
     unsigned int size = waiting.size(), count = 0;
     
     //no need to sort if one of the follow is true:
     //1. queue is empty
     //2. priority is 3 (highest priority)
     if(waiting.empty() || pushMe.getPriority() == 3)
     {
          waiting.push(pushMe);
     }
     else
     {
          //test if pushMe is supposed to be the first item
          if(waiting.front().getPriority() > pushMe.getPriority())
                spotFound = true;

          //push onto temp and pop off of wait until insertion
          //spot has been found or waiting is emptry
          while(!spotFound && count < size)
          {
               temp.push(waiting.front());
               waiting.pop();
               if(waiting.front().getPriority() > pushMe.getPriority())
                    spotFound = true;
               count++;
          }
     
          temp.push(pushMe);
     
          while(cout < size)
          {
               temp.push(waiting.front());
               waiting.pop();
               count++;
          }

          waiting = temp;
     }
}

bool waitingQueue::queueEmpty()
{
     return waiting.empty();
}

unsigned int waitingQueue::queueSize()
{
     return waiting.size();
}

printRequestType waitingQueue::queueFront()
{
     return waiting.front();
}

printRequestType waitingQueue::queueBack()
{
     return waiting.back();
}

void waitingQueue::queuePop()
{
     waiting.pop();
}
