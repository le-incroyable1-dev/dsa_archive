/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer
 * 
 * @Output Integer
 */

 #include <limits.h>

int solve(int* A, int n1, int B) {
    int msum = INT_MIN;
    int csum;

    int l = 0;
    int r = B;


    for(l = 0; l <= B; l++)
    {
        csum = 0;
        int li = 0;
        int ri = n1-1;

        r = B - l;
        int j = 0;
        for(j = 0; j < l; j++)
        {
            csum += A[li];
            li++;    
        }

        for(j = 0; j < r; j++)
        {
            csum += A[ri];
            ri--;
        }

        if(csum >= msum)
        {
            msum = csum;
        }

    }

    return msum;
}
