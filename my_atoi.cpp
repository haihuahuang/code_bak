
#include <iostream>
#include <stdio.h>

int myatoi(const char *str);

int main()
{
	printf("get number : %d\n", myatoi( "12345" ));
	printf("get number : %d\n", myatoi( "-12345" ));
	printf("get number : %d\n", myatoi( "a12345" ));
	printf("get number : %d\n", myatoi( "12345910101010101" ));
	printf("get number : %d\n", myatoi( "-12345910101010101" ));
	system("pause");
	return 0;
}

int myatoi(const char *str)
{
	if ( NULL == str )
	{
		printf("error, param is NULL\n");
		return 0;
	}

	int nIndex = 0;

	while ( '\0' != *(str + nIndex) )
	{
		if ( (*(str + nIndex) >= '0' && *(str + nIndex) <= '9')
		   || *(str + nIndex) == '-' 
		   || *(str + nIndex) == '+' )
		{
			break;
		}

		++nIndex;
	}

	if ( '\0' == *(str + nIndex) )
	{
		printf("warn, there is no dest \n");
		return 0;
	}

	// is negative number ?
	bool nFlag = false;

	if ( *(str + nIndex) == '-' )
	{
		nFlag = true;
		++nIndex;
	}
	else if ( *(str + nIndex) == '+' )
	{
		++nIndex;
	}

	int nRet = 0;

	while ( '\0' != *(str + nIndex) && *(str + nIndex) >= '0' && *(str + nIndex) <= '9' )
	{
		if ( nRet > INT_MAX / 10 )
		{
			return INT_MAX;
		}
		else if ( nRet < INT_MIN / 10 )
		{
			return INT_MIN;
		}
		else
		{
			if ( nRet == INT_MAX / 10 && *(str + nIndex) >= '8' )
			{
				return INT_MAX;
			}
			else if ( nRet == INT_MIN / 10 && *(str + nIndex) == '9' )
			{
				return INT_MIN;
			}
		}

		int  temp = *(str + nIndex) - '0';
		if ( nFlag )
		{
			temp *= -1;
		}

		nRet =  nRet*10 + temp;

		++nIndex;
	}

	return nRet;
}