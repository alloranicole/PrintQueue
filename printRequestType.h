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

class printRequestType
{
     public:
          void setPrintRequestType(int numPage, int numReq);
          //Initializes an instance of this class and uses the parameters given.
          //Postcondition:
               //NumberOfPages = numPage;
               //Priority =
                    //1 if numPage <= 10
                    //2 if 10 < numPage <= 20
                    //3 if 20 < numPage
               //RequestNumber = numReq;

          printRequestType();
          //Default constructor. Calls setPrintRequestType with all 0.
          //Post condition:
               //NumberOfPages = 0;
               //Priority = 1;
               //RequestNumber = 0;

          int getNumberOfPages() const;
          //returns the value of the private variable NumberOfPages.
          //Postcondition: Value of NumberOfPages is returned.

          int getPriority() const;
          //returns the value of the private variable Priority.
          //Postcondition: Value of Priority is returned.

          int getRequestNumber() const;
          //returns the value of the private variable RequestNumber.
          //Postcondition: Value of RequestNumber is returned.

          void print();
          //displays all of the vaiables for testing purposes or
          //if anyone would like to see them.
          //postcondition: NumberOfPages, Priority, and RequestNumber
               //are printed out to the screen.

     private:
          int NumberOfPages;
          int Priority;
          int RequestNumber;
};

#endif
