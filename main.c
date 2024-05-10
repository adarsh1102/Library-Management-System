#include <stdio.h>
#include <string.h>
#include <malloc.h>

struct book
{
    char name[30];
    char writer[30];
    int ID;
    struct book *next;
};

struct record
{
    char name[30];
    char gmail[20];
    char book[20];
    char a[30];
    int ID;
    struct record *next;
};

struct book *st=NULL;
struct record *start=NULL;
struct book *library(struct book *);
struct record *issue_of_book(struct record *);
struct record *return_of_book(struct record *);
struct book *delete(int);
struct book *add(char [],char [],int);
void display(struct record *);
void welcome();
void menu();
void display_library(struct book *);


int main()
{
    st=library(st);
    welcome();
    menu();
    return 0;
}

void welcome()
{
    printf("\n\n");
    printf("\t\t\t     ****************************************\n");
    printf("\t\t\t     *                                      *\n");
    printf("\t\t\t     *       ________________________       *\n");
    printf("\t\t\t     *             NMIMS LIBRARY            *\n");
    printf("\t\t\t     *       ________________________       *\n");
    printf("\t\t\t     *                                      *\n");
    printf("\t\t\t     *             NMIMS Campus             *\n");
    printf("\t\t\t     *        Navi Mumbai,Maharashtra       *\n");
    printf("\t\t\t     *                                      *\n");
    printf("\t\t\t     *        Contact no. : 9521468546      *\n");
    printf("\t\t\t     *                                      *\n");
    printf("\t\t\t     ****************************************\n");

}

void menu()
{
    int option;
    do
    {
        printf("\n\n");
        printf("\n\t\t\t   __________________________________________\n");
        printf("\n\t\t\t*\t\t MAIN MENU:                    *");
        printf("\n\t\t\t*\t\t1.ISSUE A BOOK                 *");
        printf("\n\t\t\t*\t\t2.RETURN A BOOK                *");
        printf("\n\t\t\t*\t\t3.RECORD OF ISSUERS            *");
        printf("\n\t\t\t*\t\t4.EXIT                         *");
        printf("\n\t\t\t   __________________________________________\n");
        printf("\n\t\t\t\t\t Enter your option: ");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
            {
                start=issue_of_book(start);
                break;
            }
            case 2:
            {
                start=return_of_book(start);
                break;
            }
            case 3:
            {
                display(start);
                break;
            }
            
        }
    }while(option!=4);
}

struct book *library(struct book *start)
{
    struct book *ptr,*book1,*book2,*book3,*book4,*book5;

    book1=(struct book *)malloc(sizeof(struct book));
    book1->next=NULL;
    st=book1;
    strcpy(book1->name,"Lord Of The Rings");
    strcpy(book1-> writer,"J.R.R. Tolkien");
    book1->ID=101;
    ptr=book1;

    book2=(struct book*)malloc(sizeof(struct book));
    book2->next=NULL;
    strcpy(book2->name,"Harry Potter");
    strcpy(book2-> writer,"J.K. Rowling");
    book2->ID=102;
    ptr->next=book2;
    ptr=book2;

    book3=(struct book*)malloc(sizeof(struct book));
    book3->next=NULL;
    strcpy(book3->name,"Geronimo Stilton");
    strcpy(book3-> writer,"Elisa-Betta Dami");
    book3->ID=103;
    ptr->next=book3;
    ptr=book3;

    book4=(struct book*)malloc(sizeof(struct book));
    book4->next=NULL;
    strcpy(book4->name,"To Kill A Mockingbird");
    strcpy(book4-> writer,"Harper Lee");
    book4->ID=104;
    ptr->next=book4;
    ptr=book4;

    book5=(struct book*)malloc(sizeof(struct book));
    book5->next=NULL;
    strcpy(book5->name,"Sherlock Holmes");
    strcpy(book5-> writer,"Arther Conan Doyle");
    book5->ID=105;
    ptr->next=book5;

    return st;
}



struct record *issue_of_book(struct record *start)
{
    struct book *ptr;
    struct record *ptr2,*new_student;
    int ID,k=0;
    
    if(st==NULL)
    {
        printf("\n\t\t\t\t Sorry !! no books left for issue ! \n\t\t\t\t\n");
    }
    else
    {
    
    display_library(st);
    
        printf("\n\n\t Enter the Book ID: ");
        scanf("%d",&ID);
    }    
        ptr=st;
        while(ptr!=NULL)
        {
            if(ptr->ID==ID)
            {
                k++;
                break;
            }
            ptr=ptr->next;
        }
        if(k==1)
        {
            
            new_student=(struct record *)malloc(sizeof(struct record));
            printf("\n\t Enter record Details:\n ");
            printf("\n\t Enter your Name: ");
            scanf("%s",new_student->name);
            printf("\n\t Enter your email: ");
            scanf("%s",new_student->gmail);
            strcpy(new_student->book,ptr->name);
            strcpy(new_student->a,ptr-> writer);
            new_student->ID=ptr->ID;
            new_student->next=NULL;
            
            printf("\n\t Book ( ID : %d ) is issued successfully!\n",new_student->ID);
            printf("\n\n\t__________________________________________\n");
            
            if(start==NULL)
            {
                start=new_student;
            }else
            {
                ptr2=start;
                while(ptr2->next!=NULL)
                {
                    ptr2=ptr2->next;
                }
                ptr2->next=new_student;
            }
            
            st=delete(new_student->ID);
            
        }
        
        else
        {
            printf("\n\t\t******Invalid Option!*******\n");
        }
        return start;
}

struct book *delete(int ID)
{
    struct book *ptr,*preptr;

    ptr=st;
    if(st->ID==ID)
    {
        ptr=st;
        st=st->next;
        free(ptr);
    }
    else
    {
        ptr=st;
        while(ptr->ID!=ID)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next=ptr->next;
        free(ptr);
    }
    return st;
}


void display_library(struct book *st)
{
    struct book *ptr;
    int i=1;
    
        ptr=st;
        printf("\n\n\n\t*************** Books Available: ****************\n");
        while(ptr!=NULL)
        {
            printf("\n\t_________________________________________________\n");
            printf("\n\t %d. Book Title : %s",i,ptr->name);
            printf("\n\t Author: %s",ptr-> writer);
            printf("\n\t Book ID: %d",ptr->ID);
            printf("\n\t_________________________________________________\n");
            ptr=ptr->next;
            i++;
        }

}

struct record *return_of_book(struct record *start)
{
    struct record *ptr,*preptr;
    char name_of_book[30], writername[30];
    int k=0,ID,val;
    
    if(start==NULL)
    {
        printf("\n\n\t\t\t************No book to return****************");
    }
    else
    {
    printf("\n\n\t*************** Books Submission ****************\n");
    printf("\n\n\t Enter your Book ID: ");
    scanf("%d",&val);
    
    ptr=start;
    while(ptr!=NULL)
    {
        if(ptr->ID==val)
        {
            k++;
            break;
        }
        ptr=ptr->next;
    }
    
    if(k==1)
    {
        ptr=start;
        if(ptr->ID==val)
        {
            printf("\n\t_________________________________________________\n");
            printf("\n\t Student Name: %s",start->name);
            printf("\n\t Student email: %s",start->gmail);
            printf("\n\t Name of Book Issued: %s",start->book);
            printf("\n\t_________________________________________________\n");
            printf("\n\n\t Return of Book ID %d done successfully!\n",val);
            printf("\n\n\t*************************************************\n");
            strcpy(name_of_book,start->book);
            strcpy(writername,start->a);
            ID=start->ID;
            start=start->next;
            free(ptr);
            add(name_of_book, writername,ID);
        }
        else
        {
            ptr=start;
            while(ptr->ID!=val)
            {
                preptr=ptr;
                ptr=ptr->next;
            }
            printf("\n\t_________________________________________________\n");
            printf("\n\t Student Name: %s",ptr->name);
            printf("\n\t Student email: %s",ptr->gmail);
            printf("\n\t Name of Book Issued: %s",ptr->book);
            printf("\n\t Book ID: %d",ptr->ID);
            printf("\n\t_________________________________________________\n");
            strcpy(name_of_book,ptr->book);
            strcpy(writername,ptr->a);
            ID=ptr->ID;
            preptr->next=ptr->next;
            free(ptr);
            add(name_of_book, writername,ID);
        }
        
        printf("\n\t\t Thank you!!! \n\t\t Visit again!!! ");

        
    }
    else
    {
        printf("\n\t\tOh Snap !! You entered the wrong ID !!");

    }
    }
    return start;
}

struct book *add(char name_of_book[30],char writername[30],int ID)
{
    struct book *ptr,*new_book;
    new_book=(struct book *)malloc(sizeof(struct book));
    strcpy(new_book->name,name_of_book);
    strcpy(new_book-> writer, writername);
    new_book->ID=ID;
    new_book->next=NULL;
    
    if(st==NULL)
    {
        st=new_book;
    }
    
    else
    {
        ptr=st;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=new_book;
    }
    
    return st;
}

void display(struct record *start)
{
    struct record *ptr;
    
    if(start==NULL)
    {
        printf("\n\n\n\t\t**************NO RECORD****************\n");
    }
    else
    {
    ptr=start;
        printf("\n\t************* Details of Students: **************\n\n");
        while(ptr!=NULL)
    {
        printf("\n\t_________________________________________________\n");
        printf("\n\t\t Student Name: %s",ptr->name);
        printf("\n\t\t Student email: %s",ptr->gmail);
        printf("\n\t\t Name of Book Issued: %s",ptr->book);
        printf("\n\t\t Book ID: %d",ptr->ID);
        printf("\n\t_________________________________________________\n");
        printf("\n\n\t*************************************************\n");
        ptr=ptr->next;
    }
    }
}


















