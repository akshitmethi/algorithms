import pandas as pd

class flatten():
	def __init__(self,ls):
		self.adj = dict()
		for pair in test:
			if(self.adj.get(pair[0])):
				self.adj[pair[0]].append(pair[1])
			else:
				self.adj[pair[0]] = [pair[1]]

	def read_graph_util(self,s,resList):
		if(self.visited.get(s)):
			if(len(resList)>0):
				self.addParent(resList,s)
			return
		resList.append(s)
		if(not self.adj.get(s)):
			self.flattenStruct.append(resList)
			return
		self.visited[s]=1
		for node in self.adj.get(s):
			self.read_graph_util(node,resList.copy())

	def addParent(self,parent,child):
		print("parent:",parent)
		print("child: ",child)
		for ls in self.flattenStruct:
			if(ls[0]==child):
				ls = [ls.insert(0,parent[x]) for x in reversed(range(len(parent)))]

	def read_graph(self):
		self.flattenStruct=[]
		self.visited=dict()
		for node in self.adj.keys():
			resList=[]
			self.read_graph_util(node,resList)

	def getFlatten(self):
		self.read_graph()
		return self.flattenStruct

	def getT3Tuple(self):
		d = self.getFlatten()
		for i in range(len(d)):
			lastval = d[i].pop()
			d[i].insert(0,lastval)
		return d

	def getDF(self):
		resultSet = self.getFlatten()
		maxLength = 0
		for arr in resultSet:
			l = len(arr)
			if(l>maxLength):
				maxLength=l
		return pd.DataFrame(resultSet,columns=["job"+str(i) for i in range(maxLength)])



obj = flatten(<input df>.as_matrix())
resultDF = obj.getDF()
