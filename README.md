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
```
