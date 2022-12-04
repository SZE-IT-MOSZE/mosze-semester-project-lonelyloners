#include "pch.hpp"
int ize(int a, int b, bool d) {
	int c;
	if (d)
	{
		c = a + b;
	}
	else c = b - a;
	return c;
}
bool ize2(int a, int b, bool** c, bool d)
{
	*c = new bool[big];
	for (int i = 0; i < big; i++)
	{
		c[i] = new bool[big];
	}
	for (int i = 0; i < big; i++)
	{
		for (int j = 0; j < big; j++)
		{
			c[i][j] = !d;
		}
	}
	for (int i = 0; i <= a; i++)
	{
		for (int j = 0; j <= b; j++)
		{
			c[i][j] = d;
		}
	}
	return c;
	delete c;
}

bool ize3(int a, int aa, int b, int bb, bool** c, bool d)
{
	*c = new bool[big];
	for (int i = 0; i < big; i++)
	{
		c[i] = new bool[big];
	}
	for (int i = 0; i < big; i++)
	{
		for (int j = 0; j < big; j++)
		{
			c[i][j] = !d;
		}
	}
	for (int i = aa; i <= a; i++)
	{
		for (int j = bb; j <= b; j++)
		{
			c[i][j] = d;
		}
	}
	return c;
	delete c;
}
bool V2F_EQ(V2F* a, V2F* b)
{
	if (a->x != b->x) { return 0; }
	else if (a->y != b->y) { return 0; }
	else return 1;
}
V2F V2Fadd(float a, float b, float c, float d)
{
	V2F* aa = new V2F(a, b);
	V2F* bb = new V2F(c, d);
	V2F* cc = new V2F();
	cc->x = aa->x + bb->x;
	cc->y = aa->y + bb->y;
	return *cc;
	delete aa;
	delete bb;
	delete cc;
}
V2F V2Fadd2(V2F* a, V2F* b)
{
	V2F* cc = new V2F;
	cc->x = a->x + b->x;
	cc->y = a->y + b->y;
	return *cc;
}

