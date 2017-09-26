#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRSIZ 10

typedef struct {
	char name[STRSIZ];	//10
	double diameter_m;	//8
	int moons;			//4
//	int position, pos1, pos2, pos3;	//16
	double orbit_time_d,rotation_time_h;		//16
//	double mass; //8
} planet_t;

int main()
{
	planet_t p1;
	planet_t p[2];
	int st, end;

	st = &p[0];
	end = &p[1];
	//,p2={"Saturn", 120536000, 62, 10759.22, 10.53};

	printf("\nMemory allocated to p1 is %u bytes\n",sizeof(p1));
	printf("\nMemory allocated to p1 is %u bytes\n",sizeof(planet_t));
	printf("\nMemory allocated to double is %u bytes\n",sizeof(double));
	printf("\nMemory allocated to int is %u bytes\n",sizeof(int));

	printf("\nMemory Diff is %u bytes\n", end - st);
/*	strcpy(p1.name, "Jupiter");
	p1.diameter_m = 142984000;
	p1.moons = 67;
	p1.orbit_time_d = 4332.59;
	p1.rotation_time_h = 9.925;

	printf("\nName : %s\n", p1.name);
	printf("\nDiameter : %.0lf meters\n",p1.diameter_m);
	printf("\nMoons : %d",p1.moons);
	printf("\nOrbit time : %.2lf days\n", p1.orbit_time_d);
	printf("\nRotation time : %.3lf hours\n", p1.rotation_time_h);

	printf("\nName : %s\n", p2.name);
	printf("\nDiameter : %.0lf meters\n",p2.diameter_m);
	printf("\nMoons : %d",p2.moons);
	printf("\nOrbit time : %.2lf days\n", p2.orbit_time_d);
	printf("\nRotation time : %.3lf hours\n", p2.rotation_time_h);
*/
	return 0;
}

