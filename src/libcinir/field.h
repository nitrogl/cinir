/*
 * Field and FieldSet.
 * 
 * Copyright (C) 2021  Roberto Metere, Newcastle <roberto@metere.it>
 */

#ifndef LIBCINIR_FIELD_H
#define LIBCINIR_FIELD_H
//-----------------------------------------------------------------------------

#include <string>
#include <map>
//-----------------------------------------------------------------------------

namespace cinir {

/**
 * A field is a key-value pair.
 */
typedef std::pair<std::string, std::string> Field;
typedef std::map<std::string, std::string> FieldSet;

#define fieldKey(a) a.first
#define fieldValue(a) a.second
//-----------------------------------------------------------------------------

} // namespace
#endif // LIBCINIR_FIELD_H
