#include <cstdio>

int main() {

    float input = -1.0;

    while (true) {

        // Check if end of input
        scanf ("%f", &input);
        if (input == 0.00){
            break;
        }

        int i = 1;
        for (float cards = 0.00 ; cards < input; ++i){

            // Check if an additional card will exceed the distance
            if ( cards + 1/(i+1)  <= input ) {
                cards += 1/((float)i+1);
            }
            else {
                break;
            }
        }

        // Finally print number of cards
        printf ("%d card(s)\n", i-1);
    }

}
