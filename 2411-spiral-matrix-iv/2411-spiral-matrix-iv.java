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
    public int[][] spiralMatrix(int m, int n, ListNode head) {
        // Initialize the 2D array with dimensions m x n, filled with -1
        int[][] arr = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                arr[i][j] = -1; // Fill the matrix with a default value (-1)
            }
        }

        // Define boundaries for the spiral traversal
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        ListNode current = head;

        while (top <= bottom && left <= right && current != null) {
            // Fill the top row
            for (int j = left; j <= right && current != null; j++) {
                arr[top][j] = current.val;
                current = current.next;
            }
            top++;

            // Fill the right column
            for (int i = top; i <= bottom && current != null; i++) {
                arr[i][right] = current.val;
                current = current.next;
            }
            right--;

            // Fill the bottom row
            for (int j = right; j >= left && current != null; j--) {
                arr[bottom][j] = current.val;
                current = current.next;
            }
            bottom--;

            // Fill the left column
            for (int i = bottom; i >= top && current != null; i--) {
                arr[i][left] = current.val;
                current = current.next;
            }
            left++;
        }

        return arr;
    }
}
