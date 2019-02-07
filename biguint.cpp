#include "biguint.h"


biguint::biguint(){
    for (int i = 0; i < CAPACITY; i++){
        data_[i] = 0;
    }
}

biguint::biguint(const std::string & temp){
    int j = temp.length()-1;
    for (int i = 0; i < temp.length(); i++){
        if (temp[j]=='0')
            data_[i]= 0;
        else if (temp[j]=='1')
            data_[i]= 1;
        else if (temp[j]=='2')
            data_[i]= 2;
        else if (temp[j]=='3')
            data_[i]= 3;
        else if (temp[j]=='4')
            data_[i]= 4;
        else if (temp[j]=='5')
            data_[i]= 5;
        else if (temp[j]=='6')
            data_[i]= 6;
        else if (temp[j]=='7')
            data_[i]= 7;
        else if (temp[j]=='8')
            data_[i]= 8;
        else if (temp[j]=='9')
            data_[i]= 9;
        else
            assert(temp[j]>='0' && temp[j]<='9');
        j--;
    }
    if (i <= 19){
        for (i; i<=19; i++){
            data_[i] = 0;
        }
    }
}

unsigned short operator [](std::size_t pos) const{
    assert((pos<CAPACITY) && (pos>=0));
    return data_[pos];
}

int biguint::compare(const biguint & b) const{
    for (int i = CAPACITY-1; i >= 0; i--){
        if (data_[i] > b.data_[i]){
            return 1;
        } else if (data_[i] < b.data_[i]){
            return -1;
        } else if (i = 0){
            return 0;
        }
    }
}

bool operator < (const biguint &a, const biguint &b){
    if (a.compare(b) == -1)
        return true;
    else
        return false;
}

bool operator <= (const biguint &a, const biguint &b){
    if (a.compare(b) == -1 || a.compare(b) == 0)
        return true;
    else
        return false;
}

bool operator != (const biguint &a, const biguint &b){
    if (a.compare(b) == 1 || a.compare(b) == -1)
        return true;
    else
        return false;
}

bool operator == (const biguint &a, const biguint &b){
    if (a.compare(b) == 0)
        return true;
    else
        return false;
}

bool operator >= (const biguint &a, const biguint &b){
    if (a.compare(b) == 1 || a.compare(b) == 0)
        return true;
    else
        return false;
}

bool operator > (const biguint &a, const biguint &b){
    if (a.compare(b) == 1)
        return true;
    else
        return false;
}

ostream& operator <<(ostream& out, const biguint& a){
    for (int i = a.CAPACITY-1; i >= 0 ; i--)
        out << a.data_[i];
    out << endl;
    return out;
}

void operator += (const biguint& b){
    unsigned short carry(0),k(10),inc;
    for (int i=0; i<=19; i++){
        inc=carry;
        carry=0;
        if((data_[i]+b.data_[i]+inc)>10){
            data_[i]=((data_[i]+b.data_[i])-k)+inc;
            carry = 1;
        }
        else{
            data_[i]=(data_[i]+b.data_[i])+inc;
        }
    }
}

biguint operator + (const biguint &a, const biguint &b){
    biguint sum;
    unsigned short carry(0),k(10),inc;
    for (int i=0; i<=19; i++){
        inc=carry;
        carry=0;
        if((a.data_[i]+b.data_[i]+inc)>10){
            sum.data_[i]=((a.data_[i]+b.data_[i])-k)+inc;
            carry = 1;
        }
        else{
            sum.data_[i]=(a.data_[i]+b.data_[i])+inc;
        }
    }
    return sum;
}

