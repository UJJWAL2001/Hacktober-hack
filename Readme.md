#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *next;
};
struct node *first = NULL;
struct node *count_node(struct node*);
struct node *print_node(struct node*);
struct node *add_beg(struct node*);
struct node *add_end(struct node*);
struct node *after_data(struct node*);
struct node *after_node(struct node*);
struct node *del_beg(struct node*);
struct node *del_end(struct node*);
struct node *del_mid_by_data(struct node*);
struct node *del_mid_by_num(struct node*);
struct node *mid_element(struct node*);
struct node *sort_node(struct node*);
struct node *reverse_node(struct node*);
struct node *search_node(struct node*);

int main()
{
        int opt;
    do{

        printf("\n1->_Counting of nodes_\n");
        printf("2->_Printing of Linked List_\n");
        printf("3->_Add a element in LL in beg_\n");
        printf("4->_Add a element in LL in end_\n");
        printf("5->_Add a element after the data_\n");
        printf("6->_Add a element after the node_\n");
        printf("7->_Del a element from the beg_\n");
        printf("8->_Del a element from the end_\n");
        printf("9->_Del a element from mid by data_\n");
        printf("10->_Del a element from mid by number_\n");
        printf("11->_Mid element of LL_\n");
        printf("12->_Sorting of LL_\n");
        printf("13->_Reverse LL_\n");
        printf("14->_Search node by data_\n");
        printf("15->FOR END OF THE PROCESS ");
        printf("\n\n__Choose a valid option__\n\n");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1: first = count_node(first);
            break;
            case 2: first = print_node(first);
            break;
            case 3: first = add_beg(first);
            break;
            case 4: first  = add_end(first);
            break;
            case 5: first = after_data(first);
            break;
            case 6: first = after_node(first);
            break;
            case 7: first = del_beg(first);
            break;
            case 8: first = del_end(first);
            break;
            case 9: first = del_mid_by_data(first);
            break;
            case 10: first = del_mid_by_num(first);
            break;
            case 11: first = mid_element(first);
            break;
            case 12: first = sort_node(first);
            break;
            case 13: first = reverse_node(first);
            break;
            case 14: first = search_node(first);
            break;
            default : printf("\n\nEnter a valid number from the above list");
            break;
        }



    }while(opt != 15);
    return 0;
}

struct node* count_node(struct node *first)
{
    struct node *ptr = first;
    int count = 0;
    if(first == NULL)
    {
        printf("\n\nLinked List is empty");
    }
    else
    {
        while(ptr != NULL)
        {
            count += 1;
            ptr = ptr->next;
        }
        printf("\nNo. of nodes in Linked List is %d\n",count);
    }
    return first;
};

struct node* print_node(struct node *first)
{
    struct node *ptr = first;
    if(first == NULL)
    {
        printf("\nLinked list is \n");
    }
    else
    {
        while(ptr != NULL)
        {
            printf(" %d ", ptr->data);
            ptr = ptr->next;
        }
    }
    return first;
};

struct node* add_beg(struct node* first)
{
    struct node *ptr = first, *new_;
    int num;
    printf("\nEnter the data to  be inserted");
    scanf("%d",&num);
    new_ = (struct node*)malloc(sizeof(struct node));
    new_->data = num;
    if(first == NULL)
    {
        first = new_;
        new_->next = NULL;
    }
    else
    {
        new_->next = first;
        first = new_;
    }
    return first;

};

struct node *add_end(struct node *first)
{
    struct node *ptr = first,*new_;
    int num;
    new_ = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data to  be inserted");
    scanf("%d",&num);
    new_->data = num;
    if(first == NULL)
    {
        first = new_;
        new_->next = NULL;
    }
    else if(ptr->next == NULL)
    {
        ptr->next = new_;
        new_->next = NULL;
    }
    else
    {
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new_;
        new_->next = NULL;
    }
    return first;

};

struct node *after_data(struct node *first)
{
    struct node *ptr = first,*new_;
    int num, data;
    new_ = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the digit to be inserted in Linked List");
    scanf("%d",&num);
    printf("\nEnter the data after you inserted the digit");
    scanf("%d",&data);
    new_->data = num;
    if(first == NULL)
    {
        printf("\nEnter the valid operation");
    }
    if(ptr->data == data)
    {
        new_->next = ptr->next;
        ptr->next = new_;
    }
    else
    {
        while(ptr->next->data != data)
        {
            ptr = ptr->next;
        }
        new_->next = ptr->next->next;
        ptr->next->next = new_;
    }
    return first;
};

struct node *after_node(struct node *first)
{
    struct node *ptr = first,*cpt = first,*new_;
    new_ = (struct node*)malloc(sizeof(struct node));
    int num,node,count = 0;
    printf("\nEnter the data to be inserted");
    scanf("%d",&num);
    printf("\nEnter the No. of nodes after you inserted the data");
    scanf("%d",&node);
    new_->data = num;
    if(first == NULL)
    {
        printf("\nEnter the valid operation");
    }
    while(count < node)
    {
        count += 1;
        ptr = ptr->next;
    }
    while(cpt->next != ptr)
    {
        cpt = cpt->next;
    }
    new_->next = cpt->next;
    cpt->next = new_;
    return first;



};

struct node *del_beg(struct node *first)
{
    struct node *ptr = first;
    if(ptr == NULL)
    {
        printf("\nNothing to delete");
    }
    else if(first->next == NULL)
    {
        free(first);
        first = NULL;
    }
    else
    {
        first = first->next;
    }
    return first;
};

struct node* del_end(struct node *first)
{
    struct node *ptr = first;
    if(first == NULL)
    {
        printf("\nNothing to delete");
    }
    else if(first->next == NULL)
    {
        free(first);
        first = NULL;
    }
    else
    {
        while(ptr->next->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = NULL;
    }
    return first;
};

struct node *del_mid_by_data(struct node *first)
{
    struct node *ptr = first;
    int data;
    printf("\nEnter the data to be deleted");
    scanf("%d",&data);
    if(first == NULL)
    {
        printf("\nNothing to delete");
    }
    else if(first->data == data && first->next == NULL)
    {
        free(first);
        first = NULL;
    }
    else
    {
        while(ptr->next->data != data && ptr->next->next != NULL)
        {
             ptr = ptr->next;
        }
        ptr->next = ptr->next->next;
    }
    return first;
};

struct node *del_mid_by_num(struct node *first)
{
    struct node *ptr = first,*cpt = first;
    int num,count = 0;
    printf("\nEnter the node which is to be deleted");
    scanf("%d",&num);
    while(count < num)
    {
        count += 1;
        ptr = ptr->next;
    }
    while(cpt->next != ptr)
    {
        cpt = cpt->next;
    }
    cpt->next = cpt->next->next;
    return first;
};

struct node *mid_element(struct node *first)
{
    struct node *slow = first, *fast = first;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("\nMid element of Linked List i %d",slow->data);
    return first;
};

struct node *sort_node(struct node *first)
{
    struct node *ptr1 = first,*ptr2 = NULL;
    int temp;
    if(first != NULL)
    {
        while(ptr1 != NULL)
        {
            ptr2 = ptr1->next;
            while(ptr2 != NULL)
            {
                if(ptr2->data > ptr1->data)
                {
                    temp = ptr2->data;
                    ptr2->data = ptr1->data;
                    ptr1->data = temp;
                }
                ptr2 = ptr2->next;
            }
            ptr1 = ptr1->next;
        }
    }
    return first;
};

struct node *reverse_node(struct node *first)
{
    struct node *prev = NULL, *next = NULL;
    if(first != NULL)
    {
        while(first != NULL)
        {
            next = first->next;
            first->next = prev;
            prev = first;
            first = next;
        }
        first = prev;
        return first;

    }
};

struct node *search_node(struct node *first)
{
    struct node *ptr = first;
    int dataa,count = 0;
    printf("\nEnter the data to  be searched");
    scanf("%d",&dataa);
    if(first == NULL)
    {
        printf("\nNothing to search");
    }
    else
    {
        while(ptr->data != dataa)
        {
            count += 1;
            ptr = ptr->next;
        }
        printf("\nPosition of the searched node is %d",count+1);
    }
    return first;
} ;

