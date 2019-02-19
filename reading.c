#include <stdio.h>

int letter_prove(char *str)
{
  while(*str)
  {
    if (*str == '.' || *str == '#')
      str++;
    else
      return (0);
  }
  return (1);
}

void ft_lst_free_chain(t_list *chain)
{
  t_list *temp;

  while (chain)
  {
    temp = chain->next;
    free(chain->content);
    free(chain);
    chain = temp;
  }
}

t_list *lst_reverse_helper(t_list *begin, t_list *end)
{
  end->next = begin;
  while (begin)
  {
    if (begin->next == end)
      break ;
    begin = begin->next;
  }
  begin->next = NULL;
  return (end);
}

t_list *ft_lst_reverse(t_list *begin)
{
  t_list *temp_begin;
  t_list *end;

  temp_begin = begin;
  while (end != temp_begin)
  {
    end = begin;
    while (end->next)
    {
      end = end->next;
    }
    begin = lst_reverse_helper(begin, end);
  }
}

t_etra *reader(int fd)
{
  char *line;
  int r;
  int count;
  t_list *temp;
  t_list *temp_res;

  count = 0;
  line = NULL;
  while ((r = get_next_line(fd, char &line)))
  {
    if (line && !ft_strlen(line))
    {

      count = 0;
    }
    else if (line && ft_strlen(line))
    {
      temp = ft_lstnew(line, ft_strlen(line));
      temp_res = ft_lstadd(lst, temp);
    }
  }
}

//ft_lst_iter(lst)

int main()
{
  printf("%d", letter_prove("...."));
  return 0;
}
