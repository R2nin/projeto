#include <allegro.h>

float bola_x,bola_y,vel_b,velV;
int dirH,dirV;
int p1_x,p2_x;
int lista[100],l;

void init();
void deinit();

void desenha();
void verifica();
int eventos();
int direcaoBola();
void comeca();

BITMAP *buffer;

int main() {
	init();
	
    buffer = create_bitmap(800,400);
	
	comeca();
	
	desenha();
	
	while (!key[KEY_ESC])
    {
          verifica();
          if(eventos()==2)
          {
                          while(!key[KEY_J] && !key[KEY_ESC])
                          {
                                           
                          }
                          comeca();
                          desenha();
          }
          desenha();
	}
	
	
	
	deinit();
	return 0;
}
END_OF_MAIN();

void comeca()
{
     p1_x=200;
	 p2_x=200;
	 bola_x=200;
	 bola_y=400;
	 vel_b=0.8;
	 dirH=1;
	 dirV=1;
	 velV=0.5;
	 l=0;
}

int eventos()
{
     for(int i=0;i<l;i++)
     {
             switch(lista[i])
             {
                             case 1:
                                  if(p1_x>=40) p1_x--;
                                  break;
                             case 2:
                                  if(p1_x<=360) p1_x++;
                                  break;
                             case 3:
                                  if(p2_x>=40) p2_x--;
                                  break;
                             case 4:
                                  if(p2_x<=360) p2_x++;
                                  break;
             }
     }
     l=0;
     if(direcaoBola()==2)
     {
                         return 2;
     }
     desenha();
     return 1;
}

int direcaoBola()
{
     if(dirH==1)
     {
                if(dirV==1) // vertical
                {
                            if(bola_x>13)
                            {
                                        bola_x-=velV;
                            }
                            else
                            {
                                dirV=2;
                                bola_x+=velV;
                            }
                }
                else
                {
                    if(bola_x<387)
                    {
                                  bola_x+=velV;
                    }
                    else
                    {
                        dirV=1;
                        bola_x-=velV;
                    }
                }
                
                if(bola_y<750) // horizontal
                {
                              bola_y+=vel_b;
                }
                else // horizontal
                {
                    if(bola_x>=p2_x-30 && bola_x<=p2_x+30 && bola_y<760) // verificacao de contato
                    {
                                       vel_b+=0.1;
                                       if(bola_x<=p2_x-23)
                                       {
                                                          dirH=2;
                                                          bola_y-=vel_b;
                                                          velV=1.5;
                                                          dirV=1;
                                       }
                                       else if(bola_x<=p2_x-10)
                                       {
                                            dirH=2;
                                            bola_y-=vel_b;
                                            velV=1;
                                            dirV=1;
                                       }
                                       else if(bola_x<=p2_x)
                                       {
                                            dirH=2;
                                            bola_y-=vel_b;
                                            velV=0.7;
                                            dirV=1;
                                       }
                                       else if(bola_x<p2_x+23)
                                       {
                                            dirH=2;
                                            bola_y-=vel_b;
                                            velV=1;
                                            dirV=2;
                                       }
                                       else
                                       {
                                           dirH=2;
                                           bola_y-=vel_b;
                                           velV=1.5;
                                           dirV=2;
                                       }
                    }
                    else if(bola_y>=760)
                    {
                         return 2;
                    }
                    else
                    {
                        bola_y+=vel_b;
                    }
                }
     }
     else
     {
         if(dirV==1) // vertical
         {
                     if(bola_x>13)
                     {
                                 bola_x-=velV;
                     }
                     else
                     {
                         dirV=2;
                         bola_x+=velV;
                     }
         }
         else
         {
             if(bola_x<387)
             {
                           bola_x+=velV;
             }
             else
             {
                 dirV=1;
                 bola_x-=velV;
             }
         }
         
         if(bola_y>50)
         {
                      bola_y-=vel_b;
         }
         else
         {
             if(bola_x>=p1_x-30 && bola_x<=p1_x+30 && bola_y>40)
             {
                                vel_b+=0.1;
                                if(bola_x<=p1_x-23)
                                {
                                                   velV=1.5;
                                                   dirV=1;
                                                   bola_y+=vel_b;
                                                   dirH=1;
                                }
                                if(bola_x<=p1_x-10)
                                {
                                                   velV=1.5;
                                                   dirV=1;
                                                   bola_y+=vel_b;
                                                   dirH=1;
                                }
                                else if(bola_x<=p1_x)
                                {
                                     velV=0.7;
                                     dirV=1;
                                     bola_y+=vel_b;
                                     dirH=1;
                                }
                                else if(bola_x<p1_x+23)
                                {
                                     velV=1;
                                     dirV=2;
                                     bola_y+=vel_b;
                                     dirH=1;
                                }
                                else
                                {
                                    velV=1.5;
                                    dirV=2;
                                    bola_y+=vel_b;
                                    dirH=1;
                                }
             }
             else if(bola_y<=40)
             {
                  return 2;
             }
             else
             {
                 bola_y--;
             }
         }
     }
}

void verifica()
{
     if(key[KEY_W])
     {
                   lista[l]=1;
                   l++;
     }
     else if(key[KEY_S])
     {
          lista[l]=2;
          l++;
     }
     if(key[KEY_UP])
     {
                    lista[l]=3;
                    l++;
     }
     else if(key[KEY_DOWN])
     {
          lista[l]=4;
          l++;
     }
}

void desenha()
{
     clear(buffer);
     
     // bola
     rectfill(buffer,(int)bola_y-5,(int)bola_x-5,(int)bola_y+5,(int)bola_x+5,makecol(255,255,255));
     
     // players
     rectfill(buffer,40,p1_x-30,50,p1_x+30,makecol(255,255,255));   // p1
     rectfill(buffer,750,p2_x-30,760,p2_x+30,makecol(255,255,255)); // p2
     
     // enquadramento
     rectfill(buffer,7,7,793,10,makecol(255,255,255));
     rectfill(buffer,7,390,793,393,makecol(255,255,255));
     rectfill(buffer,7,7,10,393,makecol(255,255,255));
     rectfill(buffer,790,7,793,393,makecol(255,255,255));
     
     blit(buffer,screen,0,0,0,0,800,400);
}

void init() {
	int depth, res;
	allegro_init();
	depth = desktop_color_depth();
	if (depth == 0) depth = 32;
	set_color_depth(depth);
    install_timer();
	install_keyboard();
	install_mouse();
	res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 400, 0, 0);
	if (res != 0) {
		allegro_message(allegro_error);
		exit(-1);
	}
}

void deinit() {
	clear_keybuf();
}
