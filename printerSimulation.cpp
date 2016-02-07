/* Group 1
 * Taylor AB and Geoffrey P
 * File to run the Print Simulation
 */
#include<fstream>
#include<cstdlib>
#include<string>
#include<iostream>
#include<ctime>

#include "printerType.h"
#include "printerListType.h"
#include "printRequestType.h"
#include "waitingQueue.h"

using namespace std;

//Function to print to the screen and ask for all of the simulation parameters
void setSimulationParameters(int& maxPages, int& printRate, int& numOfPrinters,
                         int& numOfPrintJobs, unsigned int& seed, string& file);
//Function to return the random size of the print job
int printJobArrival(int maxPages);

//Function to run the printer simulation
void runSimulation();

int main()
{
    runSimulation();
    
    return 0;
}

int printJobArrival(int maxPages){
    int pages;
    pages = rand() % maxPages + 1;
    return pages;
}

void setSimulationParameters(int& maxPages, int& printRate, int& numOfPrinters                           int& numOfPrintJobs, unsigned int& seed, string& file)
{
     char check; 
     
     cout << "Enter the total number of print jobs: ";
     cin >> numOfPrintJobs;
     cout << endl;
    
     cout << "Enter the max number of pages: ";
     cin >> maxPages;
     cout << endl;

     cout << "Enter the printing rate: ";
     cin >> printRate;
     cout << endl; 

     cout << "Enter the number of printers: ";
     cin >> numOfPrinters;
     cout << endl; 

     cout << "Want to enter a seed value? [Y/N]: ";
     cin >> check;
     cout << endl; 
 
     if(check == 'Y' || check == 'y'){
       cout << "Enter seed value: ";       
       cin >> seed;
       cout << endl; 
       srand(seed);
     }else 
       srand(time(0));

     cout << "Want simulation info sent to file? [Y/N]: ";
     cin >> check;
     cout << endl; 

     if(check == 'Y' || check == 'y'){
       cout << "Enter file name: ";
       cin >> file;
       cout << endl;
     }else 
       file = cout; 

}

void runSimulation(){

     
     int maxPages,printRate,numOfPrinters,numOfPrintJobs,clock = 1,pageNum,
         priority;
     unsigned int seed;
     string file;
     bool notFinished = true;
     int requestNumber = 1, printerID;

     setSimulationParameters(maxPages, printRate, numOfPrinters, numOfPrintJobs, seed, file);

     printRequestType printJob;
     waitingQueue pWaitingQueue;
     int printJobs = numOfPrintJobs; 
     printerListType printers(numOfPrinters);

     while(notFinished){
         //Update the printers in use by decrementing the pages to print 
         //by the print rate
         updatePrinters(clock, file);
         //Get the number of pages of the print job if print jobs available
         if(printJobs > 0){
            pageNum= printJobArrival(maxPages);
            printJob.setPrintRequestType(pageNum,requestNumber);
            printJobs--;
            requestNumber++;
           }

         printerID = printers.getFreePrinterID();
         while(printerID != -1 && !pWaitingQueue.queueEmpty()){
               printJob = pWaitingQueue.queueFront();
               printers.setPrinterBusy(printerID,printJob,
                                      printJob.getNumberOfPages(),clock,file);
               pWaitingQueue.queuePop();
               printerID = printers.getFreePrinterID();
         }
                       
         //ADD getNumberOfBusyPrinters() FUNCTION TO .h FILE
         //ALSO THERE IS AN EXTRA I in one of the .h files parameters
         //Also make sure classes are good to go
         if(printJobs <= 0 && printers.getNumberOfBusyPrinters() == 0 &&
            pWaitingQueue.queueSize() == 0)
             notFinished = false;
  
         clock++;
      }
}
