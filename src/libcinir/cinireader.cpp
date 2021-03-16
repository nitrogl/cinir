/*
 * A bucket (vector)
 * 
 * Copyright (C) 2015  Roberto Metere, Glasgow <roberto.metere@strath.ac.uk>
 */

#include <iostream>
#include <fstream>
#include "exception.h"
#include "utils.h"
#include "cinireader.h"
//-----------------------------------------------------------------------------

CIniReader::CIniReader(const std::string fileName)
{
  if (fileName != "") {
    this->read(fileName);
  }
}
//-----------------------------------------------------------------------------

CIniReader::~CIniReader()
{
  for (CIniSection *s : this->_sections) {
    delete(s);
  }
}
//-----------------------------------------------------------------------------

void CIniReader::read(const std::string fileName)
{
  std::ifstream iniFile(fileName);
  CIniSection *section;
  
  if (!iniFile.is_open()) {
    throw Exception("CIniReader::read(). Cannot load ini file.", Exception::FATAL);
  }
  
  // Read line by line
  section = nullptr;
  for (std::string line; getline(iniFile, line);) {
    std::size_t fieldAt;
    
    // Skip comments
    CIniUtils::trim(line);
    if (line[0] == ';') {
      continue;
    }
    
    // Trim
    CIniUtils::trim(line);
    
    // Parse ini line
    if (line.size() > 0) {
      if (line[0] == '[') { // Section found
        if (line[line.size() - 1] != ']') {
          throw Exception("CIniReader::read(). Malformed section.", Exception::FATAL);
        }
        
        // Switch to this section
        section = new CIniSection(line.substr(1, line.size() - 2));
        this->addSection(section);
      } else {
        fieldAt = line.find_first_of("=");
        if (fieldAt == 0 || fieldAt == line.size() - 1) {
          throw Exception("CIniReader::read(). Malformed field.", Exception::FATAL);
        }
        if (fieldAt != std::string::npos) {
          if (section == nullptr) {
            section = new CIniSection("");
            this->addSection(section);
          }
          section->addField(line.substr(0, fieldAt), line.substr(fieldAt + 1));
        }
      }
    }
  }
}
//-----------------------------------------------------------------------------

std::vector<CIniSection*> CIniReader::sections() const
{
  return this->_sections;
}
//-----------------------------------------------------------------------------

CIniSection * CIniReader::section(const std::string &name) const
{
  for (CIniSection *s : this->_sections) {
    if (s->name() == name) {
      return s;
    }
  }
  
  return nullptr;
}
//-----------------------------------------------------------------------------

bool CIniReader::hasSection(const std::string &name) const
{
  for (CIniSection *s : this->_sections) {
    if (s->name() == name) {
      return true;
    }
  }
  
  return false;
}
//-----------------------------------------------------------------------------

void CIniReader::addSection(CIniSection *section)
{
  if (section == nullptr) {
    return;
  }
  
  if (this->hasSection(section->name())) {
    CIniSection *s = this->section(section->name());
    
    if (s != section) {
      std::cerr << "CIniReader::addSection(). WARNING: overwriting fields in section '" << s->name() << "'." << std::endl;
      for (std::pair<std::string, std::string> p: section->fields()) {
        s->addField(p.first, p.second);
      }
    }
    return;
  }
  
  this->_sections.push_back(section);
}
//-----------------------------------------------------------------------------

void CIniReader::print() const
{
  for (CIniSection *section: this->_sections) {
    if (section->name() != "") {
      std::cout << std::endl << "[" << section->name() << "]" << std::endl;
    }
    for (std::pair<std::string, std::string> p: section->fields()) {
      std::cout << p.first << " = " << p.second << std::endl;
    }
  }
}
//-----------------------------------------------------------------------------
