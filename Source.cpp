#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Node
{
	int i;
	Node* pLeft;
	Node* pRight;

	Node(int iIn) : i(iIn), pLeft(nullptr), pRight(nullptr) {}
};
void PrintTree(Node* pRoot, int Level)
{
	if (!pRoot)
		return;

	PrintTree(pRoot->pRight, Level + 1);

	for (int i = 0; i < Level; i++)
		cout << "  ";
	cout << pRoot->i << endl;

	PrintTree(pRoot->pLeft, Level + 1);
}

void InsertToTree(Node*& pRoot, Node* pNew)
{
	if (!pRoot)
		pRoot = pNew;
	else
	{
		if (pNew->i < pRoot->i)
			InsertToTree(pRoot->pLeft, pNew);
		else
			InsertToTree(pRoot->pRight, pNew);
	}
}

void FindLargestSumAndBranch(Node* pRoot, int& LargestSum, vector<Node*>& LargestBranch) {

	int LeftSum, RightSum = 0;

	if (pRoot != nullptr) {

		LargestSum = pRoot->i;
		LargestBranch.push_back(pRoot);

		if (pRoot->pLeft != nullptr && pRoot->pRight != nullptr) 
		{

			FindLargestSumAndBranch(pRoot->pLeft, LeftSum, LargestBranch);
			FindLargestSumAndBranch(pRoot->pRight, RightSum, LargestBranch);

			if (RightSum >= LeftSum) 
			{
				LargestSum += RightSum;
			}
			else 
			{
				LargestSum += LeftSum;
			}

		}
		else if (pRoot->pLeft != nullptr) 
		{
			FindLargestSumAndBranch(pRoot->pLeft, LeftSum, LargestBranch);
			LargestSum += LeftSum;
		}
		else if (pRoot->pRight != nullptr) 
		{
			FindLargestSumAndBranch(pRoot->pRight, RightSum, LargestBranch);
			LargestSum += RightSum;
		}
	}
}

void PrintBranch(vector<Node*> branch, int sum) {

	cout << "Branch with the largest sum is: ";

	for (int j = 0; j < branch.size(); j++)
	{
		cout << branch[j]->i << " ";
	}

	cout << " -> SUM = " << sum << endl;

}

void PrintLargestPathAndSum(Node* pRoot) {

	vector<Node*> LargestBranch;

	int LargestSum = 0;
	
	FindLargestSumAndBranch(pRoot, LargestSum, LargestBranch);
	PrintBranch(LargestBranch, LargestSum);

}

void main()
{
	int i;

	Node* pRoot = nullptr;

	while (true)
	{
		cin >> i;
		if (i == 99)
			break;

		Node* p = new Node(i);
		InsertToTree(pRoot, p);
	}

	PrintTree(pRoot, 1);

	PrintLargestPathAndSum(pRoot);

}
