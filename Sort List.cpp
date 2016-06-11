//Sort a linked list in O(nlogn) time using constant space complexity
/**
 * Definition for singly-linked list
 * struct ListNode 
 * {
 *	  int val;
 *    ListNode *next;
 *    ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//常数空间且O(nlogn)，单链表适用于归并排序，双向链表适用于快速排序
//归并排序，时间复杂度O(nlogn), 空间复杂度O(1)
class Solution
{
public:
	ListNode* sortList(ListNode *head)
	{
		if(head == NULL || head->next == NULL) return head;
		// 快慢指针找到中间结点
		ListNode *fast = head, *slow = head;
		while(fast->next != NULL && fast->next->next != NULL)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		// 断开
		fast = slow;
		slow = slow->next; // 进入后半段
		fast->next = NULL;

		ListNode *l1 = sortList(head);  // 前半段排序
		ListNode *l2 = sortList(slow);  // 后半段排序
		return mergeTwoLists(l1, l2);
	}

	// Merge Two Sorted Lists
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
	{
        ListNode dummy(-1);  // 头结点
        for(ListNode *p = &dummy; l1 != nullptr || l2 != nullptr; p = p->next)
        {
        	int val1 = l1 == nullptr ? INT_MAX : l1->val;
        	int val2 = l2 == nullptr ? INT_MAX : l2->val;
        	if(val1 <= val2)
        	{
        		p->next = l1;
        		l1 = l1->next;
        	} else
        	{
        		p->next = l2;
        		l2 = l2->next;
        	}
        }
        return dummy.next;	
	}
}