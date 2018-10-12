#include "mymatch_interactive.h"
#include "mymatch.h"

int							mtc_match(
	char const *matchee,
	t_s_mtc_store *against,
	void *state_init,
	t_memp **p_ret)
{
	char const *const	in = matchee;
	t_memp				parse_state;

	
	if ((*against->init_match)(state_init, &parse_state) == SUCCESS &&
		(!against->node_pattern ||
		!ft_strcmp(against->node_pattern, matchee)))
	{
		matchee += ft_strlen(against->node_pattern);
		(*against->on_match)(matchee, 
	}
	against->
}
