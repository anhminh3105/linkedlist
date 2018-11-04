#include <gtest/gtest.h>
#include "linked_list.h"
#include "string.h"
#include <stdio.h>

/***************************************************************************/
TEST(addtest,normal) {
    char str[15]="List Start";
    char str1[10]="zero";
    char str2[10]="first";
    char str3[10]="second";
    char str4[10]="third";
    char str5[10]="fourth";
    char str6[10]="fifth";
    int i;

    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));

    head->next=NULL;
    head->previous= NULL; 
    head->data=str; 
    head->index=0;

    i=add_to_list(head,str1);
    EXPECT_EQ(1,i);

    i=add_to_list(head,str2);
    EXPECT_EQ(2,i);

    i=add_to_list(head,str3);
    EXPECT_EQ(3,i);

    i=add_to_list(head,str4);
    EXPECT_EQ(4,i);

    i=add_to_list(head,str5);
    EXPECT_EQ(5,i);

    i=add_to_list(head,str6);
    EXPECT_EQ(6,i);

}
/***************************************************************************/
TEST(addtest, empty_list) {
    int i;
    char str[15]="List Start";
    linked_list *head = NULL;
    i=add_to_list(head,str);
    EXPECT_EQ(0,i);
}

TEST(addtest, no_data) {
    char *str;
    int i;

    linked_list *head = NULL;
    i=add_to_list(head,str);
    EXPECT_EQ(-1,i);
}

/***************************************************************************/
TEST(search,normal)
{
    char str[15]="List Start";
    char str1[10]="zero";
    char str2[10]="first";
    char str3[10]="second";
    char str4[10]="third";
    char str5[10]="fourth";
    char str6[10]="fifth";
    int i;
    linked_list *found = NULL;
    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));

    head->next=NULL;
    head->previous= NULL; 
    head->data=str; 
    head->index=0;

    i=add_to_list(head,str1);
    i=add_to_list(head,str2);
    i=add_to_list(head,str3);
    i=add_to_list(head,str4);
    i=add_to_list(head,str5);
    i=add_to_list(head,str6);

    found=search_from_list(head,(char *)"third");
    EXPECT_EQ(found->index,4);
    EXPECT_STREQ(str4,found->data);
}

/***************************************************************************/
TEST(search,not_found)
{
    char str[15]="List Start";

    linked_list *found;

    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

    head->next=NULL;
    head->previous= NULL;
    head->data=str;
    head->index=0;

    found=search_from_list(head,(char *)"third");

    EXPECT_EQ((int *)found,(int *)NULL);
}
/***************************************************************************/
TEST(search,empty)
{
    linked_list *found;
    linked_list *head = NULL;  
    
    found=search_from_list(head,(char *)"third");

    EXPECT_EQ((int *)found,(int *)NULL);
}
/***************************************************************************/
TEST(display_item,empty) {
    linked_list *find = NULL;
    int i = display_item(find);

    EXPECT_EQ(i, - 1);
}
/***************************************************************************/
TEST(display_item,single)
{
    char str[15]="List Start";

    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

    head->next=NULL;
    head->previous= NULL;
    head->data=str;
    head->index=0;
    
    EXPECT_EQ(0, display_item(head));
}
/***************************************************************************/
TEST(display_item,add_to_list)
{
    int result;
    char str[15]="List Start";
    char str1[10]="zero";
    char str2[10]="first";
    char str3[10]="second";
    char str4[10]="third";
    char str5[10]="fourth";
    char str6[10]="fifth";
    int i = 0;

    

    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

    head->next=NULL;
    head->previous= NULL;
    head->data=str;
    head->index=i;

    

    display_item(head);

    i=add_to_list(head,str1);
    display_item(head->next);

    EXPECT_EQ(i, 1);
    EXPECT_EQ(head->next->index,1);
    EXPECT_STREQ(head->next->data,str1);

    i=add_to_list(head,str2);
    display_item(head->next);
    EXPECT_EQ(head->next->next->index,2);
    EXPECT_EQ(i,2);
    EXPECT_STREQ(head->next->next->data,str2);

    i=add_to_list(head,str3);
    display_item(head->next->next);
    EXPECT_EQ(head->next->next->next->index,3);
    EXPECT_EQ(i,3);
    EXPECT_STREQ(head->next->next->next->data,str3);

    i=add_to_list(head,str4);
    display_item(head->next->next->next);
    EXPECT_EQ(head->next->next->next->next->index,4);
    EXPECT_EQ(i,4);
    EXPECT_STREQ(head->next->next->next->next->data,str4);

    i=add_to_list(head,str5);
    display_item(head->next->next->next->next);
    EXPECT_EQ(head->next->next->next->next->next->index,5);
    EXPECT_EQ(i,5);
    EXPECT_STREQ(head->next->next->next->next->next->data,str5);

    i=add_to_list(head,str6);
    display_item(head->next->next->next->next->next);
    EXPECT_EQ(head->next->next->next->next->next->next->index,6);
    EXPECT_EQ(i,6);
    EXPECT_STREQ(head->next->next->next->next->next->next->data,str6);
}
/***************************************************************************/
TEST(display_list,empty)
{
    int result;
    char str[15]="List Start";

    linked_list *head = NULL;

    display_list(head);

}
/***************************************************************************/
TEST(display_list,normal)
{
    char str[15]="List Start";
    char str1[10]="zero";
    char str2[10]="first";
    char str3[10]="second";
    char str4[10]="third";
    char str5[10]="fourth";
    char str6[10]="fifth";
    int i;


    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

    head->next=NULL;
    head->previous= NULL;
    head->data=str;
    head->index=0;

    i=add_to_list(head,str1);
    i=add_to_list(head,str2);
    i=add_to_list(head,str3);
    i=add_to_list(head,str4);
    i=add_to_list(head,str5);
    i=add_to_list(head,str6);
    
    i = display_list(head);
    EXPECT_EQ(7, i);
}

/***************************************************************************/
TEST(display_list,single)
{
    char str[15]="List Start";

    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

    head->next=NULL;
    head->previous= NULL;
    head->data=str;
    head->index=0;
    
    EXPECT_EQ(1, display_list(head));
}
/***************************************************************************/
TEST(swap,normal_1)
{
    char str1[10]="zero";
    char str2[10]="first";
    linked_list *l_1 = (struct linked_list*) malloc(sizeof(linked_list));  
    linked_list *l_2 = (struct linked_list*) malloc(sizeof(linked_list));
    l_1->next=NULL;
    l_1->data=str1;
    l_1->previous=NULL;
    l_1->index=0;
    l_2->next=NULL;
    l_2->previous=NULL;
    l_2->data=str2;
    l_2->index=1;
    
    EXPECT_EQ(0, swap_items(l_1, l_2));
    EXPECT_STREQ(l_1->data, str2);
    EXPECT_STREQ(l_2->data, str1);
}
/***************************************************************************/
TEST(swap,empty)
{
    char str1[10]="zero";
    char str2[10]="first";
    linked_list *l_1 = NULL;  
    linked_list *l_2 = NULL;

    EXPECT_EQ(-1, swap_items(l_1, l_2));
}
/***************************************************************************/
TEST(swap,normal_2)
{
    char str1[10]="zero";
    char str2[10]="first";
    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

    head->next=NULL;
    head->previous=NULL;
    head->data=str1;
    head->index=0;
    add_to_list(head, str2);
    
    EXPECT_EQ(0, swap_items(head, head->next));
    EXPECT_STREQ(head->data, str2);
    EXPECT_STREQ(head->next->data, str1);
}
/***************************************************************************/
TEST(sort,normal)
{
    char str[15]="List Start";
    char str1[10]="zero";
    char str2[10]="first";
    char str3[10]="second";
    char str4[10]="third";
    char str5[10]="fourth";
    char str6[10]="fifth";
    int i;

    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  
    head->previous=NULL;
    head->next=NULL;
    head->data=str;
    head->index=0;

    i=add_to_list(head,str1);
    i=add_to_list(head,str2);
    i=add_to_list(head,str3);
    i=add_to_list(head,str4);
    i=add_to_list(head,str5);
    i=add_to_list(head,str6);

    printf("lists:\n");
    display_list(head);
    EXPECT_EQ(0, sort_list(head));
    EXPECT_STREQ(head->data,str);
    EXPECT_STREQ(head->next->data,str6);
    EXPECT_STREQ(head->next->next->data,str2);
    EXPECT_STREQ(head->next->next->next->data,str5);
    EXPECT_STREQ(head->next->next->next->next->data,str3);
    EXPECT_STREQ(head->next->next->next->next->next->data,str4);
    EXPECT_STREQ(head->next->next->next->next->next->next->data,str1);

    printf("list after sorted:\n");
    display_list(head);
}
/***************************************************************************/
TEST(sort,empty)
{
    linked_list *l_1 = NULL;  
    EXPECT_EQ(-1, sort_list(l_1));
}
/***************************************************************************/
TEST(sort,middle_link)
{
    char str[15]="List Start";
    char str1[10]="zero";
    char str2[10]="first";
    char str3[10]="second";
    char str4[10]="third";
    char str5[10]="fourth";
    char str6[10]="fifth";
    int i;

    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  
    head->previous=NULL;
    head->next=NULL;
    head->data=str;
    head->index=0;

    i=add_to_list(head,str1);
    i=add_to_list(head,str2);
    i=add_to_list(head,str3);
    i=add_to_list(head,str4);
    i=add_to_list(head,str5);
    i=add_to_list(head,str6);

    printf("lists:\n");
    display_list(head);
    EXPECT_EQ(0, sort_list(head->next->next->next->next->next));
    EXPECT_STREQ(head->data,str);
    EXPECT_STREQ(head->next->data,str6);
    EXPECT_STREQ(head->next->next->data,str2);
    EXPECT_STREQ(head->next->next->next->data,str5);
    EXPECT_STREQ(head->next->next->next->next->data,str3);
    EXPECT_STREQ(head->next->next->next->next->next->data,str4);
    EXPECT_STREQ(head->next->next->next->next->next->next->data,str1);

    printf("list after sorted:\n");
    display_list(head);
}
/***************************************************************************/
TEST(delete,normal)
{
    char str[15]="List Start";
    char str1[10]="zero";
    char str2[10]="first";
    char str3[10]="second";
    char str4[10]="third";
    char str5[10]="fourth";
    char str6[10]="fifth";
    int i;
    int len = 0;
    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  
    head->previous=NULL;
    head->next=NULL;
    head->data=str;
    head->index=0;


    i=add_to_list(head,str1);
    i=add_to_list(head,str2);
    i=add_to_list(head,str3);
    i=add_to_list(head,str4);
    i=add_to_list(head,str5);
    i=add_to_list(head,str6);

    printf("Before Deleting index 2:\n");
    display_list(head);
    len = delete_from_list(head,2);
    printf("Deleting index 2...\n");
    printf("After Deleting index 2:\n");
    display_list(head);
    EXPECT_EQ(len, 6);
}
/***************************************************************************/
TEST(delete,multi) {
    char str[15]="List Start";
    char str1[10]="zero";
    char str2[10]="first";
    char str3[10]="second";
    char str4[10]="third";
    char str5[10]="fourth";
    char str6[10]="fifth";
    int i;
    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  
    head->previous=NULL;
    head->data=str;
    head->index=0;
    head->next=NULL;

    i=add_to_list(head,str1);
    i=add_to_list(head,str2);
    i=add_to_list(head,str3);
    i=add_to_list(head,str4);
    i=add_to_list(head,str5);
    i=add_to_list(head,str6);

    for(i=0; i<40; i++)
        add_to_list(head,str1);
    
    i=delete_from_list(head,12);
    EXPECT_EQ(i, 46);
    i=delete_from_list(head,22);
    EXPECT_EQ(i, 45);
    i=delete_from_list(head,25);
    EXPECT_EQ(i, 44);
    i=delete_from_list(head,32);
    EXPECT_EQ(i, 43);
    i=delete_from_list(head,38);
    EXPECT_EQ(i, 42);
    i=delete_from_list(head,0);
    EXPECT_EQ(i, 41);
    i=delete_from_list(head,380);
    EXPECT_EQ(i, -1);
    display_list(head);
}
/***************************************************************************/
TEST(delete,single) {
    char str[15]="List Start";
    int i;
    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  
    head->previous=NULL;
    head->data=str;
    head->index=0;
    head->next=NULL;

    i=delete_from_list(head,0);
    display_list(head);
    EXPECT_EQ(i, 1);
}
/***************************************************************************/
TEST(delete, empty) {
    linked_list *h = NULL;
    EXPECT_EQ(-1, delete_from_list(h, 0));

}
/***************************************************************************/
TEST(empty,normal) {
    char str[15]="List Start";
    char str1[10]="zero";
    char str2[10]="first";
    char str3[10]="second";
    char str4[10]="third";
    char str5[10]="fourth";
    char str6[10]="fifth";
    int i;

    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  
    head->previous=NULL;
    head->next=NULL;
    head->data=str;
    head->index=0;

    i=add_to_list(head,str1);
    i=add_to_list(head,str2);
    i=add_to_list(head,str3);
    i=add_to_list(head,str4);
    i=add_to_list(head,str5);
    i=add_to_list(head,str6);
    printf("lists:\n");
    display_list(head);
    EXPECT_EQ(7, empty_list(head));
    printf("list after deleted:\n");
    display_list(head);
}
/***************************************************************************/
TEST(empty,at_middle_link) {
    char str[15]="List Start";
    char str1[10]="zero";
    char str2[10]="first";
    char str3[10]="second";
    char str4[10]="third";
    char str5[10]="fourth";
    char str6[10]="fifth";
    int i;

    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  
    head->previous=NULL;
    head->next=NULL;
    head->data=str;
    head->index=0;

    i=add_to_list(head,str1);
    i=add_to_list(head,str2);
    i=add_to_list(head,str3);
    i=add_to_list(head,str4);
    i=add_to_list(head,str5);
    i=add_to_list(head,str6);
    printf("lists:\n");
    display_list(head);
    EXPECT_EQ(7, empty_list(head->next->next->next->next));
    printf("list after deleted:\n");
    display_list(head);
}
/***************************************************************************/
TEST(empty,single) {
    char str[15]="List Start";
    int i;

    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  
    head->previous=NULL;
    head->next=NULL;
    head->data=str;
    head->index=0;

    printf("lists:\n");
    display_list(head);
    EXPECT_EQ(1, empty_list(head));
    printf("list after deleted:\n");
    display_list(head);
}

/***************************************************************************/
TEST(empty,empty) {
    linked_list *head = NULL;  
    EXPECT_EQ(0, empty_list(head));
}


/***************************************************************************/
TEST(status, normal)
{
    char str[15]="List Start";
    char str1[10]="zero";
    char str2[10]="first";
    char str3[10]="second";
    char str4[10]="third";
    char str5[10]="fourth";
    char str6[10]="fifth";
    int i;
    int status;
    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  
    head->previous=NULL;
    head->next=NULL;
    head->data=str;
    head->index=0;

    i=add_to_list(head,str1);
    i=add_to_list(head,str2);
    i=add_to_list(head,str3);
    i=add_to_list(head,str4);
    i=add_to_list(head,str5);
    i=add_to_list(head,str6);
    status = linkedlist_status(head);
    EXPECT_EQ(7, status);
}
/***************************************************************************/
TEST(status, one_node) {
    char str[15]="List Start";
    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));
    int status;
    head->previous=NULL;
    head->next=NULL;
    head->data=str;
    head->index=0;
    status = linkedlist_status(head);
    EXPECT_EQ(1, status);

}
/***************************************************************************/
TEST(status, empty) {
    linked_list *h = NULL;
    EXPECT_EQ(0, linkedlist_status(h));

}