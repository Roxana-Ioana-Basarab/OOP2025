#include "Math.h"
#include "Canvas.h"
#include <stdio.h>



using namespace std;
int main() {
	
	/*Math m;
	printf("%d \n", m.Add(1, 2));
	printf("%d \n", m.Add(1, 2, 3));
	printf("%d \n", m.Add(2.5 , 3.5));
	printf("%d \n\n", m.Add(2.5, 3.5, 6.4));

	printf("%d \n", m.Mul(1, 2));
	printf("%d \n", m.Mul(1, 2, 3));
	printf("%d \n", m.Mul(2.5, 3.5));
	printf("%d \n\n", m.Mul(2.5, 3.5, 6.4));

	printf("%s \n", m.Add("Andrei", "Mara"));
	*/

	Canvas draw(40, 20);

	draw.Clear();

	draw.SetPoint(6, 0, 'X');

	draw.DrawRect(5, 5, 15, 15, '#');
	draw.FillRect(6, 6, 14, 14, '+');

	draw.DrawLine(0, 0, 39, 19, '-');

	draw.DrawCircle(20, 10, 5, 'O');
	draw.FillCircle(20, 10, 5, '*');


	draw.SetPoint(20, 10, 'X');

	draw.Print();


	return 0;
}