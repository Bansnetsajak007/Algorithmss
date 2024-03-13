#include<stdio.h>

float percentage(int marks[],int size){
    int total_marks=(size*100);
    int obt_marks=0;
    for (int i = 0; i < size; i++)
    {
        obt_marks=obt_marks+marks[i];
    }

    float percentage= ( (float) obt_marks/total_marks)*100;

    return percentage;
    
}


void grade_checker(float percentage){
    if (percentage>0 && percentage<=20){
        printf("You got Grade E");
    }

    else if (percentage>20 && percentage<=40){
        printf("You got Grade D");
    }

    else if (percentage>40 && percentage<=60){
        printf("You got Grade C");
    }

    else if (percentage>60 && percentage<=80){
        printf("You got Grade B");
    }    

    else{
        printf("You got Grade A");
    }


}



int main(){
    int n;

    printf("Enter the number of subjects: ");
    scanf("%d", &n);

    int marks[n];


    for (int i = 0; i < n; i++)
    {
    printf("enter the marks of subject %d: ",i+1);
    scanf("%d",&marks[i]);
        
    }


    float resault= percentage(marks,n);


    printf("YOur percentage is %f%%",resault);
    printf("\n");
    grade_checker(resault);

    return 0;
}