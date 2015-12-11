#include<iostream>
using namespace std;
class complex{
private:
	double real;
	double imag;
public:
	complex(double r = 0.0, double i = 0.0){
		real = r; imag = i;
	}
	void setreal(double r){
		real = r;
	}
	void setimag(double i){
		imag = i;
	}
	double getreal(){
		return real;
	}
	double getimag(){
		return imag;
	}
	complex operator +(complex c2);
	complex operator -(complex c2);
	friend complex operator *(const complex &c1, const complex &c2);
	friend complex operator /(const complex &c1, const complex &c2);
	void display();

};
complex complex::operator +(complex c2){
	return complex(real + c2.real, imag + c2.imag);
}
complex complex::operator -(complex c2){
	return complex(real - c2.real, imag - c2.imag);
}
complex operator *(const complex &c1, const complex &c2){
	double x, y;
	x = c1.real*c2.real - c1.imag*c2.imag;
	y = c1.real*c2.imag + c1.imag*c2.real;
	return complex(x, y);
}
complex operator /(const complex &c1, const complex &c2){
	double x, y, z;
	x = c1.real*c2.real + c1.imag*c2.imag;
	y = c1.imag*c2.real - c1.real*c2.imag;
	z = c2.real*c2.real + c2.imag*c2.imag;
	return complex(x / z, y / z);
}
void complex::display(){
	cout << real << " + " << imag << "i" << endl;
}
int main(){
	complex  c1(1, 2), c2(1, 3), c3, c4, c5, c6;
	c3 = c1 + c2;
	c3.display();
	c4 = c1 - c2;
	c4.display();
	c5 = c1*c2;
	c5.display();
	c6 = c1 / c2;
	c6.display();
	system("PAUSE");
	return 0;

}