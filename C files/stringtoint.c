#include<stdio.h>

int stringToInt(char* str);
int main(){
  
    char str[10];
    int intValue;

    printf("Enter any integer as a string: ");
    scanf("%s",str);

   intValue = stringToInt(str);

    printf("Equivalent integer value: %d",intValue);

    return 0;
}
int stringToInt(char* str){
	int counter=0;
	int num=0;
	while(str[counter]!=0){
		num=(str[counter]-'0')+num*10;
		counter++;
	}
	return num;
}
