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

void printRequestType::setPrintRequestType(int priorCut[], int numPrior, int maxPage, int numPage, int numReq)
{
     bool found = false;
     int priorityCutoffs[numPrior];
     int k = 0;
     for(int i = 0; i < numPrior - 1; i++)
          priorityCutoffs[i] = priorCut[i];
     priorityCutoffs[numPrior - 1] = maxPage;
     if(numPage > maxPage)//quick test incase bad info is recieved
     {
          cout << "Warning: Print Request #" << numReq << " has more pages than allowed." << endl;
          Priority = numPrior;
     }
     while(found == false)
     {
          if(numPage <= priorityCutoffs[k])
          {
               found = true;
               Priority = k + 1;
          }
          k++;
     }     
     NumberOfPages = numPage;
     RequestNumber = numReq;
}

printRequestType::printRequestType(int priorCut[], int numPrior, int maxPage, int numPage, int numReq)
{
     bool found = false;
     int priorityCutoffs[numPrior];
     int k = 0;
     for(int i = 0; i < numPrior - 1; i++)
          priorityCutoffs[i] = priorCut[i];
     priorityCutoffs[numPrior - 1] = maxPage;
     if(numPage > maxPage)//quick test incase bad info is recieved
     {
          cout << "Warning: Print Request #" << numReq << " has more pages than allowed." << endl;
          Priority = numPrior;
     } 
     while(found == false)
     {
          if(numPage <= priorityCutoffs[k])
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

void printRequestType::print()
{
     cout << "Print Request number " << RequestNumber;
     cout << " has " << NumberOfPages << " page(s) and";
     cout << " has a priority of " << Priority << "." << endl;
}
