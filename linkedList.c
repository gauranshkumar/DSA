#include<stdio.h>
#include<stdlib.h>
// Creating Node Structure
struct Node{
  int val;
  struct Node* next;
};


// Inserting Node at Beginning of The List
void insertAtBegin(struct Node** head, int n){
  struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
  temp->val = n;
  temp->next = *head;
  *head = temp;
}

//Inserting Node at Ending of List
void insertAtEnd(struct Node** head, int n){
  struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
  struct Node*temp2 = *head;
  temp->val = n;
  temp->next = NULL;
  if(*head == NULL){
    *head = temp;
  }
  else{
  while(temp2->next != NULL){
    temp2 = temp2->next;
  }
  temp2->next=temp;
}
}


//Insert at Nth Position in list
//This function covers both the Scenarion of Inserting at
//beginning and ar end.
int insertAtN(struct Node** head, int val, int loc){
  struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
  temp->val = val;
  if(*head == NULL){
    temp->next = NULL;
    *head = temp;
    return 1;
  }
  else if(loc == 0){
    insertAtBegin(head,val);
    return 1;
  }
  else{
    int count=1;
    struct Node* temp2 = *head;
    while(temp2->next != NULL){
      if(count == loc){
        temp->next = temp2->next;
        temp2->next = temp;
        return 1;
      }
      temp2 = temp2->next;
      count++;
    }
    if((loc == count) && (temp2->next == NULL)){
      insertAtEnd(head,val);
      return 1;
    }
  }

  return -1;
}


//Deletion from Beginning
int deleteFromBeg(struct Node** head){
  if(*head == NULL){
    return -1;
  }
  else{
    struct Node* temp = *head;
    int r;
    *head = temp->next;
    r = temp->val;
    free(temp);
    return r;
  }
}


//Deletion From End
int deleteFromEnd(struct Node** head){
  if(*head==NULL){
    return -1;
  }
  else{
    struct Node* temp = *head;
    while(temp->next->next != NULL){
      temp = temp->next;
    }
    int r = temp->next->val;
    free(temp->next);
    temp->next = NULL;
    return r;
  }
}

//Deletion From Nth position including both cases
//Beginning and End.
int deleteFromN(struct Node** head, int loc){
  if(*head == NULL){
    return -1;
  }
  else if(loc == 0){
    return deleteFromBeg(head);
  }
  else{
    int count = 0;
    struct Node* temp = *head;
    while(temp->next != NULL){
      if(count == loc-1){
        int r = temp->next->val;
        struct Node* temp2 = temp->next;
        temp->next = temp->next->next;
        free(temp2);
        return r;
      }
      temp = temp->next;
      count++;
    }
    if((count == loc) && (temp->next == NULL)){
      return deleteFromEnd(head);
    }
  }
  return -1;
}

// Search function to find an Element in List
int Search(struct Node* head, int data){
  int count = 0;
  while(head != NULL){
    if(data == head->val){
      return count;
    }
    head = head->next;
    count++;
  }
  return -1;
}

//Traversing the list
void traverse(struct Node* head){
  while(head != NULL){
    printf("%d\t",head->val);
    head = head->next;
  }
}

int main(){
  int i,size,n,option;
  struct Node* head =  NULL;
  printf("\n============= LINKED LIST OPERATIONS ================\n");
  printf("Enter the Size of Intitial List : ");
  scanf("%d",&size);
  printf("Enter the elements : ");
  for(i=0;i<size;i++){
    scanf("%d", &n);
    insertAtEnd(&head, n);
  }
  while(1){
    printf("\n1. Insert an Elment at Beginning of List\n");
    printf("\n2. Insert an Elment at End of List\n");
    printf("\n3. Insert an Elment at Nth position in List\n");
    printf("\n4. Delete an Elment at Beginning of List\n");
    printf("\n5. Delete an Elment at End of List\n");
    printf("\n6. Delete an Nth Elment of List\n");
    printf("\n7. Search an Element in List\n");
    printf("\n8. Print the List\n");
    printf("\n9. Quit\n");
    scanf("%d",&option);
    switch(option){
      case 1:
        printf("\nEnter Element to Insert : ");
        scanf("%d",&n);
        insertAtBegin(&head,n);
        printf("Inserted %d in List and New List is :\n",n);
        traverse(head);
        break;

      case 2:
        printf("\nEnter Element to Insert : ");
        scanf("%d",&n);
        insertAtEnd(&head,n);
        printf("Inserted %d in List and New List is :\n",n);
        traverse(head);
        break;

      case 3:
        printf("\nEnter Element and Location : ");
        scanf("%d%d",&n, &i);
        int tmp = insertAtN(&head,n,i);
        if(tmp == -1){
          printf("\nLocation Out Of Bound.\n");
        }
        else{
        printf("\n%d is inserted at %d in List and New List is :\n",n,i);
        traverse(head);
        }
        break;

      case 4:
        n = deleteFromBeg(&head);
        if(n== -1){
          printf("Deletion Not Possible.");
        }
        else{
          printf("\nDeleted Element : %d\nNew List is : \n",n);
          traverse(head);
        }
        break;

      case 5: 
        n = deleteFromEnd(&head);
        if(n== -1){
          printf("\nDeletion Not Possible.\n");
        }
        else{
          printf("\nDeleted Element : %d\nNew List is : \n",n);
          traverse(head);
        }
        break;

      case 6:
        printf("\nEnter Position to Delete : ");
        scanf("%d",&i);
        n = deleteFromN(&head,i);
        if(n== -1){
          printf("Deletion Not Possible.");
        }
        else{
          printf("\nDeleted Element : %d\nNew List is : \n",n);
          traverse(head);
        }
        break;

      case 7:
        printf("\nEntet Element to search : ");
        scanf("%d",&n);
        i = Search(head, n);
        if(i == -1){
          printf("\nElement Not Found in the List\n");
        }
        else{
          printf("\nElement is present at : %d",i);
        }
        break;

      case 8:
        printf("\nThe List is : \n");
        traverse(head);
        break;

      case 9:
        exit(0);

      default:
        exit(0);

    }
  }
  return 0;
}
