#include <c_functions.h>

//Discards any number of preceding '\n' and one succeding '\n'. Input should have atleast one non-'\n' character. Null terminates the string
void my_getline(char* ptr){
	char c;
	while((c=getchar())=='\n'){}
	
	do{
		*ptr=c;
		ptr+=1;
	} while((c=getchar())!='\n');
	
	*ptr='\0';
	return;
}