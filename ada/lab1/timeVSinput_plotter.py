import time
import numpy as np
import matplotlib.pyplot as plt
import array

def bubbleSort(arr):
    n = len(arr)
 
    # Traverse through all array elements
    for i in range(n-1):
    # range(n) also work but outer loop will
    # repeat one time more than needed.
 
        # Last i elements are already in place
        for j in range(0, n-i-1):
 
            # traverse the array from 0 to n-i-1
            # Swap if the element found is greater
            # than the next element
            if arr[j] > arr[j + 1] :
                arr[j], arr[j + 1] = arr[j + 1], arr[j]


n = 5

i = 0 

xpoints = array.array('f', [0])
ypoints = array.array('f', [0])

while i < 5:

    randnums= np.random.randint(1,101,n)

    xpoints.append(n)
    
    start = time.time()
    # add function to run
    bubbleSort(randnums)
    end = time.time()

    ypoints.append(end - start)


    #xpoints.append(n)
    #start = time.time()
    # add function to run
    #mergeSort(randnums)
    #end = time.time()

    #ypoints.append(end - start)

    
    #xpoints.append(n)
    #start = time.time()
    # add function to run
    #quickSort(randnums)
    #end = time.time()

    #ypoints.append(end - start)



    print(f"Array size is {n}")

    n = n * 5
    i = i + 1
    
    print(f"Runtime of the program is {end - start}")



plt.plot(xpoints, ypoints)
plt.show()

