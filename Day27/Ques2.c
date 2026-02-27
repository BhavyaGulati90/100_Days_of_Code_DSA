// Remove loop in Linked List

class Solution
{

    public void removeLoop(Node head)
    {
        if (head == null || head.next == null)
            return;

        Node slow = head;
        Node fast = head;

        bool loopExists = false;

        while (fast != null && fast.next != null)
        {
            slow = slow.next;
            fast = fast.next.next;

            if (slow == fast)
            {
                loopExists = true;
                break;
            }
        }

        if (!loopExists)
            return;

        slow = head;

        if (slow == fast)
        {
            while (fast.next != slow)
                fast = fast.next;
        }
        else
        {

            while (slow.next != fast.next)
            {
                slow = slow.next;
                fast = fast.next;
            }
        }

        fast.next = null;
    }
}