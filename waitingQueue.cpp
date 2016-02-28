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

waitingQueue::waitingQueue(int numQueues)
{
     NumberOfPriorities = numQueues;
     list = new queue<printRequestType>[numQueues];
}

waitingQueue::waitingQueue()
{
     NumberOfPriorities = 1;
     list = new queue<printRequestType>[1];
}

void waitingQueue::push(printRequestType pushMe, int clock, ostream& out)
{
     out << "At time unit " << clock << " the following item entered the waiting queue:" << endl;
     pushMe.print(out);
     list[pushMe.getPriority()-1].push(pushMe);
}

bool waitingQueue::empty()
{
     bool empty = true;
     for(int i = 0; i < NumberOfPriorities; i++)
     {
          if(list[i].empty() == false)
               empty = false;
     }
     return empty;
}

unsigned int waitingQueue::size()
{
     unsigned int size = 0;
     for(int i = 0; i < NumberOfPriorities; i++)
     {
          size = size + list[i].size();
     }
     return size;
}

printRequestType waitingQueue::front()
{
     bool found = false;
     int i = 0;
     printRequestType front;
     while(found == false && i < NumberOfPriorities)
     {
          if(list[i].empty() == false)
          {
               found = true;
               front = list[i].front();
          }
          i++;
     }
     if(found == false)
          cout << "There is no front element in an empty queue." << endl;
     return front;
}

printRequestType waitingQueue::back()
{
     bool found = false;
     int i = NumberOfPriorities - 1;
     printRequestType back;
     while(found == false && i >= 0)
     {
          if(list[i].empty() == false)
          {
               found = true;
               back = list[i].back();
          }
          i--;
     }
     if(found == false)
          cout << "There is no back element in an empty queue." << endl;
     return back;
}

void waitingQueue::pop(printRequestType pushMe,int clock, ostream& out)
{
     out << "At time unit " << clock << " the following item exited the waiting queue:" << endl;
     pushMe.print(out);
     bool found = false;
     int i = 0;
     while(found == false && i < NumberOfPriorities)
     {
          if(list[i].empty() == false)
          {
               found = true;
               list[i].pop();
          }
          i++;
     }
     if(found == false)
          cout << "There is no front element in an empty queue." << endl;
}
