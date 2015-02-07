
#include <iostream>
#include <stdio.h>

char *compress(const char *str);
char *compressA(const char *str);

int main()
{
	printf("%s\n", compress("AABBBbbbbbbbbbbCCCCFFF") );
	system("pause");
	return 0;
}

char *compressA(const char *str)
{
	if ( NULL == str )
	{
		printf("warn, param is NULL \n");
		return NULL;
	}

	int nIndex = 1;
	int nCount = 0;
	int nlength = 1;
	
	char *pcBuff = (char *)malloc( sizeof(char)*256 );
	memset( pcBuff, 0, sizeof(char) * 256 );

	while( '\0' != *(str + nIndex) )
	{
		if ( *(str + nIndex) == *(str + nIndex - nlength) )
		{
			++nlength;
			++nIndex;
			continue;
		}
		
		if ( nlength > 1 )
		{	
			if ( nCount >= 254 )
			{
				printf("error, buff size 256 is not enough \n");
				return pcBuff;
			}
			// problem if length is than 9 ???
			*(pcBuff + nCount) = nlength + '0';
			++nCount;
			
		}

		if ( nCount >= 254 )
		{
			printf("error, buff size 256 is not enough \n");
			return pcBuff;
		}
		*(pcBuff + nCount) = *(str + nIndex - 1);
		++nCount;
		++nIndex;
		nlength = 1;
	}

	if ( nlength > 1 )
	{
		if ( nCount >= 254 )
		{
			printf("error, buff size 256 is not enough \n");
			return pcBuff;
		}
		*(pcBuff + nCount) = nlength + '0';
		++nCount;
	}

	if ( nCount >= 254 )
	{
		printf("error, buff size 256 is not enough \n");
		return pcBuff;
	}
	*(pcBuff + nCount) = *(str + nIndex - 1);

	return pcBuff;
}

char *compress(const char *str)
{
	const char *pcStr = str;
	const char *pcStrNext = str + 1;
	char *pcBuff = (char *)malloc( sizeof(char)*256 );
	int nWriteCnt = 0;
	if ( NULL == pcBuff )
	{
		printf("error, line %d malloc failed \n", __LINE__);
		return NULL;
	}
	memset( pcBuff, 0, sizeof(char) * 256 );

	while ( '\0' != * pcStr )
	{
		if ( *pcStr == *pcStrNext )
		{
			++pcStrNext;
		}
		else
		{
			int nLength = pcStrNext - pcStr;
			if ( nLength > 1 )
			{
				int lengthDo = nLength;
				int nCount = 0;
				while ( lengthDo > 0 )
				{
					++nCount;
					lengthDo /= 10;
				}

				if ( nWriteCnt + nCount >= 254 )
				{
					printf("error, buff size 256 is not enough \n");
					return pcBuff - nWriteCnt;
				}
				
				pcBuff += nCount - 1; 
				while( nLength > 0 )
				{
					*pcBuff = nLength % 10 + '0' ;
					--pcBuff;
					++nWriteCnt;
					nLength /= 10;
				}
				pcBuff += nCount + 1;
			}

			if ( nWriteCnt >= 254 )
			{
				printf("error, buff size 256 is not enough \n");
				return pcBuff - nWriteCnt;
			}
			*pcBuff++ = *pcStr;
			++nWriteCnt;
			pcStr = pcStrNext++;
		}
	}

	return pcBuff - nWriteCnt;
}
