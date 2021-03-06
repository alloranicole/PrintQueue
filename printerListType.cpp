/* Group 1
 * Taylor AB and Geoffrey P
 * Implementation file of the printerListType class
 * The class that creates and maintains the list of printers available to print
 */

#include <iostream>
#include <string>
#include <cstdlib>
 

#include "printerListType.h"

using namespace std;

printerListType::printerListType(int num, int* printRate, double* cost, 
                                 int maintenanceLimit, int maintenanceTime,
                                 double failureProb, int failureTime){
      numOfPrinters = num;
      printers = new printerType[num];
      for(int i = 0; i < num; i++){
          printers[i].setPrintRate(printRate[i]);
          printers[i].setCost(cost[i]);
          printers[i].setMaintenanceLimit(maintenanceLimit);
          printers[i].setMaintenanceTime(maintenanceTime);
          printers[i].setFailureProb(failureProb);
          printers[i].setFailureTime(failureTime);
      }
}

printerListType::~printerListType(){
      delete [] printers;
}

int printerListType::getFreePrinterID() const{
      int printerID;
      int free[numOfPrinters]; //holds the IDs that were free
      int wasFree = 0; //holds how many IDs were free
      int random;

      for(int i = 0; i < numOfPrinters; i++)
      {
            if(printers[i].isFree() && !printers[i].isInMaintenance() &&
            !printers[i].isOffline())
            {
                  free[wasFree] = i;
                  wasFree++;
            }
      }

      if (wasFree == 0)
            printerID = -1;
      else if(wasFree == 1)
            printerID = free[0];
      else
      {     
            random = rand() % wasFree;
            printerID = free[random];
      }
      
      
      //Original Method that finds the first available printer
      //for(int i = 0; i < numOfPrinters; i++)
         //if(printers[i].isFree() && !printers[i].isInMaintenance() && 
           //!printers[i].isOffline()){
           //printerID = i;
           //break;
           //}

      return printerID;
}
     
int printerListType::getNumberOfBusyPrinters() const{
      int busyPrinters = 0;
      for(int i = 0; i < numOfPrinters; i++)
          if(!printers[i].isFree())
             busyPrinters++;
      
      return busyPrinters;
}


void printerListType::setPrinterBusy(int printerID, printRequestType printJob,
                                int pages, int clock, ostream& outfile){
      printers[printerID].setBusy();
      printers[printerID].setPagesToPrint(pages);
      printers[printerID].setCurrentPrintJob(printJob);
      printers[printerID].updateTotalCost();
      printers[printerID].updateTotalJobs();
      //output what printer has what print job
      outfile << "Printer " << printerID + 1 << " now printing Print Job " <<
                 printJob.getRequestNumber() << " of \n" << 
                 printJob.getNumberOfPages() << " pages, at time " << clock << endl;
}

int printerListType::getTotalPagesPrinted(){
      int totalPagesPrinted = 0;
      for(int i = 0; i < numOfPrinters; i++)
      {
            totalPagesPrinted += printers[i].getTotalPagesPrinted();
      }
      return totalPagesPrinted;
}

int printerListType::getTotalCost(){
      int totalCost = 0;
      for(int i = 0; i < numOfPrinters; i++)
      {
            totalCost += printers[i].getTotalCost();
      }
      return totalCost;
}

void printerListType::updatePrinters(int clock, ostream& outfile){
      for(int i = 0; i < numOfPrinters; i++){
         if(!printers[i].isFree()){
           printers[i].decreasePagesToPrint(outfile, (i+1), clock);
           if(printers[i].getRemainingPagesToPrint() <= 0){
              //output what print job was completed and by what printer
              outfile << "Printer " << (i + 1) << " completed Print Job " <<
                         printers[i].getCurrentPrintJobNumber() << " of \n"
                      << printers[i].getCurrentPrintJobPages() << 
                         " pages, at time " << clock << endl; 
             printers[i].setFree();
           }
         }
           
          if(printers[i].isFree())
           printers[i].checkForMaintenance(outfile,(i + 1),clock);
      }
}

void printerListType::printResults(ostream& outfile, int runtime){
      double percentage;
      for(int i = 0; i < numOfPrinters; i++){
          outfile << "Printer " << (i+1) << " handled " << printers[i].getTotalJobs() << " jobs, ";
          outfile << "printed " << printers[i].getTotalPagesPrinted() << " pages, ";
          outfile << "and printed $" << printers[i].getTotalCost() << " worth of pages." << endl;
          outfile << "It printed for " << printers[i].getTotalTime() << " minutes, ";
          percentage = (double) printers[i].getTotalTime()/runtime;
          percentage *= 100;
          outfile << "and was available "<< percentage << "% of the time." << endl;
       }
}




