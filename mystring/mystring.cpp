#ifndef MYSTRING_TPP
#define MYSTRING_TPP

#include "mystring.hpp"

namespace vhuk {

myString::myString()
	:	m_capacity{15}
	,	m_size{0}
{
	m_buff = new char[m_capacity];
}

myString::myString(const myString& rhv)
{
	m_capacity = rhv.m_capacity;
	m_size = rhv.m_size;
	m_buff = new char[m_capacity];

	for (size_t i = 0; i < m_size; ++i) {
		m_buff[i] = rhv.m_buff[i];
	}
}

myString::myString(const char* rhv)
{
	size_t len = 0;
	for (; rhv[len]; ++len);

	m_capacity = len + 5;
	m_size = len;
	m_buff = new char[m_capacity];

	for (size_t i = 0; i < len; ++i) {
		m_buff[i] = rhv[i];
	}
}

myString::myString(const std::string& rhv)
{
	m_size = rhv.size();
	m_capacity = m_size + 5;
	m_buff = new char[m_capacity];

	for (size_t i = 0; i < m_size; ++i) {
		m_buff[i] = rhv[i];
	}
}

myString::myString(myString&& rhv)
{
	m_capacity = rhv.m_capacity;
	m_size = rhv.m_size;
	m_buff = rhv.m_buff;

	rhv.m_buff = nullptr;
}

myString::~myString()
{
	delete[] m_buff;
}

myString&
myString::operator=(const myString& rhv)
{
	if (this == &rhv) {
		return *this;
	}
	delete[] m_buff;

	m_capacity = rhv.m_capacity;
	m_size = rhv.m_size;
	m_buff = new char[m_capacity];

	for (size_t i = 0; i < m_size; ++i) {
		m_buff[i] = rhv.m_buff[i];
	}
	return *this;
}

myString&
myString::operator=(const char* rhv)
{
	size_t len = 0;
	for (; rhv[len]; ++len);

	delete[] m_buff;

	m_capacity = len + 5;
	m_size = len;
	m_buff = new char[m_capacity];

	for (size_t i = 0; i < len; ++i) {
		m_buff[i] = rhv[i];
	}
	return *this;
}

myString&
myString::operator=(const std::string& rhv)
{
	delete[] m_buff;
	m_size = rhv.size();
	m_capacity = m_size + 5;
	m_buff = new char[m_capacity];

	for (size_t i = 0; i < m_size; ++i) {
		m_buff[i] = rhv[i];
	}
	return *this;
}

myString&
myString::operator=(myString&& rhv)
{
	delete[] m_buff;
	m_capacity = rhv.m_capacity;
	m_size = rhv.m_size;
	m_buff = rhv.m_buff;

	rhv.m_buff = nullptr;

	return *this;
}

myString
myString::operator+(const myString& rhv)
{
	myString tmp;
	tmp.m_size = m_size + rhv.m_size;
	tmp.m_capacity = m_capacity + rhv.m_capacity;
	tmp.m_buff = new char[tmp.m_capacity];

	size_t i = 0;
	while (i < tmp.m_size) {
		if (i < m_size) {
			tmp.m_buff[i++] = m_buff[i];
		}
		else {
			tmp.m_buff[i++] = rhv.m_buff[i - m_size];
		}
	}
	return tmp;
}

myString
myString::operator+(const char* rhv)
{
	return *this + myString(rhv);
}

myString
myString::operator+(const std::string& rhv)
{
	return *this + myString(rhv);
}

myString&
myString::operator+=(const myString& rhv)
{
	*this = *this + rhv;
	return *this;
}

myString&
myString::operator+=(const char* rhv)
{
	*this = *this + rhv;
	return *this;
}

myString&
myString::operator+=(const std::string& rhv)
{
	*this = *this + rhv;
	return *this;
}

size_t
myString::size()
{
	return m_size;
}

char&
myString::operator[](size_t ind)
{
	if (ind >= m_size) {
		throw std::invalid_argument("index out of range");
	}
	return m_buff[ind];
}

char*
myString::begin()
{
	return m_buff;
}

char*
myString::end()
{
	return m_buff + m_size;
}




myString operator+(const char* lhv, const myString& rhv)
{
	return myString(lhv) + rhv;
}

myString operator+(const std::string& lhv, const myString& rhv)
{
	return myString(lhv) + rhv;
}

std::ostream& operator<<(std::ostream& out, myString& str)
{
	for (char i : str) {
		out << i;
	}
	return out;
}



}







#endif
