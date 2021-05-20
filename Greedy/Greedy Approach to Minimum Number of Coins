
def findMin(V):
    deno = [1, 2, 5, 10, 20, 50,
            100, 500, 1000]
    n = len(deno)
    count=0
    
    for i in range(n-1,-1,-1):
        while (V >= deno[i]):
            V -= deno[i]
            count+=1

    print(count)    
 
if __name__ == '__main__':
    n = 70
    findMin(n)
