#ifndef MYMATCH_H
# define MYMATCH_H

typedef int	(*t_mtc_adder)(
	t_mtc_node		*addee,
	void			*pattern_store);
	
typedef int	(*t_mtc_remover)(
	t_mtc_node
	t_mtc_pattern	*removee_pattern,
	void			*pattern_store);

typedef int	(*t_mtc_matcher)(
	char const	**matchee_string,
	void const	*pattern_store,
	void		**p_ret);
	
typedef struct s_mtc_unit	t_s_mtc_unit;
struct s_mtc_unit
{
	t_mtc_matcher	mtc;
	t_mtc_adder		add;
	t_mtc_remover	rem;
	void			*store;
}

# define MTC_SYS_ERR -1
# define MTC_SUCCESS 0
# define MTC_NO_PATTERN -1

#endif
