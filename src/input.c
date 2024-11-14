#include <header.h>  

// Funktion som tager input fra bruger og gemmer gpa og favorite subject i et struct student_profile
void inputData() {
    student_profile addStudent(){
        student_profile user_profile;

        printf("Enter your grade average: ");
        scanf("%lf", &user_profile.gpa);

        printf("Enter your favorite subject: ");
        scanf("%s", &user_profile.favorite_subject); 

        return user_profile;
    }    
}
