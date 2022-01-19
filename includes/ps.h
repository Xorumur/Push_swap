/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:08:51 by mlecherb          #+#    #+#             */
/*   Updated: 2022/01/19 17:15:44 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_list
{
	int				content;
	int				pos;
	struct s_list	*next;
}					t_list;

typedef struct STOCKVAL
{
	int l1;
	int l2;
	int l3;
	int l4;
	int l5;
	int l6;
	int len;
	int *log;
	int lenlog;
}		v_list;

/*			RULES		*/
void 	ft_pa(t_list *new, t_list **sta, t_list **stb);
void 	ft_pb(t_list *new, t_list **sta, t_list **stb);
void 	ft_rb(t_list *new, t_list **stb);
void 	ft_ra(t_list *new, t_list **sta);
void	ft_rra(t_list **sta);
void	ft_rrb(t_list **stb);
void	ft_sb(t_list **stb);
void	ft_sa(t_list *sta);
/*			UTILS		*/
char	**ft_split(char *s, char c);
int		ft_atoi(const char *str);
int 	ft_attrib(t_list **sta, int argc, char **argv);
/*			AFFICHAGE	*/
void	ft_afflst(t_list *sta);
void 	ft_affst(v_list st);
/*			LST			*/
void	ft_lstdeletefirst(t_list **lst);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **alst, t_list *new);
void	ft_lstadd_back(t_list **alst, t_list *new);
void 	ft_lstdeletelast(t_list *lst);
/*			SORTING		*/
int		*ft_bubblesortright(int *log, int len);
int		*ft_register(t_list *sta, v_list *st, int len);
void 	ft_chunker(v_list *st, t_list *sta, int len);
int 	ft_pos_first_chunk(t_list *sta, int max, int min);
int 	ft_pos_last_chunk(t_list *sta, int max, int min);
void 	ft_build(t_list **sta, v_list st, int max, int min);
int		ft_elvalidator(t_list *sta, int max, int min, v_list st);
void	ft_orga(t_list **stb);
void	ft_orga2(t_list **stb, int max);
void	ft_sort(t_list **stb);
void	ft_cone(v_list st, t_list **sta, t_list **stb);
void	ft_ctwo(v_list st, t_list **sta, t_list **stb);
void	ft_ctree(v_list st, t_list **sta, t_list **stb);
void	ft_cfour(v_list st, t_list **sta, t_list **stb);
void	ft_cfive(v_list st, t_list **sta, t_list **stb);
// void 	ft_push_back(v_list st, t_list **sta, t_list **stb);
// void 	ft_apply_rules(int pos, t_list **stb, int len, int content);
// int 	ft_det_pos(int content, t_list **stb);
void	ft_pushback(t_list **sta, t_list **stb, v_list st);
int		ft_det_pos(t_list **stb, int content);
void	send_top_by_rrb(t_list **stb, int content);
void	send_top_by_rb(t_list **stb, int content);
void 	fill_node(t_list **stb);

#endif 