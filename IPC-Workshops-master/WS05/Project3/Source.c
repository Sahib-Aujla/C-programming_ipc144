#include <stdio.h>
#include <string.h>

#define STRING_LEN  20
 #define SONG_BANK 5
 #define SONGS 3

 struct Song
{
     char title[STRING_LEN + 1];
     int seconds;
 };

 void calculateTimeFormat(int tSeconds, int* minutes, int* seconds);
 void createPlaylist(struct Song playlist[], const struct Song bank[], int offset, int seed, int order[]);
 void playSongs(const struct Song songs[], const int order[], int crossFade);

 int main(void)
 {

     struct Song songBank[SONG_BANK] = { {"Stayin' Alive", 249},
                                         {"Material Girl", 285},
                                         {"Dancing Queen", 232},
                                         {"Lean on Me", 257},
                                         {"Hello", 326} },
		
		     playlist[SONGS] = { {0} };
	
	     int shuffled[SONGS] = { 0 }, config1 = 2, config2 = 25, config3 = 5;
	
	
	     createPlaylist(playlist, songBank, config1, config2, shuffled);
	     playSongs(playlist, shuffled, config3);
	
	     return 0;
	 }

 void calculateTimeFormat(const int tSeconds, int* minutes, int* seconds)
 {
 * minutes = tSeconds / 60;
 * seconds = tSeconds % 60;
 }

 void createPlaylist(struct Song playlist[], const struct Song bank[], int offset, int seed, int order[])
 {
     int i = 0, idx = seed % SONGS;
     int test;

     do
     {
         test = idx + 2 < SONGS ? idx + 2 : idx + 2 - SONGS;
         order[i] = idx + 2 < SONGS ? idx + 2 : idx + 2 - SONGS;

         if (offset < 1 || offset > SONG_BANK)
         {
             offset = SONG_BANK;
	         }
	
	         playlist[i++] = bank[--offset];
	         test = idx + 1 < SONGS ? idx + 1 : idx + 1 - SONGS;
	         idx = idx + 1 < SONGS ? idx + 1 : idx + 1 - SONGS;
	
	     } while (i < SONGS);
	 }

 void playSongs(const struct Song songs[], const int order[], int crossFade)
 {
     int i, min, sec, total = 0;

     for (i = 0; i < SONGS; i++)
     {
         total += songs[order[i]].seconds;

         if (crossFade && (i + 1 < SONGS))
         {
             total -= crossFade;
             calculateTimeFormat(songs[order[i]].seconds - crossFade, &min, &sec);
         }
         else
         {
             calculateTimeFormat(songs[order[i]].seconds, &min, &sec);
         }
         printf("%-20s %2d:%02d\n", songs[order[i]].title, min, sec);
     }

     calculateTimeFormat(total, &min, &sec);
     printf("Total playing time: %3d:%02d\n", min, sec);
	 }