#include <stdio.h>
#include <math.h>

// Swap function for swapping two values
void swap(double *x, double *y) {
    double temp = *x;
    *x = *y;
    *y = temp;
}

// Bubble sort function to sort lab_grades in ascending order
void bubble_sort(double *lab_grades, int size) {
    for (int i = 0; i < size - 1; i++) { // Outer loop for each element
        for (int j = 0; j < size - i - 1; j++) { // Inner loop for comparing adjacent elements
            if (lab_grades[j] > lab_grades[j + 1]) {
                swap(&lab_grades[j], &lab_grades[j + 1]); // Swap if elements are in wrong order
            }
        }
    }
}

// Corrected rwb function
double rwb(double *lab_grades, int size) {
    // Assume lab_grades is sorted in ascending order
    double total_excess_marks = 0.0;
    for (int i = 0; i < 5; i++) { // For the worst 5 grades
        total_excess_marks += lab_grades[i] * 0.08; // Each lab grade times 8%
    }

    double rwb_value = 0.03 * sqrt(total_excess_marks); // 3% times sqrt(total excess marks)
    return rwb_value; // Return RWB value as decimal fraction (e.g., 0.0849)
}

int main() {
    double rwb_value1 = 0.0; // Initialize rwb properly
    double lab_grades1[] = {96, 100, 100, 100, 96.67, 0, 0, 0, 0, 0}; // Sample data from your example
    int size1 = sizeof(lab_grades1) / sizeof(lab_grades1[0]);

    // Call bubble_sort with a pointer to lab_grades
    bubble_sort(lab_grades1, size1);

    // Compute rwb_value using corrected rwb function
    rwb_value1 = rwb(lab_grades1, size1);

    double exam_percentage1 = 0.6 - rwb_value1; // Exam weight is 60% minus RWB
    if (exam_percentage1 < 0) {
        exam_percentage1 = 0;
    }

    double best_grades_sum1 = 0.0;
    for (int i = 0; i < 5; i++) { // Sum the best 5 grades
        best_grades_sum1 += lab_grades1[size1 - 1 - i]; // Use the highest grades after sorting
    }

    double lab_final_grade1 = (best_grades_sum1 / 5) / 100.0; // Average of best 5 grades, converted to fraction

    // For testing, let's assume exam_grade is 70%
    double exam_grade1 = 0.0; // Corrected exam_grade initialization

    // Now compute the final grade
    double final_grade1 = (lab_final_grade1 * 0.4) + (exam_grade1 * exam_percentage1) + rwb_value1;

    // Convert final_grade to percentage
    final_grade1 *= 100.0;

    printf("Lab final grade in 2CD4: %.2f%%\n", lab_final_grade1 * 100.0);
    printf("RWB in 2CD4: %.2f%%\n", rwb_value1 * 100.0);
    printf("Exam percentage in 2CD4: %.2f%%\n", exam_percentage1 * 100.0);
    printf("Your final grade in 2CD4: %.2f%%\n", final_grade1);

/// below is for a differnet course with same outline
    printf("**********\n");
    double rwb_value2 = 0.0; // Initialize rwb properly
    double lab_grades2[] = {84.19, 78.42, 90.38, 100, 100, 0, 0, 0, 0, 0}; // Sample data from your example
    int size2 = sizeof(lab_grades2) / sizeof(lab_grades2[0]);

    // Call bubble_sort with a pointer to lab_grades
    bubble_sort(lab_grades2, size2);

    // Compute rwb_value using corrected rwb function
    rwb_value2 = rwb(lab_grades2, size2);

    double exam_percentage2 = 0.6 - rwb_value2; // Exam weight is 60% minus RWB
    if (exam_percentage2 < 0) {
        exam_percentage2 = 0;
    }

    double best_grades_sum2 = 0.0;
    for (int i = 0; i < 5; i++) { // Sum the best 5 grades
        best_grades_sum2 += lab_grades2[size2 - 1 - i]; // Use the highest grades after sorting
    }

    double lab_final_grade2 = (best_grades_sum2 / 5) / 100.0; // Average of best 5 grades, converted to fraction

    // For testing, let's assume exam_grade is 70%
    double exam_grade2 = 0.0; // Corrected exam_grade initialization

    // Now compute the final grade
    double final_grade2 = (lab_final_grade2 * 0.4) + (exam_grade2 * exam_percentage2) + rwb_value2;

    // Convert final_grade to percentage
    final_grade2 *= 100.0;

    printf("Lab final grade in 2P04: %.2f%%\n", lab_final_grade2 * 100.0);
    printf("RWB in 2P04: %.2f%%\n", rwb_value2 * 100.0);
    printf("Exam percentage in 2P04: %.2f%%\n", exam_percentage2 * 100.0);
    printf("Your final grade in 2P04: %.2f%%\n", final_grade2);







    return 0;
}
