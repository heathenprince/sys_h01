#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mystrlen( char *s ) {
  int l = 0;

  while( *s ) {
    l++;
    s++;
  }  
  return l;
}


char * mystrcat( char *str1 , char *str2 ) {
  while( *str1 ) {
    str1++;
  }
  while( *str2 ) { 
    *str1 = *str2;
    str1++;
    str2++;
  }
  return str1; //returns ptr to end of str1 -- fix!
}

char * mystrcpy( char *str1 , char *str2 ) {
  while( *str2 ) {
    *str1 = *str2;
    str1++;
    str2++;
  }
  return str1; //returns ptr to end of str1
}


int mystrcmp( char *str1 , char *str2 ) { //why pointers to?
  while( *str1 == *str2 && (*str1 && *str2) ) { //make sure both are still true so you dont go over str memory!
    str1++; //thats why pointers to
    str2++;
  }
  return *str1 - *str2;
}


int mystrncmp( char *str1 , char *str2 , int n ) {
  int i = 0;
  while( *str1 == *str2 && (*str1 && *str2) &&  i < n) { 
    str1++; 
    str2++;
    i++;
  }
  return *str1 - *str2;
}


//linsearch for c
char * mystrchr( char *str, int c ) {
  while( *str ) {
    if( *str == c ) {
      return str; //mem addr
    }
    str++;
  }
  return 0; //how you return a nullpointer apparently
}


/*
//linsearch for substr
//quite a lot harder than i thought
char * mystrstr( char *str1, char *str2 ) { //return mem addr in str1
while( *str1 ) {
  if( *str1 == *str2 ) {
    //??
    str1++;
    str2++;
  }
 }
  return 0; //how you return a nullpointer apparently
  } 
*/



int main() {
  
  char b0[] = "mew"; //immutable pointers
  char b1[] = "two";
  char b2[] = "miles";
  char b3[] = "davis";
  
  char *orgcp = strcpy( b0,b1 );
  char *mycp = mystrcpy( b2,b3 ); 
  printf( "org: %s,%c\n" , b0 , *orgcp );
  printf( "mine: %s,%c\n\n" , b2 , *mycp ); //fix -- mem addr issue
  
  
  char b4[50], b5[50], b6[50],b7[50];
  strcpy( b4, "hello, " );
  strcpy( b5, "world!" );
  strcpy( b6, "string" );
  strcpy( b7, "thing" );

  strcat( b4,b5 ); 
  printf( "src: %s\n" , b5 );
  printf( "dst: %s\n" , b4 );
  mystrcat( b6,b7 );
  printf( "src: %s\n" , b7 );
  printf( "dst: %s\n" , b6 );
  
  
  char *org = strchr( "howdy" , 'w' );
  char *mine = mystrchr( "howdy" , 'w' );
  char *norg = strchr( "howdy" , 'i' ); //null test
  char *nmine = mystrchr( "howdy" , 'i' ); //null test
  printf( "strchr test\n\n" );
  printf( "testing for existing char's mem addr: %p\n" , mine );
  printf( "testing for equality w/ org: %d\n" , org == mine ); //okay ngl this is so beautiful
  printf( "testing for null mem addr: %p\n" , nmine );
  printf( "testing for equality w/ nulls: %d\n" , nmine == norg );
  
  return 0;
}


