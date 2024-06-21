int computorv2_skip_spaces(t_statment *st)
{
	if (st->str)
	{
		while ((st->pos < st->len) && isspace(st->str[st->pos]))
		{
			st->pos++;
		}
	}
	return (COMPUTORV2_SUCCESS);
}