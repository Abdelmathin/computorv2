char computorv2_next(t_statment *st)
{
	if ((st && st->str) && (st->pos < st->len))
	{
		return (st->str[st->pos]);
	}
	return (0);
}

char computorv2_next_at(t_statment *st, int at)
{
	if ((st && st->str) && (0 <= st->pos + at) && (st->pos + at < st->len))
	{
		return (st->str[st->pos + at]);
	}
	return (0);
}
