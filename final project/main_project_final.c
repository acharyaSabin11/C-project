#include<stdio.h>                   // To include the standard input output functions present in this library.
#include<conio.h>                   // To include other input output functions which are not present in stdio.h library.
#include<string.h>                  // To include functions related to string.
#include<stdlib.h>                  // To use the functions which take or provide data to a file.
#include<stdbool.h>                 // To use the boolean datatype in c which is an additional datatype in c.
#include<time.h>
#include<dirent.h>

typedef struct details
{
    char name[20];
    char gender;
    char identification_code[15];
    char ctznshp_no[20];
} std;

void Initializing_Display();        // Declaration of Initializing_Display Function.
void Heading_Printer();             // Declaration of the Heading Printer Function.
int Home_Menu();                    // Declaration of the Home_Menu Function.
void Option_Selector();             // Declaration of Option_Selector Functions.
void Enroll_Yourself();             // Declaration of Enroll_Yourself Function.
void Take_Practise_Exam();          // Declaration of Take_Practise_Exam Function.
void Take_Full_Mock_Test();         // Declaration of Take_Full_Mock_Test Function.
void View_Overall_Score();          // Declaration of View_Overall_Score Function.
void View_Leaderboard();            // Declaration of View_Leaderboard Function.
void Amend_Question_Set();          // Declaration of Amend_Question_Set Function.
void View_Enrolled_Students();      // Declaration of View_Enrolled_Students Function.
void Exit();                        // Declaration of Exit Function.

void Option_Or_Exit();
void Identification_Code_Generator(char id_string[15]);     // Declaration of Identification_Code_Generator Function.
bool Citizenship_Checker(char number[20]);                  // Declaration of Citizenship_Checker Function.
bool Identification_Code_Checker(char code[15]);            // Declaration of Identification_Code_Checker Function.
void Student_Detail_Printer(int n);
int id_citizenship_matcher();
int Mocktest_QFile_Lister();
int Practisetest_QFile_Lister();
void Mocktest_AFile_Lister();
void Newline_Remover(char string[]);
void Average_Marks_Updator(int new_marks, int student_number);
int Age_Finder(int day , int month, int year);
bool Leap_Year_Checker(int year);
void diplay_question(int c, char Qpath[50]);
int answer_check(char a, int c, char Apath[50]);
void password(char passcode[20]);
void admin();
int students_scores();
int students_details();
void Directory_Maker();
bool folder_checker( char path[100], char name[20] );
int question_counter(int set_no);


int main()                          // From here, the execution of program begins.
{
    Initializing_Display();         // Function call upon the initialing_display Function to show the details of program and developers.
    Option_Selector();              //  Function call to Option_Selector Function to provide the options to select the input.
    return 0;                       // The program Execution Ends here.
}


void Initializing_Display()         // This function contains the statements that shows the information about the developers of the project.
{
    char continue_input;
    Heading_Printer();
    printf("\nComputer Programming Project:\n\n\t\t_________________________________________________________________________\n\t\t|\t\t\t\t\t\t\t\t\t|\n\t\t|\t\t\t\t Project By:\t\t\t\t|\n\t\t|\t\t\t\t*************\t\t\t\t|\n\t\t|\t\t\t\t\t\t\t\t\t|\n\t\t|\t\t\t\t\t\t\t\t\t|\n");

    printf("\t\t|\t\t\t1. Anish Timsina(THA077BEI007)\t\t\t|\n\t\t|\t\t\t\t\t\t\t\t\t|\n");
    printf("\t\t|\t\t\t2. Bishal Khadka(THA077BEI015)\t\t\t|\n\t\t|\t\t\t\t\t\t\t\t\t|\n");
    printf("\t\t|\t\t\t3. Nixon Raj Dhakal(THA077BEI028)\t\t|\n\t\t|\t\t\t\t\t\t\t\t\t|\n");
    printf("\t\t|\t\t\t4. Sabin Acharya(THA077BEI035)\t\t\t|\n\t\t|\t\t\t\t\t\t\t\t\t|\n\t\t|\t\t\t\t\t\t\t\t\t|\n");

    printf("\t\t| Faculty: Electonics, Communication and Information Engineering.\t|\n\t\t|\t\t\t\t\t\t\t\t\t|\n");
    printf("\t\t| Semester: 1st\t\t\t\t\t\t\t\t|\n\t\t|\t\t\t\t\t\t\t\t\t|\n");
    printf("\t\t| College: Thapathali Campus.\t\t\t\t\t\t|\n\t\t|\t\t\t\t\t\t\t\t\t|\n");
    printf("\t\t| Enrolled Year : 2077 B.S.\t\t\t\t\t\t|\n\t\t|\t\t\t\t\t\t\t\t\t|\n");
    printf("\t\t|_______________________________________________________________________|\n\n");
    Directory_Maker();

    do                              // This loop is to keep on asking the user to enter "Enter" to continue until the user presses Enter.
    {
    printf("Press Enter to Continue...\n");
    fflush(stdin);
    continue_input = getchar();
    } while(continue_input != '\n');
}


void Heading_Printer()
{
    printf("\t\t\t***************************Entrance Preparation Kit For IOE Entrance Preparing students*****************************\n");
    printf("\t\t\t\t\t\t\t\t\t2078 B.S./2021 A.D.");
    printf("\n\n");
    //printing the top heading in the project
}

int Home_Menu()
{
    int loop_condition_input;
    do
    {
        system("cls");
        Heading_Printer();
        printf("ENTER THE NUMBERS TO CHOOSE THE RESPECTIVE OPTIONS:\n\n\n");
        printf("1. Enroll Yourself!\n\n");
        printf("2. Take practise Test(You can choose the number of questions.)\n\n");
        printf("3. Take Full Mock Test.\n\n");
        printf("4. View Your overall Score.\n\n");
        printf("5. View the Leader-Board\n\n");
        printf("6. Ammend Question Set.(Admins Only)\n\n");
        printf("7. View All Enrolled Students.(Admins Only)\n\n");
        printf("8. Exit.\n");
        fflush(stdin);
        scanf("%d", &loop_condition_input);
    }while(loop_condition_input<1 || loop_condition_input>8);

    if(loop_condition_input == 8)
    {
        exit(1);
    }
    else
    {
        return loop_condition_input;
    }
}


void Option_Selector()
{
    start:
    system("cls");
    int opt_select_input = Home_Menu();
    switch (opt_select_input)
    {
    case 1:
        Enroll_Yourself();
        break;
    case 2:
        Take_Practise_Exam();
        break;
    case 3:
        Take_Full_Mock_Test();
        break;
    case 4:
        View_Overall_Score();
        break;
    case 5:
        View_Leaderboard();
        break;
    case 6:
        Amend_Question_Set();
        break;
    case 7:
        View_Enrolled_Students();
        break;
    case 8:
        Exit();
        break;
    default:
        goto start;
        break;
    }
}


void Enroll_Yourself()
{
    int day , month, year;
    time_t enroll_time;
    std details;    //Making structure to take student details.
    FILE *detail, *citizenship, *Identification_Code, *Average;
    short int age;
    bool ct_checker;

    //Below part is taking the personal details from the user.
    system("cls");
    Heading_Printer();
    fseek(stdin, 0, SEEK_END);
    printf("#  Enter you name: ");
    scanf("%[^\n]s", details.name);
    printf("\n");
    fseek(stdin, 0, SEEK_END);
    printf("#  Enter your gender(Male = M, Female = F, Others = O): ");
    details.gender = getchar();
    printf("\n");
    DOB_TAKER:
    fseek(stdin, 0, SEEK_END);
    printf("#  Enter your date of birth(IN A.D.):\n");
    printf("\t#  Enter your birth year(Eg: 2002): ");
    scanf("%d", &year);
    printf("\t#  Enter your birth month(Eg: 03): ");
    scanf("%d", &month);
    printf("\t#  Enter your birth day(Eg: 24): ");
    scanf("%d", &day);
    age = Age_Finder(day, month, year);

    if(age == 0)
    {
        printf("\nYour DOB Doesn't Seem To Be Valid. Please Enter A Valid DOB.\n");
        goto DOB_TAKER;
    }
    else if(age<16)
    {
        printf("\n#  Your age is: %d years.\n", age);
        printf("YOU'RE UNDER-AGE TO GIVE THE ENTRANCE EXAM. SORRY!\n");
        printf("PRESS ANY KEY TO EXIT");
        fseek(stdin, 0, SEEK_END);
        char quit = getch();
        exit(1);
    }

    printf("\n#  Your age is: %d years.\n", age);
    printf("\n");
    fseek(stdin, 0, SEEK_END);

    Repeat: //This label is used to retake the citizenship number in case of pre registerd citizenship number.
    printf("#  Enter your Citizenship Number: ");
    memset(details.ctznshp_no, 0, sizeof(details.ctznshp_no));
    scanf("%[^\n]s", details.ctznshp_no);
    ct_checker = Citizenship_Checker(details.ctznshp_no);
    if(ct_checker == true)
    {
        printf("\n\nThe citizenship number you enterd is already registered. Please use another unregistered citizenship number.\n\n\n");
        fseek(stdin,0, SEEK_END);
        goto Repeat;
    }
    Identification_Code_Generator(details.identification_code);
    printf("\n\nYour identificaton code is : %s \n", details.identification_code);
    enroll_time = time(NULL);
    localtime(&enroll_time);

    detail = fopen("C:\\IOEEPADMK_DATABASE\\studentinfo\\Student_details.txt", "a");
    fprintf(detail, "Name: %s \n", details.name);
    fprintf(detail, "Age: %d\n", age);
    fprintf(detail, "Gender: %c\n", details.gender);
    fprintf(detail, "Date Of Birth: %d-%d-%d A.D.\n", year,month,day );
    fprintf(detail, "Citizenship Number: %s\n", details.ctznshp_no);
    fprintf(detail, "Identification Code: %s\n", details.identification_code);
    fprintf(detail, "Enroll time: %s\n", ctime(&enroll_time));
    fclose(detail);

/**********************This below part is to print the identification code of the enrolled students so that it can be used in other functions.************************/
    if((Identification_Code = fopen("C:\\IOEEPADMK_DATABASE\\studentinfo\\Identification_Code.txt","r")) == NULL)   //This condition is to check for new run of the program.
    {
        Identification_Code = fopen("C:\\IOEEPADMK_DATABASE\\studentinfo\\Identification_Code.txt","w");
        fprintf(Identification_Code, "%s", details.identification_code);
        fclose(Identification_Code);
    }
    else    //This part is for the older run of the program.
    {
        fclose(Identification_Code);
        Identification_Code = fopen("C:\\IOEEPADMK_DATABASE\\studentinfo\\Identification_Code.txt","a");
        fprintf(Identification_Code, "\n%s", details.identification_code);
        fclose(Identification_Code);
    }
/**********************************************************************************************************************************************************************/

/**********************This below part is to print the citizenship_number of the enrolled students so that it can be used in other functions.************************/
    if((citizenship = fopen("C:\\IOEEPADMK_DATABASE\\studentinfo\\Citizenship_number.txt","r")) == NULL)    //This condition is to check for new run of the program.
    {
        citizenship = fopen("C:\\IOEEPADMK_DATABASE\\studentinfo\\Citizenship_number.txt","w");
        fprintf(citizenship, "%s", details.ctznshp_no);
        fclose(citizenship);
    }
    else    //This part is for the older run of the program.
    {
        fclose(citizenship);
        citizenship = fopen("C:\\IOEEPADMK_DATABASE\\studentinfo\\Citizenship_number.txt","a");
        fprintf(citizenship, "\n%s", details.ctznshp_no);
        fclose(citizenship);
    }
/**********************************************************************************************************************************************************************/

    if((Average = fopen("C:\\IOEEPADMK_DATABASE\\mocktest\\Scoresheets\\average.txt","r")) == NULL)    //This condition is to check for new run of the program.
    {
        Average = fopen("C:\\IOEEPADMK_DATABASE\\mocktest\\Scoresheets\\average.txt","w");
        fprintf(Average,"00.00 0");
        fclose(Average);
    }
    else    //This part is for the older run of the program.
    {
        fclose(Average);
        Average = fopen("C:\\IOEEPADMK_DATABASE\\mocktest\\Scoresheets\\average.txt","a");
        fprintf(Average,"\n00.00 0");
        fclose(Average);
    }

    fflush(stdin);
    Option_Or_Exit();

}


void Take_Practise_Exam()
{
    system("cls");
    Heading_Printer();
    time_t start_time, stop_time;
    int student_id_number = id_citizenship_matcher();
    printf("\n");
    int number_of_question, a = 0;
    int score = 0, time_start = 0;
    char b, st_time[30], en_time[30];
    char Qpath[100], Apath[100], Scoresheetname[50];
    int set_number_input;
    FILE *Scoresheet;
    int setNumber;
    reEnter:
    printf("#  Enter the Question set number among displayed sets:");
    setNumber = Practisetest_QFile_Lister();
    scanf("%d",&set_number_input);
    printf("\n");
    if(set_number_input >= setNumber)
    {
        printf("\nInvalid Input!!\n");
        goto reEnter;
    }
    sprintf(Qpath, "practiseset\\QuestionSets\\Set-%d.txt", set_number_input);  //This function is used to make a formatted string.
    sprintf(Apath, "practiseset\\AnswerSets\\Set-%d.txt", set_number_input);
    start:
    printf("#  Please enter the number of question you want to solve:(Min-Questions: 5, Max-Questions: 20) \n");
    printf("\n");
    scanf("%d", &number_of_question);

    if (number_of_question >= 5 && number_of_question <= 20)
    {
        system("cls");
        Heading_Printer();
        int Qstn_repeat_checker[100];
        for(int arr_iterator = 0; arr_iterator < 100; arr_iterator++)
        {
            Qstn_repeat_checker[arr_iterator] = 0;
        }
        start_time = time(NULL);
        struct tm *time1 = localtime(&start_time);
        strftime(st_time, sizeof(st_time), "%d-%b-%Y %I:%M:%S %p", time1);
        for (int i = 0; i < number_of_question; i++)
        {
            loop:
            if (a < number_of_question)
            {
                int c;
                another:
                srand(time(0));
                c = rand() % 100 + 1;
                time_t start, end;
                bool YesNo = false;
                for(int arr_iterator = 0; arr_iterator < 100; arr_iterator++)
                {
                    if(Qstn_repeat_checker[arr_iterator] == c)
                    {
                        YesNo = true;
                        break;
                    }
                }
                if(YesNo == true)
                {
                    goto another;
                }
                else
                {
                    Qstn_repeat_checker[i] = c;
                }
                start = time(NULL);
                printf("%d. ", i+1);
                diplay_question(c, Qpath);
                while (!kbhit())
                {
                    end = time(NULL);
                    if (difftime(end, start) >= 90)
                    {
                        printf("Times up !!! \nGet ready for next question\n\n");
                        a++;
                        i++;
                        goto loop;
                    }
                }
                b = getche();
                printf("\n");
                answer_check(b, c, Apath);

                if (answer_check(b, c, Apath) == 1)
                {
                    printf("your answer is correct. \n");
                    int tiMe = difftime(end, start);
                    printf("your soved this problem in %d seconds \n\n", tiMe);
                    score++;
                }
                else
                {
                    printf("your answer is incorrect! \n\n");
                }
                a++;
            }
        }

        stop_time = time(NULL);
        struct tm *time2 = localtime(&stop_time);
        strftime(en_time, sizeof(en_time), "%d-%b-%Y %I:%M:%S %p", time2);

        sprintf(Scoresheetname, "C:\\IOEEPADMK_DATABASE\\practiseset\\Scoresheets\\%03d.txt", student_id_number);
        if((Scoresheet = fopen(Scoresheetname,"r")) == NULL)    //This condition is to check for new run of the program.
        {
            Scoresheet = fopen(Scoresheetname,"w");
            fprintf(Scoresheet,"_________________________________________________________________________________________________________________________________\n");
            fprintf(Scoresheet, "|%s\t\t|%s\t\t\t|%s\t\t\t|%s\t\t\t|%s\t|","Set Number", "Start Time", "End Time", "Duration", "Score" );
            fprintf(Scoresheet,"\n|_______________________|_______________________________|_______________________________|_______________________________|_______|");

            fprintf(Scoresheet, "\n|Set-%d\t\t\t|%s\t|%s\t|%0.2f Minutes\t\t\t|%03d/%d\t|",set_number_input, st_time, en_time, (difftime(stop_time, start_time))/60, score,number_of_question);
            fclose(Scoresheet);
        }
        else    //This part is for the older run of the program.
        {
            fclose(Scoresheet);
            Scoresheet = fopen(Scoresheetname,"a");
            fprintf(Scoresheet, "\n|Set-%d\t\t\t|%s\t|%s\t|%0.2f Minutes\t\t\t|%03d/%d\t|",set_number_input, st_time, en_time, (difftime(stop_time, start_time))/60, score,number_of_question);
            fclose(Scoresheet);
        }

        printf("\nYOUR SCORESHEET:");
        printf("\n_________________________________________________________\n|\t\t\t\t\t\t\t|\n");
        printf("|Start Time\t: %s\t\t|\n", st_time);
        printf("|End Time\t: %s\t\t|\n", en_time);
        printf("|Duration\t: %0.2f Seconds\t\t\t\t|\n", difftime(stop_time, start_time));
        printf("|Score\t\t: %03d/%d\t\t\t\t\t|\n", score,number_of_question);
        printf("|_______________________________________________________|\n");
    }

    else
    {
        printf("Please select the question between 5 and 20 \n\n");
        goto start;
    }

    Option_Or_Exit();

}


void Take_Full_Mock_Test()
{
    time_t start_time, stop_time, start, end;
    char id_number_string[3], Qsetname[100], Asetname[100], Scoresheetname[100], Question[500], st_time[30], en_time[30];
    int id_number_integer, set_number_input, score = 0;
    char Answer, Answer_input;
    FILE *Qset, *Aset, *Scoresheet;

    system("cls");
    Heading_Printer();

    id_number_integer = id_citizenship_matcher();
    int set_number;
    reEnter: 
    set_number = Mocktest_QFile_Lister();
    printf("Enter the set number: ");
    scanf("%d", &set_number_input);
    if(set_number_input >= set_number)
    {
        printf("\nInvalid Input!!\n");
        goto reEnter;
    }
    fseek(stdin, 0, SEEK_END);

    sprintf(Qsetname, "mocktest\\QuestionSets\\Set-%d.txt", set_number_input);  //This function is used to make a formatted string.
    sprintf(Asetname, "mocktest\\AnswerSets\\Set-%d.txt", set_number_input);
    Qset = fopen(Qsetname, "r");
    Aset = fopen(Asetname, "r");

    start_time = time(NULL);
    struct tm *time1 = localtime(&start_time);
    strftime(st_time, sizeof(st_time), "%d-%b-%Y %I:%M:%S %p", time1);
    start = time(NULL);

    system("cls");
    Heading_Printer();
    for (int b = 0; (b<100 && difftime(end, start)<=7200); b++)
    {
        end = time(NULL);
        printf("\n\n*******************************************************************************************************************************************************************\n");
        int tiMe = difftime(end, start);
        printf("Time: %d min %d seconds /120 min\n", tiMe/60, (tiMe%60));
        for(int a= 0; a<7; a++)
        {
                fgets(Question, sizeof(Question), Qset);
                printf("%s", Question);
        }
        printf("Enter Your option: ");
        while(kbhit() == 0)
        {
            end = time(NULL);
            if((difftime(end, start)) >= 7200)
            {
                break;
            }
        }
        if(kbhit() != 0)
        {
            Answer_input = getche();
            Answer = fgetc(Aset);
            fgetc(Aset);
            if(Answer_input == Answer)
            {
                score ++;
            }
        }
        printf("\n\nThe correct answer is: %c\n", Answer);
        printf("\nScore: %02d\n", score);
        printf("*******************************************************************************************************************************************************************\n");
    }
    stop_time = time(NULL);
    struct tm *time2 = localtime(&stop_time);
    strftime(en_time, sizeof(en_time), "%d-%b-%Y %I:%M:%S %p", time2);
    fclose(Qset);
    fclose(Aset);
    sprintf(Scoresheetname, "C:\\IOEEPADMK_DATABASE\\mocktest\\Scoresheets\\%03d.txt", id_number_integer);
    Newline_Remover(st_time);
    Newline_Remover(en_time);

    if((Scoresheet = fopen(Scoresheetname,"r")) == NULL)    //This condition is to check for new run of the program.
    {
        Scoresheet = fopen(Scoresheetname,"w");
        fprintf(Scoresheet,"_________________________________________________________________________________________________________________________________\n");
        fprintf(Scoresheet, "|%s\t\t|%s\t\t\t|%s\t\t\t|%s\t\t\t|%s\t|","Set Number", "Start Time", "End Time", "Duration", "Score" );
        fprintf(Scoresheet,"\n|_______________________|_______________________________|_______________________________|_______________________________|_______|");
        fprintf(Scoresheet, "\n|Set-%d\t\t\t|%s\t|%s\t|%0.2f Minutes\t\t\t|%03d\t|",set_number_input, st_time, en_time, (difftime(stop_time, start_time))/60, score);
        fclose(Scoresheet);
    }
    else    //This part is for the older run of the program.
    {
        fclose(Scoresheet);
        Scoresheet = fopen(Scoresheetname,"a");
        fprintf(Scoresheet, "\n|Set-%d\t\t\t|%s\t|%s\t|%0.2f Minutes\t\t\t|%03d\t|",set_number_input, st_time, en_time, (difftime(stop_time, start_time))/60, score);
        fclose(Scoresheet);
    }

    Average_Marks_Updator(score, id_number_integer);

    //Marksheet Printing******************************************************************************************************************************************
    printf("\nYOUR SCORESHEET:");
    printf("\n_________________________________________________________\n|\t\t\t\t\t\t\t|\n");
    printf("|Start Time\t: %s\t\t|\n", st_time);
    printf("|End Time\t: %s\t\t|\n", en_time);
    printf("|Duration\t: %0.2f Seconds\t\t\t\t|\n", difftime(stop_time, start_time));
    printf("|Score\t\t: %03d\t\t\t\t\t|\n", score);
    printf("|_______________________________________________________|\n");

    fflush(stdin);
    Option_Or_Exit();
}


void View_Overall_Score()
{
    system("cls");
    Heading_Printer();
    int file_no;
    char pathmock[100],pathpractise[100],c,s;
    FILE *score_mocktest,*score_practisetest;
    file_no = id_citizenship_matcher();
    sprintf(pathmock,"C:\\IOEEPADMK_DATABASE\\mocktest\\Scoresheets\\%03d.txt",file_no);
    score_mocktest=fopen(pathmock,"r");
    sprintf(pathpractise,"C:\\IOEEPADMK_DATABASE\\practiseset\\Scoresheets\\%03d.txt",file_no);
    score_practisetest=fopen(pathpractise,"r");
    printf("---------------------------------------------------------------------------------------------------\n");
    printf("\t\tScore in mock test\n");
    printf("---------------------------------------------------------------------------------------------------\n");
    if(score_mocktest == NULL)
    {
        printf("File is empty.");
    }
    while((c=fgetc(score_mocktest)) != EOF)   //reading data of student performance stored in file
    {
        printf("%c",c);
    }

    fflush(stdin);
    printf("\n\n---------------------------------------------------------------------------------------------------\n");
    printf("\t\tScore in practise test\n");
    printf("---------------------------------------------------------------------------------------------------\n");
    while((s=fgetc(score_practisetest))!=EOF)
    {
        printf("%c",s);
    }
    fflush(stdin);
    printf("\n\n");
    fclose(score_mocktest);
    fclose(score_practisetest);

    Option_Or_Exit();
}


void View_Leaderboard()
{
    system("cls");
    Heading_Printer();
    printf("LEADERBOARD:\n\n");
    FILE *averagemarks, *ptr;
    char num,line_counter_array[10];
    int number_of_data=0;
    averagemarks=fopen("C:\\IOEEPADMK_DATABASE\\mocktest\\Scoresheets\\average.txt","r");
    while((num=fgetc(averagemarks))!=EOF){
        fgets(line_counter_array,sizeof(line_counter_array),averagemarks);
        number_of_data+=1;
    }
    fclose(averagemarks);
    float average_scores[number_of_data];
    int number_of_exams[number_of_data];
    averagemarks=fopen("C:\\IOEEPADMK_DATABASE\\mocktest\\Scoresheets\\average.txt","r");
    for(int a = 0; a<number_of_data; a++)
    {
        fscanf(averagemarks, "%f", &average_scores[a]);
        fscanf(averagemarks, "%d", &number_of_exams[a]);
    }
    char ids[number_of_data][15];
    ptr = fopen("C:\\IOEEPADMK_DATABASE\\studentinfo\\Identification_Code.txt", "r");
    for(int a = 0; a<number_of_data; a++)
    {
        fgets(ids[a], sizeof(ids[a]), ptr);
        Newline_Remover(ids[a]);
    }
    fclose(averagemarks);
    fclose(ptr);

    for(int a = 0; a<number_of_data; a++)
    {
        for(int b = a+1; b<number_of_data; b++)
        {
            if(average_scores[a]<average_scores[b])
            {
                float swapper = average_scores[b];
                average_scores[b] = average_scores[a];
                average_scores[a] = swapper;

                char id_swapper[15];
                strcpy(id_swapper, ids[a]);
                strcpy(ids[a], ids[b]);
                strcpy(ids[b], id_swapper);

                int swapper1 = number_of_exams[b];
                number_of_exams[b] = number_of_exams[a];
                number_of_exams[a] = swapper1;
            }
        }
    }
    printf("\n_________________________________________________________________________________________________________\n");
    printf("|Rank\t|\tIdenitification Number\t\t|\tAverage Scores\t\t|\tExam Number\t|\n");
    printf("|_______|_______________________________________|_______________________________|_______________________|\n");
    for(int a = 0; a<number_of_data; a++)
    {
        printf("|%d\t|\t%s\t\t\t|\t%0.2f\t\t\t|\t%d\t\t|\n", a+1, ids[a], average_scores[a], number_of_exams[a]);
    }
    printf("|_______|_______________________________________|_______________________________|_______________________|\n\n");
    Option_Or_Exit();
}


void Amend_Question_Set()
{
    int input,set_no,Qnum = 0,check;
    char Qsetname[100],Question[500],Aset[100],Asetname[500],new_question[500],option1[50],option2[50],option3[50],option4[50];
    char answer,character;
    fflush(stdin);
    char passcode[20] = "project@c";
    admin();
    password(passcode);
    new_set:
    printf("\nselect the option\n");
    printf("1.Add question to existing set.\n");
    printf("2.Add new question set.\n");
    scanf("%d",&input);
    while(input<1 || input>2){      //loop continues if input is wrong
        printf("!!!!!  Wrong Input  !!!!!!!\n");
        printf("Re - enter :--  ");
        fflush(stdin);
        scanf("%d",&input);
        }
    admin();
    if(input==1)
    {
        ammend:
        fflush(stdin);
        Mocktest_QFile_Lister();
        printf("\n Input the set you want to ammend = ");
        scanf("%d",&set_no);
        fseek(stdin, 0,SEEK_END);
        FILE* Qset;
        Qnum=question_counter(set_no);

        if(Qnum>=100){
                printf("The question set is full please select another set\n");
                Qnum=0;
                fflush(stdin);
            goto ammend;
        }

        fseek(stdin, 0,SEEK_END);
        FILE* Aset;
        sprintf(Qsetname, "mocktest\\QuestionSets\\Set-%d.txt", set_no);
        sprintf(Asetname, "mocktest\\AnswerSets\\Set-%d.txt", set_no);

        Question:    //calling again from here if user want to add more questions
            Qset=fopen(Qsetname,"a");
            Aset=fopen(Asetname,"a");
        Qnum+=1;
        fseek(stdin, 0,SEEK_END);
        printf("Question:-");
        scanf("%[^\n]s",new_question);
        fprintf(Qset,"%d. %s",Qnum,new_question);
        fseek(stdin, 0,SEEK_END);
        printf("option a:- ");
        scanf("%[^\n]s",option1);
        fprintf(Qset,"\n\n a.%s",option1);
        fseek(stdin, 0,SEEK_END);
        printf("option b:- ");
        scanf("%[^\n]s",option2);
        fprintf(Qset,"\n b.%s",option2);
        fseek(stdin, 0,SEEK_END);
        printf("option c:- ");
        scanf("%[^\n]s",option3);
        fprintf(Qset,"\n c.%s",option3);
        fseek(stdin, 0,SEEK_END);
        printf("option d:- ");
        scanf("%[^\n]s",option4);
        fprintf(Qset,"\n d.%s\n\n",option4);
        fseek(stdin, 0,SEEK_END);
        printf("Answer:- ");
        scanf("%c",&answer);
        fprintf(Aset,"%c\n",answer);
        fseek(stdin, 0,SEEK_END);
        fclose(Qset);
        fclose(Aset);
        printf("\nDo you want  to add more: 1 for yes and other number for no. ");
        scanf("%d",&check);

        Qnum=question_counter(set_no);
        if(Qnum>=100){
                printf("The question set is full please select another set\n");
                Qnum=0;
                fflush(stdin);
            goto ammend;
        }
        if (check==1)
        goto Question;
        else
        {
            Option_Or_Exit();
        }
}

  if(input==2){
        int set;
        FILE* Qset;
        FILE* Aset;
        set=Mocktest_QFile_Lister();
        system("cls");
        Heading_Printer();
        printf("Set-%d:\n\n", set);
        sprintf(Qsetname, "mocktest\\QuestionSets\\Set-%d.txt", set);
        sprintf(Asetname, "mocktest\\AnswerSets\\Set-%d.txt", set);

        Question_new:
        Qset=fopen(Qsetname,"a");   //opening new set for input of question
        Aset=fopen(Asetname,"a");   //opening new set for answer input
        Qnum=Qnum+1;
        fseek(stdin, 0,SEEK_END);
            printf("Question:-");
            scanf("%[^\n]s",&new_question);
            fprintf(Qset,"%d. %s",Qnum,new_question);
            fseek(stdin, 0,SEEK_END);
            printf("option a:- ");
            scanf("%[^\n]s",&option1);
            fprintf(Qset,"\n\n a.%s",option1);
            fseek(stdin, 0,SEEK_END);
            printf("option b:- ");
            scanf("%[^\n]s",&option2);
            fprintf(Qset,"\n b.%s",option2);
            fseek(stdin, 0,SEEK_END);
            printf("option c:- ");
            scanf("%[^\n]s",&option3);
            fprintf(Qset,"\n c.%s",option3);
            fseek(stdin, 0,SEEK_END);
            printf("option d:- ");
            scanf("%[^\n]s",&option4);
            fprintf(Qset,"\n d.%s\n\n",option4);
            fseek(stdin, 0,SEEK_END);
            printf("Answer:- ");
            scanf("%[^\n]s",&answer);
            fprintf(Aset,"%c\n",answer);
            fseek(stdin, 0,SEEK_END);
            fclose(Qset);
            fclose(Aset);
            printf("\nDo you want  to add more: 1 for yes and other key for no. ");
            scanf("%d",&check);

            Qnum=question_counter(set);
             if(Qnum>=100){
                printf("The question set is full please make another set\n");
                Qnum=0;
                fflush(stdin);
                goto new_set;
             }
          if (check==1)
            goto Question_new;
          else
          {
              Option_Or_Exit();
          }
}
}


void View_Enrolled_Students()
{
    char c;
    int input,check;
    char passcode1[20]="project@c", passcode2[20] = "BANS@PROJECT";
    password(passcode1);
    admin();
    printf("Select option:-\n ");
    printf("\t 1.view students details\n");
    printf("\t 2.RESET the file of students details for keeping new record.\n");
    scanf("%d",&input);
     while(input<1 || input>2){     //calling loop again and again if input is wrong
        printf("!!!!!  Wrong Input  !!!!!!!\n");
        printf("Re - enter :--  ");
        fflush(stdin);
        scanf("%d",&input);
        }
    admin();
    if(input==1)
    {
            fflush(stdin);
            admin();
            password(passcode2);
        FILE *fptr;
        fptr=fopen("C:\\IOEEPADMK_DATABASE\\studentinfo\\student_details.txt","r");
        while((c=fgetc(fptr))!=EOF){
            printf("%c",c);
        }
        fclose(fptr);
        Option_Or_Exit();
    }

    if(input==2){
        int i;
        printf("!!!!!!YOU ARE ABOUT TO ERASE ALL STUDENTS DATA.PRESS 1 TO CONFIRM !!\n IF NOT PRESS OTHER NUMBER.  ");
        scanf("%d",&i);
        if(i==1){
                fflush(stdin);
                password(passcode2);
                admin();
                printf("YOU ARE ABOUT TO DELETE ALL THE FOLLOWING FILES!!!!!!!\n");
                students_scores();
                printf("\nPRESS 1 KEY TO CONFIRM OR OTHER KEY TO GO TO OPTION OR EXIT BLOCK!");
                scanf("%d",&check);
                if (check==1)
                {
                    DIR *theFolder = opendir("C:\\IOEEPADMK_DATABASE\\studentinfo");
                    struct dirent *next_file;
                    char filepath[250];
                    while ( (next_file = readdir(theFolder)) != NULL )
                    {
                        // build the path for each file in the folder
                        sprintf(filepath, "C:\\IOEEPADMK_DATABASE\\studentinfo\\%s", next_file->d_name);//comes the name of files serially
                        remove(filepath);  //delet the respective files from the folder of studentinfo
                    }

                    closedir(theFolder);

                    DIR *Folder_scorecard = opendir("C:\\IOEEPADMK_DATABASE\\mocktest\\Scoresheets");
                    struct dirent *score_file;
                    char filelocation[250];
                    while ( (score_file = readdir(Folder_scorecard)) != NULL )
                    {
                        // build the path for each file in the folder
                        sprintf(filelocation, "C:\\IOEEPADMK_DATABASE\\mocktest\\Scoresheets\\%s", score_file->d_name);
                        remove(filelocation);
                    }
                    closedir(Folder_scorecard);

                    DIR *Folder_practicescore = opendir("C:\\IOEEPADMK_DATABASE\\practiseset\\Scoresheets");
                    struct dirent *practice_score;
                    char fileset[250];
                    while ( (practice_score = readdir(Folder_practicescore)) != NULL )
                    {
                        // build the path for each file in the folder
                        sprintf(fileset, "C:\\IOEEPADMK_DATABASE\\practiseset\\Scoresheets\\%s", practice_score->d_name);
                        remove(fileset);
                    }
                    closedir(Folder_practicescore);
                    printf("\nALL THE FILES HAVING STUDENT DATA HAS BEEN DELETED.\n");
                    Option_Or_Exit();
                }
                else
                {
                    Option_Or_Exit();
                }
        }
        else
        {
            Option_Or_Exit();
        }
    }
}


void Exit()
{
    exit(1);
}


void Option_Or_Exit()
{
    char input;
    Top:
    printf("PRESS ENTER TO GO TO HOME MENU OR ENTER 'X' TO EXIT: ");
    fflush(stdin);
    scanf("%c", &input);
    if( input == 'x' || input == 'X' || input == '\n')
    {
        if(input == '\n')
        {
            Option_Selector();
        }
        else
        {
            Exit();
        }
    }
    else
    {
        goto Top;
    }
}


void Identification_Code_Generator(char id_string[15])
{
    FILE *number;
    short int numb;
    char end_checker;
    //This below part is just to make the code number appear automatically for the users.
    number = fopen("C:\\IOEEPADMK_DATABASE\\studentinfo\\student_number.txt", "r");
    if(number == NULL)
    {
        fclose(number);
        number = fopen("C:\\IOEEPADMK_DATABASE\\studentinfo\\student_number.txt", "w");
        fprintf(number, "001");
        fclose(number);
        number = fopen("C:\\IOEEPADMK_DATABASE\\studentinfo\\student_number.txt", "r");
    }

    do
    {
    fscanf(number, "%d", &numb);
    } while((end_checker = fgetc(number)) != EOF);
    fclose(number);

    memset(id_string,0, 15);
    sprintf(id_string, "IOE078EP%03d", numb);

    numb++;

    number = fopen("C:\\IOEEPADMK_DATABASE\\studentinfo\\student_number.txt", "a");
    fprintf(number, "\n%03d", numb);
    fclose(number);
}


bool Citizenship_Checker(char number[20])
{
    FILE *ptr = fopen("C:\\IOEEPADMK_DATABASE\\studentinfo\\Citizenship_number.txt", "r");  //Opering the file Citizenship_number.txt in read mode to read the numbers in the file.
    char number_from_file[20];  //This string stores the citizenship_number from file.
    char checker;   //This character is used to identify the End Of File.
    if(ptr == NULL) //This is for the first run of the program. If there is no file named Citizenship_number.txt, the function returns false.
    {
        fclose(ptr);
        return false;
    }
    else
    {
        while((checker = fgetc(ptr)) != EOF)
        {
            fseek(ptr, -1, SEEK_CUR);
            fgets(number_from_file, sizeof(number_from_file), ptr);
            for(int a = 0; number_from_file[a] != '\0'; a++)    //This loop is to remove the '\n' that comes along with the string at its end when using fgets function.
            {
                if(number_from_file[a] == '\n') //if '\n' is identified, this block is executed.
                {
                    number_from_file[a] = '\0'; //'\n'is replaced by '\0'.
                }
            }
            if(strcmp(number_from_file, number) == 0)   //If the citizenship number from file is equal to the citizenship number from the function, it returns true.
            {
                fclose(ptr);
                return true;
            }
        }
    }
    fclose(ptr);    
    return false;   //If no matching Citizenship number is found, the function returns false.
}


bool Identification_Code_Checker(char code[15])
{
    FILE *ptr = fopen("C:\\IOEEPADMK_DATABASE\\studentinfo\\Identification_Code.txt", "r");  //Opering the file Identification_Code.txt in read mode to read the numbers in the file.
    char code_from_file[20];  //This string stores the citizenship_number from file.
    char checker;   //This character is used to identify the End Of File.
    if(ptr == NULL) //This is for the first run of the program. If there is no file named Identification_Code.txt, the function returns false.
    {
        fclose(ptr);
        return false;
    }
    else
    {
        while((checker = fgetc(ptr)) != EOF)
        {
            fseek(ptr, -1, SEEK_CUR);
            fgets(code_from_file, sizeof(code_from_file), ptr);
            for(int a = 0; code_from_file[a] != '\0'; a++)    //This loop is to remove the '\n' that comes along with the string at its end when using fgets function.
            {
                if(code_from_file[a] == '\n') //if '\n' is identified, this block is executed.
                {
                    code_from_file[a] = '\0'; //'\n'is replaced by '\0'.
                }
            }
            if(strcmp(code_from_file, code) == 0)   //If the citizenship number from file is equal to the Identification code from the function, it returns true.
            {
                fclose(ptr);
                return true;
            }
        }
    }
    fclose(ptr);    //If no matching Identification Code is found, the function returns false.
    return false;
}


void Student_Detail_Printer(int n)
{
    char det[50];
    FILE *ptr;
    ptr = fopen("C:\\IOEEPADMK_DATABASE\\studentinfo\\Student_details.txt", "r");
    for(int a = 1; a<=n; a++)
    {
        if(a != n)
        {
            for(int b = 0; b<8; b++)
            {
                fgets(det, sizeof(det), ptr);
            }
        }
        else if(a == n)
        {
            printf("********************************************************************************************************************************************************\n\n");
            for(int b = 0; b<8; b++)
            {
                fgets(det, sizeof(det), ptr);
                printf("\t\t\t\t\t\t\t%s\n", det);
            }
            printf("********************************************************************************************************************************************************\n\n");
        }
    }
    fclose(ptr);
}


int Mocktest_QFile_Lister()
{
    int set_number = 1;
    DIR *Directory;
    printf("Choose among the following Question Sets: \n");
    Directory = opendir("mocktest\\QuestionSets");
    struct dirent *lister;
    lister =readdir(Directory);
    lister =readdir(Directory);
    while((lister = readdir(Directory)) != NULL)
    {
        printf("%d. %s\n",set_number, lister->d_name);
        set_number++;
    }
    closedir(Directory);
    return set_number;
}

int Practisetest_QFile_Lister()
{
    int set_number = 1;
    DIR *Directory;
    printf("Choose among the following Question Sets: \n");
    Directory = opendir("practiseset\\QuestionSets");
    struct dirent *lister;
    lister =readdir(Directory);
    lister =readdir(Directory);
    while((lister = readdir(Directory)) != NULL)
    {
        printf("%d. %s\n",set_number, lister->d_name);
        set_number++;
    }
    closedir(Directory);
    return set_number;
}


void Mocktest_AFile_Lister()
{
    int set_number = 1;
    DIR *Directory;
    printf("Choose among the following Question Sets: \n");
    Directory = opendir("practiseset\\QuestionSets");
    struct dirent *lister;
    lister =readdir(Directory);
    lister =readdir(Directory);
    while((lister = readdir(Directory)) != NULL)
    {
        printf("%d. %s\n",set_number, lister->d_name);
        set_number++;
    }
    closedir(Directory);
}


int id_citizenship_matcher()
{
    char id_code[15], id_number_string[3], ct_no_input[20], ct_no_file[20];
    int id_number_integer;
    bool checker;
    FILE *Citizenship_Number;
    Repeat: //This label is used to retake the identification code in case of not registerd identification code.
    printf("Enter Your Identification Code: ");
    memset(id_code, 0, sizeof(id_code));
    scanf("%s", id_code);
    printf("\n\n");
    checker = Identification_Code_Checker(id_code);
    if(checker == false)
    {
        printf("The identification code you enterd is not registered. Please use another registered Identification code.\n");
        fseek(stdin,0, SEEK_END);
        goto Repeat;
    }

    for(int a = 0; a<3; a++)
    {
        id_number_string[a] = id_code[8+a];
    }
    id_number_integer = atoi(id_number_string);

/****************************************This part matches the respective identification number with the person's citizenship number to avoid trespassing*******************/
    Take_Citizenship:
    printf("Enter Your Citizenship Number For Confirmation: ");
    fseek(stdin, 0, SEEK_END);
    scanf("%s", ct_no_input);
    printf("\n\n");
    Citizenship_Number = fopen("C:\\IOEEPADMK_DATABASE\\studentinfo\\Citizenship_number.txt", "r");
    for(int a = 0; a<id_number_integer; a++)
    {
        fgets(ct_no_file, sizeof(ct_no_file), Citizenship_Number);
    }
    fclose(Citizenship_Number);

    for(int a = 0; ct_no_file[a] != '\0'; a++)    //This loop is to remove the '\n' that comes along with the string at its end when using fgets function.
    {
        if(ct_no_file[a] == '\n') //if '\n' is identified, this block is executed.
        {
            ct_no_file[a] = '\0'; //'\n'is replaced by '\0'.
        }
    }
    if(strcmp(ct_no_input, ct_no_file) != 0)
    {
        printf("The citizenship number you entered doest match with your identification number.\n");
        goto Take_Citizenship;
    }
    else
    {
        system("cls");
        Heading_Printer();
        Student_Detail_Printer(id_number_integer);
    }
/***********************************************************************************************************************************************************************/
return id_number_integer;
}


void Newline_Remover(char string[])
{
    for(int a = 0; string[a] != '\0'; a++)    //This loop is to remove the '\n' that comes along with the string at its end when using fgets function.
    {
        if(string[a] == '\n') //if '\n' is identified, this block is executed.
        {
            string[a] = '\0'; //'\n'is replaced by '\0'.
        }
    }
}


void Average_Marks_Updator(int new_marks, int student_number)
{

    float marks;
    int exam_times;
    char end_checker;
    FILE *ptr1, *ptr2 = fopen("C:\\IOEEPADMK_DATABASE\\mocktest\\Scoresheets\\averageupdate.txt", "w");
    ptr1 = fopen("C:\\IOEEPADMK_DATABASE\\mocktest\\Scoresheets\\average.txt", "r");
    for(int a = 1; (end_checker = fgetc(ptr1)) != EOF; a++)
    {
        fseek(ptr1, -1, SEEK_CUR);
        fscanf(ptr1, "%f", &marks);
        printf("%0.2f\n", marks);
        fscanf(ptr1, "%d", &exam_times);
        if(a == student_number)
        {
            marks = ((marks*exam_times)+new_marks)/(++exam_times);
        }
        fprintf(ptr2, "\n%0.2f %d", marks, exam_times );
    }
    fclose(ptr1);
    fclose(ptr2);

    ptr2 = fopen("C:\\IOEEPADMK_DATABASE\\mocktest\\Scoresheets\\averageupdate.txt", "r");
    ptr1 = fopen("C:\\IOEEPADMK_DATABASE\\mocktest\\Scoresheets\\average.txt", "w");
    end_checker = fgetc(ptr2);
    while((end_checker = fgetc(ptr2)) != EOF)
    {
        fputc(end_checker, ptr1);
    }
    fclose(ptr1);
    fclose(ptr2);
    remove("C:\\IOEEPADMK_DATABASE\\mocktest\\Scoresheets\\averageupdate.txt");
}


int Age_Finder(int day , int month, int year)
{
    time_t today;
    time(&today);
    struct tm *today_time = localtime(&today);
    if(year > today_time->tm_year+1900 || (year == today_time->tm_year+1900 && month > (today_time->tm_mon+1)) || (year == today_time->tm_year+1900 && month == (today_time->tm_mon+1)) && day > today_time->tm_mday) //if the entered date is of later date than today's date, it is displayed to be invalid.
    {
        return 0;
    }
    else
    {
        if(month<=12 && month>0)    //checking if the month is valid. i.e between 1 to 12. this if statement is executed only if the month number is 1-12.
        {
            if(Leap_Year_Checker(year) == true) //if the year is leap year, the validity of the february date is upto 29 feb which is checked here.
            {
                if(month == 2 && (day<1 || day>29)) //if date in february in leap year is less than one or greater than 29, the date is displayed to be invalid.
                {
                    return 0;
                }
            }
            else    //if the year is not a leap year, the validity of the february date is upto 28 feb which is checked here.
            {
                if(month == 2 && (day<1 || day>28)) //if date in february in not leap year is less than one or greater than 28, the date is displayed to be invalid.
                {
                    return 0;
                }
            }

            if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) //if the months are January, March, May, July, August, October and December they have 31 days, so date more than that is considered as invalid.
            {
                if(day>31 || day<1)
                {
                    return 0;
                }
            }
            else // If the months are April, June, September and November, they have 30 days and date more than that is considered as invalid.
            {
                if(day<1 || day>30)
                {
                    return 0;
                }
            }
        }
        else    //if the month number is less than or equal to 0 or greater than 12, the date is shown as invalid.
        {
            return 0;
        }
            year = (today_time->tm_year + 1900) - year; // if the date is valid, the year difference is calculated.
            if(month>(today_time->tm_mon+1))    //if the entered month is greater than the current month, the person has not completed that year in age. so 1 is subtracted from the calculated year.
            {
                year--;
                return year;
            }
            else if(month == (today_time->tm_mon+1)) // if the month is equal to the current month, day value is checked.
            {
                if(day>(today_time->tm_mday))   //if the entered day is greater than the current day of month, the person has not completed that year in age. so 1 is subtracted from the calculated year.
                {
                    year --;
                    return year;
                }
                else    //if the entered day is less than or equal to the current day of month, year value is returned directly.
                {
                    return year;
                }
            }
            else    // if the month is less than the current month, the year value is returned directly.
            {
                return year;
            }
    }
}


bool Leap_Year_Checker(int year)
{
    if(year % 4 == 0)
    {
        if(year % 100 == 0)
        {
            if(year % 400 == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}


void diplay_question(int c, char Qpath[50])
{
    char b[1000];
    FILE *ptr;
    ptr = fopen(Qpath, "r");
    for (int v = 0; v < c; v++)
    {
        if (v < c - 1)
        {
            for (int i = 0; i < 7; i++)
            {
                fgets(b, sizeof(b), ptr);
            }
        }
        else
        {
            for (int j = 0; j < 7; j++)
            {
                fgets(b, sizeof(b), ptr);
                printf("%s", b);
            }
        }
    }
    fclose;
}


int answer_check(char a, int c, char Apath[50])
{
    char q;
    FILE *ptr1;
    ptr1 = fopen(Apath, "r");
    for (int b = 1; b <= c; b++)
    {
        if (b != c)
        {
            q = fgetc(ptr1);
            fgetc(ptr1);
        }
        if (b == c)
        {
            q = fgetc(ptr1);
            fgetc(ptr1);
        }
        fclose;
    }
    if (a == q)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


void password(char passcode[20]){
    int check;
    char pass_code[20];
    admin();
    fflush(stdin);
    int passcode_number = 0;
    if( strcmp(passcode, "project@c") == 0)
    {
        passcode_number = 1;
    }
    else if(strcmp(passcode, "BANS@PROJECT") == 0)
    {
        passcode_number = 2;
    }
    printf("Enter the passcode-%d:-\t", passcode_number);
    scanf("%[^\n]s",&pass_code);
    check=strcmp(pass_code,passcode);
    while(check!=0){
        printf("!!!!!  Wrong passcode   !!!!!!!\n");
        printf("Re - enter passcode :-- ");
        fflush(stdin);
        scanf("%[^\n]s",&pass_code);
        check=strcmp(pass_code,passcode);
    }
    while(check==0)
    return;
}


void admin(){
    system("cls");
    printf("\t\t--Admin section only.--\n\t!!!!! AUTHORISED USER ONLY ALLOWED!!--\n");
    printf("-----------------------------------------------------------------------------------\n");
}


int students_scores()
{
    int j;
    j=students_details();
    DIR *students;
    students = opendir("C:\\IOEEPADMK_DATABASE\\mocktest\\scoresheets");
    struct dirent *std;
    std =readdir(students);
    std =readdir(students);
    while((std= readdir(students)) != NULL)
    {
        printf("%d. %s\n",j, std->d_name);
        j++;
    }
    closedir(students);
    students = opendir("C:\\IOEEPADMK_DATABASE\\practiseset\\scoresheets");
    std =readdir(students);
    std =readdir(students);
    while((std= readdir(students)) != NULL)
    {
        printf("%d. %s\n",j, std->d_name);
        j++;
    }
    closedir(students);
    return j;
}


int students_details()
{
    int i=1;
    DIR *students;
    students = opendir("C:\\IOEEPADMK_DATABASE\\studentinfo");
    struct dirent *std;
    std =readdir(students);
    std =readdir(students);
    while((std= readdir(students)) != NULL)
    {
        printf("%d. %s\n",i, std->d_name);
        i++;
    }
    closedir(students);
    return i;
}


bool folder_checker( char path[100], char name[20] )
{
    DIR *FOLDER;
    bool repeat_checker;
    FOLDER = opendir(path);
    struct dirent *folder_reader;
    folder_reader = readdir(FOLDER);
    if((folder_reader = readdir(FOLDER)) == NULL)
    {
        return false;
    }
    while(folder_reader != NULL)
    {
        if(strcmp(folder_reader->d_name, name) == 0)
        {
            repeat_checker = true;
            break;
        }
        else
        {
            repeat_checker = false;
            folder_reader = readdir(FOLDER);
        }
    }
    return repeat_checker;
}


void Directory_Maker()
{
    bool repeat_checker = folder_checker("C:\\", "IOEEPADMK_DATABASE");
    if(repeat_checker == false)
    {
        mkdir("C:\\IOEEPADMK_DATABASE");
    }
    repeat_checker = folder_checker("C:\\IOEEPADMK_DATABASE", "mocktest");
    if(repeat_checker == false)
    {
        mkdir("C:\\IOEEPADMK_DATABASE\\mocktest");
        mkdir("C:\\IOEEPADMK_DATABASE\\mocktest\\Scoresheets");
    }
    repeat_checker = folder_checker("C:\\IOEEPADMK_DATABASE", "practiseset");
    if(repeat_checker == false)
    {
        mkdir("C:\\IOEEPADMK_DATABASE\\practiseset");
        mkdir("C:\\IOEEPADMK_DATABASE\\practiseset\\Scoresheets");
    }
    repeat_checker = folder_checker("C:\\IOEEPADMK_DATABASE", "studentinfo");
    if(repeat_checker == false)
    {
        mkdir("C:\\IOEEPADMK_DATABASE\\studentinfo");
    }
}


//used to count the existing number of question in set
int question_counter(int set_no){
    int Qnum=0,Lines=0;
    char Qsetname[100],character;
    FILE* Qset;
        sprintf(Qsetname, "mocktest\\QuestionSets\\Set-%d.txt", set_no);
        Qset=fopen(Qsetname,"r");
        if (Qset == NULL)
        {
            printf("The file doesn't exist ! Please check again .");
            Exit();
        }
        while((character=fgetc(Qset))!=EOF) //calculating the existing number of question in given set
        {
            if(character=='\n')
            {
                Lines+=1;
                if(Lines==7)
                {
                    Qnum+=1;
                    Lines=0;
                }
            }
    }
        fclose(Qset);
        return Qnum;
}
