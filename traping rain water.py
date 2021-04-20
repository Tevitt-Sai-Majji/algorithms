def trappingWater(self, arr,n):
        trap=0
        maxi=0
        left=[]
        for i in range(n):
            maxi=max(maxi,arr[i])
            left.append(maxi)
        maxi=0
        for i in range(n-1,-1,-1):
            maxi=max(maxi,arr[i])
            left[i]=min(left[i],maxi)
        for i in range(1,n-1):
            trap+=left[i]-arr[i]
        return trap
