#include "pch.h"

TEST(Bpos, izeteszt) {
  EXPECT_EQ((ize(1,5,true)), 6);
  EXPECT_TRUE(true);
  std::cout << "\nNEXT TEST\n\n";
}
TEST(Bpos2, ize2teszt) {
	bool d = false;
	bool **c = new bool*[big];
	for (int i = 0; i < big; i++) {
		c[i] = new bool[big];
	}
	int g = 3;
	ize2(g, g, c, d);
	for (int i = 0; i < big; i++) {
		for (int j = 0; j < big; j++) {
			if ((i <= g) && (j <= g)) {
				EXPECT_EQ((c[i][j]), d);
				EXPECT_TRUE(true);
			}
			else {
				EXPECT_EQ((c[i][j]), !d);
				EXPECT_TRUE(true);
			}
		}

	}
	std::cout << "\nNEXT TEST\n\n";
}
