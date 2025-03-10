#include "globalFunctions.h"
#include <stdio.h>
#include <string.h>

int globalFunctions::Comp_Name(const char* s1, const char* s2)
{
	if (strcmp(s1, s2) > 0)
		return 1;
	else if (strcmp(s1, s2) == 0)
		return 0;
	else
		return - 1;
}

int globalFunctions::Comp_Avg(float s1, float s2)
{
	if (s1>s2)
		return 1;
	else if (s1== s2)
		return 0;
	else
		return -1;
}

int globalFunctions::Comp_Math(float s1, float s2)
{
	if (s1 > s2)
		return 1;
	else if (s1 == s2)
		return 0;
	else
		return -1;
}

int globalFunctions::Comp_Eng(float s1, float s2)
{
	if (s1 > s2)
		return 1;
	else if (s1 == s2)
		return 0;
	else
		return -1;
}

int globalFunctions::Comp_His(float s1, float s2)
{
	if (s1 > s2)
		return 1;
	else if (s1 == s2)
		return 0;
	else
		return -1;
}
