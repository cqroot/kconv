#ifndef __STRUTIL_H
#define __STRUTIL_H

#include <stdbool.h>

bool str_has_prefix(const char *str, const char *prefix);
bool str_has_suffix(const char *str, const char *suffix);
bool str_is_integer(const char *s);
bool str_is_number(const char *s);
int str_trim_right(char *s, const char c);

#endif /* ifndef __STRUTIL_H */
