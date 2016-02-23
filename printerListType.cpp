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
                                 int maintenanceLimit, int maintanenceTime,
                                 double failureProb, int failureTime){
      numOfPrinters = num;
      printers = new printerType[num];
      for(int i = 0; i < num; i++){
          printers[i].setPrintRate(printRate[i]);
          printers[i].setCost(cost[i]);
          printers[i].setMaintenanceLimit(maintenanceLimit);
          printers[i].setMaintenanceTime(maintanenceTime);
          printers[i].setFailureProb(failureProb);
          printers[i].setFailureTime(failureTime);
      }
}

printerListType::~printerListType(){
      delete [] printers;
}

int printerListType::getFreePrinterID() const{
      int printerID = -1;
      
      for(int i = 0; i < numOfPrinters; i++)
         if(printers[i].isFree() && !printers[i].isInMaintenance() && 
            !printers[i].isOffline()){
           printerID = i;
           break;
           }

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
      //output what printer has what print job
      outfile << "Printer " << printerID + 1 << " now printing Print Job " <<
                 printJob.getRequestNumber() << " of \n" << 
                 printJob.getNumberOfPages() << " pages, at time " << clock << endl;
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






