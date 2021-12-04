#include "parser.tab.c"
#include "stdio.h"
#include "ast.h"

int start(const char *p) {
    FILE *fp = fopen( p, "r" );
    compile(fp);
    fclose(fp);
    return 0;
}
