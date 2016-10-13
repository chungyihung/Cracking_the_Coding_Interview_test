#include<stdio.h>
#include<stdlib.h>

#define STRLENGTH 20

void reverse( char * str )
{
    char * strend = str;
    char tmp;

    /* check if str is valid string */
    if( str != NULL )
        {
        while( *strend != '\0' )
            {
            strend++;
            }
        strend--;
        }

    /*Note that the input str is a pointer which points to the begin of input address
     *not the begin of input address itself */
    while(str < strend )
        {
        tmp = *str;
        *str = *strend;
        *strend = tmp;
        str = str + 1;
        strend = strend - 1;
        }

}

void main()
{
    char input[STRLENGTH] = "asdfqwerzxcv";
    printf( "input = %s\n", input );
    reverse(input);
    printf( "result = %s\n", input );
}
