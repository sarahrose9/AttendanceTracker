/* NAME: SARAH DIAS BARRETO
   ROLL NO: 19CSE1029

   PROJECT DETAILS: The program is written in c language to assist a student in tracking his/her attendance in a particular course.
                    The student sets a target attendance for each course
                    The program calculates the number of classes needed to be attended to achieve the target attendance if the attendance
                    is below the target attendance.
                    It also calculates the number of classes a student can afford to miss if his/her attendance is well above the target attendance,
                    however this feature should only be used in case of an emergency.
                    Based on the data previously entered the program calculates the attendance when the student attends or misses a class.
 */




#include<stdio.h>
#include<windows.h>
int main()
{
    SetConsoleTitle("ATTENDANCE TRACKER");
    int n;
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    //isystem("color 9E");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|BACKGROUND_RED|BACKGROUND_INTENSITY);
    printf("\nENTER THE TOTAL NUMBER OF SUBJECTS\n");
    scanf("%d",&n);
    int i,b[n];
    int attended[n],missed[n];
    char name[n][10];
    float a[n],target[n];
    int l;
    for(i=0,l=1;i<n,l<n+1;i++,l++)
    {
        SetConsoleTextAttribute(h,l);
        printf("\nENTER THE SUBJECT\n");
        scanf("%s",&name[i]);
        printf("\nENTER TARGET ATTENDANCE PERCENTAGE\n");
        scanf("%f",&target[i]);
        printf("\nENTER NUMBER OF ATTENDED\n");
        scanf("%d",&attended[i]);
        printf("\nENTER NUMBER OF CLASSES MISSED\n");
        scanf("%d",&missed[i]);
        b[i]=attended[i]+missed[i];
        a[i]=(float)attended[i]/(float)b[i];
        a[i]=a[i]*100;
        printf("\nATTENDANCE=%f",a[i]);
        printf("\n");
        if(a[i]<target[i])
        {
            printf("\nNUMBER OF CLASSES NEEDED TO ATTEND=%d",4*missed[i]-attended[i]);
            printf("\n");
        }
        else if(a[i]>=target[i])
        {
            printf("\nNUMBER OF CLASSES YOU CAN MISS=%d",(int)(0.25*attended[i])-missed[i]);
        }
        printf("\n");
    }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED);
       // printf("\n");
        int totalattnd=0,total=0;
        float overall;
        for(i=0;i<n;i++)
        {
            totalattnd=totalattnd+attended[i];
            total=total+b[i];
        }
        overall=((float)totalattnd/(float)total)*100;
        printf("\nYOUR CURRENT OVERALL ATTENDANCE=%f",overall);
printf("\n");

    while(1)
    {
        for(i=0,l=1;i<n,l<n+1;i++,l++)
        {
            SetConsoleTextAttribute(h,l);
            printf("\nSUBJECT=%s",name[i]);
            int c;
            printf("\nPRESS 1 IF YOU ATTENDED A CLASS... -1 IF YOU MISSED A CLASS....0 IF THERE'S NO CHANGE");
            scanf("%d",&c);
            if(c==1)
            {
                attended[i]++;
            }
            else if(c==-1)
            {
              missed[i]++;
            }
            b[i]=attended[i]+missed[i];
        a[i]=(float)attended[i]/(float)b[i];
        a[i]=a[i]*100;
        printf("\nATTENDANCE=%f",a[i]);
        printf("\nATTENDED=%d",attended[i]);
        printf("\nMISSED=%d",missed[i]);
        if(a[i]<target[i])
        {
            printf("\nNUMBER OF CLASSES NEEDED TO ATTEND=%d",4*missed[i]-attended[i]);
            printf("\n");
        }
        if(a[i]>=target[i])
        {
            printf("\nNUMBER OF CLASSES YOU CAN MISS=%d",(int)(0.25*attended[i])-missed[i]);
            printf("\n");
        }
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED);
        printf("\n");
        int totalattnd=0,total=0;
        float overall;
        for(i=0;i<n;i++)
        {
            totalattnd=totalattnd+attended[i];
            total=total+b[i];
        }
        overall=((float)totalattnd/(float)total)*100;
        printf("\nYOUR CURRENT OVERALL ATTENDANCE=%f",overall);
        printf("\n");
        printf("\nPress p to exit");
        printf("\n");
        char ch;
        ch=getchar();
        if(ch=='p')
            break;
    }
    return 0;
}
