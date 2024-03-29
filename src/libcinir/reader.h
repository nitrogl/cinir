/*
 * A Reader of INI files.
 * 
 * Copyright (C) 2021  Roberto Metere, Newcastle <roberto@metere.it>
 */

#ifndef LIBCINIR_READER_H
#define LIBCINIR_READER_H
//-----------------------------------------------------------------------------

#include <string>
#include <vector>
#include "section.h"
//-----------------------------------------------------------------------------

namespace cinir {
/**
 * Automatically parses ini file.
 * Sections must be enclosed in square brackets, fields are key-value pairs separated by '=', and comments start with semicolon, ';'.
 */
class Reader
{
public:
  /**
   * Initialise the ini file to the internal structure.
   * 
   * @param fileName the ini file name to read
   */
  Reader(const std::string fileName = "");
  
  /**
   * Destructor
   */
  virtual ~Reader();
  
  /**
   * Read from the file provided and populate the internal structure.
   * 
   * @param fileName the ini file name to read from
   */
  void read(const std::string fileName);
  
  /**
   * Get the sections in the ini file
   */
  std::vector<Section*> sections() const;
  
  /**
   * Get a section by its name.
   * 
   * @param name the section's name to look for
   * @return the section with given name
   */
  Section* section(const std::string &name) const;
  
  /**
   * Tests if the ini file contains a section with given name.
   * 
   * @param name the section's name to look for
   * @return <code>true</code> if a section with given name is found
   */
  bool hasSection(const std::string &name) const;
  
  /**
   * Add a section to the reader.
   * 
   * @param section the section to add
   */
  void addSection(Section *section);
  
  /**
   * Print out the parsed ini file.
   * It will be stripped of comments and extra spaces.
   */
  void print() const;
  
protected:
  std::vector<Section*> _sections; ///< The sections parsed from the ini file
};
//-----------------------------------------------------------------------------

} // namespace
#endif // LIBCINIR_READER_H
