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
    public ListNode insertGreatestCommonDivisors(ListNode head) {
        ListNode current = head;
        while(head!=null && head.next!=null)
        {
            int a = head.val;
            int b = head.next.val;

            int res = gcd(a,b);

            ListNode nn = new ListNode(res);

            nn.next = head.next;
            head.next = nn;
            head = head.next.next;
        }
        return current;
    }

    public static int gcd(int val1 , int val2)
    {
        int result = Math.min(val1,val2);

        while(val1 %result!=0 || val2%result!=0)
        {
            result--;
        }
        return result;
    }
}