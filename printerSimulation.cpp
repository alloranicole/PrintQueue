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
#include<cmath>

#include "printerListType.h"
#include "printRequestType.h"
#include "waitingQueue.h"

using namespace std;

//Function to print to the screen and ask for all of the simulation parameters
//Postcondition: simulation parameters have value given by user also includes the variables that are different
//per printer
void setSimulationParameters(istream& in, int& maxPages, int*& printRate, double*& cost, int& numOfPrinters, int& numOfPrintJobs, unsigned int& seed, int& checkFile, int& maintenanceLimit, int& maintanenceTime, double& failureProb, int& failureTime, int& numberOfPriorities, int*& priorityCutoffs, double& avgJobs);
//Function to return the random size of the print job
//Postcondition: number of pages of a print job is returned
int printJobArrival(int maxPages, int L, int* U, double* a);
//Exectutes the function of the Poisson Distribution and returns the
//result for a specific k
double P(int k, double avgJobs);
//Factorial function
int fact(int x);
//Returns how many different sections are created for the specific distribution
//based on the average jobs per minute. This allows an array to be created to be used 
int findKMax(double avgJobs);
//Sets up the Poisson distribution array filling each element of the array with the distribution
//cutoffs
void setUpDist(double*& poissonDist, int k, double avgJobs);
//With the page distribution a priority level is found and then
//within that priority level a random number for the page number is found
int findPrintJobs(double*& a, int k);
//Sets up the distribution in an array 
//in order to find which priority level the random set of pages is in
void setUpPageDist(double*& a, int L);

//Function designed to print out both the initial input and the results
//uses ostream to output to whichever medium is sent, ex. cout or output file
/*void printResults(int& maxPages, int*& printRate, double*& cost, int& numOfPrinters,
     int& numOfPrintJobs, unsigned int& seed, int& checkFile, int& maintenanceLimit, int& maintanenceTime,
     double& failureProb, int& failureTime, int& numberOfPriorities, int*& priorityCutoffs, double& avgJobs);
*/
void printResults(int runtime, int avgPrinterWait,printerListType *printers, ostream& outfile);
//Function to run the printer simulation
//Postcondition: simulation is run calculating the results which are then displayed
void runSimulation();

int main()
{
    runSimulation();
    
    return 0;
}

int fact(int x){
       if(x == 0)
          return 1;
       return x * fact(x-1);
}

double P(int k, double avgJobs){
       double lambda =  avgJobs;
       int factK = fact(k);
       double ex = exp(-1 * lambda);
       double numerator = pow(lambda,k) * ex;
       double total = (double) numerator / factK;
       return total;      
       
}

int findKMax(double avgJobs){
         double total = 0;
         int k = 0;
         while(total < .95){
              total += P(k, avgJobs);
              k++;
         }
         return k;
}

void setUpDist(double*& poissonDist, int k, double avgJobs){
         poissonDist[0] = P(0, avgJobs);
         for(int i = 1; i < k; i++)
            poissonDist[i] = poissonDist[i-1] + P(i, avgJobs);
         poissonDist[k] = 1;        
 }   

int findPrintJobs(double*& a, int k){
         double printJobs = ((double) rand() / (RAND_MAX));
         if(printJobs <= a[0])
            return 0;
         for(int i = 1; i < k+1; i++){
             if(printJobs > a[i-1] && printJobs <= a[i]){
                return i;
              }
         }
         return 0;
}          

void setUpPageDist(double*& a, int L){
         //Special cases if have 1,2,or 3 priority levels
         if(L == 1)
            a[0] = 1;
         else if(L == 2){
            a[0] = .5;
            a[1] = 1;
         }else if(L == 3){
            a[0] = (double) 1.0/3;
            a[1] = (double) 2.0/3;
            a[2] = 1;
         }else if(L > 3){
            a[0] = (double) 1.0/3;
            for(int i = 1; i < L - 1; i++)
                a[i] = (1.0/(3+i)) + a[i-1];
            a[L-1] = 1;
         }
}
             

int printJobArrival(int maxPages, int L, int* U, double* a){
    int pages, priority;
    double random = ((double) rand() / (RAND_MAX));
    //finds a priority level
    if(random <= a[0])
       priority = 1;
    else 
      for(int i = 1; i < L; i++)
          if(random > a[i-1] && random <= a[i]){
             priority = i+1;
             break;
          }
    //Finds a random number of pages within priority level
    if(priority == 1){
        pages = rand() % U[0] + 1;
        return pages;
     }else
        for(int i = 1; i < L; i++)
            if(priority == (i+1)){
               pages = rand() % (U[i] - U[i-1]) + (U[i-1] + 1);
               return pages;
            }
     return 0;
}   
         

void setSimulationParameters(istream& in,int& maxPages, int*& printRate, double*& cost, int& numOfPrinters,
     int& numOfPrintJobs, unsigned int& seed, int& checkFile, int& maintenanceLimit, int& maintenanceTime,
     double& failureProb, int& failureTime, int& numberOfPriorities, int*& priorityCutoffs, double& avgJobs)
{
     char check; 
     
     cout << "Use the default number of jobs? (default = 100 jobs) [y/n]: ";
     in >> check;
     cout << endl;
     if(check == 'Y' || check == 'y')
     {
          numOfPrintJobs = 100;
          cout << endl;
     }
     else
     {
          cout << "Enter the total number of print jobs: ";
          in >> numOfPrintJobs;
          cout << endl;
     }
     
     cout << "Use the default maximum number of pages? (default = 50 pages) [y/n]: ";
     in >> check;
     cout << endl;
     if(check == 'Y' || check == 'y')
     {
          maxPages = 50;
          cout << endl;
     }
     else
     {
          cout << "Enter the maximum number of pages: ";
          in >> maxPages;
          cout << endl;
     }

     cout << "Use the default number of printers? (default = 3 printers) [y/n]: ";
     in >> check;
     cout << endl;
     if(check == 'Y' || check == 'y')
     {
          numOfPrinters = 3;
          cout << endl;
     }
     else
     {
          cout << "Enter the number of printers: ";
          in >> numOfPrinters;
          cout << endl;
     }

     printRate = new int[numOfPrinters];
     cost = new double[numOfPrinters];
      
     cout << "Separate printing rates for the " << numOfPrinters << 
             " printer(s)? [Y/N]: ";
     in >> check;
     cout << endl; 

     if(check == 'Y' || check == 'y')
     {
        for(int i = 0; i < numOfPrinters; i++)
        {
            cout << "Enter the rate for printer " << (i+1) << " : ";       
            in >> printRate[i];
            cout << endl; 
        }  
     }
     else
     {
        cout << "Use the default print rate? (default = 10 pages per minute) [y/n]: ";
        in >> check;
        cout << endl;
        if(check == 'Y' || check == 'y')
        {
            for(int i = 0; i < numOfPrinters; i++)
            {
                printRate[i] = 10;
                cout << endl;
            }
        }
        else
        {
            cout << "Enter the rate for printers: ";
            in >> printRate[0];
            cout << endl;       
            for(int i = 1; i < numOfPrinters; i++)
            {
                printRate[i] = printRate[0];
            }
        }
     }
       
     cout << "Enter the cutoff for maintenance: ";
     in >> maintenanceLimit;
     cout << endl; 
     
     cout << "Use the default time for maintanance? (default = 10 minutes) [y/n]: ";
     in >> check;
     if(check == 'Y' || check == 'y')
     {
          maintenanceTime = 10;
          cout << endl;
     }
     else
     {
          cout << "Enter the time for maintanence: ";
          in >> maintenanceTime;
          cout << endl;
     } 

     cout << "Enter the probability for failure: ";
     in >> failureProb;
     cout << endl; 
     
     cout << "Use default time to fix a failure? (default = 2 minutes) [y/n]: ";
     in >> check;
     if(check == 'Y' || check == 'y')
     {
          failureTime = 2;
          cout << endl;
     }
     else
     {
          cout << "Enter the time to fix failure: ";
          in >> failureTime;
          cout << endl;
     } 

     cout << "Average number of prints jobs per minute: ";
     in >> avgJobs;
     cout << endl;
     
     cout << "Separate cost per page for the " << numOfPrinters << 
             " printers? [Y/N]: ";
     in >> check;
     cout << endl; 

     if(check == 'Y' || check == 'y'){
        for(int i = 0; i < numOfPrinters; i++){
            cout << "Enter the cost per page for printer " << (i+1) << " : ";       
            in >> cost[i];
            cout << endl; 
          }  
     }else{
        cout << "Enter the cost per page for printers: ";
        in >> cost[0];
        cout << endl;       
        for(int i = 1; i < numOfPrinters; i++){
            cost[i] = cost[0];
        }
     }

     cout << "Enter number of priority levels: ";
     in >> numberOfPriorities;
     priorityCutoffs = new int[numberOfPriorities];
     for(int i = 0; i < numberOfPriorities - 1; i++)
     {    
          cout << "Maximum page value of priority level " << i + 1 << ": ";
          in >> priorityCutoffs[i];
          while(i > 0 && priorityCutoffs[i-1] >= priorityCutoffs[i])
          {
               cout << "Warning: this value is less than or equal to the value";
               cout << " of the previous cutoff." << endl;
               cout << "Please insert a value greater than the previous: ";
               in >> priorityCutoffs[i];
          }
     }
     priorityCutoffs[numberOfPriorities-1] = maxPages;
     cout << endl;
       
     cout << "Want to enter a seed value? [Y/N]: ";
     in >> check;
     cout << endl; 
 
     if(check == 'Y' || check == 'y'){
       cout << "Enter seed value: ";       
       in >> seed;
       cout << endl; 
       srand(seed);
     }else{
       seed = 0; 
       srand(time(0));
     }
     cout << "Want simulation info sent to file? [Y/N]: ";
     in >> check;
     cout << endl; 
     //This variable is used in the runSimulation to check if a user gives a
     //filename
     if(check == 'Y' || check == 'y'){
       checkFile = 1;
     }else 
       checkFile = 0;

}

void printResults(int runtime, int avgPrinterWait,
     printerListType *printers, ostream& outfile)
{
     outfile << "The simulation ran for " << (runtime-1) << " minute(s)." << endl;
     outfile << "In the process, " << printers->getTotalPagesPrinted() << " pages were printed." << endl;
     outfile << "This cost you $" << printers->getTotalCost() << "." << endl;
     //Shouldn't be printers, should be the printjobs
     /*outfile << "On average, the printers had to wait " << avgPrinterWait << " minutes for a job." << endl;*/
     printers->printResults(outfile, runtime);   
} 

void runSimulation(){

     //Variables
     int maxPages,numOfPrinters,numOfPrintJobs,clock = 1,pageNum;
     int maintenanceLimit, maintenanceTime, failureTime, printJobs;
     int numberOfPriorities, *priorityCutoffs;
     double failureProb, avgJobs;
     int *printRate;
     double *cost, *poissonDist, *pageDist;
     unsigned int seed;
     int requestNumber = 1, printerID;
     ofstream outfile;//output file
     ifstream inputfile;//input file
     int checkFile;//tracks if filename was given
     ostream* out = &cout;//Prints to specified location 
     istream* in = &cin;//reads from specified location    
     char check; 
     
    //Checks if the user wants to read in from a file
     cout<< "Want simulation parameters inputted from a file? [Y/N]: ";
     cin>> check;
     cout << endl;
   
     if(check == 'Y' || check == 'y'){
        char filename[30];
        cout<<"Enter file name: ";
        cin >> filename;
        cout << endl;
        inputfile.open(filename);
        while(inputfile.fail()){
            cerr<<"Problem with input file."<<endl;
            cout << "Enter file name: ";
            cin >> filename;
            cout << endl;
            inputfile.open(filename);
        }
        in = &inputfile;
     }         

     //Gets initial values from user
     setSimulationParameters(*in,maxPages, printRate, cost, numOfPrinters, numOfPrintJobs, seed, 
          checkFile, maintenanceLimit, maintenanceTime, failureProb, failureTime, numberOfPriorities, priorityCutoffs, avgJobs);
     //Decides if the user wants to enter a file name 
     //then opens said file
     if(checkFile == 1){
       char file[30];
       cout << "Enter file name: ";
       *in >> file;
       cout << endl;
       outfile.open(file);
       //If there is an issue with the filename asks for another
       while(outfile.fail()){
          cerr<<"Problem with output file."<<endl;
          cout << "Enter file name: ";
          *in >> file;
          cout << endl;
          outfile.open(file);
       }
       out = &outfile;//changes which location is sent to functions
     } 
     
     //Sets up all distributions
     int k = findKMax(avgJobs);
     poissonDist = new double[k+1];
     setUpDist(poissonDist,k,avgJobs);
     pageDist = new double[numberOfPriorities];
     setUpPageDist(pageDist, numberOfPriorities);
 
     printRequestType printJob;
     waitingQueue pWaitingQueue(numberOfPriorities);
     int printJobsLeft = numOfPrintJobs;//holds total number of print jobs
     //sets up list of # printers 
     printerListType printers(numOfPrinters, printRate, cost, maintenanceLimit, maintenanceTime, failureProb, failureTime);
     //after each run through of the loop check to see if all the 
     //print jobs have been completed, thus the simulation is finished
     //if no more print jobs AND no busy printers AND no jobs in the queue
     while(printJobsLeft > 0 || printers.getNumberOfBusyPrinters() != 0 ||
         pWaitingQueue.size() != 0){
         //Update the printers in use by decrementing the pages to print 
         //by the print rate
         printers.updatePrinters(clock,*out);
            
         //Get the number of pages of the print job if print jobs available
         if(printJobsLeft > 0){
            //Gets the number of print jobs that arrived
            printJobs = findPrintJobs(poissonDist, k);
            if(printJobs > 0)
               for(int i = 1; i <= printJobs; i++){
                   //get the number of pages of that print job
                   pageNum = printJobArrival(maxPages,numberOfPriorities,priorityCutoffs,pageDist);
                   //add print job to the queue
                   printJob.setPrintRequestType(priorityCutoffs,numberOfPriorities,pageNum,requestNumber);
                   pWaitingQueue.push(printJob, clock, *out);
	              printJobsLeft--;//decrement print jobs left
                   requestNumber++;//print job id number
               }
           }

         //if there are print jobs in the queue and a printer is free
         //pair the next print job with a free printers
         printerID = printers.getFreePrinterID();//get free printer
         while(printerID != -1 && !pWaitingQueue.empty()){
               printJob = pWaitingQueue.front();//get print job in front
               //move print job to printer
               printers.setPrinterBusy(printerID,printJob,printJob.getNumberOfPages(),clock, *out);
               pWaitingQueue.pop(printJob, clock, *out);
               printerID = printers.getFreePrinterID();//check for free printer
         }
                       
  
         clock++;//update the clock time 
      }
     

      //This needs a value. I recommend allowing each printer to know how long is has waiting
      //and making a function that calls that value. Then, before printResults is called,
      //do a for loop like I did above for the other values and divide for the average.
      int avgPrinterWait = 0;

      printResults(clock, avgPrinterWait,&printers, *out);

      //If a filename was given make sure to close it
      if(checkFile==1)
        outfile.close();
     if(check == 'Y' || check == 'y')
        inputfile.close();
}     
