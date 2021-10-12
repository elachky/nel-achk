#include <unistd.h>

int	exist(char c, char *used){
	int i;

	i = -1;
	while(used[++i])
		if (c == used[i])
			return (1);
	return (0);
}

int	main(int c,char **args){
	int	i;
	int	j;
	int	k;
	char	used[30];

	i = 1;
	k = 0;
	j = 0;
	if(c == 3)
		while(i < 3){
			while(args[i][j]){
				if (exist(args[i][j], used) == 0){
					write(1, &args[i][j], 1);
					used[k++] = args[i][j];
				}
				j++;
			}
			j = 0;
			i++;
		}
	write(1, "\n", 1);
	return (0);
}
