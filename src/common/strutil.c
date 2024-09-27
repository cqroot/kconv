#include "strutil.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool StrHasPrefix(const char *str, const char *prefix)
{
    if (!str || !prefix) {
        return false;
    }

    const size_t lenStr = strlen(str);
    const size_t lenPrefix = strlen(prefix);
    if (lenStr < lenPrefix) {
        return false;
    }

    if (memcmp(str, prefix, lenPrefix) == 0) {
        return true;
    }
    return false;
}

bool StrHasSuffix(const char *str, const char *suffix)
{
    if (!str || !suffix) {
        return false;
    }

    const size_t lenStr = strlen(str);
    const size_t lenSuffix = strlen(suffix);
    if (lenStr < lenSuffix) {
        return false;
    }

    if (memcmp(str + lenStr - lenSuffix, suffix, lenSuffix) == 0) {
        return true;
    }
    return false;
}

bool StrIsInteger(const char *s)
{
    if (!s) {
        return false;
    }

    for (size_t i = 0; i < strlen(s); ++i) {
        if (s[i] < '0' || s[i] > '9') {
            return false;
        }
    }

    return true;
}

bool StrIsNumber(const char *s)
{
    if (!s) {
        return false;
    }

    bool hasDot = false;
    for (size_t i = 0; i < strlen(s); ++i) {
        if (s[i] == '.' && !hasDot) {
            hasDot = true;
            continue;
        }

        if (s[i] < '0' || s[i] > '9') {
            return false;
        }
    }

    return true;
}

int StrTrimRight(char *s, const char c)
{
    const size_t lenStr = strlen(s);

    if (!s) {
        return lenStr + 1;
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
