/*
 * Generic exception.
 * 
 * Copyright (C) 2016  Roberto Metere, Glasgow <roberto.metere@strath.ac.uk>
 */

#ifndef LIBCINIR_CINIREADER_H
#define LIBCINIR_CINIREADER_H
//-----------------------------------------------------------------------------

#include <string>
#include <vector>
#include "cinisection.h"
//-----------------------------------------------------------------------------

/**
 * Automatically parses ini file.
 * Sections must be enclosed in square brackets, fields are key-value pairs separated by '=', and comments start with semicolon, ';'.
 */
class CIniReader
{
public:
  /**
   * Initialise the ini file to the internal structure.
   * 
   * @param fileName the ini file name to read
   */
  CIniReader(const std::string fileName = "");
  
  /**
   * Destructor
   */
  virtual ~CIniReader();
  
  /**
   * Read from the file provided and populate the internal structure.
   * 
   * @param fileName the ini file name to read from
   */
  void read(const std::string fileName);
  
  /**
   * Get the sections in the ini file
   */
  std::vector<CIniSection*> sections() const;
  
  /**
   * Get a section by its name.
   * 
   * @param name the section's name to look for
   * @return the section with given name
   */
  CIniSection* section(const std::string &name) const;
  
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
  void addSection(CIniSection *section);
  
  /**
   * Print out the parsed ini file.
   * It will be stripped of comments and extra spaces.
   */
  void print() const;
  
protected:
  std::vector<CIniSection*> _sections; ///< The sections parsed from the ini file
};
//-----------------------------------------------------------------------------

#endif // LIBCINIR_CINIREADER_H
