#include "pch.h"
#pragma once

//#include "../../src/headers/Player.h"
//#include "../../src/headers/Command.h"
//#include "../../src/headers/csv2vector.h"
//#include "../../src/headers/Router.h"
//#include "../../src/Router.cpp"
TEST(teszt1, izeteszt) {
	EXPECT_EQ((ize(1, 1, true)), 2);
	EXPECT_TRUE(true);
	//std::cout << "\nNEXT TEST\n\n";
}
TEST(teszt1, ize2teszt) {
	bool d = true;//ezt átirni más tesztekre
	bool** c = new bool* [big];
	for (int i = 0; i < big; i++) {
		c[i] = new bool[big];
	}
	int a = 5;//v�ltoztathat� MAX big (big=5)
	int b = 5;//v�ltoztathat� MAX big (big=5)
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
	//std::cout << "\nNEXT TEST\n\n";
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
TEST(teszt1, ize3teszt) {
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
						ize3(f, d, g, e, c, h2);
						for (int i = 0; i < big; i++) {
							for (int j = 0; j < big; j++) {
								if (((i >= d) && (i <= f)) && ((j >= e) && (j <= g))) {
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
TEST(MATHTEST, V2Fteszt)
{
	int a = 1, b = 2, c = 3, d = 4;
	float ac = float(a + c);
	float bd = float(b + d);
	V2F* aa = new V2F;
	aa->x = ac; aa->y = bd;
	V2F* bb = new V2F(V2Fadd(float(a), float(b), float(c), float(d)));
	EXPECT_TRUE(V2F_EQ(bb, aa));
	delete  bb;
	V2F* cc = new V2F(V2Fadd(3.0f, 3.0f, 3.0f, 3.0f));
	EXPECT_FALSE(V2F_EQ(cc, aa));
}
TEST(MATHTEST, V2Fteszt2)
{
	int a = 1, b = 2, c = 3, d = 4;
	float ac = float(a + c);
	float bd = float(b + d);
	V2F* aa = new V2F(ac, bd);
	V2F* a1 = new V2F(float(a), float(b));
	V2F* b1 = new V2F(float(c), float(d));
	V2F* dd = new V2F(V2Fadd2(a1, b1));
	EXPECT_TRUE(V2F_EQ(dd, aa));
	V2F* cc = new V2F(V2Fadd(0.0f, 0.0f, 0.0f, 0.0f));
	EXPECT_FALSE(V2F_EQ(cc, aa));
	EXPECT_FALSE(V2F_EQ(cc, dd));
}







//class SortTest : public testing::TestWithParam<std::vector<V2F>> {};
//
//TEST_P(SortTest, WorksForVariousInputs) {
//	auto in = GetParam();
//	auto expected = in;
//	
//
//}
//TEST(TESZT, teszt1) {};TEST(TESZT, teszt2) {};TEST(TESZT, teszt3) {};TEST(TESZT, teszt4) {};TEST(TESZT, teszt5) {};TEST(TESZT, teszt6) {};TEST(TESZT, teszt7) {};TEST(TESZT, teszt8) {};TEST(TESZT, teszt9) {};TEST(TESZT, teszt10) {};TEST(TESZT2, teszt11) {};TEST(TESZT2, teszt12) {};TEST(TESZT2, teszt13) {};TEST(TESZT2, teszt14) {};TEST(TESZT2, teszt15) {};TEST(TESZT2, teszt16) {};TEST(TESZT2, teszt17) {};TEST(TESZT2, teszt18) {};TEST(TESZT2, teszt19) {};TEST(TESZT2, teszt20) {};TEST(TESZT3, teszt21) {};TEST(TESZT3, teszt22) {};TEST(TESZT3, teszt23) {};TEST(TESZT3, teszt24) {};TEST(TESZT3, teszt25) {};TEST(TESZT3, teszt26) {};TEST(TESZT3, teszt27) {};TEST(TESZT3, teszt28) {};TEST(TESZT3, teszt29) {};TEST(TESZT3, teszt30) {};TEST(TESZT4, teszt31) {};TEST(TESZT4, teszt32) {};TEST(TESZT4, teszt33) {};TEST(TESZT4, teszt34) {};TEST(TESZT4, teszt35) {};TEST(TESZT4, teszt36) {};TEST(TESZT4, teszt37) {};TEST(TESZT4, teszt38) {};TEST(TESZT4, teszt39) {};TEST(TESZT4, teszt40) {};TEST(TESZT5, teszt41) {};TEST(TESZT5, teszt42) {};TEST(TESZT5, teszt43) {};TEST(TESZT5, teszt44) {};TEST(TESZT5, teszt45) {};TEST(TESZT5, teszt46) {};TEST(TESZT5, teszt47) {};TEST(TESZT5, teszt48) {};TEST(TESZT5, teszt49) {};TEST(TESZT5, teszt50) {};

//TEST(MOVEMENT1,ROUTER1)
//{
//	
//}
//class MockRouter : public Router
//{
//	MOCK_METHOD0(move, void(std::string cm, std::string it));
//	MOCK_METHOD1(route, void(std::string command, std::string item));
//};
//int main() 
//{
//	Player p = Player();
//
//	//Ez a sor kell a while ciklusok elé
//	Router r = Router(p);
//
//	while (true) {
//		std::string command;
//		getline(std::cin, command);
//
//		//Ez a 3 sor kell az eventfigyelő ciklusba
//		Command c = Command(command);
//		c.make();
//		r.route(c.getCommand(), c.getItem());
//
//	}
//}




