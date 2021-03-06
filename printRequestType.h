/*   Group Number: 1
     Members: Geoffrey, Taylor
     File Description:
          Contains the header information for the class
          printRequestType, which represents one request
          to print a specific number of pages.
     Notes for grading:
*/

#ifndef H_printRequestType
#define H_printRequestType
#include<iostream>

using namespace std;

class printRequestType
{
     public:
          void setPrintRequestType(int priorCut[], int numPrior, int numPage, int numReq);
          //Sets the values of the private variables.
          //Post condition:
               //NumberOfPages = numPage
               //RequestNumber = numReq
               //Priority =
                    //1. Initilize list of cutoffs
                    //2. Add maximum number of pages to the end (represents final cutoff)
                    //3. Compare number of pages to cutoffs until a cutoff is greater or equal
                    //4. Assign Priority the value of the position in the array that the cutoff was found

          printRequestType(int priorCut[], int numPrior, int numPage, int numReq);
          //Default constructor with values.
          //Post condition: see setPrintRequestType
          
          printRequestType();
          //Default constructor without values.
          //Post condition: all variables are zero.

          int getNumberOfPages() const;
          //returns the value of the private variable NumberOfPages.
          //Postcondition: Value of NumberOfPages is returned.

          int getPriority() const;
          //returns the value of the private variable Priority.
          //Postcondition: Value of Priority is returned.

          int getRequestNumber() const;
          //returns the value of the private variable RequestNumber.
          //Postcondition: Value of RequestNumber is returned.
     
          int getTimeEnter() const;
          //returns the value of the private variable timeEnter.
          //Postcondition: Value of timeEnter is returned.

          void print(ostream& out);
          //displays all of the vaiables for testing purposes or
          //if anyone would like to see them.
          //postcondition: NumberOfPages, Priority, and RequestNumber
               //are printed out to the screen.

          void setTimeEnter(int time);
          //sets the variable "timeEnter" to equal the input "time"
          //post condition: timeEnter = time

     private:
          int NumberOfPages; //how many pages this job has
          int Priority; //the importance of this job, smaller = more important
          int RequestNumber; //when the job was made compared to other jobs
          int timeEnter;
};

#endif
