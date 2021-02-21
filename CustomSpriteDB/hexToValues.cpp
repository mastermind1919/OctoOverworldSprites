#include <iostream>
#include <iomanip>
#include <limits>
#include <sstream>
#include <cassert>
#include <string>

using namespace std;



int main(int argc, char **argv){

	if (argc == 97){
		// Take the input, and convert the specific values to floats
		float pixelSize = 4.5454546667;
		// ignore the Z and W values, as they are certain to be changed
		// For X1;
		// Little endian order, so just reverse the bytes
		string X1H;
		X1H += argv[20];
		X1H += argv[19];
		X1H += argv[18];
		X1H += argv[17];

		unsigned int X1;
		std::stringstream X1S;
		X1S << std::hex << X1H;
		X1S >> X1;
		cout << "X1: " << reinterpret_cast<float&>(X1) << endl;

		// For X2;
		string X2H;
		X2H += argv[4];
		X2H += argv[3];
		X2H += argv[2];
		X2H += argv[1];
		unsigned int X2;
		std::stringstream X2S;
		X2S << std::hex << X2H;
		X2S >> X2;
		cout << "X2: " << reinterpret_cast<float&>(X2) << endl;
		
		// For Bottom
		string Y1H;
		Y1H += argv[40];
		Y1H += argv[39];
		Y1H += argv[38];
		Y1H += argv[37];
		unsigned int Y1;
		std::stringstream Y1S;
		Y1S << std::hex << Y1H;
		Y1S >> Y1;

		// Print out results for program
		cout << "For program:" << endl;
		float offset = (reinterpret_cast<float&>(X2) / pixelSize) + (reinterpret_cast<float&>(X1) / pixelSize);
		cout << "Base Offset: " << offset << endl;
		cout << "Bottom Pixel: " << (reinterpret_cast<float&>(Y1) / pixelSize) << endl;
		

	}
	else {
		cout << "Usage: hexToFile <Hex input from HxD>" << endl; 
	}

}
