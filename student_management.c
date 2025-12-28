/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student 
{
    int roll_no;
    char name[50];
    float marks;
    struct student *link;
};
struct student *head=NULL;
struct student *createnode(int roll_no, char name[], float marks)
{
    struct student *newnode=(struct student *)malloc(sizeof(struct student));
    if(newnode==NULL)
    {
        printf("\nMemory allocation not possible\n");
        exit(0);
    }
    newnode->roll_no=roll_no;
    strcpy(newnode->name,name);
    newnode->marks=marks;
    newnode->link=NULL;
    return newnode;
    
}
void insertatend(int roll_no, char name[], float marks)
{
    struct student *newnode=createnode(roll_no,name,marks);
    struct student *current=head;
    if(head==NULL)
    {
        head=newnode;
        return;
    }
    while(current->link!=NULL)
    {
        current=current->link;
    }
    current->link=newnode;
}
void deletebykey(int roll_no)
{
    struct student *current=head->link;
    struct student *prev=head;
    if(current==NULL)
    {
        printf("\nDeletion not possible, key not found\n");
    }
    while(current!=NULL&& current->roll_no!=roll_no)
    {
        prev=current;
        current=current->link;
    }
    prev->link=current->link;
    printf("\nStudent with roll number %d is deleted\n", current->roll_no);
    free(current);
}
struct student *searchbykey(int roll_no)
{
    struct student *current=head;
    while(current!=NULL)
    {
        if(current->roll_no==roll_no)
           return current; 
        current=current->link;
    }
}
void display()
{
    int i=1;
    struct student *current=head;
    if(current==NULL)
    {
        printf("\nThe list is empty, student details is not available\n");
        return ;
    }
    while(current!=NULL)
    {
        printf("\nStudent details as follows:\n");
        printf("\nStudent %d", i);
        printf("\nRoll number : %d", current->roll_no);
        printf("\nName : %s", current->name);
        printf("\nMarks : %f", current->marks);
        current=current->link;
        i++;
    }
}
void freelist()
{
    struct student *current=head->link;
    struct student *next;
    while(current!=NULL)
    {
        next=current->link;
        free(current);
        current=next;
    }
}
int main()
{
    int choice, roll_no, n;
    char name[50];
    float marks;
    printf("---Student Management System---\n");
    printf("\nEnter the size of the student list:");
    scanf("%d", &n);
    printf("\nEnter %d student details:\n", n);
    for(int i=1;i<=n;i++)
    {
        printf("\nStudent details %d:\n", i);
        printf("Student roll number: ");
        scanf("%d", &roll_no);
        printf("Student name: ");
        scanf("%s", name);
        printf("Student marks: ");
        scanf("%f", &marks);
        insertatend(roll_no,name,marks);
    }
    while(1)
    {
        printf("\nMenu:\n1. Insert student details\n2. Delete student details\n3. Search student details\n4. Display the student details\n5. Exit\n");
        printf("Enter the choice:");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:{
                printf("\nEnter the student details:\n");
                printf("Student roll number:");
                scanf("%d", &roll_no);
                printf("Student name:");
                scanf("%s", name);
                printf("Student marks:");
                scanf("%f", &marks);
                insertatend(roll_no,name,marks);
            }
            break;
            case 2:{
                printf("\nEnter the roll number to delete the student details:\n");
                scanf("%d", &roll_no);
                deletebykey(roll_no);
            }
            break;
            case 3:{
                printf("\nEnter the roll number to search for a particular student details:\n");
                scanf("%d", &roll_no);
                struct student *s=searchbykey(roll_no);
                if(s!=NULL)
                {
                    printf("\n---Student found---\n");
                    printf("Student roll number: %d", s->roll_no);
                    printf("\nStudent name: %s", s->name);
                    printf("\nStudent marks: %f", s->marks);
                }
                else
                {
                    printf("\nNot able to find the student details:");
                }
            }
            break;
            case 4:display();
            break;
            case 5:{
                printf("Exiting program\n");
                exit(0);
            }
            break;
            default:{
                printf("\nInvalid choice\n");
                return 0;
            }
        }


    }
}