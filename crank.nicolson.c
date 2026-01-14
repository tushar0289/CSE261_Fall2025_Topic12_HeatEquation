#include <stdio.h>

int main(void){
    int nx = 50;
    int nt = 5000; // number of time steps in that simulation
    double length = 1.0;
    double t_max = 0.1; // max simulation time
    double alpha = 0.1;
    double t_target = 0.1;
    
    double dx = length / (nx - 1);
    double dt = t_target / nt; // difference btwn each time step
    double r = (alpha * dt) / (dx * dx);
    
    double u[nx], d[nx], u_new[nx];
    double a[nx], b[nx], c[nx], c_prime[nx], d_prime[nx];
    
    for (int i = 0; i < nx; i++){
        u[i] = 0.0;
        if (i > nx/3 && i < 2*nx/3) u[i] = 100.0; 
    }
    
    u[0] = 0;
    u[nx - 1] = 0;
    
    double A = -r / 2.0;
    double B = 1.0 + r;
    double C = -r / 2.0;
    
    FILE *fp = fopen("refernce.txt", "w");
    
    for(int i = 0; i < nx; i++){
        for(int i = 1; i < nx - 1; i++){
            d[i] = (r / 2.0) * u[i - 1] + (1.0 - r) * u[i] + (r / 2.0) * u[i + 1];
        }
        
        d[1] -= A * u[0];
        d[nx - 2] -= C * u[nx - 1];
        
        c_prime[1] = C / B;
        d_prime[1] = d[1] / B;
        for(int i = 2; i < nx - 1; i++){
            double m = B - A * c_prime[i - 1];
            c_prime[i] = C / m;
            d_prime[i] = (d[i] - A * d_prime[i - 1])/ m;
            u_new[nx-2] = d_prime[nx-2];
            for (int i = nx - 3; i >= 1; i--) {
                u_new[i] = d_prime[i] - c_prime[i] * u_new[i+1];
            }
            for (int i = 1; i < nx - 1; i++) u[i] = u_new[i];
        }
    }
    
    for (int i = 0; i < nx; i++) {
        fprintf(fp, "%f %f\n", i * dx, u[i]);
    }
    fclose(fp);
    
    return 0;
}