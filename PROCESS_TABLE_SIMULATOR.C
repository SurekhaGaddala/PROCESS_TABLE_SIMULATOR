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
	
}

void Shell_sortByBST(){
	
}

void Linear_searchByPID(){
	
}

void Binary_searchBYPID(){

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


