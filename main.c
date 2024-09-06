char	*ft_strcat(char *dest, char *src)
{
	unsigned int	i;

	i = 0;
	while (dest[i])
		i++;
	while (*src)
	{
		dest[pos] = *src;
		src++;
		pos++;
	}
	dest[pos] = 0;
	return (dest);
}