#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int num;
    struct node *next;
};
 
void create(struct node **);
void findunion(struct node *, struct node *, struct node **);
void display(struct node *);
void release(struct node **);
 
int main()
{
    struct node *phead, *qhead, *intersect, *unionlist;
 
    phead = qhead = intersect = unionlist = NULL;
    printf("Enter elements in the list 1\n");
    create(&phead);
    printf("\nEnter elements in the list 2\n");
    create(&qhead);
    findunion(phead, qhead, &unionlist);
    
    printf("\nDisplaying list 1:\n");
    display(phead);
    printf("Displaying list 2:\n");
    display(qhead);
    printf("Displaying the union of the 2 lists:\n");
    display(unionlist);
    
    release(&phead);
    release(&qhead);
    release(&unionlist);
    
 
    return 0;
}
 

 
void findunion(struct node *p, struct node *q, struct node **unionlist)
{
    struct node *utemp, *ufront, *urear;
    int flag = 0;
 
    while (p != NULL)
    {
        ufront = *unionlist;
        while (ufront != NULL)
        {
            if (ufront->num == p->num)
            {
                flag = 1;
            }
            ufront = ufront->next;
        }
        if (flag)
        {
            flag = 0;
        }
        else
        {
            utemp = (struct node *)malloc(sizeof(struct node));
            utemp->num = p->num;
            utemp->next = NULL;
            if (*unionlist == NULL)
            {
                *unionlist = utemp;
            }
            else
            {
                urear->next = utemp;
            }
            urear = utemp;
        }
        p = p->next;
    }
    while (q != NULL)
    {
        ufront = *unionlist;
        while (ufront != NULL)
        {
            if (ufront->num == q->num)
            {
                flag = 1;
            }
            ufront = ufront->next;
        }
        if (flag)
        {
            flag = 0;
        }
        else
        {
            utemp = (struct node *)malloc(sizeof(struct node));
            utemp->num = q->num;
            utemp->next = NULL;
            if (*unionlist == NULL)
            {
                *unionlist = utemp;
            }
            else
            {
                urear->next = utemp;
            }
            urear = utemp;
        }
        q = q->next;
    }
}
 
void create(struct node **head)
{
    struct node *temp, *rear;
    int ch, a;
 
    do
    {
        printf("Enter a number: ");
        scanf("%d", &a);
        temp = (struct node *)malloc(sizeof(struct node));
        temp->num = a;
        temp->next = NULL;
        if (*head == NULL)
        {
            *head = temp;
        }
        else
        {
            rear->next = temp;
        }
        rear = temp;
        printf("Do you want to continue [1/0] ? ");
        scanf("%d", &ch);
    } while (ch != 0);
}
 
void display(struct node *head)
{
    while (head != NULL)
    {
        printf("%d   ", head->num);
        head = head->next;
    }
    printf("\n");
}
 
void release(struct node **head)
{
    struct node *temp = *head;
    while ((*head) != NULL)
    {
        (*head) = (*head)->next;
        free (temp);
        temp = *head;
    }
}