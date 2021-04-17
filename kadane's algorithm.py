a=[1,2,3,-1,5]
size=5
maxi=0
s=0
for i in range(1,size):
    if a[i]+a[i-1]>a[i]:
        a[i]+=a[i-1]
    maxi=max(maxi,a[i])
print(maxi)
#returns max sum subarray 
