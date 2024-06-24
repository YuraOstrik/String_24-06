#include <iostream>
using namespace std;

class MyString 
{
	char* str;
	int len;
public:
	MyString()
	{
		str = nullptr;
		len = 0;
	}
	MyString(const char* s)
	{
		str = new char[strlen(s) + 1];
		strcpy_s(str, strlen(s) + 1, s);

		len = strlen(str) + 1;
	}
	void Output();
	~MyString()
	{
		delete[] str;
	}

	const char* Get()
	{
		return str;
	}
	void Set(const char* s)
	{
		if (str != nullptr)
		{
			delete[] str;
		}
		str = new char[strlen(s) + 1];
		strcpy_s(str, strlen(s) + 1, s);
		len = strlen(str);
	}

	void MyStrcpy(MyString& obj)
	{
		if (str != nullptr) {
			delete[] str;
		}
		str = new char[strlen(obj.str) + 1];
		strcpy_s(str, strlen(obj.str) + 1, obj.str);
		len = strlen(str);
	}
	bool MyStrStr(const char* word) {
		if (*word == '\0') {
			return true;
		}
		for (int i = 0; str[i] != '\0'; i++) {
			if (str[i] == word[0]) {
				int j;
				for (j = 0; word[j] != '\0'; j++) {
					if (str[i + j] != word[j]) {
						break;
					}
				}
				if (word[j] == '\0') {
					return true;
				}
			}
		}
		return false;
	}
	int  MyChr(char c)
	{
		for (int i = 0; i < strlen(str); i++) {
			if (str[i] == c) {
				return i;
			}
		}
		return -1;
	}
	int MyStrLen() {
		return len;
	}
	void MyStrCat(MyString& b)
	{
		int nlen = len + b.len - 1;
		char* list = new char[nlen];

		for (int i = 0; i < len - 1; ++i) {
			list[i] = str[i];
		}

		
		for (int i = 0; i < b.len; ++i) {
			list[len - 1 + i] = b.str[i];
		}

		delete[] str;

		str = list;
		len = nlen;
		cout << str << endl;
	}
	void MyDelChr(char c)
	{
		int count = 0;
		for (int i = 0; i < len - 1; ++i) {
			if (str[i] != c) {
				++count;
			}
		}

		char* del = new char[count + 1];
		int j = 0;

		
		for (int i = 0; i < len - 1; ++i) {
			if (str[i] != c) {
				del[j++] = str[i];
			}
		}

		del[count] = '\0'; 

		cout << del;
	}
	int MyStrCmp(MyString& b)
	{
		if (strlen(str) > strlen(b.str)) {
			return 1;
		}
		else if (strlen(str) == strlen(b.str)) {
			return 0;
		}
		else {
			return -1;
		}
	}
};
void MyString::Output()
{
	cout << str << endl;
}

ostream& operator << (ostream& os, MyString& obj)
{
	os << obj.Get() << endl;
	return os;
}
istream& operator >> (istream& is, MyString& obj)
{
	char buff[80];
	cout << "Enter word -> " << endl;
	is >> buff;
	obj.Set(buff);
	return is;

}




int main()
{
	MyString A("Hello World");
	MyString B("[Goodmorning ...");
	

	/*if (A.MyStrStr("World")) {
		cout << "\nTrue" << endl;
	}
	else {
		cout << "\nFalse" << endl;
	}*/

	/*A.MyStrCat(B);*/
	/*cout << A.MyChr('o');*/
	cout << A.MyStrCmp(B);
}


