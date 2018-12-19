# FdF
projet FdF de 42

## Notes de cours MinilibX

`man /usr/share/man/man3/mlx.1`


## Fonctions

### Connection a la minilibX
Include des fonctions de la librairie:
`#include <mlx.h>`

Pour le link il faut ajouter ces flags a la compilation:
`-lmlx -framework OpenGL -framework AppKit`

Fonction qui connecte au serveur graphique x du mac:
```c
void	*mlx_init()
```
Elle renvoie un pointeur comme identifiant de connexion au serveur graphique, si echoue, renvoie un pointeur sur `NULL`


### Gestion des fenetres
#### Creation d'une fenetre a l'ecran:
```c
void	*mlx_new_window(void *mlx_ptr, int width, int height, char *title)
```
Elle renvoie un pointeur comme identifiant de la fenetre.

#### Reintialisation d'une fenetre


Affichage d'un pixel dans la fenetre:
```c
int mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color)
```

#### Exemple personnel
```c
int		main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 512, 512, "titre de la fenetre");
	mlx_pixel_put(mlx_ptr, win_ptr, 128, 128, 0xFFFFFF);
}
```

# Gestion des evenements

Avant d'appeler mlx_loop, on appelle mlx_key_hook :
```c
int mlx_key_hook(void *win_ptr, int (*funct_ptr)(), void *param );
```
En code cela donne ca
```c
mlx_key_hook(win_ptr, deal_key, (void *)0);
```
on doit alors creer la fonction qui est appelee:
```c
int deal_key(int key, void *param)
{
	ft_putchar('x');
	return (0);
}
```
Le parametre "`void param`" est a utiliser pour transmettre les variables mlx_ptr et win_ptr.