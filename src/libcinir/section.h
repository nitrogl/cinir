/*
 * A Section.
 * 
 * Copyright (C) 2021  Roberto Metere, Newcastle <roberto@metere.it>
 */

#ifndef LIBCINIR_SECTION_H
#define LIBCINIR_SECTION_H
//-----------------------------------------------------------------------------

#include <string>
#include <map>
#include "field.h"
//-----------------------------------------------------------------------------

namespace cinir {

/**
 * A section contains fields (key-value pairs).
 * Sections must be enclosed by square brackets.
 */
class Section
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
   * Test if the section is global.
   * A section is global if its name is the empty string (fields not preceded by section name).
   * 
   * @return <code>true</code> if the key is present
   */
  bool isGlobal() const;
  
  /**
   * Get the fields related to the section.
   * A field is a key-value pair, i.e. "key=value".
   * 
   * @return the fields as a map key-value
   */
  FieldSet fields() const;
  
  /**
   * Get the value of a field with given key.
   * 
   * @param key the key of the field
   * @return the value mapped with key
   */
  std::string field(const std::string &key) const;
  
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
   * @param field the field to add
   */
  void addField(const Field field);
  
  /**
   * Add a new field (key-value pair) to this section.
   * 
   * @param key the key to populate (lvalue)
   * @param value the value associated to the key (rvalue)
   */
  void addField(const std::string key, const std::string value);
  
protected:
  std::string _name; ///< The name of the section
  FieldSet _fields;  ///< The fields (key-value pairs) in the section
};
//-----------------------------------------------------------------------------

} // namespace
#endif // LIBCINIR_SECTION_H
