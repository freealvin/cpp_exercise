#include<iostream>
#include "BSTreeNode.h"
using namespace std;
void convertBST2DL(BSTreeNode *root, BSTreeNode* &last)
{

    if(root==NULL)
        return;

    BSTreeNode *pCurrent = root;

    if(root->m_pLeft!=NULL)
        convertBST2DL(root->m_pLeft, last);

    pCurrent->m_pLeft = last;
    if(last!=NULL)
        last->m_pRight = pCurrent;
    last = pCurrent;//把当前节点插入到双链表结尾

    if(pCurrent->m_pRight!=NULL)
        convertBST2DL(pCurrent->m_pRight, last);

}
BSTreeNode* Convert_Solution1(BSTreeNode* pHeadOfTree)
{
    BSTreeNode *last = NULL;
    convertBST2DL(pHeadOfTree, last);
    pHeadOfTree = last;
    while(pHeadOfTree&&pHeadOfTree->m_pLeft)
        pHeadOfTree = pHeadOfTree->m_pLeft;

    return pHeadOfTree;
}

void Print_BST(BSTreeNode* pHead)
{
    while(pHead!=NULL&&pHead->m_pRight){
        cout << pHead->m_nValue << '=';
        pHead = pHead->m_pRight;
    }
    if(pHead)
        cout << pHead->m_nValue;
    cout << endl;
}

struct BSTreeNode *pHead = NULL;

BSTreeNode* AddBSTNode(BSTreeNode* &pHead, int value)
{
    if(pHead==NULL)
    {
        pHead = new BSTreeNode;
        pHead->m_nValue = value;
        pHead->m_pLeft = NULL;
        pHead->m_pRight = NULL;
    }
    else if(value<pHead->m_nValue)
    {
        AddBSTNode(pHead->m_pLeft, value);
    }
    else
        AddBSTNode(pHead->m_pRight, value);
}

int main()
{
    AddBSTNode(pHead, 10);
    AddBSTNode(pHead, 6);
    AddBSTNode(pHead, 14);
    AddBSTNode(pHead, 16);
    AddBSTNode(pHead, 12);
    AddBSTNode(pHead, 4);
    AddBSTNode(pHead, 8);
    pHead = Convert_Solution1(pHead);
    Print_BST(pHead);
    return 0;
}
