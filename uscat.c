#include <stdio.h>
#include <stdlib.h>

#define NMAX 100000
#define VMAX 1000000000

int main()
{
	unsigned n, *a, vmax, i, x, st, dr, mij, tc, c, r;

	FILE *fin = fopen("uscat.in", "r");

	if (!fin) { printf("Eroare uscat.in\n"); return 1; }

	fscanf(fin, "%u", &n);

	if (n < 1 || n > NMAX) { printf("Eroare valoare n\n"); return 2; }

	a = (unsigned*)malloc(n*sizeof(unsigned));

	if (!a) { printf("Eroare alocare memorie *a\n"); return 4; }

	for (vmax = i = 0; i < n; i++) {
		fscanf(fin, "%u", &a[i]);

		if (a[i] < 1 || a[i] > VMAX) { printf("Eroare valoare a[i]\n"); return 3; }

		if (a[i] > vmax) vmax = a[i];
	}	

	fscanf(fin, "%u", &x);

	fclose(fin);

	FILE *fout = fopen("uscat.out", "w");

	if (x == 1) fprintf(fout, "%u", vmax);
	else {
		st = 0, dr = vmax;

		while (dr-st > 1) {
			mij = st + (dr-st)/2;
			
			for (tc = i = 0; i < n && tc <= mij; i++) {
				if (a[i] > mij) {
					c = (a[i]-mij)/(x-1);

					r = (a[i]-mij)%(x-1);

					tc = r == 0 ? tc+c : tc+c+1;
				}
			}

			if (tc <= mij) dr = mij;
			else st = mij;
		}

		fprintf(fout, "%u", dr);
	}

	fclose(fout);

	free(a);

	return 0;
}

// scor 100
