#include "push_swap.h"
/* */ /* */
/* */ /* */
/* */ /* */
/* */ /* */
/* */ /* */

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
	{
		str = malloc(sizeof(char));
		str[0] = 0;
		return (str);
	}
	i = 0;
	while (s[start + i] && i < len)
		i++;
	str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len && start + i < ft_strlen(s))
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static size_t	ft_nbr_mots(char const *s, char c)
{
	size_t	i;
	size_t	mot;

	i = 0;
	mot = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			while (s[i] != c && s[i])
				i++;
			mot++;
		}
	}
	return (mot);
}

static size_t	ft_lettres(char const *s, size_t start, char c)
{
	size_t	i;

	i = 0;
	while (s[start + i] && s[start + i] != c)
	{
		i++;
	}
	return (i);
}

char	**ft_split(const char *s, char c)
{
	size_t	i;
	size_t	mots;
	char	**ptr;

	if (!s)
		return (NULL);
	ptr = malloc((ft_nbr_mots(s, c) + 1) * sizeof(ptr));
	if (!ptr)
		return (NULL);
	i = 0;
	mots = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			ptr[mots] = ft_substr(s, i, ft_lettres(s, i, c));
			i = i + ft_lettres(s, i, c);
			mots++;
		}
	}
	ptr[mots] = NULL;
	return (ptr);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	signe;
	int	retour;

	i = 0;
	signe = 1;
	retour = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
			i++;
	if (nptr[i] == 43 || nptr[i] == 45)
	{
		if (nptr[i] == 45)
			signe = signe * -signe;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		retour = retour * 10 + nptr[i] - '0';
		i++;
	}
	return (retour * signe);
}

size_t	ft_strlenn(int *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
/* */ /* */
/* */ /* */
/* */ /* */
/* */ /* */
/* */ /* */
/* */ /* */
/* */ /* */
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

