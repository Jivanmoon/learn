#include<bits/stdc++.h>
using namespace std;
vector<string> prase(const char *str)  //分离每个符号
{
	vector<string>tokens;
	int len = strlen(str);
	char *p = (char*)malloc((len + 1) * sizeof(char));
	int i = 0, j = 0;
	while (i < len) //去除空格
	{
		if (str[i] == ' ')
		{
			i++;
			continue;
		}
		p[j++] = str[i++];
	}
 
	p[j] = '\0';
	j = 0;
	len = strlen(p);
	while (j < len)
	{
		char temp[2] = { 0 }; //存储符号
		string token;
		switch (p[j])
		{
		case '+':
		case '*':
		case '/':
		case '(':
		case ')':
			temp[0] = p[j];
			temp[1] = '\0';
			token = temp;
			tokens.push_back(token);
			break;
		case '-':
			if (p[j - 1] == ')' || isdigit(p[j - 1])) //不能使用--j，会死循环
			{
				temp[0] = p[j];
				temp[1] = '\0';
				token = temp;
				tokens.push_back(token);
				break;
			}
			else
			{
				temp[0] = '$';
				temp[1] = '\0';
				token = temp;
				tokens.push_back(token);
				break;
			}
		default:
			i = j;
			while (isdigit(p[i]))
				i++;
 
			char *operand = (char*)malloc((i - j + 1) * sizeof(char));
			memset(operand, 0, i - j + 1);
			memcpy(operand, p + j, i - j);
			operand[i - j] = '\0';
			token = operand;
			tokens.push_back(token);
			free(operand);
 
			j = i - 1;
			break;
		}
		j++;
 
	}
	free(p);
	return tokens;
}
int priority(string opd)
{
	int level;
	if (opd == "$")
		level = 3;
	else if (opd == "*" || opd == "/")
		level = 2;
	else if (opd == "+" || opd == "-")
		level = 1;
	else if (opd == "(" || opd == ")")
		level = 0;
	return level;
}
void calculate(stack<int>& opdStack, string opt)
{
	if (opt == "+")
	{
		int rOpd = opdStack.top();
		opdStack.pop();
		int lOpd = opdStack.top();
		opdStack.pop();
		int result = rOpd + lOpd;
		opdStack.push(result);
	}
	else if (opt == "-")
	{
		int rOpd = opdStack.top();
		opdStack.pop();
		int lOpd = opdStack.top();
		opdStack.pop();
		int result = lOpd - rOpd;
		opdStack.push(result);
	}
	else if (opt == "*")
	{
		int rOpd = opdStack.top();
		opdStack.pop();
		int lOpd = opdStack.top();
		opdStack.pop();
		int result = lOpd * rOpd;
		opdStack.push(result);
	}
	else if (opt == "/")
	{
		int rOpd = opdStack.top();
		opdStack.pop();
		int lOpd = opdStack.top();
		opdStack.pop();
		int result = lOpd / rOpd;
		opdStack.push(result);
	}
	else if (opt == "$")
	{
		int result = opdStack.top();
		opdStack.pop();
		result = -result;
		opdStack.push(result);
	}
}
int computationalExp(const char *str)
{
	vector<string>tokens = prase(str);
	stack<int>opdStack;
	stack<string>optStack;
 
	for (int i = 0; i < tokens.size(); i++)
	{
		string token = tokens[i];
		if (token == "+" || token == "-" || token == "*" || token == "/" || token == "$")
		{
			if (optStack.empty())
			{
				optStack.push(token);
			}
			else
			{
				int tokenPriority = priority(token);
				string topOptStack = optStack.top();
				int optPriority = priority(topOptStack);
				if (tokenPriority > optPriority) //运算操作符优先于栈顶操作符，则入栈
				{
					optStack.push(token);
				}
				else
				{//否则弹出操作符和操作数进行计算，直至当前操作符优先栈顶操作符时，入栈
					while (tokenPriority <= optPriority)
					{
						calculate(opdStack, topOptStack);
						optStack.pop();
						if (optStack.size() > 0)
						{
							topOptStack = optStack.top();
							optPriority = priority(topOptStack);
						}
						else
						{
							break;
						}
					}
					optStack.push(token);
				}
			}
		}
		else if (token == "(")
		{
			optStack.push(token);
		}
		else if (token == ")")
		{
			while (optStack.top() != "(")
			{
				string topOpt = optStack.top();
				calculate(opdStack, topOpt);
				optStack.pop();
			}
			optStack.pop();//弹出"("
		}
		else
		{
			opdStack.push(stoi(token));//操作数入栈
		}
	}
	while (optStack.size() != 0)
	{
		string topOpt = optStack.top();
		calculate(opdStack, topOpt);
		optStack.pop();
	}
	return opdStack.top();
}
int main()
{
	const char *str = "30+5-6*-9/3+(4+3*7)";
	cout << computationalExp(str) << endl;
	return 0;
}