#include "color.h"
#include "data_unit.h"
#include "define.h"
#include <stdio.h>
#include <string.h>

void show_help()
{
    printf("Usage: uconv NUMBER[SUFFIX]\n");
    printf("   or: uconv OPTION\n");
    printf("\n");
    printf("OPTIONS:\n");
    printf("  -h, --help     display this help and exit\n");
    printf("  -v, --version  output version information and exit\n");
}

void show_version()
{
    printf("uconv 0.0.1\n");
}

RET_CODE_E convert(char *arg)
{
    RET_CODE_E ret = convert_data_unit(arg);
    RETURN_IF_ERR(ret);

    return RET_OK;
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        show_help();
        return RET_ERR_PARAM;
    }

    if (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help")) {
        show_help();
        return RET_OK;
    }

    if (!strcmp(argv[1], "-v") || !strcmp(argv[1], "--version")) {
        show_version();
        return RET_OK;
    }

    RET_CODE_E ret = convert(argv[1]);
    if (ret == RET_ERR_PARAM) {
        printf("uconv: invalid value '%s'\n\n", argv[1]);
        show_help();
        return RET_ERR_PARAM;
    }
    if (ret != RET_OK) {
        printf(COLOR_FG_RED "ERROR: %d\n" COLOR_RESET, ret);
    }

    return RET_OK;
}
