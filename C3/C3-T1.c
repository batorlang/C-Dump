#include <stdio.h>

int main() {
    float usage, total;
    printf("How much electricity did you use this month?\n");
    if (scanf("%f", &usage) != 1) {
        return 1;
    }

    //Tier 1
    if (usage <= 500.0) {
        total = usage * 0.18;
    }

    //Tier 2
    else if (usage <= 1000.0) {
        total = (500.0*0.18) + ((usage - 500.0) * 0.21);
    }

    //Tier 3
else {
    total = (500.0 * 0.18) + (500.0 * 0.21) + ((usage - 1000.0) * 0.25);
}

printf("Total electricity bill this month is %.2f EUR.\n", total);

return 0;

}