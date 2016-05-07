#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include "mat2.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

TEST_CASE ("TestDefaultConstructorVektor","[Constructor]"){
    Vec2 v;
	REQUIRE(v.x == 0.0f);
	REQUIRE(v.y == 0.0f);
}

TEST_CASE ("TestUserConstructorVektor","[Constructor]"){
    Vec2 v{3.2, 4.4};
	REQUIRE(v.x == 3.2f);
	REQUIRE(v.y == 4.4f);
}

TEST_CASE ("Test Vektor +=","[Vektor Operator]"){
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

TEST_CASE ("Test Vektor -=","[Vektor Operator]"){
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

TEST_CASE ("Test Vektor *=","[Vektor Operator]"){
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

TEST_CASE ("Test Vektor /=","[Vektor Operator]"){
    Vec2 v1{3.2, 4.4};
    Vec2 v2(1.1, 1.1);
    Vec2 v3(0.0, 2.6);
    v1/2.0f;
	REQUIRE(v1.x == Approx(1.6f));
	REQUIRE(v1.y == Approx(2.2f));
	v2/-1.0f;
	REQUIRE(v2.x == Approx(-1.1f));
	REQUIRE(v2.y == Approx(-1.1f));
}


TEST_CASE ("Test Vektor +","[Vektor Operator]"){
    Vec2 v1{3.2, 4.4};
    Vec2 v2(1.1, 1.1);
    Vec2 v3 = v1+v2;
	REQUIRE(v3.x == Approx(4.3f));
	REQUIRE(v3.y == Approx(5.5f));
    Vec2 v4{0.0, -1.2};
    Vec2 v5(-2.2, 3.0);
    Vec2 v6 = v4+v5;
	REQUIRE(v6.x == Approx(-2.2f));
	REQUIRE(v6.y == Approx(1.8f));
}

TEST_CASE ("Test Vektor -","[Vektor Operator]"){
    Vec2 v1{3.2, 4.4};
    Vec2 v2(1.1, 1.1);
    Vec2 v3 = v1-v2;
	REQUIRE(v3.x == Approx(2.1f));
	REQUIRE(v3.y == Approx(3.3f));
    Vec2 v4{0.0, -1.2};
    Vec2 v5(-2.2, 3.0);
    Vec2 v6 = v4-v5;
	REQUIRE(v6.x == Approx(2.2f));
	REQUIRE(v6.y == Approx(-4.2f));
}

TEST_CASE ("Test Vektor * vector float","[Vektor Operator]"){
    Vec2 v1{3.2, 4.0};
    float s = 2;
    Vec2 v3 = v1*s;
	REQUIRE(v3.x == Approx(6.4f));
	REQUIRE(v3.y == Approx(8.0));
    Vec2 v4{0.0, 3.0};
    float t = -1.0;
    Vec2 v6 = v4*t;
	REQUIRE(v6.x == Approx(0.0f));
	REQUIRE(v6.y == Approx(-3.0f));
}

TEST_CASE ("Test Vektor  /","[Vektor Operator]"){
    Vec2 v1{3.2, 4.4};
    float s = 2;
    Vec2 v3 = v1/s;
	REQUIRE(v3.x == Approx(1.6f));
	REQUIRE(v3.y == Approx(2.2f));
    Vec2 v4{0.0, -3.0};
    float t = -1.5;
    Vec2 v6 = v4/t;
	REQUIRE(v6.x == Approx(0.0f));
	REQUIRE(v6.y == Approx(2.0f));
}

TEST_CASE ("Test Vektor * float vector","[Vektor Operator]"){
    Vec2 v1{3.2, 4.0};
    float s = 2;
    Vec2 v3 = s*v1;
	REQUIRE(v3.x == Approx(6.4f));
	REQUIRE(v3.y == Approx(8.0));
    Vec2 v4{0.0, 3.0};
    float t = -1.0;
    Vec2 v6 = t*v4;
	REQUIRE(v6.x == Approx(0.0f));
	REQUIRE(v6.y == Approx(-3.0f));
}

TEST_CASE ("TestDefaultConstructorMatrix","[Constructor]"){
    Mat2 m;
	REQUIRE(m.w == Approx(1.0f));
	REQUIRE(m.x == Approx(1.0f));
	REQUIRE(m.y == Approx(1.0f));
	REQUIRE(m.z == Approx(1.0f));
}

TEST_CASE ("TestUserConstructorMatrix","[Constructor]"){
    Mat2 m{3.2, 4.4, -2.0, 0.0};
	REQUIRE(m.w == Approx(3.2f));
	REQUIRE(m.x == Approx(4.4f));
	REQUIRE(m.y == Approx(-2.0f));
	REQUIRE(m.z == Approx(0.0f));
}

TEST_CASE ("Test Matrix *=","[Matrix Operator]"){
    Mat2 m1{2.2, 3.3, 4.4, 5.5};
    Mat2 m2{2.0, 3.0, 4.0, 5.0};
    m1 *= m2;
	REQUIRE(m1.w == Approx(4.4f));
	REQUIRE(m1.x == Approx(9.9f));
	REQUIRE(m1.y == Approx(17.6f));
	REQUIRE(m1.z == Approx(27.5f));
	Mat2 m3{-2.2, 3.3, -4.4, 5.5};
    Mat2 m4{2.0, -3.0, -4.0, 0.0};
    m3 *= m4;
	REQUIRE(m3.w == Approx(-4.4f));
	REQUIRE(m3.x == Approx(-9.9f));
	REQUIRE(m3.y == Approx(17.6f));
	REQUIRE(m3.z == Approx(0.0f));
}

TEST_CASE ("Test Matrix *","[Matrix Operator]"){
    Mat2 m1{2.2, 3.3, 4.4, 5.5};
    Mat2 m2{2.0, 3.0, 4.0, 5.0};
    Mat2 m3 = m1*m2;
	REQUIRE(m3.w == Approx(4.4f));
	REQUIRE(m3.x == Approx(9.9f));
	REQUIRE(m3.y == Approx(17.6f));
	REQUIRE(m3.z == Approx(27.5f));
	Mat2 m5{-2.2, 3.3, -4.4, 5.5};
    Mat2 m6{2.0, -3.0, -4.0, 0.0};
    Mat2 m4 = m5*m6;
	REQUIRE(m4.w == Approx(-4.4f));
	REQUIRE(m4.x == Approx(-9.9f));
	REQUIRE(m4.y == Approx(17.6f));
	REQUIRE(m4.z == Approx(0.0f));
}

TEST_CASE("Determinante","[Determinante]"){
	Mat2 m{2.0, 3.0, 1.0, 2.0};
	REQUIRE(m.det() == Approx(1.0f));
	Mat2 m1{4.2, 3.0, 1.0, 0.0};
	REQUIRE(m1.det() == Approx(-3.0f));
	Mat2 m2{-2.0, -3.0, 1.0, 2.0};
	REQUIRE(m2.det() == Approx(-1.0f));
}

TEST_CASE("Test Matrix * Vektor","[Matrix Vektor Operation]"){
	Mat2 m{1.0, 2.0, 7.0, 4.0};
	Vec2 v{1.0, 2.0};
	Vec2 vres1 = m*v;
	REQUIRE(vres1.x == Approx(5.0f));
	REQUIRE(vres1.y == Approx(15.0f));
	Mat2 m1{-2.0, 3.5, 0.0, -2.0};
	Vec2 v1{-3.0, 2.0};
	Vec2 vres2 = m1*v1;
	REQUIRE(vres2.x == Approx(13.0f));
	REQUIRE(vres2.y == Approx(-4.0f));
}

TEST_CASE("Test Vektor * Matrix","[Vektor Matrix Operation]"){
	Mat2 m{1.0, 2.0, 7.0, 4.0};
	Vec2 v{1.0, 2.0};
	Vec2 vres1 = v*m;
	REQUIRE(vres1.x == Approx(5.0f));
	REQUIRE(vres1.y == Approx(15.0f));
	Mat2 m1{-2.0, 3.5, 0.0, -2.0};
	Vec2 v1{-3.0, 2.0};
	Vec2 vres2 = v1*m1;
	REQUIRE(vres2.x == Approx(13.0f));
	REQUIRE(vres2.y == Approx(-4.0f));
}

TEST_CASE("Inverse Matrix","[Matrix Operation]"){
	Mat2 m{2.0, 3.0, 4.0, 5.0};
	Mat2 m1 = inverse(m);
	REQUIRE(m1.w == Approx(5.0f));
	REQUIRE(m1.x == Approx(-3.0f));
	REQUIRE(m1.y == Approx(-4.0f));
	REQUIRE(m1.z == Approx(2.0f));
}

TEST_CASE("Transponiert Matrix","[Matrix Operation]"){
	Mat2 m{2.0, 3.0, 4.0, 5.0};
	Mat2 m1 = transpose(m);
	REQUIRE(m1.w == Approx(2.0f));
	REQUIRE(m1.x == Approx(4.0f));
	REQUIRE(m1.y == Approx(3.0f));
	REQUIRE(m1.z == Approx(5.0f));
}

TEST_CASE("Rotation Matrix","[Matrix Operation]"){
	Mat2 m{2.0, 3.0, 4.0, 5.0};
	Mat2 m1 = make_rotation_mat2(0);
	REQUIRE(m1.w == Approx(1.0f));
	REQUIRE(m1.x == Approx(0.0f));
	REQUIRE(m1.y == Approx(0.0f));
	REQUIRE(m1.z == Approx(1.0f));


	//Noch weitere
}

TEST_CASE ("TestDefaultConstructorCircle","[Constructor]"){
	Circle c;
	REQUIRE(c.getPoint2D().x == Approx(1.0f));
	REQUIRE(c.getPoint2D().y == Approx(1.0f));
	REQUIRE(c.getRadius() == Approx(1.0f));
	REQUIRE(c.getColor().r == Approx(0.0f));
	REQUIRE(c.getColor().g == Approx(0.0f));
	REQUIRE(c.getColor().b == Approx(0.0f));
}

TEST_CASE ("TestUserConstructorCircle","[Constructor]"){
	Circle c{{2.0,3.0}, 5, {0,1,0}};
	REQUIRE(c.getPoint2D().x == Approx(2.0f));
	REQUIRE(c.getPoint2D().y == Approx(3.0f));
	REQUIRE(c.getRadius() == Approx(5.0f));
	REQUIRE(c.getColor().r == Approx(0.0f));
	REQUIRE(c.getColor().g == Approx(1.0f));
	REQUIRE(c.getColor().b == Approx(0.0f));
}

TEST_CASE ("TestDefaultConstructorRectangle","[Constructor]"){
	Rectangle r;
	REQUIRE(r.getLeftPoint2D().x == Approx(0.0f));
	REQUIRE(r.getLeftPoint2D().y == Approx(1.0f));
	REQUIRE(r.getRightPoint2D().x == Approx(1.0f));
	REQUIRE(r.getRightPoint2D().y == Approx(0.0f));
	REQUIRE(r.getColor().r == Approx(0.0f));
	REQUIRE(r.getColor().g == Approx(0.0f));
	REQUIRE(r.getColor().b == Approx(0.0f));
}

TEST_CASE ("TestUserConstructorRectangle","[Constructor]"){
	Rectangle r{{2,2}, {5,1}, {1,0,0}};
	REQUIRE(r.getLeftPoint2D().x == Approx(2.0f));
	REQUIRE(r.getLeftPoint2D().y == Approx(2.0f));
	REQUIRE(r.getRightPoint2D().x == Approx(5.0f));
	REQUIRE(r.getRightPoint2D().y == Approx(1.0f));
	REQUIRE(r.getColor().r == Approx(1.0f));
	REQUIRE(r.getColor().g == Approx(0.0f));
	REQUIRE(r.getColor().b == Approx(0.0f));
}

TEST_CASE("Circumference Circle","[Circle Operation]")
{
	Circle c{{2.0,3.0}, 5, {0,1,0}};
	REQUIRE(c.circumference() == Approx(31.415926536f));
}

TEST_CASE("Circumference Rectangle","[Rectangle Operation]")
{
	Rectangle r{{2,2}, {5,1}, {1,0,0}};
	REQUIRE(r.circumference() == Approx(8.0f));
	Rectangle r1{{5,1}, {1,5}, {1,0,0}};
	REQUIRE(r1.circumference() == Approx(16.0f));
	Rectangle r2{{2,0}, {4,-2}, {1,0,0}};
	REQUIRE(r2.circumference() == Approx(8.0f));
}

TEST_CASE("Rectangle check Point is_inside","[Rectangle Operation]")
{
	Rectangle r{{2,2}, {5,1}, {1,0,0}};
	Point2D point{4,1.5};
	REQUIRE(r.is_inside(point) == true);
	Rectangle r1{{5,1}, {1,5}, {1,0,0}};
	REQUIRE(r1.is_inside(point) == false);
	Rectangle r2{{1,2}, {2,1}, {1,0,0}};
	REQUIRE(r2.is_inside(point) == false);
}

TEST_CASE("Circle check Point is_inside","[Circle Operation]")
{
	Circle c{{2.0,3.0}, 5, {0,1,0}};
	Point2D point{4,1.5};
	REQUIRE(c.is_inside(point) == true);
	Circle c1{{1.0,1.0}, 0.5, {0,1,0}};
	Point2D point1{40,40};
	REQUIRE(c1.is_inside(point1) == false);
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}