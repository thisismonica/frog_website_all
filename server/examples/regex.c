/*
 * Simple regular expression matching.
 *
 * From:
 *   The Practice of Programming
 *   Brian W. Kernighan, Rob Pike
 *
 */


static int matchhere(char*,char*);

static int matchstar(int c, char *re, char *text)
{
    do
    {
        if (matchhere(re, text))
            return 1;
    }
    while (*text != '\0' && (*text++ == c || c== '.'));
    return 0;
}

static int matchhere(char *re, char *text)
{
    if (re[0] == '\0')
        return 0;
    if (re[1] == '*')
        return matchstar(re[0], re+2, text);
    if (re[0] == '$' && re[1]=='\0')
        return *text == '\0';
    if (*text!='\0' && (re[0]=='.' || re[0]==*text))
        return matchhere(re+1, text+1);
    return 0;
}

/*
 * Match function: return 1 if matched else 0
*/
int match(char *re)
{
    /*
     * Add constant string for testing
     */
    char str[] = "bug";
    char *text = str;

    if (re[0] == '^')
        return matchhere(re+1, text);
    do
    {
        if (matchhere(re, text))
            return 1;
    }
    while (*text++ != '\0');
    return 0;
}

