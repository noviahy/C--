#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main()
{
	float kg, meter, BMI;

	printf("\n type your weight \n");
	scanf("%f", &kg);
	printf("\n type your height \n");
	scanf("%f", &meter);

	BMI = kg / (meter * meter);

	if (BMI < 18.5)
	{
		printf("\n BMI = %f, it is underweight \n", BMI);
	}
	else if ((18.5 <= BMI) && (BMI < 25))
	{
		printf("\n BMI = %f, it is normal \n", BMI);
	}
	else 
	{
		printf("\n BMI = %f, it is overweight \n", BMI);
	}
}