#include <iostream>
#include <libcinir.h>
//-----------------------------------------------------------------------------

int main(void) {
  Reader reader("example.ini");
    
  for (Section *section: reader.sections()) {
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
