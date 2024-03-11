#include <stdio.h>

void mystrcpy(char *s, char *t)
{
    while ((*s++ = *t++) != '\0')
        ;
}

int main(int argc, char const *argv[])
{
    char str[] = "Hello";
    *str ='a';
    printf("%s\n", str);
    return 0;
}

