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

#include <queue>
#include "waitingQueue.h"
#include "printRequestType.h"

using namespace std; 

void waitingQueue::add(printRequestType pushMe)
{
     if(pushMe.getPriority() == 1)
          priorityOne.push(pushMe);
     else if(pushMe.getPriority() == 2)
          priorityTwo.push(pushMe);
     else
          priorityThree.push(pushMe);
}

bool waitingQueue::queueEmpty()
{
     if(priorityOne.empty())
     {
          if(priorityTwo.empty())
          {
               if(priorityThree.empty())
               {
                    return true;
               }
               else
               {
                    return false;
               }
          }
          else
          {
               return false;
          }
     }
     else
     {
          return false;
     }
}

unsigned int waitingQueue::queueSize()
{
     unsigned int size = priorityOne.size();
     size += priorityTwo.size();
     size += priorityThree.size();
     return size;
}

printRequestType waitingQueue::queueFront()
{
     if(!priorityOne.empty())
          return priorityOne.front();
     else if(!priorityTwo.empty())
          return priorityTwo.front();
     else if(!priorityThree.empty())
          return priorityThree.front();
     else
          cout << "There is no front of an emptry queue." << endl;
}

printRequestType waitingQueue::queueBack()
{
     if(!priorityThree.empty())
          return priorityThree.back();
     else if(!priorityTwo.empty())
          return priorityTwo.back();
     else if(!priorityOne.empty())
          return priorityOne.back();
     else
          cout << "There is no back of an empty queue." << endl;
}

void waitingQueue::queuePop()
{
     if(!priorityOne.empty())
          priorityOne.pop();
     else if(!priorityTwo.empty())
          priorityTwo.pop();
     else if(!priorityThree.empty())
          priorityThree.pop();
     else
          cout << "Cannot pop from empty queue." << endl;
}
