//
// Created by avichai on 4/24/20.
//
#include <complex>
using namespace std;

namespace solver{


    class RealVariable {
    //private:
    public:
        double MP;
        double coefficient;
        int power;
        double pow2;


        //constractors
        RealVariable();
        RealVariable(double realNum);
        RealVariable(RealVariable const &other);

        //operators
        friend RealVariable operator==(const double &c1, const RealVariable &c2);
        friend RealVariable operator==(const RealVariable& c1, const RealVariable& c2);
        friend RealVariable operator==(const RealVariable& c1, const double c2);
        friend RealVariable operator^(const RealVariable& c1, const int c2);
        friend RealVariable operator/(const RealVariable& c1,const double c2 ) ;

        friend RealVariable operator- (const RealVariable& c1, const RealVariable& c2);
        friend RealVariable operator-(const RealVariable &c1,const double c2);
        friend RealVariable operator-( const double c1,const RealVariable &c2);

        friend RealVariable operator+(const RealVariable &c1, const RealVariable &c2);
        friend RealVariable operator+ (const RealVariable &c1, const double c2);
        friend RealVariable operator+ (const double c1 ,const RealVariable &c2);

        friend RealVariable operator* (const double c1 ,const RealVariable& c2);
        friend RealVariable operator* (const RealVariable &c1, const double c2);
        friend RealVariable operator* (const RealVariable &c1,const RealVariable &c2);


    };




    class ComplexVariable {
    public:
   // private:
        complex<double> pow2;
        complex<double> coefficient;
        complex<double> MP;


        //constractors

        ComplexVariable();
        ComplexVariable(double realNum,double imagNum);
        ComplexVariable(ComplexVariable &other);
        ComplexVariable(complex<double> pow2, complex<double> coefficient,complex<double> MP);
        ComplexVariable(double pow2Real,double pow2Imag,double coefficientReal,double coefficientImag,double PMReal,double PMmag);


        //operators
        friend ComplexVariable operator* (const double c1 ,const ComplexVariable& c2);
        friend ComplexVariable operator* (const ComplexVariable& c1,const double c2);
        friend ComplexVariable operator* (ComplexVariable& c1,ComplexVariable& c2);
        friend ComplexVariable operator- (const ComplexVariable& c1, const double& c2);
        friend ComplexVariable operator- (const double& c1,const ComplexVariable& c2);
        friend ComplexVariable operator -(const ComplexVariable &c1, complex<double>c2);
        friend ComplexVariable operator- (const ComplexVariable& c1, const ComplexVariable& c2);
        friend ComplexVariable operator==(const ComplexVariable& c1, const double & c2);
        friend ComplexVariable operator==(const ComplexVariable& c1, const ComplexVariable& c2);
        friend ComplexVariable operator^(const ComplexVariable& c1, const double& c2);
        friend ComplexVariable operator/(const ComplexVariable& c1,const double & c2 ) ;
        friend ComplexVariable operator +(const ComplexVariable &c1, const ComplexVariable &c2);
        friend ComplexVariable operator +(const double c1, const ComplexVariable &c2);
        friend ComplexVariable operator+(const ComplexVariable &c1, const double c2);
        friend ComplexVariable operator +(const ComplexVariable &c1, complex<double>c2);

    };

//solve function
        double solve(RealVariable x);
   complex<double> solve(ComplexVariable x);


  /*

    class ComplexVariable{
    private:
        double _re;
        double _im;

    public:

        // Constructor. Also works as a conversion from double and
        // also as a default ctor.
        ComplexVariable (const double& re= 0.0,
                 const double& im= 0.0)
                : _re(re), _im(im) {
        }

        // getters
        double re() const {
            return _re;
        }

        double im() const {
            return _im;
        }

        // Logical NOT
        bool operator!() const {
            return _re==0 && _im==0;
        }

        // the const on the return type is to
        // avoid -c1 = c10 from working
        const ComplexVariable operator-() const {
            return ComplexVariable(-_re , -_im);
            // longer version:
            //ComplexVariable result;
            //result._re = -_re;
            //result._im = -_im;
            //return result;
        }

        //----------------------------------------
        // binary operators
        //----------------------------------------

        // (c1+c2) = 5;

        const ComplexVariable operator+(const ComplexVariable& other) const {
            return ComplexVariable(_re + other._re, _im + other._im);
            //  5+7=12;
        }



        ComplexVariable& operator+=(const ComplexVariable& other) {
            _re+= other._re;
            _im+= other._im;
            return *this; // for call chaining
        }

        // const ComplexVariable operator-(const ComplexVariable& other) const {
        //     return ComplexVariable(_re - other._re, _im - other._im);
        // }

        ComplexVariable& operator-=(const ComplexVariable& other) {
            _re-= other._re;
            _im-= other._im;
            return *this;
        }

        // (a+bi)*(c+di) =
        // (ac-bd) + (ad+bc)i
        ComplexVariable& operator*=(const ComplexVariable& other) {
            double new_re = _re*other._re - _im*other._im;
            double new_im = _re*other._im + _im*other._re;
            _re = new_re;
            _im = new_im;
            // version with bug
            // _im= _re*other._im + _im*other._re;
            // _re= _re*other._re - _im*other._im;
            return *this;
        }
        //----------------------------------------


        operator double() const {
            return double();
        }


        // prefix increment:
        ComplexVariable& operator++() {
            _re++;
            return *this;
        }

        // postfix increment:
        const ComplexVariable operator++(int dummy_flag_for_postfix_increment) {
            ComplexVariable copy = *this;
            _re++;
            return copy;
        }
        //-------------------------------------
        // friend global binary operators
        //-------------------------------------
        friend const ComplexVariable operator- (const ComplexVariable& c1, const ComplexVariable& c2);
        friend const ComplexVariable operator* (const ComplexVariable& c1, const ComplexVariable& c2);
        friend bool operator==(const ComplexVariable& c1, const ComplexVariable& c2);
        friend bool operator!=(const ComplexVariable& c1, const ComplexVariable& c2);



    };

  //  ComplexVariable operator""i(unsigned long long arg);


    */
};





