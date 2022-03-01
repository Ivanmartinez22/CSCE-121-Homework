#include <iostream>
#include "functions.h"

using std::cout;
using std::endl;

int digit_counter(int a){
	bool check = false;
	int counter = 0; 
    int a_copy = a;
	while(check == false){
		a_copy /= 10;
		counter ++;
		if(a_copy == 0){
			check = true;
		}
	}
    counter -= 1;
	return counter;
}

bool is_valid_range(int a, int b){
	// TODO(student): validate input range
	bool validity;
	if((a > b) || (a < 0) || (b > 9999)){
		validity = false;
	}
	else{
		validity = true;
	}
	return validity;
}

char classify_mv_range_type(int number) {
    // TODO(student): return 'M' if number has /\/\... pattern,
    // return 'V' if number has \/\/ pattern, and return 'N' otherwise
    int right;
    int left;
    int num_of_digits = 0;
    int change = 0;
    num_of_digits += digit_counter(number);
    char return_value;
    while (num_of_digits > 0){
        right = number % 10;
        number = number / 10;
        left = number % 10;
        num_of_digits -= 1;
        if (left == right){
            return_value = 'N';
            break;
        }
        if (right < left){
            if (change == 0){
                change+=1;
            }
            else if (change == -1){
                change +=2;
            }
            else{
                return_value = 'N';
                 break;
                }
            }
        if (right > left){
            if (change == 0){
                change -= 1;
            }
            else if (change == 1){
                change -= 2;
            }
            else{
                return_value = 'N';
                break;
            }
        }
        if (num_of_digits == 0){
            if (right > left){
                 return_value = 'M';
            }
            if (right < left){
                return_value = 'V';
            }
        }
    }
    return return_value;
}

void count_valid_mv_numbers(int a, int b) {
	// TODO(student): count the number of valid mountain ranges and valley
	// ranges in the range [a, b] and print out to console using the format
	// in Requirement 4 of the homework prompt
	int mountains = 0;
	int valleys = 0;
	int neither = 0;
	
	for(int i = a; i <= b; i++){
		char range_type = classify_mv_range_type(i);
		if(range_type == 'M'){
			mountains++;
		}
		else if(range_type == 'V'){
			valleys++;
		}
		else{
			neither++;
		}
	}
	cout << "There are " << mountains << " mountain ranges and " << valleys << " valley ranges between " << a << " and " << b << "." << endl;
}
	