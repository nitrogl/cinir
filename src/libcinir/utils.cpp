/*
 * A bucket (vector)
 * 
 * Copyright (C) 2015  Roberto Metere, Glasgow <roberto.metere@strath.ac.uk>
 */

#include "utils.h"
//-----------------------------------------------------------------------------

void CIniUtils::trim(std::string &s, const char* trimSpaces)
{
  s.erase(s.find_last_not_of(trimSpaces) + 1);
  s.erase(0, s.find_first_not_of(trimSpaces));
}
//-----------------------------------------------------------------------------
