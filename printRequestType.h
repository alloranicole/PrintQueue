/*   Group Number: 1
     Members: Geoffrey, Taylor
     File Description:
          Contains the header information for the class
          printRequestType, which represents one request
          to print a specific number of pages.
     Notes for grading:
*/

class printRequestType
{
     public:
          void printRequestType(int numPage, int numPrior, int numReq);
          //Initializes an instance of this class and uses the parameters given.
          //Postcondition:
               //NumberOfPages = numPage;
               //Priority = numPrior;
               //RequestNumber = numReq;

          int getNumberOfPages() const;
          //returns the value of the private variable NumberOfPages.
          //Postcondition: Value of NumberOfPages is returned.

          int getPriority() const;
          //returns the value of the private variable Priority.
          //Postcondition: Value of Priority is returned.

          int getRequestNumber() const;
          //returns the value of the private variable RequestNumber.
          //Postcondition: Value of RequestNumber is returned.

     private:
          int NumberOfPages;
          int Priority;
          int RequestNumber;
};
