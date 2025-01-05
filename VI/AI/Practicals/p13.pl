/*
length of list is even or odd.

evenlength(?List) -> true when List has even no. of elements.
oddlength(?List) -> true when List has odd no. of elements.
*/
evenlength(List) :- 
    length(List, L),
    Z is mod(L,2),
    Z =:= 0.
    
oddlength(List) :- 
    length(List, L),
    Z is mod(L,2),
    Z =:= 1.