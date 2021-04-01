#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

#define alloc(t) (t*) malloc(sizeof(t))

/* define a linked list sCell */
typedef struct sCell
{
	double num;
	struct sCell *next;
} tCell;

/* Add element to the beginning of the list */
tCell *InitCell(double elt, tCell *succ)
{
	tCell *h;

	h = malloc(sizeof(tCell));
	if (h == NULL)
		return (NULL);

	h->num = elt;
	h->next = succ;
	succ = h;

	return (succ);
}

/* Display the linked list */
void PrintList(tCell *first)
{
	if (first != NULL)
	{
		PrintList(first->next);
		printf("%.7f\n", first->num);
	}
}

/* Heron Function*/
tCell *Heron(double p, double a)
{
	tCell *list;
	double approx;

	list = NULL;
	approx = a;

	list = InitCell(approx, list);
	approx = (approx + (p / approx)) / 2;

	while (1 / pow(10, 7) < fabs(approx - sqrt(p)))
	{
		approx = (approx + (p / approx)) / 2.0;
		list = InitCell(approx, list);
	}

	return (list);
}

int main(void)
{
	double p, u0;
	tCell *first=NULL;

	printf("U0 = ");
	scanf("%lf", &u0);
	printf("p = ");
	scanf("%lf", &p);

	printf("the Heron sequence until having convergence with an error equal to 10^(-7) is: \n");
	first = Heron(p, u0);
	PrintList(first);
	printf("\n");

	return (0);
}
