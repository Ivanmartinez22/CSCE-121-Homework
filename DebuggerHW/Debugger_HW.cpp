#include <iostream>
using namespace std;

int Largest(int a, int b, int c) {
    int d = a;
    if (b > d) {
        d = b;
    }        
    if (c > d){
        d = c;
    }
    return d;
}
bool SumIsEven(int a, int b) {
    bool return_value;
    int sum = a + b;
    double remainder = sum % 2;
    if(remainder == 0){
        return_value = true;
    }
    else{
        return_value = false;
    }
    return return_value;
}
int BoxesNeeded(int apples){
    int remainder = apples % 20; 
    int num_of_boxes = apples/20;
    if(num_of_boxes < 0){
        num_of_boxes = 0;
    }
    else if((apples > 1) && (apples < 20)){
        num_of_boxes = 1;
    }
    else if(remainder != 0){
        num_of_boxes = num_of_boxes + 1;
    }
    return num_of_boxes;
}
bool SmarterSection(double A_correct, double A_total, double B_correct, double B_total) {
    if((A_total <= 0 || B_total <= 0) || (A_correct < 0 || B_correct < 0)){
        throw std::invalid_argument("Invalid Arguments");
    }
    double smart_percentage_a = (A_correct/A_total) * 100;
    double smart_percentage_b = (B_correct/B_total) * 100;
    bool smart_determination = smart_percentage_a > smart_percentage_b;
    return smart_determination;  
}
bool GoodDinner(int pizzas, bool is_weekend) {
    bool return_value;
    if (((pizzas >= 10) && (pizzas <= 20)) || ((is_weekend == true) && (pizzas > 10))){
        return_value = true;
    }
    else{
        return_value = false;
    }
    return return_value;
}
int SumBetween(int low, int high) {
    int value;
    int sum = 0;
    int negative_high = -1 * high;
    int negative_low = -1 * low;
    if(low > high){
        throw std::invalid_argument("Invalid Argument");
    }
    if(low == high){
        value = low;
    }
    if (low == negative_high){
        value = 0;
    }
    if(low == 0){
        low = 1;
    }
    if(high == 0){
        high = -1;
    }
    if(low < 0 && high > 0){
        if(low < negative_high){
            high = negative_high - 1;
        }
        else if(low > negative_high){
            low = negative_low + 1;
        }
    }
    if(low < 0 && high < 0){
        for(int i = low; low <= high; low++){
            sum += low;
            if(sum >= 0){
                throw std::overflow_error("Interger Overflow");
            }
            else{
                value = sum;
            }
        }
    }
    if(low > 0 && high > 0){
        for(int i = low; low <= high; low++){
            sum += low;
            if(sum <= 0){
                throw std::overflow_error("Interger Overflow");
            }
            else{
                value = sum;
            }
        }
    }
    return value;
}
int Product(int a, int b) {
    
    int return_value = a*b;
    int initial = a*b;
    int test_1 = return_value/INT32_MAX;
    int test_2 = return_value/INT32_MIN;
    if((a > 0 && b > 0) && return_value < 0){
        throw std::overflow_error("Interger Overflow");
    }else if((a < 0 && b > 0) && return_value > 0){
        throw std::overflow_error("Interger Overflow");
    }else if((a > 0 && b < 0) && return_value > 0){
        throw std::overflow_error("Interger Overflow");
    }else if((a < 0 && b < 0) && return_value < 0){
        throw std::overflow_error("Interger Overflow");
    }else if(a == 0 || b == 0){
        return_value = 0;
    }
    else if( (a != 0) && ((initial / a) != b )){
        throw std::overflow_error("Interger Overflow");
    }
    return return_value;
}
