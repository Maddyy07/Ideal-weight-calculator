#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include <stdlib.h>
float inaday(double a); //In a day module starts from line 364
double caloriesugg(double weight,double height,int age,char gender); //caloriesugg module occurs at 145 line
void monthly(double a,float mc); //month module starts at 121
float scan(char fud[]);
void unitcalsteps(double uc,int us);
void heightless5(double height,float weight,char gender[]);
void history();
struct monthzz{
    char monthcapi[20];
    char monthsmall[20];
    char monthz1[20];
};
struct juices{
    int id;
    char name[20];
}juname[5];
struct juices23{
    float ml;
    float calories;
}jucal[5];
struct fruit{
    int id;
    char name[20];
}fruname[35];
struct fruit2po{
    float grams;
    float calories;
}frugram[35];
struct veg{
    int id;
    char name[20];
}vegay[30];
struct vegcalo{
    float grams;
    float calories;
}vegram[30];
struct nveg{
    int id;
    char name[20];
}nvegay[15];
struct nvegcalo{
    float grams;
    float calories;
}nvegram[15];
//P. Naga Srinivas
int main(){
    /*Asking the user for his/her weight,height,age and gender so that
    we can caclulate his/her ideal weight*/
    float weight,mc;
    int counter=0;
    printf("\n\t\t\t\t\t    WELCOME TO FITNESS ANALYSER\n-------------------------------------------------------------------------------------------------------------\n\n");
    printf("		                            Details");
    char name[10];
    printf("\nPlease enter your name Mr./Mrs. : ");
    scanf("%[^\n]",name);
    printf("\n\nPlease enter your weight(in kilograms): ");
    while(counter!=1){
        scanf("%f",&weight);
        if(weight>0){
        counter=1;}
        else{
        printf("Please enter a proper weight: ");}
    }
    double height,height2;counter=0;double inches=0;
    while(counter!=1){
        printf("\n\nPlease enter your height(in feet): ");
        scanf("%lf",&height);
        printf("\nPlease enter the inches seperately(in inch): ");
        scanf("%lf",&inches);
            inches=(inches/12);
            height=height+inches;
            if(height>=4.5){
                counter=1;
            }
    }
    height2=height;
    char gender[6];counter=0;char gender1[4]={'m','a','l','e'},gender2[6]={'f','e','m','a','l','e'},gender3[4]={'M','A','L','E'},gender4[6]={'F','E','M','A','L','E'};
    printf("\nPlease enter your gender(male/female): ");
    while(counter!=1){
        int len=0;
        scanf("%s",gender);
        if(gender[0]=='m'||gender[0]=='M'){
            for(int i=0;i<4;i++){ 
                if(gender[i]==gender1[i]||gender[i]==gender3[i]){
                   len++;
                }
            }
        }    
        else if(gender[0]=='f'||gender[0]=='F'){
            for(int i=0;i<6;i++){ 
                if(gender[i]==gender2[i]||gender[i]==gender4[i]){
                   len++;
                }
        }
        }
        if(len==6||len==4){
            counter=1;
        }    
        else{
           printf("\nPlease enter a valid gender either male (or) female: ");
        }     
    }
    //Asking the user for his age
    int age;
    printf("\nPlease enter your age: ");counter=0;
    while(counter!=1){
        scanf("%u",&age);
        if(age>=7)
         counter=1;
        else printf("\nPlease enter a valid age(age more than 7): ");
    }
printf("\n\t\t************************\n");
    //Ideal Weight Calculation
    //Dividing the people based on their height 
    double idw;int c1=0;int var1; 
    if(height>=5){
        c1=1;
        height=height-5;
        height=height*12;
        if(gender[0]=='m'||gender[0]=='M'){
            idw=52+1.9*height;
            printf("\nMr.%s your ideal weight is %.3lf kg.\n",name,idw);
        }
        else{
            idw=49+1.7*height;
            printf("\nMrs.%s your ideal weight is %.3lf kg.\n",name,idw);
        }
    }else{
    	heightless5(height,weight,gender);
    }
	var1=0;
	if(c1==1){
    if(weight>idw-3 && weight<idw+3){
        printf("\nYou are maintaining a proper diet.\n");
        var1=1;
    }
    else if(weight<idw-3){
        printf("\nYou are underweight\n");
        var1=2;
    }
    else{
        printf("\nYou are overweight\n");
        var1=3;
    }
    }
    int choice,x=1;
    while(x!=0&&var1!=0) {
    printf("\n\nWould you like to be recommended for your physical activites?\nEnter 1 for yes or 2 for no.: \n");
    scanf("%u",&choice);
    if((choice==1)||(choice==2)) {
        x=0;
    }
    else {
        x=1;
    }
    }
    if(choice==1){
        if(var1==3)
        printf("\nCardio and sports are better options for burning more calories!\n");
        else if(var1==2)
        printf("\nAdd more calories in your diet suggested by us!\n");
        else if(var1==1)
        printf("\nYou are in perfect shape!\n");
    }
    double a=caloriesugg(weight,height2,age,gender[0]); 
    mc=inaday(a);
int y,steps;
printf("\n\nWould you like to check the unitcal and number of calories burnt by steps?\n");
printf("\nif yes press 1 or press 2 for no:");
scanf("%d",&y);
if(y==1) {
	printf("\nEnter the number of steps:");
	scanf("%d",&steps);
	unitcalsteps(a,steps);
};
monthly(a,mc);
y=0;
while(y!=1){
printf("\nPlease enter 1 to know your history, 2 to skip: ");
scanf("%d",&y);
if(y==1){
    history();
}else if(y==2){
    printf("\n\nThank you for using our analyser.");
    y=1;
}
else{
    continue;
}
}
return 0;
}
//Prasanth S
void heightless5(double height,float weight,char gender[]){
    int j1,s1,m1,sh1;
    j1=1;
if(height>=4.50&&height<4.58){
   j1=0;
   if(gender[0]=='m'||gender[0]=='M'){
    printf("According to inputs the ideal weight for your height should be 32Kg\n");
   }
   else{
     printf("According to inputs the ideal weight for your height should be 32Kg\n");
   }
}
s1=1;
if(height>=4.51&&height<4.60){
   s1=0;
   if(gender[0]=='m'||gender[0]=='M'){
    printf("According to inputs the ideal weight for your height should be 34Kg\n");
   }
   else{
     printf("According to inputs the ideal weight for your height should be 34Kg\n");
   }
}
m1=1;
if(height>=4.60&&height<4.75){
   m1=0;
   if(gender[0]=='m'||gender[0]=='M'){
    printf("According to inputs the ideal weight for your height should be 37Kg\n");
   }
   else{
     printf("According to inputs the ideal weight for your height should be 36Kg\n");
   }
}
sh1=1;
if(height>=4.70&&height<4.90){
   sh1=0;
   if(gender[0]=='m'||gender[0]=='M'){
    printf("According to inputs the ideal weight for your height should be 43Kg\n");
   }
   else{
     printf("According to inputs the ideal weight for your height should be 41Kg\n");
   }
}
if (j1==0){
    if(gender[0]=='m'||gender[0]=='M'){
        if(weight>32){
            printf("\nYou are over weight, please maintain proper diet\n");
        }
        else if(weight<32){
            printf("\nYou are under weight,please maintain proper diet\n");
        }
        else{
            printf("\nYou are in healthy weight,please maintain the same diet\n");
        }
        }
    else{
        if(weight>32){
            printf("\nYou are over weight, please maintain proper diet\n");
        }
        else if (weight<32){
            printf("\nYou are under weight,please maintain proper diet\n");
        }
        else{
            printf("\nYou are in healthy weight,please maintain the same diet\n");
        }
    }
}
if (s1==0){
    if(gender[0]=='m'||gender[0]=='M'){
        if(weight>34){
            printf("\nYou are over weight, please maintain proper diet\n");
        }
        else if (weight<34){
            printf("\nYou are under weight,please maintain proper diet\n");
        }
        else{
            printf("\nYou are in healthy weight,please maintain the same diet\n");
        }
        }
    else{
        if(weight>34){
            printf("\nYou are over weight, please maintain proper diet\n");
        }
        else if (weight<34){
            printf("\nYou are under weight,please maintain proper diet\n");
        }
        else{
            printf("\nYou are in healthy weight,please maintain the same diet\n");
        }
    }
}
if (m1==0){
    if(gender[0]=='m'||gender[0]=='M'){
        if(weight>36){
            printf("\nYou are over weight, please maintain proper diet\n");
        }
        else if (weight<36){
            printf("\nYou are under weight,please maintain proper diet\n");
        }
        else{
            printf("\nYou are in healthy weight,please maintain the same diet\n");
        }
        }
    else{
        if(weight>36){
            printf("\nYou are over weight, please maintain proper diet\n");
        }
        else if (weight<36){
            printf("\nYou are under weight,please maintain proper diet\n");
        }
        else{
            printf("\nYou are in healthy weight,please maintain the same diet\n");
        }
    }
}
if (sh1==0){
    if(gender[0]=='m'||gender[0]=='M'){
        if(weight>41){
            printf("\nYou are over weight, please maintain proper diet\n");
        }
        else if (weight<41){
            printf("\nYou are under weight,please maintain proper diet\n");
        }
        else{
            printf("\nYou are in healthy weight,please maintain the same diet\n");
        }
        }
    else{
        if(weight>41){
            printf("\nYou are over weight, please maintain proper diet\n");
        }
       else  if (weight<41){
            printf("\nYou are under weight,please maintain proper diet\n");
        }
        else{
            printf("\nYou are in healthy weight,please maintain the same diet\n");
        }
    }
}
}
// R Madhavan-caloriesuggestion module function
double caloriesugg(double weight,double height,int age,char gender){
double a;
if(gender=='m'||gender=='M')
{
height = height*30.48;
//BMR formula-Minimum calories required for basic functions at rest
a=88.362+13.397*weight+4.799*height-5.677*age;
printf("\nCalories required per day: %.3lf\n\n",a);
}
else
{
height= height*30.48;
a=447.593+9.247*weight+3.098*height-4.330*age;
printf("\n\nCalories required per day: %.3lf\n\n",a);
}
return a;
}
void unitcalsteps(double a,int steps) {
	printf("\n\nEach unit of proteins and carbohydrates contain 4 calories\n");
    printf("\n\nEach unit of fats contain 9 calories");
steps=steps*0.04;
int c= steps+a;
printf("\n\nNumber of calories burnt by steps is %d",steps);
printf("\n\nTotally you have burnt %d  calories in a day",c);
}
//in a day by joel
float inaday(double a) {
	int size=20;
    for(int i=0;i<30;i++){
    vegay[i].id=i+1;
    nvegay[i].id=i+1;
    }
    FILE *ptr3=fopen("vegnames.txt","r");
    char ch5[20]=" ";
    for(int i=0;i<30;i++){
        fgets(vegay[i].name,sizeof(vegay[i].name),ptr3);
    }
    fclose(ptr3); 
    ptr3=fopen("Vegrams.txt","r");
    for(int i=0;i<30;i++){
        fgets(ch5,sizeof(ch5),ptr3);
        vegram[i].grams=atof(ch5);
    }
    fclose(ptr3);
    ptr3=fopen("veggie.txt","r");
    for(int i=0;i<30;i++){
        fgets(ch5,sizeof(ch5),ptr3);
        vegram[i].calories=atof(ch5);
    }
    fclose(ptr3);
    ptr3=fopen("nvegnames.txt","r");
    for(int i=0;i<15;i++){
        fgets(nvegay[i].name,sizeof(nvegay[i].name),ptr3);
    }
    fclose(ptr3);
    ptr3=fopen("nvegrams.txt","r");
    for(int i=0;i<15;i++){
        fgets(ch5,sizeof(ch5),ptr3);
        nvegram[i].grams=atof(ch5);
    }
    fclose(ptr3);
    ptr3=fopen("nveggie.txt","r");
    for(int i=0;i<15;i++){
        fgets(ch5,sizeof(ch5),ptr3);
        nvegram[i].calories=atof(ch5);
    }
    fclose(ptr3);
    ptr3=fopen("fruitnames.txt","r");
    for(int i=0;i<34;i++){
        fruname[i].id=i+1;
        fgets(fruname[i].name,sizeof(fruname[i].name),ptr3);
    }
    fclose(ptr3);
    ptr3=fopen("fruitgrams.txt","r");
    for(int i=0;i<34;i++){
       fgets(ch5,sizeof(ch5),ptr3);
       frugram[i].grams=atof(ch5);
    }
    fclose(ptr3);
    ptr3=fopen("fruitie.txt","r");
    for(int i=0;i<34;i++){
        fgets(ch5,sizeof(ch5),ptr3);
        frugram[i].calories=atof(ch5);
    }
    fclose(ptr3);
    ptr3=fopen("juicenames.txt","r");
    for(int i=0;i<5;i++){
        juname[i].id=i+1;
        fgets(juname[i].name,sizeof(juname[i].name),ptr3);
    }
    fclose(ptr3);
    ptr3=fopen("juml.txt","r");
    for(int i=0;i<5;i++){
      fgets(ch5,sizeof(ch5),ptr3);
      jucal[i].ml=atof(ch5);
    }
    fclose(ptr3);
    ptr3=fopen("jucal.txt","r");
    //char ch13[10]="";
    for(int i=0;i<5;i++){
        fgets(ch5,sizeof(ch5),ptr3);//junames
        jucal[i].calories=atof(ch5);
    } // ends here }
    /*for(int i=0;i<30;i++){
        printf("%s ",vegay[i].name);
    }
    printf("\n");
    for(int i=0;i<15;i++){
        printf("%s ",nvegay[i].name);
    }
    printf("\n");
    for(int i=0;i<5;i++){
       printf("%s ",juname[i].name);
    }
    printf("\n");
    for(int i=0;i<34;i++){
        printf("%s ",fruname[i].name);
    }*/
   int noof;float total=0.0;char session[3][10]={"morning","afternoon","evening"};
    for(int i=0;i<3;i++){
        char fooditem[20];
      printf("Please enter what you took in %s session:\n\n\t->Vegetables\n\t->Non-Vegetables\n\t->Fruits\n\t->Juices\n",session[i]);
      printf("\nEnter number of items you took: ");
      scanf("%d",&noof);
      int n=1;
      while(noof>0){
      fflush(stdin);
      printf("\nEnter the %d item you ate (veg/non veg/fruits/juices): ",(n));
      n++;
      scanf("%[^\n]",fooditem);
      total=total+scan(fooditem);
      noof--;
      }
    }
  printf("\n\nTotal calories taken are %.2f",total);
  if(total>a-15 && total<a+15){
    printf("\n\nCongratulations, you followed a proper diet.");
  }else if(total<a-15){
        printf("\n\nPlease follow our suggested calories and try to follow it.");
    }
    else{
        printf("\n\nYou have taken more calories than we have suggested!");
    }
    return total;
}
float scan(char fud[]){
    char fooditem23[20];
    int ide;
    //for vegetables
    if(!strcmp(fud,"veg") || !strcmp(fud,"vegetables")){
         fflush(stdin);
         puts("Enter the veg item name: ");
         scanf("%[^\n]",fooditem23);
         for(int i=0;i<30;i++){
            if(!(strncmp(fooditem23,vegay[i].name,strlen(fooditem23)))){
                ide=vegay[i].id;
                break;
            }
        }
        float grama;
        puts("\nEnter how many grams you have taken: ");
        scanf("%f",&grama);
        //returns the calorie the user got by taking vegetables from that 
        //particular grams 
        return (grama*(vegram[ide-1].calories)/vegram[ide-1].grams);
    }
    //for non-vegetables
    if(!strcmp(fud,"nonveg")||!strcmp(fud,"non veg")||!strcmp(fud,"non-vegetables")){
         fflush(stdin);
         puts("Enter the nonveg item name: ");
         scanf("%[^\n]",fooditem23);
         for(int i=0;i<15;i++){
            if(!(strncmp(fooditem23,nvegay[i].name,strlen(fooditem23)))){
                ide=nvegay[i].id;
                break;
            }
        }
        float grama;
        puts("\nEnter how many grams you have taken: ");
        scanf("%f",&grama);
        return (grama*(nvegram[ide-1].calories)/nvegram[ide-1].grams);
    }
    // for juices
    if(!strcmp(fud,"juices")||!strcmp(fud,"juice")){
         fflush(stdin);  
         puts("Enter the juice name: ");
         scanf("%[^\n]",fooditem23);
         for(int i=0;i<5;i++){
            if(!(strncmp(fooditem23,juname[i].name,strlen(fooditem23)))){
                ide=juname[i].id;
                break;
            }
         }
        float grama;
        puts("\nEnter how many ml you have taken: ");
        scanf("%f",&grama);
        return (grama*(jucal[ide-1].calories)/jucal[ide-1].ml);
    }
    // for fruits
    if(!strcmp(fud,"fruits")||!strcmp(fud,"fruit")) {
         fflush(stdin);
         puts("Enter the fruit name: ");
         scanf("%[^\n]",fooditem23);
         for(int i=0;i<35;i++){
            if(!(strncmp(fooditem23,fruname[i].name,strlen(fooditem23)))){
                ide=fruname[i].id;
                break;
            }
         }
         float grama;
        puts("\nEnter how many grams you have taken: ");
        scanf("%f",&grama);
        return (grama*(frugram[ide-1].calories)/frugram[ide-1].grams);
}
}
//PHD Surya Shanmuk
void monthly(double a,float mc){
    char month[10];
    FILE *fprt1=fopen("monthcapital.txt","r");
    FILE *fprt2=fopen("monthsmall.txt","r");
    FILE *fprt3=fopen("monthz.txt","r");
    struct monthzz names[12];
	int y=0;
    while(fgets(names[y].monthcapi,sizeof(names[y].monthcapi),fprt1)){
        fgets(names[y].monthsmall,sizeof(names[y].monthsmall),fprt2);
        fgets(names[y].monthz1,sizeof(names[y].monthz1),fprt3);
        y++;
    }
    fclose(fprt1);
    fclose(fprt2);
    fclose(fprt3);
    FILE *ptr124=fopen("month.txt","a");
    int days=0;
    fflush(stdin);
    while(days!=1){
    fflush(stdin);
    printf("\n\nPlease enter the month: ");
    scanf("%s",month);
    for(int i=0;i<12;i++){
         if(!(strncmp(month,names[i].monthcapi,strlen(month))) ||!(strncmp(month,names[i].monthsmall,strlen(month))) || !(strncmp(month,names[i].monthz1,strlen(month)))){
            days=1;
            break;
         }
    }
    }
    if(month[0]=='F' || month[0]=='f'){
        days=28;
    }else if(((month[0]=='j' || month[0]=='J') && (month[1]=='a' || month[1]=='A')) || ((month[0]=='j' || month[0]=='J') && ((month[1]=='u' || month[1]=='U') && (month[2]=='l' || month[2]=='L'))) || (month[0]=='m' || month[0]=='M') || ((month[0]=='A' || month[0]=='a') && month[1]=='u' || (month[1]=='U')) || (month[0]=='o' || month[0]=='O') || (month[0]=='d' || month[0]=='D')){
        days =31;
    }else{
        days=30;
    }
    a*=days;
    mc*=days;
    if (days < 28 && days >= 1)
    {
     printf("No. of Calories you have taken in the given number of days : %.2f\n",mc);
    }
    else if (days > 28 && days <= 31)
    {
        printf("No. of Calories you have taken in the month : %.2f\n",mc);
    };
    if (mc > a - 50.0 && mc < a + 50.0) {
        printf("\nYou are in healthy condition");
    }
    else if (mc < a - 50.0) {
            printf("\n\nYou should intake more calories to be healthy");
        }
        else{
            printf("\n\nYou need to intake less calories to be healthy");
        }
    fprintf(ptr124,"In the month %s you have taken a total of %.2f calories\n",month,mc);
    fclose(ptr124);
}
void history(){
    FILE *fhistory=fopen("month.txt","r");
    //printing out the history of the user
    char ch[70]="";
    printf("\n\t\t-------HISTORY OF THE USER IS---------\n\n");
    while(fgets(ch,sizeof(ch),fhistory))
    printf("%s\n",ch);
    fclose(fhistory);
}