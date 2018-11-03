#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int add_to_list(linked_list *ll, char *s) {
	if (ll != NULL && s != NULL) {	// ll should not be NULL and s should have a value to add to next element of ll.
		if (ll->next == NULL) {
			linked_list *new_element = (struct linked_list*)malloc(sizeof(linked_list));	// allocate memory for a new link to append to ll.
			new_element->data = s;	// assign s to the data of new_element.
			int inx = ll->index + 1;
			new_element->index = inx;
			new_element->next = NULL; // new_element does not have any link.
			ll->next = new_element;
			return inx;
		} else return add_to_list(ll->next, s);
	} else return -1;
}
int display_item(linked_list *ll) {
	if (ll != NULL) {
		printf("%d	%s\n", ll->index, ll->data);
		return 0;
	} else return -1;
}
int display_list(linked_list *ll) {
	if (ll != NULL) {
		display_item(ll);
		if (ll->next == NULL) {
			return ll->index + 1;
		} else return display_list(ll->next);
	} else return 0;
}
linked_list *search_from_list(linked_list *ll, char *s) {
	if (ll != NULL) {
		int equal = strcmp(ll->data, s);
		if(equal == 0) {
			return ll;
		} else if (ll->next == NULL) return NULL;
		else return search_from_list(ll->next, s);
	} else return NULL;
}
int delete_from_list(linked_list *ll, int index) {
	if (ll != NULL || index < 0) {
		linked_list *previous = ll;
		linked_list *current = ll;
		while (current != NULL && current->index != index) {
			previous = current;
			current = current->next;
		}
		if (current != NULL) {
			previous->next = current->next;
			current = previous;
			while (current->next != NULL) {
				current = current->next;
				current->index -= 1;
			}
			return current->index + 1;
		} else return -1;
	} else return -1;
}
int empty_list(linked_list *ll)
{
	if (ll != NULL) {
		linked_list *next = ll->next;
		free(ll);
		if (ll->next == NULL) return 1;
		else return empty_list(next) + 1;
	} else return 0;
}
int swap_items(linked_list *f, linked_list *s) {
	if (f != NULL && s != NULL) {
		char *tmp;
		tmp = f->data;
		f->data = s->data;
		s->data = tmp;
		return 0;
	} else return -1;
}
int sort_list(linked_list *ll)
{
	if (ll != NULL) {
		linked_list *i, *j;
		for (i = ll; i->next != NULL; i = i->next) {
			for (j = i->next; j != NULL; j = j->next) {
				if (strcmp(i->data, j->data) > 0) {
					swap_items(i, j);
				}
			}
		}
		return 0;
	} else return -1;
}

int linkedlist_status(linked_list *ll) {
	if(ll) {
		fflush(stdout);
		if (ll->next == NULL) return ll->index + 1;
		else return linkedlist_status(ll->next);
	} else return 0;
}