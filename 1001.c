// A+B format

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
    int a, b;
    scanf("%d%d", &a, &b);
    int c = a + b;
    //Both a anb b is between 10^-6 and 10^6
    //The max length of a+b is 7, plus negative symbol and '/0'
    char str[9];

    //char *  itoa ( int value, char * str, int base );
    //This function is not in standard library,

    //But we can use function sprintf() to replace it
    //int sprintf ( char * str, const char * format, ... );
    //The return value is the number of char(except the appended at the end of the string)
    //If failed, it will return a negative number

    //And we can use atoi(), atof() to convert string to int or double
    

    sprintf(str, "%d", c);

    //In the worst case, we need to add 2 ','
    char solution[11];

    //sizeof() and strlen()
    int maxLength = strlen(str);
    int count = 0;
    int index = 0;
    for(int i=maxLength-1; i>=0; i--){
        if(count == 3 && str[i]!='-'){
            solution[index++] = ',';
            count = 0;
        }
        solution[index++] = str[i];
        count++;
    }
    solution[index] = '\0';

    for(int i=strlen(solution)-1; i>=0; i--)
        printf("%c", solution[i]);

    return 0;
}