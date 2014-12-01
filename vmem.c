#define PAGE_SIZE		4*1000/8 //4kB <=> 500 octets
#define SECOND_LVL_TT_COUN 	512 // 2⁸ avec 8 = 19-12+1 (taille de Second Level tabe index dans l'adresse logique)
#define SECOND_LVL_TT_SIZE	512*PAGE_SIZE // => 256 ko : Nombre d'entrées des tables de pages de niveau 2 multiplié par la taille d'une page
#define FIRST_LVL_TT_COUN	4096 // 2¹² avec 12 = 31-20+1 (taille de First Level tabe index dans l'adresse logique)
#define FIRST_LVL_TT_SIZE	4096*SECOND_LVL_TT_SIZE // => 1 048 576 ko : Nombre d'entrées des tables de pages de niveau 1 multiplié par la taille d'une table de pages de niveau 2
#define TOTAL_TT_SIZE		//4096*FIRST_LVL_TT_SIZE <== Ca fait beaucoup... Environ 4 To... 


