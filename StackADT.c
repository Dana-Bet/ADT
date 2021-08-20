#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define SizeStack 30

/*function prototypes*/
struct node* InItNode(int);
void PrintNode(struct node*);
void PrintStack();
void PushThree(struct node*,int);
void Push(struct node*);
void Pop();
void PopItAll();
void Min_Max();
int ItIsfull(int cnt);
int ItIsEmpty(int cnt);

 struct node
{
   int key;
   struct node *next;
};
 struct node *head=NULL;

/*Function implications*/
int ItIsfull(int cnt)
{
    if (cnt == SizeStack)
    {
        printf("The stack is full!");
        return  1;
    }
    return 0;
}
int ItIsEmpty(int cnt)
{
    if (cnt == 0)
        return 1;
    return 0;
}
struct node* InItNode(int k)
{
    struct node *temp;
    temp =(struct node*)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Allocation failed!");
        return NULL;
    }
    else
    {
        temp->key = k;
        temp->next = NULL;
    }
    return temp;
}
void PrintNode(struct node* ptr)
{
    printf("->%d ", ptr->key);
}
void PrintStack()
{
    struct node* run = head;
    while (run!=NULL)
    {
        PrintNode(run);
        run = run->next->next->next;
    }
    printf("->//");

}
void Push(struct node* ptr) 
{
    ptr->next = head;
    head=ptr;
}
void PushThree(struct node* ptr,int size)
{
    struct node* temp=ptr;
    int cnt = 3;
    int newnum = ptr->key;
    if (ItIsEmpty(size))     //If the stuck is empty ,push the first node three times.
    {
        while (cnt)
        {
            Push(temp);
            temp = InItNode(newnum);
            cnt--;
        }
        return;
    }
    else               //If not empty.
    {
        struct node *min =head->next;
        struct node *max =head->next->next;
        if (newnum > max->key)
        {
            temp = InItNode(newnum);
            Push(temp);
        }
        else
        {
            temp = InItNode(max->key);
            Push(temp);
        }
        if (newnum < min->key)
        {
            temp = InItNode(newnum);
            Push(temp);
        }
        else
        {
            temp = InItNode(min->key);
            Push(temp);
        }
    }

    temp = InItNode(newnum);
    Push(temp);

}
void Pop()
{
    struct node* temp;
    for (int i =0; i <3; i++)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}
void PopItAll()
{
    while (!ItIsEmpty)
        Pop;
    head = NULL;
}
void Min_Max()
{
    
    printf("The minimum is:%d\nThe maximum is:%d", head->next->key, head->next->next->key);
}

int main() {
    int cnt = 0;
    int val=0;
    int ch = 1;
    struct node* ptr;
    int i;
    while (ch != 0)
    {
        printf("\n1:Push to stack\n");
        printf("\n2:Pop from stack\n");
        printf("\n3:Print the stack\n");
        printf("\n4:Print the minimum and maximum values\n");
        printf("\n0:quit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            if (ItIsfull(cnt))
                break;
            printf("Insert a key:");
            scanf("%d",&val);
            ptr = InItNode(val);
            if (ptr == NULL) {
                printf("Allocation failed");
                PopItAll();
                cnt = 0;
            }
            else {
                PushThree(ptr,cnt);
                cnt += 1;
            }
            break;
        case 2:
            if (ItIsEmpty(cnt))
            {
                printf("The stack is empty!!");
                break;
            }
            else 
            {
                Pop();
                cnt -= 1;
            }
            break;
        case 3:
            if (!ItIsEmpty(cnt))
                PrintStack();
            else
            {
                printf("The stack is empty!!\n");
                printf("Choose other option.");
            }
            break;
        case 4:
            Min_Max();
            break;
        case 0:
            PopItAll();
            printf("Bye Bye!");
            return 0;
        }

    }


}