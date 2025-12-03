#include <stdio.h>
#include <string.h>
#include <ctype.h>
struct information{
	int ID;
	char Name[100];
	char Designation[100];
	int Salary;
};
struct information employees[200];
void displayEmployees(struct information employees[], int n);
void HighestSalary(struct information employees[], int n);
void SearchEmployees(struct information employees[], int n);
void SearchEmployees(struct information employees[], int n){
	int choice,ID,i;
	char name[100];
	printf("There are two ways you can search for employees: ");
	printf("Either by ID or Name: (1-ID, 2-Name): ");
	scanf("%d", &choice);
	if(choice==1){
		printf("Enter the ID you want to search: ");
		scanf("%d", &ID);
		for(i=0;i<n;i++){
			if(ID==employees[i].ID){
				printf("Employee found!\n");
				printf("Employee ID: %d, Employee name: %s, Employee designation: %s, Salary: %d \n"
	            , employees[i].ID,employees[i].Name,employees[i].Designation,employees[i].Salary);
	            break;
			}
		}
	}else if(choice==2){
		printf("Enter the name you want to search: ");
		scanf("%s",name);
		for(i=0;i<n;i++){
			if(stricmp(name,employees[i].Name)==0){
				printf("Employee found!\n");
				printf("Employee ID: %d, Employee name: %s, Employee designation: %s, Salary: %d \n"
	            , employees[i].ID,employees[i].Name,employees[i].Designation,employees[i].Salary);
	            break;
			}
		}
	}else{
		printf("Invalis choice");
	}

}
void HighestSalary(struct information employees[], int n){
	int i,highestPaid,index;
	for(i=0;i<n-1;i++){
		if(employees[i+1].Salary>employees[i].Salary){
			highestPaid=employees[i+1].Salary;
		    index=i+1;
		}
	}
	printf("Highest salary details\n");
	printf("Employee ID: %d, Employee name: %s, Employee designation: %s, Salary: %d \n"
	, employees[index].ID,employees[index].Name,employees[index].Designation,employees[index].Salary);
}
void displayEmployees(struct information employees[], int n){
	int i;
	printf("ID\tName\tDesignation\tSalary\n");
	for(i=0;i<n;i++){
		printf("%d\t%-8s\t%-12s\t%d\n", employees[i].ID,employees[i].Name,employees[i].Designation,employees[i].Salary);
	}
}
int main(){
	int n,i,choose;
	printf("Enter the number of employees you want to store data of: ");
	scanf("%d", &n);
	for(i=0;i<n;i++){
		printf("Enter ID for employee %d: ", i+1);
		scanf("%d", &employees[i].ID);
		printf("Enter name for employee %d: ", i+1);
		scanf("%s", employees[i].Name);
		printf("Enter designation for employee %d: ", i+1);
		scanf("%s", employees[i].Designation);
		printf("Enter salary for employee %d: ", i+1);
		scanf("%d", &employees[i].Salary);
	}
	printf("Do u want to \n");
	printf("1-Display the employee data stored\n");
	printf("2-Find the employee with the highest salary\n");
	printf("3-Search for an employee: ");
	printf("4-Exit");
	scanf("%d", &choose);
	switch(choose){
		case 1:
			displayEmployees(employees, n);
			break;
		case 2:
			HighestSalary(employees,n);
			break;
		case 3:
			SearchEmployees(employees,n);
			break;
		case 4:
			break;
	}
}

//The function Bonus(employees,n) can be passed this function can sort through the salaries of all the employees
//added employees[n].Salary if its <=50000 then it can be stored in a variable bonus 
// bonus = (employees[n].Salary*10/100) + employees[n].Salary;
// this can be then updated back employees[n].Salary = bonus;
