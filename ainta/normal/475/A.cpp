#include<stdio.h>
int n;
char p[6][28] = {
	"+------------------------+",
	"|#.#.#.#.#.#.#.#.#.#.#.|D|)",
	"|#.#.#.#.#.#.#.#.#.#.#.|.|",
	"|#.......................|",
	"|#.#.#.#.#.#.#.#.#.#.#.|.|)",
	"+------------------------+"
};
int main()
{
	int i, n, j;
	scanf("%d", &n);
	for (i = 0; i < 28; i++){
		for (j = 0; j < 6; j++){
			if (p[j][i] == '#' && n > 0){
				n--;
				p[j][i] = 'O';
			}
		}
	}
	for (i = 0; i < 6; i++){
		printf("%s\n", p[i]);
	}
	return 0;
}