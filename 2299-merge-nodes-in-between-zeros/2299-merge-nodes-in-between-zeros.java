/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeNodes(ListNode head) {
        ListNode dummynode = new ListNode();
        int sum = 0;
        ListNode currtail = dummynode;
        ListNode currnode = head.next; // Skip the first 0 node
        while (currnode != null) {
            if (currnode.val != 0) {
                sum += currnode.val;
            } else {
                currtail.next = new ListNode(sum); // Assign to next
                currtail = currtail.next; // Move currtail forward
                sum = 0; // Reset sum
            }
            currnode = currnode.next;
        }
        return dummynode.next;
    }
}
