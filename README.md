# CIniR
Custom-Ini Reader

The cinir library loads ini files whose section names and/or field names are not necessarily known in advance, and that can grow in number.
So, the aim of cinir is to ease querying field values and looping by sections.

For developers, just include <libcinir.h> in your C++ source code after installing the library.

## Sample usage

The following example simply prints out what has been understood by the reader parsing the file "example.ini".

```cpp
#include <iostream>
#include <libcinir.h>

int main(void) {
  cinir::Reader reader("example.ini");
    
  for (cinir::Section *section: reader.sections()) {
    if (!section->isGlobal()) {
      std::cout << std::endl << "[" << section->name() << "]" << std::endl;
    }
    for (cinir::Field field: section->fields()) {
      auto [key, value] = field;
      std::cout << key << " = " << value << std::endl;
    }
  }
  
  return 0;
}
```
