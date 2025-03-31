#include <stdio.h>
int main(){
	int age;
	float height, weight;
	
	printf("Enter your age:");
	scanf("%d",&age);
	
	printf("Enter your height:");
	scanf("%f",&height);
	
	printf("Enter your weight:");
	scanf("%f",&weight);
	
	printf("You're %d years old, %.2f cm. tall and Damn you weigh %.2f!!",age, height, weight);
	return 0;
}
