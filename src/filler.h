/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 11:10:43 by abukasa           #+#    #+#             */
/*   Updated: 2018/08/15 16:21:13 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"

struct				s_pieceinfo
{
	int				xlen;
	int				ylen;
	int				offy;
	int				offx;
}					thepiece;

struct				s_mapinfo
{
	int				player;
	char			enemy;
	int				mapy;
	int				mapx;
	int				myy;
	int				myx;
	int				enemyy;
	int				enemyx;
}					mapping;

struct				s_map
{
	int				y;
	int				x;
	int				data;
	int				heat;
	struct s_map	*left;
	struct s_map	*right;
	struct s_map	*top;
	struct s_map	*bttm;
	struct s_map	*next;
	struct s_map	*prev;
}					*headdata;

struct				s_all
{
	struct s_map	**smap;
	struct s_map	**cmap;
	struct s_piece	**spiece;
	struct s_piece	**cpiece;
}					*all;

struct				s_piece
{
	int				y;
	int				x;
	int				data;
	struct s_piece	*left;
	struct s_piece	*right;
	struct s_piece	*top;
	struct s_piece	*bttm;
	struct s_piece	*next;
	struct s_piece	*prev;
	int				tempx;
	int				tempy;
}					*headpiece;

struct				s_poss
{
	int				x;
	int				y;
	int				exit;
	struct s_poss	*next;
}					*headposs;
struct s_poss		*currentposs;
struct s_poss		*newposs;

int					search(char *line, char c);
struct s_mapinfo	getmapinfo();
void				placepiece(int y, int x);
struct s_mapinfo	board();
struct s_map		*adddata(int x, int y, char c, struct s_map *headdata);
struct s_piece		*addpiece(int x, int y, char c, struct s_piece *headpiece);
void				addpiece2(struct s_piece **currentpiece,
		struct s_piece **newpiece, struct s_piece **headpiece);
struct s_pieceinfo	getpieceinfo(char *line);
struct s_poss		*checkpossible(struct s_mapinfo mapping,
		struct s_pieceinfo thepiece);
int					piececheck(struct s_all *all, int *xy,
		char piece, struct s_mapinfo mapping);
int					piececheck2(int *xyp, struct s_all *all,
		struct s_mapinfo *mapping, char piece);
struct s_poss		*addposs(int x, int y);
char				mypiece(struct s_map *headdata);
void				algo1(struct s_poss **headposs, struct s_mapinfo mapping);
void				algo2(struct s_poss **headposs, struct s_mapinfo mapping,
		struct s_map *headdata);
double				ftsq(int num);
int					ftpow(int nbr, int pow);
int					ifcenter(int a, int b);
void				trimpiece(struct s_piece **headpiece,
		struct s_pieceinfo *thepiece);
struct s_pieceinfo	xtrim(struct s_piece **headpiece,
		struct s_pieceinfo thepiece);
struct s_pieceinfo ytrim(struct s_piece **headpiece,
		struct s_pieceinfo thepiece);
int					xempty(struct s_piece *headpiece);
int					yempty(struct s_piece *headpiece);
struct s_pieceinfo	trimy(struct s_piece *headpiece,
		struct s_pieceinfo thepiece);
void				trimy2(struct s_piece **temp);
struct s_pieceinfo	trimx(struct s_piece *headpiece,
		struct s_pieceinfo thepiece);
void				trimx2(struct s_piece **temp);
int					emptyx(struct s_piece *headpiece);
int					emptyy(struct s_piece *headpiece);
struct s_pieceinfo	ytrim(struct s_piece **headpiece,
		struct s_pieceinfo thepiece);
void				ytrim2(struct s_piece **temp, struct s_piece **headpiece);
void				init_piece(struct s_pieceinfo *p);
void				init_mapping(struct s_mapinfo *m);
struct s_all		*init_all(struct s_map **headdata,
		struct s_piece **headpiece, struct s_all *all);
void				free_poss(struct s_poss **headposs);
void				free_map(struct s_map **headdata);
void				free_piece(struct s_piece **headpiece);
struct s_mapinfo	play();
struct s_map		**createmap(struct s_map *headdata);
struct s_piece		**createpiece(struct s_piece *headpiece);
void				freeall(struct s_piece **headpiece,
		struct s_map **headdata, struct s_poss **headposs);
#endif
