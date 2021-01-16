#include <stdio.h>
#define ERROR_TRUE    0x00
#define ERROR_FALSE   0x01

int IsRegular(char *Array, const char *expression)
{
    int isRegular = ERROR_TRUE;
	int i = 0;
    int j = 0;
    char key;

	for (; '\0' != expression[j]; j++)
	{
        if ('\0' == Array[i])
		{
			isRegular=ERROR_FALSE;
			break;
		}

		if ('.' == expression[j])
		{
			i++;
			continue;
		}
		else if ('*' == expression[j])
		{
			key = expression[j - 1];
			if ('.' == key)
			{
				key = Array[i - 1];
			}
            while('\0' != Array[i])
			{
				if (Array[i] != key)
				{
					break;
				}

				i++;
			}
		}
		else
		{
			if (Array[i] != expression[j])			
			{
                if ('*' != expression[j + 1])
				{
					isRegular=ERROR_FALSE;
					break;
				}
			}
     		i++;
		}
	}

    if ('\0' != Array[i])
    {
        isRegular=ERROR_FALSE;
    }

    return isRegular;
}

void Test(char *Array, char *expression)
{
	int isRegular = IsRegular(Array, expression);

    if (ERROR_TRUE == isRegular)
	{
		printf("True\r\n");
	}
    else
	{
		printf("False\r\n");
	}

    return;
}

int main(int argc, char *argv[])
{
	//Test("aa", "a");
	//Test("aa", "a*");
	//Test("aa", ".*");
	//Test("aab", "c*a*b");
	Test("mississippi", "mis*is*p*.");

    return 0;
}
