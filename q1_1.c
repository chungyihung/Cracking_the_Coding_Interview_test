#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define STRLENGTH   10

bool is_non_repeat_char_no_extra_structure( char * str)
{
    int i, j, length;
    bool ret = false;
    length = strlen( str );

    for( i = 0; i < length; i++ )
        {
        for( j = i + 1; j < length; j++ )
            {
            if( *(str + i) == *(str + j) )
                {
                ret = true;
                break;
                }
            }
        if( ret == true )
            {
            break;
            }
        }
    return ret;
}

#define ASCII_SIZE 256
bool is_non_repeat_char( char * str)
{
    int i, j, length;
    bool ret = false;
    bool exist_flag[ASCII_SIZE];
    char str_chr;

    for( i = 0; i < ASCII_SIZE; i++ )
        {
        exist_flag[i] = false;
        }

    length = strlen( str );

    for( i = 0; i < length; i++ )
        {
        str_chr = *( str + i );
        if( true == exist_flag[(int)str_chr] )
            {
            ret = true;
            break;
            }
        else
            {
            exist_flag[(int)str_chr] = true;
            }
        }

    return ret;
}

void main()
{
    char input[STRLENGTH] = "absdf";

    printf("result = %s\n", is_non_repeat_char_no_extra_structure(input)? "yes": "no" );
    printf("result = %s\n", is_non_repeat_char(input)? "yes": "no" );

}
