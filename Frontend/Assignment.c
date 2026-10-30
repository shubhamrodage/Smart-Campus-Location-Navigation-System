#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int Data;
    struct Node *Left;
    struct Node *Right;
};

struct Node* CreateNode(int iNo)
{
    struct Node *NewNode;

    NewNode = (struct Node*)malloc(sizeof(struct Node));

    NewNode->Data = iNo;
    NewNode->Left = NULL;
    NewNode->Right = NULL;

    return NewNode;
}

struct Node* Insert(struct Node *Root, int iNo)
{
    struct Node *NewNode;
    struct Node *Temp;
    struct Node *Parent;

    NewNode = CreateNode(iNo);

    if(Root == NULL)
    {
        return NewNode;
    }

    Temp = Root;

    while(Temp != NULL)
    {
        Parent = Temp;

        if(iNo < Temp->Data)
        {
            Temp = Temp->Left;
        }
        else
        {
            Temp = Temp->Right;
        }
    }

    if(iNo < Parent->Data)
    {
        Parent->Left = NewNode;
    }
    else
    {
        Parent->Right = NewNode;
    }

    return Root;
}

void Inorder(struct Node *Root)
{
    struct Node *Stack[100];
    struct Node *Temp = Root;

    int Top = -1;

    while(Temp != NULL || Top != -1)
    {
        while(Temp != NULL)
        {
            Stack[++Top] = Temp;
            Temp = Temp->Left;
        }

        Temp = Stack[Top--];

        printf("%d ", Temp->Data);

        Temp = Temp->Right;
    }
}

void Preorder(struct Node *Root)
{
    struct Node *Stack[100];
    struct Node *Temp;

    int Top = -1;

    if(Root == NULL)
    {
        return;
    }

    Stack[++Top] = Root;

    while(Top != -1)
    {
        Temp = Stack[Top--];

        printf("%d ", Temp->Data);

        if(Temp->Right != NULL)
        {
            Stack[++Top] = Temp->Right;
        }

        if(Temp->Left != NULL)
        {
            Stack[++Top] = Temp->Left;
        }
    }
}

void Postorder(struct Node *Root)
{
    struct Node *Stack1[100];
    struct Node *Stack2[100];

    struct Node *Temp;

    int Top1 = -1;
    int Top2 = -1;

    if(Root == NULL)
    {
        return;
    }

    Stack1[++Top1] = Root;

    while(Top1 != -1)
    {
        Temp = Stack1[Top1--];

        Stack2[++Top2] = Temp;

        if(Temp->Left != NULL)
        {
            Stack1[++Top1] = Temp->Left;
        }

        if(Temp->Right != NULL)
        {
            Stack1[++Top1] = Temp->Right;
        }
    }

    while(Top2 != -1)
    {
        Temp = Stack2[Top2--];

        printf("%d ", Temp->Data);
    }
}

int main()
{
    struct Node *Root = NULL;

    int iChoice;
    int iNo;

    while(1)
    {
        printf("\n\n===== BINARY SEARCH TREE =====\n");

        printf("1. Insert\n");
        printf("2. Postorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Inorder Traversal\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &iChoice);

        switch(iChoice)
        {
            case 1:

                printf("Enter number: ");
                scanf("%d", &iNo);

                Root = Insert(Root, iNo);

                printf("Node inserted successfully.\n");
                break;

            case 2:

                printf("Postorder Traversal: ");
                Postorder(Root);
                printf("\n");
                break;

            case 3:

                printf("Preorder Traversal: ");
                Preorder(Root);
                printf("\n");
                break;

            case 4:

                printf("Inorder Traversal: ");
                Inorder(Root);
                printf("\n");
                break;

            case 5:

                printf("Program terminated.\n");
                return 0;

            default:

                printf("Invalid choice.\n");
        }
    }

    return 0;
}