/* Group 1
 * Taylor AB and Geoffrey P
 * Header file of the printerListType class
 * The class that creates and maintains the list of printers available to print
 */
#include <fstream>
#include <string>

#include "printRequestType.h"
#include "printerType.h"

using namespace std;

class printerListType{
      

      public:
            //Constructor to initialize the list of printers 
            //Postcondition: numOfPrinters = num and a list of printers
            //is created the size of num and thus all of those printers
            //are initialized with the status "free" 
            //The values in printRate[] are assigned to the corresponding printer
            //The values in cost[] are assigned to the corresponding printer
            //The maintenanceLimit and fixTime is set for all printers
            printerListType(int num, int *printRate, double *cost, 
                            int maintenanceLimit, int maintenanceTime, 
                            double failureProb, int failureTime);

            //Destructor
            //Postcondition: the list of printers is destroyed
            ~printerListType();
            
            //Function to search the list of printers 
            //Postcondition: if a printer is free the ID is returned
            //else -1 is returned
            int getFreePrinterID() const;

            //Function to return the number of busy printers
            //Postcondition: the number of busy printers is returned
            int getNumberOfBusyPrinters() const;
            
            //Function to set a printer as busy
            //Postcondition: The specified printer is found by the printerID
            //and set to "busy", currentPrintJob = printJob, 
            //pagesToPrint = pages
            void setPrinterBusy(int printerID, printRequestType printJob,
                                int pages,int clock,ostream & outfile);

            //Function to update the status of each printer
            //Postcondition: the pagesToPrint is decremented by the printRate
            //If pagesToPrint is zero or less the printer is set to "free"
            void updatePrinters(int clock, ostream& outfile);
      
      private:
            int numOfPrinters;
            printerType *printers;
};      
