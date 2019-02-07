#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

class Money{
public:
    Money();
    Money(double amount);
    Money(int theDollars, int theCents);
    Money(int theDollars);
    double getAmount()const;
    int getDollars()const;
    int getCents()const;
    friend  const Money operator +(const Money& amount1, const Money& amount2);
    friend const Money operator -(const Money& amount1, const Money& amount2);
    friend bool operator ==(const Money& amount1, const Money& amount2);
    friend const Money operator -(const Money& amount);
    friend ostream& operator << (ostream& outputStream, const Money& amount);
    friend istream& operator >> (istream& inputStream, Money& amount);
    friend bool operator <(const Money& amount1, const Money& amount2);
    friend bool operator <=(const Money& amount1, const Money& amount2);
    friend bool operator >(const Money& amount1, const Money& amount2);
    friend bool operator >=(const Money& amount1, const Money& amount2);
    const Money percent(int percentFigure) const;

private:
    int dollars,cents;
    int dollarsPart(double amount)const;
    int centsPart(double amount)const;
    int round (double number)const;
};

Money::Money(int theDollars, int theCents) {
    dollars=theDollars;
    cents=theCents;
}
Money::Money(double amount){
    dollars=(dollarsPart(amount));
    cents=(centsPart(amount));
}

bool operator ==(const Money& amount1, const Money& amount2){
    return((amount1.dollars==amount2.dollars)&&(amount1.cents==amount2.cents));
}

ostream& operator << (ostream& outputStream, const Money& amount){
    int absDollars = abs(amount.dollars);
    int absCents = abs(amount.cents);
    if (amount.dollars < 0 || amount.cents < 0){
        outputStream << "$-";
    }
    else{
        outputStream << '$';
        outputStream << absDollars;
    }
    if (absCents >= 10){
        outputStream << '.' << absCents;
    }
    else{
        outputStream << '.' << '0' << absCents;
    }
    return outputStream;
}
istream& operator >> (istream& inputStream, Money& amount){
    char dollarSign;
    inputStream >> dollarSign;
    if (dollarSign != '$'){
        cout << "No dollar sign in Money input. \n";
        exit(1);
    }
    double amountAsDouble;
    inputStream >> amountAsDouble;
    amount.dollars = amount.dollarsPart(amountAsDouble);
    amount.cents = amount.centsPart(amountAsDouble);

    return inputStream;
}

int Money::dollarsPart(double amount) const {
    return static_cast<int>(amount);
}

int Money::centsPart(double amount) const {
    double doubleCents = amount * 100;
    int intCents = (round(fabs(doubleCents))) % 100;
    if (amount < 0){
        intCents = -intCents;
    }
    return intCents;
}

int Money::round(double number) const {
    return static_cast<int>(floor(number + 0.5));
}

bool operator <(const Money& amount1, const Money& amount2){
    if(amount1.dollars<amount2.dollars){
        return(amount1.dollars<amount2.dollars);
    }
    if(amount1.dollars==amount2.dollars){
        return(amount1.cents<amount2.cents);
    }
    else{
        return 0;
    }
}
bool operator <=(const Money& amount1, const Money& amount2){
    if(amount1.dollars<amount2.dollars){
        return(amount1.dollars<amount2.dollars);
    }
    if(amount1.dollars==amount2.dollars){
        return(amount1.cents<=amount2.cents);
    }
    else{
        return 0;
    }
}
bool operator >(const Money& amount1, const Money& amount2){
    if(amount1.dollars>amount2.dollars){
        return(amount1.dollars>amount2.dollars);
    }
    if(amount1.dollars==amount2.dollars){
        return(amount1.cents>amount2.cents);
    }
    else{
        return 0;
    }
}
bool operator >=(const Money& amount1, const Money& amount2){
    if(amount1.dollars>amount2.dollars){
        return(amount1.dollars>amount2.dollars);
    }
    if(amount1.dollars==amount2.dollars){
        return(amount1.cents>=amount2.cents);
    }
    else{
        return 0;
    }
}

const Money Money::percent(int percentFigure)const{
    int tempdollars=(dollars*(percentFigure/100));
    int tempcents=(cents*(percentFigure/100));
    return Money(tempdollars,tempcents);
}

int main(){
    //Money m1(50,10),m2(50,20);
    int perc,dollars1,dollars2,cents1,cents2;
    cout << "Enter dollars for m1: ";
    cin >> dollars1;
    cout << "Enter cents for m1: ";
    cin >> cents1;
    cout << "Enter dollars for m2: ";
    cin >> dollars2;
    cout << "Enter cents for m2: ";
    cin >> cents2;

    Money m1(dollars1,cents1),m2(dollars2,cents2);

    cout << "(m1<m2) is =" << (m1<m2) << endl;
    cout<< "(m1<=m2) is =" << (m1<=m2) << endl;
    cout << "(m1>m2) is =" << (m1>m2) << endl;
    cout << "(m1>=m2) is =" << (m1>=m2) << endl;

    cout << "Enter percent desired for m1: ";
    cin >> perc;
    cout << "That percent of m1 is: " << m1.percent(perc) <<endl;



    return 0;
}