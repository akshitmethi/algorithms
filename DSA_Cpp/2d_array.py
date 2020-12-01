def printmax(arr,i,j):
	print(range(i,i+2))
	for row in range(i,i+3):
		print()
		for col in range(j,j+3):
			if(row != i+1 or (col != j and col != j+2)):
				print(arr[row][col],end= " ")
			print(" ",end=" ")


arr = list()
for i in range(6):
	arr.append(list(map(int,input().split(" "))))
print("complete array")
printmax(arr,2,2)
print(arr)

