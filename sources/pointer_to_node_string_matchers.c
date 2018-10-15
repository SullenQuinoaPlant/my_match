int							mtc_npstr_while_progress(
	char const **matchee,
	t_mtc_store pattern_store,
	void *m_s,
	t_memp *ret)
{
	t_s_mtc_n **const	npstr = (t_s_mtc_n**)pattern_store;
	char const			*prv;
	char const			*in;
	int					i;
	int					r;

	prv = 0;
	in = *matchee;
	while (prv != in && *in)
	{
		i = -1;
		prv = in;
		while (npstr[++i] && prv == in)
			r = run_node(&in, npstr[i], m_s, ret);
	}
	*matchee = in;
	return (r);
}
