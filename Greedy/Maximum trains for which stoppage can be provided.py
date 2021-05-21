def maxStops(arr,n,m):
    arr.sort(key=lambda i:i[1])
    v=[-1]*(n+1)
    count=0
    for i in range(m):
        if v[arr[i][2]]==-1:
            count+=1
            v[arr[i][2]]=arr[i]
        else:

            if v[arr[i][2]][1]<=arr[i][0]:
                v[arr[i][2]]=arr[i]
                count+=1
    print(count)

n=3 #number of platforms
m=6 #number of trains
arr=[[1000, 1030, 1],
 [1010, 1030, 1],
 [1000, 1020, 2],
 [1030, 1200, 2],
 [1200, 1230, 3],
 [900,1005,1]]

#second test case
# n=2
# m=5
# arr=[[1000,1030,1],
#      [1010,1020,1],
#      [1025,1040,1],
#      [1130,1145,2],
#      [1130,1140,2]]

maxStops(arr,n,m)
