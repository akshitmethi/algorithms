a = [16,17,4,5,3,2]

def test(a):
	max= -1
	i = len(a)-1
	while(i>=0):
		t = a[i]
		a[i] = max
		if(max<t):
			max= t
		i = i-1
	return a

print(test(a))