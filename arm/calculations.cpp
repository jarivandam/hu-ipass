#include "math.h"
#include "calculations.hpp"
#include "coordinate.hpp"
int calc_positions(int &len1,int &len2,coordinate &position,uint16_t &servo1, uint16_t &servo2){
    int x = position.get_x();
    int y = position.get_y();
    if (x > 0 && y > 0){
        float pre_servo2 = atan2(sqrt(1-((pow(x,2)+pow(y,2) - pow(len1,2) - pow(len2,2))/(2*len1*len2))), ((pow(x,2) + pow(y,2) + pow(len1,2) + pow(len2,2))/(2*len1*len2)));
        float k1 = len1+(len2*cos(pre_servo2));
        float k2 = len2*sin(pre_servo2);
        float pre_servo1 = atan2(y,x) + atan2(k2,k1);
         // 90 degrees in radians 
        if (pre_servo1  > 1.57079633 || pre_servo1 < 0){
            pre_servo2 = atan2(-sqrt(1-((pow(x,2)+pow(y,2) - pow(len1,2) - pow(len2,2))/(2*len1*len2))), ((pow(x,2) + pow(y,2) + pow(len1,2) + pow(len2,2))/(2*len1*len2)));
            float k1 = len1+(len2*cos(pre_servo2));
            float k2 = len2*sin(pre_servo2);
            pre_servo1 = atan2(y,x) + atan2(k2,k1);
            if (servo1 >=0  && servo2 >= 0){ 
                servo1 = (pre_servo1 * 180)/3.14;
                servo2 = (pre_servo2 * 180)/3.14;
                return 0;
            }
            else{
                return 1;
            }
        }
        else {
            if (servo1 >=0  && servo2 >= 0){ 
                servo1 = (pre_servo1 * 180)/3.14;
                servo2 = (pre_servo2 * 180)/3.14;
                return 0;
            }  
            else{
                return 1;
            }

        }
    }
    else{
        return 1;
    }
}
