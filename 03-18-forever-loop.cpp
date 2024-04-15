// #include "Cen_Heat.h" // include a user-defined header file

void init(void) {
    return;
}

void Get_Required_Temperature(void) {
    return;
}

void Get_Actual_Temperature(void) {
    return;
}

void Control_Boiler(void) {
    return;
}

int main(void) {
// Init the system
    init();
    while(1) { // 'for ever' (Super Loop)
        Get_Required_Temperature(); // Find temperature the user requires (via the user interface)
        Get_Actual_Temperature(); // Find current room temperature is (via temperature sensor)
        Control_Boiler(); // Adjust the gas burner, as required
    }
    return 0;
}
