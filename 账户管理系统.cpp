/*
��Ŀ:�������ϵͳ
��������������ķ�չ����������Ҫ��¼��ƽ̨����ӣ���ϵͳ��ʵ�����¹���
��Ŀʱ�䣺2020��7��22�� 
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
int manue();//�˵� 
int login();//��¼���� 
int adduser();//����˻���Ϣ
int alterloginpassword();//�޸ĵ�¼����
int viewallinformation(); //�鿴������Ϣ 
int DelLineData();//ɾ��ָ����
string CharToStr(); 
int altermation();;
int number=0; 
//������ 
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
				alterloginpassword();//�޸ĵ�¼���� 
				break;
			}
			case 0:{
				system("cls");
				printf("\n\n\n\n                                   ϵͳ���˳�!!!\n\n\n\n");
				exit(0);
				break;
			}
		}
	} 
	return 0;
} 
//�޸ĵ�¼���� 
int alterloginpassword(){
	system("cls");
	char a[100]; 
	string oldpassword,ch;
	//¼���ļ����� 
	FILE *fp=fopen("����.txt","r");
	if(fp==NULL){
		printf("û���������룬��������ļ���������");
		exit(1);
	}
	fscanf(fp,"%s",a);
	fclose(fp);
	ch=a;
	printf("\n\n***********************�޸ĵ�¼����**************************\n\n");
	//��������� 
	printf("                     ����������룺");
	cin>>oldpassword;
	if(oldpassword!=ch){
		//������ֻ��һ��������� 
	    printf("\n\n                  ������󣡣���<�س������ز˵�>\n\n\n"); 
	    getchar();
	    getchar();
		return 1;
	}
	//�������������� 
	string newpassword1="sds";
	string newpassword2="gfg";
	while(1){
		printf("\n\n                     ������������(����q�˳��޸�)��");
	 	cin>>newpassword1;
	 	if(newpassword1=="q")return 1; 
		printf("\n\n                     ��ȷ�������룺");
		cin>>newpassword2;
		if(newpassword1==newpassword2)break;
		printf("\n\n                     �����������벻һ��!!!\n\n");
	} 
	FILE *fp1=fopen("����.txt","w");
	char word[100];
	strncpy(word,newpassword2.c_str(),newpassword2.length()+1);
	//д�������� 
	fprintf(fp1,"%s",word);
	fclose(fp);
	printf("\n\n                     �����޸ĳɹ�!!!<�س����ز˵�>");
	getchar();
	getchar();
}
//�����˺���Ϣ����
int fileline()
{
    ifstream ReadFile;
    int n=0;
    string tmp;
    ReadFile.open("�˻���Ϣ��.txt",ios::in);//ios::in ��ʾ��ֻ���ķ�ʽ��ȡ�ļ�
    if(ReadFile.fail())//�ļ���ʧ��:����0
    {
        return 0;
    }
    else//�ļ�����
    {
        while(getline(ReadFile,tmp,'\n'))
        {
            n++;
        }
        ReadFile.close();
        return n;
    }
} 
//�ַ���תstring���� 
string CharToStr(char * contentChar)
{
	string tempStr;
	for (int i=0;contentChar[i]!='\0';i++)
	{
		tempStr+=contentChar[i];
	}
	return tempStr;
}
//����û���Ϣ 
int adduser(){ 
	char platform[100],username[100],password[100],website[100],Email[100],remarks[100];
	system("cls");
	printf("\n\n************************************����˻���Ϣ***************************************\n\n\n");
	printf("                     ������ƽ̨����(��������q��ȡ�����)��");
	scanf("%s",platform); 
	if(CharToStr(platform)=="q") return 1;
	printf("\n\n                     �������û�����");
	scanf("%s",username);
	if(CharToStr(username)=="q") return 1;
	printf("\n\n                     �����û����룺");
	scanf("%s",password);
	if(CharToStr(password)=="q") return 1;
	printf("\n\n                     ������ƽ̨��ַ��"); 
	scanf("%s",website);
	if(CharToStr(website)=="q") return 1;
	printf("\n\n                     ���������䣺"); 
	scanf("%s",Email);
	if(CharToStr(Email)=="q") return 1;
	printf("\n\n                     �����뱸ע��Ϣ��");
	scanf("%s",remarks);
	if(CharToStr(remarks)=="q") return 1;
	FILE *fp=fopen("�˻���Ϣ��.txt","a+");
	//printf("%d",fileline());
			fprintf(fp,"\n%s ",platform);
	    	fprintf(fp,"%s ",username);
	    	fprintf(fp,"%s ",password);
	    	fprintf(fp,"%s ",website);
	    	fprintf(fp,"%s ",Email);
	    	fprintf(fp,"%s",remarks);
	    	printf("\n\n\n\n\n                          ��ӳɹ�!!!<�س����ز˵�>");

		getchar();
		getchar();
		fclose(fp);
		return 1;
}
//�鿴�����˺���Ϣ
int viewallinformation(){
	system("cls"); 
	printf("\n\n*****************************************************************************�����˺���Ϣ************************************************************************************************\n\n\n");
	FILE *fp = fopen("�˻���Ϣ��.txt","r");
	int line=fileline();
	printf("���      ");
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
	printf("\n\n                                                                       ����%d����¼����!<�س����ز˵�>",line-1);
	
	return 1;
} 
//ɾ��ָ����Ϣ 
int DelLineData()
{
	system("cls");
	printf("\n\n*************************************************************************ɾ��ָ������Ϣ****************************************************************************\n\n");
	FILE *fp = fopen("�˻���Ϣ��.txt","r");
	int fileline0=fileline();
	printf("���      ");
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
	printf("\n\n                                                             ��ָ��ɾ���еı�ţ�����0���ز˵���:");
	int LL;
	cin>>LL; 
	if(LL==0){
		return 1;
	}
	if(LL>=fileline0){
		printf("\n\n\n\n\n                                                                  ��������!!!<�س������ز˵�>");
		getchar();
		getchar();
		return 1;
	}
	int lineNum=LL; 
	ifstream in;
	in.open("�˻���Ϣ��.txt");
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
	//д���ļ�
	ofstream out;
	out.open("�˻���Ϣ��.txt");
	out.flush();
	out<<strFileData;
	out.close();
	printf("\n\n\n                                                                     ɾ���ɹ�!!!<�س������ز˵�>");
	getchar();
	getchar();
	return 1;
} 
//�޸�ָ����
int altermation(){
	system("cls");
	printf("\n\n************************************************************************�޸�ָ������Ϣ***************************************************************************\n\n");
	FILE *fp = fopen("�˻���Ϣ��.txt","r");
	int fileline0=fileline();
	char a[100],b[100],c[100],d[100],e[100],f[100],t[100];
	printf("���      ");
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
	printf("\n\n                                                                     ��ָ���޸��еı��(����0�˳��޸�):");
	int LL;
	cin>>LL; 
	if(LL==0)return 1;
	if(LL>=fileline0){
		printf("\n\n\n\n\n                                                                           ��������!!!<�س������ز˵�>");
		getchar();
		getchar();
		return 1;
	}
	FILE *fp1 = fopen("�˻���Ϣ��.txt","r");
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
	printf("\n\n\n\n                                                                     ��ѡ���޸���ѡ��:");
	fclose(fp1); 
	char p;
	cin>>p;
	char a1[100],b1[100],c1[100],d1[100],e1[100],f1[100];
	//�ҵ�ָ���� 
	FILE *fp3 = fopen("�˻���Ϣ��.txt","r");
	for(int i=0;i<fileline0;i++){
		fscanf(fp3,"%s",a1);
		fscanf(fp3,"%s",b1);
		fscanf(fp3,"%s",c1);
		fscanf(fp3,"%s",d1);
		fscanf(fp3,"%s",e1);
		fscanf(fp3,"%s",f1);
		if(i==LL){//�ҵ���ָ���� 
			break;
		}		
	}
	fclose(fp3);
	printf("\n\n                                                                     ");
	switch(p){
		case 'a':{
			printf("�������µ�%s��",a);
			scanf("%s",a1);
			break;
		}
		case 'b':{
			printf("�������µ�%s��",b);
			scanf("%s",b1);
			break;
		}
		case 'c':{
			printf("�������µ�%s��",c);
			scanf("%s",c1);
			break;
		}
		case 'd':{
			printf("�������µ�%s��",d);
			scanf("%s",d1);
			break;
		}
		case 'e':{
			printf("�������µ�%s��",e);
			scanf("%s",e1);
			break;
		}
		case 'f':{
			printf("�������µ�%s��",f);
			scanf("%s",f1);
			break;
		}
		default :{
			printf("������󣡣���<�س������ز˵�>");
			getchar();
			getchar();
			return 1; 
		
		}
	}
	//ɾ����һ��
	int lineNum=LL; 
	ifstream in;
	in.open("�˻���Ϣ��.txt");
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
	//д���ļ�
	ofstream out;
	out.open("�˻���Ϣ��.txt");
	out.flush();
	out<<strFileData;
	out.close();
	//������Ϣ���� 
	FILE *fp2=fopen("�˻���Ϣ��.txt","a+");
	//printf("%d",fileline());
			fprintf(fp2,"%s ",a1);
	    	fprintf(fp2,"%s ",b1);
	    	fprintf(fp2,"%s ",c1);
	    	fprintf(fp2,"%s ",d1);
	    	fprintf(fp2,"%s ",e1);
	    	fprintf(fp2,"%s",f1);
	fclose(fp2);
	
	printf("\n\n\n                                                                     �޸ĳɹ�!!!<�س����ز˵�>");
	getchar();
	getchar();
	return 1; 
} 
//��¼ҳ�� 
int login(){
	int flag=1;
	char a[100];
	string ch;
	string password;
	//�������� 
	FILE *fp=fopen("����.txt","a+");
	if(fp==NULL){
		printf("û���������룬��������ļ���������");
		exit(1);
	}
	fscanf(fp,"%s",a);
	ch=a;
	printf("\n\n***********************�˻�����ϵͳ*******************\n\n");
	while(1){
			if(flag==1){
				printf("                  �������¼���룺");
			}
			flag=0;
			cin>>password;
			if(password==ch)break;
			system("cls");
			printf("\n\n***********************�˻�����ϵͳ*******************\n\n");
			printf("\n                  ����������������룺"); 	
	} 
	system("cls");
	return 1;
}
//�˵� 
int manue(){
	printf("\n\n* * * * * * * * * * * * * *�˻�����ϵͳ* * * * * * * * * * * * * *\n\n");
	printf("                          1.����˻�\n\n");
	printf("                          2.�鿴�����˻���Ϣ\n\n");
	printf("                          3.ɾ��ָ���˻���Ϣ\n\n");
	printf("                          4.�޸��˻���Ϣ\n\n");
	printf("                          5.�޸�ϵͳ��¼����\n\n");
	printf("                          0.�˳�ϵͳ\n");
	printf("\n\n###################################################################\n\n");
	printf("                            ��ѡ�������");
}
