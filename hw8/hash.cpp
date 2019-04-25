#include <iostream>
#include <cmath>

using namespace std;

unsigned long long hasher(string p)
{
	int casts[p.size()];
	for(unsigned int i = 0; i<p.size();i++)
	{
		casts[i] = (int)p[i];
	}
	unsigned long long hp = 0;
	for(unsigned int i = 0; i< p.size() - 1; i++)
	{
		hp += casts[i];
		hp *= 128;
	}
	hp += (unsigned long long)casts[p.size() -1];
	unsigned int w4 = hp % 65521;
	unsigned int w3 = (hp/65521) % 65521;
	unsigned int w2 = ((hp/65521)/65521) % 65521;
	unsigned int w1 = (((hp/65521)/65521)/65521) % 65521;
	unsigned long long encript = (45912 * w1 + 35511 * w2 + 65169 * w3 + 4625 * w4) % 65521;
	return encript;
}
int main()
{
	unsigned long long p = hasher("password");
	cout << "password " << p << endl;
	p = hasher("graphics");
	cout << "graphics " << p << endl;
	p = hasher("piazza");
	cout << "piazza " << p << endl;
	p = hasher("abc123");
	cout << "abc123 " << p << endl;
	p = hasher("fighton");
	cout << "fighton " << p << endl;
	p = hasher("csci104");
	cout << "csci104 " << p << endl;
}