#include <unistd.h>

int	main(int c,char **args){
	int	i;
	int	j;
	int	used[255];

	i = 1;
	j = 0;
	while (j < 255){
		used[j++] = 0;
	}
	j = 0;
	if(c == 3)
		while(i < 3){
			while(args[i][j]){
				if (!used[args[i][j]]){
					write(1, &args[i][j], 1);
					used[args[i][j]] = 1;
				}
				j++;
			}
			j = 0;
			i++;
		}
	write(1, "\n", 1);
	return (0);
}
