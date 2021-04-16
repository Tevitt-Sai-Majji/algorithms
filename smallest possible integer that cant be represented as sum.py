array=sorted(array)
        j=1
        for i in array:
            if i > j:
                return j
            j+=i
        return j
