int computorv2_setpos(t_statment *st, int pos)
{
	if (st)
	{
		st->pos = pos;
		return (COMPUTORV2_ERROR);
	}
	return (COMPUTORV2_SUCCESS);
}