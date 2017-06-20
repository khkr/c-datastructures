#include <stdio.h>

int remaining(int n, int k)
{
	int r =0;
	for(int i=2;i<=n;i++)
	r = (r+k)%i;

return r;
}
int main()
{

	int t, n, r,i,j;
	
	int output[100];

		scanf("%d%d",&n,&r);

		printf("Output is %d\n",remaining(n,r)+1);


}

