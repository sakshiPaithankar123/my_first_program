#include<iostream>
using namespace std;
class complex{
    private:
    float real;
    float imag;
    public:
    complex(){
        real=0;
        imag=0;
    }
    complex(float r,float i){
        real=r;
        imag=i;
    }
    ~complex(){ }
    void display(){
        cout<<real<<"+"<<imag<<"i"<<endl;
    }
    complex add(complex c){
        return complex(real+c.real,imag+c.imag);
    }
    complex subtract(complex c){
        return complex(real-c.real,imag-c.imag);
    }
    complex multiply(complex c){
        float r=real*c.real-imag*c.imag;
        float i=real*c.imag+imag*c.real;
        return complex(r,i);
    }
};
int main(){
    complex c1(4,5),c2(2,3);
    cout<<"\nfirst complex number:";
    c1.display();
    cout<<"second complex number:";
    c2.display();
    complex sum=c1.add(c2);
    cout<<"\nsum:";
    sum.display();
    complex diff=c1.subtract(c2);
    cout<<"difference:";
    diff.display();
    complex prod=c1.multiply(c2);
    cout<<"product:";
    prod.display();
    return(0);
}