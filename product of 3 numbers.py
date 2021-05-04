def check(n,k):
    l=[]
    if k==int(n**0.5):
        return l
    if n<24:
        return l
    a,m,i=0,n,k
    while n>i :
        if n%i==0:
            n//=i
            a+=1
            l.append(i)
        if a==2 and n>i:
            l.append(n)
            return l
        i+=1
    return check(m,k+1)
for _ in range(int(input())):
    l=check(int(input()), 2)
    if len(l)==0:
        print("NO")
    else:
        print("YES")
        print(*l)
