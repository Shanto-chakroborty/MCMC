#include<iostream>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<fstream>
using namespace std;

int main()
	{
		double x,dx, back_x, initial ,final, metro, step= 1;
		int n, nacc=0,k ;
		
		srand(time(NULL));
		x=0;
	    ofstream file("mcmc.dat");
	
	for(n=100;n<=1000000;n=n+100)
	{	
	double sum=0,sum2=0;
		for (k=0;k<n;k++)
			{
				back_x=x;
				
				initial= 0.5*x*x;
				
				dx= (double) rand()/RAND_MAX;
				dx= (dx-0.5)*step;
			    x= x+dx;		    
			    final= 0.5*x*x;
			    
			    metro=  (double) rand()/RAND_MAX;
			    if(exp(initial-final)> metro)
			       nacc++;
			       
			     else 
			        x= back_x;
				
				sum+= x;
				sum2+= x*x;
			
			}
		file<<n<<"   "<<sum/n<<"    "<<sum2/n<<endl;	
	}	
		return 0;
	}
	
	
	
	
	
	