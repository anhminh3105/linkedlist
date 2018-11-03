# Linked List

This is a task of the Embedded System Programming course.

This repo contains the implementation of Linked List written in C.

### the structure of Linked List is as follow:
```
struct linked_list{
  char *data;
  int index; /* position of the element in the list, normally not used with Linked Lists, just for exercise */
  struct linked_list *next;
};
```
#### The master branch currently contains basic functions which satisfly the following requirements:
![image](https://user-images.githubusercontent.com/18170028/47956110-47fc0a80-dfa8-11e8-86c3-26c42d74bbf9.png)
