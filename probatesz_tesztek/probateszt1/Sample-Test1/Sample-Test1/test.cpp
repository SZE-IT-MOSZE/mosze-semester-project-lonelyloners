#include "pch.h"

TEST(Bpos, izeteszt) {
  EXPECT_EQ((ize(1,5,true)), 6);
  EXPECT_TRUE(true);
  std::cout << "\nNEXT TEST\n\n";
}
TEST(Bpos2, ize2teszt) {
	bool d = true
		;//ezt átirni más tesztekre
	bool **c = new bool*[big];
	for (int i = 0; i < big; i++) {
		c[i] = new bool[big];
	}
	int a = 5;//változtatható MAX big (big=5)
	int b = 5;//változtatható MAX big (big=5)
	ize2(a, b, c, d);
	for (int i = 0; i < big; i++) {
		for (int j = 0; j < big; j++) {
			if ((i < a) && (j < b)) {
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
