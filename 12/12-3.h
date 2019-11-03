void set_mode(int m, int *mode) {
    if (m == 0)
        *mode = 0;
    else if (m == 1)
        *mode = 1;
    else {
        *mode = 1;
        puts("Invalid mode specified. Mode 1 (US) used.");
    }
}

void get_info(int mode, float *distance, float *fuel) {
    if (mode == 0)
        puts("Enter distance traveled in kilometers:");
    else
        puts("Enter distance traveled in miles:");
    scanf("%f", distance);
    if (mode == 0)
        puts("Enter fuel consumed in litres:");
    else
        puts("Enter fuel consumed in gallons:");
    scanf("%f", fuel);
}

void show_info(int mode, float *distance, float *fuel) {
    if (mode == 0) {
        printf("Fuel consumption is %.1f litres per 100km.\n",
                (*fuel / *distance) * 100);
    }
    else if (mode == 1) {
        printf("Fuel consumption is %.1f miles per gallon.\n",
                *distance / *fuel);
    }
    else
        puts("Invalid mode specified");
}
