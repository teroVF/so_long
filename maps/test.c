#include <mlx.h>

int main(int argc, char const *argv[])
{
    void    *mlx;
    void    *window;
    void    *img_ptr;
    void    *img_ptr2;
    void    *img_ptr3;
    int     height;
    int     width;
	height = 70;
	width = 70;


    mlx = mlx_init();
    window = mlx_new_window(mlx, 300, 300, "primeira");
    img_ptr = mlx_xpm_file_to_image(mlx, "./textures/unnamed.xpm", &height, &width);
    img_ptr2 = mlx_xpm_file_to_image(mlx, "./textures/Singel_tree_&_vertical_row.xpm", &height, &width);
    img_ptr3 = mlx_xpm_file_to_image(mlx, "./textures/pikachu.xpm", &height, &width);
    mlx_put_image_to_window(mlx, window, img_ptr, 0, 0);
    mlx_put_image_to_window(mlx, window, img_ptr2, 0, 70);
    mlx_put_image_to_window(mlx, window, img_ptr2, 0, 140);
    mlx_put_image_to_window(mlx, window, img_ptr3, 0, 210);
    mlx_loop(mlx);
}
