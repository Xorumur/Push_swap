/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:58:48 by mlecherb          #+#    #+#             */
/*   Updated: 2022/01/24 18:22:47 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	int				content;
	int				pos;
	struct s_list	*next;
}					t_list;


void	eco_space(t_list *stb, t_list *sta, int *log);
int		ft_checker(t_list **sta);
/*			RULES		*/
void	ft_pa(t_list *new, t_list **sta, t_list **stb);
void	ft_pb(t_list *new, t_list **sta, t_list **stb);
void	ft_rb(t_list *new, t_list **stb);
void	ft_ra(t_list *new, t_list **sta);
void	ft_rra(t_list **sta);
void	ft_rrb(t_list **stb);
void	ft_sb(t_list **stb);
void	ft_sa(t_list *sta);
/*			LST			*/
void	ft_lstdeletefirst(t_list **lst);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **alst, t_list *new);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstdeletelast(t_list *lst);
void	delete_linked_list(t_list **sta);
/*			AFFICHAGE	*/
void	ft_afflst(t_list *sta);
void	ft_afflog(int *log, int len);
/*			MAIN		*/
int		ft_attrib(t_list **sta, int argc, char **argv);
char	**ft_split(char *s, char c);
int		ft_atoi(const char *str);
/*			SORT		*/
int		*det_first_pack(t_list **sta, int *pack);
void	bottom_b(t_list **sta, t_list **stb);
void	top_b(t_list **sta, t_list **stb);
void	bottom_a(t_list **sta);
void	det_case(int *pack, t_list **sta);
int		case_pack(int *log);
int		*parting(t_list **sta);
int		*stack_log(t_list **sta);
int		*ft_bubblesortright(int *log, int len);
void	cutting(t_list **sta, t_list **stb);
void	assist_cutting(t_list **sta, t_list **stb, int end, int *log);
int		ft_first_max(t_list **sta, int *log);
void	sizetwo(t_list **sta);
/*			QUICKSORT	*/
void	ft_utd(t_list **sta);
void	ft_dtu(t_list **sta);
void	ft_dut(t_list **sta);
void	ft_tud(t_list **sta);
void	ft_tdu(t_list **sta);

void	sizetree(t_list **sta);
void	ft_utd3(t_list **sta);
void	ft_dtu3(t_list **sta);
void	ft_dut3(t_list **sta);
void	ft_tud3(t_list **sta);
void	ft_tdu3(t_list **sta);

void	push_a(t_list **sta, t_list **stb);
int		*log_stb(t_list **stb, int *log);
void	ft_quick(t_list **sta);
// void	first_encounter(t_list **stb, int *log, int len);
void	last_two(t_list **stb, t_list **sta);

void	last_four(t_list **stb);
void	put_min_bot(t_list **stb, int min);
void	push_elem(t_list **sta, t_list **stb);
void	go_top(t_list **stb, int *log, int len);
int		det_top(t_list **stb, int *log, int len);
int		det_bot(t_list **stb, int *log, int len);
void	send_top_by_rrb(t_list **stb, int content);
void	send_top_by_rb(t_list **stb, int content);
int		get_content(t_list **stb, int pos);
void	fill_node(t_list **stb);
int		ft_det_pos(t_list **stb, int content);
#endif