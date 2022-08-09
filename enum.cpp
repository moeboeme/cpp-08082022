#include <iostream>

using namespace std;

enum class Color {red, blue, green};
enum class Traffic_light {red, green, yellow};

string get_color_string(Color color){
    switch(color){
        case Color::red:
            return "rojito";
        case Color::blue:
            return "Azulino";
        default:
            return "Green";
    }
}

string get_traffic_color_string(Traffic_light color){
    switch(color){
        case Traffic_light::red:
            return "rojito";
        case Traffic_light::green:
            return "Green";
        default:
            return "Yellow";
    }
}

int main(){
    

    Color col = Color::red;
    Traffic_light light {Traffic_light::yellow};

    cout << "Color primario: " << get_color_string(col) << '\n';
    cout << "Luz semaforo: " << get_traffic_color_string(light) << '\n';

    return EXIT_SUCCESS;
}