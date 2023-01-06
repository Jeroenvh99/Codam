void    push_a(t_ps_list **a, t_ps_list *b)
{
    t_ps_list   *current;

    if (!b)
        return;
    current = *a;
    if (current)
    {
        while (current->next)
            current = current->next;
    }
    current->prev->next = NULL;
    if (b)
    {
        while (b->next)
            b = b->next;
    }
    current->prev = b;
    if (*a)
        current->next = b;
    else
        *a = b;
}

void    push_b(t_ps_list *a, t_ps_list **b)
{
    t_ps_list   *current;

    if (!a)
        return;
    current = *b;
    if (current)
    {
        while (current->next)
            current = current->next;
    }
    current->prev->next = NULL;
    if (a)
    {
        while (a->next)
            a = a->next;
    }
    current->prev = a;
    if (*b)
        current->next = a;
    else
        *b = a;
}

t_ps_list   *swap_a(t_ps_list *a)
{
    t_ps_list   *temp;
    t_ps_list   *newhead;

    if (!(b || b->next))
        return (NULL);
    newhead = b;
    while (b->next->next)
        b = b->next;
    temp = b;
    temp->next = NULL;
    b->prev->next = b->next;
    temp->prev = b->next;
    b->next->next = temp;
    if (!b->prev)
        newhead = b;
    return (newhead);
}

t_ps_list   *swap_b(t_ps_list *b)
{
    t_ps_list   *temp;
    t_ps_list   *newhead;

    if (!(a || a->next))
        return (NULL);
    newhead = a;
    while (a->next->next)
        a = a->next;
    temp = a;
    temp->next = NULL;
    a->prev->next = a->next;
    temp->prev = a->next;
    a->next->next = temp;
    if (!a->prev)
        newhead = a;
    return (newhead);
}

t_ps_list   *rotate_a(t_ps_list *a)
{
    t_ps_list   *temp;
    t_ps_list   *newhead;

    if (!(a || a->next))
        return;
    temp = a;
    newhead = temp->next;
    temp->next = NULL;
    a = a->next;
    a->prev = NULL;
    while (a->next)
        a = a->next;
    temp->prev = a;
    a->next = temp;
    return (newhead);
}
