class node:
	def __init__(self,data):
		self.data = data
		self.next = None

a = [1,2,3,4,5]
curr = node(a[0])
head = curr
for i in range(1,len(a)):
	curr.next = node(a[i])
	curr = curr.next

# 5     -> 6 -> None
# 		curr



curr = head
while(curr != None):
	print(curr.data,end='->')
	curr = curr.next

