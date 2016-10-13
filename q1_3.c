#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

bool is_elements_of_string(char * str1, char * str2)
{
    int len1, len2, i, j;
    char tmp;
    bool ret = true;
    bool *flag;

    len1 = strlen(str1);
    len2 = strlen(str2);

    /* First check if the lengthes of strings are the same */
    if( len1 == len2 )
        {
        flag = (bool*)malloc(len1 * sizeof(bool));
        for( i = 0; i < len1; i++ )
            {
            flag[i] = false;
            }

        /* Travel all characters of two strings */
        for( i = 0; i < len1; i++ )
            {
            tmp = *(str1 + i);
            for( j = 0; j < len1; j++ )
                {
                if( ( tmp == *( str2 + j ) ) &&
                    ( false == flag[j] ) )
                    {
                    flag[j] = true;
                    break;
                    }

                /* If the character in current index of str1 still can not find a
                 * suitable place in str2 then it means that string can't be the same
                 * if the string is rearrange */
                if( j == len1 - 1)
                    {
                    ret = false;
                    }
                }
            if( ret == false )
                {
                break;
                }
            }

        free(flag);
        }
    else
        {
        ret = false;
        }

    return ret;
}

#define STRLENGTH 20
void main()
{
    char str1[STRLENGTH] = "asdfqwerzxcv";
    char str2[STRLENGTH] = "qwerasdfvcxz";
    char str3[STRLENGTH] = "qwerasdf";
    char str4[STRLENGTH] = "qwerasdfqwer";

    printf("str1: str2 = %s\n", is_elements_of_string(str1, str2) ? "yes" : "no");
    printf("str1: str3 = %s\n", is_elements_of_string(str1, str3) ? "yes" : "no");
    printf("str1: str4 = %s\n", is_elements_of_string(str1, str4) ? "yes" : "no");

}
