/* Group 1
 * Taylor AB and Geoffrey P
 * Tests printerListType for functionality and accuracy
 */
#include <iostream>
#include <string>
#include <cstdlib>
 

#include "printerListType.h"

using namespace std;

int main()
{
      int rate[3] = {5,5,5};
      double cost[3] = {2,2,2};
      printerListType printerList(3,rate,cost,5,2,3,2);

      cout << printerList.getFreePrinterID() << endl;
      cout << printerList.getFreePrinterID() << endl;
      cout << printerList.getFreePrinterID() << endl;
      
}
