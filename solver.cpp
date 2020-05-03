//
// Created by avichai on 4/24/20.
//
#include <iostream>
#include <math.h>
#include "solver.hpp"
//using namespace std;
#include <complex>



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
        if(ans2.power==0)ans2.coefficient=0;
        if (c1.MP!=0) ans2.MP=c1.MP*c2;
        if(c1.pow2!= 0)
        {
            ans2.pow2=c1.pow2*c2;
        }
        return ans2;

    }
    RealVariable operator^(const RealVariable &c1, const int c2)
    {
        RealVariable ans, ans2;
        if(c2>2||c2<0) throw ("can not be less then 0 or big from 2");
        if(c1.pow2!= 0&&c2>1) throw ("power can not be big from 2");
if(c1.pow2== 0&&c2==2&&c1.MP==0)
{

    ans.coefficient=0;
    ans.power=0;
    ans.MP=0;
    ans.pow2=pow(c1.coefficient,2);

}
   else {

    double help = 1;//חישוב אמצע מקדם X

    ans.pow2= pow(c1.coefficient, c2);

    help = c1.coefficient * c1.MP * 2;

    ans.power = c1.power;
    ans.MP = pow(c1.MP, c2);
    ans.coefficient = help;

}
        return ans;
    }
    RealVariable operator/(const RealVariable &c1, const double c2)
    {
        RealVariable ans;
        ans.MP=c1.MP/c2;
        ans.coefficient=c1.coefficient/c2;
        if(c1.pow2!= 0) ans.pow2=c1.pow2/c2;
        return ans;
    }
    RealVariable operator*(const RealVariable &c1, const RealVariable &c2)
    {
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
        return  ans;
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
    ComplexVariable::ComplexVariable()
    {
        this->pow2.real(0);
        this->pow2.imag(0);
        this->coefficient.real(1);
        this->coefficient.imag(0);
        this->MP.real(0);
        this->MP.imag(0);


    }

    ComplexVariable::ComplexVariable(double realNum,double imagNum )
    {
        this->pow2.real(0);
        this->pow2.imag(0);
        this->coefficient.real(realNum);
        this->coefficient.imag(imagNum);
        this->MP.real(0);
        this->MP.imag(0);
    }
    ComplexVariable::ComplexVariable(ComplexVariable &other)
    {
        this->pow2=other.pow2;
        this->coefficient=other.coefficient;
        this->MP=other.MP;
    }
    ComplexVariable::ComplexVariable(complex<double> pow2, complex<double> coefficient, complex<double> MP) {
        this->pow2=pow2;
        this->coefficient=coefficient;
        this->MP=MP;
    }

    ComplexVariable::ComplexVariable(double pow2Real,double pow2Imag,double coefficientReal,double coefficientImag,double PMReal,double PMmag)
    {
        this->pow2.real(pow2Real);
        this->pow2.imag(pow2Imag);
        this->coefficient.real(coefficientReal);
        this->coefficient.imag(coefficientImag);
        this->MP.real(PMReal);
        this->MP.imag(PMmag);
    }

///////////////////////////////////////////////////////////////////////
    complex<double> solve(ComplexVariable x)
    {
        complex<double> ans=0;
        if(x.pow2.imag()==0&&x.coefficient.imag()==0&&x.MP.imag()==0&&x.pow2.real()==0)
        {
            return -x.MP.real()/x.coefficient.real();
        }
            else if(x.pow2.imag()==0&&x.coefficient.imag()==0&&x.MP.imag()==0)
        {
            double sq=pow(x.coefficient.real(),2)-4*x.pow2.real()*x.MP.real();
            if (sq<0)
            {
                ans.imag((-x.coefficient.real() + sqrt(-sq)) / (2 * x.pow2.real()))  ;

            }
            else {
                ans = (-x.coefficient.real() + sqrt(sq)) / (2 * x.pow2.real());
                // ans=ans*10000; //שיחזיר 4 ספרות אחרי הנקודה
                //  int help=(int)(ans);
                //  ans=(double)help/10000;
            }
            return ans;
        }
else if(x.pow2.imag()==0&&x.pow2.real()==0&&x.MP.real()==0&&x.MP.imag()==0) {
            ans.imag(x.coefficient.imag());
            ans.real(0);

        }
return ans;
    }

///////////////////////////////////////////////////////////////////////

    //operators

    ComplexVariable operator-(const ComplexVariable &c1, const double &c2)
    {
        ComplexVariable ans(c1.pow2,c1.coefficient,c1.MP-c2);
        return ans;
    }
    ComplexVariable operator-( const double &c1,const ComplexVariable &c2)
    {
        ComplexVariable ans(-c2.pow2,-c2.coefficient,-c2.MP+c1);
        return ans;
    }
    ComplexVariable operator-(const ComplexVariable &c1, const ComplexVariable &c2)
    {
        ComplexVariable ans(c1.pow2-c2.pow2,c1.coefficient-c2.coefficient,c1.MP-c2.MP);
        return ans;
    }
    ComplexVariable operator-(const ComplexVariable &c1, complex<double> c2)
    {
        { //מנקודת הנחה שמחברים את ה 2Xi
            ComplexVariable ans(c1.pow2,c1.coefficient-c2,c1.MP);
            return ans;
        }
    }
    ComplexVariable operator+(const ComplexVariable &c1, const ComplexVariable &c2)
    {
        ComplexVariable ans(c1.pow2+c2.pow2,c1.coefficient+c2.coefficient,c1.MP+c2.MP);
        return ans;
    }
    ComplexVariable operator+(const ComplexVariable &c1, complex<double> c2)
    { //מנקודת הנחה שמחברים את ה 2Xi
        ComplexVariable ans(c1.pow2,c1.coefficient+c2,c1.MP);
        return ans;
    }
    ComplexVariable operator+(const double c1, const ComplexVariable &c2)
    {
        ComplexVariable ans(c2.pow2,c2.coefficient,c2.MP+c1);
        return ans;
    }
    ComplexVariable operator+(const ComplexVariable &c1, const double c2)
    {
        return operator+(c2,c1);
    }
    ComplexVariable operator*(const double c1, const ComplexVariable &c2)
    {
        ComplexVariable ans(c2.pow2*c1,c2.coefficient*c1,c2.MP*c1);
        return ans;
    }
    ComplexVariable operator*(const ComplexVariable &c1, const double c2)
    {
        return operator*(c2,c1);
    }
    ComplexVariable operator*(ComplexVariable &c1, ComplexVariable &c2)
    {
        ComplexVariable ans(0,0);
        if((c1.pow2.imag()!=0&&c2.pow2.imag()!=0)||(c1.pow2.imag()!=0&&c2.pow2.real()!=0)||(c1.pow2.real()!=0&&c2.pow2.imag()!=0)||(c1.pow2.imag()!=0&&c2.pow2.imag()!=0))
            throw invalid_argument("we can not solve power bigger then 2");
        else if((c1.pow2.imag()!=0&&c2.coefficient.imag()!=0)||(c1.pow2.imag()!=0&&c2.coefficient.real()!=0)||(c1.pow2.real()!=0&&c2.coefficient.imag()!=0)||(c1.pow2.real()!=0&&c2.coefficient.real()!=0))
            throw invalid_argument("we can not solve power bigger then 2");
        else if (c1.pow2.real()!=0||c1.pow2.imag()!=0){//בc1 יש חזקת 2
           // int j=1;
           // cout<<ans.pow2<<ans.coefficient<<ans.MP<<j++<<endl;
            ans.pow2.real(c1.pow2.real()*c2.MP.real());
           // cout<<ans.pow2<<ans.coefficient<<ans.MP<<j++<<endl;
            ans.pow2.imag(c1.pow2.real()*c2.MP.imag());
           // cout<<ans.pow2<<ans.coefficient<<ans.MP<<j++<<endl;
            ans.pow2.imag((c1.pow2.imag()*c2.MP.real())+ans.pow2.imag());
           // cout<<ans.pow2<<ans.coefficient<<ans.MP<<j++<<endl;
            ans.pow2.real((-c1.pow2.imag()*c2.MP.imag())+ans.pow2.real());
           // cout<<ans.pow2<<ans.coefficient<<ans.MP<<j++<<endl;
            //טיפול בX
            ans.coefficient.real(c1.coefficient.real()*c2.MP.real());
            ans.coefficient.imag(c1.coefficient.real()*c2.MP.imag());
            ans.coefficient.imag((c1.coefficient.imag()*c2.MP.real())+ans.coefficient.imag());
            ans.coefficient.real((-c1.coefficient.imag()*c2.MP.imag())+ans.coefficient.real());
            //מספרים רגילים
            ans.MP.real(c1.MP.real()*c2.MP.real());
            ans.MP.imag(c1.MP.real()*c2.MP.imag());
            ans.MP.imag((c1.MP.imag()*c2.MP.real())+ans.MP.imag());
            ans.MP.real((-c1.MP.imag()*c2.MP.imag())+ans.MP.real());
        }
        else if (c2.pow2.real()!=0||c2.pow2.imag()!=0){//בc2 יש חזקת 2
            // טיפול בחזקות2
            ans.pow2.real(c2.pow2.real()*c1.MP.real());
            ans.pow2.imag(c2.pow2.real()*c1.MP.imag());
            ans.pow2.imag((c2.pow2.imag()*c1.MP.real())+ans.pow2.imag());
            ans.pow2.real((-c2.pow2.imag()*c1.MP.imag())+ans.pow2.real());
           //טיפול בX
            ans.coefficient.real(c2.coefficient.real()*c1.MP.real());
            ans.coefficient.imag(c2.coefficient.real()*c1.MP.imag());
            ans.coefficient.imag((c2.coefficient.imag()*c1.MP.real())+ans.coefficient.imag());
            ans.coefficient.real((-c2.coefficient.imag()*c1.MP.imag())+ans.coefficient.real());
            //מספרים רגילים
            ans.MP.real(c2.MP.real()*c1.MP.real());
            ans.MP.imag(c2.MP.real()*c1.MP.imag());
            ans.MP.imag((c2.MP.imag()*c1.MP.real())+ans.MP.imag());
            ans.MP.real((-c2.MP.imag()*c1.MP.imag())+ans.MP.real());
        }
        else{ //(ax+axi)(ax+axi)
            ans.pow2.real((c1.coefficient.real()*c2.coefficient.real())+(-c1.coefficient.imag()*c2.coefficient.imag()));
            ans.pow2.imag((c1.coefficient.real()*c2.coefficient.imag())+(c1.coefficient.imag()*c2.coefficient.real()));
            ans.coefficient.real((c1.coefficient.real()*c2.MP.real())+(-c1.coefficient.imag()*c2.MP.imag())+(c1.MP.real()*c2.coefficient.real())+(-c1.MP.imag()*c2.coefficient.imag()));
            ans.coefficient.imag((c1.coefficient.real()*c2.MP.imag())+(c1.coefficient.imag()*c2.MP.real())+(c1.MP.real()*c2.coefficient.imag())+(c1.MP.imag()*c2.coefficient.real()));
            ans.MP.real((c1.MP.real()*c2.MP.real())+(-c1.MP.imag()*c2.MP.imag()));
            ans.MP.imag((c1.MP.imag()*c2.MP.real())+(c1.MP.real()*c2.MP.imag()));
        }
        return ans;
    }
    ComplexVariable operator==(const ComplexVariable &c1, const ComplexVariable &c2)
    {
        ComplexVariable ans(c1.pow2-c2.pow2,c1.coefficient-c2.coefficient,c1.MP-c2.MP);
        return ans;
    }
    ComplexVariable operator==(const ComplexVariable &c1, const double &c2)
    {
        ComplexVariable ans(c1.pow2,c1.coefficient,c1.MP-c2);
        return ans;
    }
    ComplexVariable operator^(const ComplexVariable &c1, const double &c2)
    {
        if (c2 > 2) throw invalid_argument("we can not solve power bigger then 2");
        else if ((c1.pow2.real() != 0 || c1.pow2.imag() != 0) && c2 == 2)
            throw invalid_argument("we can not solve power bigger then 2");
        else if (c2 == 2) {
            ComplexVariable ans(1, 0, 0);
            return ans;
        } else if (c2 == 1) {
            ComplexVariable ans(c1.pow2, c1.coefficient, c1.MP);
            return ans;
        }
        throw invalid_argument("wrong");
    }
    ComplexVariable operator/(const ComplexVariable &c1, const double &c2)
    {
        ComplexVariable ans(c1.pow2/c2,c1.coefficient/c2,c1.MP/c2);
        return ans;
    }

}



