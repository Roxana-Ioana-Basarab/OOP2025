#include <stdio.h>
#include <cstring>

using namespace std;

float chartofloat(char str[])
{
    float rezultat = 0.0f;
    float fractie = 1.0f;
    bool esteNegativ = false;
    bool esteFractie = false;
    int i = 0;

    if (str[i] == '-')
    {
        esteNegativ = true;
        i++;
    }

    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] == '.')
        {
            if (esteFractie)
            {
                return 0.0f;
            }
            esteFractie = true;
        }
        else if (str[i] >= '0' && str[i] <= '9')
        {
            if (esteFractie)
            {
                fractie /= 10.0f;
                rezultat += (str[i] - '0') * fractie;
            }
            else
            {
                rezultat = rezultat * 10.0f + (str[i] - '0');
            }
        }
    }
    if (esteNegativ)
    {
        rezultat = -rezultat;
    }

    return rezultat;
}

int main()
{
    char str[101];
    float sum=0.0f;
    FILE * openFile;

    openFile = fopen("in.txt", "r");

    while(fgets (str, 101, openFile) != NULL)
    {
        sum += chartofloat(str);
        strcpy(str,"");
    }

    fclose(openFile);
    printf("Sum is: %0.0f", sum);
    return 0;
}