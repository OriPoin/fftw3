/*
 * Copyright (c) 2001 Matteo Frigo
 * Copyright (c) 2001 Steven G. Johnson
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

/* $Id: zero.c,v 1.6 2003-02-09 07:36:25 stevenj Exp $ */

#include "bench.h"

/* set I/O arrays to zero.  Default routine */
void problem_zero(bench_problem *p)
{
     bench_complex czero = {0, 0};
     if (p->kind == PROBLEM_COMPLEX) {
	  caset(p->inphys, p->iphyssz, czero);
	  caset(p->outphys, p->ophyssz, czero);
     } else if (p->kind == PROBLEM_R2R) {
	  aset(p->inphys, p->iphyssz, 0.0);
	  aset(p->outphys, p->ophyssz, 0.0);
     } else if (p->kind == PROBLEM_REAL && p->sign < 0) {
	  aset(p->inphys, p->iphyssz, 0.0);
	  caset(p->outphys, p->ophyssz, czero);
     } else if (p->kind == PROBLEM_REAL && p->sign > 0) {
	  caset(p->inphys, p->iphyssz, czero);
	  aset(p->outphys, p->ophyssz, 0.0);
     } else {
	  BENCH_ASSERT(0); /* TODO */
     }
}