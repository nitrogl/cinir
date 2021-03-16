#include <iostream>
#include <libcinir.h>
//-----------------------------------------------------------------------------

int main(void) {
  CIniReader reader("example.ini");
  reader.print();
  return 0;
}
//-----------------------------------------------------------------------------
