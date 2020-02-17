#include "ft_select.h"

void	print_list(t_word *words)
{
	while (words)
	{
		ft_printf("%s %d\n", words->value, words->len);
		words = words->next;
	}
}

int main()
{
	int argc = 6;
	char *argv[] = {
		"please ignore",
		"alpha",
		"beta",
		"charlie",
		"delta",
		"echo"
	};
	t_word	*list;

	list = create_words_list(argc, argv);
	print_list(list);
	ft_printf("\nlog: delete head\n");
	list = delete_word(list, list);
	print_list(list);

	t_word *w = get_word_no(list, 2);
	list = delete_word(list, w);
	ft_printf("\nlog: delete word #2\n");
	print_list(list);
	return (0);
}
