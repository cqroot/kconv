#ifndef __STRUTIL_H
#define __STRUTIL_H

#include <stdbool.h>

bool StrHasPrefix(const char *str, const char *prefix);
bool StrHasSuffix(const char *str, const char *suffix);
bool StrIsInteger(const char *s);
bool StrIsNumber(const char *s);
int StrTrimRight(char *s, const char c);

#endif /* ifndef __STRUTIL_H */
