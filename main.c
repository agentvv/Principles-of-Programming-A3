#include <stdio.h>
#include "assignment3.h"

int main() {
  struct HBnode *HB1;
  HB1 = createHBlist(5, 5);
  printHBlist(HB1);
  printf("\n\n");
  struct SLnode *SL1 = flattenList(HB1);
  printSLlist(SL1);
  printf("\n\n\n");

  struct HBnode *HB2;
  HB2 = createHBlist(0, 5);
  printHBlist(HB2);
  printf("\n\n");
  struct SLnode *SL2 = flattenList(HB2);
  printSLlist(SL2);
  printf("\n\n\n");

  freeHBlist(HB1);
  freeSLlist(SL1);
  freeHBlist(HB2);
  freeSLlist(SL2);
}
