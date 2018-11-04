#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int add_to_list(linked_list *ll, char *s) {
	if (strlen(s) > 0) {
		linked_list *new_element = (struct linked_list*)malloc(sizeof(linked_list));
		new_element->data = s;	// assign s to the data of new node.
		new_element->next = NULL; // new node does not have reference to any node.
		if (ll == NULL) {
			new_element->previous = NULL;
			new_element->index = 0;
			ll = new_element;
			return ll->index;
		} 
		else {
			while (ll->next != NULL) ll = ll->next;
			new_element->previous = ll;
			new_element->index = ll->index + 1;
			ll->next = new_element;
			return new_element->index;
		}
	}  
	return -1;
}


int display_item(linked_list *ll) {
	if (ll != NULL) {	// ll should not be NULL
		printf("%d	%s\n", ll->index, ll->data);	// display node index and is data.
		return 0;	// return no error indication.
	} else return -1; // return error indication.
}

int display_list(linked_list *ll) {
	int display_cnt = 0;
	if (ll != NULL) { // ll should not be NULL
		if (ll->previous != NULL) while (ll->previous != NULL) ll = ll->previous;
		do {
			if (display_item(ll) == 0) 
				display_cnt++;
			ll = ll->next;
		} while (ll != NULL);
	return display_cnt;
	}
	return -1;
}

linked_list *search_from_list(linked_list *ll, char *s) {
	/*
		traverse amongst the nodes in linked_list to find and return the node which matches data s, 
		if not found this function return NULL.

		Arguments:
		*ll -- address of the 
	*/
	if (ll != NULL) {
		if (ll->previous != NULL) while (ll->previous != NULL) ll = ll->previous;
		while (ll != NULL) {
			int equal = strcmp(ll->data, s);
			if(equal == 0)
				return ll;
			ll = ll->next;

		}
	}
	return NULL;
}
int delete_from_list(linked_list *ll, int index) {
	if (ll != NULL && index >= 0) {
		linked_list *previous = NULL;
		linked_list *current = ll;
		while (current != NULL && current->index != index) {
			previous = current;
			current = current->next;
		}
		if (current != NULL) {
			if (index == 0) {
				previous = current;
				current = current->next;
				free(previous);
				if (current == NULL) return 1;
				else {
					current->index -= 1;
					current->previous = NULL;
				}
			} else {
				previous->next = current->next;
				free(current);
				current = previous;
			}
			while (current->next != NULL) {
				previous = current;
				current = current->next;
				current->index -= 1;	
				current->previous = previous;	
			}		
			return current->index + 1;
		} else return -1;
	} else return -1;
}
int empty_list(linked_list *ll)
{
	linked_list *previous;
	int free_cnt = 0;

	if (ll != NULL) {
		if (ll->previous != NULL) while (ll->previous != NULL) ll = ll->previous;
		while (ll != NULL) {
			ll = ll->next;
			previous = ll;
			free(previous);
			free_cnt++;
		}
		return free_cnt;
	}
	return -1;
}
int swap_items(linked_list *f, linked_list *s) {
	if (f != NULL && s != NULL) {
		linked_list *head1 = f;
		linked_list *head2 = s;
		if (head1->previous != NULL) while (head1->previous != NULL) head1 = head1->previous;
		if (head2->previous != NULL) while (head2->previous != NULL) head2 = head2->previous;
		if (head1 != head2) return -1;
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
		if (ll->previous != NULL) while (ll->previous != NULL) ll = ll->previous;
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