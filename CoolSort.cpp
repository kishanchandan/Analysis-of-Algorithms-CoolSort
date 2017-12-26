#include <iostream>
using namespace std;
int coolsort(int sub_array[],int n)
{
	int j,temp;
	for(int i=0;i<n;i++)
	{
		j=i;
		while(j>0 && sub_array[j]<sub_array[j-1])
		{
			temp=sub_array[j];
			sub_array[j]=sub_array[j-1];
			sub_array[j-1]=temp;
			j--;
		}
	}
}
int main() 
{
 int elements[100],n,k, i ,j ,temp,m=0,steps[15],step_counter,step_size,current_step;
 int sub_array[100]={};
 int p=0;

	cout<<"Enter the Number of Elements in the array\n";
	cin>>n;
	
	cout<<"Enter the Elements seperated by space\t";
	for (i = 0; i < n; i++)
	{
		cin>>elements[i];
	}
	cout<<"Enter the number steps";
	cin>>step_counter;
	cout<<"Enter the steps";
	for (i = 0; i < step_counter; i++)
	{
		cin>>steps[i];
	}
	while(p<step_counter)
	{
        k = 0,j=0;
        current_step=steps[p];
		for(i=0;i<=step_counter;i++)
        {
            while(k<n)
            {
                sub_array[j] = elements[k];
                k=k+current_step;
                j++;			
            }   
        }
        coolsort(sub_array,j);
	
        k = 0,j=0;
        for(i=0;i<=step_counter;i++)
        {
            while(k<n)
            {
                elements[k]=sub_array[j];
                k=k+current_step;
                j++;			
            }
        }
        p++;
        
    }
	for(i=0;i<n;i++)
        {
            cout<<"\t"<<elements[i];
        }
	
	
	return 0;
}