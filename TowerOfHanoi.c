# include <stdio.h>

void towers(int num, char from_tower,char to_tower,char aux_tower)
{
	if(num==1)
	{
		printf("Move disk 1 from tower %c to tower %c\n",from_tower,to_tower);
		return;
	}

	towers(num-1,from_tower,aux_tower,to_tower);

	printf("Move disk %d from tower %c to tower %c\n",num,from_tower,to_tower);

	towers(num-1,aux_tower,to_tower,from_tower);

}

int main()
{
	int num;

	printf("Number of disks\n");

	scanf("%d",&num);

	printf("Towers of Hanoi series:\n");

	towers(num,'A','B','C');

}





