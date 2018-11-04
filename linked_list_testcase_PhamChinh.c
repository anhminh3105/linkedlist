#include <gtest/gtest.h>
#include "linked_list.h"

/***************************************************************************/
TEST(AddToList, normal) {
	char str[15] = "First";
	char str1[10] = "Second";
	char str2[20] = "third";

	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));
	head->next = NULL;
	head->previous = NULL;
	head->data = str;
	head->index = 0;
	int index;

	index = add_to_list(head, str1);
	EXPECT_EQ(1, index);
	index = add_to_list(head, str2);
	EXPECT_EQ(2, index);
}

TEST(AddToList, special_character) {
	char str[15] = "&First %#?";
	char str1[10] = "Second å";
	char str2[20] = "third {([ ])}";

	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));
	head->next = NULL;
	head->previous = NULL;
	head->data = str;
	head->index = 0;
	int index;

	index = add_to_list(head, str1);
	EXPECT_EQ(1, index);
	index = add_to_list(head, str2);
	EXPECT_EQ(2, index);
}

TEST(AddToList, empty_string) {
	char str[15];
	char str1[10] = "Second å";
	char str2[20];

	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));
	head->next = NULL;
	head->previous = NULL;
	head->data = str;
	head->index = 0;
	int index;

	index = add_to_list(head, str1);
	EXPECT_EQ(1, index);
	index = add_to_list(head, str2);
	EXPECT_EQ(2, index);
}

TEST(DisplayItem, normal) {
	char str[15] = "List Start";

	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));

	head->next = NULL;
	head->previous = NULL;
	head->data = str;
	head->index = 0;

	EXPECT_EQ(0, display_item(head));
	EXPECT_STREQ(head->data, str);
}

TEST(DisplayItem, special_character) {
	char str[15] = "&First %#?";
	char str1[10] = "Second å";
	char str2[20] = "third {([ ])}";

	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));
	head->next = NULL;
	head->previous = NULL;
	head->data = str;
	head->index = 0;

	add_to_list(head, str1);
	add_to_list(head, str2);

	EXPECT_EQ(0, display_item(head->next->next));
	EXPECT_STREQ(head->next->next->data, str2);
}

TEST(DisplayItem, item_not_found) {
	char str[15] = "&First %#?";
	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));
	head->next = NULL;
	head->previous = NULL;
	head->data = str;
	head->index = 0;

	EXPECT_EQ(-1, display_item(head->next));
}

TEST(DisplayList, normal) {
	char str[15] = "List Start";
	char str1[10] = "zero";
	char str2[10] = "first";
	char str3[10] = "second";
	int index;

	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));

	head->next = NULL;
	head->previous = NULL;
	head->data = str;
	head->index = 0;

	index = add_to_list(head, str1);
	index = add_to_list(head, str2);
	index = add_to_list(head, str3);

	EXPECT_EQ(4, display_list(head));
}

TEST(DisplayList, special_character) {
	char str[20] = "List Start {}()[]";
	char str1[15] = "zero ABC #¤";
	char str2[10] = "first?+´+";
	char str3[10] = "second å";
	int index;

	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));

	head->next = NULL;
	head->previous = NULL;
	head->data = str;
	head->index = 0;

	index = add_to_list(head, str1);
	index = add_to_list(head, str2);
	index = add_to_list(head, str3);

	EXPECT_EQ(4, display_list(head));
}

TEST(DisplayList, empty_list) {
	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));
	head = NULL;

	EXPECT_EQ(-1, display_list(head));
}

TEST(SearchFromList, normal)
{
	char str[15] = "List Start";
	char str1[15] = "second";
	char str2[15] = "third";

	linked_list *found;
	linked_list *head;

	head = (struct linked_list*) malloc(sizeof(linked_list));
	head->next = NULL;
	head->previous = NULL;
	head->data = str;
	head->index = 0;

	add_to_list(head, str1);
	add_to_list(head, str2);

	found = search_from_list(head, (char *)"third");

	EXPECT_EQ(found->index, 2);
	EXPECT_STREQ(str2, found->data);
}

TEST(SearchFromList, special_character)
{
	char str[20] = "List Start ?1!#";
	char str1[15] = "?+0* ";
	char str2[15] = "third_";

	linked_list *found;
	linked_list *head;

	head = (struct linked_list*) malloc(sizeof(linked_list));
	head->next = NULL;
	head->previous = NULL;
	head->data = str;
	head->index = 0;

	add_to_list(head, str1);
	add_to_list(head, str2);

	found = search_from_list(head, (char *)"?+0* ");

	EXPECT_EQ(found->index, 1);
	EXPECT_STREQ(str1, found->data);
}

TEST(SearchFromList, not_found)
{
	char str[15] = "List Start";

	linked_list *found;

	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));

	head->next = NULL;
	head->previous = NULL;
	head->data = str;
	head->index = 0;

	found = search_from_list(head, (char *)"something");

	EXPECT_EQ((int *)found, (int *)NULL);
}

TEST(DeleteFromList, normal)
{
	char str[15] = "This ";
	char str1[10] = "Is ";
	char str2[10] = "A ";
	char str3[10] = "Test ";
	char str4[10] = "For ";
	char str5[10] = "Delete ";
	char str6[10] = "Function ";
	int i;

	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));

	head->next = NULL;
	head->previous = NULL;
	head->data = str;
	head->index = 0;

	i = add_to_list(head, str1);
	i = add_to_list(head, str2);
	i = add_to_list(head, str3);
	i = add_to_list(head, str4);
	i = add_to_list(head, str5);
	i = add_to_list(head, str6);

	EXPECT_EQ(6, delete_from_list(head, 2));
	EXPECT_EQ(head->next->next->index, 2);
	EXPECT_STREQ(head->next->next->data, str3);
	EXPECT_EQ(head->next->next->next->next->index, 4);
	EXPECT_STREQ(head->next->next->next->next->data, str5);
}

TEST(DeleteFromList, index_not_found)
{
	char str[15] = "This ";
	char str1[10] = "Is ";
	char str2[10] = "A ";
	char str3[10] = "Test ";
	char str4[10] = "For ";
	char str5[10] = "Delete ";
	char str6[10] = "Function ";
	int i;

	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));

	head->next = NULL;
	head->previous = NULL;
	head->data = str;
	head->index = 0;

	i = add_to_list(head, str1);
	i = add_to_list(head, str2);
	i = add_to_list(head, str3);
	i = add_to_list(head, str4);
	i = add_to_list(head, str5);
	i = add_to_list(head, str6);

	EXPECT_EQ(-1, delete_from_list(head, 10));
}

TEST(DeleteFromList, delete_head_element)
{
	char str[15] = "This ";
	char str1[10] = "Is ";
	char str2[10] = "A ";
	char str3[10] = "Test ";
	char str4[10] = "For ";
	char str5[10] = "Delete ";
	char str6[10] = "Function ";
	int i;

	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));

	head->next = NULL;
	head->previous = NULL;
	head->data = str;
	head->index = 0;

	i = add_to_list(head, str1);
	i = add_to_list(head, str2);
	i = add_to_list(head, str3);
	i = add_to_list(head, str4);
	i = add_to_list(head, str5);
	i = add_to_list(head, str6);

	linked_list *temp = head->next;
	int result = delete_from_list(head, 0);
	head = temp;
	EXPECT_EQ(6, result);
	EXPECT_EQ(head->index, 0);
	EXPECT_STREQ(head->data, str1);
	EXPECT_EQ((int *)head->previous, (int *)NULL);
	EXPECT_EQ(head->next->next->index, 2);
	EXPECT_STREQ(head->next->next->data, str3);
	display_list(head);
}

TEST(DeleteFromList, delete_last_element)
{
	char str[15] = "This ";
	char str1[10] = "Is ";
	char str2[10] = "A ";
	char str3[10] = "Test ";
	char str4[10] = "For ";
	char str5[10] = "Delete ";
	char str6[10] = "Function ";
	int i;

	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));

	head->next = NULL;
	head->previous = NULL;
	head->data = str;
	head->index = 0;

	i = add_to_list(head, str1);
	i = add_to_list(head, str2);
	i = add_to_list(head, str3);
	i = add_to_list(head, str4);
	i = add_to_list(head, str5);
	i = add_to_list(head, str6);

	EXPECT_EQ(6, delete_from_list(head, 6));
	EXPECT_EQ((int *)head->next->next->next->next->next->next, (int *)NULL);
}

TEST(EmptyList, normal) {
	char str[15] = "This ";
	char str1[10] = "Is ";
	char str2[10] = "A ";
	char str3[10] = "Test ";
	char str4[10] = "For ";
	char str5[10] = "Empty ";
	char str6[10] = "Function ";
	int i;

	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));

	head->next = NULL;
	head->previous = NULL;
	head->data = str;
	head->index = 0;

	i = add_to_list(head, str1);
	i = add_to_list(head, str2);
	i = add_to_list(head, str3);
	i = add_to_list(head, str4);
	i = add_to_list(head, str5);
	i = add_to_list(head, str6);
	EXPECT_EQ(7, empty_list(head));
}

TEST(EmptyList, empty_empty_list) {
	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));
	head = NULL;
	EXPECT_EQ(-1, empty_list(head));
}

TEST(EmptyList, middle_node) {
	char str[15] = "This ";
	char str1[10] = "Is ";
	char str2[10] = "A ";
	char str3[10] = "Test ";
	char str4[10] = "For ";
	char str5[10] = "Empty ";
	char str6[10] = "Function ";
	int i;

	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));

	head->next = NULL;
	head->previous = NULL;
	head->data = str;
	head->index = 0;

	i = add_to_list(head, str1);
	i = add_to_list(head, str2);
	i = add_to_list(head, str3);
	i = add_to_list(head, str4);
	i = add_to_list(head, str5);
	i = add_to_list(head, str6);
	EXPECT_EQ(7, empty_list(head->next->next));
}

TEST(SwapItem, normal) {
	char str[15] = "This ";
	char str1[10] = "Is ";
	char str2[10] = "A ";
	char str3[10] = "Test ";
	char str4[10] = "For ";
	char str5[20] = "Swap Item ";
	char str6[10] = "Function ";
	int i;

	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));

	head->next = NULL;
	head->previous = NULL;
	head->data = str;
	head->index = 0;

	i = add_to_list(head, str1);
	i = add_to_list(head, str2);
	i = add_to_list(head, str3);
	i = add_to_list(head, str4);
	i = add_to_list(head, str5);
	i = add_to_list(head, str6);

	EXPECT_EQ(swap_items(head->next->next, head->next), 0);
	EXPECT_EQ(head->next->next->index, 2);
	EXPECT_STREQ(head->next->next->data, str1);
	EXPECT_EQ(head->next->index, 1);
	EXPECT_STREQ(head->next->data, str2);
}

TEST(SwapItem, outsider) {
	char str[15] = "This ";
	char str1[10] = "Is ";
	char str2[10] = "A ";
	char str3[10] = "Test ";
	char str4[10] = "For ";
	char str5[20] = "Swap Item ";
	char str6[10] = "Function ";
	int i;

	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));

	head->next = NULL;
	head->previous = NULL;
	head->data = str;
	head->index = 0;

	i = add_to_list(head, str1);
	i = add_to_list(head, str2);
	i = add_to_list(head, str3);
	i = add_to_list(head, str4);
	i = add_to_list(head, str5);
	i = add_to_list(head, str6);

	linked_list *other = (struct linked_list*) malloc(sizeof(linked_list));
	other->next = NULL;
	head->previous = NULL;
	other->data = str;
	other->index = 0;
	i = add_to_list(other, str5);

	EXPECT_EQ(swap_items(other->next, head->next), -1);
	EXPECT_EQ(head->next->index, 1);
	EXPECT_STREQ(head->next->data, str1);
	EXPECT_EQ(other->next->index, 1);
	EXPECT_STREQ(other->next->data, str5);
}

TEST(SwapItem, swap_null) {
	char str[15] = "This ";
	char str1[10] = "Is ";
	char str2[10] = "A ";
	char str3[10] = "Test ";
	char str4[10] = "For ";
	char str5[20] = "Swap Item ";
	char str6[10] = "Function ";
	int i;

	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));

	head->next = NULL;
	head->previous = NULL;
	head->data = str;
	head->index = 0;

	i = add_to_list(head, str1);
	i = add_to_list(head, str2);
	i = add_to_list(head, str3);
	i = add_to_list(head, str4);
	i = add_to_list(head, str5);
	i = add_to_list(head, str6);

	EXPECT_EQ(swap_items(head->next->next->next->next->next->next->next, head->next), -1);
	EXPECT_EQ((int *)head->next->next->next->next->next->next->next, (int *)NULL);
	EXPECT_EQ(head->next->index, 1);
	EXPECT_STREQ(head->next->data, str1);
}

TEST(SortList, normal)
{
	char str[15] = "This ";
	char str1[10] = "Is ";
	char str2[10] = "A ";
	char str3[10] = "Test ";
	char str4[10] = "For ";
	char str5[20] = "Sort List ";
	char str6[10] = "Function ";
	int i;

	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));

	head->next = NULL;
	head->previous = NULL;
	head->data = str;
	head->index = 0;

	i = add_to_list(head, str1);
	i = add_to_list(head, str2);
	i = add_to_list(head, str3);
	i = add_to_list(head, str4);
	i = add_to_list(head, str5);
	i = add_to_list(head, str6);

	sort_list(head);

	EXPECT_STREQ(head->data, str2);
	EXPECT_STREQ(head->next->data, str4);
	EXPECT_STREQ(head->next->next->data, str6);
	EXPECT_STREQ(head->next->next->next->data, str1);
	EXPECT_STREQ(head->next->next->next->next->data, str5);
	EXPECT_STREQ(head->next->next->next->next->next->data, str3);
	EXPECT_STREQ(head->next->next->next->next->next->next->data, str);
	display_list(head);
}

TEST(SortList, empty_list)
{
	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));
	head = NULL;
	sort_list(head);

	EXPECT_EQ(-1, sort_list(head));
}

TEST(SortList, special_character)
{
	char str[15] = "!# This ()";
	char str1[10] = "+ -*/Is ";
	char str2[10] = "A BCD";
	char str3[10] = "&Test* ";
	char str4[10] = "&%¤For ";
	char str5[20] = "!§½Sort List ";
	char str6[15] = "/Function ";
	int i;

	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));

	head->next = NULL;
	head->previous = NULL;
	head->data = str;
	head->index = 0;

	i = add_to_list(head, str1);
	i = add_to_list(head, str2);
	i = add_to_list(head, str3);
	i = add_to_list(head, str4);
	i = add_to_list(head, str5);
	i = add_to_list(head, str6);

	sort_list(head);

	EXPECT_STREQ(head->data, str);
	EXPECT_STREQ(head->next->data, str5);
	EXPECT_STREQ(head->next->next->data, str4);
	EXPECT_STREQ(head->next->next->next->data, str3);
	EXPECT_STREQ(head->next->next->next->next->data, str1);
	EXPECT_STREQ(head->next->next->next->next->next->data, str6);
	EXPECT_STREQ(head->next->next->next->next->next->next->data, str2);
	display_list(head);
}

TEST(Status, normal) {
	char str[15] = "This ";
	char str1[10] = "Is ";
	char str2[10] = "A ";
	char str3[10] = "Test ";
	char str4[10] = "For ";
	char str5[20] = "Status ";
	char str6[10] = "Function ";
	int i;

	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));

	head->next = NULL;
	head->previous = NULL;
	head->data = str;
	head->index = 0;

	i = add_to_list(head, str1);
	i = add_to_list(head, str2);
	i = add_to_list(head, str3);
	i = add_to_list(head, str4);
	i = add_to_list(head, str5);
	i = add_to_list(head, str6);

	EXPECT_EQ(7, linkedlist_status(head));
}

TEST(Status, middle_list) {
	char str[15] = "This ";
	char str1[10] = "Is ";
	char str2[10] = "A ";
	char str3[10] = "Test ";
	char str4[10] = "For ";
	char str5[20] = "Status ";
	char str6[10] = "Function ";
	int i;

	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));

	head->next = NULL;
	head->previous = NULL;
	head->data = str;
	head->index = 0;

	i = add_to_list(head, str1);
	i = add_to_list(head, str2);
	i = add_to_list(head, str3);
	i = add_to_list(head, str4);
	i = add_to_list(head, str5);
	i = add_to_list(head, str6);

	EXPECT_EQ(7, linkedlist_status(head->next->next));
}

TEST(Status, empty_list) {
	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));
	head = NULL;

	EXPECT_EQ(-1, linkedlist_status(head));
}