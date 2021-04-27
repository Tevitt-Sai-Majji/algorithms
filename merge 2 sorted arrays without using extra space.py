def merge(self,A,B,n,m):
        i = n-1
        j = 0
        while(i>=0 and j <m):
            if A[i]> B[j]:
                A[i],B[j] = B[j],A[i]
                i-=1
                j+=1
                print(A)
                print(B)
            else:
                break
        A.sort()
        B.sort()
  
