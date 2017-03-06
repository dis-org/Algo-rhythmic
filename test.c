#include <stdio.h>
#include <stdlib.h>
#include "esami.h"
#include "fuffa.h"

int main(int argc, char* argv[])
{
  int len= argc -1;
  char array[len];
  Set_t Sets[len];


  for(int i= 0; i<len; i++)
    {
      array[i]= argv[i+1][0];
      make_Set(&Sets[i],array[i]);
    }

  char input[100];
  int state= 0;
  char* c;
  Set_t* A;
  Set_t* B;

  while(1)
    {
      scanf("%s",input);
      c= input;
      state= 0;
      
      while(*c!='\0')
	{
	  switch(state)
	    {
	    case 0: //cerco A
	      switch(*c)
		{
		case'+':
		  break;
		default:
		  A= find_Set(Sets,len,*c);
		  if(A)
		    {
		      print_Set(A);
		      state= 1;
		    }
		  else state= -1;
		}
	      break;
	    case 1: // cerco un simbolo
	      switch(*c)
		{
		case'+':
		  state= 2;
		}
	      break;
	    case 2:// cerco B e unisco
	      switch(*c)
		{
		case'+':
		  break;
		default:
		  B= find_Set(Sets,len,*c);
		  if(B)
		    {
		      print_Set(B);
		      A= union_Set(A,B);
		      print_Set(A);		      
		      state= 1;
		    }
		}
	      break;
	    default: //errore brutto
	      return 404;
	    }
	  if(state==-1)
	    {
	      puts("elemento non presente");
	      return 0;
	    }	    
	  c++;
	}
    }  
  return 0;
}
