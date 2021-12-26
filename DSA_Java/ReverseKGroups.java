/*
Question asked in Apple interview
Reverse K groups in a linkedList

1->2->3->4->5->6->7->8
if k=3 (3 groups)

output:
3->2->1->6->5->4->8->7

*/

import java.util.List;
import java.util.Arrays;

public class ReverseKGroups {
	
	public Node reverseList(Node head, boolean returnHead){
		Node curr = head;
		Node prev = null;
		Node next = curr.next;
		while(curr.next != null){
			curr.next = prev;
			prev= curr;
			curr = next;
			next = curr.next;
		}
		curr.next = prev;
		if(returnHead)
			return curr;
		return head;
	}

	public Node reversegroup(Node head, int k){
		int i=1;
		Node nextHead = null;
		Node currHead = head;
		Node curr = currHead;
		Node prev = null;
		while(curr != null){
			curr = curr.next;
			i++;
			if(i%k == 0 || curr.next == null){
				Node next = curr.next;
				curr.next = null;
				currHead = reverseList(currHead,true);
				if(prev == null){
					head = currHead;
				} else
					prev.next = currHead;
				Node tempCurr = currHead;
				while(tempCurr.next != null){
					tempCurr = tempCurr.next;
				}
				prev = tempCurr;
				curr = next;
				currHead = curr;
				i=1;
			}
		}
		return head;
	}

	public Node createList(List<Integer> values){
		if(values.size() ==0 )
			return null;
		Node head = new Node(values.get(0));
		Node curr = head;
		for(int i=1; i<values.size(); i++){
			curr.next = new Node(values.get(i));
			curr = curr.next;
		}
		return head;
	}

	public void printList(Node head){
		Node curr = head;
		while(curr != null){
			System.out.print(String.format("->%d",curr.val));
			curr = curr.next;
		}
		System.out.println(" ");
	}

	public static void main(String[] args) {
		ReverseKGroups rkg = new ReverseKGroups();
		Node head = rkg.createList(Arrays.asList(1,2,3,4,5,6,7,8,9,10,11,12));
		rkg.printList(rkg.reversegroup(head,5));
	}
}

class Node{
	public int val;
	public Node next;
	public Node(int val){
		this.val = val;
	}
}