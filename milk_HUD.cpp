#include <iostream>
#include <string>
using namespace std;

string brand[101]={};
int price[101]={0};
double avePrice[101] ={0};
int volume[101]={0};
int day[101] ={0};

int main()
{
    int T;
    cin>>T;
    
    for(int i = 1; i<= T; i++)
    {
        int maxVolume =0;    //��¼ѡ��ţ�̵����� 
        string theBrand;       //��¼ѡ�е�ţ�̵�Ʒ�� 
        double minAvePrice= 100000;    //��¼ѡ��ţ�̵ļ۸� 
        
        int numberOfBrand;        //Ҫ�����ţ��Ʒ�Ƶ����� 
        cin >> numberOfBrand;
        
        for(int j =1; j<= numberOfBrand; j++)
        {
            cin >> brand[j] >> price[j] >> volume[j];
            day[j] = volume[j]/200;
            
            if( day[j] <=5 && day[j] >= 1)
                avePrice[j] = static_cast<double>( price[j]) / (day[j] );
            else if(day[j]>5)
                avePrice[j] = static_cast<double>(price[j]) /5;
            else
                avePrice[j] = 10000;
        }
        
        for(int j =1; j<= numberOfBrand; j++)
        {
            if( avePrice[j] < minAvePrice && day[j] >=1)
            {
                minAvePrice = avePrice[j];

                theBrand = brand[j];
                maxVolume = volume[j];
            }

            else if( avePrice[j] == minAvePrice && volume[j] > maxVolume && day[j] >=1)
            {
                minAvePrice = avePrice[j];

                theBrand = brand[j];
                maxVolume = volume[j];
            }
        }
        
        cout<< theBrand<<endl;

    }

}
