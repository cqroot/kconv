#include "data_unit.h"
#include "define.h"
#include "strutil.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char desc[16];
    char unit[3];
    bool hidden;
    double base;
} data_unit_t;

data_unit_t units[] = {
    { "Terabyte", "tB", true,  1             },
    { "Terabyte", "TB", false, 1             },
    { "Gigabyte", "gB", true,  1024          },
    { "Gigabyte", "GB", false, 1024          },
    { "Megabyte", "mB", true,  1048576       },
    { "Megabyte", "MB", false, 1048576       },
    { "Kilobyte", "kB", true,  1073741824    },
    { "Kilobyte", "KB", false, 1073741824    },
    { "Byte",     "B",  false, 1099511627776 },
    { "Bit",      "b",  false, 8796093022208 },
};

static RET_CODE_E convert(const double val, const double base)
{
    printf("val: %f, base: %f.\n", val, base);
    printf("Result:\n");
    for (int i = ARRAY_LEN(units) - 1; i >= 0; --i) {
        if (units[i].hidden) {
            continue;
        }

        char result[100] = { 0 };
        sprintf(result, "%lf", val / base * units[i].base);
        str_trim(result, '0');
        str_trim(result, '.');

        printf("  %-8s (%2s):  %s\n", units[i].desc, units[i].unit, result);
    }
    return RET_OK;
}

RET_CODE_E convert_data_unit(const char *s)
{
    for (int i = 0; i < ARRAY_LEN(units); i++) {
        if (!str_has_suffix(s, units[i].unit)) {
            continue;
        }

        char *substr = (char *)malloc(strlen(s));
        strncpy(substr, s, strlen(s) - strlen(units[i].unit));
        if (!str_is_number(substr)) {
            free(substr);
            return RET_ERR_PARAM;
        }

        RET_CODE_E ret = convert(atof(substr), units[i].base);

        free(substr);
        return RET_OK;
    }

    return RET_ERR_PARAM;
}
