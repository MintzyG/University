#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "olytics.h"
#include "probe.h"
#include "exampleFunc.h"
#include "helpers.h"



// A single puzzle remains, what if I need multiple pieces of data for the function to work?
// I could just adapt the function to receive a single struct Package and then unpack it inside
// Or could take a look at c11 overloading like structure using _Generic and macros
// Or perhaps use variadic arguments to feed the function 
int main(int argc, char** argv) {

  srand(time(NULL));
  OlyticsInstance* O = CreateInstance();

  int size = 0, ceiling = 0;
  if (argc > 1) {
    for (int i = 1; i < argc; i++) {
      switch (i) {
        case 1:
          O->dataSize = strtoul(argv[1], NULL, 0);
          break;
        case 2:
          O->dataCeiling = strtoul(argv[2], NULL, 0);
          break;
      }
    }
  }

  #ifdef off
    O->logs->log_level = OFF;
  #elif warn
    O->logs->log_level = WARN;
  #elif trace
    O->logs->log_level = TRACE;
  #elif all
    O->logs->log_level = ALL;
  #endif

  O->logs->Log(O->logs, "Running GTD", __func__, WARN);
  O->GenerateTestData(O, O->dataSize, O->dataCeiling);
  
  
  O->logs->Log(O->logs, "Running OlyticsWrapper", __func__, WARN);
  int* bubbleData = O->GetTestData(O);
  O->OlyticsWrapper(O, bubble, bubbleData, O->dataSize);
  // PrintData(bubbleData, O->dataSize);
  free(bubbleData);
  
  O->logs->Log(O->logs, "Running OlyticsWrapper for the second time", __func__, WARN);
  int* bubbleDataTwo = O->GetTestData(O);
  PrintData(bubbleDataTwo, O->dataSize);
  O->OlyticsWrapper(O, bubble, bubbleDataTwo, O->dataSize);
  // PrintData(bubbleData, O->dataSize);
  free(bubbleDataTwo);

  O->ProbeDataByIndex(O, 0);
  O->ProbeDataByIndex(O, 1);
  O->logs->CloseLogs(O->logs);
  return 0;
}
