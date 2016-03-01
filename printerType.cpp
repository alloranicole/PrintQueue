/* Group 1
 * Taylor AB and Geoffrey P
 * Implementation file of the printerType class
 * The class that defines what variables and methods a printer has available to
 * it
 */

#include <iostream>
#include <string>
#include <cstdlib>

#include "printerType.h"

using namespace std;


printerType::printerType(){
       status = "free";
       maintenanceStatus = "isWorking";
       failureStatus = "printing";
       maintenanceLimit = 0;
       mLValue = 0;
       maintenanceTime = 0;
       mTValue = 0;
       failureProb = 0;
       failureTime = 0;
       fTValue = 0;
       cost = 0;
       pagesToPrint = 0;
       printRate = 0;
       totalPagesPrinted = 0;
       totalTime = 0;
       totalCost = 0;
       totalJobs = 0;
}

bool printerType::isFree() const{
       return (status == "free");
}

bool printerType::isInMaintenance() const{
       return (maintenanceStatus == "inMaintenance");
}

bool printerType::isOffline() const{
       return (failureStatus == "offline");
}

void printerType::setBusy(){
       status = "busy";
}

void printerType::setInMaintenance(){
       maintenanceStatus = "inMaintenance";
}

void printerType::setOffline(){
       failureStatus = "offline";
}

void printerType::setPrinting(){
       failureStatus = "printing";
}

void printerType::setIsWorking(){
       maintenanceStatus = "isWorking";
}

int printerType::getTotalTime(){
       return totalTime;
}

void printerType::setFree(){
       status = "free";
}

void printerType::setPagesToPrint(int p){
       pagesToPrint = p;
}

void printerType::setPrintRate(int p){
       printRate = p;
}

void printerType::setMaintenanceLimit(int m){
       maintenanceLimit = m;
       mLValue = m;
}

void printerType::setMaintenanceTime(int f){
       maintenanceTime = f;
       mTValue = f;
}

void printerType::setCost(double c){
       cost = c;
}

void printerType::setFailureProb(double f){
       failureProb = f;
}

void printerType::setFailureTime(int f){
       failureTime = f;
       fTValue = f;
}

int printerType::getRemainingPagesToPrint() const{
       return pagesToPrint;
}

double printerType::getTotalCost(){
       return totalCost;
}

void printerType::checkForMaintenance(ostream& outfile, int ID, int clock){
       if(maintenanceLimit <= 0 && !isInMaintenance()){
          setInMaintenance();
          outfile << "Printer " << ID << " is currently in maintenance at time "
                  << clock << endl;
       }else if(maintenanceTime > 0 && isInMaintenance())
               maintenanceTime--;
        else if(maintenanceTime==0){
               maintenanceTime = mTValue;
               maintenanceLimit = mLValue;
               setIsWorking();
               outfile << "Printer " << ID << " is out of maintenance at time "
                       << clock << endl;
       }
}

void printerType::checkForFailure(ostream& outfile, int ID, int clock){
       if(!isOffline()){
          double check;
          check = ((double) rand() / (RAND_MAX));
	  if(check <= failureProb){ 
             setOffline();
             outfile << "Printer " << ID << " failed printing and is offline at time "
                     << clock << endl;
          }   
       }else if(failureTime > 0 && isOffline())
                failureTime--;
        if(failureTime == 0){
           failureTime = fTValue;
           setPrinting();
           outfile << "Printer " << ID << " is no longer offline at time "
                        << clock << endl;
       }
}

void printerType::updateTotalJobs(){
       totalJobs++;
}

void printerType::updateTotalCost(){
       totalCost += (cost * pagesToPrint);
}
               
void printerType::decreasePagesToPrint(ostream& outfile,int ID, int clock){
       checkForFailure(outfile, ID, clock);
       if(!isOffline())
       {      
            pagesToPrint -= printRate;
            maintenanceLimit -= printRate;
            totalTime++;
            if(pagesToPrint >= 0)
            {
                  totalPagesPrinted += printRate;
            }
            else
            {
                  totalPagesPrinted += printRate + pagesToPrint;
            }
       }
}

void printerType::setCurrentPrintJob(printRequestType printJob){
       currentPrintJob = printJob;
}

int printerType::getCurrentPrintJobNumber() const{
       return currentPrintJob.getRequestNumber();
}

int printerType::getCurrentPrintJobPages() const{
       return currentPrintJob.getNumberOfPages();
}

int printerType::getTotalJobs(){
       return totalJobs;
}

int printerType::getTotalPagesPrinted()
{
     return totalPagesPrinted;
}















