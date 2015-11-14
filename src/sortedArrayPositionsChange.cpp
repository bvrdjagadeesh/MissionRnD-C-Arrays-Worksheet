/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>
void * sortedArrayPositionsChange(int *Arr, int len)
{
	if (Arr != NULL&&len > 0)
	{
		int i, s1 = 0, s2 = 0, t, c = 0;
		for (i = 0; i < len-1; i++)
		{
			if (Arr[i]>Arr[i + 1] && c == 0)
			{
				s1 = i;
				c++;
			}
			else if (Arr[i] > Arr[i + 1] && c ==1)
			{
				s2 = i + 1;
			}
		}
		if (s1 != 0 || s2 != 0)
		{
			t = Arr[s2];
			Arr[s2] = Arr[s1];
			Arr[s1] = t;
		}
	}
	else
		return NULL;
}