/**
 * @file Computor.c 
 * @author Li Tianyu 
 * @brief 底层链表实现栈
 * @version 0.2
 * @date 2021-12-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include "Stack.h"
#include <math.h>
#include <assert.h>
#define PI 3.1415926
#define INITIAL_SIZE 100
#define DEBUG 0


/**
 * @brief 符号优先级比较,a为当前读入，b为栈顶元素
 * 
 * @param a 
 * @param b 
 * @return int  c反馈指令信息 0.结束 1.弹栈 2.压栈 3.删除当前元素及栈顶元素 4.报错 
 */
int ComparePriority(char a,char b);

/**
 * @brief 数字符串转为浮点数
 * 
 * @return float 返回该浮点数
 */
float ConvertToFloat(char *temp);

/**
 * @brief 清空字符串
 * 
 */
void ClearString(char *str);

/**
 * @brief 对中缀表达式进行运算
 * 
 * @param str 中缀表达式 Status判断是否是非法表达式 YES合法 NO非法
 * @return float 返回运算结果
 */
float Operation(char *str,YesNo* status);
/**
 * @brief 计算三角函数
 * 
 * @param functionName 函数名:0:cos 1:sin 2:tan 3:arccos 4:arcsin 5:arctan 6:sqrt
 * @param pStr 三角函数
 * @param round 指针指向指针地址改变
 * @return float 返回计算结果 
 */
float TriFunction(int functionName,char *pStr,int *round);





float TriFunction(int functionName,char *pStr,int *round){
    char *temp = malloc(INITIAL_SIZE*sizeof(char));
    //pTemp为指向temp的指针
    char *pTemp = temp;
    float result =0;
    int count=0;
    while(((*pStr>='0'&&*pStr<='9')||*pStr =='.')){
        *pTemp++ = *pStr;
        if((*(pStr+1) >'9'||*(pStr+1)<'0') && *(pStr+1)!='.'){
            result = ConvertToFloat(temp);
        }
        count++;
        pStr++;
    }
    switch(functionName){
        case 0:
                result = cos(result);
                break;
        case 1:
                result = sin(result);
                break;
        case 2:
                result = tan(result);
                break;
        case 3:
                result = acos(result);
                break;
        case 4:
                result = asin(result);
                break;
        case 5:
                result = atan(result);
                break;
        case 6:
                result = sqrt(result);
                break;
    }
    *round = count;
    return result;
}
void ClearString(char *str){
    free(str);
    str = (char*)malloc(INITIAL_SIZE*sizeof(char));
}
float ConvertToFloat(char *temp){
    int i=0;
    float value =0;
    float weight = 0.1;
    while(temp[i] != '\0' && temp[i] != '.'){
        value = value*10 + temp[i]-'0';
        i++;
    }
    if(temp[i] == '\0'){
        return value;
    }
    i++;
    while(temp[i]!='\0'){
        value = value+(temp[i]-'0')*weight;
        weight/=10.0;
        i++;
    }
    return value;
}
int ComparePriority(char a,char b){       
	int c;                         
	switch(a){
		case '#':
                if(b=='#'){
                    c=0;
                }else{
                    c=1;
                }
                break;
		case '+':
                if(b=='#'||b=='('){
                    c=2;
                }else{
                    c=1;
                }
                break;
		case '-':
                if(b=='#'||b=='('){
                    c=2;
                }else{
                    c=1;
                }
                break;
		case '*':
                if(b=='*'||b=='/'){
                    c=1;
                }else{
                    c=2;
                }
                break;
		case '/':
                if(b=='*'||b=='/'){
                    c=1;
                }else{
                    c=2;
                }
                break;
		case '(':
                c=2;
                break;
		case ')':
                if(b=='('){
                    c=3;
                }else{
                    c=1;
                }
                break;
		default :
                c=4;
                break; 
	}
	return c;
}
float Operation(char *str,YesNo* status){
    //向表达式末尾追加'#'
	strcat(str,"#");
    //pStr为指向str的指针,用于中缀表达式的遍历
    char *pStr = str;
    //numFloat数组用来存临时数据
    float numFloat[INITIAL_SIZE];
    //pNumFloat为指向numFloat数组的指针
    float* pNumFloat = numFloat;
    //numStack和opeStack分别为数字栈和符号栈
    Stack *numStack = Stack_Construct();
    Stack *opeStack = Stack_Construct();
    //temp用于数字尾部追加
    char *temp = malloc(INITIAL_SIZE*sizeof(char));
    //pTemp为指向temp的指针
    char *pTemp = temp;
    //先在符号栈中压入优先级最低的'#'
	char ope = '#';
    //num1和num2用于数字栈顶元素的运算
    float num1=0;
    float num2 =0;
    //result是运算后的最终结果
    float result =0;
    float num0 = 0;
    char sum = '+';
    char sub = '-';
    float* pNum0 = &num0;
    char* pSum = &sum;
    char* pSub = &sub;
    int* count= malloc(sizeof(int));
    Stack_Push(opeStack,&ope);
    //对单个字符进行遍历
	while(*pStr!='\0'){
        //如果是数字就连起来
		if((*pStr>='0' && *pStr<='9')||*pStr == '.') {
            //pTemp用来临时存储数字
            *pTemp++ = *pStr;
            if((*(pStr+1) >'9'||*(pStr+1)<'0') && *(pStr+1) != '.'){
                //将临时数字转换成浮点型压入数字栈
                *pNumFloat = ConvertToFloat(temp);
                Stack_Push(numStack,pNumFloat++);
                //将临时字符串清空
                ClearString(temp);
                pTemp = temp;
            }
            pStr++;
		}else if((*pStr == '-' && Stack_IsEmpty(numStack)) 
                    || (*pStr == '-' && *(pStr-1) == '(')){
                        Stack_Push(numStack,pNum0);
                        Stack_Push(opeStack,pSub);
                        pStr++;
        }else if (*pStr == 'c'||*pStr == 'o'||*pStr == 's'||
                    *pStr == 'n'||*pStr == 'i'||*pStr == 't'||*pStr == 'a'||*pStr == 'r'
                    ||*pStr == 'q'){
            *pTemp++ = *(pStr++);
            if(strcmp(temp,"cos")==0||strcmp(temp,"sin")==0||strcmp(temp,"tan")==0||strcmp(temp,"arccos")==0
                ||strcmp(temp,"arcsin")==0||strcmp(temp,"arctan")==0||strcmp(temp,"sqrt")==0){
                    if(strcmp(temp,"cos") == 0){
                        ClearString(temp);
                        pTemp = temp;
                        *pNumFloat = TriFunction(0,pStr,count);
                    }else if(strcmp(temp,"sin") == 0){
                        ClearString(temp);
                        pTemp = temp;
                        *pNumFloat = TriFunction(1,pStr,count);  
                    }else if(strcmp(temp,"tan") == 0){
                        ClearString(temp);
                        pTemp = temp;
                        *pNumFloat = TriFunction(2,pStr,count);   
                     }else if(strcmp(temp,"arccos") == 0){
                        ClearString(temp);
                        pTemp = temp;
                        *pNumFloat = TriFunction(3,pStr,count);    
                     }else if(strcmp(temp,"arcsin") == 0){
                        ClearString(temp);
                        pTemp = temp;
                        *pNumFloat = TriFunction(4,pStr,count);   
                    }else if(strcmp(temp,"arctan") == 0){
                        ClearString(temp);
                        pTemp = temp;
                        *pNumFloat = TriFunction(5,pStr,count);    
                     }else if(strcmp(temp,"sqrt") == 0){
                        ClearString(temp);
                        pTemp = temp;
                        *pNumFloat = TriFunction(6,pStr,count);
                    }
                    pStr+=*count;
                    Stack_Push(numStack,pNum0);
                    Stack_Push(numStack,pNumFloat++);
                    Stack_Push(opeStack,pSum);
            }
        }else{
            //比较当前符号和符号栈顶符号的优先级——获取操作指令
			switch(ComparePriority(*pStr,*(char *)Stack_Peek(opeStack))){

                //操作指令：0.结束 1.弹栈 2.压栈 3.删除当前元素及栈顶元素 4.报错 

				case 0:
						result = *(float*)Stack_Pop(numStack,freeData);
						pStr++;
						break;
				case 1:
                        //b中存数字栈弹出的数据
                        num1 = *(float*)Stack_Pop(numStack,freeData);
                        num2 = *(float*)Stack_Pop(numStack,freeData);
                        //弹出符号栈顶的字符
						switch(*(char *)Stack_Pop(opeStack,freeData)){
							case '+':
                                    *pNumFloat = num1+num2;
                                    Stack_Push(numStack,pNumFloat++);
                                    break;
							case '*':
                                    *pNumFloat = num1*num2;
                                    Stack_Push(numStack,pNumFloat++);
                                    break;
							case '-':
                                    *pNumFloat = num2-num1;
                                    Stack_Push(numStack,pNumFloat++);
                                    break;
							case '/':
                                    *pNumFloat = num2/num1;
                                    Stack_Push(numStack,pNumFloat++);
                                    break;
						}
						break;
				case 2:
                        //运算符优先级高压入栈
                        Stack_Push(opeStack,pStr++);
						break;
				case 3:
                        //用于删除左右括号
						pStr++;
                        Stack_Pop(opeStack,freeData);
						break;
				case 4:
                        *status = NO;
						pStr++;
						return 0;
			} 
	    }
    }
    return result;
}

int main(){
    int mode=0;
    float result =0;
    char* str = malloc(INITIAL_SIZE*sizeof(char));
    YesNo status = YES;
    printf("请输入计算表达式:\n");
    gets(str);
    printf("请输入输出模式:  向控制台输入为0 向文件输出为1\n");
    scanf("%d",&mode);
    result = Operation(str,&status);
    if(status == NO){
        printf("检测到非法字符");
        return 0;
    }
    if(mode == 0){
        printf("计算结果为:%f",result);
        return 0;
    }else if(mode == 1){
        FILE* fileOutput = fopen("D:\\CProjects\\Calculator\\TargetText.txt","a");
        assert(fileOutput!=NULL);
        fprintf(fileOutput,"%f\n",result);
        printf("已写入文件");
        return 0;
    }
    printf("非法字符请重新输入");
    return 0;
}
