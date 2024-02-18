#include <stdio.h>
#include "StrList.h"
#include <stdlib.h>

// Node & List Data Structures
typedef struct _node {
    char _data;
    struct _node * _next;
} Node;


struct _StrList {
    Node* _head;
    size_t _size;
};

StrList* StrList_alloc(){
    StrList* p = (StrList*)malloc(sizeof(StrList));
	p->_head = NULL;
	p->_size = 0;
	return p;
}

void StrList_free(StrList* StrList){
    if (StrList == NULL){
        return;
    } 
	Node* p1 = StrList->_head;
	Node* p2;
	while(p1) {
		p2 = p1;
		p1 = p1->_next;
		Node_free(p2);
	}
	free(StrList);

}

size_t StrList_size(const StrList* StrList){
    return StrList->_size;

}

void StrList_insertLast(StrList* StrList, const char* data){

}

void StrList_insertAt(StrList* StrList, const char* data,int index){

}

char* StrList_firstData(const StrList* list){
    return *list->_head->_data;

}

void StrList_print(const StrList* StrList){
    const Node* p= StrList->_head;
	while(p) {
		printf("(%.2f)->",p->_data);
		p= p->_next;
	}
	printf("|| size:%zu\n",StrList->_size);
}

void StrList_printAt(const StrList* Strlist,int index){// hadar
	Node* p = Strlist->_head;
	for (int i = 0; i <= index; i++)
	{
		p->_next;
	}
	printf("(%.2f)->",p->_data);
}

int StrList_printLen(const StrList* Strlist){//hadar
Node* p = Strlist->_head;
char *str = Strlist->_head->_data;
int count = 0;
while (p!=NULL)
	{
		count += strlen(*str);
		p->_next;
		*str = p->_data;
	}
 return count;
}

int StrList_count(StrList* StrList, const char* data){//hadar
int count = 0;
Node* p = StrList->_head;
char *str = StrList->_head->_data;
while (p!=NULL)
	{
	if(strcmp(*str,data) == 0){
		count++;
	}
	p->_next;
	*str = p->_data;
	}
return count;
}

void StrList_remove(StrList* list, const char* data){//hadar
Node* p = list->_head->_next;
Node* prev = NULL;
char *str = list->_head->_data;
StrList* tmplist = list;
while (p!=NULL)
	{
	if(strcmp(*str,data) == 0){
		if (list == NULL) {
                // If the match is in the first node
                list->_head = p->_next;
        	}
		else {
             // If the match is in a subsequent node
            list->_head = p->_next;
            }

            // Free the memory allocated for the string
            free(p->_data);
            free(p);
	}
	p->_next;
	list->_head = list->_head->_next;
	*str = p->_data;
	}
	list->_head = tmplist;
}

void StrList_removeAt(StrList* list, int index){//hadar
Node* p = list->_head->_next;
Node* prev = NULL;
char *str = list->_head->_data;
StrList* tmplist = list;
for (int i = 0;i<=index;i++){
	if(i==index){
		if (list == NULL) {
                // If the match is in the first node
                list->_head = p->_next;
        	}
		else {
             // If the match is in a subsequent node
            list->_head = p->_next;
            }

            // Free the memory allocated for the string
            free(p->_data);
            free(p);
	}
	p->_next;
	list->_head = list->_head->_next;
	*str = p->_data;
	}
	list->_head = tmplist;
}

int StrList_isEqual(const StrList* StrList1, const StrList* StrList2){
    const int eq= 0;
	const int neq= 1;
	
	const Node* p1= StrList1->_head;
	const Node* p2= StrList2->_head;
	while(p1) {
		if (p2==NULL||p1->_data!=p2->_data) return neq;
		p1= p1->_next;
		p2= p2->_next;
	}
	if (p2!=NULL) return neq;
	return eq;
}

StrList* StrList_clone(const StrList* StringList){
    StrList*  ret = StrList_alloc();
	const Node* old= StringList->_head;
	Node* * copy = &(ret->_head);
	ret->_size= StringList->_size;
	while(old) {
		*copy= Node_alloc(old->_data,NULL);
		old= old->_next;
		copy= &((*copy)->_next);
	}
	return ret;

}

void StrList_reverse( StrList* StrList){

}

void StrList_sort( StrList* StrList){

}

int StrList_isSorted(StrList* StrList){

}



