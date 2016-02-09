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
       pagesToPrint = 0;
       printRate = 0; 
       totalTime = 0;
}

bool printerType::isFree() const{
       return (status == "free");
}

void printerType::setBusy(){
       status = "busy";
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

int printerType::getRemainingPagesToPrint() const{
       return pagesToPrint;
}

void printerType::decreasePagesToPrint(){
       pagesToPrint -= printRate;
       totalTime++;
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














