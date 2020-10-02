// Name: B10332021 黃昱崴
// Date:2017.2.23
// Last Update: 2017.2.23
// Problem statement: 大數相加
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
bool g = true;
inline int max(int a, int b) { return a > b ? a : b; }
//大數結構
struct BigInt{
	bool check;
    int v_size;
    int numData[9999+1];
};
//輸出
void PrintNumber(const BigInt &number){
	if (number.check) cout << '-';
    for (int i = number.v_size - 1; i >= 0; --i) cout << number.numData[i];
	cout << endl;
}
//轉為數字型態
void ToInt(const string &buffer, BigInt &result){
	result.check = buffer[0] == '-';
	result.v_size = buffer.size() - result.check;
    int size = result.v_size;
	while (--size >= 0){
		result.numData[size] = buffer[result.v_size - size - !result.check] - '0';
		if (result.numData[size] < 0 || result.numData[size] > 9)
			g = false;
	}
}
//讀取大數
void Read(BigInt &result){
	string input;
	getline(cin, input);
	ToInt(input, result);
}
//大數相加
BigInt Add(const BigInt &n1, const BigInt &n2){
	BigInt result{ false, 0,{ 0 } };
	int i = 0, carry = 0, sum = 0;
	for (; i < max(n1.v_size, n2.v_size); i++){
		sum = n1.numData[i] + n2.numData[i] + carry;
		carry = sum / 10;
		result.numData[i] = sum % 10;
	}
	result.v_size = i;
	result.check = n1.check && n2.check;
	if (carry) result.numData[result.v_size++] = carry;
	return result;
}
int main(){
	BigInt n1{ false, 0,{ 0 } }, n2{ false, 0,{ 0 } };
	//檢查有無錯誤格式
	try{
		g = true;
		Read(n1);
		Read(n2);
		if (!g) throw exception();
		BigInt n3 = Add(n1, n2);
		PrintNumber(n3);
	}
	catch (const exception& e){
		cout << ("Not a valid number, please try again.") << endl;
	}
	system("pause");
}