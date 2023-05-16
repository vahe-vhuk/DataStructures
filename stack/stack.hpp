#ifndef __T_STACK_HPP__
#define __T_STACK_HPP__

#include "../vector/vector.hpp"

namespace vhuk {

template <typename T, typename Sequence = vhuk::Vector<T> >
class Stack : private Sequence
{
    template <typename T2, typename Sequence2>
    friend bool operator==(const Stack<T2, Sequence2>& lhv, const Stack<T2, Sequence2>& rhv);
    template <typename T2, typename Sequence2>
    friend bool operator<(const Stack<T2, Sequence2>& lhv, const Stack<T2, Sequence2>& rhv);
    template <typename T2, typename Sequence2>
    friend bool operator>(const Stack<T2, Sequence2>& lhv, const Stack<T2, Sequence2>& rhv);
    template <typename T2, typename Sequence2>
    friend bool operator<=(const Stack<T2, Sequence2>& lhv, const Stack<T2, Sequence2>& rhv);
    template <typename T2, typename Sequence2>
    friend bool operator>=(const Stack<T2, Sequence2>& lhv, const Stack<T2, Sequence2>& rhv);

public:
    typedef typename Sequence::value_type value_type;
    typedef typename Sequence::size_type size_type;

public:
    Stack();
    Stack(const Stack& rhv);
    Stack& operator=(const Stack& rhv);
    bool empty() const;
    size_type size() const;
    value_type& top();
    const value_type& top() const;
    void push(const value_type& d);
    void pop();
};

}

#include "stack.cpp"

#endif /// __T_STACK_HPP__

