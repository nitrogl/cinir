#include <iostream>
#include <libcinir.h>
//-----------------------------------------------------------------------------

int main(void) {
  cinir::Reader reader("example.ini");
  
  for (cinir::Section *section: reader.sections()) {
    if (!section->isGlobal()) {
      std::cout << std::endl << "[" << section->name() << "]" << std::endl;
    }
    for (cinir::Field p: section->fields()) {
      std::cout << fieldKey(p) << " = ";
      std::cout << fieldValue(p) << std::endl;
      
      // You could split the value in tokens
      std::vector<std::string> tokens = cinir::Utils::explode(p.second, ",");
      std::size_t i = 0;
      for (std::string token : tokens) {
        std::cout << (i++ > 0 ? "," : "") << token;
      }
      std::cout << std::endl;
    }
  }
  
  return 0;
}
//-----------------------------------------------------------------------------
