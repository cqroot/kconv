#include "strutil.h"
#include <stdio.h>
#include <string.h>

bool str_has_suffix(const char *str, const char *suf)
{
    if (!str || !suf) {
        return false;
    }

    size_t lstr = strlen(str);
    size_t lsuf = strlen(suf);
    if (lstr < lsuf) {
        return false;
    }

    if (strstr(str + lstr - lsuf, suf)) {
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

    char c = s[0];
    while (c != '\0') {
        if (c < '0' || c > '9') {
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
