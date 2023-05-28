#ifndef MYSTRING_HPP
#define MYSTRING_HPP

#include <iostream>
#include <string>

namespace vhuk {

class myString
{
private:
	char* m_buff;
	size_t m_capacity;
	size_t m_size;
public:
	myString();
	myString(const myString&);
	myString(const char*);
	myString(const std::string&);
	~myString();

	myString(myString&&);

	myString& operator=(const myString&);
	myString& operator=(const char*);
	myString& operator=(const std::string&);

	myString& operator=(myString&&);

	myString operator+(const myString&);
	myString operator+(const char*);
	myString operator+(const std::string&);

	myString& operator+=(const myString&);
	myString& operator+=(const char*);
	myString& operator+=(const std::string&);

	size_t size();

	char& operator[](size_t);

	char* begin();
	char* end();

	
};

myString operator+(const char*, const myString&);
myString operator+(const std::string&, const myString&);

std::ostream& operator<<(std::ostream&, const myString&);
}

#include "mystring.cpp"


#endif
