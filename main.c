#include <stdio.h>
#include "StrList.h"
#include "StrList.c"
#include <string.h>
#include <stdlib.h>
#define SIZE 10000

int main(){
    StrList* StrList = StrList_alloc(); //Creating a new list.
    int input;
    int index;
    char word[1000];

    do{
        scanf(" %d", &input);
        switch (input)
        {
        case 1:
            scanf("%d", &input);
            //Node* p = StrList->_head;
            for(int i = 1;i <= input;i++){
                if(scanf("%s",word)>=0){
                    StrList_insertLast(StrList, word);
                    printf("the new node data  is %s:\n", StrList->_head->_data);
                }
            }
            printf("this is the head of the list %s:\n", StrList->_head->_data);
            break;

        case 2:
            scanf(" %d", &index);
            char words[50];
            for(int i = 0;i < input;i++){
                if(scanf("%s",words)>=0){
                    StrList_insertAt(StrList,words,index);
                }
                index++;
            }
            
            break;

        case 3:
            StrList_print(StrList);
            break;

        case 4:
            StrList_size(StrList);
            break;

        case 5:
            scanf(" %d", &index);
            StrList_printAt(StrList,index);    
            break;


        case 6:
            StrList_printLen(StrList);    
            break;


        case 7:
            scanf("%s", word);
            StrList_count( StrList,word);     
            break;


        case 8:
            scanf("%s", word);
            StrList_remove(StrList,word);    
            break;


        case 9:
            scanf(" %d", &index);
            StrList_removeAt(StrList,index);    
            break;


        case 10:
            StrList_reverse(StrList);    
            break;


        case 11:
            StrList_free(StrList);    
            break;


        case 12:
            StrList_sort(StrList);   
            break;


        case 13:
            StrList_isSorted(StrList);    
            break;

        case 0:
            StrList_free(StrList);
            return 0;
            break;
            
        default:
            return 0;
            break;
        } 
    }while(input!=0);
    
return 0;
}