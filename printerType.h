/* Group 1
 * Taylor AB and Geoffrey P
 * printerType Header File
 * The class that defines what variables and methods a printer has available to
 * it
 */
#include <fstream>
#include <string>

#include "printRequestType.h"

using namespace std; 

class printerType{

      public:
            //Default Constructor
            //Set the values of the instance variables to default values
            //Postcondition: status is initialized to "free" and pagesToPrint,
            //printRate, totalTime, are all initialized to 0.
            printerType();
            
            //Function to determine if a printer is free (status = "free")
            //Postcondition: returns true if the printer is free, else it
            //returns false
            bool isFree() const;
         
            // 
            bool isInMaintenance() const;

            //
            bool isOffline() const;

            //Function to set a printer to busy when it receives a print job
            //Postcondition: status = "busy"
            void setBusy();
            
            //  
            void setInMaintenance();
           
            //
            void setIsWorking();

            //
            void setOffline();

            //
            void setPrinting();

            //Function to return the value of total time that the printer spent
            //printing print jobs
            //Postcondition: totalTime is returned
            int getTotalTime();

            //Function to set a printer to free when it is finished with a print
            //job
            //Postcondition: status = "free"
            void setFree();

            //Function to set the number of pages to print to the 
            //number of pages from the print job
            //Postcondition: pagesToPrint = printJob.pages
            void setPagesToPrint(int p);
            
            //Function to set the print rate for the printer
            void setPrintRate(int p);
            
            //
            void setMaintenanceLimit(int m);

            //
            void setMaintenanceTime(int m);

            //
            void setCost(double c);

            //
            void setFailureProb(double f);
            
            //
            void setFailureTime(int f);

            //Function to return how many pages are left to print
            //Postcondition: pagesToPrint is returned
            int getRemainingPagesToPrint() const;
            
            //
            double getTotalCost();
 
            //
            void checkForMaintenance(ostream& outfile, int ID, int clock);
           
            //
            void checkForFailure(ostream& outfile, int ID, int clock);

            //
            void updateTotalCost();

            //Function to decrease the number of pagesToPrint by the printing
            //rate 
            //Postcondition: pagesToPrint -= printRate
            void decreasePagesToPrint(ostream& outfile, int ID, int clock);

            //Function to set the info of the current print job
            //Postcondition: currentPrintJob = printJob;
            void setCurrentPrintJob(printRequestType printJob);

            //Function to return the print job number of the current job
            //Postcondition: currentPrintJob.jobNumber is returned
            int getCurrentPrintJobNumber() const;
                
            //Function to return the number of pages of the current print job
            //Postcondition: pages of the current print job returned
            int getCurrentPrintJobPages() const;

      private:
            printRequestType currentPrintJob;
            string status;
            string maintenanceStatus;
            string failureStatus;
            int maintenanceLimit;
            int mLValue;
            int maintenanceTime;
            int mTValue;
            double cost;
            int pagesToPrint;
            int printRate;
            double failureProb;
            int failureTime;
            int fTValue;
            int totalTime;
            double totalCost;
};
