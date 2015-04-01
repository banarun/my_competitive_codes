#include<iostream>
#include<string>
#include<cstdio>
#include<cstdlib>

using namespace std;

struct name
{
	int count;
	string sn;
	name* next;
	struct country* link;
}*node1=NULL;

struct country
{
	int count;
	string cn;
	country* next;
}*node2=NULL;

void iname(string s,string sub);
void max();
int  fname(string sub);
country*  fcountry(string sub);

int main()
{
	int m,t,i;
	string s,sub;
	cin>>t>>m;
	
	for(i=0;i<t;i++)
	{
		
		cin>>s>>sub;
		iname(s,sub);
	}

	for(i=0;i<m;i++)
	{
		cin>>s;
		int asd=fname(s);
	}
	max();
	
	
	return 0;
}
void iname(string s,string sub)
{
	
	name* temp;
	temp =new name;
	temp->sn=s;
	temp->count=0;
	
	if(node1==NULL)
	{
		temp->next=NULL;
		node1=temp;
		
		country* tem;
		tem = new country;
		tem->count=0;
		tem->cn=sub;
		tem->next=NULL;
		node2=tem;
		
		node1->link=node2;
	}
	else
	{
		temp->next=node1;
		node1=temp;
		country* fg=fcountry(sub);
		if(fg==NULL)
		{
			country* tem;
			tem=new country;
			node1->link=tem;
			tem->cn=sub;
			temp->count=0;
			tem->next=node2;
			node2=tem;
			
			
		}
		else
		{
			node1->link=fg;
		}
	}
	
}

int fname(string sub)
{
	name* temp;
	int flag=0;
	temp=node1;
	while(temp!=NULL)
	{
		if(temp->sn==sub)
		{
			flag=1;
			(temp->count)++;
			country* tem;
			tem=temp->link;
			(tem->count)++;
			break;
		}
		
		temp=temp->next;
	}
	return flag;
}

country* fcountry(string sub)
{
	country* temp;
	country* fl=NULL;
	temp=node2;
	while(temp!=NULL)
	{
		string s=temp->cn;
		if(s==sub)
		{
			fl=temp;
			break;
		}
		else
		fl=temp;
		
		temp=temp->next;
	}
	return fl;
	
}

void max()
{
	country* cmnode;
	country* tem=node2;
	int maxn=0,maxc=0;
	name* nmnode;
	name* temp=node1;
	
	nmnode=node1;
	while(temp!=NULL)
	{	
		if(temp->count>maxn)
		{
			maxn=temp->count;
			nmnode=temp;
		}
		else if(maxn==temp->count)
		{
				if((nmnode->sn)>(temp->sn))
				nmnode=temp;
		}
		temp=temp->next;
	}
	
	cmnode=node2;
	while(tem!=NULL)
	{
		if(tem->count>=maxc)
		{
			maxc=tem->count;
			cmnode=tem;
		}
		if(maxc==tem->count)
		{
				if((cmnode->cn)>(tem->cn))
				cmnode=tem;
		}
		tem=tem->next;
	}
	cout<<cmnode->cn<<endl<<nmnode->sn<<"\n";
}
