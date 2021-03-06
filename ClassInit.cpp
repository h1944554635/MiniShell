#include "ClassInit.h"
#include "PWD.h"
#include "Order.h"
#include "MKDIR.h"
#include "CD.h"
#include "LS.h"
#include "CAT.h"
#include "WHOAMI.h"
#include "MV.h"
#include "RM.h"
#include "DIFF.h"
#include "WC.h"
#include "CP.h"
#include <iostream>

using namespace std;

/*
所有的命令实现都继承自Order类，同时该文件中需包含所有的派生类头文件
*/

//带参数命令
Order* ClassInit::init(string orderName, string params)
{
	if(orderName.empty())
	{
		cout << "faild: command is NULL";
		return NULL;
	}
	Order *order = NULL;

	if(orderName.compare("mkdir") == 0)
	{
		order = new MKDIR(params);
	}
	else if(orderName.compare("cd") == 0)
	{
		order = new CD(params);
	}
	else if(orderName.compare("ls") == 0)
	{
		order = new LS(params);
	}
	else if(orderName.compare("cat") == 0)
	{
		order =new CAT(params);
	}	
	else if(orderName.compare("mv") == 0)
	{
		order = new MV(params);
	}
	else if(orderName.compare("rm") == 0)
	{
		order = new RM(params);
	}
	else if(orderName.compare("diff") == 0)
	{
		order =new DIFF(params);
	}
	else if(orderName.compare("wc") == 0)
	{
		order = new WC(params);
	}
	else if(orderName.compare("cp") == 0)
	{
		order = new CP(params);
	}
	else
	{
		cout << orderName << " :No such command" << endl;
	}
	
	return order;
}

//无参数命令
Order* ClassInit::init(string orderName)
{
	if(orderName.empty())
	{
		cout << "faild: command is NULL";
		return NULL;
	}
	
	Order *order = NULL;
	
	/*
	此处采用if else的形式判断传入的命令
	将对应的命令执行对象赋给Order基类后传出
	*/
	if(orderName.compare("pwd") == 0)
	{
		order = new PWD();
	}
	else if(orderName.compare("ls") == 0)
	{	
		order = new LS();
	}
	else if(orderName.compare("whoami") == 0)
	{
		order = new WHOAMI();
	}
	/*
	else if(orderName.compare("who" == 0))
	{
		order = new WHO();
	}
	*/
	else
	{
		cout << orderName << " :No such command" << endl;
	}

	return order;
}

/*
* 此方法用于删除传入字符串两边的多余空格
*/
string ClassInit::trim(string strParams)
{
	if(strParams.empty())
		return strParams;
	
	strParams.erase(0, strParams.find_first_not_of(" "));
	strParams.erase(strParams.find_last_not_of(" ") + 1);

	return strParams;
}

/*
暂时不会传入c风格字符串，此处请忽略

Order* ClassInit::init(char* orderName, char* params)
{
	Order order = NULL;
	return order;													    
}

Order* ClassInit::init(char* orderName)
{
	Order order = NULL;
	return order;														    
}
*/
