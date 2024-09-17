#ifndef __STRUTIL_H
#define __STRUTIL_H

#include <stdbool.h>

bool str_has_suffix(const char *str, const char *suf);
bool str_is_integer(const char *s);
bool str_is_number(const char *s);
void str_trim(char *s, const char c);

#endif /* ifndef __STRUTIL_H */
