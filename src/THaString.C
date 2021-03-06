////////////////////////////////////////////////////////////////////////
//
//       THaString.C  (implementation)
//
////////////////////////////////////////////////////////////////////////

#include "THaString.h"
#include <algorithm>
#include <cctype>

#ifdef HAS_SSTREAM
#include <sstream>
#else
#include <strstream>
#endif

using namespace std;

namespace THaString {

//_____________________________________________________________________________
int CmpNoCase( const string& r, const string& s )
{
  // Case insensitive compare.  Returns -1 if "less", 0 if equal, 1 if
  // "greater".

  string::const_iterator p =  r.begin();
  string::const_iterator p2 = s.begin();

  while (p != r.end() && p2 != s.end()) {
    if (toupper(*p) != toupper(*p2))
      return (toupper(*p) < toupper(*p2)) ? -1 : 1;
    ++p;
    ++p2;
  }

  return (r.size() == s.size()) ? 0 : (r.size() < s.size()) ? -1 : 1;
}

//_____________________________________________________________________________
vector<string> Split( const string& s )
{
  // Split on whitespace.
#ifdef HAS_SSTREAM
  istringstream ist(s.c_str());
#else
  istrstream ist(s.c_str());
#endif
  string w;
  vector<string> v;

  while (ist >> w)
    v.push_back(w);
  return v;
}

//_____________________________________________________________________________
unsigned int Hex( const string& s )
{
  // Conversion to unsigned interpreting as hex.
#ifdef HAS_SSTREAM
  istringstream ist(s.c_str());
#else
  istrstream ist(s.c_str());
#endif
  unsigned int in;
  ist >> hex >> in;
  return in;
}

//_____________________________________________________________________________
string ToLower( const string& s )
{
  // Return copy of this string converted to lower case.

  string result(s);
  // The bizarre cast here is needed for newer gccs
  transform( s.begin(), s.end(), result.begin(), (int(*)(int))tolower );
  return result;
}

//_____________________________________________________________________________
string ToUpper( const string& s )
{
  // Return copy of this string converted to upper case.
  string result(s);
  transform( s.begin(), s.end(), result.begin(), (int(*)(int))toupper );
  return result;
}

//_____________________________________________________________________________
void Lower( string& s )
{
  // Convert this string to lower case

  transform( s.begin(), s.end(), s.begin(), (int(*)(int))tolower );
  return;
}

//_____________________________________________________________________________
void Upper( string& s )
{
  // Convert this string to upper case
  transform( s.begin(), s.end(), s.begin(), (int(*)(int))toupper );
  return;
}

//_____________________________________________________________________________

}
