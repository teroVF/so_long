#include "mlx.h"
#include <fcntl.h>
#include "libft/libft.h"

void	if_is_rectaculo(char *pwd)
{
	int		i;
	i = open(pwd, O_RDONLY);
	while (1)
	{
		get_next_line(i);
		if_is_rectangule()
	}
		
}

int main(int argc, char const *argv[])
{
	void *mlx;
	void *window;

	if (argc < 2)
		return (1);
	mlx = mlx_init();
	validate_map();
	window = mlx_new_window();
	return 0;
}
