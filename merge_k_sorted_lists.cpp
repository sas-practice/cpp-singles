/**
 * https://leetcode.com/problems/merge-k-sorted-lists
 * Definition for singly-linked list.
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


struct NodeCmp
{
    bool operator()(const ListNode &lhs, const ListNode &rhs) const
    {
        return lhs.val > rhs.val;
    }
};

ListNode* mergeKLists(vector<ListNode *>& lists) {

    if (lists.size() == 1) return lists[0];

    priority_queue<ListNode, vector<ListNode>, NodeCmp> pq;

    for (auto &head: lists) {
        if (head) {
            pq.push(*head);
        }
    }

    ListNode* result = nullptr;
    ListNode* tail = nullptr;

    while (!pq.empty()) {
        auto current = pq.top();
        pq.pop();

        if (current.next) pq.push(*current.next);

        ListNode* copy = new ListNode(current.val);

        if (!tail) {
            result = copy;
            tail = copy;
        } else {
            tail -> next = copy;
            tail = copy;
        }
    }

    return result;
}
