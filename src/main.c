#include "color.h"
#include "config.h"
#include "data_unit.h"
#include "define.h"
#include "unix_timestamp.h"
#include <stdio.h>
#include <string.h>

void ShowHelp()
{
    printf("Usage: kconv [PREFIX]NUMBER[SUFFIX]\n");
    printf("   or: kconv OPTION\n");
    printf("\n");
    printf("OPTIONS:\n");
    printf("  -h, --help     display this help and exit\n");
    printf("  -v, --version  output version information and exit\n");
    printf("\n");
    printf("PREFIX and SUFFIX:\n");
    printf("  Data Unit Converter:\n");
    printf("    <NUMBER>TB  <NUMBER>tB  <NUMBER>GB  <NUMBER>gb\n");
    printf("    <NUMBER>MB  <NUMBER>mB  <NUMBER>KB  <NUMBER>kB\n");
    printf("    <NUMBER>B   <NUMBER>b\n");
    printf("  Unix Timestamp Converter:\n");
    printf("    <NUMBER>    (Length 10)\n");
}

void ShowVersion()
{
    printf("kconv %d.%d.%d\n", KCONV_VERSION_MAJOR, KCONV_VERSION_MINOR,
           KCONV_VERSION_PATCH);
}

RET_CODE_E Convert(char *arg)
{
    RET_CODE_E ret;

    ret = ConvertDataUnit(arg);
    if (ret != RET_ERR_PARAM) {
        return ret;
    }

    ret = convert_unix_timestamp(arg);
    if (ret != RET_ERR_PARAM) {
        return ret;
    }

    return RET_ERR_PARAM;
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        ShowHelp();
        return RET_ERR_PARAM;
    }

    if (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help")) {
        ShowHelp();
        return RET_OK;
    }

    if (!strcmp(argv[1], "-v") || !strcmp(argv[1], "--version")) {
        ShowVersion();
        return RET_OK;
    }

    RET_CODE_E ret = Convert(argv[1]);
    if (ret == RET_ERR_PARAM) {
        printf("kconv: invalid value '%s'\n\n", argv[1]);
        ShowHelp();
        return RET_ERR_PARAM;
    }
    if (ret != RET_OK) {
        printf(COLOR_FG_RED "ERROR: %d\n" COLOR_RESET, ret);
        return ret;
    }

    return RET_OK;
}
