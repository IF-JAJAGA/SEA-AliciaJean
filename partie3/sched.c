#include "sched.h"


void init_ctx(struct ctx_s* ctx, func_t f, unsigned int stack_size)
{
	ctx->sp = phyAlloc_alloc ( stack_size );
	ctx->f_ctx = f;
	ctx->lr = *f;
}

void __attribute__ ((naked)) switch_to (struct ctx_s* ctx){
	//Sauvegarder les variables locales en pushant tous les registres
	__asm("push {R0-R12}");	

	//Sauvegarder le contexte courant	
	__asm ("mov %0, sp" : "=r"(current_ctx->sp));
	__asm ("mov %0, lr" : "=r"(current_ctx->lr));
	
	//Changer de contexte courant
	current_ctx=ctx;

	//Restaurer le nouveau contexte
	__asm ("mov sp , %0" : : "r"(current_ctx->sp));
	__asm ("mov lr , %0" : : "r"(current_ctx->lr));
	
	//Restituer toutes les variables globales contenues dans les registres
	__asm("pop {R0-R12}");
	
	//Sauter à l'adresse de retour du contexte restauré
	__asm ("bx lr" );

}
