#include <stdio.h>

int main(void)
{
    char *s= "HI!";

    printf("%c\n", *(s+1));
    printf("%s\n", s+1);
    printf("%s\n", &s[0]);

    
}

// string ddoesnt exist insteap string of string use char*