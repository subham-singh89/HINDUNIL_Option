#include<iostream>
#include<cmath>
using namespace std;
float calculateSD(float data[],int n);
int main()
{
	int n;
  cin>>n;
  float volatility;
  float data[n];

  
  for(int i = 0; i < n; ++i) {
    cin >> data[i];
  }

  volatility= calculateSD(data,n);
  cout<<volatility<<endl;
  float hedge_ratio,delta,unders,underl,options,optionl;
	cout<<"Enter the starting underlying price:"<<endl;
	cin>>unders;
	cout<<"Enter the last underlying price:"<<endl;
	cin>>underl;
	cout<<"Enter the last option price:"<<endl;
	cin>>options;
	cout<<"Enter the last option price:"<<endl;
	cin>>optionl;
	delta=(options-optionl)/(unders-underl);
	hedge_ratio=delta*100;
	cout<<"Hedge ratio is:"<<hedge_ratio<<endl;
	if(hedge_ratio>0)
	{
		cout<<"Positive hedge"<<endl;
	}
	else if(hedge_ratio==0)
	{
		cout<<"Neutral hedge"<<endl;
	}
	float f_p,e_p=2700,i_r=8.50,Div=39;
	float t=18/365;
	f_p=(e_p*(1+(i_r*t)))-Div;
	cout<<"Forward price is:"<<f_p<<endl;
		float check1,check2;
	check1=e_p-volatility;
		check2=e_p+volatility;
	if(f_p>check1 && f_p<check2)
	{
		
			if(f_p<e_p)
			{
				cout<<"Put option and hedge by buying "<<hedge_ratio<<" percentage of call on underlying"<<endl;
			}
			else if(f_p>e_p)
			{
				cout<<"call option and hedge by buying "<<hedge_ratio<<" percentage of put on underlying"<<endl;
			}

	}
	else
	{
		cout<<"There is less than 33 percent chance of this option ending in money"<<endl;
	}
	return 0;
	
}
float calculateSD(float data[],int n) {
  float sum = 0.0, mean, standardDeviation = 0.0;
  int i;

  for(i = 0; i < n; ++i) {
    sum += data[i];
  }

  mean = sum / n;

  for(i = 0; i < n; ++i) {
    standardDeviation += pow(data[i] - mean, 2);
  }

  return sqrt(standardDeviation / n);
}
