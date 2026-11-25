#include <stdio.h>
#include <string.h>
#include <ctype.h>

enum Months {
    JAN = 1,
    FEB,
    MAR,
    APR,
    MAY,
    JUN,
    JUL,
    AUG,
    SEP,
    OCT,
    NOV,
    DEC
};

static int parse_month(const char *s) {
    char buf[64];
    size_t len = strlen(s);
    if (len == 0 || len >= sizeof(buf)) {
        return 0;
    }
    for (size_t i = 0; i < len; i++) {
        buf[i] = (char)toupper((unsigned char)s[i]);
    }
    buf[len] = '\0';

    if (strcmp(buf, "JAN") == 0 || strcmp(buf, "JANUARY") == 0) return JAN;
    if (strcmp(buf, "FEB") == 0 || strcmp(buf, "FEBRUARY") == 0) return FEB;
    if (strcmp(buf, "MAR") == 0 || strcmp(buf, "MARCH") == 0) return MAR;
    if (strcmp(buf, "APR") == 0 || strcmp(buf, "APRIL") == 0) return APR;
    if (strcmp(buf, "MAY") == 0) return MAY;
    if (strcmp(buf, "JUN") == 0 || strcmp(buf, "JUNE") == 0) return JUN;
    if (strcmp(buf, "JUL") == 0 || strcmp(buf, "JULY") == 0) return JUL;
    if (strcmp(buf, "AUG") == 0 || strcmp(buf, "AUGUST") == 0) return AUG;
    if (strcmp(buf, "SEP") == 0 || strcmp(buf, "SEPT") == 0 || strcmp(buf, "SEPTEMBER") == 0) return SEP;
    if (strcmp(buf, "OCT") == 0 || strcmp(buf, "OCTOBER") == 0) return OCT;
    if (strcmp(buf, "NOV") == 0 || strcmp(buf, "NOVEMBER") == 0) return NOV;
    if (strcmp(buf, "DEC") == 0 || strcmp(buf, "DECEMBER") == 0) return DEC;
    return 0;
}

static void print_month_days(enum Months m) {
    switch (m) {
        case JAN:
        case MAR:
        case MAY:
        case JUL:
        case AUG:
        case OCT:
        case DEC:
            printf("31 days\n");
            break;
        case APR:
        case JUN:
        case SEP:
        case NOV:
            printf("30 days\n");
            break;
        case FEB:
            printf("28 or 29 days\n");
            break;
        default:
            break;
    }
}

int main() {
    char token[128];
    if (scanf("%127s", token) == 1) {
        int m = parse_month(token);
        if (m != 0) {
            print_month_days((enum Months)m);
            return 0;
        }
    }

    const char *names[] = {
        "JAN", "FEB", "MAR", "APR", "MAY", "JUN",
        "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"
    };

    for (int m = JAN; m <= DEC; m++) {
        printf("%s: ", names[m - 1]);
        print_month_days((enum Months)m);
    }

    return 0;
}
