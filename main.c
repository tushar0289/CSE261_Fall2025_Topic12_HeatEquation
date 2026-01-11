// Not ready to output files
// Need more calculation

#include <stdio.h>

double sqr(double x);

int main(void){
    double rod_length = 1.0;
    double grid_spacing = 0.05;
    double diffusivity = 0.25;
    double stability_factor = 0.25;
    double time_step = (stability_factor * sqr(grid_spacing)) / diffusivity;
    
    printf("Time step: %g\n", time_step);
    
    double n;
    printf("Enter time: \n");
    scanf("%lf", &n);
    printf("Showing result for %g second FTCS\n", n);
    
    int time_itr = n / time_step;
    int space_itr = rod_length / grid_spacing + 1;
    
    if (stability_factor < 0.5)
        printf("Stable FTCS\n");
    
    printf("stability_factor: %g\n", stability_factor);
    
    double temp[space_itr] = {};
    int mid = space_itr / 2;
    
    temp[mid] = 100.0;
    
    
    double new_temp[space_itr] = {};
    
    printf("%d\n", time_itr);
    
    FILE *fp = fopen("ftcs.dat", "w");
    
    for(int i = 0; i < time_itr; i++){
        for(int j = 1; j < space_itr - 1; j++){
            new_temp[j] = temp[j] + stability_factor * (temp[j - 1] - 2 * temp[j] + temp[j + 1]);
        }
        new_temp[0] = 0;
        new_temp[space_itr - 1] = 0;
        for(int j = 0; j < space_itr; j++)
            temp[j] = new_temp[j];
    }
    
    for(int i = 0; i < space_itr; i++){
        fprintf(fp, "%g %g\n", i * grid_spacing, temp[i]);
    }
    fclose(fp);
    
    return 0;
}

double sqr(double x){
    return x * x;
}