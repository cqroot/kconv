#include "unix_timestamp.h"
#include "color.h"
#include "define.h"
#include "strutil.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

RET_CODE_E convert_unix_timestamp(const char *s)
{
    if (!STR_IsInteger(s)) {
        return RET_ERR_PARAM;
    }

    if (strlen(s) != 10) {
        return RET_ERR_PARAM;
    }

    time_t t = (time_t)atoi(s);
    struct tm lt;
#if defined (_WIN32) || defined (_WIN64)
    (void)localtime_s(&lt, &t);
#else
    (void)localtime_r(&t, &lt);
#endif

    char res[32];
    if (strftime(res, sizeof(res), "%Y-%m-%d %H:%M:%S", &lt) == 0) {
        return RET_FAILED;
    }

    printf(COLOR_FG_BLUE "\n" COLOR_RESET);
    printf(COLOR_FG_BLUE " ============================\n" COLOR_RESET);
    printf(COLOR_FG_BLUE "   Unix Timestamp Converter  \n" COLOR_RESET);
    printf(COLOR_FG_BLUE " ============================\n" COLOR_RESET);
    printf(COLOR_FG_CYAN "  Date" COLOR_RESET ": %s\n", res);
    return RET_OK;
}
