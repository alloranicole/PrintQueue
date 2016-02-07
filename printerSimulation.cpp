/* Group 1
 * Taylor AB and Geoffrey P
 * File to run the Print Simulation
 */
#include<fstream>
#include<cstdlib>
#include<string>
#include<iostream>
#include<ctime>

#include "printerListType.h"
#include "printRequestType.h"
#include "waitingQueue.h"

using namespace std;

//Function to print to the screen and ask for all of the simulation parameters
//Postcondition: simulation parameters have value given by user
void setSimulationParameters(int& maxPages, int& printRate, int& numOfPrinters,
                         int& numOfPrintJobs, unsigned int& seed, int& checkFile);
//Function to return the random size of the print job
//Postcondition: number of pages of a print job is returned
int printJobArrival(int maxPages);

//Function to run the printer simulation
//Postcondition: simulation is run calculating the results which are then displayed
void runSimulation();

int main()
{
    runSimulation();
    
    return 0;
}

int printJobArrival(int maxPages){
    int pages;
    //gets random page number from 1 to maxPages
    pages = rand() % maxPages + 1;
    return pages;
}

void setSimulationParameters(int& maxPages, int& printRate, int& numOfPrinters,                           int& numOfPrintJobs, unsigned int& seed, int& checkFile)
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
     //This variable is used in the runSimulation to check if a user gives a
     //filename
     if(check == 'Y' || check == 'y'){
        checkFile = 1;
     }else 
       checkFile = 0;

}

void runSimulation(){

     //Variables
     int maxPages,printRate,numOfPrinters,numOfPrintJobs,clock = 1,pageNum;
     unsigned int seed;
     bool notFinished = true;//Tracks if the loop is finished
     int requestNumber = 1, printerID;
     ofstream outfile;//output file 
     int checkFile;//trackes if filename was given
   
     //Gets initial values from user
    setSimulationParameters(maxPages, printRate, numOfPrinters, numOfPrintJobs, seed, checkFile);
     //Decides if the user wants to enter a file name 
     //then opens said file
     if(checkFile == 1){
       char file[30];
       cout << "Enter file name: ";
       cin >> file;
       cout << endl;
       outfile.open(file);
       //If there is an issue with the filename asks for another
       while(outfile.fail()){
          cerr<<"Problem with output file."<<endl;
          cout << "Enter file name: ";
          cin >> file;
          cout << endl;
          outfile.open(file);
       }
     }
     
     printRequestType printJob;
     waitingQueue pWaitingQueue;
     int printJobs = numOfPrintJobs;//holds total number of print jobs
     //sets up list of # printers 
     printerListType printers(numOfPrinters);

     while(notFinished){
         //Update the printers in use by decrementing the pages to print 
         //by the print rate
         //If a filename was given there is a different function call
         if(checkFile == 1)
            printers.updatePrinters(clock,outfile);
         else
            printers.updatePrinters(clock,cout);
            
         //Get the number of pages of the print job if print jobs available
         if(printJobs > 0){
            pageNum= printJobArrival(maxPages);
            //add print job to the queue
            printJob.setPrintRequestType(pageNum,requestNumber);
            pWaitingQueue.add(printJob);
            printJobs--;//decrement print jobs left
            requestNumber++;//print job id number
           }

         //if there are print jobs in the queue and a printer is free
         //pair the next print job with a free printers
         printerID = printers.getFreePrinterID();//get free printer
         while(printerID != -1 && !pWaitingQueue.queueEmpty()){
               printJob = pWaitingQueue.queueFront();//get print job in front
               //move print job to printer
               //If a filename was given there is a different function call
               if(checkFile == 1)
                  printers.setPrinterBusy(printerID,printJob,printJob.getNumberOfPages(),printRate,clock, outfile);
               else
                  printers.setPrinterBusy(printerID,printJob,printJob.getNumberOfPages(),printRate,clock, cout);
               pWaitingQueue.queuePop();
               printerID = printers.getFreePrinterID();//check for free printer
         }
                       
         //after each run through of the loop check to see if all the 
         //print jobs have been completed, thus the simulation is finished
         //if no more print jobs AND no busy printers AND no jobs in the queue
         if(printJobs <= 0 && printers.getNumberOfBusyPrinters() == 0 &&
            pWaitingQueue.queueSize() == 0)
             notFinished = false;
  
         clock++;//update the clock time 
      }
      //If a filename was given make sure to close it
      if(checkFile==1)
        outfile.close();
}
