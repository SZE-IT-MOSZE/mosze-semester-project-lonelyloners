#include "..\pch.hpp"
#include "..\..\pch\googletest\googletest\include\gtest\gtest.h"
#include "..\..\pch\googletest\googlemock\include\gmock\gmock.h"

TEST(teszt1, izeteszt)
{
	EXPECT_EQ((ize(1, 1, true)), 2);
	EXPECT_TRUE(true);
}
TEST(teszt1, ize2teszt)
{
	bool d = true;
	bool** c = new bool* [big];
	for (int i = 0; i < big; i++)
	{
		c[i] = new bool[big];
	}
	int a = 5;
	int b = 5;
	ize2(a, b, c, d);
	for (int i = 0; i < big; i++)
	{
		for (int j = 0; j < big; j++)
		{
			if ((i <= a) && (j <= b))
			{
				EXPECT_EQ((c[i][j]), d);
			}
			else
			{
				EXPECT_EQ((c[i][j]), !d);
			}
		}

	}
	for (int i = 0; i < big; i++)
	{
		delete[] c[i];
	}
	delete[] c;
}

void test(int f,int  g,bool** c,bool h2)
{
	ize2(f, g, c, h2);
	for (int i = 0; i < big; i++)
	{
		for (int j = 0; j < big; j++)
		{
			if ((i < f) && (j < g))
			{
				EXPECT_EQ((c[i][j]), !h2);
				EXPECT_TRUE((c[i][j]) == h2);
				EXPECT_FALSE((c[i][j]) == !h2);
			}
			else
			{
				EXPECT_EQ((c[i][j]), h2);
				EXPECT_FALSE((c[i][j]) == h2);
				EXPECT_TRUE((c[i][j]) == !h2);
			}
		}

	}

}

TEST(teszt1, ize3teszt)
{
	for (int d = 0; d < big; d++)
	{
		for (int e = 0; e < big; e++)
		{
			for (int f = d; f < big; f++)
			{
				for (int g = e; g < big; g++)
				{
					for (int h1 = 0; h1 <= 1; h1++)
					{
						bool h2 = h1;
						bool** c = new bool* [big];
						for (int i = 0; i < big; i++)
						{
							*c = new bool[big];
						}
						ize3(f, d, g, e, c, h2);
						for (int i = 0; i < big; i++)
						{
							for (int j = 0; j < big; j++)
							{
								if (((i >= d) && (i <= f)) && ((j >= e) && (j <= g)))
								{
									EXPECT_EQ((c[i][j]), h2);
									EXPECT_TRUE((c[i][j]) == h2);
									EXPECT_FALSE((c[i][j]) == !h2);
								}
								else 
								{
									EXPECT_NE((c[i][j]), h2);
									EXPECT_FALSE((c[i][j]) == h2);
									EXPECT_TRUE((c[i][j]) == !h2);
								}
							}

						}
						for (int ii = 0; ii < big; ii++)
						{
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
	std::cout<<"Press any key to continue";
	std::cin.get();
}
 class MockEntity : public Entity
{
	public:
	MockEntity(V2F p_pos, SDL_Texture* p_tex): Entity(p_pos,p_tex){};
	MOCK_METHOD(void,setSize,(int w, int h));
	MOCK_METHOD(void,setPosi,(int x,int y));
	MOCK_METHOD(void,setTarget,(int direct, int distance));
	MOCK_METHOD(SDL_Texture*,getTex,());
	MOCK_METHOD(SDL_Rect,getCurrentFrame,());
	MOCK_METHOD(void, setDirZero,());
	MOCK_METHOD(int, getDirection,());
	MOCK_METHOD(int, getTargetX,()); 
	MOCK_METHOD(int, getTargetY,());  
};
class MockRouter : public Router 
{
		public:
        MOCK_METHOD(void,move,(std::string cm, std::string it, Entity& ent));
        MOCK_METHOD(void,help,());
        MOCK_METHOD(void,next_page,(RenderWindow& rw));
        MOCK_METHOD(void,route,(std::string command, std::string item, Entity& ent, RenderWindow& rw));
};
class MockCommand : public Command 
{
	public:

		MockCommand(std::string cm):Command(cm){};
        MOCK_METHOD(void,make,());
        MOCK_METHOD(bool,validate,(std::string command));
        MOCK_METHOD(std::string,getCommand,());
        MOCK_METHOD(std::string,getItem,());

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
    std::cin.get();
	std::cin.get();
  return RUN_ALL_TESTS();
}