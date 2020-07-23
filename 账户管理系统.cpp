/*
项目:密码管理系统
背景：随着网络的发展，市面上需要登录的平台多而杂，本系统可实现以下功能
项目时间：2020年7月22日 
*/
#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
#include<map>
#include<ctime>
#include<set>
#include<cstdlib>
#include<fstream> 
using namespace std;
int manue();//菜单 
int login();//登录界面 
int adduser();//添加账户信息
int alterloginpassword();//修改登录密码
int viewallinformation(); //查看所有信息 
int DelLineData();//删除指定行
string CharToStr(); 
int altermation();;
int number=0; 
//主函数 
int main(){
	login();
	while(1){
		system("cls");
		manue();
		int m;
	    cin>>m;
		switch(m){
			case 1:{
				adduser();
				break;
			}
			case 2:{
				viewallinformation(); 
				getchar();
            	getchar();
				break;
			}
			case 3:{
				DelLineData();
				break;
			}
			case 4:{
				altermation();
				break;
			}
			case 5:{
				alterloginpassword();//修改登录密码 
				break;
			}
			case 0:{
				system("cls");
				printf("\n\n\n\n                                   系统已退出!!!\n\n\n\n");
				exit(0);
				break;
			}
		}
	} 
	return 0;
} 
//修改登录密码 
int alterloginpassword(){
	system("cls");
	char a[100]; 
	string oldpassword,ch;
	//录入文件密码 
	FILE *fp=fopen("密码.txt","r");
	if(fp==NULL){
		printf("没有设置密码，请打开密码文件设置密码");
		exit(1);
	}
	fscanf(fp,"%s",a);
	fclose(fp);
	ch=a;
	printf("\n\n***********************修改登录密码**************************\n\n");
	//输入旧密码 
	printf("                     请输入旧密码：");
	cin>>oldpassword;
	if(oldpassword!=ch){
		//旧密码只有一次输入机会 
	    printf("\n\n                  密码错误！！！<回车键返回菜单>\n\n\n"); 
	    getchar();
	    getchar();
		return 1;
	}
	//两次输入新密码 
	string newpassword1="sds";
	string newpassword2="gfg";
	while(1){
		printf("\n\n                     请输入新密码(输入q退出修改)：");
	 	cin>>newpassword1;
	 	if(newpassword1=="q")return 1; 
		printf("\n\n                     请确认新密码：");
		cin>>newpassword2;
		if(newpassword1==newpassword2)break;
		printf("\n\n                     两次输入密码不一致!!!\n\n");
	} 
	FILE *fp1=fopen("密码.txt","w");
	char word[100];
	strncpy(word,newpassword2.c_str(),newpassword2.length()+1);
	//写入新密码 
	fprintf(fp1,"%s",word);
	fclose(fp);
	printf("\n\n                     密码修改成功!!!<回车返回菜单>");
	getchar();
	getchar();
}
//计算账号信息个数
int fileline()
{
    ifstream ReadFile;
    int n=0;
    string tmp;
    ReadFile.open("账户信息库.txt",ios::in);//ios::in 表示以只读的方式读取文件
    if(ReadFile.fail())//文件打开失败:返回0
    {
        return 0;
    }
    else//文件存在
    {
        while(getline(ReadFile,tmp,'\n'))
        {
            n++;
        }
        ReadFile.close();
        return n;
    }
} 
//字符串转string类型 
string CharToStr(char * contentChar)
{
	string tempStr;
	for (int i=0;contentChar[i]!='\0';i++)
	{
		tempStr+=contentChar[i];
	}
	return tempStr;
}
//添加用户信息 
int adduser(){ 
	char platform[100],username[100],password[100],website[100],Email[100],remarks[100];
	system("cls");
	printf("\n\n************************************添加账户信息***************************************\n\n\n");
	printf("                     请输入平台名称(以下输入q均取消添加)：");
	scanf("%s",platform); 
	if(CharToStr(platform)=="q") return 1;
	printf("\n\n                     请输入用户名：");
	scanf("%s",username);
	if(CharToStr(username)=="q") return 1;
	printf("\n\n                     请输用户密码：");
	scanf("%s",password);
	if(CharToStr(password)=="q") return 1;
	printf("\n\n                     请输入平台网址："); 
	scanf("%s",website);
	if(CharToStr(website)=="q") return 1;
	printf("\n\n                     请输入邮箱："); 
	scanf("%s",Email);
	if(CharToStr(Email)=="q") return 1;
	printf("\n\n                     请输入备注信息：");
	scanf("%s",remarks);
	if(CharToStr(remarks)=="q") return 1;
	FILE *fp=fopen("账户信息库.txt","a+");
	//printf("%d",fileline());
			fprintf(fp,"\n%s ",platform);
	    	fprintf(fp,"%s ",username);
	    	fprintf(fp,"%s ",password);
	    	fprintf(fp,"%s ",website);
	    	fprintf(fp,"%s ",Email);
	    	fprintf(fp,"%s",remarks);
	    	printf("\n\n\n\n\n                          添加成功!!!<回车返回菜单>");

		getchar();
		getchar();
		fclose(fp);
		return 1;
}
//查看所有账号信息
int viewallinformation(){
	system("cls"); 
	printf("\n\n*****************************************************************************所有账号信息************************************************************************************************\n\n\n");
	FILE *fp = fopen("账户信息库.txt","r");
	int line=fileline();
	printf("编号      ");
	for(int i=0;i<line;i++){
			string A,B;
			char a[100],b[100],c[100],d[100],e[100],f[100],t[100];
			fscanf(fp,"%s",a);
			fscanf(fp,"%s",b);
			fscanf(fp,"%s",c);
			fscanf(fp,"%s",d);
			fscanf(fp,"%s",e);
			fscanf(fp,"%s",f);
			printf("%-20s%-20s%-30s%-30s%-30s%-30s\n\n",a,b,c,d,e,f);
			if(i!=line-1){
				printf("%-10d",i+1);
			}
			
	}
	printf("\n\n=========================================================================================================================================================================================");
	printf("\n\n                                                                       共有%d条记录！！!<回车返回菜单>",line-1);
	
	return 1;
} 
//删除指定信息 
int DelLineData()
{
	system("cls");
	printf("\n\n*************************************************************************删除指定行信息****************************************************************************\n\n");
	FILE *fp = fopen("账户信息库.txt","r");
	int fileline0=fileline();
	printf("编号      ");
	for(int i=0;i<fileline0;i++){
			string A,B;
			char a[100],b[100],c[100],d[100],e[100],f[100],t[100];
			fscanf(fp,"%s",a);
			fscanf(fp,"%s",b);
			fscanf(fp,"%s",c);
			fscanf(fp,"%s",d);
			fscanf(fp,"%s",e);
			fscanf(fp,"%s",f);
			printf("%-20s%-20s%-30s%-30s%-30s%-30s\n\n",a,b,c,d,e,f);
			if(i!=fileline0-1){
				printf("%-10d",i+1);
			}
			
	}
	printf("\n\n===============================================================================================================================================================");
	printf("\n\n                                                             请指定删除行的编号（输入0返回菜单）:");
	int LL;
	cin>>LL; 
	if(LL==0){
		return 1;
	}
	if(LL>=fileline0){
		printf("\n\n\n\n\n                                                                  输入有误!!!<回车键返回菜单>");
		getchar();
		getchar();
		return 1;
	}
	int lineNum=LL; 
	ifstream in;
	in.open("账户信息库.txt");
	string strFileData = "";
	int line = 0;
	char lineData[1024] = {0};
	while(in.getline(lineData, sizeof(lineData)))
	{
		if (line == lineNum)
		{
			//strFileData += "\n";
		}
		else
		{
			if(line!=0){
				strFileData += "\n";
			}
			strFileData += CharToStr(lineData);
		}
		line++;
	}
	in.close();
	//写入文件
	ofstream out;
	out.open("账户信息库.txt");
	out.flush();
	out<<strFileData;
	out.close();
	printf("\n\n\n                                                                     删除成功!!!<回车键返回菜单>");
	getchar();
	getchar();
	return 1;
} 
//修改指定行
int altermation(){
	system("cls");
	printf("\n\n************************************************************************修改指定行信息***************************************************************************\n\n");
	FILE *fp = fopen("账户信息库.txt","r");
	int fileline0=fileline();
	char a[100],b[100],c[100],d[100],e[100],f[100],t[100];
	printf("编号      ");
	for(int i=0;i<fileline0;i++){
			string A,B;
			fscanf(fp,"%s",a);
			fscanf(fp,"%s",b);
			fscanf(fp,"%s",c);
			fscanf(fp,"%s",d);
			fscanf(fp,"%s",e);
			fscanf(fp,"%s",f);
			printf("%-20s%-20s%-30s%-30s%-30s%-30s\n\n",a,b,c,d,e,f);
			if(i!=fileline0-1){
				printf("%-10d",i+1);
			}
			
	}
	fclose(fp);
	printf("\n\n                                                                     请指定修改行的编号(输入0退出修改):");
	int LL;
	cin>>LL; 
	if(LL==0)return 1;
	if(LL>=fileline0){
		printf("\n\n\n\n\n                                                                           输入有误!!!<回车键返回菜单>");
		getchar();
		getchar();
		return 1;
	}
	FILE *fp1 = fopen("账户信息库.txt","r");
	fscanf(fp1,"%s",a);
	fscanf(fp1,"%s",b);
	fscanf(fp1,"%s",c);
	fscanf(fp1,"%s",d);
	fscanf(fp1,"%s",e);
	fscanf(fp1,"%s",f);
	printf("\n\n\n\n               ----------------------------------------------------------------------------------------------------------------------");
    printf("\n\n\n                                       a.%s",a);
	printf("      b.%s",b);
	printf("      c.%s",c);
	printf("      d.%s",d);
	printf("      e.%s",e);
	printf("      f.%s",f);
	printf("\n\n\n\n                                                                     请选择修改行选项:");
	fclose(fp1); 
	char p;
	cin>>p;
	char a1[100],b1[100],c1[100],d1[100],e1[100],f1[100];
	//找到指定行 
	FILE *fp3 = fopen("账户信息库.txt","r");
	for(int i=0;i<fileline0;i++){
		fscanf(fp3,"%s",a1);
		fscanf(fp3,"%s",b1);
		fscanf(fp3,"%s",c1);
		fscanf(fp3,"%s",d1);
		fscanf(fp3,"%s",e1);
		fscanf(fp3,"%s",f1);
		if(i==LL){//找到了指定行 
			break;
		}		
	}
	fclose(fp3);
	printf("\n\n                                                                     ");
	switch(p){
		case 'a':{
			printf("请输入新的%s：",a);
			scanf("%s",a1);
			break;
		}
		case 'b':{
			printf("请输入新的%s：",b);
			scanf("%s",b1);
			break;
		}
		case 'c':{
			printf("请输入新的%s：",c);
			scanf("%s",c1);
			break;
		}
		case 'd':{
			printf("请输入新的%s：",d);
			scanf("%s",d1);
			break;
		}
		case 'e':{
			printf("请输入新的%s：",e);
			scanf("%s",e1);
			break;
		}
		case 'f':{
			printf("请输入新的%s：",f);
			scanf("%s",f1);
			break;
		}
		default :{
			printf("输入错误！！！<回车键返回菜单>");
			getchar();
			getchar();
			return 1; 
		
		}
	}
	//删除这一行
	int lineNum=LL; 
	ifstream in;
	in.open("账户信息库.txt");
	string strFileData = "";
	int line = 0;
	char lineData[1024] = {0};
	while(in.getline(lineData, sizeof(lineData)))
	{
		if (line == lineNum)
		{
			//strFileData += "\n";
		}
		else
		{
			strFileData += CharToStr(lineData);
			strFileData += "\n";
		}
		line++;
	}
	in.close();
	//写入文件
	ofstream out;
	out.open("账户信息库.txt");
	out.flush();
	out<<strFileData;
	out.close();
	//将新信息插入 
	FILE *fp2=fopen("账户信息库.txt","a+");
	//printf("%d",fileline());
			fprintf(fp2,"%s ",a1);
	    	fprintf(fp2,"%s ",b1);
	    	fprintf(fp2,"%s ",c1);
	    	fprintf(fp2,"%s ",d1);
	    	fprintf(fp2,"%s ",e1);
	    	fprintf(fp2,"%s",f1);
	fclose(fp2);
	
	printf("\n\n\n                                                                     修改成功!!!<回车返回菜单>");
	getchar();
	getchar();
	return 1; 
} 
//登录页面 
int login(){
	int flag=1;
	char a[100];
	string ch;
	string password;
	//读入密码 
	FILE *fp=fopen("密码.txt","a+");
	if(fp==NULL){
		printf("没有设置密码，请打开密码文件设置密码");
		exit(1);
	}
	fscanf(fp,"%s",a);
	ch=a;
	printf("\n\n***********************账户管理系统*******************\n\n");
	while(1){
			if(flag==1){
				printf("                  请输入登录密码：");
			}
			flag=0;
			cin>>password;
			if(password==ch)break;
			system("cls");
			printf("\n\n***********************账户管理系统*******************\n\n");
			printf("\n                  密码错误请重新输入："); 	
	} 
	system("cls");
	return 1;
}
//菜单 
int manue(){
	printf("\n\n* * * * * * * * * * * * * *账户管理系统* * * * * * * * * * * * * *\n\n");
	printf("                          1.添加账户\n\n");
	printf("                          2.查看所有账户信息\n\n");
	printf("                          3.删除指定账户信息\n\n");
	printf("                          4.修改账户信息\n\n");
	printf("                          5.修改系统登录密码\n\n");
	printf("                          0.退出系统\n");
	printf("\n\n###################################################################\n\n");
	printf("                            请选择操作：");
}
