/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 17:47:24 by tmielcza          #+#    #+#             */
/*   Updated: 2014/03/27 16:59:12 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# define PARS_TOK_NB		3

/*
**	RT
*/
typedef struct s_pos	t_vect;

typedef struct			s_pos
{
	double				x;
	double				y;
	double				z;
}						t_pos;

typedef struct			s_color
{
	int					r;
	int					g;
	int					b;
}						t_color;

typedef struct			s_ccolor
{
	double				r;
	double				g;
	double				b;
}						t_ccolor;

typedef struct			s_mater
{
	char				*name;
	t_ccolor			diff;
	double				spec;
	double				shin;
	double				refl;
	double				sblur;
}						t_mater;

typedef struct			s_det
{
	double				a;
	double				b;
	double				c;
	double				det;
}						t_det;

typedef struct			s_ray
{
	double				t;
	t_vect				norm;
	t_vect				rnorm;
	t_pos				hit;
	t_pos				rhit;
	t_pos				or;
	t_vect				dir;
}						t_ray;

typedef struct			s_spot
{
	struct s_spot		*next;
	t_ray				ray;
	t_ccolor			ccol;
}						t_spot;

typedef struct			s_view
{
	double				width;
	double				height;
	double				dist;
	t_pos				upleft;
	t_vect				upvect;
	t_vect				rtvect;
}						t_view;

typedef struct			s_cam
{
	t_pos				pos;
	t_pos				look;
	t_vect				dir;
	t_view				view;
	double				xind;
	double				yind;
}						t_cam;

typedef struct			s_sphr
{
	double				rad;
}						t_sphr;

typedef struct			s_pln
{
	t_vect				dir;
}						t_pln;

typedef struct			s_cyl
{
	double				rad;
}						t_cyl;

typedef struct			s_cone
{
	double				tan_a;
	double				angle;
}						t_cone;

typedef struct			s_ellips
{
	t_vect				size;
}						t_ellips;

typedef struct			s_vimg
{
	void				*ptr;
	char				*pxl;
	int					bpp;
	int					ln;
	int					nd;
}						t_vimg;

typedef struct			s_rot
{
	double				**y;
	double				**x;
	double				**z;
}						t_rot;

typedef struct			s_obj
{
	struct s_obj		*next;
	void				*obj;
	int					type;
	t_color				color;
	t_mater				mat;
	t_cam				cam;
	t_ray				ray;
	t_rot				rot;
	t_rot				invrot;
	t_pos				or;
}						t_obj;

typedef struct			s_env
{
	void				*mlx;
	void				*win;
	t_vimg				img;
	t_obj				*l_obj;
	t_cam				cam;
	t_spot				*l_spot;
	int					draw;
	int					selected_button;
	int					status;
	int					fail;
	void				*wb;
	void				*gb;
	void				*rb;
	void				*owl;
	void				*black;
}						t_env;

/*
**	PARSER
*/
enum					e_pars_otypes
{
	_sphere, _plan, _cyl, _cone, _elli
};

enum					e_pars_obj
{
	_opos, _orot, _ocolor, _otype, _omat
};

enum					e_pars_cam
{
	_cpos, _clook, _cdir
};

enum					e_pars_token
{
	_tcam, _tspot, _tobj
};

enum					e_lex_status
{
	_lwait, _word, _num, _comment
};

enum					e_pars_status
{
	_start, _camera, _spot, _wait
};

typedef struct			s_llex
{
	struct s_llex		*next;
	int					type;
	char				*str;
}						t_llex;

typedef struct			s_laut
{
	int					status;
	int					i;
	char				*buf;
	t_llex				*l_lex;
}						t_laut;

typedef struct			s_saut
{
	int					fd;
	int					status;
	t_llex				*l_lex;
	int					done[PARS_TOK_NB];
}						t_saut;

typedef struct			s_pars
{
	int					status;
	int					max;
	char				*str;
	int					(*is)(t_llex *);
	int					(*use)(t_env *, t_saut *);
}						t_pars;

#endif
