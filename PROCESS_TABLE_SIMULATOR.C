#include<stdio.h>
#include <stdlib.h>
typedef struct{
	int pid;
	char pname[50];
	int priority;
	float BST;
}process;
int count=0;
process table[50];
void Add(){
	printf("Enter process-%d details\n",count+1);
	printf("Enter PID\n");
	scanf("%d", &table[count].pid);
	printf("Enter process name\n");
	scanf("%s", table[count].pname);
	printf("Enter priority\n");
	scanf("%d", &table[count].priority);
	printf("Enter Burst time\n");
	scanf("%f", &table[count].BST);
	count++;
}

void Display(){
	int i;
	for(i=0;i<=count;i++)
	{
    printf("process-%d\n",i+1);
	printf("\nPID-%d\tProcess name - %s\n",table[i].pid,table[i].pname);
	printf("\npriority - %d\tBST - %f\n",table[i].priority,table[i].BST);
   }
}

void Bubble_sortByPriority(){
     int i,j;
     for(i=0;i<count;i++){
     	for(j=0;j<count-i-1;count++){
     		if(table[j].priority>table[j+1].priority);{
     			int temp=table[j].priority;
     			table[j].priority=table[j+1].priority;
     			table[j+1].priority=temp;
			 }
		 }
	 }
}

void Insertion_sortByPID(){
	int i, j, comp = 0, shifts = 0;
	Process key;
	clock_t start = clock();
	
	for (i = 1; i < n; i++) {
		key = p[i];
		j = i - 1;
		while (j >= 0 && p[j].pid > key.pid) {
			comp++;
			p[j+1] = p[j];
			shifts++;
			j--;
}

void Shell_sortByBST(){
	int gap, i, j, comp = 0, shifts = 0;
	Process temp;
	clock_t start = clock();
	
	for (gap = n/2; gap > 0; gap /= 2) {
		for (i = gap; i < n; i++) {
			temp = p[i];
			for(j = i; j >= gap && p[j-gap].burstTime > temp.burstTime;j-=gap)
			{
				comp++;
				p[j] = p[j-gap];
				shifts++;
			}
			p[j] = temp;
		}
}

void Linear_searchByPID(){
		int key, i, comp = 0;
	clock_t start = clock();
	printf("\n Enter PID to be search: ");
	scanf("%d", &key);
	for (i=0; i<n; i++) {
		comp++;
		if (p[i].pid == key) {
			clock_t end = clock();
			printf("Found at position %d", i+1);
			printf("\nComparisons: %d", comp);
			printf("\nTime: %lf Clock seconds\n", (double)(end-start)/CLOCKS_PER_SEC);
			return;
		}
	}
	printf("\n Process not found");
}

void Binary_searchBYPID(){
int low = 0, high = n-1, mid, key, comp = 0;
	clock_t start = clock();
	printf("\nEnter PID to search: ");
	scanf("%d", &key);
	while (low <= high) {
		mid = (low + high) / 2;
		comp++;
		if (p[mid].pid == key) {
			clock_t end = clock();
			printf("Found at position %d", mid+1);
			printf("\nComparisons: %d", comp);
			printf("\nTime: %lf seconds\n", (double)(end-start)/CLOCKS_PER_SEC);
			return;
		}
		else if (key < p[mid].pid)
		high = mid-1;
		else
		low = mid + 1;
	}
	printf("\nProcess not found");	
}

int main(){
	while(1){
	printf("1.Add\n2.Display\n3.Bubble_sort(priority)\n4.Insertion_sor(PID)\n5.Shell_sort(BST)\n");
	printf("6.Linear_search(PID)\n7.Binary_search(PID2)\n8.exitTheLoop\n");
	int choice;
	printf("Enter your Choice\n");
	scanf("%d",&choice);
    switch (choice){
    	case 1:Add();break;
        case 2:Display();break;
        case 3:Bubble_sortByPriority();break;
        case 4:Insertion_sortByPID();break;
        case 5:Shell_sortByBST();break;
        case 6:Linear_searchByPID();break;
        case 7:printf("come here after sorting");break;
		       Binary_searchBYPID();break;
	    case 8:exit(0);break;
  } 
 }
}

