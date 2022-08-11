#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
void computerword(void);
void computernumber(void);
void showLogo(void);
void userword(void);
void usernumber(void);
void loose(int i,char u1[50]);
void delay(int);
void credits(void);
void gotoxy(short x, short y)                                             
{
 COORD pos ={x,y};
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
struct score
{
	char name[50];
	int score;	
}hg;
int Score_Card(char name[50],int score)
{
	FILE*ptr;
	ptr=fopen("score.DAT","a+");
	fwrite(&hg,sizeof(hg),1,ptr);
	fclose(ptr);
}
int Display_Card(char name[30],int score)
{
	FILE*fp;
	fp=fopen("score.DAT","r");
	if(fp==NULL)
	{
		printf("\n\t\t\tNO RECORDS FOUND.....");
	}
		 printf("\n---------------------------------------------------------------------------------------------------------------------");
		 printf("\n\t\t\t\t\t\tSCORE CARD");
		 printf("\n--------------------------------------------------------------------------------------------------------------------");
	while((fread(&hg,sizeof(hg),1,fp))!=0)
	{
		printf("\n\t\tName:%s\tScore:%d",hg.name,hg.score);
		printf("\n--------------------------------------------------------------------------------------------------------------------");

	}
	fclose(fp);
}
void main()
{	

   
   PlaySound(TEXT("Tetris.wav"),NULL,SND_FILENAME|SND_ASYNC|SND_LOOP);

  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  printf("DATE:%d-%d-%d \nTIME:%d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1,tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
  printf("LOADING..........");
	printf("\n");
	showLogo();
	printf("\n");
	system("COLOR 0A");
	printf("LOADED");
	int choice,gamechoice;
	printf("\n");
		printf("\n");
	printf("--------------------------------------------------------------------------------------------------------------------");
	printf("\n\t\t\t\t\t\tWELCOME TO HANGMEN GAME");
	printf("\n--------------------------------------------------------------------------------------------------------------------");
	printf("\n\n HOW TO PLAY : ");
	printf("\n\n* You will get just TEN chances to guess the right word");
	printf("\n\n* Each wrong answer will be hanged as a part of man ");
    printf("\n\n* So help the Man and get...set...GO..!!");
    printf("\n\n Save The Man....\n");
    printf("\n--------------------------------------------------------------------------------------------------------------------");
    printf("\n");
		printf("\n\n\t\t\t\t\t\t MENU : ");
	printf("\n--------------------------------------------------------------------------------------------------------------------");
	printf("\n\t 1-USER VS USER");
	printf("  \t\t   2-COMPUTER VS USER");
	printf("\t 3-CREDITS");
	printf("\t\t 4-SCORE CARD");
	printf("\t 5-Exit");
       	printf("\n--------------------------------------------------------------------------------------------------------------------");  
       	printf("\nENTER THE CHOICE:");
	scanf("%d",&choice);
	system("cls");
	system("COLOR 0A");
	if(choice==2)
	{
		        	printf("\n---------------------------------------------------------------------------------------------------------------------\n");
		            printf("\n\t\t\t\t\t\t COMPUTER VS USER MODE\n");
		            printf("\n-------------------------------------------------------------------------------------------------------------------\n");
		            printf(" \n HOW TO PLAY : \n");
		            printf("\n --> PRESS 1 for NUMBER game ");
		            printf("\n --> PRESS 2 for WORD game ");
		            printf("\n --> You have to guess the number or wordin just TEN tries \n");
		            printf("\n---------------------------------------------------------------------------------------------------------------------");
		           printf("\t\t\t 1-NUMBER GAME\t\t\t\t\t\t\t2-WORD GAME");
		            printf("\n---------------------------------------------------------------------------------------------------------------------");
		           printf("\nENTER THE CHOICE:");
		              scanf("%d",&gamechoice);
		         system("cls");
		         system("COLOR 0A");

		        if(gamechoice==2)
		        computerword();
		        
		        else if(gamechoice==1)
		        computernumber();
		
		
	}
	else if(choice==4)
	{
		Display_Card(hg.name,hg.score);
	}

	else if(choice==3)
	{
		credits();
	}
	else if(choice==1)
	{
		printf("\n---------------------------------------------------------------------------------------------------------------------\n");
		printf("\n\t\t\t\t\t\t USER VS USER MODE\n");
		printf("\n-------------------------------------------------------------------------------------------------------------------\n");
		printf(" \n HOW TO PLAY : \n");
		printf("\n --> PRESS 1 for NUMBER game ");
		printf("\n --> PRESS 2 for WORD game ");
		printf("\n --> You have to guess the no or wordin just TEN tries \n");
		printf("\n---------------------------------------------------------------------------------------------------------------------");
		printf("\n\t\t\t 1-NUMBER GAME\t\t\t\t\t\t\t2-WORD GAME");
		printf("\n---------------------------------------------------------------------------------------------------------------------");
		printf("\nENTER THE CHOICE:");
		scanf("%d",&gamechoice);
		system("cls");
system("COLOR 0A");
		if(gamechoice==2)
		userword();
		else if(gamechoice==1)
		usernumber();

	}
		
	}
	
void showLogo(void)
    {

       printf("\n");
FILE *fp;
	fp=fopen("hangman.TXT","r");
	char ch;
	
	
	while(1)
	{
		ch=fgetc(fp);
		if(ch==EOF)
		{
			break;
		}
			system("COLOR 0A");
			printf("\033[0m"); 
		printf("%c",ch);
	}
         }
void drawRectangle(int startX, int endX, int startY, int endY){
	system("cls");system("COLOR 0A");
	int x,y;
	for(x=startX;x<=endX;x++){
		for(y=startY;y<=endY;y++){
			if(x==startX || x==endX || y==startY || y==endY){
				gotoxy(x,y);
				printf("*");
			}
		}
	}
}
	void credits(void)
{
	PlaySound(TEXT("credits.wav"),NULL,SND_FILENAME|SND_ASYNC|SND_LOOP);
	system("cls");system("COLOR 0A");
		printf("\n--------------------------------------------------------------------------------------------------------------------");
	printf("\n\t\t\t\t\t\t CREDITS\n");
	printf("\n--------------------------------------------------------------------------------------------------------------------");
	drawRectangle(45,75,5,10);
	gotoxy(50,7); 
	printf("HANGMAN PROJECT ON C");
	delay(5);
	system("cls");system("COLOR 0A");
	drawRectangle(35,95,5,10);
	gotoxy(40,7);
	printf("MADE BY:MUHAMMAD HAMMAD,NASAR NAEEM,RAFAY SIDDIQUI");
	delay(5);
    system("cls");system("COLOR 0A");
    drawRectangle(45,75,5,10);
    gotoxy(50,7);
    printf("ROLL NO:19K-0212,19K-1405,19K-0320");
delay(5);
	system("cls");system("COLOR 0A");
		drawRectangle(45,75,5,10);
    gotoxy(50,7);

    printf("FAST UNIVERSITY(NUCES)");
    delay(5);
    drawRectangle(45,85,5,10);
    gotoxy(50,7);
    printf("SUBMITTED TO:SIR BASIT JASANI");
    delay(5);
    
}

void userword(void)
{
		printf("\n---------------------------------------------------------------------------------------------------------------------\n");
		printf("\n\t\t\t\t\t\t USER VS USER MODE(WORD MODE)\n");
		printf("\n-------------------------------------------------------------------------------------------------------------------\n");
char word[50],guess[50],u1[20],u2[20],h[20];
int i=0,j=0,k=0,letter,won=0,wrong,s=50,m=0,l=0,d=0,r=0,p=0,f=0;
			printf("\n\n ENTER NAME OF FIRST USER: ");
		scanf("%s",u1);
		printf("\n ENTER NAME OF SECOND USER : ");
		scanf("%s",u2);
	     
	printf("\n\n%s ENTER THE WORD %s : ",u1,u2);
while((word[i]=getch())!='\r')
    {
    printf("-");
    i++; //length of word
    }
    printf("\n\n%s GIVE HINT to %s:",u1);
    scanf("%s",&h);
    printf("\n\nHint: %s",h);
    char repeat[i];
    
    printf("\n\n%s YOUR TURN TO GUESS \n",u2);
    printf("\n\nIt is an %d letter word\n",i);
     //printf("YOUR TIME STARTS NOW:");
     
//	int z;
//	for(z=0;z<10;z++)
//	{
//		delay(1);
//		printf("%d",z+1);
//	}
time_t game_time=40;
time_t start =time(NULL);

while(m<10) // m is chances
    {
    	gotoxy(90,7);
    	printf("Remaining: %d second(s)",game_time-(time(NULL) - start));
    	if(time(NULL)-start>=game_time){
    		system("cls");system("COLOR 0A");
    		printf("Time Out");
    		strcpy(hg.name,u1);
    		s=0;
    		hg.score=s;
    		Score_Card(hg.name,hg.score);
    		exit(1);
		}
    	if(kbhit()){ //keyboard hit 
    	   
	           p=0;	
	           letter=0;    	
               fflush(stdin);
	           guess[j]=getche(); //getche wait for keyboard input
	           p=0;
	           system("cls");system("COLOR 0A");
	           wrong=0;
	           //guess[j];
	           p=0;
for(k=0;k<=j;k++)
{	
if(guess[j]==guess[k])
	{
		p++;
    }
}

if(p==1)
{
	    p=0;
for(k=0;k<=i;k++)
	{
		
             if(guess[j]==word[k])	
	         {
	                    won++;	
	                    wrong++;	
	                    letter++;
for(f=0;f<i;f++)
{
	if(f==k)
             	printf("%c",word[k]);
	else
	            printf("-");
}
       printf("\n");
	//printf("\nThe word is present at: %d",k+1);
if(letter<=i)
	{		
	         printf("\n %c is Correct",guess[j]);
	         printf("\nNo of correct guess : %d\n",won);
	//loose(m);
		}
    }
   }
if(wrong==0)
   	{
   		
   	          printf("\n %c is wrong\n",guess[j]);
   	          printf("\nNo of correct guess : %d\n",won);
              s=s-5;
   	          loose(m,u1);
   	          m++;
    }
    
if (won==i)
    {
    	PlaySound(TEXT("win.wav"),NULL,SND_FILENAME|SND_ASYNC);
    	printf("\nYOU SAVED THE MAN.....");
	        printf("\nCONGRAT YOU WON\n");
	        hg.score=s;
	        strcpy(hg.name,u1);
	        Score_Card(hg.name,hg.score);
	        char ch;
	        printf("PRESS s IF YOU WANT TO SEE THE SCORE:");
	        scanf("%c",&ch);
	        if(ch=='s')
	        {
	        	Display_Card(hg.name,hg.score);
			}
	        break;
    }
    

	j++; 
}
else
{
           	 printf("\nYou already entered this alphabat\n");

         	 p=0;
             printf("\nNo of correct guess : %d\n",won);
	         //loose(m,u1);
}
}
}
}




void usernumber(void)
	{
			printf("\n---------------------------------------------------------------------------------------------------------------------\n");
		printf("\n\t\t\t\t\t\t USER VS USER MODE(NUMBER MODE)\n");
		printf("\n-------------------------------------------------------------------------------------------------------------------\n");
			int a,i,no,j=0,k=0;
	char u1[20],u2[20];
	printf("USER 1 ENTER YOUR NAME:");
	scanf("%s",&u1);
	printf("\n\nUSER 2 ENTER YOUR NAME:");
	scanf("%s",&u2);
		printf("\n\nThe number range should be 1<num<100\n");
		printf("\n %s ENTER NUMBER:",u1);
		while(j!=1)
		{
		       scanf("%d",&no);
		       if(no>1 && no<100)
		                j++;
		else
		printf("ENTER AGAIN\n");
		}
		system("cls");system("COLOR 0A");
		printf("%s YOU WILL HAVE 10 TRY:\n",u2);
		printf("%s GUESS THE NUMBER:",u2);
		for(i=0;i<10;i++)
		{
			 scanf("%d",&a);
			 system("cls");
			 system("COLOR 0A");

			 if(no==a)
			 {
			 	
			          printf("CORRECT.YOU WON \n");
			          break;
		     }
		    else if(a<no)
		    {
			    printf("The number entertered is lesser \n");
			    loose(k,u1);
			    k++;

		    }
			else if(a>no)
			{
		          printf("the number entertered is greater \n");
		          loose(k,u1);
		          k++;
		    }
			
	    }


		
		
	}



	void computernumber(void)
	{
			printf("\n---------------------------------------------------------------------------------------------------------------------\n");
		printf("\n\t\t\t\t\t\t COMPUTER VS USER MODE(NUMBER MODE)\n");
		printf("\n-------------------------------------------------------------------------------------------------------------------\n");
		int a,i,no,k=0;
		 srand((unsigned)time(NULL));
		 a=rand();
		 a=a%100;
		printf("Enter Your Name:");
		char u1[50];
		fflush(stdin);
		gets(u1);
		printf("\n\nGuess the number:  0>=no<100\n");
		printf("%s will have 10 tries\n",u1);
		for(i=0;i<10;i++)
		{
			scanf("%d",&no);
			system("cls");system("COLOR 0A");

			if(no==a)
			{
			     printf("CORRECT.YOU WON \n");
			      break;
		    }
		    else if(no<a)
		    {
		             printf("The number entereded is less \n");
		            loose(k,u1);
		             k++;
		    }
		    else if(no>a)
		    {			
		             printf("The number entereded is greater\n");
		           loose(k,u1);
		             k++;
		    }
			
	    }


	}
	
	
void computerword(void)
{
		printf("\n---------------------------------------------------------------------------------------------------------------------\n");
		printf("\n\t\t\t\t\t\t COMPUTER VS USER MODE(WORD MODE)\n");
		printf("\n-------------------------------------------------------------------------------------------------------------------\n");
	int i=0,j=0,s=50,a,k=0,wrong=0,right=0,won=0,correct=0,p=0;
	char guess[50],word[12][12] = {"zygapophysis","xtemporized","maximization","polygamizing","zygapophyses","backflipping","demonstrator","conversation","presentation","reproduction","satisfaction","headquarters" };
	char u1[20];
	srand((unsigned)time(NULL)); 
	a=rand(); // a is temporary varible in which we store the random word
	a=a%12; // 12 is the total number of words
	printf("\nPLEASE ENTER YOUR NAME:");
	scanf("%s",&u1);
	printf("\n%s guess the 12 letter word\n",u1);
	printf("\nYOU WILL HAVE 10 CHANCES \n"); 
	
	
	time_t game_time=40;
time_t start =time(NULL);

	
while(k<10) // k is chances
	{
		gotoxy(90,7); 
    	printf("Remaining: %d second(s)",game_time-(time(NULL) - start));
    	if(time(NULL)-start>=game_time){
    		system("cls");system("COLOR 0A");
    		printf("\nYOU FAILED TO SAVE THE MAN....");
    		printf("Time Out");
    		strcpy(hg.name,u1);
    		s=0;
    		hg.score=s;
    		Score_Card(hg.name,hg.score);
    		exit(1);
		}
    	if(kbhit()) //kbhit means keyboard hit
		{

		        right=0;
		        wrong=0;
		        fflush(stdin);
               guess[j]=getche();
                system("cls");
				system("COLOR 0A");
for(i=0;i<=j;i++) 
    {
	if(guess[j]==guess[i])
	{
		p++;
	}
    }      
 if(p==1)
 { 
 p=0;      
for(i=0;i<12;i++)
		{
              if(guess[j]==word[a][i]) 			
			{
				wrong++;
				right++;
				correct++;
				printf("\nThe word is present at: %d\n",i+1);
if(right<2)
			{
			printf("%c is Correct\n",guess[j]);
			printf("NO of correct guess : %d\n",correct);
			//loose(k);
		    }
	
			}
		}
if(correct==12) //12 is the length of word
		{
			PlaySound(TEXT("win.wav"),NULL,SND_FILENAME|SND_ASYNC);
			printf("YOU WON\n");
			printf("YOU SAVED THE MAN.");
			  hg.score=s;
	        strcpy(hg.name,u1);
	        Score_Card(hg.name,hg.score);
	          printf("PRESS s IF YOU WANT TO SEE THE SCORE:");
	          char ch;
	        scanf("%c",&ch);
	        if(ch=='s')
	        {
	        	Display_Card(hg.name,hg.score);
			}
	        break;
			//printf("the correct word is: %s\n",word[a][12]);
			break;
		}
		
		
if(wrong==0)
		{
			printf("%c is wrong\n",guess[j]);
			printf("NO of correct guess : %d\n",correct);
            s=s-5;
			loose(k,u1);
			k++;
			
			
		}
	}
else
	{
		p=0;
	printf("\nYou have already enter this alphabat\n");
	printf("NO of correct guess : %d\n",correct);
	loose(k,u1);
   }
   j++;
	
}
}
}



void delay(int number_of_seconds) //time function
{
	int milli_seconds=1000*number_of_seconds;
	clock_t start_time=clock();
	while(clock()<start_time+milli_seconds);
}

	



 void loose(int i,char u1[50]) // loose function
  {
  	int s=0;
  	char ch;
 switch (i) {
     case 0 :
     	PlaySound(TEXT("nope.wav"),NULL,SND_FILENAME|SND_ASYNC);
      printf("NUMBER OF WRONG GUESS: %d\n\n",++i);
      printf("\n");
      printf("\n");
      printf("\n");
      printf("\n");
      printf("\n");
      printf("\n");
      printf("____________\n\n");
      break;
     case 1 :
     	PlaySound(TEXT("nope.wav"),NULL,SND_FILENAME|SND_ASYNC);
      printf("NUMBER OF WRONG GUESS: %d\n\n",++i);
      printf("\n");
      printf("  |\n");
      printf("  |\n");
      printf("  |\n");
      printf("  |\n");
      printf("  |\n");
      printf("__|_________\n\n");
     break;
     case 2 :
     	PlaySound(TEXT("nope.wav"),NULL,SND_FILENAME|SND_ASYNC);
      printf("NUMBER OF WRONG GUESS: %d\n\n",++i);
      printf("  _______\n");
      printf("  |\n");
      printf("  |\n");
      printf("  |\n");
      printf("  |\n");
      printf("  |\n");
      printf("__|_________\n\n");
     break;
     case 3 :
     	PlaySound(TEXT("nope.wav"),NULL,SND_FILENAME|SND_ASYNC);
      printf("NUMBER OF WRONG GUESS: %d\n\n",++i);
      printf("  _______\n");
      printf("  |/\n");
      printf("  |\n");
      printf("  |\n");
      printf("  |\n");
      printf("  |\n");
      printf("__|_________\n\n");
     break;
     case 4 :
     	PlaySound(TEXT("nope.wav"),NULL,SND_FILENAME|SND_ASYNC);
      printf("NUMBER OF WRONG GUESS: %d\n\n",++i);
      printf("  _______\n");
      printf("  |/   | \n");
      printf("  |    O \n");
      printf("  |\n");
      printf("  |\n");
      printf("  |\n");
      printf("__|_________\n\n");
     break;
     case 5 :
     	PlaySound(TEXT("nope.wav"),NULL,SND_FILENAME|SND_ASYNC);
      printf("NUMBER OF WRONG GUESS: %d\n\n",++i);
      printf("  _______\n");
      printf("  |/   | \n");
      printf("  |    O \n");
      printf("  |    |\n");
      printf("  |    |\n");
      printf("  |\n");
      printf("__|_________\n\n");
     break;
     case 6 :
     	PlaySound(TEXT("nope.wav"),NULL,SND_FILENAME|SND_ASYNC);
      printf("NUMBER OF WRONG GUESS: %d\n\n",++i);
      printf("  _______\n");
      printf("  |/   | \n");
      printf("  |    O \n");
      printf("  |   \\|\n");
      printf("  |    | \n");
      printf("  |\n");
      printf("__|_________\n\n");
     break;
     case 7 :
     	PlaySound(TEXT("nope.wav"),NULL,SND_FILENAME|SND_ASYNC);
      printf("NUMBER OF WRONG GUESS: %d\n\n",++i);
      printf("  _______\n");
      printf("  |/   | \n");
      printf("  |    O \n");
      printf("  |   \\|/\n");
      printf("  |    | \n");
      printf("  |\n");
      printf("__|_________\n\n");
     break;
     case 8 :
     	PlaySound(TEXT("nope.wav"),NULL,SND_FILENAME|SND_ASYNC);
      printf("NUMBER OF WRONG GUESS: %d\n\n",++i);
      printf("  _______\n");
      printf("  |/   | \n");
      printf("  |    O \n");
      printf("  |   \\|/\n");
      printf("  |    | \n");
      printf("  |   /\n");
      printf("__|_________\n\n");
     break;
     case 9 :
     	PlaySound(TEXT("fail.wav"),NULL,SND_FILENAME|SND_ASYNC);
      printf("NUMBER OF WRONG GUESS: %d\n\n",++i);
      printf("  _______\n");
      printf("  |/   | \n");
      printf("  |    X \n");
      printf("  |   \\|/\n");
      printf("  |    | \n");
      printf("  |   / \\\n");
      printf("__|_________\n\n");
      printf("\n GAME OVER");
      printf("\nBETTER LUCK NEXT TIME.");
      strcpy(hg.name,u1);
      hg.score=s;
      Score_Card(hg.name,hg.score);
      printf("\nPRESS s to see the Score:");
      scanf("%c",&ch);
      if(ch=='s');
      Display_Card(hg.name,hg.score);
     break;
 }
}
