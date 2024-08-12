
int strcompare(char str[],char m[])
{
	int flag;
	int i=0;
	while(str[i]!='\0' && m[i]!='\0')
	{
		if(str[i]!=m[i])
		{
			flag=1;
			break;
		}
		i++;
	}
	
	if(flag==1)
		return 0;
	else 
		return 1;
}
