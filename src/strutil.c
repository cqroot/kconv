#include "strutil.h"
#include <stdio.h>
#include <string.h>

bool str_has_prefix(const char *str, const char *prefix)
{
    if (!str || !prefix) {
        return false;
    }

    size_t lstr = strlen(str);
    size_t lprefix = strlen(prefix);
    if (lstr < lprefix) {
        return false;
    }

    if (strstr(str, prefix) == str) {
        return true;
    } else {
        return false;
    }
}

bool str_has_suffix(const char *str, const char *suffix)
{
    if (!str || !suffix) {
        return false;
    }

    size_t lstr = strlen(str);
    size_t lsuffix = strlen(suffix);
    if (lstr < lsuffix) {
        return false;
    }

    if (strstr(str + lstr - lsuffix, suffix)) {
        return true;
    } else {
        return false;
    }
}

bool str_is_integer(const char *s)
{
    if (!s) {
        return false;
    }

    for (int i = 0; i < strlen(s); ++i) {
        if (s[i] < '0' || s[i] > '9') {
            return false;
        }
    }

    return true;
}

bool str_is_number(const char *s)
{
    if (!s) {
        return false;
    }

    int dotcnt = 0;
    for (int i = 0; i < strlen(s); ++i) {
        if (s[i] == '.' && dotcnt == 0) {
            dotcnt++;
            continue;
        }

        if (s[i] < '0' || s[i] > '9') {
            return false;
        }
    }

    return true;
}

void str_trim(char *s, const char c)
{
    if (!s) {
        return;
    }

    for (int i = strlen(s) - 1; i >= 0; --i) {
        if (s[i] == c) {
            s[i] = '\0';
        } else {
            return;
        }
    }
    return;
}
