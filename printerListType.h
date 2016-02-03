/* Group 1
 * Taylor AB and Geoffrey P
 * Header file of the printerListType class
 */
#include <fstream>
#include <string>

using namespace std;

class printerListType{
      

      public:
            //Constructor to initialize the list of printers
            //Postcondition: numOfPrinters = num and a list of printers
            //is created the size of num and thus all of those printers
            //are initialized with the status "free" 
            printerListType(int num = 1);

            //Destructor
            //Postcondition: the list of printers is destroyed
            ~printerListType();
            
            //Function to search the list of printers 
            //Postcondition: if a printer is free the ID is returned
            //else -1 is returned
            int getFreePrinterID() const;

            //Function to set a printer as busy
            //Postcondition: The specified printer is found by the printerID
            //and set to "busy", currentPrintJob = printJob, 
            //pagesToPrint = pages
            void setPrinterBusy(int printerID, printRequestType printJob,
                                int pagesi, int clock, ostream& outfile);

            //Function to update the status of each printer
            //Postcondition: the pagesToPrint is decremented by the printRate
            //If pagesToPrint is zero or less the printer is set to "free"
            void updatePrinters(int clock, ostream& outfile);
      
      private:
            int numOfPrinters;
            printerType *printers;
};      
