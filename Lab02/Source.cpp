#include "NumberList.h"
#include "Student.h"
#include "globalFunctions.h"
#include <stdio.h>


using namespace std;

int main()
{
    /*NumberList p;
    p.Init();
    p.Add(1), p.Add(4), p.Add(2), p.Add(7);
    p.Print();
    p.Sort();
    p.Print();*/

    Student s1,s2;
    s1.SetName("Andrei", 6);
    s2.SetName("Matei", 5);

    s1.SetMath(9);
    s2.SetMath(5);

    s1.SetEng(7);
    s2.SetEng(7);

    s1.SetHys(6);
    s2.SetHys(8);

    printf("%0.1f \n", s1.Average());
    printf("%0.1f \n", s2.Average());

    printf("%s \n", s1.GetName());
    printf("%s \n", s2.GetName());

    globalFunctions p1;

    printf("%d \n",p1.Comp_Name(s1.GetName(), s2.GetName()));
    printf("%d \n", p1.Comp_Avg(s1.Average(), s2.Average()));
    printf("%d \n", p1.Comp_Math(s1.GetMath(),s2.GetMath()));
    printf("%d \n", p1.Comp_Eng(s1.GetEng(), s2.GetEng()));
    printf("%d \n", p1.Comp_His(s1.GetHys(), s2.GetHys()));

    return 0;
}
