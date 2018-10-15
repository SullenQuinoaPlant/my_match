#include "mymatch_interactive.h"

int							run_node(
	char const **m,
	t_s_mtc_n *n,
	void *m_s,
	t_memp *ret)
{
	int		r;

	r = MTC_YAY;
	if ((*n->is_match)(n->node_pattern, m, m_s) == MTC_YAY &&
		(r = (*n->on_match)(m, m_s, ret)) == MTC_YAY &&
		(n->continue && n->continue_mtc) &&
		(r = (*n->continue_mtc)(m, continue, m_s, ret)) == MTC_YAY &&
		n->on_return)
		r = (*n->on_return)(m, m_s, ret);
	return (r);
}
