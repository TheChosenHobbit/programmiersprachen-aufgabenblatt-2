#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"

TEST_CASE ("TestDefaultConstructor","[Constructor]"){
    Vec2 v;
	REQUIRE(v.x == 0.0f);
	REQUIRE(v.y == 0.0f);
}

TEST_CASE ("TestUserConstructor","[Constructor]"){
    Vec2 v{3.2, 4.4};
	REQUIRE(v.x == 3.2f);
	REQUIRE(v.y == 4.4f);
}

TEST_CASE ("Test +=","[Operator]"){
    Vec2 v1{3.2, 4.4};
    Vec2 v2(1.1, 1.1);
    Vec2 v3(4.2, 2.4);
    v1+=v2;
	REQUIRE(v1.x == Approx(4.3f));
	REQUIRE(v1.y == Approx(5.5f));
	v2+=v3;
	REQUIRE(v2.x == Approx(5.3f));
	REQUIRE(v2.y == Approx(3.5f));

}

TEST_CASE ("Test -=","[Operator]"){
    Vec2 v1{3.2, 4.4};
    Vec2 v2(1.1, 1.1);
    Vec2 v3(2.4, 4.2);
    v1-=v2;
	REQUIRE(v1.x == Approx(2.1f));
	REQUIRE(v1.y == Approx(3.3f));
	v2-=v3;
	REQUIRE(v2.x == Approx(-1.3f));
	REQUIRE(v2.y == Approx(-3.1f));
}

TEST_CASE ("Test *=","[Operator]"){
    Vec2 v1{3.2, 4.4};
    Vec2 v2(1.1, 1.1);
    Vec2 v3(2.2, 3.2);
    v1*=2.0f;
	REQUIRE(v1.x == Approx(6.4f));
	REQUIRE(v1.y == Approx(8.8f));
	v2*=0.0f;
	REQUIRE(v2.x == Approx(0.0f));
	REQUIRE(v2.y == Approx(0.0f));
	v3*=-2.0f;
	REQUIRE(v3.x == Approx(-4.4f));
	REQUIRE(v3.y == Approx(-6.4f));
}

TEST_CASE ("Test /","[Operator]"){
    Vec2 v1{3.2, 4.4};
    Vec2 v2(1.1, 1.1);
    Vec2 v3(0.0, 2.6);
    v1/2.0f;
	REQUIRE(v1.x == Approx(1.6f));
	REQUIRE(v1.y == Approx(2.2f));
	v2/-1.0f;
	REQUIRE(v2.x == Approx(-1.1f));
	REQUIRE(v2.y == Approx(-1.1f));
	//v3/0.0f;
	//REQUIRE(v3.x == Approx());
	//REQUIRE(v3.y == Approx(0.0f));

}


int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
