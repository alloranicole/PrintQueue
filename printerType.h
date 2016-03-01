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
            //Postcondition: status and other boolean variables are initialized to "free", 
            //"isWorking", and "printing" and pagesToPrint,
            //printRate, totalTime, as well as the other new variables are all initialized to 0.
            printerType();
            
            //Function to determine if a printer is free (status = "free")
            //Postcondition: returns true if the printer is free, else it
            //returns false
            bool isFree() const;
         
            //checks if the printer is in maintenance and returns true or false
            bool isInMaintenance() const;

            //checks if the printer is offline and returns true or false
            bool isOffline() const;

            //Function to set a printer to busy when it receives a print job
            //Postcondition: status = "busy"
            void setBusy();
            
            //sets if the printer is in maintenance
            void setInMaintenance();
           
            //sets if the printer is out of maintenance
            void setIsWorking();

            //sets the printer offline so that the failure can be fixed
            void setOffline();

            //sets if the printer is allowed to print (as in it isn't offline)
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
            
            //sets the amount of pages a printer can print until it has to go into
            //maintenance
            void setMaintenanceLimit(int m);

            //sets how long it takes to get a printer out of maintenance
            void setMaintenanceTime(int m);

            //sets how much it costs per page to print
            void setCost(double c);

            //sets the probability that a printer will fail at printing a job
            void setFailureProb(double f);
            
            //sets how long it takes the printer to fix a failure
            void setFailureTime(int f);

            //Function to return how many pages are left to print
            //Postcondition: pagesToPrint is returned
            int getRemainingPagesToPrint() const;
            
            //returns the total cost accumulated
            double getTotalCost();
 
            //Checks whether a printer ran out of printer paper/ ink and needs to go 
            //into maintenance
            void checkForMaintenance(ostream& outfile, int ID, int clock);
           
            //Checks whether or not a printer was able to succeed in printing and if it needs to 
            //go offline
            void checkForFailure(ostream& outfile, int ID, int clock);

            //Updates the total cost the printer accumulated printing pages
            void updateTotalCost();

            //Updates the total number of jobs the printer has had
            void updateTotalJobs();

            //Function to decrease the number of pagesToPrint by the printing
            //rate, also increase the totalTime, decreases pages from the maintenanceLimit,
            //and adds to the total amount of pages printed 
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
           
            //Returns the total number of jobs the printer received
            int getTotalJobs(); 
     
            //Returns how many total pages were printed at the time it is called
            int getTotalPagesPrinted();

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
            int totalPagesPrinted;
            double failureProb;
            int failureTime;
            int fTValue;
            int totalTime;
            double totalCost;
            int totalJobs;
};
