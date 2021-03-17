/**
 * Copyright (C) 2019-2020 Roberto Metere
 * Newcastle Upon Tyne, UK <roberto.metere@ncl.ac.uk>
 */

#ifndef CINIR_H
#define CINIR_H

#define LIB_CINIR_LIBRARY "Custom-Ini Reader. The library"
#define CINIR_NAMESPACE_CLASS(c) namespace cinir { class c; } using namespace cinir;

// ---------------------------------------------------------------------

// Debug defines
#ifdef DEBUG
  #define printd(format, ...) { fprintf(stderr, "%s:%d:%s(): " format "\n", __FILE__, __LINE__, __func__, __VA_ARGS__); fflush(stderr); }
#else
  #define printd(format, ...) /* do nothing */
#endif
// ---------------------------------------------------------------------

#endif // CINIR_H
 
