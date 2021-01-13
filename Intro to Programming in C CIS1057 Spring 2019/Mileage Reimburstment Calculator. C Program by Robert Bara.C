#include <stdio.h>
#include <stdlib.h>
/*
 * Programmer: Robert Bara
 * Class:      CIS 1057
 * Date:       January 22, 2019
 *
 */

int main() {
    /* beginning_Oddometer is an Input-Beginning Oddometer Reading: 32155.2
       ending_Oddometer is an Input-Ending Oddometer Reading: 32310.7
       mileage will be an Output- The Salesperson's Distance
       reimburstment will be an Output- The total Reibmurstment (Reimburstment per mile + Reimburstment)*/

    double beginning_oddometer, ending_oddometer, mileage,reimburstment;

    printf("Mileage Reimburstment Calculator. C Program by Robert Bara \n"
           "To Calculate the Mileage Reimburstment of a Salesperson.\n");

    printf("Enter the Starting Oddometer: ");
    scanf("%lf", &beginning_oddometer);    //Calculate Beginning Oddometer

    printf("Enter the Ending Oddometer: ");
    scanf("%lf", &ending_oddometer);       //Calculate Ending Oddometer

    // Perform Calculations Change in Mileage and multiplied by Reimburstment
     mileage = ending_oddometer - beginning_oddometer;
     reimburstment = 0.35 * mileage;

    // Display Results
    printf("The total distance travelled is %.1lf miles.\n "
           "At $0.35 per mile, the total reimburstment is $%.3lf.\n", mileage,
           reimburstment);
    return EXIT_SUCCESS;
}



SCRIPT:

C:\Users\Robert\CLionProjects\untitled1\cmake-build-debug\untitled1.exe
Mileage Reimburstment Calculator. C Program by Robert Bara
To Calculate the Mileage Reimburstment of a Salesperson.
Enter the Starting Oddometer:32155.2
 32155.2
Enter the Ending Oddometer:32310.7
 32310.7
The total distance travelled is 155.5 miles.
 At $0.35 per mile, the total reimburstment is $54.42.

Process finished with exit code 0

C:\Users\Robert\CLionProjects\untitled1\cmake-build-debug\untitled1.exe
Mileage Reimburstment Calculator. C Program by Robert Bara
To Calculate the Mileage Reimburstment of a Salesperson.
Enter the Starting Oddometer:18520
 18520
Enter the Ending Oddometer:20985
 20985
The total distance travelled is 2465.0 miles.
 At $0.35 per mile, the total reimburstment is $862.75.

Process finished with exit code 0

C:\Users\Robert\CLionProjects\untitled1\cmake-build-debug\untitled1.exe
Mileage Reimburstment Calculator. C Program by Robert Bara
To Calculate the Mileage Reimburstment of a Salesperson.
Enter the Starting Oddometer:100
 100
Enter the Ending Oddometer:450
 450
The total distance travelled is 350.0 miles.
 At $0.35 per mile, the total reimburstment is $122.50.

Process finished with exit code 0

C:\Users\Robert\CLionProjects\untitled1\cmake-build-debug\untitled1.exe
Mileage Reimburstment Calculator. C Program by Robert Bara
To Calculate the Mileage Reimburstment of a Salesperson.
Enter the Starting Oddometer:7898.6
 7898.6
Enter the Ending Oddometer:8970.4
 8970.4
The total distance travelled is 1071.8 miles.
 At $0.35 per mile, the total reimburstment is $375.13.

Process finished with exit code 0

C:\Users\Robert\CLionProjects\untitled1\cmake-build-debug\untitled1.exe
Mileage Reimburstment Calculator. C Program by Robert Bara
To Calculate the Mileage Reimburstment of a Salesperson.
Enter the Starting Oddometer:454642125451245484846323215456450.25
 454642125451245484846323215456450.25
Enter the Ending Oddometer:5656568953959922222330232332323032659887.5
 5656568953959922222330232332323032659887.5
The total distance travelled is 5656568499317796000000000000000000000000.0 miles.
 At $0.35 per mile, the total reimburstment is $1979798974761228600000000000000000000000.00.

Process finished with exit code 0

