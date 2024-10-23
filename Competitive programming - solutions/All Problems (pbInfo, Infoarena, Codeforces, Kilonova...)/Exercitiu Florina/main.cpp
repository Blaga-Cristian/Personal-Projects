#include <iostream>
#include <cstring>
using namespace std;

void FNume(char s[], char id[])
{
    id[0] = 0;

    char* p = strtok(s, " ");
    p = strtok(NULL, " ");

    strcat(id, p);
    strcat(id, "2022");
}

char s[51], id[51];

int main()
{
    cin.get(s, 51);
    cin.get();

    FNume(s, id);

    cout << id << '\n';
    return 0;
}
