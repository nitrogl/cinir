/*
 * A bucket (vector)
 * 
 * Copyright (C) 2015  Roberto Metere, Glasgow <roberto.metere@strath.ac.uk>
 */

#include "utils.h"

using namespace cinir;
//-----------------------------------------------------------------------------

void Utils::trim(std::string &s, const char* trimSpaces)
{
  s.erase(s.find_last_not_of(trimSpaces) + 1);
  s.erase(0, s.find_first_not_of(trimSpaces));
}
//-----------------------------------------------------------------------------

std::vector<std::string> Utils::explode(const std::string &s, const std::string separator)
{
  std::size_t commaAt, tokenStarts;
  std::vector<std::string> tokens;
  std::string token;
  tokenStarts = 0;
  
  commaAt = s.find(separator);
  while (commaAt != std::string::npos) {
    token = s.substr(tokenStarts, commaAt - tokenStarts);
    if (token == "") {
      break;
    }
    tokens.push_back(token);
    tokenStarts = commaAt + separator.size();
    commaAt = s.find(separator, tokenStarts);
  }
  if (tokenStarts < s.size()) {
    tokens.push_back(s.substr(tokenStarts, commaAt - tokenStarts));
  }
  
  return tokens;
}
//-----------------------------------------------------------------------------
