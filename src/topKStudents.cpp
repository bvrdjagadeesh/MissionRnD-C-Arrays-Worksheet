/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>

struct student {
	char *name;
	int score;
};

void swap(struct student *students, int ind1, int ind2) {
	struct student temp = students[ind1];
	students[ind1] = students[ind2];
	students[ind2] = temp;
}

void sort(struct student *students, int len){
	int counter1, counter2;
	for (counter1 = 0; counter1 < len - 1; counter1++){
		for (counter2 = counter1; counter2 < len; counter2++){
			if (students[counter1].score < students[counter2].score){
				swap(students, counter1, counter2);
			}
		}
	}
}

struct student ** topKStudents(struct student *students, int len, int K) {
	if (K > 0 )
	{
		if (K == 1)
		{
			int counter = 0, max = 0, pos;
			for (counter = 0; counter < len; counter++){
				if (students[counter].score>max){
					max = students[counter].score;
					pos = counter;
				}
			}
			struct student **topKstudents = (struct student**)calloc(K, sizeof(struct student));
			topKstudents[0] = &students[pos];
			return topKstudents;
		}
		else
		{
			int i;
			struct student **topKstudents = (struct student**)calloc(K, sizeof(struct student));
			sort(students, len);
			for (i = 0; i < K; i++)
				topKstudents[i] = &students[i];

			return topKstudents;
		}
	}
	else
		return NULL;
}