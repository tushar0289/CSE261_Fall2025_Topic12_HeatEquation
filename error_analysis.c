#include <stdio.h>
#include <math.h>

int main(void){
    FILE *fref = fopen("reference.txt", "r");
    FILE *fftcs = fopen("ref_ftcs(0.1).dat", "r");
    FILE *fcn = fopen("ref_crank_nicolson(0.1).txt", "r");
    FILE *f_error = fopen("error_analysis.txt", "w");
    
    double x, u_ref, u_ftcs, u_cn;
    
    fprintf(f_error, "x ftcs_error cn_error");
    
    while(fscanf(fref, "%lf %lf", &x, &u_ref) != EOF && fscanf(fftcs, "%*f %lf", &u_ftcs) != EOF && fscanf(fcn, "%*f %lf", &u_cn) != EOF){
        double err_ftcs = fabs(u_ftcs - u_ref);
        double err_cn = fabs(u_cn - u_ref);
        
        fprintf(f_error, "%8g %12e %12e\n", x, err_ftcs, err_cn);
    }
    
    
    fclose(fref);
    fclose(fftcs);
    fclose(fcn);
    fclose(f_error);
    return 0;
}