#include<iostream>
#include<cmath>
#include<cstring>
#include<sstream>
using namespace std;
#define Arrow() ( "-->" ) 					//Arrow Used for Options at many Places
struct Complex{
	float real, imaginary;
	void get_data();
	void display();
	Complex sum(const Complex first, const Complex second);
	Complex minus(const Complex first, const Complex second);
	Complex negative(const Complex number);
	Complex conjugate(const Complex number);
	float magnitude();
	bool equality(const Complex first);
	Complex product(const Complex first, const Complex second);
	void multiplicative_inverse(const Complex number);
};
void Complex :: display(){
	if(imaginary < 0)
	cout << real << imaginary << "i" << endl;
	else
	cout << real << "+" << imaginary << "i" << endl;
}

void Complex :: get_data(){
	char *input  = new char[8];        //Input of Natural way of Complex Number
	string a = "", b = "";			  //Spliting of real & imaginary Parts from ab;
	bool error = false;              //For checking wether + is Ocuurs between complex number or minus
	int index = 0;
	cin.ignore();	
	//Input of Complex Number
	cout << "Enter Complex Number: ";
	cin.getline(input, 30, '\n');
	cin.clear();
	
	//Index for Spliting
	for(int i = 0; i < strlen(input); i++){
			if(input[i] == '+' || input[i] == '-'){
				index = i;
				if(input[i] == '-') error = true;
				if(input[i] == '+') break;
			}
		}
		
	//Spliting of Complex Number if both real & imaginary parts are Present
	if(index != 0){
		for(int i = 0; i < index; i++)
			a += input[i];
		for(int i = index+1; i < strlen(input)-1; i++)
			b += input[i];
			}

	//if Only One Part Present
	else{
			if(input[strlen(input)-1] == 'i')
					b += input;
			else
					a += input;
	}
	
	//String stream for assigning to float variables
	stringstream ss;
	//Real Number Extracting
	if(index != 0){
		for(int i=0; i<a.size(); i++){
			if(isdigit(a[i]) || a[i] == '-' || a[i] == '.')
				ss << a[i];
		}
			ss >> real;
			ss.clear();
		//Imaginary Number Extracting	
			for(int i = 0; i < b.size(); i++){
					if(isdigit(b[i]) || b[i] == '.')
						ss << b[i];
				}
			ss >> imaginary;
			ss.clear();
			if(error) imaginary = -imaginary;
	}
	
	//If Only One Part is Present
	else {
		if(a == ""){
		real = 0;
		ss << b;
		ss >> imaginary;
	}
	else{
		imaginary = 0;
		ss << a;
		ss >> real; 
	}
	}
	
	delete [] input;
}
	
Complex Complex :: minus(const Complex first, const Complex second){
	Complex result;
	result.real = first.real - second.real;	
	result.imaginary = first.imaginary - second.imaginary;
	return result;
}

Complex Complex :: sum(const Complex first, const Complex second){
	Complex result;
	result.real = first.real + second.real;	
	result.imaginary = first.imaginary + second.imaginary;
	return result;
}
Complex Complex :: negative(const Complex number){
	Complex result;
	result.real = -number.real;	
	result.imaginary = -number.imaginary;
	return result;
}

Complex Complex :: conjugate(const Complex number){
	Complex result;
	result.real = number.real;	
	result.imaginary = -number.imaginary;
	return result;
}

float Complex :: magnitude(){
	float magnitude;
	magnitude = sqrt( (real*real) + (imaginary*imaginary)); 
	return magnitude;
}

bool Complex :: equality(const Complex first){
	if(real == first.real && imaginary == first.imaginary) return true;
	return false;
}

Complex Complex :: product(const Complex first, const Complex second){
	Complex result;
	result.real = ( (first.real*second.real) - (first.imaginary*second.imaginary) );
	result.imaginary =  ( (first.real*second.imaginary) + (first.imaginary*second.real) );
	return result;
} 
void Complex :: multiplicative_inverse(const Complex number){
	Complex denominator, numenator;
	denominator = denominator.conjugate(number);
	numenator = numenator.product(number, denominator);
	denominator.display();
	cout << "-------" << endl;
	numenator.display();
}

int main(){
	
	Complex var1, var2;
	int option;
	cout << "Press Enter to Continue: ";
	var1.get_data();
	
	//Testor funtions of Complex Struct
	cout << "\n1)" << Arrow() << "Conjugate of Complex Number\n";
	cout << "2)" << Arrow() << "Minus of Complex Number\n";
	cout << "3)" << Arrow() << "Magnitude of Complex Number\n";
	cout << "4)" << Arrow() << "Multiplicative Inverse of Complex Number\n";
	cout << "5)" << Arrow() << "Sum of Complex Number\n";
	cout << "6)" << Arrow() << "Product of Complex Number\n";
	cout << "7)" << Arrow() << "Diffrence of Complex Number\n";
	cout << "8)" << Arrow() << "Equality of Complex Number\n";
	cout << "\nEnter Your Option Please: ";
	cin >> option;
	switch(option){
		case 1:
			var1.conjugate(var1).display();
			break;
		case 2:
			var1.negative(var1).display();
			break;
		case 3:
			cout << "Magnitude is: " << var1.magnitude();
			break;
		case 4:
			var1.multiplicative_inverse(var1);
			break;
		case 5:
			cout << "Enter second Complex Number\n\n";
			var2.get_data();
			var1.sum(var1, var2).display();	
			break;
		case 6:
			cout << "Enter second Complex Number\n\n";
			var2.get_data();
			var1.product(var1, var2).display();	
			break;
		case 7:
			cout << "Enter second Complex Number\n\n";
			var2.get_data();
			var1.minus(var1, var2).display();	
			break;
		case 8:
			cout << "Enter second Complex Number\n\n";
			var2.get_data();
			cout <<  var1.equality(var2);
			break;
		default:
			cout << "Wrong Input\n";
	
	}
	return 0;

}
