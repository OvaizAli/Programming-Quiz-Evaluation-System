#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<string.h>

struct user{
	char Id[20];
	char password[20];
	char str2[100];
}std;

void studentscore(int counter); //To save the scores of Students
void StartQuiz(void); //To begin the Quiz
void Score(void); //To show The Scores
void Quit(void); //To quit the Quiz
int compare(FILE *f2,FILE *f1); //To compare the User input with possible outcomes of the specific question
void printQuestion(int); //To Display the questions.
int match(int); //To Compare the User ID

int main()
{
	system("cls");
	FILE *front; //Homescreen Openeing file
	char key; //Character gainer for choice
	int pass,bound;
	void (*call[3])(void)={StartQuiz, Score, Quit}; //functions for choice 
	
	char fr[100]; 
	front=fopen("front.txt","r");
	while(!feof(front))
	{
		fgets(fr,100,front);
		printf("%s",fr);
	}
	fclose(front);
	key=getch();
	key=toupper(key); 
	

    	
   {
	if(key =='S')
	{
		bound=1;
	if((pass=match(bound))==1) //Matching the user ID
	(*call[0])();
	}
	else if(key =='M')
	{
		bound=0;
	 if((pass=match(bound))==1)
	 (*call[1])();
	}
	else if(key=='Q')
	(*call[2])();
    else
    {
	system("cls");
	main();
    }


  }
}

int compare(FILE * fPtr1, FILE * fPtr2) //Comparision of files
{
    char ch1, ch2;
    fPtr2= fopen("input1.txt","r"); //Stores the User Input answer
    do{
    	ch1=fgetc(fPtr1);
    	ch2=fgetc(fPtr2);
    	if(ch1!=ch2)
    	return -1;
    	else
    	{
    	ch1=fgetc(fPtr1);
    	ch2=fgetc(fPtr2);	
		}
	}while(ch1!= EOF || ch2!= EOF);
    fclose(fPtr1);
    fclose(fPtr2);
     
	return 1;
}
void printQuestion(int q) // function for printing the question
{
	FILE *f3;
	char ch;
	
	if(q==1)
	{
		f3=fopen("question1.txt","r");
		while((ch=fgetc(f3))!=EOF)
		{
			printf("%c",ch);
		}
		fclose(f3);
		
	}
	else if(q==2)
	{
		f3=fopen("question2.txt","r");
		while((ch=fgetc(f3))!=EOF)
		{
			printf("%c",ch);
		}
		fclose(f3);
	}
	else if(q==3)
	{
		f3=fopen("question3.txt","r");
		while((ch=fgetc(f3))!=EOF)
		{
			printf("%c",ch);
		}
		fclose(f3);
	}
	else if(q==4)
	{
		f3=fopen("question4.txt","r");
		while((ch=fgetc(f3))!=EOF)
		{
			printf("%c",ch);
		}
		fclose(f3);
	}
	else if(q==5)
	{
		f3=fopen("question5.txt","r");
		while((ch=fgetc(f3))!=EOF)
		{
			printf("%c",ch);
		}
		fclose(f3);
	}
}
void StartQuiz(void) //Quiz Starting Function
{
    	FILE *f2,*f1,*inst,*checking;
    	int result1,result2,result3,result4,result5,result6; //declaration of variable to store the comparision of two answers consecutively.
    	int count=0,i,j=0; //counter for scoring (Counting the correct answer
    	char c1,c2,ch;
    	system("cls");
		inst=fopen("instructions.txt","r");
		while((ch=fgetc(inst))!=EOF)
		{
			printf("%c",ch);
		}
		fclose(inst);
        system("pause");
		//Loop to begin the Question Answers
		for(i=1;i<=5;i++){
		
	   switch(i)
	    {
	    case 1:	
		    system("cls");
		    printQuestion(i);
	        f2= fopen("answer1(a).txt","r");
	        f1= fopen("input1.txt","w");
	        while((ch=getchar())!=EOF)
            {
            
    	    fputc(ch,f1);
            }
            fclose(f1);
		    result1= compare(f2,f1);
		    f2= fopen("answer1(b).txt","r");
		    result2= compare(f2,f1);
		    f2= fopen("answer1(c).txt","r");
		    result3= compare(f2,f1);
		    f2= fopen("answer1(d).txt","r");
		    result4= compare(f2,f1);
		    if(result1==1 || result2==1 || result3==1 || result4 ==1 || result5==1)
		    {
		    	printf("Correct !!\n\nPress any key to move ");
			    count++;
	     	}
		    else
		    printf("Wrong :(\nPress any key to move ");
		    getch();
		    break;
		case 2:
			system("cls");
	        f2= fopen("answer2(a).txt","r");
	        f1=fopen("input1.txt","w");
	        printQuestion(i);
	        while((ch=getchar())!=EOF)
            {
        
    	    fputc(ch,f1);
            }
            fclose(f1);
		    result1= compare(f2,f1);
		    f2= fopen("answer2(b).txt","r");
		    result2= compare(f2,f1);
		    if(result1==1 || result2==1)
		    {
		    	printf("Correct !!\nPress any key to move ");
			    count++;
	     	}
		    else
		    printf("\nWrong :(\nPress any key to move ");
		    getch();
		    break;
		case 3:
			system("cls");
	        f2= fopen("answer3(a).txt","r");
	        f1=fopen("input1.txt","w");
	        printQuestion(i);
	        while((ch=getchar())!=EOF)
            {
            
    	    fputc(ch,f1);
            }
            fclose(f1);
		    result1= compare(f2,f1);
		    f2= fopen("answer3(b).txt","r");
		    result2= compare(f2,f1);
		    f2= fopen("answer3(c).txt","r");
		    result3= compare(f2,f1);
		    f2= fopen("answer3(d).txt","r");
		    result4= compare(f2,f1);
		    f2= fopen("answer3(e).txt","r");
		    result5= compare(f2,f1);
		    f2= fopen("answer3(f).txt","r");
		    result6= compare(f2,f1);
		    if(result1==1 || result2==1 || result3==1 || result4 ==1 || result5==1 || result6==1 )
		    {
		    	printf("Correct !!\nPress any key to move ");
			    count++;
	     	}
		    else
		    printf("Wrong :(\nPress any key to move ");
		    getch();
		    break;
		case 4:
			system("cls");
	        f2= fopen("answer4(a).txt","r");
	        f1=fopen("input1.txt","w");
	        printQuestion(i);
	        while((ch=getchar())!=EOF)
            {
            
    	    fputc(ch,f1);
            }
            fclose(f1);
		    result1= compare(f2,f1);
		    if(result1==1)
		    {
		    	printf("Correct !!\nPress any key to move ");
			    count++;
	     	}
		    else
		    printf("\nWrong :(\nPress any key to move ");
		    getch();
		    break;
		case 5:
			system("cls");
	        f2= fopen("answer5(a).txt","r");
	        f1=fopen("input1.txt","w");
	        printQuestion(i);
	        while((ch=getchar())!=EOF)
            {
            
    	    fputc(ch,f1);
            }
            fclose(f1);
		    result1= compare(f2,f1);
		    f2= fopen("answer5(b).txt","r");
		    result2= compare(f2,f1);
		    f2= fopen("answer5(c).txt","r");
		    result3= compare(f2,f1);
		    f2= fopen("answer5(d).txt","r");
		    result4= compare(f2,f1);
		    if(result1==1 || result2==1 || result3==1 || result4 ==1)
		    {
		       printf("Correct !!\nPress anyr key to move ");
			   count++;
			}
		    else
		    printf("\nWrong :(\nPress any key to move ");
		    getch();
		    break;
	    }
	}       system("cls");
	        printf("\n\n\n\t\t\t\t\t  No. of correct Questions : %d",count);
	        printf("\n\n\n\t\t\t\t\t   No. of wrong Questions  : %d",(5-count));
	        count*=5;
	        printf("\n\n\t\t\t\t\t\t\tYour score : %d\n\n",count);
	        printf("\n\n\t\t\t\t\t      *******Thank You!*******");
	        
	        checking=fopen("checkingpoint.txt","a");
	
	        fprintf(checking,"%s\n",std.Id);//storing user id in file
	        fclose(checking);
	        getch();
	        
	        studentscore(count);
	        main(); // calling main again to know user choice
}
void Score(void) //function to show the Scores on the console
{
	system("cls");
    FILE *stud;
    char show;
    stud=fopen("score.txt","r");
  	
  	while(!feof(stud))
  	{
  	show=fgetc(stud);
  	printf("%c",show);
    }
}
void Quit(void) //function to quit the Quiz
{
	exit(1);
}
// User ID matching
int match(int bound) 
{
	FILE *userdetail, *checking;
	int loop , line=4, key=0;
	char check , str[512],checkuser[100]; //User ID info.
	userdetail = fopen("userinfo.txt","w+"); // To save information taken as input
	checking=fopen("checkingpoint.txt","r");
	FILE *userdata = fopen("user.txt", "r");
	system("cls");
    
    
    if (userdata == NULL) {
    printf("Failed to open file\n");
    }
    printf("\n   \t   \t\t\t\t ************Enter your ID*********\n\t\t\t\t\t\t\t");
    gets(std.Id); // taking user id as input
    fprintf(userdetail,"%s ",std.Id); // copying in file
    
    printf("\n   \t   \t\t\t\t **********Enter your Password******\n\t\t\t\t\t\t\t");
    gets(std.password);  //taking password as input from user
    fputs(std.password,userdetail); //copy in file
    
    rewind(userdetail);
    while(!feof(userdetail))
    fgets(std.str2,100,userdetail); //getting id and password into array
    if(bound==1)
    while(!feof(checking))
    {
    	fgets(checkuser,100,checking);
    	
    	checkuser[strlen(checkuser)-1]='\0';
    	if(strcmp(checkuser,std.Id)==0)
    	{
    		key++;
    		break;
		}
	}
    fclose(checking);
    if(key==0){
	
	
    for(loop = 0; loop<line; ++loop)
	{
    fgets(str, sizeof(str), userdata);
    fclose(userdetail);
    str[strlen(str)-1] = '\0';
    
    if(strcmp(std.str2,str) == 0 ) //comparing user id and password with user data.
    {
 	fclose(userdata);
     return 1;
    }
    }
    }
    else
    printf("\n\t\t\t\t\tTest has been conducted through this ID.\n\n");
    printf("\t\t\t\t\t\t Enter correct ID\n\n\t\t\t\t\tEnter R to try again or B to return\n");
    check = getch();
    check = toupper(check);
    while(1)
    {
    	if(check=='R' || check=='B')
    	break;
    	check = getch();
    	check = toupper(check);
	}
   
    
    if(check =='R')
	{
   	fclose(userdata);
   	match(bound);
    }
    else if(check =='B')
    {
   	fclose(userdata);
   	main();
    }

}
void studentscore(int count) //Function to store the User Scores
{
	FILE *stud;
	stud = fopen("score.txt","a");
	fprintf(stud,"%s  %d\n",std.Id,count);
	fclose(stud);
	
}
//End Of the Program!!
