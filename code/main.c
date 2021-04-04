//reference:https://www.cnblogs.com/grandyang/p/8873471.html
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAX 10^6 


double eval(char*);
double getnum(char* str, int* index);
int isoperator(int);

int main(void){
	double result;
	char string[MAX];
	while(scanf("%s",string)!=EOF){
		printf("%.15lf\n",eval(string));
	} 
	return 0;
}

double eval(char* s){
	int n = strlen(s);
	double temp = 0,current=0,result=0;
	char op = '+';
	int j,count;
	for(int i = 0; i < n; i++){
		char c = s[i];
		
		if(isdigit(c)){
			temp = temp*10+c-'0';
		}
		
		if(c=='('){
			j = i; count = 0;
			for(;i<n;i++){
				if(s[i]=='(')count++;
				if(s[i]==')')count--;
				if(count==0)break;
			}
			int length = i-j-1,position = j+1; 
			char substr[length+1];
			strncpy(substr,s+position,length);
			substr[length] = '\0'; 
			temp = eval(substr); 
		}
		
		if(isoperator(c)||i== n-1){
			switch(op){
				case'+':current+=temp;break;
				case'-':current-=temp;break;
				case'*':current*=temp;break;
				case'/':current/=temp;break;
			}
			if(c=='+'||c=='-'||i==n-1){
				result += current;
				current =0;
			}
			op = c;
			temp = 0;
		}
	}
	return result;
}


int isoperator(int c){
	return (c=='+'||c=='-'||c=='*'||c=='/');
}






