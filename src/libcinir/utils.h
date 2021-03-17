/*
 * Generic exception.
 * 
 * Copyright (C) 2016  Roberto Metere, Glasgow <roberto.metere@strath.ac.uk>
 */

#ifndef LIBCINIR_UTILITIES_H
#define LIBCINIR_UTILITIES_H
//-----------------------------------------------------------------------------

#include <string>
//-----------------------------------------------------------------------------

namespace cinir {
/**
 * Utility functions. It includes:
 *  - trim
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
};
//-----------------------------------------------------------------------------

} // namespace
#endif // LIBCINIR_UTILITIES_H
