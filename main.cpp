#include <iostream>
#include <math.h>
#include <map>
using namespace std;

map<char,int> valoresletras;
map<int,char> valores;

int base10(string x, int n){
    int num=0;
//    int i=x.length()-1;
    int j=x.length()-1;
//    cout<<x<<endl;
    for(int i=0;i<x.size();i++){
        if(isdigit(x[i])) {
            string a;
            a+=x[i];
            num += stoi(a)*pow(n,j);
//            cout<<a<<" "<<n<<" "<<j<<" elevado: "<<stoi(a)*pow(n,j)<<endl;
        }
        else {
            num += valoresletras[x[i]] * pow(n, j);
//            cout<<x[i]<<" "<<n<<" "<<j<<" elevado: "<<valoresletras[x[i]]*pow(n,j)<<endl;
        }
        j--;
    }
    return num;
}

int baseminima(string x){
    int b=2;
    for(auto i:x){
        if(isdigit(i)){
        string num;
        num+=i;
        if(stoi(num)+1>b){
            b=stoi(num)+1;
        }
        }
        else{
            if(valoresletras[i]+1>b){
                b=valoresletras[i]+1;
            }
        }
    }
    return b;
}

bool bases(string x,string y){
    int i;
    int j;
    for(i=baseminima(x);i<=36;i++){
        for(j=baseminima(y);j<=36;j++){
            if(base10(x,i)==base10(y,j)){
                cout<<x<<" (base "<< i<<") = "<<y <<" (base " <<j<<")"<<endl;
//                cout<<i<<" "<<j<<endl;
                return true;
            }

        }
    }
    cout<<x<<" is not equal to "<<y<<" in any base 2..36"<<endl;

}


int main() {
    valoresletras['A']=10;
    valoresletras['B']=11;
    valoresletras['C']=12;
    valoresletras['D']=13;
    valoresletras['E']=14;
    valoresletras['F']=15;
    valoresletras['G']=16;
    valoresletras['H']=17;
    valoresletras['I']=18;
    valoresletras['J']=19;
    valoresletras['K']=20;
    valoresletras['L']=21;
    valoresletras['M']=22;
    valoresletras['N']=23;
    valoresletras['O']=24;
    valoresletras['P']=25;
    valoresletras['Q']=26;
    valoresletras['R']=27;
    valoresletras['S']=28;
    valoresletras['T']=29;
    valoresletras['U']=30;
    valoresletras['V']=31;
    valoresletras['W']=32;
    valoresletras['X']=33;
    valoresletras['Y']=34;
    valoresletras['Z']=35;

    valores[10]='A';
    valores[11]='B';
    valores[12]='C';
    valores[13]='D';
    valores[14]='E';
    valores[15]='F';
    valores[16]='G';
    valores[17]='H';
    valores[18]='I';
    valores[19]='J';
    valores[20]='K';
    valores[21]='L';
    valores[22]='M';
    valores[23]='N';
    valores[24]='O';
    valores[25]='P';
    valores[26]='Q';
    valores[27]='R';
    valores[28]='S';
    valores[29]='T';
    valores[30]='U';
    valores[31]='V';
    valores[32]='W';
    valores[33]='X';
    valores[34]='Y';
    valores[35]='Z';

    string a,b;
    while(cin>>a>>b){
//        cout<<base10("9D",21)<<" "<<base10("312",8);
        bases(a,b);
    }

    return 0;
}