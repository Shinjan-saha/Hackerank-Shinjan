int marks_summation(int* p, int number_of_students, char gender) {
    int s = 0, i = 0;
    if (gender == 'g') {
        i++;
    }
    for (; i < number_of_students; i = i+2) {
        s += p[i];       
    }
    return s;
