#include <stdio.h>
#include <math.h>

int main() {

    double x,z,y;
    double u;
    double mu = -1e100;
    double mx,my,mz;
    double hx = 1.3;
    double hy = 0.1;
    double hz = 0.8;

	for (x = 1.0; x<3.0;x += hx) {
	    for (y = -.2;y >= -0.4; y -= hy) {
		for (z = 0.5; z <= 1.5; z += hz) {
		    u= -sqrt(y*y+4.0*x*x/3.0+(sin(x*x*x-y) - fabs(x*y))/(x*z));
		    printf("%.1f %.1f %.1f %.6f\n",x,y,z,u);
		    if (u >mu) {
		        mu=u;
			mx=x;
			my=y;
			mz=z;
		    }
		}
	    }
	}

printf("\n%.6f\n",mu);
printf("\n%.1f %.1f %.1f\n",mx,my,mz);

return 0;
}
