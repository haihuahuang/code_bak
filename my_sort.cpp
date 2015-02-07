
#include <iostream>
#include <stdio.h>
#include <time.h>

#define ARRARY_SIZE ( 10 )
#define ARRARY_MAX  ( 99 )
#define ARRARY_MIN  ( -9 )

void BubbleSort(int aInt[], int nSize);

void BubbleSortFlag(int aInt[], int nSize);

void InsertSort(int aInt[], int nSize);

void ShellSort(int aInt[], int nSize, int nDis);

void SelectSort(int aInt[], int nSize);

void QuickSort(int aInt[], int nStart, int nEnd);

int MidFind(int aInt[], int nSize, int nValue);

void PrintArray(int aInt[], int nSize);

void GetArrValueByRand(int aInt[], int nValueMax, int nValueMin, int nSize);

int main()
{
	int anArr[ARRARY_SIZE];
	GetArrValueByRand( anArr, ARRARY_MAX, ARRARY_MIN, ARRARY_SIZE );

	PrintArray( anArr, ARRARY_SIZE );

	QuickSort(anArr, 0, ARRARY_SIZE - 1);

	PrintArray( anArr, ARRARY_SIZE );

	system("pause");
	return 0;
}

void BubbleSort(int aInt[], int nSize)
{
	for(int i = 0; i < nSize; ++i)
	{
		for(int j = 0; j < nSize - i - 1; ++j)
		{
			if ( aInt[j] > aInt[j + 1] )
			{
				int nInter = aInt[j];
				aInt[j] = aInt[j + 1];
				aInt[j + 1] = nInter;
				continue;
			}
			break;
		}
	}
}

void BubbleSortFlag(int aInt[], int nSize)
{
	bool bNotOver = true;
	while ( bNotOver )
	{
		bNotOver = !bNotOver;
		--nSize;
		for(int i = 0; i < nSize; ++i)
		{
			if ( aInt[i] > aInt[i + 1] )
			{
				int nInter = aInt[i];
				aInt[i] = aInt[i + 1];
				aInt[i + 1] = nInter;

				bNotOver = true;
				continue;
			}
			break;
		}
	}
}

void InsertSort(int aInt[], int nSize)
{
	for(int i = 1; i < nSize; ++i)
	{
		int nIndex = i;
		while ( aInt[nIndex] < aInt[nIndex - 1] )
		{
			int nInter = aInt[nIndex];
			aInt[nIndex] = aInt[nIndex - 1];
			aInt[nIndex - 1] = nInter;
			--nIndex;
		}
	}
}

void ShellSort(int aInt[], int nSize, int nDis)
{
	while ( nDis > 0 )
	{
		for(int i = 0; i < nSize - nDis; ++i)
		{
			if ( aInt[i] > aInt[i + nDis] )
			{
				int nInter = aInt[i];
				aInt[i] = aInt[i + nDis];
				aInt[i + nDis] = nInter;
			}
		}
		--nDis;
	}
}

void SelectSort(int aInt[], int nSize)
{
	for(int i = 0; i < nSize; ++i)
	{
		int nMin = i;
		for(int j = i + 1; j < nSize; ++j)
		{
			nMin = (aInt[nMin] > aInt[j] ? j : nMin);
		}
		
		if ( nMin != i )
		{
			int Inter = aInt[i];
			aInt[i] = aInt[nMin];
			aInt[nMin] = Inter;
		}
	}
}

int  QuickPartition(int aInt[], int nStart, int nEnd)
{
	int nKey = aInt[nStart];
	int i = 0;
	int j = 0;
	for (i = nStart + 1, j = i ; i <= nEnd; ++i)
    {
		if ( aInt[i] < nKey )
        {
			int nInter = aInt[i];
			aInt[i] = aInt[j];
			aInt[j++] = nInter;
        }
    }
    
	int nInter = aInt[nStart];
	aInt[nStart] = aInt[j - 1];
	aInt[j - 1] = nInter;

    return j-1;
}

void QuickSort(int aInt[], int nStart, int nEnd)
{
    if( nStart <= nEnd )
    {
         int split=QuickPartition( aInt, nStart, nEnd );
         QuickSort( aInt, nStart, split-1 );
         QuickSort( aInt, split+1, nEnd );
    }
}

int MidFind(int aInt[], int nSize, int nValue)
{
	int nBegin = 0;
	int nEnd = nSize;
	int nMid = (nBegin + nEnd)/2;

	while ( nBegin < nEnd )
	{
		if ( aInt[nMid] < nValue )
		{
			nEnd = nMid;
		}
		else if ( aInt[nMid] > nValue )
		{
			nBegin = nMid;
		}
		else
		{
			return nMid;
		}
	}

	return -1;
}

void PrintArray(int aInt[], int nSize)
{
	for(int i = 0; i < nSize; ++i)
	{
		printf("%d\t", aInt[i]);
	}
	printf("\n");
}

void GetArrValueByRand(int aInt[], int nValueMax, int nValueMin, int nSize)
{
	srand((unsigned)time(NULL));

	for(int i = 0; i < nSize; ++i)
	{
		aInt[i] = rand() % (nValueMax - nValueMin + 1) + nValueMin;
	}
}