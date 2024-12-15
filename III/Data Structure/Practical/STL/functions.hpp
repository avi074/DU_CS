#ifndef __functions__
#define __functions__

#include <bits/functexcept.h>

namespace stl
{
    template <class II, class OI>
    void copy(II start, II end, OI res)
    {
        while (start != end)
        {
            res->push_back(*start);
            start++;
        }
    }

    template <typename T>
    constexpr void chkEmpty(T *o)
    {
        if (o->empty())
            std::__throw_underflow_error("ADT is Empty !!!");
    }

    template <typename T>
    constexpr void chkFull(T *o)
    {
        if (o->full())
            std::__throw_overflow_error("ADT is Full !!!");
    }

} // namespace stl
#endif