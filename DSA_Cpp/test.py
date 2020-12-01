class Node:
    def __init__(self,val):
        self.data = val
        self.right = None
        self.left = None
        self.nextRight= None

def connect(root):
    '''
    :param root: root of the given tree
    :return: none, just connect accordingly.
    {
        # Node Class:
        class Node:
            def __init__(self,val):
                self.data = val
                self.left = None
                self.right = None
                self.nextRight = None
    }
    '''
    queue = []
    queue.append((root,0))
    prev_level =-1
    prev_node = root
    while(queue[0][0]):
        curr,level = queue.pop(0)
        print("nodes : ",curr.data,prev_node.data)
        print("level : ",prev_level,level)
        if(prev_level == level):
            prev_node.nextRight = curr
        prev_node = curr
        prev_level = level
        for child in [curr.left,curr.right]:
            queue.append((child,level+1))


################Main Code#####################
if (__name__ == "__main__"):
    root = Node(3)
    root.left = Node(1)
    root.left.left = Node(4)
    root.left.right = Node(5)
    root.right = Node(2)
    connect(root)
    print(root.left.left.nextRight.data)