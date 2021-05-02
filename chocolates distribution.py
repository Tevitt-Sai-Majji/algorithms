#cholocate packets with no of chotolaltes
arr=[7,3,2,4,9,12,56]
#number of students
m=3
#to print min diff of max chocolates and min chocolates 
arr.sort()
i=j=0
mini=99999
while j<len(arr)-1:
    if j-i==m-1:
        mini=min(arr[j]-arr[i],mini)
        j+=1
    elif j-i>m-1:
        i+=1
    elif j-i<m-1:
        j+=1
print(mini)
