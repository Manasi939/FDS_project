#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<conio.h>
  int m=0;
  struct abc
  {         int numofd;
       char name[20];
      char gender[20];
      char vaccine_name[20];
      int age;
     char first_dose[20]; 
      char s_dose[20];
       char password[20];
       char username[20];
       char before_v[5];     //Covid infected before taking vaccination
       char after_v1[5];       //Covid infected after taking first vaccination
       char after_v2[5];       //Covid infected after taking second vaccination
      struct abc *next;       
  }*head,*temp;
   
 struct vaccine
  {
    char vac_name[20];
    int number;
  }c;
  int num=1,num1=0;
 FILE *fp,*slots;
 void display_doses()
 { 
   slots=fopen("nslot_dat.txt","r");
   printf("\n%-20s  %s\n","VACCINE NAME","QUANTITY");
  while(fread(&c,sizeof(struct vaccine),1,slots)==1)
  {
  
   printf("%-20s %d\n",c.vac_name,c.number);
  
  }
fclose(slots);
 }
 void update_doses()
 {
  
   slots=fopen("nslot_dat.txt","a+");
     if(fread(&c,sizeof(struct vaccine),1,slots)!=1)
     {
         printf("\nEnter no. of doses available for covaccine:\n");
         scanf("%d",&c.number);
       strcpy(c.vac_name,"covaccine");
          fwrite(&c,sizeof(struct vaccine),1,slots);
           //ftell(slots);
         printf("\nEnter no. of doses available for covishield:\n");
         scanf("%d",&c.number);
             fflush(stdin);
           strcpy(c.vac_name,"covishield");
           
          
           fwrite(&c,sizeof(struct vaccine),1,slots);
                   
         fclose(slots) ;
     }
     else{ 
        fclose(slots);
      display_doses();    fclose(slots);
        slots=fopen("nslot_dat.txt","r+");
      int ch; 
      printf("\n Do you want to update slots of:\n1)Covishield\n2)Covaccine\n3)EXIT");
      scanf("%d",&ch);
      if(ch==1)
      { 
        int sz=sizeof(struct vaccine);
       
         while(fread(&c,sizeof(struct vaccine),1,slots)==1)
         {
          
            if(strcmp(c.vac_name,"covishield")==0)
            {
          printf("\nEnter slots available of covishield:");
        scanf("%d",&c.number);
          strcpy(c.vac_name,"covishield");
            fseek(slots,-sz,1);
       fwrite(&c,sizeof(struct vaccine),1,slots);
                   break;
            }
           
         }
         fclose(slots);
      }
       else if(ch==2)
      { slots=fopen("nslot_dat.txt","r+");
        int sz=sizeof(struct vaccine);
        
         while(fread(&c,sizeof(struct vaccine),1,slots)==1)
         {
          if(strcmp(c.vac_name,"covaccine")==0)
          { printf("\nEnter slots available of covaccine:");
        scanf("%d",&c.number);
        strcpy(c.vac_name,"covaccine");
           fseek(slots,-sz,1);
       fwrite(&c,sizeof(struct vaccine),1,slots);
       break;
          }
         } fclose(slots);
      }
     }
     fclose(slots);
 }
 
 void search()
{ 
  int sz= sizeof(struct abc);

    int f=0;
    char nam[20];
     fp=fopen("nvac.txt","r");
    printf("\nEnter username: ");
    fflush(stdin);
    gets(nam);
    
     while(fread(temp,sz,1,fp)==1)
    {
  
              
        if(strcmp(nam,temp->username)==0){
            f=1; 
         printf("\n%-20s %-5s %-15s %-15s   %-15s  %-15s  %-20s %-20s  %-15s\n", "NAME","AGE","VACCINE","NUMOFDOSES","first_dose","s_dose","infected_before_v","infected_after_v","After_v2");   
         printf("%-20s %-5d %-15s %-15d   %-15s  %-15s  %-20s %-20s  %-15s\n", temp->name,temp->age,temp->vaccine_name,temp->numofd,temp->first_dose,temp->s_dose,temp->before_v,temp->after_v1,temp->after_v2);
 break;
        }
        
    }
    fclose(fp);
    if(f==0)
    {
        printf("\n User not found");
    }
}
  struct abc* admin()
  {
        temp=(struct abc *)malloc(sizeof(struct abc ));
       int flag=0;
      fp=fopen("nvac.txt","a+");
       int c;
      if(fp==NULL)
      {
        printf("\nCouldn't open file\n");
      }
     // printf("%d",sizeof(struct abc));
      int sz=sizeof(struct abc);
     // fseek(fp,0,SEEK_SET);
     // int z=fread(head,sizeof(head),1,fp);
    //  printf("\n%d z",z);
  if (fread(temp,sz,1,fp)!=1) 
 {
   printf("\nCREATE ADMIN:\n");
   printf("\nEnter name: ");
   fflush(stdin);
   gets(temp->name);
    
   printf("\nEnter age: ");
   scanf("%d",&temp->age);
  
   printf("\nEnter gender(male/female): ");
   fflush(stdin);
   gets(temp->gender);
   printf("\nEnter num of doses:(0/1/2):  ");
   scanf("%d",&temp->numofd);
     if(temp->numofd==0)
     {
         strcpy(temp->vaccine_name,"NULL");
         strcpy(temp->first_dose,"00/00/00");
         strcpy(temp->s_dose,"00/00/00");
        
         strcpy(temp->after_v1,"NULL");
         strcpy(temp->after_v2,"NULL");

     }
     else{
      printf("\nEnter name of vaccine: ");
       fflush(stdin);
       gets(temp->vaccine_name);
       if(temp->numofd==2)
       {
         printf("\nEnter date of fist vaccination: ");
         fflush(stdin);
         gets(temp->first_dose);
         printf("\nEnter date of second vaccination: ");
         fflush(stdin);
         gets(temp->s_dose);
       }
       else
       {

       printf("\nEnter date of fist vaccination: ");
         fflush(stdin);
         gets(temp->first_dose);
         strcpy(temp->s_dose,"00/00/00");
       }
     }
   printf("\nEnter username: ");
   fflush(stdin);
   gets(temp->username);
printf("\nEnter password ");
   fflush(stdin);
   gets(temp->password);
  printf("\nWere you infected by COVID-19 before taking vaccination:");
  fflush(stdin);
   gets(temp->before_v);
   if(temp->numofd==2)
   {
      printf("\nWere you infected by COVID-19 after taking fisrt vaccination:");
  fflush(stdin);
   gets(temp->after_v1);
   printf("\nWere you infected by COVID-19 after taking second vaccination:");
  fflush(stdin);
   gets(temp->after_v2);
   }
   else if(temp->numofd==1)
   {
      printf("\nWere you infected by COVID-19 after taking fisrt vaccination:");
  fflush(stdin);
   gets(temp->after_v1);
   strcpy(temp->after_v2,"NULL");
    } 
   fwrite(temp,sz,1,fp);
 fclose(fp);
    temp->next=NULL;
    head=temp;
 }
 else
{
  char user[20],pass[20];
  do{
    int choice,f=0;
    int found=0;
       flag++;
  printf("\nEnter username: ");
  fflush(stdin);
  gets(user);
  /*rewind(fp);
  printf("%d\n",ftell(fp));
  while(fread(head,sz,1,fp)==1)
    {printf("found");
        if(strcmp(user,head->username)==0){
            f=1;
             printf("found");
        }
        break;
    }*/
  if(strcmp(user,head->username)==0)
    {
        printf("\nEnter password: ");
          fflush(stdin);
        gets(pass);
       if(strcmp(pass,head->password)==0)
    { 
        printf("\n                                     ---------------------------------------------------------------------------------\n");
printf("                                                              WELCOME ADMIN");
printf("\n                                      ---------------------------------------------------------------------------------\n");
       do
       { found=1;
           
         printf("\n1)Display list\n2)Vaccination doses Status\n3)Search a person\n");
         scanf("%d",&choice);
         switch(choice)
         {
           case 1:
                {struct abc *ptr;
                  ptr=head; 
                    printf("\n%-20s %-5s %-15s %-15s   %-15s  %-15s  %-20s %-20s  %-15s\n", "NAME","AGE","VACCINE","NUMOFDOSES","first_dose","s_dose","infected_before_v","infected_after_v","After_v2");   
         
              while(ptr!=NULL)
                {
                
         
         printf("%-20s %-5d %-15s %-15d   %-15s  %-15s  %-20s %-20s  %-15s\n", ptr->name,ptr->age,ptr->vaccine_name,ptr->numofd,ptr->first_dose,ptr->s_dose,ptr->before_v,ptr->after_v1,ptr->after_v2);
 
                    ptr=ptr->next;
                  }
              break;
                }
          case 2:
              update_doses();
               break;
          case 3:
              search();
                break;
              
           
         }
       } while (choice!=0);
       if(found==1)   {break;}  
    }
    }
    else  
    {
        printf("\nPlease retry\n");
        
    }
  }while(flag!=3);
  fclose(fp);
  return head;
}

  }
  /*void bookslot(struct abc **p)
  { 
       struct abc *t= *p
     if(*(*(p)->numofd)==0)
     {
    printf("\nBOOK SLOT ON:\n");
         fflush(stdin);
    printf("\nSELECT VACCINATION 1)COVISHEILD\n2)COVACCINE\n");
           scanf(" %s",temp->vaccine_name);
    printf("\nnumber of dose:\n ");
            scanf("%d",&temp->numofd);
    printf("***SLOT BOOKING SUCCESSFULL*****");
     }
 
  }*/
 
  void log_in()
  {
      char uname[10];
      int found=0,ch;
      printf("\nEnter username\n");
      fflush(stdin);
       gets(uname);
   
   struct abc *p=head;
   
    
      while(p!=NULL)
      {
        if(strcmp(uname,p->username)==0  )
        {
            found=1;
            break;
        }
          p=p->next;
      }
      if(found==1)
      {   char v_name[20];
          char pw[10]; int chances=0;
          do
          { chances++;
           printf("\nEnter password\n");
             fflush(stdin);
            gets(pw);
          if(strcmp(pw,p->password)==0)
          {       
             chances=3;
                   do
                   {
                     printf("\n1)Display Info\n2)Book vaccination slot\n3)Display slots available\n4)Modify\n");
                     scanf("%d",&ch);
                         switch(ch)
                         {
                           case 1:
                           printf("\n******USER INFO******\n");
                             printf("NAME: %s\n",p->name);
                              printf("AGE: %d\n",p->age);
                             printf("vaccine name: %s\n",p->vaccine_name);
                             printf("NO OF DOSES: %d\n",p->numofd);
                              printf("Date of vaccination: First) %s Second) %s\n",p->first_dose,p->s_dose);
                              printf("\nCovid infected: 1)Before vaccination: %s  2)After first vaccination: %s  2)After second vaccination: %s\n",temp->before_v,temp->after_v1,temp->after_v2);
                              break;
                          case 2:
                               {  int t=0; int covs,covv,vc,sz=sizeof(struct abc),sz1=sizeof(struct vaccine);  
                               
                                                slots=fopen("nslot_dat.txt","r+");
                                             
                                           
                                               while(fread(&c,sizeof(struct vaccine),1,slots)==1)
                                                {
                                                      
                                                          t++;
                                                          if(t==1)
                                                          {
                                                            covv=c.number;
                                                          }
                                                  if(t==2)
                                                          {
                                                            covs=c.number;
                                                          }
      
                                                }
                                                fclose(fp) ;
                                  if(p->numofd==0)
                                           {
                                            
            
                                                t=0;
                                                if(covv!=0 || covs!=0)
                                                {      printf("\nSlots available\n")   ; 
                                                       display_doses() ;
                                                    
                                                     printf("\nSELECT VACCINATION 1)COVISHEILD\n2)COVACCINE(1/2)\n");
                                                     scanf("%d",&vc);
                                                     label:
                                                         if(vc==1)
                                                         {
                                                           if(covs!=0)
                                                           {
                                                              printf("\nBOOK SLOT ON:\n");
                                                               fflush(stdin);
                                                                   gets(p->first_dose);
                                                                    strcpy(p->vaccine_name,"covishield");
                                                                    covs--;
                                                                    t=1;
                                                           }
                                                           else
                                                           {
                                                              int ans;
                                                             printf("\nSlots for covaccine available..Do you want to continue with covaccine 0)NO 1)yes: ");
                                                            
                                                             scanf("%d",&ans);
                                                                 if(ans==0)
                                                                 {
                                                                   printf("\nYou need to wait till covishield slots are available\n");
                                                                 }
                                                                 else
                                                                 {
                                                                   vc=2;
                                                               
                                                                 }
                                                           }
                                                           
                                                         }
                                                     
                                                           if(vc==2)
                                                         {
                                                           if(covv!=0)
                                                           {
                                                              printf("\nBOOK SLOT ON:\n");
                                                               fflush(stdin);
                                                                   gets(p->first_dose);
                                                                   strcpy(p->vaccine_name,"covaccine");
                                                                   covv--;
                                                                   t=1;
                                                           }
                                                           else 
                                                           {int ans1;
                                                              printf("\nSlots for covishield available..Do you want to continue with covishield0)NO 1)yes \n");
                                                             
                                                             scanf("%s",&ans1);
                                                                 if(ans1==0)
                                                                 {
                                                                   printf("\nYou need to wait till covaccine slots are available\n");
                                                                 }
                                                                 else
                                                                 {
                                                                  vc=1;
                                                                  goto label;
                                                                 }    
                                                           }
                                                           
                                                     }
                                                     
                                                }
                                                if(covv==0 && covs==0)
                                                {
                                                  printf("\nSlots not available now\n")   ;  
                                                  printf("Kindly try after some time\n");
                                                      break;
                                                }
                                               
                                 }  
                                            else if(p->numofd==1)
                                                  {
                                                      if(strcmp(p->vaccine_name,"covishield")==0 && covs!=0)      
                                                     {
                                                           printf("\nBOOK SLOT ON:\n");
                                                               fflush(stdin);
                                                                   gets(p->s_dose);
                                                                  
                                                                   covs--;
                                                                   t=1;
                                                     }
                                                     else if(strcmp(p->vaccine_name,"covaccine")==0 && covv!=0)
                                                     {
                                                        printf("\nBOOK SLOT ON:\n");
                                                               fflush(stdin);
                                                                   gets(p->s_dose);
                                                                  
                                                                   covv--;
                                                                   t=1;
                                                     }
                                                     else  {printf("\nSlots not available now\n")   ;  
                                                  printf("Kindly try after some time\n");}

                                                  }
                                                  else{
                                                    printf("\nYou are fully vaccinated\n");
                                                    t=0;
                                                  }
                                            fclose(slots);
                                              fp=fopen("nvac.txt","r+");
                                                slots=fopen("nslot_dat.txt","r+");
                                                     if(t==1)   
                                                {
                                                
                                                while(fread(temp,sizeof(struct abc),1,fp)==1)
                                                         {
                                                              if(strcmp(temp->name,p->name)==0)
                                                              {
                                                                  
                                                           strcpy(temp->name,p->name);
                                                            strcpy(temp->gender,p->gender);
                                                             strcpy(temp->vaccine_name,p->vaccine_name);
                                                           
                                                             temp->age=p->age;
                                                             temp->numofd=(++p->numofd);
                                                              strcpy(temp->first_dose,p->first_dose);
                                                              if(p->numofd==2)
                                                              {
                                                              strcpy(temp->s_dose,p->s_dose);

                                                              }
                                                              else if(p->numofd==1)
                                                              {
                                                                strcpy(temp->s_dose,"00/00/00");
                                                              }
                                                               strcpy(temp->before_v,p->before_v);
                                                                strcpy(temp->after_v1,p->after_v1);
                                                                 strcpy(temp->after_v2,p->after_v2);
                                                              strcpy(temp->username,p->username);
                                                              strcpy(temp->password,p->password);
                                                              
                                                   
                                                        fseek(fp,-sz,1);
                                                         fwrite(temp,sizeof(struct abc),1,fp);
                                                               fclose(fp);
                                                              break;
                                                     }
        
                                                         }
                                                         int f=0;
                                                     /* if(fread(&c,sizeof(struct vaccine),1,slots)!=1)
                                                      {
                                                        f++;
                                                        if(f==1)
                                                        {
                                                           strcpy(c.vac_name,"covaccine");
                                                        fwrite(&c,sizeof(struct vaccine),1,slots);
                                                        }
                                                       if(f==2) 
                                                       {
                                                        strcpy(c.vac_name,"covishield");
           
          
                                                 fwrite(&c,sizeof(struct vaccine),1,slots);
                                                       }
                                                  
                                                     } */
                                                     slots=fopen("nslot_dat.txt","r+");
                  
                                         while(fread(&c,sizeof(struct vaccine),1,slots)==1)
         { 
           if(strcmp(p->vaccine_name,c.vac_name)==0)
            {     
              if(strcmp(p->vaccine_name,"covishield")==0)
              {
                   c.number=covs;
                    strcpy(c.vac_name,"covishield");
                    fseek(slots,-sz1,1);
                   fwrite(&c,sizeof(struct vaccine),1,slots);
                   fclose(slots);
                   break;
              }
              else 
              {
                c.number=covv;
                strcpy(c.vac_name,"covaccine");
                fseek(slots,-sz1,1);
                   fwrite(&c,sizeof(struct vaccine),1,slots);
                    fclose(slots);
                   break;
              }
         
              
                   
            }

      }

           
      
                                                      }
                                                    
                                                    
                                                
                                            fclose(slots);
                                            fclose(fp);    
                                             printf("\n***SLOT BOOKING SUCCESSFULL*****\n");

                         }                
  
                            break;
                               case 3:
                                display_doses() ;
                                   break;
                                 case 4:
                                 {
                                   int sz=sizeof(struct abc);      int f=0;
                                        char nam[20];
                                       fp=fopen("nvac.txt","r+");          
                                       while(fread(temp,sizeof(struct abc),1,fp)==1)
                                                         {
                                                              if(strcmp(temp->name,p->name)==0)
                                                              {
                                                                printf("\nEnter name: ");
                                                                fflush(stdin);
                                                                gets(p->name);
                                                                 strcpy(temp->name,p->name);
                                                                  printf("\nEnter gender: ");
                                                                fflush(stdin);
                                                                gets(p->gender);
                                                                 
                                                            strcpy(temp->gender,p->gender);
                                                           
                                                               
                                                         printf("\nEnter age: ");
                                                           scanf("%d",&p->age);
                                                             temp->age=p->age;
                                                             printf("\nEnter num of doses:(0/1/2):  ");
                                                              scanf("%d",&p->numofd);
                                                             temp->numofd=p->numofd;
                                                         if(temp->numofd==0)
                                                              {
                                                     strcpy(temp->vaccine_name,"NULL");
                                                     strcpy(temp->first_dose,"00/00/00");
                                                        strcpy(temp->s_dose,"00/00/00");
                                                         strcpy(p->vaccine_name,"NULL");
                                                     strcpy(p->first_dose,"00/00/00");
                                                        strcpy(p->s_dose,"00/00/00");
                                                        printf("\nWhere you infected with covid-19 earlier? \n");
                                                        gets(p->before_v);
                                                         strcpy(temp->before_v,p->before_v);
                                                        strcpy(p->after_v1,"NULL");
                                                          strcpy(temp->after_v1,"NULL");
                                                          strcpy(p->after_v2,"NULL");
                                                          strcpy(temp->after_v2,"NULL");
                                                                   }
                                                           else{
                                                   printf("\nEnter name of vaccine: ");
                                                                 fflush(stdin);
                                                       gets(p->vaccine_name);
                                                         strcpy(temp->vaccine_name,p->vaccine_name);
                                             if(p->numofd==2)
                              {
                 printf("\nEnter date of fist vaccination: ");
                   fflush(stdin);
                  gets(p->first_dose);
                     strcpy(temp->first_dose,p->first_dose);
         printf("\nEnter date of second vaccination: ");
         fflush(stdin);
         gets(p->s_dose);
            strcpy(temp->s_dose,p->s_dose);
              printf("\nWhere you infected with covid-19 before vaccination? \n");
                          gets(p->before_v);
                     strcpy(temp->before_v,p->before_v);
                        printf("\nWhere you infected with covid-19 after first vaccination? \n");
                          gets(p->after_v1);
                     strcpy(temp->after_v1,p->after_v1);
                        printf("\nWhere you infected with covid-19 after second vaccination? \n");
                          gets(p->after_v2);
                     strcpy(temp->after_v2,p->after_v2);
                                                        
       }
       else if(p->numofd==1)
       {

       printf("\nEnter date of fist vaccination: ");
         fflush(stdin);
         gets(p->first_dose);
           strcpy(temp->first_dose,p->first_dose);
         strcpy(temp->s_dose,"00/00/00");
          strcpy(p->s_dose,temp->s_dose);
                printf("\nWhere you infected with covid-19 before vaccination? \n");
                          gets(p->before_v);
                     strcpy(temp->before_v,p->before_v);
          printf("\nWhere you infected with covid-19 after first vaccination? \n");
                          gets(p->after_v1);
                     strcpy(temp->after_v1,p->after_v1);
                     strcpy(temp->after_v2,"NULL");
                     strcpy(p->after_v2,temp->after_v2);

       }
       
     }
   printf("\nEnter username: ");
   fflush(stdin);
   gets(p->username);
   strcpy(temp->username,p->username);
printf("\nEnter password ");
   fflush(stdin);
   gets(p->password);
        strcpy(temp->password,p->password);                                                     
                                                             
                                                              
                                                             

                                                   
                                                        fseek(fp,-sz,1);
                                                         fwrite(temp,sizeof(struct abc),1,fp);
                                                               fclose(fp);
                                                              break;
                                                     }
        
                                                         }
                                                       
                                                      }
                                 
                                         break;

                         }
                   } while (ch!=0);
                   



             
          }
          else {
            if(chances<3) { printf("\n*****WRONG PASSWORD PLEASE RETRY*******\n");}
            else printf("*****YOU HAVE ENTERED WRONG PASSWORD 3 TIMES LOGIN AGAIN LATER*******\n");
              
          }
          }while(chances!=3);

      }
      else printf("\n***USER DOESN'T EXIST*****\n");
      
  }
void create()
{

  num++;

     fp=fopen("nvac.txt","a+");
     int sz= sizeof(struct abc);
    temp =(struct abc *)malloc(sizeof(struct abc));
    struct abc *p=head;;
     if(num==2)
 {
   head->next=temp;
  
 }
 for(int i=2;i<num;i++)
 {
   p=p->next;
 }
 p->next=temp;

      printf("\nCreate a new account by entering all th below information\n") ;
     
   printf("\nEnter name: ");
   fflush(stdin);
   gets(temp->name);
   printf("\nEnter age: ");
   scanf("%d",&temp->age);
   
   printf("\nEnter gender(male/female): ");
   fflush(stdin);
   gets(temp->gender);
   printf("\nEnter num of doses:(0/1/2):  ");
   scanf("%d",&temp->numofd);
     if(temp->numofd==0)
     {
         strcpy(temp->vaccine_name,"NULL");
         strcpy(temp->first_dose,"00/00/00");
         strcpy(temp->s_dose,"00/00/00");
            printf("\nWhere you infected with covid-19 before vaccination? \n");
            fflush(stdin);
                          gets(temp->before_v);
          strcpy(temp->after_v2,"NULL");
           strcpy(temp->after_v1,"NULL");

     }
     else{
      printf("\nEnter name of vaccine: ");
       fflush(stdin);
       gets(temp->vaccine_name);
       if(temp->numofd==2)
       {
         printf("\nEnter date of fist vaccination: ");
         fflush(stdin);
         gets(temp->first_dose);
         printf("\nEnter date of second vaccination: ");
         fflush(stdin);
         gets(temp->s_dose);
          printf("\nWhere you infected with covid-19 before vaccination? \n");
                          gets(temp->before_v);
                     
                        printf("\nWhere you infected with covid-19 after first vaccination? \n");
                          gets(temp->after_v1);
                
                        printf("\nWhere you infected with covid-19 after second vaccination? \n");
                          gets(temp->after_v2);
                     
       }
       else if(temp->numofd==1)
       {

       printf("\nEnter date of fist vaccination: ");
         fflush(stdin);
         gets(temp->first_dose);
         strcpy(temp->s_dose,"00/00/00");
          printf("\nWhere you infected with covid-19 before vaccination? \n");
                          gets(temp->before_v);
                     
                        printf("\nWhere you infected with covid-19 after first vaccination? \n");
                          gets(temp->after_v1);
                          strcpy(temp->after_v2,"NULL");
       }
       
     }
   printf("\nEnter username: ");
   fflush(stdin);
   gets(temp->username);
printf("\nEnter password ");
   fflush(stdin);
   gets(temp->password);
   fwrite(temp,sz,1,fp);
 fclose(fp);

   temp->next=NULL;
    
   
}
void stat()
{
   struct abc *ptr;
     ptr=head; 
 printf("\n%-20s %-5s %-15s %-15s   %-15s  %-15s  %-20s %-20s  %-15s\n", "NAME","AGE","VACCINE","NUMOFDOSES","first_dose","s_dose","infected_before_v","infected_after_v","After_v2");   
   int num_1=0,num_2=0,num_3=0,total=0,num_covv=0,num_covs=0;      
 while(ptr!=NULL)
      {        total++;
          if(strcmp(ptr->before_v,"yes")==0 ) 
          {
              num_1++;
          }  
          if(strcmp(ptr->after_v1,"yes")==0 ) 
          {
              num_2++;
          }  
          if(strcmp(ptr->after_v2,"yes")==0 ) 
          {
              num_3++;
          }  
            if(strcmp(ptr->vaccine_name,"covishield")==0 ) 
          {
              num_covs++;
          } 
            if(strcmp(ptr->vaccine_name,"covaccine")==0 ) 
          {
              num_covv++;
          } 
         
       
                    ptr=ptr->next;
  } 
  float percent_1 =(((float)num_1)/(total))*100;
   float percent_2 =(((float)num_2)/(total))*100;
 float percent_3 =(((float)num_3)/(total))*100;
 
int max= ((num_1>=num_2 && num_1>=num_3)?(num_1):((num_2>=num_3 && num_2>=num_1)?num_2:(num_3>=num_2 && num_3>=num_1?num_3:num_1)));


int n=max;
printf("\n---------------------------------------------------------------------------------\n");
printf("                       Graph to show effectivesness of vaccine\n");
printf("\n---------------------------------------------------------------------------------\n");
printf("\n   %.2f\t%.2f\t%.2f\n\n",percent_1,percent_2,percent_3);
for(int i=max;i>=1;i--)
{printf("|\t");
    if(i<=num_1)
    {
        printf("*****");
    }
    printf("\t");
    if(i<=num_2)
    {
       printf("*****"); 
    }
    printf("\t");
      if(i<=num_3)
    {
       printf("*****"); 
    }
    printf("\n");

}
printf("----------------------------------------------------------------\n");
 printf("   Before\tAfter\tAfter\n");
 printf("   vac\t\tvac_1\t_vac2\n");
 printf("\n---------------------------------------------------------------------------------\n");
printf("                       Number of people taking covaccine or covishield\n");
printf("\n---------------------------------------------------------------------------------\n");
max=(num_covv>=num_covs?num_covv:num_covs);
printf("\n\t%d\t%d\n\n",num_covv,num_covs);
for(int i=max;i>=1;i--)
{   printf("|\t");
    if(i<=num_covv)
    {
        printf("*****");
    }
    printf("\t");
    if(i<=num_covs)
    {
       printf("*****"); 
    }
    printf("\n");


}
printf("----------------------------------------------------------------\n");
 printf("   Covaccine\tcovishield\n");


}
int main()
{
  char str[20];
 
  int flag=0;
   fp=fopen("nvac.txt","r");
       int c;
     
      int sz=sizeof(struct abc);
    
 temp = (struct abc*)malloc(sizeof(struct abc));
    head; // points to the first node of the linked list in the file
    struct abc* last; // points to the last node of the linked list in the file
    last = head = NULL;
    
    if (fp == NULL)
    {
        printf("\nCouldn't Open File'\n");
        exit (1);
    }
  
    while(fread(temp, sizeof(struct abc), 1, fp))
    { 
       
        if(head==NULL)
        {
            head = last = (struct abc *)malloc(sizeof(struct abc));
            flag=1;
        }
        else
        {num++;
            last->next = (struct abc *)malloc(sizeof(struct abc));
            last = last->next;
        }
        last->age = temp->age;
        strcpy(last->name, temp->name);
        strcpy(last->gender, temp->gender);
        strcpy(last->vaccine_name, temp->vaccine_name);
        last->numofd = temp->numofd;
        strcpy(last->first_dose, temp->first_dose);
         strcpy(last->s_dose, temp->s_dose);
          strcpy(last->username, temp->username);
           strcpy(last->password, temp->password);
           strcpy(last->before_v, temp->before_v);
           strcpy(last->after_v1, temp->after_v1);
           strcpy(last->after_v2, temp->after_v2);
        last->next = NULL;
        
    } 
   
    printf("\n                                     ---------------------------------------------------------------------------------\n");
printf("                                                              WELCOME TO VACCINATION REGISTRATION SYSTEM\n");
printf("\n                                      ---------------------------------------------------------------------------------\n");
if(flag==0)
{
       head=(struct abc *)malloc(sizeof(struct abc ));
}
    fclose(fp);
    //  int c;
    
printf(" SELECT AN OPTION BELOW\n");

  do
  {
     printf("\n1)ADMIN LOGIN\n2)CREATE NEW ACCOUNT\n3)USER LOGIN\n4)VIEW STATISTICS ON EFFECTIVENESS OF VACCINATION\n");
     scanf("%d",&c);
      switch(c)
      {
          case 1:
            {
                 head=admin();
                 break;
            }
          case 2:
          {  
           create();
            
               break;
          }
          case 3:
           log_in();
           break;
          case 4:
             stat();
              break;
             
      }
  } while (c!=0);
 
   

  
}