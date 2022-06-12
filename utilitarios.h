#ifndef UTILITARIOS_H_INCLUDED
#define UTILITARIOS_H_INCLUDED

#define MIN(x,y) ( x<y ? x:y)

typedef int (*Cmp)(const void *, const void *);
typedef int (*Acum) (void *, const void *);
typedef void (*Mostrar) (const void *);

typedef enum
{
    verdadero = 1,
    falso =0
}booleano;

#endif // UTILITARIOS_H_INCLUDED
