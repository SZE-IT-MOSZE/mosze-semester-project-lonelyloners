//
// pch.cpp
//

#include "pch.h"
int ize(int a, int b, bool d){
 int c;
 if (d) {
	 c = a + b;
 }
 else c = b - a;
 return c;
}
bool ize2(int a, int b, bool** c, bool d) {
	*c = new bool [big];
	for (int i = 0; i < big; i++) {
		c[i] = new bool [big];
	}
	for (int i = 0; i < big; i++) {
		for (int j = 0; j < big; j++) {
			c[i][j] = !d;
		}
	}
	for (int i = 0; i <=a; i++) {
		for (int j = 0; j <=b; j++) {
			c[i][j] = d;
		}
	}
	return c;
}
