a = [5,7,1] 
k = 5
swap=0
i=0
j=len(a)-1
while(i<j):
	if(a[i]<=k):
		i += 1
		continue
	else:
		if(a[j]<=k):
			t= a[i]
			a[i] = a[j]
			a[j] = t
			swap += 1
			i +=1
		j -= 1
print(swap)
print(a)