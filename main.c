#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"intal.h"

char* intal_add(const char* intal1, const char* intal2)
{
	int l1 = strlen(intal1);
	int l2 = strlen(intal2);

	int l3 = l1>l2?l1:l2;
	char* sum = (char*)calloc(l3+2, sizeof(char));

	int c = 0;
	int i = 0;
	int a1,a2,s;
	while(i<l1 && i<l2)
	{
		a1 = intal1[l1-i-1]-'0';
		a2 = intal2[l2-i-1]-'0';

		s = a1+a2+c;
		c = s>=10?1:0;
		s = s>=10?s-10:s;
		
		sum[l3-i] = s+'0'; 

		i++;
	}

	while(i<l2)
	{
		a2 = intal2[l2-1-i]-'0';
		
		s = a2+c;
		c = s>=10?1:0;
		s = s>=10?s-10:s;
		
		sum[l3-i] = s+'0';
		
		i++;
	}

	while(i<l1)
	{
		a1 = intal1[l1-1-i]-'0';
		
		s = a1+c;
		c = s>=10?1:0;
		s = s>=10?s-10:s;
		
		sum[l3-i] = s+'0';
		
		i++;
	}

	sum[l3+1] = '\0';

	if(c != 0)
	{
		sum[0] = '1';
		return sum;
	}
	else
	{
		char* nsum = (char*)calloc(l3+1, sizeof(char));
		for(int i = 0; i<l3+1; i++)
		{
			nsum[i] = sum[i+1];
		}
		free(sum);
		sum = NULL;
		return nsum;
	}
}

int intal_compare(const char* intal1, const char* intal2)
{
	int l1 = strlen(intal1);
	int l2 = strlen(intal2);

	if(l1>l2)
		return 1;
	else if(l2>l1)
		return -1;
	else
	{
		int i;
		for(i = 0; i<l1; i++)
		{
			if(intal1[i] != intal2[i])
				break;
		}
		if(i == l1)
			return 0;
		else if(intal1[i] > intal2[i])
			return 1;
		else
			return -1;
	}	
}

char* intal_diff(const char* intal1, const char* intal2)
{
	int l1 = strlen(intal1);
	int l2 = strlen(intal2);

	char* tintal1 = (char*)calloc(l1+1,sizeof(char));
	char* tintal2 = (char*)calloc(l2+1,sizeof(char));
	tintal1[l1] = '\0';
	tintal2[l2] = '\0';
	strcpy(tintal1, intal1);
	strcpy(tintal2, intal2);

	int c = intal_compare(tintal1, tintal2);
	if(c == 0)
	{
		char* ans = (char*)calloc(2, sizeof(char));
		ans[0] = '0';
		ans[1] = '\0';

		free(tintal1);
		tintal1 = NULL;
		free(tintal2);
		tintal2 = NULL;

		return ans;
	}
	else if(c == 1)
	{
		char* ans = (char*)calloc(l1+1,sizeof(char));

		for(int i = 0; i<l1; i++)
		{	
			if(i<l2)
			{
				if(tintal1[l1-1-i] >= tintal2[l2-1-i])
					ans[l1-1-i] = tintal1[l1-1-i] - tintal2[l2-1-i]+'0';	
				else
				{
					for(int j = l1-2-i; j>=0; j--)
					{
						if(tintal1[j] == '0')
							tintal1[j] = '9';
						else
						{
							tintal1[j] = tintal1[j]-1;
							break;
						}

					}
					ans[l1-1-i] = tintal1[l1-1-i]+10 - tintal2[l2-1-i]+'0'; 
				}
			}
			else
			{
				ans[l1-1-i] = tintal1[l1-1-i];	
			}
		}
		ans[l1] = '\0';

		free(tintal1);
		tintal1 = NULL;
		free(tintal2);
		tintal2 = NULL;

		int i;
		for(i = 0; i<l1; i++)
		{
			if(ans[i] != '0' || ans[i+1] == '\0')
				break;
		}
		if(i == 0)
			return ans;
		else
		{	
			char* nans = (char*)calloc(l1+1-i,sizeof(char));
			for(int j = i; j<=l1; j++)
			{
				nans[j-i] = ans[j];
			}
			free(ans);
			ans = NULL;
			return nans;
		}
	}
	else
	{
		char* ans = (char*)calloc(l2+1,sizeof(char));

		for(int i = 0; i<l2; i++)
		{	
			if(i<l1)
			{
				if(tintal2[l2-1-i] >= tintal1[l1-1-i])
					ans[l2-1-i] = tintal2[l2-1-i] - tintal1[l1-1-i]+'0';
				else
				{
					for(int j = l2-2-i; j>=0; j--)
					{
						if(tintal2[j] == '0')
							tintal2[j] = '9';
						else
						{
							tintal2[j]-=1;
							break;
						}

					}
					ans[l2-1-i] = tintal2[l2-1-i]+10 - tintal1[l1-1-i]+'0'; 
				}
			}
			else
			{
				ans[l2-1-i] = tintal2[l2-1-i];	
			}
		}
		ans[l2] = '\0';

		free(tintal1);
		tintal1 = NULL;
		free(tintal2);
		tintal2 = NULL;

		int i;
		for(i = 0; i<l2; i++)
		{
			if(ans[i] != '0' || ans[i+1] == '\0')
				break;
		}
		if(i == 0)
			return ans;
		else
		{	
			char* nans = (char*)calloc(l2+1-i,sizeof(char));
			for(int j = i; j<=l2; j++)
			{
				nans[j-i] = ans[j];
			}
			free(ans);
			ans = NULL;
			return nans;
		}
	}
}

char* intal_multiply(const char* intal1, const char* intal2)
{
	int l1 = strlen(intal1);
	int l2 = strlen(intal2);

	char* ans = (char*)calloc(l1+l2+1,sizeof(char));
	for(int i = 0; i<l1+l2; i++)
		ans[i] = '0';
	ans[l1+l2] = '\0';

	int x1,x2,s;
	int c = 0;
	int i,j;
	int car = 0;
	int sar = 0;
	for(i = 0; i<l1; i++)
	{
		for(j = 0; j<l2; j++)
		{
			x1 = intal2[l2-1-j]-'0';
			x2 = intal1[l1-1-i]-'0';

			s = x1*x2+c;
			c = s/10;
			s = s%10;

			
			sar = (ans[l1+l2-i-j-1]+s+car-'0')%10;
			car = (ans[l1+l2-i-j-1]+s+car-'0')/10;
			ans[l1+l2-i-j-1] = sar+'0';
		}

		sar = (ans[l1+l2-i-j-1]+c+car-'0')%10;
		ans[l1+l2-i-j-1] = sar+'0';
		car = 0;
		c = 0;
	}

	for(i = 0; i<l2+l1; i++)
	{
		if(ans[i] != '0' || ans[i+1] == '\0')
			break;
	}
	if(i == 0)
		return ans;
	else
	{	
		char* nans = (char*)calloc(l1+l2+1-i,sizeof(char));
		for(int j = i; j<=l2+l1; j++)
		{
			nans[j-i] = ans[j];
		}
		free(ans);
		ans = NULL;
		return nans;
	}

}

char* intal_mod(const char* intal1, const char* intal2)
{
	int d=strlen(intal1)-strlen(intal2)-1;
	char *ext=calloc(strlen(intal2)+d+1,sizeof(char));
	if(intal_compare(intal1,intal2)==-1)
	{
		char* te = (char*)calloc(strlen(intal1)+1, sizeof(char));
		strcpy(te, intal1);
		free(ext);
		ext = NULL;
		return te;
	}
	
	
	if(d>0)
	{
		for(int i=0;i<strlen(intal2);i++)
		{
			ext[i]=intal2[i];
		}
		int m=strlen(intal2);
		for(int i=0;i<d;i++)
		{
			ext[i+m]='0';
		}
		ext[d+m]='\0';
		char*z=intal_diff(intal1,ext);
		free(ext);
		ext = z;
		char*x = intal_mod(ext,intal2);
		free(ext);
		ext = NULL;
		z = NULL;
		return x;
	}
	char* x = intal_diff(intal1, intal2);
	char* y = intal_mod(x,intal2); 
	free(x);
	x = NULL;
	free(ext);
	ext = NULL;
	return y;

}

char* intal_pow(const char* intal1, unsigned int n)
{
	if(n == 0)
	{
		char* temp = (char*)calloc(2, sizeof(char));
		temp[0] = '1';
		temp[1] = '\0';
		return temp;	
	}
	if(n == 1)
	{
		char* temp = (char*)calloc(strlen(intal1)+1, sizeof(char));
		strcpy(temp, intal1);

		return temp;
	}

	
	char* t = intal_pow(intal1, n/2);

	char* ans = intal_multiply(t,t);
	
	if(n%2)
	{
		char*z = intal_multiply(ans, intal1);
		free(ans);
		ans = z;
	}

	free(t);
	t = NULL;

	return ans;
}

char* intal_gcd(const char* intal1, const char* intal2)
{
	if(intal_compare(intal2, "0") == 0)
	{
		char* t = (char*)calloc(strlen(intal1)+1, sizeof(char));
		strcpy(t, intal1);

		return t;
	}
	char* x = intal_mod(intal1, intal2);
	char* y = intal_gcd(intal2, x);
	free(x);
	x = NULL;
	return y;
}

char* intal_fibonacci(unsigned int n)
{
	char* a = (char*)calloc(2, sizeof(char));
	a[0] = '0';
	a[1] = '\0';

	char* b = (char*)calloc(2, sizeof(char));
	b[0] = '1';
	b[1] = '\0';

	char* ans = NULL;
	if(n == 0)
		return a;
	if(n == 1)
		return b;
	else
	{
		for(int i = 2; i<=n; i++)
		{
			ans = intal_add(a, b);
			free(a);
			a = b;
			b = ans;
		}
	}
	
	free(a);
	// free(ans);
	a = NULL;
	ans = NULL;

	return b;
}

char* intal_factorial(unsigned int n)
{
	char* ans = (char*)calloc(2, sizeof(char));
	ans[0] = '1';
	ans[1] = '\0';

	if(n == 0 || n == 1)
		return ans;

	char* i = (char*)calloc(2, sizeof(char));
	i[0] = '2';
	i[1] = '\0';

	unsigned int x = 2;
	char*z = NULL;
	char*y = NULL;
	while(x != n+1)
	{
		z  = intal_multiply(i, ans);
		free(ans);
		ans = z;
		y = intal_add(i, "1");
		free(i);
		i = y;
		x++;
	}

	free(i);
	i = NULL;
	y = NULL;

	return ans;
}

char* intal_bincoeff(unsigned int n, unsigned int k)
{
	char** dp = (char**)calloc(k+1, sizeof(char*));
	for(int i = 0; i<=k; i++)
		dp[i] = NULL;
	
	for(int i = 1; i<=k; i++)
	{
		dp[i] = (char*)calloc(2, sizeof(char));
		dp[i][0] = '0';
		dp[i][1] = '\0';
	}
	dp[0] = (char*)calloc(2, sizeof(char));
	dp[0][0] = '1';
	dp[0][1] = '\0';

	char*x = NULL;;
	for(int i = 1; i<=n; i++)
	{
		for(int j = i>k?k:i ; j>0; j--)
		{
			x = intal_add(dp[j], dp[j-1]);
			free(dp[j]);
			dp[j] = x;
		}
	}
	char* ans = (char*)calloc(strlen(dp[k])+1, sizeof(char));
	strcpy(ans, dp[k]);

	for(int i = 0; i<=k; i++)
	{
		free(dp[i]);
		dp[i]= NULL;
	}
	x = NULL;
	free(dp);
	dp = NULL;
	return ans;
}

int intal_max(char **arr, int n)
{
	int ind = 0;
	int c;
	for(int i = 1; i<n; i++)
	{
		c = intal_compare(arr[ind], arr[i]);
		if(c == -1)
			ind = i;
	}

	return ind;
}

int intal_min(char **arr, int n)
{
	int ind = 0;
	int c;
	for(int i = 1; i<n; i++)
	{
		c = intal_compare(arr[ind], arr[i]);
		if(c == 1)
			ind = i;
	}

	return ind;
}

int intal_search(char **arr, int n, const char* key)
{
	for(int i = 0; i<n; i++)
	{
		if(intal_compare(arr[i], key) == 0)
			return i;
	}
	return -1;
}

int intal_binsearch(char **arr, int n, const char* key)
{
	int l = 0;
	int r = n-1;

	int m;
	int x;
	while(l<=r)
	{
		m = (l+r)/2;
		x = intal_compare(arr[m], key);
		
		if(x == 0)
		{
			return m;
		}
		else if(x == 1)
			r = m-1;
		else
			l = m+1;
	}

	return -1;
}

static int partition(char **a, int l, int r)
{
	int m = l;
	int i = l;
	int j = r+1;
	char* x;
	while(i<=j)
	{
		i++;
		while(i<=r && intal_compare(a[i],a[m]) == -1)
			i++;

		j--;
		while(j>=l && intal_compare(a[j],a[m]) == 1)
			j--;

		if(i<j)
		{
			x = a[j];
			a[j] = a[i];
			a[i] = x;
		}
	}
	x = a[j];
	a[j] = a[m];
	a[m] = x;

	x = NULL;

	return j;
}

static void quicksort(char** arr, int l, int r)
{	
	int s;
	if(l<r)
	{
		s = partition(arr, l, r);
		quicksort(arr, l, s-1);		
		quicksort(arr, s+1, r);
	}	
}

void intal_sort(char **arr, int n)
{
	quicksort(arr,0,n-1);
}

char* coin_row_problem(char **arr, int n)
{
	char* ans = "0";
	char* in = "0";
	char* ex = "0";

	char** dp = (char**)calloc(n, sizeof(char*));
	for(int i = 0; i<n; i++)
		dp[i] = NULL;

	for(int i = 0; i<n; i++)
	{
		in = arr[i];
		if(i-2 >= 0)
		{
			char* x = intal_add(dp[i-2], in);
			in = x;
		}

		if(i-1>=0)
		{
			ex = dp[i-1];
		}

		if(intal_compare(in, ex) == 1)
			dp[i] = in;
		else
			dp[i] = ex;

		if(intal_compare(dp[i], ans) == 1)
			ans = dp[i];
	}
	char* rans = (char*)calloc(strlen(ans)+1, sizeof(char));
	strcpy(rans, ans);
	free(dp);
	dp = NULL;
	ans = NULL;

	return rans;
}
