#include <iostream>
#include <iomanip>
#include <limits>
#include <sstream>
#include <cassert>
#include <string>

using namespace std;

string reverse_pairs(string const &src){
	assert(src.size() % 2 == 0);
	string result;
	result.reserve(src.size());

	for (size_t i = src.size(); i != 0; i -= 2){
		result.append(src, i - 2, 2);
	}
	return result;
}

string ieee_float_to_hex(float f){
	static_assert(numeric_limits<float>::is_iec559, "native float must be an IEEE float");
	union {float fval ; std::uint32_t ival ; };
	fval = f;
	ostringstream stm;
	stm << std::hex << std::uppercase << ival;
	string result;
	result = reverse_pairs(stm.str());
	return result;

}


int main(){
	signed int spriteX1;
	signed int spriteX2;
	string x1Input;
	string x2Input;
	signed int spriteY1;
	signed int spriteY2;
	string y1Input;
	string y2Input;
	signed int xOffset;
	signed int offset;
	// for dividing, asset size should be 512x512
	signed int assetSize = 512;
	// Pixel size is 4.54545466667 in game
	float pixelSize = 4.5454546667;
	float X1;
	float X2;
	float Y1;
	float Y2;
	float Z1;
	float Z2;
	float W1;
	float W2;
	

	// Take input, and convert it to hex float
	cout << "Pixel Top Left X:" << endl;
	cin >> x1Input;
	cout << "Pixel Top Left Y:" << endl;
	cin >> y1Input;
	cout << "Pixel Bottom Right X:" << endl;
	cin >> x2Input;
	cout << "Pixel Bottom Right Y:" << endl;
	cin >> y2Input;
	cout << "X offset:" << endl;
	cin >> xOffset;
	cout << "Floor Pixel offset (usually 18):" << endl;
	cin >> offset;

	spriteX1 = stoi(x1Input);
	spriteX2 = stoi(x2Input);
	spriteY1 = stoi(y1Input);
	spriteY2 = stoi(y2Input);
	
	std::cout.precision(8);
	// Calculate the floats, and take them as an input
	signed int delX = spriteX2 - spriteX1;
	X1 = ((delX + xOffset) / 2) * pixelSize;
	X2 = -((delX - xOffset) / 2) * pixelSize;
	signed int delY = spriteY2 - spriteY1;
	Y1 = (offset) * pixelSize;
	Y2 = (offset + delY) * pixelSize;
	Z1 = (static_cast<float>(spriteX1) / 512);
	Z2 = (static_cast<float>(spriteX2) / 512);
	W1 = (static_cast<float>(spriteY1) / 512);
	W2 = (static_cast<float>(spriteY2) / 512);


	cout << "Output should be in the following format:" << endl;
	cout << "X2 Y2 Z2 W1, X1 Y2 Z1 W1, X1 Y1 Z1 W2, X2 Y1 Z2 W2, X2 Y2 Z2 W1, X1 Y1 Z1 W2" << endl;
	cout << ieee_float_to_hex(X1) << ieee_float_to_hex(Y2) << ieee_float_to_hex(Z2) << ieee_float_to_hex(W1);
	cout << ieee_float_to_hex(X2) << ieee_float_to_hex(Y2) << ieee_float_to_hex(Z1) << ieee_float_to_hex(W1);
	cout << ieee_float_to_hex(X2) << ieee_float_to_hex(Y1) << ieee_float_to_hex(Z1) << ieee_float_to_hex(W2);
	cout << ieee_float_to_hex(X1) << ieee_float_to_hex(Y1) << ieee_float_to_hex(Z2) << ieee_float_to_hex(W2);
	cout << ieee_float_to_hex(X1) << ieee_float_to_hex(Y2) << ieee_float_to_hex(Z2) << ieee_float_to_hex(W1);
	cout << ieee_float_to_hex(X2) << ieee_float_to_hex(Y1) << ieee_float_to_hex(Z1) << ieee_float_to_hex(W2) << endl;
}
