/*
 * A bucket (vector)
 * 
 * Copyright (C) 2015  Roberto Metere, Glasgow <roberto.metere@strath.ac.uk>
 */

#include <iostream>
#include "utils.h"
#include "cinisection.h"
//-----------------------------------------------------------------------------

CIniSection::CIniSection(const std::string name)
{
  this->setName(name);
}
//-----------------------------------------------------------------------------

CIniSection::~CIniSection() {}
//-----------------------------------------------------------------------------

std::string CIniSection::name() const
{
  return this->_name;
}
//-----------------------------------------------------------------------------

void CIniSection::setName(const std::string name)
{
  this->_name = name;
  CIniUtils::trim(this->_name);
}
//-----------------------------------------------------------------------------

std::map<std::string, std::string> CIniSection::fields() const
{
  return this->_fields;
}
//-----------------------------------------------------------------------------

bool CIniSection::hasField(const std::string &key) const
{
  std::string k = key;
  CIniUtils::trim(k);
  return this->_fields.contains(k);
}
//-----------------------------------------------------------------------------

void CIniSection::addField(const std::string key, const std::string value)
{
  std::string k = key;
  std::string v = value;
  CIniUtils::trim(k);
  CIniUtils::trim(v);
  if (this->hasField(k)) {
    std::cerr << "CIniSection::addField(). WARNING: overwriting key '" << k << "' in section '" << this->_name << "'." << std::endl;
  }
  
  this->_fields.insert_or_assign(k, v);
}
//-----------------------------------------------------------------------------
