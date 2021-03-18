/*
 * Generic exception.
 * 
 * Copyright (C) 2016  Roberto Metere, Glasgow <roberto.metere@strath.ac.uk>
 */

#ifndef LIBCINIR_UTILITIES_H
#define LIBCINIR_UTILITIES_H
//-----------------------------------------------------------------------------

#include <string>
#include <vector>
//-----------------------------------------------------------------------------

namespace cinir {
/**
 * Utility functions. It includes:
 *  - trim
 *  - explode
 */
class Utils
{
public:
  /**
   * Remove leading and ending space characters from a string.
   * 
   * @param s the string to trim
   * @param trimSpaces all the space characters to remove
   */
  static void trim(std::string &s, const char* trimSpaces = " \t\n\r\f\v");
  
  /**
   * Explode a string into tokens separated by a given substring.
   * It skips empty tokens.
   * 
   * @param s the string to explode
   * @param separator the separator string
   * @return the string tokens in a vector
   */
  static std::vector<std::string> explode(const std::string &s, const std::string separator = ",");
};
//-----------------------------------------------------------------------------

} // namespace
#endif // LIBCINIR_UTILITIES_H
