#ifndef _cards_h
#define _cards_h


#endif

#include <cassert>
#include <cmath>
#include <algorithm>


class card{
    private:
    unsigned n;

    public:
    //Constructors
    card(){
        n=0;
    }
    
    card(const unsigned& p){
        assert(p < 52);
        n=p;
    }
    
    //Accessors
    const unsigned& id() const {
        return n;
    }
    
    const unsigned suit() const {
        return floor(n/13.);
    }
    
    const unsigned val() const {
        return n%13;
    }
    
    //Mutator
    unsigned& id() {
        return n;
    }
    
    //Printing Operator
    friend std::ostream& operator<<(std::ostream& __lhs, const card& __rhs) {
        __lhs << __rhs.val()+1;
        
        if(__rhs.suit() == 0)
        __lhs << "S";
        else if(__rhs.suit() == 1)
        __lhs << "H";
        else if(__rhs.suit() == 2)
        __lhs << "D";
        else if(__rhs.suit() == 3)
        __lhs << "C";
        
        return __lhs;
    }
};

///Static Deck - Draw With Replacement
class sdeck{
    private:
    card D[52];
    
    public:
    //Constructors
    sdeck() {
        for(unsigned i=0; i<52; ++i){
            card temp(i);
            D[i]=temp;
        }
    }
    
    //Accessor
    const card& operator[](const unsigned& i) const {
        assert(i<52);
        return D[i];
    }
    
    //Shuffle
    sdeck& shuffle() {
        std::random_shuffle(std::begin(D), std::end(D));
        return *this;
    }
    
    //Draw
    card draw() {
        card temp = D[0];
        for(unsigned i=0; i<51; ++i)
        D[i]=D[i+1];
        D[52]=temp;
        return temp;
    }
};