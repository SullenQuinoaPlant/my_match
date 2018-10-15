#include "mymatch_interactive.h"
#include "mymatch.h"

int							mtc_match(
	char const *match_this,
	t_mtc_store *against,
	t_memp m_s_init,
	t_memp *p_ret)
{
	char const *const	in = match_this;
	t_s_mtc_s *const	store = (t_s_mtc_s*)against;
	t_memp				m_s;
	int					r;

	*p_ret = 0;
	m_s = 0;
	if ((*store->init_match)(m_s_init, &m_s) == MTC_YAY)
		r = run_node(&in, store->head, m_s->p, p_ret);
	if (m_s->p)
	{
		if (store->end_match)
			store->end_match(m_s);
		else
			ft_cleanfree(m_s->p, m_s->sz);
	}
	return (r);
}
