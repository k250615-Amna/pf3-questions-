#include <stdio.h>

float calculateRepayment(float loan,float IntrestRate,int years);
int years;
float result,loan,fixedAmount,remaining,currentLoan,IntrestRate;
int current=1;

float calculateRepayment(float loan,float IntrestRate,int years){
	char choice;
	float additional;
	if(loan<=0||years<=1){
		return fixedAmount;
	}
	else{
		currentLoan=loan+(loan*(IntrestRate/100));
		printf("Year %d : Loan before payment %f \n", current,currentLoan);
		current++;
		
		printf("Are there any additional payments(y/n): ");
		scanf(" %c", &choice);
		if(choice=='y'){
			printf("Enter the additional payment: ");
			scanf("%f", &additional);
		}
		remaining = currentLoan-(fixedAmount+additional);
		if(remaining<0){
			remaining=0;
		}
		printf("Year %d : Loan after payment %f \n", current,remaining);
		years--;
		return calculateRepayment(remaining,IntrestRate,years)+fixedAmount;
	}
}

int main(){
	printf("Enter the loan amount: ");
	scanf("%f",&loan);
	printf("Enter the intrest rate: ");
	scanf("%f",&IntrestRate);
	printf("Enter the number of years: ");
	scanf("%d", &years);
	printf("Enter the fixed amount paid per year: ");
	scanf("%f", &fixedAmount);
	result = calculateRepayment(loan,IntrestRate,years);
	printf("%f\n",result);
	
}
//recursion breaks down the problem into simpler smaller problems in this case repeated calculations are done
//such adding the intrest subracting the fixed amount and then displaying the loan before and after payment
//its easier to add functions in recursion 
//its easier to read since there are no repeated loops being used 
//each recursion calculates a year worth of loan payment
