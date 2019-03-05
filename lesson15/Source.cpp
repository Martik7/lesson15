#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string.h>
#include <clocale>
#include <sstream>
#include <string>
using namespace std;

int myStr_cmp(const char* s1, const char* s2)
{
	int k1 = strlen(s1);
	int k2 = strlen(s2);
	int n = k1 < k2 ? k1 : k2;

	for (size_t i = 0; i <= n; i++)
	{
		if (s1[i] > s2[i])
		{
			return 1;
		}
		else if (s1[i] < s2[i])
		{
			return -1;
		}
	}
	return 0;
}

char *my_strcpy(char *s1, const char *s2) {
	if ((*s1 = *s2) != '\0') {
		return my_strcpy(s1 + 1, s2 + 1);
	}
	else {
		return s1;
	}
}

char *myStr_Cpy(char *s1, const char *s2)
{
	char *t_ptr = s1;
	while (*s2 != '\0')
	{
		*t_ptr++ = *s2++;
	}
	*t_ptr = '\0';
	return s1;
}

char *my_strcat(char *s1, const char *s2, bool _copy_phase = false) {
	if (_copy_phase) {
		if ((*s1 = *s2) != '\0') {
			my_strcat(s1 + 1, s2 + 1, true);
		}
	}
	else {
		my_strcat(s1 + 1, s2, *(s1 + 1) == '\0');
	}
	return s1;
}

int parser(char* str1)
{
	int s = 0;
	int k = 1;

	if (!isdigit(str1[0]) || isdigit(str1[strlen(str1) - 1]))
		cout << "Wrong expression" << endl;
	else
	{
		for (size_t i = 0; i < strlen(str1); i++)
		{
			if (str1[i] != '+' && str1[i] != '-')
				s += k * (str1[i] - 48);
			else if (str1[i] == '+')
				k = 1;
			else if (str1[i] == '-')
				k = -1;
		}
	}
	return s;
}


template<typename T>
string ToString(const T& v)
{
	ostringstream ss;
	ss << v;
	return ss.str();
}

template<typename T>
T FromString(const string& str)
{
	istringstream ss(str);
	T ret;
	ss >> ret;
	return ret;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	
	/*char str1[50] = "This is example for example";
	char str2[50] = "example";

	char *p1 = str1;
	int k = 0;

	while (p1 = strstr(p1, str2))
	{
		p1 = p1 + strlen(str2);
		k++;
	}
	cout << k << endl;*/

	/*cout << myStr_cmp(str1, str2) << endl;
	cout << my_strcpy(str1, str2);
	cout << str << endl;
	cout << myStr_Cpy(str1, str2) << endl;
	cout << my_strcat(str1, str2) << endl;*/

	char str1[50] = "2+5-9+7";
	cout << parser(str1) << endl;

	/*char s[50] = "2+5-4";
	int i = FromString<int>(s);
	std::string str = ToString(i);
	cout << ToString(i) << endl;
	cout << FromString<int>(s) << endl;*/


	system("pause");
	return 0;
}