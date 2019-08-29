#include <stdio.h>
#include <string.h>

void str_replace(char *str1, char *str2, char *str3);

int main()
{
	char str1[256] = "30 10 * * *";
	char str2[256] = "*";
	char str3[256] = "any";

	printf("%s\n",str1);		
	str_replace(str1, str2, str3);
	printf("-----\n");		
	printf("%s\n",str1);		
}

void str_replace(char *str1, char *str2, char *str3)
{
	int i,j,k,count,same;
	char *p, *q, *z;
	char temp[256];
	
	for ( i = 0; i < strlen(str1); )
	{
		p = str1+i;
		q = str2;
		if (*p == *q)
		{
			same = 1;
			for ( j = 0; j < strlen(str2); j++)
			{
				if (*p == *q)
				{
					p++;
					q++;
				}
				else
				{
					same = 0;
					break;
				}
			}
			if (same == 0)
			{
				i++;
			}
			else
			{
				sprintf(temp, "%s", p);
				z = str1+i;
				for (k = 0; k < strlen(str3); k++)
				{
					*z = str3[k];
					z++;
				}
				i += strlen(str3);
				sprintf(z, "%s", temp);
			}
		}
		else
		{
			i++;
		}
	}
}
