#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class zipcode{
    public:
    zipcode(int zip);
    zipcode(string zip);
    int getint(){return Code;}
    string getstring();
    int Code;
    private:
    int Decode(string zip);
    string Encode();
};

zipcode::zipcode(int zip) {
    Code=zip;
}

zipcode::zipcode(string zip) {
    Code=Decode(zip);
}

string zipcode::getstring() {
    return Encode();
}

int zipcode::Decode(string zip){
    string s1=zip.substr(0,5);
    string s2=zip.substr(5,5);
    string s3=zip.substr(10,5);
    string s4=zip.substr(15,5);
    string s5=zip.substr(20,5);
    int n1(0),n2(0),n3(0),n4(0),n5(0);
    if(s1.at(0)=='1'){
        n1+=7;
    }
    if(s1.at(1)=='1'){
        n1+=4;
    }
    if(s1.at(2)=='1'){
        n1+=2;
    }
    if(s1.at(3)=='1'){
        n1+=1;
    }
    if(s2.at(0)=='1'){
        n2+=7;
    }
    if(s2.at(1)=='1'){
        n2+=4;
    }
    if(s2.at(2)=='1'){
        n2+=2;
    }
    if(s2.at(3)=='1'){
        n2+=1;
    }
    if(s3.at(0)=='1'){
        n3+=7;
    }
    if(s3.at(1)=='1'){
        n3+=4;
    }
    if(s3.at(2)=='1'){
        n3+=2;
    }
    if(s3.at(3)=='1'){
        n3+=1;
    }
    if(s4.at(0)=='1'){
        n4+=7;
    }
    if(s4.at(1)=='1'){
        n4+=4;
    }
    if(s4.at(2)=='1'){
        n4+=2;
    }
    if(s4.at(3)=='1'){
        n4+=1;
    }
    if(s5.at(0)=='1'){
        n5+=7;
    }
    if(s5.at(1)=='1'){
        n5+=4;
    }
    if(s5.at(2)=='1'){
        n5+=2;
    }
    if(s5.at(3)=='1'){
        n5+=1;
    }
    return ((n1*10000)+(n2*1000)+(n3*100)+(n4*10)+n5);
}

string zipcode::Encode(){
    string s1,s2,s3,s4,s5,str;
    int n1,n2,n3,n4,n5;
    n1=Code/10000;
    n2=(Code%10000)/1000;
    n3=((Code%10000)%1000)/100;
    n4=(((Code%10000)%1000)%100)/10;
    n5=(((Code%10000)%1000)%100)%10;
    if(n1==0){
        s1="00000";
    }
    if(n1==1){
        s1="00010";
    }
    if(n1==2){
        s1="00100";
    }
    if(n1==3){
        s1="00110";
    }
    if(n1==4){
        s1="01000";
    }
    if(n1==5){
        s1="01010";
    }
    if(n1==6){
        s1="01100";
    }
    if(n1==7){
        s1="10000";
    }
    if(n1==8){
        s1="10010";
    }
    if(n1==9){
        s1="10100";
    }
    if(n2==0){
        s2="00000";
    }
    if(n2==1){
        s2="00010";
    }
    if(n2==2){
        s2="00100";
    }
    if(n2==3){
        s2="00110";
    }
    if(n2==4){
        s2="01000";
    }
    if(n2==5){
        s2="01010";
    }
    if(n2==6){
        s2="01100";
    }
    if(n2==7){
        s2="10000";
    }
    if(n2==8){
        s2="10010";
    }
    if(n2==9){
        s2="10100";
    }
    if(n3==0){
        s3="00000";
    }
    if(n3==1){
        s3="00010";
    }
    if(n3==2){
        s3="00100";
    }
    if(n3==3){
        s3="00110";
    }
    if(n3==4){
        s3="01000";
    }
    if(n3==5){
        s3="01010";
    }
    if(n3==6){
        s3="01100";
    }
    if(n3==7){
        s3="10000";
    }
    if(n3==8){
        s3="10010";
    }
    if(n3==9){
        s3="10100";
    }
    if(n4==0){
        s4="00000";
    }
    if(n4==1){
        s4="00010";
    }
    if(n4==2){
        s4="00100";
    }
    if(n4==3){
        s4="00110";
    }
    if(n4==4){
        s4="01000";
    }
    if(n4==5){
        s4="01010";
    }
    if(n4==6){
        s4="01100";
    }
    if(n4==7){
        s4="10000";
    }
    if(n4==8){
        s4="10010";
    }
    if(n4==9){
        s4="10100";
    }
    if(n5==0){
        s5="00000";
    }
    if(n5==1){
        s5="00010";
    }
    if(n5==2){
        s5="00100";
    }
    if(n5==3){
        s5="00110";
    }
    if(n5==4){
        s5="01000";
    }
    if(n5==5){
        s5="01010";
    }
    if(n5==6){
        s5="01100";
    }
    if(n5==7){
        s5="10000";
    }
    if(n5==8){
        s5="10010";
    }
    if(n5==9){
        s5="10100";
    }
    str=s1+s2+s3+s4+s5;
    return str;
}

int main(){
    int zip1;
    string zip2;
    //zipcode z1(94024);
    //zipcode z2("0001000100001100100001010");
    cout << "Enter integer zipcode for z1: ";
    cin >> zip1;
    cout << "Enter string zipcode for z2: ";
    cin >> zip2;

    zipcode z1(zip1);
    zipcode z2(zip2);

    cout << z1.getint() <<endl;
    cout << z1.getstring() <<endl;
    cout << z2.getint() <<endl;
    cout << z2.getstring() <<endl;


    return 0;
}