#include <stdio.h>

int main(void){
    double length = 1.0;
    int nt = 100;
    int nx = 50;
    double alpha = 0.1;
    double t_target = 0.05;
    
    double dx = length / (nx - 1);
    double dt = t_target / nt;
    double r = (alpha * dt) / (dx * dx);

    
    printf("Time step: %g\n", dt);

    
    if (r < 0.5)
        printf("Stable FTCS\n");
    
    printf("stability_factor: %g\n", r);
    
    double temp[nx] = {};
    
    for(int i = nx / 3; i < 2 * nx / 3; i++)
        temp[i] = 100.0;
    
    
    double new_temp[nx] = {};
    
    printf("%d\n", nx);
    
    FILE *fp = fopen("ftcs(0.05).dat", "w");
    
    for(int i = 0; i < nt; i++){
        for(int j = 1; j < nx - 1; j++){
            new_temp[j] = temp[j] + r * (temp[j - 1] - 2 * temp[j] + temp[j + 1]);
        }
        new_temp[0] = 0;
        new_temp[nx - 1] = 0;
        for(int j = 0; j < nx; j++)
            temp[j] = new_temp[j];
    }
    
    for(int i = 0; i < nx; i++){
        fprintf(fp, "%g %g\n", i * dx, temp[i]);
    }
    fclose(fp);
    
    return 0;
}