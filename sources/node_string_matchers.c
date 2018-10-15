int							mtc_while_progress(
	char const **matchee,
	t_mtc_store pattern_store,
	t_memp **state)
{
	t_s_mtc_node **const	str = (t_s_mtc_node*)pattern_store;
	char const				*prv;
	char const				*in;
	int						i;

	prv = 0;
	in = *matchee;
	while (prv != in && *in)
	{
		i = -1;
		prv = in;
		while (str[++i] && prv == in)
			if (!ft_strcmp(in, str[i]->node_pattern))
				run_node(str[i], 
}
