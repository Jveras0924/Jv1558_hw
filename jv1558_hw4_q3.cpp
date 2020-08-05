
#include <iostream>
using namespace std;

int main() {

    int decimal_num, rem, num, i;

    cout << "Please enter decimal number: " << endl;
    cin >> decimal_num;

    if (decimal_num >= 64 && decimal_num < 128) {
        for (i = 64; i > 0; i /= 2) {
            if (decimal_num >= i) {
                cout << 1;
                decimal_num -= i;
            } else
                cout << 0;
        }
    }
    else if (decimal_num >= 512) {
        for (i = 512; i > 0; i /= 2) {
            if (decimal_num >= i) {
                cout << 1;
                decimal_num -= i;
            } else
                cout << 0;
        }
    }
    else if(decimal_num >= 256 && decimal_num < 512){
        for(i = 256; i > 0; i/= 2){
            if(decimal_num >= i){
                cout << 1;
                decimal_num -= i;
            }
            else
                cout << 0;
        }
    }
    else if(decimal_num >= 128 && decimal_num < 256){
        for(i = 128; i > 0; i/= 2){
            if(decimal_num >= i){
                cout << 1;
                decimal_num -= i;
            }
            else
                cout << 0;
        }
    }
    else if(decimal_num >= 32 && decimal_num < 64){
        for(i = 32; i > 0; i/= 2){
            if(decimal_num >= i){
                cout << 1;
                decimal_num -= i;
            }
            else
                cout << 0;
        }
    }
    else if(decimal_num >= 16 && decimal_num < 32){
        for(i = 16; i> 0; i/=2){
            if(decimal_num >= i){
                cout << 1;
                decimal_num -= i;
            }
            else
                cout << 0;
        }
    }
    else if(decimal_num >= 8 && decimal_num < 16){
        for(i = 8; i> 0; i/=2){
            if(decimal_num >= i){
                cout << 1;
                decimal_num -= i;
            }
            else
                cout << 0;
        }
    }
    else if(decimal_num >= 4 && decimal_num < 8){
        for(i = 4; i > 0; i /= 2){
            if(decimal_num >= i){
                cout << 1;
                decimal_num -= i;
            }
            else
                cout << 0;
        }
    }
    else if(decimal_num >= 2 && decimal_num < 4){
        for(i = 2; i > 0; i /= 2){
            if(decimal_num >= i){
                cout << 1;
                decimal_num -= i;
            }
            else
                cout << 0;
        }
    }
    else if(decimal_num >= 1 && decimal_num < 2){
        for(i = 1; i > 0; i /= 2){
            if(decimal_num >= i){
                cout << 1;
                decimal_num -= i;
            }
            else
                cout << 0;
        }
    }

    return 0;
}