#include "strutil.h"
#include <stdio.h>
#include <string.h>

bool str_has_prefix(const char *str, const char *prefix)
{
    if (!str || !prefix) {
        return false;
    }

    size_t len_str = strlen(str);
    size_t len_prefix = strlen(prefix);
    if (len_str < len_prefix) {
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

    size_t len_str = strlen(str);
    size_t len_suffix = strlen(suffix);
    if (len_str < len_suffix) {
        return false;
    }

    if (strstr(str + len_str - len_suffix, suffix)) {
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

int str_trim_right(char *s, const char c)
{
    size_t len_str = strlen(s);

    if (!s) {
        return len_str + 1;
    }

    for (int i = strlen(s) - 1; i >= 0; --i) {
        if (s[i] == c) {
            s[i] = '\0';
        } else {
            return i + 1;
        }
    }
    return 1;
}
