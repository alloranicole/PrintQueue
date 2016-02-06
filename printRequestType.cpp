/*   Group Number: 1
     Members: Geoffrey, Taylor
     File Description:
          Contains the implimentation for the class
          printRequestType, which represents one request
          to print a specific number of pages.
     Notes for grading:
*/

#include <iostream>

#include "printRequestType.h"

using namespace std;

void printRequestType::setPrintRequestType(int numPage, int numReq)
{
     NumberOfPages = numPage;
     if(numPage <= 10)
     {
          Priority = 1;
     }
     else if(numPage <= 20)
     {
          Priority = 2;
     }
     else
     {
          Priority = 3;
     }
     RequestNumber = numReq;
}

printRequestType::printRequestType()
{
     setPrintRequestType(0,0);
}

int printRequestType::getNumberOfPages() const
{
     return NumberOfPages;
}

int printRequestType::getPriority() const
{
     return Priority;
}

int printRequestType::getRequestNumber() const
{
     return RequestNumber;
}
