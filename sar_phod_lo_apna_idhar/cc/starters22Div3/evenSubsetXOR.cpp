#include <iostream>
using namespace std;

int* decToBinary(int n)
{
    // array to store binary number
    int binaryNum[20];

    // counter for binary array
    int i = 0;
    while (n > 0) {

        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    
    int *bin = new int[i];
    
    for(int j = 0; j < i; j++)
    {
        bin[j] = binaryNum[j];
    }
    
    return bin;
}

void dowithone(int &n)
{
    int *bin = decToBinary(n);
    int size = ceil(log2(n));
    bool z = false;
    int ones = 0;
    
    for(int i = 1; i < size; i++)
    {
        if(bin[i] == 0)
        {
            z = true;
        }
        else
        {
            ones++;
        }
    }

    if(z)
    {
        if(ones%2 == 0)
        {
            n = n+1;
            cout << n << " ";
            return;
        }
    }

    
    n = n+2;
    cout << n << " ";
    return;
}

int main() {
	// your code goes here
	int t = 0;
	cin >> t;
	int n = 0;
	
	
	while(t--)
	{
	    cin >> n;
	    
	    int num = 3;
	    cout << num << " ";
	    
	    int count = 1;
	    
	    while(count < n)
	    {
	        int *bin = decToBinary(num);
	        if(bin[0] == 1)
	        {
	            dowithone(num);
	        }
	        else
	        {
	            num = num+1;
	            dowithone(num);
	        }
	        
	        count++;
	    }
	    
	    
	}
	
	return 0;
}
