#ifndef IMAGES_BONUS_H
# define IMAGES_BONUS_H

# define TREE_TILE "./textures/tree.xpm"
# define FLOOR_TILE "./textures/floor.xpm"
# define PLAYER "./textures/pikachu.xpm"
# define ENEMY "./textures/enemy2.xpm"
# define ENEMIES "./textures/enemy.xpm"
# define ENEMIES_EV "./textures/enemy_evo.xpm"
# define COLLECTIBLES "./textures/pokeball.xpm"
# define EXIT "./textures/pichu.xpm"
# define FRIENDS "./textures/friends.xpm"

# define C_00 "./textures/0.xpm"
# define C_01 "./textures/1.xpm"
# define C_02 "./textures/2.xpm"
# define C_03 "./textures/3.xpm"
# define C_04 "./textures/4.xpm"
# define C_05 "./textures/5.xpm"
# define C_06 "./textures/6.xpm"
# define C_07 "./textures/7.xpm"
# define C_08 "./textures/8.xpm"
# define C_09 "./textures/9.xpm"
# define T_SIZE 70

typedef struct s_img
{
	void	*wall_t;
	void	*floor_t;
	void	*player_t;
	void	*items_t;
	void	*exit_t;
	void	*friend_t;
	void	*enemy_t;
	void	*enemy_tt;
	void	*enemy_tev;
	void	*c00;
	void	*c01;
	void	*c02;
	void	*c03;
	void	*c04;
	void	*c05;
	void	*c06;
	void	*c07;
	void	*c08;
	void	*c09;
}	t_img;

#endif
