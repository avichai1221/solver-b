//
// Created by avichai on 4/24/20.
//
#include <iostream>
#include <math.h>
#include "solver.hpp"
//using namespace std;



namespace solver {

    //constractors
    RealVariable::RealVariable()
    {
        MP=0.0;
        coefficient=1.0;
        power=1;
        pow2= 0;
    }
    RealVariable::RealVariable(double realNum)
    {
        this->MP=realNum;
        coefficient=1.0;
        power=1;
        pow2= 0;
    }
    RealVariable::RealVariable(RealVariable const &other)
    {
        this->coefficient=other.coefficient;
        this->MP=other.MP;
        this->power=other.power;
        this->pow2=other.pow2;
    }

///////////////////////////////////////////////////////////////////////

    double solve(RealVariable x)
    {
        double ans=0;
        if(x.pow2== 0) //אין חזקת 2
        {
            if (x.coefficient == 0 && x.MP != 0) throw invalid_argument("wrong");
            else if ((x.coefficient == 0 && x.MP == 0)||(x.coefficient == 1 && x.MP == 0)) return 0;
            else if (x.coefficient == 1 && x.MP != 0) return -x.MP;
            else {
                ans=(-x.MP)/x.coefficient;
                ans=ans*10000; //שיחזיר 4 ספרות אחרי הנקודה
                int help=(int)(ans);
                ans=(double)help/10000;
                return ans;
            }

        }else if( (x.coefficient==0&&x.pow2!= 0))
        {
            double save=-x.MP/x.pow2;
            if(save>0){
                ans=sqrt(save);
                ans=ans*10000; //שיחזיר 4 ספרות אחרי הנקודה
                int help=(int)(ans);
                ans=(double)help/10000;
                return ans;

            }
            throw invalid_argument("There is no real solution");
        }

        else{//נוסחת שורשים
            double sq=x.coefficient*x.coefficient-4*x.pow2*x.MP;
            if (sq<0) throw invalid_argument("There is no real solution");
            ans=(-x.coefficient+sqrt(sq))/(2*x.pow2);
            ans=ans*10000; //שיחזיר 4 ספרות אחרי הנקודה
            int help=(int)(ans);
            ans=(double)help/10000;
            return ans;
        }

    }
///////////////////////////////////////////////////////////////////////

    //operators

    RealVariable operator+(const RealVariable &c1, const RealVariable &c2)
    {
        RealVariable ans;

        if(c1.power==c2.power&&c1.power==1) //חזקות שוות 1
        {
            ans.power=c2.power;
            ans.MP=c1.MP+c2.MP;
            ans.coefficient=c1.coefficient+c2.coefficient;
            if (c1.pow2!=0 &&c2.pow2!= 0)
            {
                ans.pow2=c1.pow2+c2.pow2;
            }
            else if(c1.pow2!=0){
                ans.pow2=c1.pow2;
            }
            else if(c2.pow2!=0){
                ans.pow2=c2.pow2;
            }
        } else if(c1.power==1&&c2.power==0){
            ans=operator+(c1,c2.coefficient);
            ans.MP=ans.MP+c2.MP;
            if (c1.pow2!=0 &&c2.pow2!= 0)
            {

                ans.MP=c1.MP+c2.MP;
                ans.coefficient=c1.pow2+c2.pow2;

            }
            else if(c1.pow2!=0){
                ans.pow2=c1.pow2;
            }
            else if(c2.pow2!=0){
                ans.pow2=c2.pow2;
            }
        }
        else if(c1.power==0&&c2.power==1){
            ans=operator+(c1.coefficient,c2);
            ans.MP=ans.MP+c1.MP;
            if (c1.pow2!=0 &&c2.pow2!= 0)
            {
                ans.MP=c1.MP+c2.MP;
                ans.coefficient=c1.pow2+c2.pow2;
            }
            else if(c1.pow2!=0){
                ans.pow2=c1.pow2;
            }
            else if(c2.pow2!=0){
                ans.pow2=c2.pow2;
            }
        }
        else{ //חזקות שוות 0
            ans.MP=c1.coefficient+c2.coefficient+c1.MP+c2.MP;
            ans.coefficient=0;
            ans.power=0;
            if (c1.pow2!=0 &&c2.pow2!= 0)
            {
                ans.pow2=c1.pow2+c2.pow2;
            }
            else if(c1.pow2!=0){
                ans.pow2=c1.pow2;
            }
            else if(c2.pow2!=0){
                ans.pow2=c2.pow2;
            }
        }
        return ans;
    }
    RealVariable operator-(const RealVariable &c1, const RealVariable &c2)
    {

        RealVariable ans;

        if(c1.power==c2.power&&c1.power==1) //חזקות שוות 1
        {
            ans.power=c2.power;
            ans.MP=c1.MP-c2.MP;
            ans.coefficient=c1.coefficient-c2.coefficient;
            if (c1.pow2!=0 &&c2.pow2!= 0) //בדיקה אם קיים חזקת 2
            {
                ans.MP=c1.MP-c2.MP;
                ans.pow2=c1.pow2-c2.pow2;
            }
            else if(c1.pow2!=0){
                ans.pow2=c1.pow2;
            }
            else if(c2.pow2!=0){
                ans.pow2=c2.pow2;
            }
        } else if(c1.power==1&&c2.power==0){
            ans=operator-(c1,c2.coefficient);
            ans.MP=ans.MP-c2.MP;
            if (c1.pow2!=0 &&c2.pow2!= 0)
            {
                RealVariable ans2;
                ans.MP=c1.MP-c2.MP;
                ans.pow2=c1.pow2-c2.pow2;
            }
            else if(c1.pow2!=0){
                ans.pow2=c1.pow2;
            }
            else if(c2.pow2!=0){
                ans.pow2=c2.pow2;
            }
        }
        else if(c1.power==0&&c2.power==1){
            ans=operator-(c1.coefficient,c2);
            ans.MP=ans.MP-c1.MP;
            if (c1.pow2!=0 &&c2.pow2!= 0)
            {
                ans.MP=c1.MP-c2.MP;
                ans.pow2=c1.pow2-c2.pow2;
            }
            else if(c1.pow2!=0){
                ans.pow2=c1.pow2;
            }
            else if(c2.pow2!=0){
                ans.pow2=c2.pow2;
            }
        }
        else{ //חזקות שוות 0
            ans.MP=c1.coefficient-c2.coefficient-c1.MP-c2.MP;
            if (c1.pow2!=0 &&c2.pow2!= 0)
            {
                ans.MP=c1.MP-c2.MP;
                ans.pow2=c1.pow2-c2.pow2;
            }
            else if(c1.pow2!=0){
                ans.pow2=c1.pow2;
            }
            else if(c2.pow2!=0){
                ans.pow2=c2.pow2;
            }
        }
        return ans;
    }
    RealVariable operator-(const double c1, const RealVariable &c2)
    {
        RealVariable ans(c2);
        if(c2.pow2!= 0)
        {
           ans.pow2=-c2.pow2;
        }

        ans.coefficient=-c2.coefficient;
        ans.MP=-c2.MP+c1;
        return ans;
    }
    RealVariable operator+(const double c1, const RealVariable &c2)
    {
        return operator+(c2, c1);
    }
    RealVariable operator+(const RealVariable &c1, const double c2)
    {
        RealVariable ans(c1);
        ans.MP=c1.MP+c2;
        return ans;
    }
    RealVariable operator-(const RealVariable &c1, const double c2)
    {
        RealVariable ans(c1);
        ans.MP=c1.MP-c2;
        return ans;
    }
    RealVariable operator*(const double c1,const RealVariable &c2)
    {
        return operator*(c2,c1);
    }
    RealVariable operator*(const RealVariable &c1, const double c2)
    {
        RealVariable ans2;
        if (c1.coefficient!=0) ans2.coefficient=c1.coefficient*c2;
        ans2.power=c1.power;
        if (c1.MP!=0) ans2.MP=c1.MP*c2;
        if(c1.pow2!= 0)
        {
            ans2.pow2=c1.pow2*c2;
        }
        return ans2;

    }
    RealVariable operator^(const RealVariable &c1, const int c2)
    {
        if(c2>2||c2<0) throw ("can not be less then 0 or big from 2");
        if(c1.pow2!= 0&&c2>1) throw ("power can not be big from 2");
if(c1.pow2== 0&&c2==2&&c1.MP==0)
{
    RealVariable ans;
    ans.coefficient=0;
    ans.power=0;
    ans.MP=0;
    ans.pow2=pow(c1.coefficient,2);
    return ans;
}
   else {
    RealVariable ans, ans2;
    double help = 1;//חישוב אמצע מקדם X

    ans.pow2= pow(c1.coefficient, c2);

    help = c1.coefficient * c1.MP * 2;

    ans.power = c1.power;
    ans.MP = pow(c1.MP, c2);
    ans.coefficient = help;
    return ans;
}
    }
    RealVariable operator/(const RealVariable &c1, const double c2)
    {
        RealVariable ans;
        ans.MP=c1.MP/c2;
        ans.coefficient=c1.coefficient/c2;
        if(c1.pow2!= 0) ans.pow2=c1.pow2/c2;
        return ans;
    }
    RealVariable operator*(const RealVariable &c1, const RealVariable &c2) {
        RealVariable ans;
        double help;//מקדם X
if((c1.pow2!= 0&&c2.pow2!= 0)||(c1.pow2!= 0&&c2.power==1)||(c2.pow2!= 0&&c1.power==1))throw invalid_argument("can not do ^>2");
        if(c1.power==c2.power==1)
        {

            help=c1.coefficient*c2.MP+c2.coefficient*c1.MP;

            ans.power=c2.power;
            ans.MP=c1.MP*c2.MP;
            ans.coefficient=help;
            ans.pow2=c1.coefficient*c2.coefficient;
        }
    }
    RealVariable operator==(const RealVariable &c1, const double c2)
    {

       return operator-(c1,c2);
    }
    RealVariable operator==(const RealVariable &c1, const RealVariable &c2)
    {
        return operator-(c1,c2);
    }
    RealVariable operator==(const double &c1, const RealVariable &c2)
    {
        RealVariable ans=operator*(c2,-1);
        return operator==(ans,-c1);
    }



///////////////////////////////////////////////////////////////////////



    //constractors
    ComplexVariable::ComplexVariable() {
        this->realNum=0.0;
        this->imagNum=0.0;
    }

    ComplexVariable::ComplexVariable(double realNum,double imagNum ) {
        this->realNum=realNum;
        this->imagNum=imagNum;
    }

///////////////////////////////////////////////////////////////////////
    complex<double> solve(ComplexVariable x) {

        return 2.9i;
    }
///////////////////////////////////////////////////////////////////////

    //operators
    ComplexVariable operator*(const double &c2, ComplexVariable &c1) {
        return ComplexVariable();
    }

    ComplexVariable operator-(const ComplexVariable &c1, const RealVariable &c2) {
        return ComplexVariable();
    }
    ComplexVariable operator-(const ComplexVariable &c1, const ComplexVariable &c2) {
        return ComplexVariable();
    }
    ComplexVariable operator==(const ComplexVariable &c1, const RealVariable &c2) {
        return ComplexVariable();
    }

    ComplexVariable operator^(const ComplexVariable &c1, const double &c2) {
        return ComplexVariable();
    }

    ComplexVariable operator/(const ComplexVariable &c1, const RealVariable &c2) {
        return ComplexVariable();
    }

    ComplexVariable operator+(const ComplexVariable &c1, const ComplexVariable &c2) {
        return ComplexVariable();
    }

    ComplexVariable operator+(const ComplexVariable &c1, complex<double> c2) {
        return ComplexVariable();
    }

    ComplexVariable operator+(const int c1, const ComplexVariable &c2) {
        return ComplexVariable();
    }

    ComplexVariable operator==(const ComplexVariable &c1, const ComplexVariable &c2) {
        return ComplexVariable();
    }





}

/*


    const ComplexVariable operator*(const ComplexVariable &c1, const ComplexVariable &c2) {
        return ComplexVariable(c1._re * c2._re - c1._im * c2._im,
                               c1._re * c2._im + c1._im * c2._re);
    }

    const RealVariable operator*(const int &c2const, RealVariable &c1) {
        return RealVariable();
    }
    bool operator==(const ComplexVariable &c1, const ComplexVariable &c2) {
        // this implementation can cause problems with
        // double precision (== for doubles)
        return ((c1._re == c2._re) && (c1._im == c2._im));
    }

    bool operator!=(const ComplexVariable &c1, const ComplexVariable &c2) {
        return ((c1._re != c2._re) || (c1._im != c2._im));
        //return (!(c1==c2));
        return (std::abs(c1._re - c2._re) > 0.0001 || std::abs(c1._im - c2._im) > 0.0001);
    }

    ComplexVariable operator^(const ComplexVariable &c1, const ComplexVariable &c2) {
        return ((c1._re != c2._re) || (c1._im != c2._im));
        // return (!(c1==c2));
    }


    const ComplexVariable operator-(const ComplexVariable &c1, const ComplexVariable &c2) {
        return ComplexVariable(c1._re - c2._re, c1._im - c2._im);
    }

    bool operator/(const ComplexVariable &c1, const int &c2) {
        return false;
    }


     ComplexVariable operator""i(long double d)
    {
        return ComplexVariable{0.0, static_cast<double>(d)};
    }

*/

