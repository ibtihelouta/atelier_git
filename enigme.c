#include "enigme.h"


enigme generer(){
    enigme e;
    int solution,ajout;
    int i;

    int coeffQ[4];
    


    srand( time( NULL ) );
    coeffQ[0]=rand() % 20;
    coeffQ[1]=coeffQ[0]+4;
    coeffQ[2]=coeffQ[1]-20;
    coeffQ[3]=coeffQ[0]+coeffQ[2];



	sprintf(e.question,"(%d + %d)* %d - %d =?",coeffQ[0],coeffQ[1],coeffQ[2],coeffQ[3]);
    /*
    exemple:
    (13 + 17)* -3 - 10 =?
    */
    
    
    solution=(coeffQ[0]+coeffQ[1])*coeffQ[2]-coeffQ[3];//calculer la solution
    
    
  

    srand( time( NULL ) );
    e.solution =1 + rand() % 3;
    if (e.solution==1)                 
    {
        sprintf(e.rep1,"%d",solution);
        srand( time( NULL ) );
        ajout =1+rand() % 15;
        sprintf(e.rep2,"%d",solution+ajout);
        srand( time( NULL ) );
        ajout =(rand() % 15)-20;
        sprintf(e.rep3,"%d",solution+ajout);
    }
    if (e.solution==2)
    {
        sprintf(e.rep2,"%d",solution);
        srand( time( NULL ) );
        ajout =1 + rand() % 15;
        sprintf(e.rep1,"%d",solution+ajout);
        srand( time( NULL ) );
        ajout =(rand() % 15)-20;
        sprintf(e.rep3,"%d",solution+ajout);
    }
    if (e.solution==3)
    {
        sprintf(e.rep3,"%d",solution);
        srand( time( NULL ) );
        ajout =1+rand() % 15;
        sprintf(e.rep1,"%d",solution+ajout);
        srand( time( NULL ) );
        ajout =(rand() % 15)-20;
        sprintf(e.rep2,"%d",solution+ajout);
    }
    return e;
    
    

}
void afficherEnigme(enigme *e, SDL_Surface * screen){
    

SDL_Surface *texte,*R1,*R2,*R3,*back,*bouton;
SDL_Rect posQ,pos1,pos2,pos3,posbouton1,posbouton2,posbouton3;
SDL_Color couleurNoire = {0, 0, 0};
TTF_Font *police = NULL;


bouton=IMG_Load("bouton.png");
back=IMG_Load("background.png");


TTF_Init();
    
   
police = TTF_OpenFont("arial.ttf", 95);




//mettre le chaine caractere des images 

    texte = TTF_RenderText_Blended(police, e->question, couleurNoire);
    R1 = TTF_RenderText_Blended(police, e->rep1, couleurNoire);
    R2 = TTF_RenderText_Blended(police, e->rep2, couleurNoire);
    R3 = TTF_RenderText_Blended(police, e->rep3, couleurNoire);



    posQ.x=50;
    posQ.y=50;
    pos1.x=80;
    pos1.y=300;
    posbouton1.x=30;
    posbouton1.y=300;
    pos2.x=430;
    pos2.y=300;
    posbouton2.x=380;
    posbouton2.y=300;
    pos3.x=720;
    pos3.y=300;
    posbouton3.x=680;
    posbouton3.y=300;



    SDL_BlitSurface(back, NULL, screen, NULL); 
    SDL_BlitSurface(texte, NULL, screen, &posQ); 
    SDL_BlitSurface(bouton,NULL,screen,&posbouton1);
    SDL_BlitSurface(bouton,NULL,screen,&posbouton2);
    SDL_BlitSurface(bouton,NULL,screen,&posbouton3);
    SDL_BlitSurface(R1, NULL, screen, &pos1); 
    SDL_BlitSurface(R2, NULL, screen, &pos2); 
    SDL_BlitSurface(R3, NULL, screen, &pos3); 
}
