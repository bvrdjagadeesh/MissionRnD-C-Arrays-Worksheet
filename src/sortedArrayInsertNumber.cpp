/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>
#include <malloc.h>

int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	if (Arr != NULL&&len > 0)
	{
		int i, t;
		for (i = 0; i <len; i++)
		{
			if (num < Arr[i])
			{
				for (; i <= len; i++)
				{
					t = Arr[i];
					Arr[i] = num;
					num = Arr[i + 1];
				}
			}
		}
		if (num>Arr[len - 1])
		{
			Arr[len] = num;
		}
		return Arr;
	}
	else
		return NULL;
}