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
		resList.append(s)
		if(not self.adj.get(s)):
			self.flattenStruct.append(resList)
			return
		for node in self.adj.get(s):
			self.read_graph_util(node,resList.copy())

	def read_graph(self):
		self.flattenStruct=[]
		for node in self.adj.keys():
			resList=[]
			self.read_graph_util(node,resList.copy())

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
		resultSet = self.getT3Tuple()
		maxLength = 0
		for arr in resultSet:
			l = len(arr)
			if(l>maxLength):
				maxLength=l
		return pd.DataFrame(resultSet,columns=["T3 Job"]+["job"+str(i) for i in range(maxLength-1)])



obj = flatten(<input df>.as_matrix())
resultDF = obj.getDF()
