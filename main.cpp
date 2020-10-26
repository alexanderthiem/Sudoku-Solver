#include <iostream>
using namespace std;

/* Sample Input
8 7 0 6 9 0 0 0 0
0 0 0 0 0 0 8 6 7
0 1 0 0 5 0 0 0 0
0 0 0 0 0 0 1 0 8
7 8 0 3 0 0 0 0 6
0 0 3 1 8 4 9 0 0
1 0 6 7 0 5 0 0 0
9 3 8 0 0 1 0 0 0
0 0 0 0 0 0 6 0 3

Solution:

8 7 4   6 9 3   5 2 1
3 9 5   4 1 2   8 6 7
6 1 2   8 5 7   3 9 4

4 2 9   5 7 6   1 3 8
7 8 1   3 2 9   4 5 6
5 6 3   1 8 4   9 7 2

1 4 6   7 3 5   2 8 9
9 3 8   2 6 1   7 4 5
2 5 7   9 4 8   6 1 3

*/
/*one more difficulty sample input
0 0 0 0 0 9 0 7 0
0 0 0 0 8 2 0 5 0
3 2 7 0 0 0 0 4 0
0 1 6 0 4 0 0 0 0
0 5 0 0 0 0 3 0 0
0 0 0 0 9 0 7 0 0
0 0 0 6 0 0 0 0 5
8 0 2 0 0 0 0 0 0
0 0 4 2 0 0 0 0 8


Solution:
6 8 5   4 3 9   2 7 1
4 9 1   7 8 2   6 5 3
3 2 7   5 6 1   8 4 9

9 1 6   3 4 7   5 8 2
7 5 8   1 2 6   3 9 4
2 4 3   8 9 5   7 1 6

1 3 9   6 7 8   4 2 5
8 6 2   9 5 4   1 3 7
5 7 4   2 1 3   9 6 8
*/


/*one with various solutions
0 0 0 0 0 0 0 7 0
0 0 0 0 8 2 0 5 0
3 2 7 0 0 0 0 4 0
0 1 6 0 4 0 0 0 0
0 5 0 0 0 0 3 0 0
0 0 0 0 9 0 7 0 0
0 0 0 6 0 0 0 0 5
8 0 2 0 0 0 0 0 0
0 0 4 2 0 0 0 0 8
*/






int fac(int x)
{
	int res=x;
	while(--x)
	res*=x;
	return res;
}

int pow(int b, int e)
{
	int res=b;
	while(--e)
	res*=b;
	return res;
}

bool equals(int *a,int *b,int length)
{
	for(int i=0;i<length;i++)
	{
		bool t=true;
		for(int j=0;j<length;j++)
		{
			if(a[(i+j)%length]!=b[j])
			t= false;
		}
		if(t)
		return t;
	}
	return false;
}

bool ordered(int *a,int length)
{
	for(int i=1;i<length;i++)
	{
		if(a[i]<=a[i-1])
		return false;
	}
	return true;
}

bool in(int a,int *b,int length)
{
	for(int i=0;i<length;i++)
	{
		if(a==b[i])
		return true;
	}
	return false;
}

int count(bool *a)
{
	int res=0;
	for(int i=0;i<9;i++)
	if(a[i])
	res++;
	return res;
}

int count(bool **a)
{
	int res=0;
	for(int i=0;i<9;i++)
	res+=count(a[i]);
	return res;
}

int count(bool ***a)
{
	int res=0;
	for(int i=0;i<9;i++)
	res+=count(a[i]);
	return res;
}

bool correct(bool **a)
{
	for(int i=0;i<9;i++)
	if(count(a[i])>1)
	return false;
	bool **b;
	b=new bool*[9];
	for(int i=0;i<9;i++)
	{
		b[i]=new bool[9];
		for(int j=0;j<9;j++)
		b[i][j]=a[j][i];
	}
	for(int i=0;i<9;i++)
	if(count(b[i])>1)
	return false;
	return true;
}


bool correct(bool ***a)
{
	for(int i=0;i<9;i++)
	if(!correct(a[i]))
	return false;
	bool ***b;
	b=new bool**[9];
	for(int i=0;i<9;i++)
	{
		b[i]=new bool*[9];
		for(int j=0;j<9;j++)
		b[i][j]=a[j][i];
	}
	for(int i=0;i<0;i++)
	if(!correct(b[i]))
	return false;
	return true;
}



int Cases1[9][9];
int Cases2[36][9];
int Cases3[84][9];
int Cases4[126][9];
int Cases5[126][9];
int Cases6[84][9];
int Cases7[36][9];
int Cases8[9][9];

void initialize1()
{
	for(int i=0;i<9;i++)
	{
		for(int k=0;k<9;k++)
		Cases1[i][k]=(i+k)%9;
	}
}

void initialize2()
{
	int n=2;
	int place=0;

	for(int i=0;i<pow(9,n);i++)
	{
		int temp[n];
		int tmp=i;
		for(int j=0;j<n;j++)
		{
			temp[j]=tmp%9;
			tmp/=9;
		}
		if(ordered(temp,n))
		{
			for(int j=0;j<n;j++)
			Cases2[place][j]=temp[j];
			place++;

		}
	}
	for(int i=0;i<36;i++)
	{
		place=n;
		for(int j=0;j<9;j++)
		{
			if(!in(j,Cases2[i],n))
			Cases2[i][place++]=j;
		}

	}
}

void initialize3()
{
	int n=3;
	int place=0;
	for(int i=0;i<pow(9,n);i++)
	{
		int temp[n];
		int tmp=i;
		for(int j=0;j<n;j++)
		{
			temp[j]=tmp%9;
			tmp/=9;
		}
		if(ordered(temp,n))
		{
			for(int j=0;j<n;j++)
			Cases3[place][j]=temp[j];
			place++;

		}
	}
	for(int i=0;i<84;i++)
	{
		place=n;
		for(int j=0;j<9;j++)
		{
			if(!in(j,Cases3[i],n))
			Cases3[i][place++]=j;
		}
	}
}

void initialize4()
{
	int n=4;
	int place=0;
	for(int i=0;i<pow(9,n);i++)
	{
		int temp[n];
		int tmp=i;
		for(int j=0;j<n;j++)
		{
			temp[j]=tmp%9;
			tmp/=9;
		}
		if(ordered(temp,n))
		{
			for(int j=0;j<n;j++)
			Cases4[place][j]=temp[j];
			place++;
		}
	}
	for(int i=0;i<126;i++)
	{
		place=n;
		for(int j=0;j<9;j++)
		{
			if(!in(j,Cases4[i],n))
			Cases4[i][place++]=j;
		}
	}
}

void initialize5()
{
	int n=5;
	for(int i=0;i<126;i++)
	{
		for(int j=0;j<9;j++)
		Cases5[i][(9-n+j)%9]=Cases4[i][j];
	}
}

void initialize6()
{
	int n=6;
	for(int i=0;i<84;i++)
	{
		for(int j=0;j<9;j++)
		Cases6[i][(9-n+j)%9]=Cases3[i][j];
	}
}

void initialize7()
{
	int n=7;
	for(int i=0;i<36;i++)
	{
		for(int j=0;j<9;j++)
		Cases7[i][(9-n+j)%9]=Cases2[i][j];
	}
}

void initialize8()
{
	int n=8;
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		Cases8[i][(9-n+j)%9]=Cases1[i][j];
	}
}

//This Funktion initialize() requires around 1/1319 of the performance SoloLearn allows you to use. I found this out by testing
	/*for(int i=0;i<??;i++)
	{
		initialize();
	}*/
//For ?? bigger than 1319 the cout order did not work properly
//This noumber changed by time(The performance other users are occupying??)
void initialize()
{
	initialize1();
	initialize2();
	initialize3();
	initialize4();
	initialize5();
	initialize6();
	initialize7();
	initialize8();

}

bool solving11(bool **p)
{
	bool res=false;
	int n=1;
	int list[9];
	int Place=0;
	for(int i=0;i<9;i++)	//Going through all combinations
	{
		Place=0;
		for(int j=0;j<9;j++)   //Going through first dimension of p
		{
			bool t=false;
			for(int k=0;k<n;k++)	//Going through all numbers in combination
			{
				if(p[j][Cases1[i][k]])
				t=true;
			}
			if(t)
			list[Place++]=j;
		}
		if(Place==n)
		{
			for(int j=0;j<Place;j++)   //Going through all involved p
			{
				for(int k=n;k<9;k++)   //Going through all numbers of not combination
				{
					if(p[list[j]][Cases1[i][k]])
					{
						res=true;
						p[list[j]][Cases1[i][k]]=false;
					}
				}
			}
		}
	}
	return res;
}

bool solving12(bool **p)
{
	bool res=false;
	int n=2;
	int list[9];
	int Place=0;
	for(int i=0;i<36;i++)	//Going through all combinations
	{
		Place=0;
		for(int j=0;j<9;j++)   //Going through first dimension of p
		{
			bool t=false;
			for(int k=0;k<n;k++)	//Going through all numbers in combination
			{
				if(p[j][Cases2[i][k]])
				t=true;
			}
			if(t)
			list[Place++]=j;
		}
		if(Place==n)
		{
			for(int j=0;j<Place;j++)   //Going through all involved p
			{
				for(int k=n;k<9;k++)   //Going through all numbers of not combination
				{
					if(p[list[j]][Cases2[i][k]])
					{
						res=true;
						p[list[j]][Cases2[i][k]]=false;
					}
				}
			}
		}
	}
	return res;
}

bool solving13(bool **p)
{
	bool res=false;
	int n=3;
	int list[9];
	int Place=0;
	for(int i=0;i<84;i++)	//Going through all combinations
	{
		Place=0;
		for(int j=0;j<9;j++)   //Going through first dimension of p
		{
			bool t=false;
			for(int k=0;k<n;k++)	//Going through all numbers in combination
			{
				if(p[j][Cases3[i][k]])
				t=true;
			}
			if(t)
			list[Place++]=j;
		}
		if(Place==n)
		{
			for(int j=0;j<Place;j++)   //Going through all involved p
			{
				for(int k=n;k<9;k++)   //Going through all numbers of not combination
				{
					if(p[list[j]][Cases3[i][k]])
					{
						res=true;
						p[list[j]][Cases3[i][k]]=false;
					}
				}
			}
		}
	}
	return res;
}

bool solving14(bool **p)
{
	bool res=false;
	int n=4;
	int list[9];
	int Place=0;
	for(int i=0;i<126;i++)	//Going through all combinations
	{
		Place=0;
		for(int j=0;j<9;j++)   //Going through first dimension of p
		{
			bool t=false;
			for(int k=0;k<n;k++)	//Going through all numbers in combination
			{
				if(p[j][Cases4[i][k]])
				t=true;
			}
			if(t)
			list[Place++]=j;
		}
		if(Place==n)
		{
			for(int j=0;j<Place;j++)   //Going through all involved p
			{
				for(int k=n;k<9;k++)   //Going through all numbers of not combination
				{
					if(p[list[j]][Cases4[i][k]])
					{
						res=true;
						p[list[j]][Cases4[i][k]]=false;
					}
				}
			}
		}
	}
	return res;
}

bool solving15(bool **p)
{
	bool res=false;
	int n=5;
	int list[9];
	int Place=0;
	for(int i=0;i<126;i++)	//Going through all combinations
	{
		Place=0;
		for(int j=0;j<9;j++)   //Going through first dimension of p
		{
			bool t=false;
			for(int k=0;k<n;k++)	//Going through all numbers in combination
			{
				if(p[j][Cases5[i][k]])
				t=true;
			}
			if(t)
			list[Place++]=j;
		}
		if(Place==n)
		{
			for(int j=0;j<Place;j++)   //Going through all involved p
			{
				for(int k=n;k<9;k++)   //Going through all numbers of not combination
				{
					if(p[list[j]][Cases5[i][k]])
					{
						res=true;
						p[list[j]][Cases5[i][k]]=false;
					}
				}
			}
		}
	}
	return res;
}

bool solving16(bool **p)
{
	bool res=false;
	int n=6;
	int list[9];
	int Place=0;
	for(int i=0;i<84;i++)	//Going through all combinations
	{
		Place=0;
		for(int j=0;j<9;j++)   //Going through first dimension of p
		{
			bool t=false;
			for(int k=0;k<n;k++)	//Going through all numbers in combination
			{
				if(p[j][Cases6[i][k]])
				t=true;
			}
			if(t)
			list[Place++]=j;
		}
		if(Place==n)
		{
			for(int j=0;j<Place;j++)   //Going through all involved p
			{
				for(int k=n;k<9;k++)   //Going through all numbers of not combination
				{
					if(p[list[j]][Cases6[i][k]])
					{
						res=true;
						p[list[j]][Cases6[i][k]]=false;
					}
				}
			}
		}
	}
	return res;
}

bool solving17(bool **p)
{
	bool res=false;
	int n=7;
	int list[9];
	int Place=0;
	for(int i=0;i<36;i++)	//Going through all combinations
	{
		Place=0;
		for(int j=0;j<9;j++)   //Going through first dimension of p
		{
			bool t=false;
			for(int k=0;k<n;k++)	//Going through all numbers in combination
			{
				if(p[j][Cases7[i][k]])
				t=true;
			}
			if(t)
			list[Place++]=j;
		}
		if(Place==n)
		{
			for(int j=0;j<Place;j++)   //Going through all involved p
			{
				for(int k=n;k<9;k++)   //Going through all numbers of not combination
				{
					if(p[list[j]][Cases7[i][k]])
					{
						res=true;
						p[list[j]][Cases7[i][k]]=false;
					}
				}
			}
		}
	}
	return res;
}

bool solving18(bool **p)
{
	bool res=false;
	int n=8;
	int list[9];
	int Place=0;
	for(int i=0;i<9;i++)	//Going through all combinations
	{
		Place=0;
		for(int j=0;j<9;j++)   //Going through first dimension of p
		{
			bool t=false;
			for(int k=0;k<n;k++)	//Going through all numbers in combination
			{
				if(p[j][Cases8[i][k]])
				t=true;
			}
			if(t)
			list[Place++]=j;
		}
		if(Place==n)
		{
			for(int j=0;j<Place;j++)   //Going through all involved p
			{
				for(int k=n;k<9;k++)   //Going through all numbers of not combination
				{
					if(p[list[j]][Cases8[i][k]])
					{
						res=true;
						p[list[j]][Cases8[i][k]]=false;
					}
				}
			}
		}
	}
	return res;
}

void solving(bool ***p,int x)
{
	bool ***temp=new bool**[54];
	for(int i=0;i<54;i++)
	{
		temp[i]=new bool*[9];
		for(int j=0;j<9;j++)
		{
			temp[i][j]=new bool[9];
		}
	}
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			temp[i][j]=p[i][j];
		}
		for(int j=0;j<9;j++)
		{
			temp[i+9][j]=p[j][i];
		}
		for(int j=0;j<9;j++)
		{
			temp[i+18][j]=p[3*(i/3)+j/3][3*(i%3)+j%3];
		}
	}
	for(int i=0;i<27;i++)
	{
		for(int j=0;j<9;j++)
		{
			for(int k=0;k<9;k++)
			{
				temp[27+i][j][k]=temp[i][k][j];
			}
		}
	}
	bool t=true;
	while(t)
	{
		t=false;
		for(int i=0;i<54;i++)
		{
			if(solving11(temp[i]))
			t=true;
			if(solving12(temp[i]))
			t=true;
			if(solving13(temp[i]))
			t=true;
			if(solving14(temp[i]))
			t=true;
			if(solving15(temp[i]))
			t=true;
			if(solving16(temp[i]))
			t=true;
			if(solving17(temp[i]))
			t=true;
			if(solving18(temp[i]))
			t=true;
		}
	}
	if(count(p)==81)
	{
		if(correct(p))
		{
		    cout<<endl;
			for(int i=0;i<81;i++)
			{
				int count=0;
				for(int j=0;j<9;j++)
				{
					if(p[i/9][i%9][j])
					{
						cout << j+1;
						cout << " ";
						count++;
					}
				}
				for(int j=0;j<1-count;j++)
				cout << "  ";
				if(i%9==5||i%9==2)
				cout << "  ";
				if(i%9==8)
				cout << endl;
				if((i%9==8)&&(i/9==5||i/9==2||i/9==8))
				cout << endl;
			}
			cout << endl ;
		}
	}
	else
	{
		while(!(count(p[x/9][x%9])-1))
		x++;
		for(int i=0;i<9;i++)
		{
			bool ***a=new bool**[9];
			for(int i=0;i<9;i++)
			{
				a[i]=new bool*[9];
				for(int j=0;j<9;j++)
				{
					a[i][j]=new bool[9];
					for(int k=0;k<9;k++)
					a[i][j][k]=p[i][j][k];
				}
			}
			if(p[x/9][x%9][i])
			{
				for(int j=0;j<9;j++)
				{
					if(j!=i)
					a[x/9][x%9][j]=false;
					else
					a[x/9][x%9][j]=true;
				}
				/*for(int i=0;i<81;i++)
				{
					int count=0;
					for(int j=0;j<9;j++)
					{
						if(a[i/9][i%9][j])
						{
							cout << j+1;
							cout << " ";
							count++;
						}
					}
					for(int j=0;j<1-count;j++)
					cout << "  ";
					if(i%9==5||i%9==2)
					cout << "  ";
					if(i%9==8)
					cout << endl;
					if((i%9==8)&&(i/9==5||i/9==2||i/9==8))
					cout << endl;
				}
				cout << endl << endl;*/
				solving(a,x+1);
			}
		}
	}
}

int main() {
	bool ***field=new bool**[9];
	for(int i=0;i<9;i++)
	{
		field[i]=new bool*[9];
		for(int j=0;j<9;j++)
		field[i][j]=new bool[9];

	}
	for(int i=0;i<pow(9,3);i++)
	field[i/81][(i/9)%9][i%9]=true;
	int solvedField[9][9];
	for(int i=0;i<81;i++)
	{
		cin >> solvedField[i/9][i%9];
		if(solvedField[i/9][i%9]>0)
		{
			for(int j=1;j<10;j++)
			{
				if (j!=solvedField[i/9][i%9])
				field[i/9][i%9][j-1]=false;
			}
		}
	}
	initialize();
	solving(field,0);







	return 0;
}
