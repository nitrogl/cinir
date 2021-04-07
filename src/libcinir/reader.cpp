/*
 * A bucket (vector)
 * 
 * Copyright (C) 2015  Roberto Metere, Glasgow <roberto.metere@strath.ac.uk>
 */

#include <iostream>
#include <fstream>
#include "exception.h"
#include "utils.h"
#include "reader.h"

using namespace cinir;
//-----------------------------------------------------------------------------

Reader::Reader(const std::string fileName)
{
  if (fileName != "") {
    this->read(fileName);
  }
}
//-----------------------------------------------------------------------------

Reader::~Reader()
{
  for (Section *s : this->_sections) {
    delete(s);
  }
}
//-----------------------------------------------------------------------------

void Reader::read(const std::string fileName)
{
  std::ifstream iniFile;
  Section *section;
  std::size_t lineno;
  
  iniFile.open(fileName, std::ifstream::in);
  if (!iniFile.is_open()) {
    throw Exception("Custom-Ini Reader. Cannot load ini file '" + fileName + "'.", Exception::FATAL);
  }
  
  // Read line by line
  section = nullptr;
  lineno = 0;
  for (std::string line; getline(iniFile, line);) {
    std::size_t fieldAt;
    
    // Line number
    ++lineno;
    
    // Skip comments
    Utils::trim(line);
    if (line[0] == ';') {
      continue;
    }
    
    // Trim
    Utils::trim(line);
    
    // Parse ini line
    if (line.size() > 0) {
      if (line[0] == '[') { // Section found
        if (line[line.size() - 1] != ']') {
          throw Exception(fileName + ":" + std::to_string(lineno) + ". Malformed section.", Exception::FATAL);
        }
        
        // Switch to this section
        section = new Section(line.substr(1, line.size() - 2));
        this->addSection(section);
      } else {
        fieldAt = line.find_first_of("=");
        if (fieldAt == 0) {
          throw Exception(fileName + ":" + std::to_string(lineno) + ". Malformed field.", Exception::FATAL);
        }
        if (fieldAt != std::string::npos) {
          if (section == nullptr) {
            section = new Section("");
            this->addSection(section);
          }
          section->addField(line.substr(0, fieldAt), line.substr(fieldAt + 1));
        }
      }
    }
  }
}
//-----------------------------------------------------------------------------

std::vector<Section*> Reader::sections() const
{
  return this->_sections;
}
//-----------------------------------------------------------------------------

Section * Reader::section(const std::string &name) const
{
  for (Section *s : this->_sections) {
    if (s->name() == name) {
      return s;
    }
  }
  
  return nullptr;
}
//-----------------------------------------------------------------------------

bool Reader::hasSection(const std::string &name) const
{
  for (Section *s : this->_sections) {
    if (s->name() == name) {
      return true;
    }
  }
  
  return false;
}
//-----------------------------------------------------------------------------

void Reader::addSection(Section *section)
{
  if (section == nullptr) {
    return;
  }
  
  if (this->hasSection(section->name())) {
    Section *s = this->section(section->name());
    
    if (s != section) {
      std::cerr << "Reader::addSection(). WARNING: overwriting fields in section '" << s->name() << "'." << std::endl;
      for (std::pair<std::string, std::string> p: section->fields()) {
        s->addField(p.first, p.second);
      }
    }
    return;
  }
  
  this->_sections.push_back(section);
}
//-----------------------------------------------------------------------------

void Reader::print() const
{
  for (Section *section: this->_sections) {
    if (section->name() != "") {
      std::cout << std::endl << "[" << section->name() << "]" << std::endl;
    }
    for (std::pair<std::string, std::string> p: section->fields()) {
      std::cout << p.first << " = " << p.second << std::endl;
    }
  }
}
//-----------------------------------------------------------------------------
