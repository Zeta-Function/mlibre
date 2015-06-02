
#ifndef _cnum_h
#define _cnum_h


#endif

#include &lt;cmath>
#include &lt;cassert>
#include &lt;vector>

class cnum{
private:
    double x, y;
    
public:
    //Constructor
    cnum(double X, double Y){
        x=X;
        y=Y;
    }
    
    cnum(){
        x=0;
        y=0;
    }
    
    cnum(double X){
        x=X;
        y=0;
    }
    
    //Accessors
    const double& re() const {
        return x;
    }
    
    const double& im() const {
        return y;
    }
    
    const double arg() const {
        return atan(y/x);
    }
    
    //Mutators
    double& re() {
        return x;
    }
    
    double& im() {
        return y;
    }
    
    //Printing Of cnum
    friend std::ostream& operator&lt;&lt;(std::ostream& __lhs, const cnum& __rhs) {
        __lhs &lt;&lt; __rhs.x &lt;&lt; "+" &lt;&lt; __rhs.y &lt;&lt; "i";
        return __lhs;
    }
    
    
    //cnum-cnum Operators
    friend cnum operator*(const cnum& lhs, const cnum& rhs){
        cnum K;
        K.re()=lhs.re()*rhs.re()-lhs.im()*rhs.im();
        K.im()=lhs.re()*rhs.im()+lhs.im()*rhs.re();
        return K;
    }
    
    friend cnum operator/(const cnum& lhs, const cnum& rhs){
        assert(rhs.re()*rhs.re() + rhs.im()*rhs.im() != 0);
        cnum K;
        double fact = rhs.re()*rhs.re() + rhs.im()*rhs.im();
        K.re()=(lhs.re()*rhs.re() + lhs.im()*rhs.im())/fact;
        K.im()=(lhs.im()*rhs.re()-lhs.re()*rhs.im())/fact;
        return K;
    }
    
    friend cnum operator+(const cnum& lhs, const cnum& rhs){
        cnum K;
        K.re()=lhs.re()+rhs.re();
        K.im()=lhs.im()+rhs.im();
        return K;
    }
    
    friend cnum operator-(const cnum& lhs, const cnum& rhs){
        cnum K;
        K.re()=lhs.re()-rhs.re();
        K.im()=lhs.im()-rhs.im();
        return K;
    }
    
    
    
    //Exponent Operator
    friend cnum pow(const cnum& lhs, const cnum& rhs){
        cnum K;
        double s = pow(lhs.re()*lhs.re()+lhs.im()*lhs.im(),rhs.re()/2)*exp(-rhs.im()*lhs.arg());
        double t = rhs.re()*lhs.arg()+0.5*rhs.im()*log(lhs.re()*lhs.re()+lhs.im()*lhs.im());
        K.re()= s*cos(t);
        K.im()= s*sin(t);
        
        if(K.re()*K.re()&lt;0.000001)
            K.re()=0;
        if(K.im()*K.re()&lt;0.000001)
            K.im()=0;
        return K;
    }
    
    //Absolute Value
    double abs(){
        return sqrt(x*x+y*y);
    }
    
    //Principal Log
    cnum plog(){
        assert(x != 0 and y != 0);
        cnum temp;
        temp.re()=log(this->abs());
        temp.im()=this->arg();
        return temp;
    }
    
    
    
    //ZETA FUNCTIONS
    
    //Gm
    cnum zgm(double q){
        cnum lol=*this;
        cnum sum(1,0);
        cnum recip(-1,0);
        cnum one(1,0);
        for(double k=1; k&lt;50; ++k){
            cnum temp(pow(q,-k),0);
            sum = sum*pow((one-temp*lol),recip);
        }
        return sum;
    }
    
    //T2
    cnum zt2(double q){
        cnum lol=*this;
        cnum sum(1,0);
        cnum recip(-1,0);
        cnum one(1,0);
        for(double k=1; k&lt;25; ++k)
            for(double j=1; j&lt;25; ++j){
                cnum temp(pow(q,-k-j),0);
                sum = sum*pow((one-temp*lol),recip);
            }
        return sum;
        
    }
    //G2
    cnum zg2(double q){
        cnum lol=*this;
        cnum sum(1,0);
        cnum recip(-1,0);
        cnum one(0,0);
        cnum ee(2.718281,0);
        for(double i=1; i&lt;10; ++i){
            cnum temp(i,0);
            cnum temp2(pow(q,6*i)*(pow(q,6*i)-1)*(pow(q,2*i)-1),0);
            //  std::cout &lt;&lt; temp &lt;&lt; "\t";
            //  std::cout &lt;&lt; temp2 &lt;&lt; std::endl;
            sum = sum+(pow(lol,temp)/temp)/(temp2);
        }
        return pow(ee,sum);
    }
    
};

//Meshing Operator
std::vector&lt;cnum> mesh(const double& xlow, const double& xup, const double& ylow, const double& yup, const double& resolution){
    assert(xlow &lt; xup and ylow &lt; yup and resolution > 0);
    std::vector&lt;cnum> _M;
    double xdif = xup-xlow;
    double ydif = yup - ylow;
    // cnum temp(xlow,ylow);
    // _M.push_back(temp);
    for(double i=0; i&lt;resolution+1; ++i)
        for(double j=0; j&lt;resolution+1; ++j){
            cnum temp;
            temp.re() = xlow+xdif*(i/resolution);
            temp.im() = ylow+ydif*(j/resolution);
            _M.push_back(temp);
        }
    std::cout &lt;&lt; "test" &lt;&lt; std::endl;
    
    return _M;
}

