#include<iostream>
#include<cmath>
using namespace std;

const double Pi=3.14159;

double dientich(double R) {
    return Pi*pow(R,2);
}

double dientich(double dai, double rong) {
    return dai*rong;
}

double dientich(double a, double b, double c) {
    double q=(a+b+c)/2;
    return sqrt(q*(q-a)*(q-b)*(q-c));
}

int main()
{
    int chon;
    double R,dai,rong,a,b,c;
    cout<<"MENU"<<endl;
    cout<<"1.Tinh dien tich hinh tron"<<endl;
    cout<<"2.Tinh dien tich hinh chu nhat"<<endl;
    cout<<"3.Tinh dien tich hinh tam giac"<<endl;
    cout<<"4. Thoat"<<endl;
    cout<<"Lua chon cua ban: ";
    cin>>chon;

    switch(chon)
    {
        case 1:
        cout<<"Nhap do dai R: ";
        cin>>R;
        cout<<"Dien tich hinh tron co ban kinh R la: "<<dientich(R)<<endl;
        break;

        case 2:
        cout<<"Nhap do dai cac canh hcn: ";
        cin>>dai>>rong;
        cout<<"Dien tich hinh chu nhat la: "<<dientich(dai,rong)<<endl;
        break;

        case 3:
        cout<<"Nhap do dai cac canh tam giac: ";
        cin>>a>>b>>c;
        if(a+b<=c || a+c<=b || b+c<=a) cout<<"Tam giac khong hop le!";
        else cout<<"Dien tich hinh tam giac la: "<<dientich(a,b,c)<<endl;
        break;

        case 4: break;
        
        default:
        cout<<"Khong hop le!"<<endl;
        break;
    }
}