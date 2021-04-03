//reference:https://www.cnblogs.com/grandyang/p/8873471.html

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAX 10^6


double eval(char*);
double getnum(char* str, int* index);
int isoperator(int);
double eval_substring(char*,int);



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
	for(int i = 0;i<n;i++){
		char c = s[i];
		if(isdigit(c)){
			temp = temp*10+c-'0';
		}else if(c=='('){
			int j = i, count = 0;
			for(;i<n;i++){
				if(s[i]=='(')count++;
				if(s[i]==')')count--;
				if(count==0)break;
			}
			temp = eval_substring(&s[j+1],i-j);
		}
		if(isoperator(c)||i== n-1){
			switch(op){
				case'+':current+=temp;break;
				case'-':current-=temp;break;
				case'*':current*=temp;break;
				case'/':current/=temp;break;
			}
			if(c=='+'||c=='-'||i==n-1){
				result+=current;
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

double eval_substring(char* string,int length){
	if(length == 0){
		return 0.0;
	}
	char str[length];
	for(int index = 0;index<length;index++){
		str[index] = string[index];
	}
	return eval(str);
} 


