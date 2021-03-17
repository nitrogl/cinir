/*
 * A bucket (vector)
 * 
 * Copyright (C) 2015  Roberto Metere, Glasgow <roberto.metere@strath.ac.uk>
 */

#include <iostream>
#include "utils.h"
#include "section.h"
//-----------------------------------------------------------------------------

Section::Section(const std::string name)
{
  this->setName(name);
}
//-----------------------------------------------------------------------------

Section::~Section() {}
//-----------------------------------------------------------------------------

std::string Section::name() const
{
  return this->_name;
}
//-----------------------------------------------------------------------------

void Section::setName(const std::string name)
{
  this->_name = name;
  Utils::trim(this->_name);
}
//-----------------------------------------------------------------------------

std::map<std::string, std::string> Section::fields() const
{
  return this->_fields;
}
//-----------------------------------------------------------------------------

bool Section::hasField(const std::string &key) const
{
  std::string k = key;
  Utils::trim(k);
  return this->_fields.contains(k);
}
//-----------------------------------------------------------------------------

void Section::addField(const std::string key, const std::string value)
{
  std::string k = key;
  std::string v = value;
  Utils::trim(k);
  Utils::trim(v);
  if (this->hasField(k)) {
    std::cerr << "Section::addField(). WARNING: overwriting key '" << k << "' in section '" << this->_name << "'." << std::endl;
  }
  
  this->_fields.insert_or_assign(k, v);
}
//-----------------------------------------------------------------------------
