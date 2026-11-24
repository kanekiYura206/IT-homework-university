#include <stdio.h>
#include <math.h>
#include <stdbool.h>

enum Function {
    SIN,
    COS,
    EXP,
    SINH
};

double pow_over_fact(double x, int p) {
    double r = 1.0;
    for (int i = 1; i <= p; i++) r *= fabs(x) / i;
    return r;
}


// 1.Taylor expansion
double sin_taylor_expansion(double x, int count_terms) {
    double sum = 0.0;
    double term = x;

    for(int k = 0; k < count_terms; k++) {
        sum += term;
        term *= -x * x / ((2.0 * k + 2) * (2.0 * k + 3));
    }

    return sum;
}

double cos_taylor_expansion(double x, int count_terms) {
    double sum = 0.0;
    double term = 1.0;

    for(int k = 0; k < count_terms; k++) {
        sum += term;
        term *= -x * x / ((2.0 * k + 1) * (2.0 * k + 2));
    }

    return sum;
}

double exp_taylor_expansion(double x, int count_terms) {
    double sum = 0.0;
    double term = 1.0;

    for(int k = 0; k < count_terms; k++) {
        sum += term;
        term *= x / (k + 1);
    }

    return sum;
}

double sinh_taylor_expansion(double x, int count_terms) {
    double sum = 0.0;
    double term = x;

    for (int k = 0; k < count_terms; k++) {
        sum += term;
        term *= x * x / ((2.0 * k + 2) * (2.0 * k + 3));
    }

    return sum;
}


// 2.Errors
double sin_error(double x, int count_terms) {
    return pow_over_fact(x, 2*count_terms + 1);
}

double cos_error(double x, int count_terms) {
    return pow_over_fact(x, 2*count_terms);
}

double exp_error(double x, int count_terms) {
    return exp(x > 0 ? x : 0) * pow_over_fact(x, count_terms);
}

double sinh_error(double x, int count_terms) {
    return cosh(x) * pow_over_fact(x, 2*count_terms + 1);
}


// 3.Getters
double get_reference_function(int function, double x) {
    double (*reference[4])(double) = {
        sin,
        cos,
        exp,
        sinh
    };

    return reference[function](x);
}

double get_taylor_function(int function, double x, int count_terms) {
    double (*taylor[4])(double, int) = {
        sin_taylor_expansion,
        cos_taylor_expansion,
        exp_taylor_expansion,
        sinh_taylor_expansion
    };

    return taylor[function](x, count_terms);
}

double get_error_estimation(int function, double x, int count_terms) {
    double (*error[4])(double, int) = {
        sin_error,
        cos_error,
        exp_error,
        sinh_error
    };

    return error[function](x, count_terms);
}


// 4.Operating modes
void first_mode() {
    int command, count_terms;
    double x, error;

    printf("\nChoose the function\n");
    printf("\n1 - sin(x)\n");
    printf("\n2 - cos(x)\n");
    printf("\n3 - exp(x)\n");
    printf("\n4 - sinh(x)\n");
    printf("\n5 - to start\n");

    // Input function
    while(true) {
        if((scanf("%d", &command) == 1) && (command >= 1 && command <= 5)) {
            if(command == 5) return;
            break;
        }
        
        printf("\nInvalid input :(\nTry again:\n");

        int ch;
        while((ch = getchar()) != '\n' && ch != EOF);
    }

    // Input point
    printf("\nEnter the required point:\n");
    while(true) {
        if(scanf("%lf", &x) == 1) break;

        printf("\nInvalid input :(\nTry again:\n");

        int ch;
        while((ch = getchar()) != '\n' && ch != EOF);
    }

    // Input error
    printf("\nEnter the required precision (error >= 0.000001):\n");
    while(true) {
        if((scanf("%lf", &error) == 1) && (error >= 0.000001)) break;

            printf("\nInvalid input :(\nTry again:\n");
            
            int ch;
            while((ch = getchar()) != '\n' && ch != EOF);
        }
        
    // Input maximum count of terms
    printf("\nEnter the maximum count of terms (1-1000):\n");

    while(true) {
        if(scanf("%d", &count_terms) == 1 &&
            count_terms >= 1 && count_terms <= 1000)
            break;

        printf("\nInvalid input :(\nTry again:\n");

        int ch;
        while((ch = getchar()) != '\n' && ch != EOF);
    }

    // Calculation
    double reference = get_reference_function(command - 1, x);
    double taylor = 0.0;
    double actual_error = 0.0, error_bound = 0.0;

    int terms_used = 0;
    bool precision_achieved = false;

    for(int n = 1; n <= count_terms; n++) {
        taylor = get_taylor_function(command - 1, x, n);

        error_bound = get_error_estimation(command - 1, x, n);
        actual_error = fabs(reference - taylor);

        terms_used = n;

        if(error_bound <= error) {
            precision_achieved = true;
            break;
        }
    }

    // Output results
    printf("\n---------- RESULTS ----------\n");

    printf("\nReference value:      %.12f", reference);
    printf("\nTaylor approximation: %.12f", taylor);
    printf("\nActual error:         %.12e", actual_error);

    printf("\nTerms used:           %d", terms_used);
    printf("\nRequired precision:   %.12e", error);

    if(precision_achieved)
        printf("\n\nPrecision achieved!");
    else
        printf("\n\nRequired precision was not achieved.");

    printf("\n-----------------------------\n");
}

void second_mode() {
    int command, count_terms;
    double x;

    printf("\nChoose the function\n");
    printf("\n1 - sin(x)\n");
    printf("\n2 - cos(x)\n");
    printf("\n3 - exp(x)\n");
    printf("\n4 - sinh(x)\n");
    printf("\n5 - to start\n");

    // Input function
    while(true) {
        if((scanf("%d", &command) == 1) && (command >= 1 && command <= 5)) {
            if(command == 5) return;
            break;
        }
        
        printf("\nInvalid input :(\nTry again:\n");

        int ch;
        while((ch = getchar()) != '\n' && ch != EOF);
    }

        // Input point
    printf("\nEnter the required point:\n");
    while(true) {
        if(scanf("%lf", &x) == 1) break;

        printf("\nInvalid input :(\nTry again:\n");

        int ch;
        while((ch = getchar()) != '\n' && ch != EOF);
    }

    // Input maximum count of terms
    printf("\nEnter maximum count of terms (1-25):\n");

    while(true) {
        if(scanf("%d", &count_terms) == 1 && count_terms >= 1 && count_terms <= 25) break;

        printf("\nInvalid input :(\nTry again:\n");

        int ch;
        while((ch = getchar()) != '\n' && ch != EOF);
    }

    // Calculation
    double reference = get_reference_function(command - 1, x);

    printf("\nReference value: %.12f\n", reference);

    printf("\n-----------------------------------------------\n");
    printf("Terms\tApproximation\t\tActual error\n");
    printf("-----------------------------------------------\n");

    for(int n = 1; n <= count_terms; n++) {
        double approximation =
            get_taylor_function(command - 1, x, n);

        double actual_error = fabs(reference - approximation);

        printf("%d\t%.12f\t%.6e\n", n, approximation, actual_error);
    }

    printf("-----------------------------------------------\n");
}

void info() {
    printf("\nMode 1 - Calculate a function value with a specified precision or maximum number of terms.\n");
    printf("\nMode 2 - Perform a series of calculations with an increasing number of terms (1 to NMax).\n");
}


// 5.Main
int main() {
    int command;

    printf("\n=== Function value calculator ===\n");
    printf("\n1 - first mode\n");
    printf("\n2 - second mode\n");
    printf("\n3 - info\n");
    printf("\n4 - exit\n");

    while(true) {
        while(true) {
            if(scanf("%d", &command) == 1 && command >= 1 && command <= 4) break;

            printf("\nInvalid input :(\nTry again:\n");

            int ch;
            while((ch = getchar()) != '\n' && ch != EOF);
        }
        
        switch(command) {
        case 1:
            first_mode();
            break;
        
        case 2:
            second_mode();
            break;
        
        case 3:
            info();
            break;
        
        case 4:
            return 0;

        default:
            break;
        }
    }
}
