// 답이 여러 가지인 경우에는 아무거나 출력한다.
// 링크드 리스트는 시간 초과;;
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct ListNode {
	int data;
	struct ListNode* next;
} ListNode;

void InsertInLinkedList(ListNode** head, int data, int position) {
	ListNode* inserted = new ListNode;
	inserted->data = data;

	if (position == 1 || *head == NULL) {
		inserted->next = *head;
		*head = inserted;
	}
	else {
		ListNode* inserted_prev = *head;
		for (int i = 1; (inserted_prev->next != NULL) && (i < position - 1); i++) {
			inserted_prev = inserted_prev->next;
		}

		ListNode* inserted_next = inserted_prev->next;
		inserted_prev->next = inserted;
		inserted->next = inserted_next;
	}
}

int FindIdx(struct ListNode* head, int data) {

	struct ListNode* current = head;
	int idx = 1;

	while (current != NULL) {
		if (current->data == data) {
			break;
		}
		current = current->next;
		idx++;
	}
	return idx;
}

void PrintList(struct ListNode* head, int last_student) {
	struct ListNode* current = head;
	while (current != NULL)
	{
		cout << current->data << " ";
		current = current->next;
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	ListNode* student_order = NULL;

	for (int i = 0; i < m; i++) {
		int first_student;
		int second_student;

		cin >> first_student >> second_student;
		if (i == 0) {
			InsertInLinkedList(&student_order, second_student, 1);
			InsertInLinkedList(&student_order, first_student, 1);
		}
		InsertInLinkedList(&student_order, first_student, FindIdx(student_order, second_student));
	}


	PrintList(student_order, n);
	return 0;
}