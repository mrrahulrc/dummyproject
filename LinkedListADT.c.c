#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
struct Node
{
    int data;
    struct Node* link;
};

struct Node* START = NULL;

struct Node* CreateNode()
{
    struct Node* t;
    t = (struct Node*)malloc(sizeof(struct Node));
    return t;
}

void viewList()
{
    struct Node* t;
    if(START == NULL)
    {
        printf("linked list is empty : \n");
    }
    else
    {
        t = START;
        while(t!=NULL)
        {
            printf("%d ",t->data);
            t = t->link;
        }
        printf("\n");
    }
}

void InserAtTheStart()
{
    int info;
    struct Node*t,*p;

    t = CreateNode();
    printf("enter the value : ");
    scanf("%d",&info);
    t->data = info;
    t->link = NULL;

    if(START == NULL)
    {
        START = t;
    }
    else
    {
        /*
        p = START->link;
        START = t;
        t->link = p;
        */
        t->link = START;
        START = t;
    }
}

void InserAtTheEnd()
{
    int info;
    struct Node *t,*ll;
    t = CreateNode();
    printf("Enter the value : ");
    scanf("%d",&info);

    t->data = info;
    t->link = NULL;

    if(START == NULL)
    {
        START = t;
    }
    else
    {
        ll = START;
        while(ll->link!=NULL)
        {
            ll = ll->link;
        }
        ll->link = t;
    }
}

void InsertBeforeTheElement()
{
    int info,element;
    struct Node *t,*ll,*lp;
    t = CreateNode();
    printf("Enter the number : ");
    scanf("%d",&info);
    printf("Enter the element you wanna add before : ");
    scanf("%d",&element);
    t->data = info;
    t->link = NULL;

    if(START==NULL)
    {
        START = t;
    }
    else if(START->data == element)
    {
        t->link = START;
        START = t;
    }
    else
    {
        ll = START;
        lp = START;
        while(ll->data != element)
        {
            //finding the element which we want to find :
            ll = ll->link;
        }

        while(lp->link!=ll)
        {
            //finding before the element
            lp = lp->link;
        }

        lp->link = t;
        t->link = ll;
    }
}

void InsertAfterTheElement()
{
    int info,element;
    struct Node *t,*ll;
    t = CreateNode();
    printf("Enter the value : ");
    scanf("%d",&info);
    printf("Enter the element before you want to insert element : ");
    scanf("%d",&element);

    t->data = info;
    t->link = NULL;

    if(START == NULL)
    {
        printf("linked list is empty : \n");
        free(t);
    }
    else
    {
        ll = START;
        while(ll->data != element)
        {
            ll = ll->link;
        }

        t->link = ll->link;
        ll->link = t;
    }
}

void DeleteFirstElement()
{
    struct Node *ptr;
    if(START == NULL)
    {
        printf("linked list is empty : \n");
    }
    else
    {
        ptr = START;
        START = START->link;
        free(ptr);
    }
}

void DeleteLastElement()
{
    struct Node *ptr,*ll;
    ptr = START;
    ll = START;

    if(START == NULL)
    {
        printf("linked list is empty : \n");
    }
    else if(START->link==NULL)
    {
        START=NULL;
    }
    else
    {
        while(ptr->link!=NULL)
        {
            ptr = ptr->link;
        }
        while(ll->link!=ptr)
        {
            ll = ll->link;
        }
        ll->link = NULL;
        free(ptr);
    }
}

void DeleteFixElement()
{
    int info;
    struct Node *ptr,*ll;
    ptr = START;
    ll = START;

    printf("Enter the element you want to delete : ");
    scanf("%d",&info);

    if(START == NULL)
    {
        printf("linked list is empty : \n");
    }
    else if(ptr->data==info && ptr->link==NULL)
    {
        free(ptr);
        START=NULL;
    }
    else if(ptr->data==info)
    {
        START = START->link;
        free(ptr);
    }
    else
    {
        while(ptr->data!=info)
        {
            ptr = ptr->link;
        }
        while(ll->link!=ptr)
        {
            ll = ll->link;
        }
        ll->link = ptr->link;
        free(ptr);
    }
}

void IsAvailable()
{
    int info,t=1;
    struct Node *ll,*lk;
    ll = START;


    printf("Enter the element you want to check  : ");
    scanf("%d",&info);

    while(ll->data!=info)
    {
        if(ll->data!=info && ll->link==NULL)
        {
            t=0;
            break;
        }
        ll=ll->link;
    }

    if(t)
    {
        printf("element is avaiable in linked list : \n");
    }
    else
    {
        printf("element is not available  \n");
    }
}
int main()
{
    int t;
    printf("1. Quit \n");
    printf("2. Display the element \n");
    printf("3. Insert element at the start \n");
    printf("4. Insert element at the end\n");
    printf("5. Insert element before the element : \n");
    printf("6. Insert element after the element : \n");
    printf("7. Delete First Element : \n");
    printf("8. Delete last element : \n");
    printf("9. Delete the particular Node :\n");
    printf("10. Check whether element is available or not : \n");
    st:
    printf("Enter the choice : ");
    scanf("%d",&t);
    switch(t)
    {
    case 1 :
        exit(0);

    case 2 :
        viewList();
        goto st;

    case 3:
        InserAtTheStart();
        goto st;

    case 4:
        InserAtTheEnd();
        goto st;

    case 5:
        InsertBeforeTheElement();
        goto st;

    case 6:
        InsertAfterTheElement();
        goto st;

    case 7:
        DeleteFirstElement();
        goto st;

    case 8:
        DeleteLastElement();
        goto st;

    case 9:
        DeleteFixElement();
        goto st;

    case 10:
        IsAvailable();
        goto st;
    default :
        printf("enter the valid choice : ");
        goto st;
    }
    return 0;
}
