#include <bits/stdc++.h>

using namespace std;

void Words(char str[]) {
    char v[101][101];

    char *p=strtok(str," ");
    int i=0;
    while(p) {
        strcpy(v[++i], p);
        p=strtok(NULL, " ");

    }

    for(int k=1; k<i; k++)
        for(int j=k+1; j<=i; j++)
            if(strlen(v[k])<strlen(v[j]))
                swap(v[j],v[k]);
                
    for(int k=1;k<i;k++)
        for(int j=k+1;j<=i;j++)
            if(strlen(v[k])==strlen(v[j])&&strcmp(v[k], v[j])>0)
                swap(v[j],v[k]);

    for(int r=1; r<=i; r++)
        printf("%s\n",v[r]);

}

int main()
{
    char str[101];
    FILE * openFile;

    openFile = fopen("in.txt", "r");

    if(fgets (str, 101, openFile) != NULL)
    {
        Words(str);
    }

    fclose(openFile);
    return 0;
}