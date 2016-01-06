/*
 * Copyright (C) 2012  Alejandro Mery <amery@geeks.cl>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <stddef.h> /* offsetof */
#include "common.h"

/** initialize an empty list hook */
void list_init(struct list_entry *self)
{
    self->prev = self->next = self;
}

/** puts an entry between two other on a list */
void list_inject(struct list_entry *l, struct list_entry *prev, struct list_entry *next)
{
    l->prev = prev;
    l->next = next;

    next->prev = l;
    prev->next = l;
}

/** removes an entry for the list where it's contained */
void list_remove(struct list_entry *l)
{
    struct list_entry *prev = l->prev, *next = l->next;
    next->prev = prev;
    prev->next = next;
}

/** returns first element of a list */
struct list_entry *list_first(struct list_entry *l)
{
    return (l->next == l) ? NULL : l->next;
}

/** returns last element of a list */
struct list_entry *list_last(struct list_entry *l)
{
    return (l->prev == l) ? NULL : l->prev;
}

/** returns next element on a list */
struct list_entry *list_next(struct list_entry *l, struct list_entry *e)
{
    return (e->next == l) ? NULL : e->next;
}

/** is list empty? */
int list_empty(struct list_entry *l)
{
    return (l->prev == l);
}
