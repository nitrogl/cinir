#include <iostream>
#include <libcinir.h>
//-----------------------------------------------------------------------------

int main(void) {
  CIniReader reader("example.ini");
    
  for (CIniSection *section: reader.sections()) {
    if (section->name() != "") {
      std::cout << std::endl << "[" << section->name() << "]" << std::endl;
    }
    for (std::pair<std::string, std::string> p: section->fields()) {
      std::cout << p.first << " = " << p.second << std::endl;
    }
  }
  
  return 0;
}
//-----------------------------------------------------------------------------
