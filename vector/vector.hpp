#ifndef __T_VECTOR_HPP__
#define __T_VECTOR_HPP__

#include <iostream>

namespace vhuk {

template <typename T> class Vector;

template <typename T>
std::istream& operator>>(std::istream& in, Vector<T>& v);

template <typename T>
std::ostream& operator<<(std::ostream& out, const Vector<T>& v);

template <typename T>
class Vector
{
public:
    typedef T value_type;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef value_type* pointer;
    typedef std::ptrdiff_t difference_type;
    typedef std::size_t size_type;

public:
    class const_iterator {
        friend Vector<value_type>;
    public:
        const_iterator();
        const_iterator(const const_iterator& rhv);
        ~const_iterator();
        const const_iterator& operator=(const const_iterator& rhv);
        const value_type& operator*() const;
        const value_type* operator->() const;
        
        const const_iterator& operator++();
        const const_iterator operator++(value_type);
        const const_iterator& operator--();
        const const_iterator operator--(value_type);
        const const_iterator operator+=(const size_type i);
        const const_iterator operator-=(const size_type i);
        const const_iterator operator+(const size_type i) const;
        const const_iterator operator-(const size_type i) const;
        const_reference operator[](const size_type size) const;
        bool operator==(const const_iterator& rhv) const;
        bool operator!=(const const_iterator& rhv) const;
        bool operator<(const const_iterator& rhv) const;
        bool operator<=(const const_iterator& rhv) const;
        bool operator>(const const_iterator& rhv) const;
        bool operator>=(const const_iterator& rhv) const;
    protected:
        explicit const_iterator(pointer ptr);
    private:
        pointer ptr_;
    };

public:
    class iterator : public const_iterator {
        friend Vector<value_type>;
    public:
        iterator();
        iterator(const iterator& rhv);
        ~iterator();
        value_type& operator*();
        value_type* operator->();
        reference operator[](const size_type size);
    protected:
        explicit iterator(pointer ptr);
    };

public:
    class const_reverse_iterator {
        friend Vector<value_type>;
    public:
        const_reverse_iterator();
        const_reverse_iterator(const const_reverse_iterator& rhv);
        ~const_reverse_iterator();
        const const_reverse_iterator& operator=(const const_reverse_iterator& rhv);
        const value_type& operator*() const;
        const value_type* operator->() const;
        
        const const_reverse_iterator& operator++();
        const const_reverse_iterator operator++(value_type);
        const const_reverse_iterator& operator--();
        const const_reverse_iterator operator--(value_type);
        const const_reverse_iterator operator+=(const size_type i);
        const const_reverse_iterator operator-=(const size_type i);
        const const_reverse_iterator operator+(const size_type i) const;
        const const_reverse_iterator operator-(const size_type i) const;
        const_reference operator[](const size_type size) const;
        bool operator==(const const_reverse_iterator& rhv) const;
        bool operator!=(const const_reverse_iterator& rhv) const;
        bool operator<(const const_reverse_iterator& rhv) const;
        bool operator<=(const const_reverse_iterator& rhv) const;
        bool operator>(const const_reverse_iterator& rhv) const;
        bool operator>=(const const_reverse_iterator& rhv) const;
    protected:
        explicit const_reverse_iterator(pointer ptr);
    private:
        pointer ptr_;
    };
public:
    class reverse_iterator : public const_reverse_iterator {
        friend Vector<value_type>;
    public:
        reverse_iterator();
        reverse_iterator(const reverse_iterator& rhv);
        ~reverse_iterator();
        value_type& operator*();
        value_type* operator->();
        reference operator[](const size_type size);
    protected:
        explicit reverse_iterator(pointer ptr);
    };

public:
    Vector();
    Vector(const size_type size);
    Vector(const int size, const_reference init);
    Vector(const Vector<value_type>& rhv);
    template <typename InputIterator> Vector(InputIterator f, InputIterator l);
    ~Vector();
    
    void set(const size_type index, const_reference value);
    const_reference get(const size_type index) const;

    size_type size() const;
    size_type max_size() const;
    bool empty() const;
    void resize(const size_type size, const_reference init = value_type());
    void clear();
    size_type capacity() const;
    void reserve(const size_type size);

    void push_back(const_reference element);
    void pop_back();
    const_reference front() const;
    reference front();
    const_reference back() const;
    reference back();

    const Vector<value_type>& operator=(const Vector<value_type>& rhv);
    reference operator[](const size_type index);
    const_reference operator[](const size_type index) const;
    bool operator==(const Vector<value_type>& rhv) const;
    bool operator!=(const Vector<value_type>& rhv) const;
    bool operator<(const Vector<value_type>& rhv) const;
    bool operator<=(const Vector<value_type>& rhv) const;
    bool operator>(const Vector<value_type>& rhv) const;
    bool operator>=(const Vector<value_type>& rhv) const;

    const_iterator begin() const;
    iterator begin();
    const_iterator end() const;
    iterator end();
    const_reverse_iterator rbegin() const;
    reverse_iterator rbegin();
    const_reverse_iterator rend() const;
    reverse_iterator rend();

public:
    //iterator insert(iterator pos, const value_type& x);
    iterator insert(iterator pos, const T& x);
    void insert(iterator pos, const int n, const T& x);
    template <typename InputIterator>
    void insert(iterator pos, InputIterator f, InputIterator l);
    
    iterator erase(iterator pos);
    iterator erase(iterator f, iterator l);

private:
    pointer begin_;
    pointer end_;
    pointer bufferEnd_;
};

}

#include "vector.cpp"
#endif /// __T_VECTOR_HPP__

