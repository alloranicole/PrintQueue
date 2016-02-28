/* Group 1
 * Taylor AB and Geoffrey P
 * File to run the Print Simulation
 * A given number of printers complete a given number of print jobs in a 
 * certain order. The simulation returns how long it takes to do such.
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
void setSimulationParameters(int& maxPages, int*& printRate, double*& cost, int& numOfPrinters, int& numOfPrintJobs, unsigned int& seed, int& checkFile, int& maintenanceLimit, int& maintanenceTime, double& failureProb, int& failureTime);
//Function to return the random size of the print job
//Postcondition: number of pages of a print job is returned
int printJobArrival(int maxPages);

int printJobs(

void printResults(int& maxPages, int& printRate, int& numOfPrinters, int& numOfPrintJobs, unsigned int& seed, ostream& outfile);

//Function to run the printer simulation
//Postcondition: simulation is run calculating the results which are then displayed
void runSimulation();

int main()
{
    runSimulation();
    
    return 0;
}

double P(int k, int avgJobs){
       double lambda = (double)(1/avgJobs);
       
}
double[] setUpDist(int avgJobs){
         double total = 0;
         int k = 0;
         while(total < .95){
              total += P(k, avgJobs);
              k++;
         }
         double a[k+1];
         a[0] = P(0, avgJobs);
         for(int i = 1; i < k; i++)
            a[i] = a[i-1] + P(i, avgJobs);
         a[k] = 1;
         return a;        
 }   
     
    

int printJobs(double a[]){
         //look in movie simulation for random
         double printJobs = rand() % 1;
         if(printJobs < a[0])
            return 0;
         //look up how to get size of array
         for(int i = 1; i < size; i++)
             if(printJobs > a[i-1] && printJobs < a[i])
                return i;
}          
             
         
    

int printJobArrival(int maxPages){
    int pages;
    //gets random page number from 1 to maxPages
    pages = rand() % maxPages + 1;
    return pages;
}

void setSimulationParameters(int& maxPages, int*& printRate, double*& cost, int& numOfPrinters, int& numOfPrintJobs, unsigned int& seed, int& checkFile, int& maintenanceLimit, int& maintanenceTime, double& failureProb, int& failureTime)
{
     char check; 

     cout << "Enter the total number of print jobs: ";
     cin >> numOfPrintJobs;
     cout << endl;
    
     cout << "Enter the max number of pages: ";
     cin >> maxPages;
     cout << endl;

     cout << "Enter the number of printers: ";
     cin >> numOfPrinters;
     cout << endl; 

     printRate = new int[numOfPrinters];
     cost = new double[numOfPrinters];
      
     cout << "Want separate printing rates for the " << numOfPrinters << 
             " printers? [Y/N]: ";
     cin >> check;
     cout << endl; 

     if(check == 'Y' || check == 'y'){
        for(int i = 0; i < numOfPrinters; i++){
            cout << "Enter the rate for printer " << (i+1) << " : ";       
            cin >> printRate[i];
            cout << endl; 
          }  
     }else{
        cout << "Enter the rate for printers: ";
        cin >> printRate[0];
        cout << endl;       
        for(int i = 1; i < numOfPrinters; i++){
            printRate[i] = printRate[0];
        }
     }       
     cout << "Enter the cutoff for maintenance: ";
     cin >> maintenanceLimit;
     cout << endl; 
   
     cout << "Enter the time for maintanence: ";
     cin >> maintanenceTime;
     cout << endl; 

     cout << "Enter the probability for failure: ";
     cin >> failureProb;
     cout << endl; 
    
     cout << "Enter the time to fix failure: ";
     cin >> failureTime;
     cout << endl; 
     
     cout << "Want a separate cost per page for the " << numOfPrinters << 
             " printers? [Y/N]: ";
     cin >> check;
     cout << endl; 

     if(check == 'Y' || check == 'y'){
        for(int i = 0; i < numOfPrinters; i++){
            cout << "Enter the cost per page for printer " << (i+1) << " : ";       
            cin >> cost[i];
            cout << endl; 
          }  
     }else{
        cout << "Enter the cost per page for printers: ";
        cin >> cost[0];
        cout << endl;       
        for(int i = 1; i < numOfPrinters; i++){
            cost[i] = cost[0];
        }
     }
       
     cout << "Want to enter a seed value? [Y/N]: ";
     cin >> check;
     cout << endl; 
 
     if(check == 'Y' || check == 'y'){
       cout << "Enter seed value: ";       
       cin >> seed;
       cout << endl; 
       srand(seed);
     }else{
       seed = 0; 
       srand(time(0));
     }
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

void printResults(int& maxPages, int& printRate, int& numOfPrinters, int& numOfPrintJobs, unsigned int& seed, int clock, ostream& outfile)
{
     //remind the user what they gave at the beginning
     outfile << "---You gave the following information---" << endl;
     outfile << "Number of print jobs---: " << numOfPrintJobs << endl;
     outfile << "Maximum number of pages-: " << maxPages << endl;
     outfile << "Rate of printing--------: " << printRate << endl;
     outfile << "Number of printers------: " << numOfPrinters << endl;
     if(seed == 0)
           outfile << "You did not provide a seed." << endl;
     else
           outfile << "Seed value--------------: " << seed << endl;

      //display results
      outfile << "---Results of the simulation------------" << endl;
      outfile << "Time Elapsed------------: " << clock - 1 << endl;
}

void runSimulation(){

     //Variables
     int maxPages,numOfPrinters,numOfPrintJobs,clock = 1,pageNum;
     int maintenanceLimit, maintenanceTime, failureTime, printJobs;
     double failureProb;
     int *printRate;
     double *cost;
     unsigned int seed;
     int requestNumber = 1, printerID;
     ofstream outfile;//output file
     int checkFile;//tracks if filename was given
     ostream* out = &cout;//Prints to specified location 
      
     //Gets initial values from user
     setSimulationParameters(maxPages, printRate, cost, numOfPrinters, numOfPrintJobs, seed, checkFile, maintenanceLimit, maintenanceTime, failureProb, failureTime);
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
       out = &outfile;//changes which location is sent to functions
     } 
     
     double poissonDist[] = setUpDist(); 
     
     printRequestType printJob;
     waitingQueue pWaitingQueue;
     int printJobs = numOfPrintJobs;//holds total number of print jobs
     //sets up list of # printers 
     printerListType printers(numOfPrinters, printRate, cost, maintenanceLimit, maintenanceTime, failureProb, failureTime);
     //after each run through of the loop check to see if all the 
     //print jobs have been completed, thus the simulation is finished
     //if no more print jobs AND no busy printers AND no jobs in the queue
     while(printJobs > 0 || printers.getNumberOfBusyPrinters() != 0 ||
           pWaitingQueue.queueSize() != 0){
         //Update the printers in use by decrementing the pages to print 
         //by the print rate
         printers.updatePrinters(clock,*out);
            
         //Get the number of pages of the print job if print jobs available
         if(printJobs > 0){
            printJobs = printJobs(a);
            if(printJobs > 0)
               for(int i = 1; i <= printJobs; i++){
                   pageNum= printJobArrival(maxPages);
                   //add print job to the queue
                   printJob.setPrintRequestType(pageNum,requestNumber);
                   pWaitingQueue.add(printJob);
                   printJobs--;//decrement print jobs left
                   requestNumber++;//print job id number
               }
           }

         //if there are print jobs in the queue and a printer is free
         //pair the next print job with a free printers
         printerID = printers.getFreePrinterID();//get free printer
         while(printerID != -1 && !pWaitingQueue.queueEmpty()){
               printJob = pWaitingQueue.queueFront();//get print job in front
               //move print job to printer
               printers.setPrinterBusy(printerID,printJob,printJob.getNumberOfPages(),clock, *out);
               pWaitingQueue.queuePop();
               printerID = printers.getFreePrinterID();//check for free printer
         }
                       
         //after each run through of the loop check to see if all the 
         //print jobs have been completed, thus the simulation is finished
         //if no more print jobs AND no busy printers AND no jobs in the queue
  
         clock++;//update the clock time 
      }
      
     // printResults(maxPages, printRate, numOfPrinters, numOfPrintJobs, seed, clock, *out);
      //If a filename was given make sure to close it
      if(checkFile==1)
        outfile.close();
}
