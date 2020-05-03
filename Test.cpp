
#include "doctest.h"
#include "solver.hpp"
using namespace std;
using solver::solve, solver::RealVariable, solver::ComplexVariable;



TEST_CASE("Tests for RealVariable operator + and - ") {
    RealVariable x;

            CHECK(solve(25+x-41==10) == double(26));
            CHECK(solve(2+x-11 ==102) == double(111));
            CHECK(solve(4-x-4.8==22) == double(-22.8));
            CHECK(solve(9-x-7.5 ==54) == double(-52.5));
            CHECK(solve(12+x+3==60) == double(45));
            CHECK(solve(2-x==10.1) == double(-8.1));
            CHECK(solve(33+x-4==4.8) == double(-24.2));
            CHECK(solve(4+x==10) == double(6));
            CHECK(solve(x-4==17.5) == double(21.5));
            CHECK(solve(20+x+6==100) == double(74));
            CHECK(solve(25+x-41==10+4+x+x) == double(-30));
            CHECK(solve(2+x+x-11==10+31) == double(25));
            CHECK(solve(4-x-4.8==22+x+x+x) == double(-5.7));
            CHECK(solve(13-x-7==x+x) == double(2));
            CHECK(solve(12+x+3==62-5) == double(42));
            CHECK(solve(2-x==10.3+x) == double(-4.15));
            CHECK(solve(33.1+x-4.2==4.8) == double(-24.1));
            CHECK(solve(2.5432+x==1+x+x+11.22) == double(-9.6768));
            CHECK(solve(x-4==17.5+44) == double(65.5));
            CHECK(solve(20+x+6==100-3+x+x) == double(-71));
    }



TEST_CASE("Tests for RealVariable operator * and / ") {
    RealVariable x;

            CHECK(solve(2*x-4==10*x) == double(-0.5));
            CHECK(solve(2+x-101 ==12*x) == double(-9));
            CHECK(solve(4-x-4.8*x==22) == double(-3.1034));
            CHECK(solve(5*x-x-7.5 ==5-10) == double(0.625));
            CHECK(solve(12+x+13==60*x) == double(0.4237));
            CHECK(solve(2*x/2==10) == double(10));
            CHECK(solve(33*x/3==4*x) == double(0));
            CHECK(solve(4*x==10+x/4.5) == double(2.6470));
            CHECK(solve(-4*x==x/2) == double(0));
            CHECK(solve(200*x==100) == double(0.5));
           CHECK(solve(25*x-41==10+x/4) == double(2.0606));
    CHECK(solve(20*x+5==-10*x/2) == double(-0.2));
            CHECK(solve(4*x-4.8*x==22) == double(-27.5));
            CHECK(solve(16*x/2==x/1) == double(0));
            CHECK(solve(12*x/3==62-5) == double(14.25));
            CHECK(solve(2*x==10.3*x) == double(0));
            CHECK(solve(33.1234*x-4.2222==4.8) == double(0.2723));
            CHECK(solve(x/12==x/12+4*x+4) == double(-1));
            CHECK(solve(-4/4*x==44) == double(-44));
            CHECK(solve(20*x+6==100-3*x) == double(4.0869));
}

TEST_CASE("Tests for RealVariable operator ^ ") {
    RealVariable x;
            CHECK(solve((x^2)- 4*x == 21) == double(7));
            CHECK((solve((x^2) - 9*x == -8) == double(8)||solve((x^2) - 9*x == -8) == double(1)));
            CHECK(solve((x^2)+(x^2) +5*x +3== 0) == double(-1));
            CHECK((solve((x^2) - 2 == 2) == double(2)||solve((x^2) - 2 == 2) == double(-2)));
            CHECK(solve(-1==2*x+(x^2)) == double(-1));
            CHECK((solve((x^2) == 25) == double(5)||solve((x^2) == 25) == double(-5)));
            CHECK_THROWS(solve((x^2)+x+36== -3));
            CHECK((solve((x^2)+(x^2)+(x^2)+(x^2)==4) == double(1)||solve((x^2)+(x^2)+(x^2)+(x^2)==4) == double(-1)));
            CHECK_THROWS(solve((x^2)+3== -3));
            CHECK_THROWS(solve((x^2)+36== -3));
            CHECK_THROWS(solve((x^2)+50== -30));
}



TEST_CASE("Tests for ComplexVariable operator + and - ") {
    ComplexVariable x;

            CHECK(solve(25+x-41==10) == complex<double>(26,0));
            CHECK(solve(2+x-11 ==102) == complex<double>(111,0));
            CHECK(solve(12+x+3==60) == complex<double>(45,0));
            CHECK(solve(33+x-4==4.8) == complex<double>(-24.2,0));
            CHECK(solve(4+x==10) == complex<double>(6,0));
            CHECK(solve(x-4==17.5) == complex<double>(21.5,0));
            CHECK(solve(20+x+6==100) == complex<double>(74,0));
            CHECK(solve(25+x-41==10+4+x+x) == complex<double>(-30,0));
            CHECK(solve(2+x+x-11==10+31) == complex<double>(25,0));
            CHECK(solve(12+x+3==62-5) == complex<double>(42,0));
            CHECK(solve(33+x-4.2222==4.8) == complex<double>(-23.9778,0));
            CHECK(solve(x-4==17.5+44) == complex<double>(65.5,0));

}
TEST_CASE("Tests for ComplexVariable CHECK_THROWS ") {
    ComplexVariable y;
            CHECK_THROWS(solve((y ^ 3)==-16));
            CHECK_THROWS(solve((y ^ 3)+5==200));
            CHECK_THROWS(solve((y ^ 0)==-16));
            CHECK_THROWS(solve((y ^ 3) == 100));
            CHECK_THROWS(solve((y ^ 4) == 16));
            CHECK_THROWS(solve((y ^ 4) == -16));
            CHECK_THROWS(solve((y ^ -2) == -16));
            CHECK_THROWS(solve((y^5)+2==18));
            CHECK_THROWS(solve((y ^ 8)==-16));
            CHECK_THROWS(solve((y ^ 9)==-16));

}

TEST_CASE("Tests for ComplexVariable operator * and / and ^ ") {
    ComplexVariable x;

            CHECK(solve(2 * x - 4 == 10 * x) == complex<double>(-0.5, 0));
            CHECK(solve(2 + x - 101 == 12 * x) == complex<double>(-9, 0));
            CHECK(solve(5 * x - x - 7.5 == 5 - 10) == complex<double>(0.6250, 0));
            CHECK(solve(2 * x / 2 == 10) == complex<double>(10, 0));
            CHECK(solve(33 * x / 3 == 4 * x) == complex<double>(0, 0));
            CHECK(solve(20 * x + 5 == -10 * x / 2) == complex<double>(-0.2, 0));
            CHECK(solve(2 * x == 10.3 * x) == complex<double>(0, 0));
            CHECK(solve(-4 / 4 * x == 44) == complex<double>(-44, 0));
}
    TEST_CASE("Tests for ComplexVariable") {
    ComplexVariable y;

            CHECK(solve(y + 5i == 2 * y + 3i) == complex<double>(0, 2));
            CHECK(solve(2 * y + 3i == 3 * y + 13i) == complex<double>(0, -10));
            CHECK(solve(2 * y + 8i == 3 * y + 2i) == complex<double>(0, 6));
            CHECK((solve((y^2) == -16)==std::complex<double>(0,4)||solve((y^2) == -16)==std::complex<double>(0,-4)));
            CHECK((solve((y^2) + 2*y + 4 == 20 + 6*y/2 - y)==std::complex<double>(4,0)||solve((y^2) + 2*y + 4 == 20 + 6*y/2 - y)==std::complex<double>(-4,0))); //(-4,0)
            CHECK((solve(y+5i == 2*y+3i)==std::complex<double>(0,2)||solve(y+5i == 2*y+3i)==std::complex<double>(0,-2)));
            CHECK((solve((y^2)==-100)==std::complex<double>(0,10)||solve((y^2)==-100)==std::complex<double>(0,-10)));
            CHECK((solve((y^2)==100)==std::complex<double>(10,0)||solve((y^2)==100)==std::complex<double>(-10,0)));
            CHECK((solve((y^2)==-25)==std::complex<double>(0,5)||solve((y^2)==-25)==std::complex<double>(0,-5)));
            CHECK((solve((y^2)==-9)==std::complex<double>(0,3)||solve((y^2)==-9)==std::complex<double>(0,-3)));
            CHECK((solve((y^2)==-81)==std::complex<double>(0,9)||solve((y^2)==-81)==std::complex<double>(0,-9)));
            CHECK(solve(y-4 == 10)==std::complex<double>(14,0));
            CHECK((solve((y^2) + 3*y + 4 == 20 + 6*y/2 )==std::complex<double>(4,0)||solve((y^2) + 3*y + 4 == 20 + 6*y/2 )==std::complex<double>(-4,0))); //(-4,0)
            CHECK((solve((y^2) + 3*y == 16 + 3*y )==std::complex<double>(4,0)||solve((y^2) + 3*y == 16 + 3*y )==std::complex<double>(-4,0))); //(-4,0)
            CHECK((solve((y^2) + 6*y/2 == 16 + 9*y/3 )==std::complex<double>(4,0)||solve((y^2) + 6*y/2 == 16 + 9*y/3 )==std::complex<double>(-4,0))); //(-4,0)
            CHECK((solve((y^2)==9)==std::complex<double>(3,0)||solve((y^2)==9)==std::complex<double>(-3,0)));  //-3
            CHECK((solve((y^2)+5==30)==std::complex<double>(5,0)||solve((y^2)+5==30)==std::complex<double>(-5,0))); //-5
            CHECK((solve(2*y-2==4)==std::complex<double>(3,0)||solve(2*y-2==4)==std::complex<double>(-3,0)));   //-3
            CHECK(solve(5 * y + 5i == 12 * y+ 5i) == complex<double>(0, 0));
            CHECK((solve(2*(y^2)==-200)==std::complex<double>(0,10)||solve(2*(y^2)==-200)==std::complex<double>(0,-10)));
            CHECK((solve(2*(y^2)==-50)==std::complex<double>(0,5)||solve(2*(y^2)==-50)==std::complex<double>(0,-5)));




}