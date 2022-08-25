#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node
{
    char co[ 20 ] ;
    char c[ 5 ] [ 20 ] ;
    char m[5][20];
    char p [5][20];
    int ccount ;
    int mcount;
    int pcount;
    struct node * link ;
} ;

struct node * clo[ 26 ] ;
int j=-1;
void insertcloth( char * ) ;
void search( char * ) ;
void show( ) ;
void removecloth();

int main( )
{
    char cloth[ 20 ]  ;
    char n[20];
    int i,ch;
    while ( 1 )
    {
        printf("\n\t\t.******.\n");
        printf ( "\n\t\tCloset organizer\n" ) ;
        printf ( "\n\t\t1.insert cloth details\n" ) ;
        printf ( "\t\t2.search for your cloth position.\n" ) ;
        printf ( "\t\t3.show wardrobe.\n" ) ;
        printf("\t\t4.Remove the cloth from your war drobe\n");
        printf ( "\t\t5.Exit." ) ;
        printf("\n\t\t**************.\n");
        printf ( "\n\n\t\tEnter your Your Choice ") ;
        scanf ( "%d", &ch ) ;


        switch ( ch )
        {
            case 1 :
			    printf ( "\nEnter cloth name : " ) ;
                fflush ( stdin ) ;
                gets ( cloth ) ;
                insertcloth (cloth ) ;
                break ;

            case 2 :
			     printf ( "\nEnter the cloth name to  search : " ) ;
                 scanf("%s",cloth);
                 search( cloth ) ;
                 getch( ) ;
                 break ;

            case 3 :
                show( ) ;
                getch( ) ;
				break ;

            case 4 :
                  printf("\t\tEnter the cloth name to delete\t\t");
                  scanf("%s",cloth);
                  removecloth(cloth);
                  getch();
				  break;
				  
            case 5:
                exit(0);

            default :
			printf ( "\nWrong Choice" ) ;
        }
    }
}

void insertcloth ( char * str )
{
    int i;
    j++;
    struct node * r, * temp = clo [ j ], * q ;
    char col [ 5 ] [ 20 ], ch = 'y' ;
    char m[5][20], ch2='y';
    char p [5][20] , ch3='y';

    q = ( struct node * ) malloc ( sizeof ( struct node ) ) ;
    strcpy ( q -> co, str ) ;
    q -> link = NULL ;

    for ( i = 0 ; tolower ( ch ) == 'y' && i < 5 ; i++ )
    {

        fflush ( stdin ) ;
        printf ( "\n\nEnter the colour of the cloth : " ) ;
        gets ( col [ i ] ) ;
        strcpy ( q -> c[ i ] , col[ i ] ) ;
        if ( i != 4 )
        {
           printf ( "add hint about colour of the cloth (y/n) " ) ;
            ch = getche( ) ;
        }
        else
        printf ( "You cannot enter more than 5 hint about colour." ) ;
        fflush ( stdin ) ;

    }

    q -> ccount = i ;

    for ( i = 0 ; tolower ( ch2 ) == 'y' && i < 5 ; i++ )
    {
        fflush ( stdin ) ;
        printf ( "\n\nEnter material of the cloth : " ) ;
        gets (  m[ i ] ) ;
        strcpy ( q -> m [ i ] , m [ i ] ) ;
        if ( i != 4 )
        {
            printf ( "\nAdd more hint about the material (y/n) " ) ;
            ch2 = getche( ) ;
        }
        else
            printf ( "You cannot enter the more than 5 hint about material" ) ;

        fflush ( stdin ) ;

    }
    q -> mcount = i ;
    for ( i = 0 ; tolower ( ch3 ) == 'y' && i < 5 ; i++ )
    {
        fflush ( stdin ) ;
        printf ( "\n\nEnter the place where you want to put your cloth : " ) ;
        gets (  p[ i ] ) ;
        strcpy ( q ->  p[ i ] , p[ i ] ) ;
        if ( i != 4 )
        {
            printf ( "\nAdd more hint place name (y/n) " ) ;
            ch3 = getche( ) ;//wait for input character and after getting input character print that
        }

        else
            printf ( "You cannot enter more than 5 hint about place ." ) ;
        fflush ( stdin ) ;
    }
    q -> pcount = i ;




    if ( clo [ j ] == NULL || strcmp ( clo [ j ] -> c, str ) > 0 )
    {
        r = clo [ j ] ;
        clo [ j ] = q ;
        q -> link = r ;
        return ;
    }

    else
    {
        while ( temp != NULL )
        {
            if ( ( strcmp ( temp -> c, str ) < 0 ) && ( ( strcmp ( temp -> link -> c, str ) > 0 ) ||
                                            temp -> link == NULL ) )
            {
                q -> link = temp -> link ;
                temp -> link = q ;
                return ;
            }
            temp = temp -> link ;
        }
    }
}

void show( )
{
    struct node *n ;
    int i, j ;

    printf ( "\n******YOUR CLOSET****\n" );
    for ( i = 0 ; i <= 40 ; i++ )
        printf ( "_" ) ;

    for ( j = 0 ;j <= 25 ; j++ )
    {
        n = clo [ j ] ;
        if ( n != NULL )
        {
           printf("\nCloths:");
		    printf ( "%s", n ->co) ;

            printf("\ncolours:");
            for ( i = 0 ; i < n -> ccount ; i++ )
                printf ( "\n\t(%d)\t%s", i+1,n -> c [ i ] ) ;
             printf("\nmaterials:");
            for ( i = 0 ; i < n -> mcount ; i++ )
                printf ( "\n\t(%d)\t%s", i+1,n -> m [ i ] ) ;
            printf("\nPlaces");
            for ( i = 0 ; i < n -> pcount ; i++ )
                printf ( "\n\t(%d)\t%s", i+1,n -> p[ i ] ) ;
            n = n -> link ;

        }
    }
}


void search(char *str)
{
    struct node *n ;
    int i, j ;
    int flag=0;

    printf ( "\n******YOUR FIND RESULT****\n" ) ;
    for ( i = 0 ; i <= 40 ; i++ )
        printf ( "~" ) ;
    for ( j = 0 ;j <= 25 ; j++ )
    {
        n = clo [ j ] ;
        char *str1=n->co;
        if ( n != NULL )
        {
            if(strcmp (str,str1)==0)
            {

           printf("\nCloths:");
		    printf ( "%s", n ->co) ;

            printf("\ncolours:");
            for ( i = 0 ; i < n -> ccount ; i++ )
                printf ( "\n\t(%d)\t%s", i+1,n -> c [ i ] ) ;
             printf("\nmaterials:");
            for ( i = 0 ; i < n -> mcount ; i++ )
                printf ( "\n\t(%d)\t%s", i+1,n -> m [ i ] ) ;
            printf("\nPlaces");
            for ( i = 0 ; i < n -> pcount ; i++ )
                printf ( "\n\t(%d)\t%s", i+1,n -> p[ i ] ) ;
            n = n -> link ;
            flag=1;
            break;
            }

        }
    }
    if(flag==0)
    {
        printf("\n\nCloth doesn't exist\n\n");
    }
}
void removecloth(char *str)
{
    struct node *n ;
    int i, j ;
    int flag=0;

    printf ( "\n******YOUR DELETE RESULT****\n" ) ;
    for ( i = 0 ; i <= 35 ; i++ )
        printf ( "_" ) ;
    for ( j = 0 ;j <= 25 ; j++ )
    {
        n = clo [ j ] ;
        char *str1=n->co;
        if ( n != NULL )
        {
            if(strcmp (str,str1)==0)
            {
                clo[j]=NULL;

            printf("\n\nCloth deleted\n\n");

            flag=1;
            break;
            }

        }
    }
    if(flag==0)
    {
        printf("\n\nCloth doesn't exist\n\n");
    }
}
