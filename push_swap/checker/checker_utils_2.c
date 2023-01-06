t_ps_list   *rotate_b(t_ps_list *b)
{
    t_ps_list   *temp;
    t_ps_list   *newhead;

    if (!(b || b->next))
        return;
    temp = b;
    newhead = temp->next;
    temp->next = NULL;
    b = b->next;
    b->prev = NULL;
    while (b->next)
        b = b->next;
    temp->prev = b;
    b->next = temp;
    return (newhead);
}

t_ps_list   *rrotate_a(t_ps_list *a)
{
    t_ps_list   *current;

    if (!(a || a->next))
        return;
    current = a;
    while (current->next)
        current = current->next;
    current->prev->next = NULL;
    current->prev = NULL;
    a->prev = current;
    current->next = a;
    return (current);
}

t_ps_list   *rrotate_b(t_ps_list *b)
{
    t_ps_list   *current;

    if (!(b || b->next))
        return;
    current = b;
    while (current->next)
        current = current->next;
    current->prev->next = NULL;
    current->prev = NULL;
    b->prev = current;
    current->next = b;
    return (current);
}
