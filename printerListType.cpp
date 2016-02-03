/* Group 1
 * Taylor AB and Geoffrey P
 * Implementation file of the printerListType class
 */

#include <iostream>
#include <string>
#include <cstdlib> 

#include "printerListType.h"

using namespace std;

printerListType::printerListType(int num){
      numOfPrinters = num;
      printers = new printerType[num];
}

printerListType::~printerListType(){
      delete [] printers;
}

printerListType::getFreePrinterID() const{
      int printerID = -1;
      
      for(int i = 0; i < numOfPrinters; i++)
         if(printers[i].isFree()){
           printerID = i;
           break;
           }

      return printerID;
}

printerListType::setPrinterBusy(int printerID, printRequestType printJob,
                                int pages, int clock, ostream& outfile){
      printers[printerID].setBusy();
      printers[printerID].setPagesToPrint(pages);
      printers[printerID].setCurrentPrinter(printJob);
      outfile << "Printer " << printerID + 1 << " now printing Print Job " <<
                 printJob.getPrintJobNumber() << " of \n" << 
                 printJob.getPages() << " pages, at time " << clock << endl;
}

printerListType::updatePrinters(int clock, ostream& outfile){
      
      for(int i = 0; i < numOfPrinters; i++)
         if(!printers[i].isFree()){
           printers[i].decreasePagesToPrint();
           if(printers[i].getRemainingPagesToPrint() <= 0){
              outfile << "Printer " << (i + 1) << " completed Print Job " <<
                         printers[i].getCurrentPrintJobNumber() << " of \n"
                      << printers[i].getCurrentPrintJobPages() << 
                         " pages, at time " << clock << endl; 
             printers[i].setFree();
           }
         }
}






