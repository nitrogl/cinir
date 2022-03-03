/*
 * A Section.
 * 
 * Copyright (C) 2021  Roberto Metere, Newcastle <roberto@metere.it>
 */

#include <iostream>
#include "utils.h"
#include "section.h"
#include "exception.h"

using namespace cinir;
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

bool Section::isGlobal() const
{
  return this->_name == "";
}
//-----------------------------------------------------------------------------

void Section::setName(const std::string name)
{
  this->_name = name;
  Utils::trim(this->_name);
}
//-----------------------------------------------------------------------------

FieldSet Section::fields() const
{
  return this->_fields;
}
//-----------------------------------------------------------------------------

std::string Section::field(const std::string &key) const
{
  try {
    return this->_fields.at(key);
  } catch (std::out_of_range &) {
    throw Exception("Section::field(). Fatal error: field '" + key + "' not found.", Exception::FATAL);
  }
}
//-----------------------------------------------------------------------------

bool Section::hasField(const std::string &key) const
{
  std::string k = key;
  Utils::trim(k);
  return this->_fields.contains(k);
}
//-----------------------------------------------------------------------------

void Section::addField(const Field field)
{
  this->addField(field.first, field.second);
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
