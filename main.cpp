#include <iostream>
#include "address.h"
#include "date.h"
#include "student.h"

int main(){
    Address a;
    a.init("123 W Main St", "Muncie", "IN", "47303");
    a.printAddress();
    // end testAddress

    Date d;
    d.init("01/27/1997");
    d.printDate();
    // end testDate

    Student r;
    r.init("Ava,Nguyen,12 Oak St,Springfield,IL,62701,01/15/2006,06/01/2024,24");
    r.printStudent();
    // end testStudent

    return 0;
}
