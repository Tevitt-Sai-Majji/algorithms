a=[2,3,1,2,4,2]
stack=[]
l=[]
top=-1
for i in range(len(a)-1,-1,-1):
    if top==-1:
        l.append(a[i])
        stack.append(a[i])
        top+=1
    else:
        while True:
            print(stack)
            if top>-1:
                p=stack.pop()
                top-=1
                if a[i]>=p:
                    l.append(a[i]-p)
                    stack.append(p)
                    stack.append(a[i])
                    top+=2
                    break
            else:
                l.append(a[i])
                stack.append(a[i])
                top+=1
                break
print(stack)
print(l[::-1])
print(a)
