#include <cstring>
#include <iostream>
using namespace std;
int main()
{
	char s[200],*p1,*p2;
	cin >> s;
	p1 = s + 2;
	p2 = s + 5;
	p1 = p1 - p2;
	cout << p1;
	return 0;
}