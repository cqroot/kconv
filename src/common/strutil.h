#ifndef __STRUTIL_H
#define __STRUTIL_H

#include <stdbool.h>

bool STR_HasPrefix(const char *str, const char *prefix);
bool STR_HasSuffix(const char *str, const char *suffix);
bool STR_IsInteger(const char *s);
bool STR_IsNumber(const char *s);
int STR_TrimRight(char *s, const char c);

#endif /* ifndef __STRUTIL_H */
