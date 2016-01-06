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
#ifndef __SUNXI_FEXC_COMMON_H__
#define __SUNXI_FEXC_COMMON_H__

#include <stddef.h> /* offsetof */

/** flat function argument as unused */
#ifdef UNUSED
#elif defined(__GNUC__)
#	define UNUSED(x) UNUSED_ ## x __attribute__((unused))
#else
#	define UNUSED(x) UNUSED_ ## x
#endif

/** finds the parent of an struct member */
#ifndef container_of
#define container_of(P,T,M)	(T *)((char *)(P) - offsetof(T, M))
#endif

/** calculate number of elements of an array */
#ifndef ARRAY_SIZE
#define ARRAY_SIZE(A)		(sizeof(A)/sizeof((A)[0]))
#endif

/** shortcut to printf to stderr */
#define errf(...)	fprintf(stderr, __VA_ARGS__)

#define pr_info(...)	errf("sunxi-fexc: " __VA_ARGS__)
#define pr_err(...)	errf("E: sunxi-fexc: " __VA_ARGS__)

#ifdef DEBUG
#define pr_debug(...)	errf("D: sunxi-fexc: " __VA_ARGS__)
#else
#define pr_debug(...)
#endif

/*
 * list
 */

/** a list hook */
struct list_entry {
    struct list_entry *prev;
    struct list_entry *next;
};

#define list_insert(H, E)	list_inject((E), (H), (H)->next)
#define list_append(H, E)	list_inject((E), (H)->prev, (H))

void list_init(struct list_entry *self);
void list_inject(struct list_entry *l, struct list_entry *prev, struct list_entry *next);
void list_remove(struct list_entry *l);
struct list_entry *list_first(struct list_entry *l);
struct list_entry *list_last(struct list_entry *l);
struct list_entry *list_first(struct list_entry *l);
struct list_entry *list_last(struct list_entry *l);
struct list_entry *list_next(struct list_entry *l, struct list_entry *e);
int list_empty(struct list_entry *l);

#endif /* __SUNXI_FEXC_COMMON_H__  */
