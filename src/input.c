#include <header.h>  

// Dette er c filen til hvordan input skal koere i programmet


#define NAME_LENGTH 25
#define SUBJECT_NAME 25

void inputData()
{

typedef struct student_profile
{
    char name[NAME_LENGTH + 1];
    double gpa;
    int school_type;
    char favorite_subject[SUBJECT_NAME + 1];
} student_profile;

void addStudent(struct student_profile *prof)

void addStudent(struct student_profile *prof)
{
    printf("Enter your name:  ");
    scanf("%s", &prof->name);

    printf("Enter your grade average: ");
    scanf("%lf", &prof->gpa);

    printf("Enter your secondary education (1 = STX, 2 = HHX, 3 = HTX, 4 = HF): ");
    scanf("%d", &prof->school_type);

    printf("Enter your favorite subject: ");
    scanf("%s", &prof->favorite_subject); 

}
    
}
