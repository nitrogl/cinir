/*
 * Generic exception.
 * 
 * Copyright (C) 2016  Roberto Metere, Glasgow <roberto.metere@strath.ac.uk>
 */

#ifndef LIBCINIR_Section_H
#define LIBCINIR_Section_H
//-----------------------------------------------------------------------------

#include "cinir.h"
CINIR_NAMESPACE_CLASS(Section)
//-----------------------------------------------------------------------------

#include <string>
#include <map>
#include "section.h"
//-----------------------------------------------------------------------------

/**
 * A section contains fields (key-value pairs).
 * Sections must be enclosed by square brackets.
 */
class cinir::Section
{
public:
  /**
   * Create a section. It is delimited by square brackets.[]
   */
  Section(const std::string name = "");
  virtual ~Section();
  
  /**
   * Sections are identified by names.
   * Two sections with the same name are considered the same.
   * 
   * @return the name of the section
   */
  std::string name() const;
  
  /**
   * Set the name of the section.
   * 
   * @param name the name to assign to the section
   */
  void setName(const std::string name);
  
  /**
   * Get the fields related to the section.
   * A field is a key-value pair, i.e. "key=value".
   * 
   * @return the fields as a map key-value
   */
  std::map<std::string, std::string> fields() const;
  
  /**
   * Test if any field with given key is set in the section
   * 
   * @param key the key to test
   * @return <code>true</code> if the key is present
   */
  bool hasField(const std::string &key) const;
  
  /**
   * Add a new field (key-value pair) to this section.
   * 
   * @param key the key to populate (lvalue)
   * @param value the value associated to the key (rvalue)
   */
  void addField(const std::string key, const std::string value);
  
protected:
  std::string _name;                          ///< The name of the section
  std::map<std::string, std::string> _fields; ///< The fields (key-value pairs) in the section
};
//-----------------------------------------------------------------------------

#endif // LIBCINIR_Section_H
