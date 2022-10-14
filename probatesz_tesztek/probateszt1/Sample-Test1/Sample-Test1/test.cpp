#include "pch.h"

TEST(Bpos, izeteszt) {
  EXPECT_EQ((ize(1,1,true)), 2);
  EXPECT_TRUE(true);
  std::cout << "\nNEXT TEST\n\n";
}
TEST(Bpos2, ize2teszt) {
	bool d = true;//ezt átirni más tesztekre
	bool** c = new bool* [big];
	for (int i = 0; i < big; i++) {
		c[i] = new bool[big];
	}
	int a = 1;//változtatható MAX big (big=5)
	int b = 1;//változtatható MAX big (big=5)
	ize2(a, b, c, d);
	for (int i = 0; i < big; i++) {
		for (int j = 0; j < big; j++) {
			if ((i <= a) && (j <= b)) {
				EXPECT_EQ((c[i][j]), d);
			}
			else {
				EXPECT_EQ((c[i][j]), !d);
			}
		}

	}//std::cout << "A teszt a(z) \t" << f + 1 << '\t' << g + 1 << '\t' << (h2 ? "true" : "false") << '\t' << "parameterekre elvegzodott\n";
	for (int i = 0; i < big; i++) {
		delete[] c[i];
	}
	delete[] c;
	std::cout << "\nNEXT TEST\n\n";
}
/*
void test(int f,int  g,bool** c,bool h2) {
	ize2(f, g, c, h2);
	for (int i = 0; i < big; i++) {
		for (int j = 0; j < big; j++) {
			if ((i < f) && (j < g)) {
				EXPECT_EQ((c[i][j]), !h2);
				//EXPECT_TRUE((c[i][j]) == h2);
				//EXPECT_FALSE((c[i][j]) == !h2);
			}
			else {
				EXPECT_EQ((c[i][j]), h2);
				//EXPECT_FALSE((c[i][j]) == h2);
				//EXPECT_TRUE((c[i][j]) == !h2);
			}
		}

	}
	
}
*/
TEST(Bpos2, ize3teszt) {
	for (int d = 0; d < big; d++) {
		for (int e = 0; e < big; e++) {
			for (int f = d; f < big; f++) {
				for (int g = e; g < big; g++) {
					for (int h1 = 0; h1 <= 1; h1++) {
						bool h2 = h1;
						bool** c = new bool* [big];
						for (int i = 0; i < big; i++) {
							*c = new bool[big];
						}

						//*c = new bool[big];
						ize3(f,d, g,e, c, h2);
						for (int i = 0; i < big; i++) {
							for (int j = 0; j < big; j++) {
								if (((i>=d) && (i <= f)) && ((j >= e) && (j <= g))) {
									EXPECT_EQ((c[i][j]), h2);
									//EXPECT_TRUE((c[i][j]) == h2);
									//EXPECT_FALSE((c[i][j]) == !h2);
								}
								else {
									EXPECT_NE((c[i][j]), h2);
									//EXPECT_FALSE((c[i][j]) == h2);
									//EXPECT_TRUE((c[i][j]) == !h2);
								}
							}

						}
					/*	if ((e <= 2) && (d <= 2) && (f >= big - 3) && (g >= big - 3) && (h2 == true)) {
							for (int i = 0; i < big; i++) {
								for (int j = 0; j < big; j++) {
									std::cout << c[i][j] << '\t';
								}
								std::cout << std::endl;
							}
						}*/

						//std::cout << "A teszt a(z) \t" << f + 1 << '\t' << g + 1 << '\t' << (h2 ? "true" : "false") << '\t' << "parameterekre elvegzodott\n";
						for (int ii = 0; ii < big; ii++) {
							delete[] c[ii];
						}
						delete[] c;
					}
				}
			}
		}
	}
}



