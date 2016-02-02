/*   Group Number: 1
     Members: Geoffrey, Taylor
     File Description:
          Contains the implimentation for the class
          printRequestType, which represents one request
          to print a specific number of pages.
     Notes for grading:
*/

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void printRequestType::printRequestType(int numPage, int numPrior, int numReq)
{
     NumberOfPages = numPage;
     Priority = numPrior;
     RequestNumber = numReq;
}

int printRequestType::getNumberOfPages()
{
     return NumberOfPages;
}

int printRequestType::getPriority()
{
     return Priority;
}

int printRequestType::getRequestNumber()
{
     return RequestNumber;
}
