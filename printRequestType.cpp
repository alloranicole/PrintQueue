/*   Group Number: 1
     Members: Geoffrey, Taylor
     File Description:
          Contains the implimentation for the class
          printRequestType, which represents one request
          to print a specific number of pages.
     Notes for grading:
*/
#include<iostream>
#include "printRequestType.h"

using namespace std;

void printRequestType::setPrintRequestType(int priorCut[], int numPrior, int numPage, int numReq)
{
     bool found = false;
     int k = 0;
     while(found == false)
     {
          if(numPage <= priorCut[k])
          {
               found = true;
               Priority = k + 1;
          }
          k++;
     }     
     NumberOfPages = numPage;
     RequestNumber = numReq;
}

printRequestType::printRequestType(int priorCut[], int numPrior, int numPage, int numReq)
{
     bool found = false;
     int k = 0;
     while(found == false)
     {
          if(numPage <= priorCut[k])
          {
               found = true;
               Priority = k + 1;
          }
          k++;
     }     
     NumberOfPages = numPage;
     RequestNumber = numReq;
}

printRequestType::printRequestType()
{
     NumberOfPages = 0;
     Priority = 0;
     RequestNumber = 0;
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

void printRequestType::print(ostream& out)
{
     out << "Job Number-----: " << RequestNumber << endl;
     out << "Number of Pages: " << NumberOfPages << endl;
     out << "Priority-------: " << Priority << endl;
}
