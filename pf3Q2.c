#include <stdio.h>

int calculateFuel(int fuel,int consumption, int recharge, int solarBonus, int totalPlanets);

int visitedPlanets=1;
int calculateFuel(int fuel,int consumption, int recharge, int solarBonus, int totalPlanets){
	char choice;
	if(fuel<=0 || visitedPlanets>totalPlanets){
		return 0;
	}
	else{
		fuel=fuel-consumption;
		printf("Is the space craft recharging? (y/n): ");
		scanf(" %c", &choice);
		if(choice=='y'){
			fuel=fuel+recharge;
		}
		if(visitedPlanets%4==0){
			printf("Solar bonus\n");
			fuel=fuel+solarBonus;
		}
		printf("Planet %d and the Fuel Left is %d \n", visitedPlanets, fuel);
		visitedPlanets++;
		calculateFuel(fuel,consumption,recharge,solarBonus,totalPlanets);
	}
}
int main(){
	int fuel,consumption,recharge,solarBonus,totalPlanets;
	printf("Enter the total fuel: ");
	scanf("%d", &fuel);
	printf("Enter the fixed consumption of fuel per planet: ");
	scanf("%d", &consumption);
	printf("Enter the recharge amount that takes place due to changing conditions: ");
	scanf("%d", &recharge);
	printf("Enter the amount of fuel restored due to solar bonus: ");
	scanf("%d", &solarBonus);
	printf("Enter the total number of planets to be visited: ");
	scanf("%d", &totalPlanets);
	calculateFuel(fuel,consumption,recharge,solarBonus,totalPlanets);
}
