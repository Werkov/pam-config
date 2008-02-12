/* Copyright (C) 2007, 2008 Thorsten Kukuk
   Author: Thorsten Kukuk <kukuk@thkukuk.de>

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License version 2 as
   published by the Free Software Foundation.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */


#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "pam-config.h"
#include "pam-module.h"

static int
write_config_ccreds (pam_module_t *this __attribute__ ((unused)),
		     enum write_type op __attribute__ ((unused)),
		     FILE *fp __attribute__ ((unused)))
{
  if (debug)
    printf ("**** write_config_ccreds (...)\n");

  /* Don't do anything here, pam_krb5 and pam_ldap have to write
     this entries. */

  return 0;
}

GETOPT_START_1(AUTH)
GETOPT_END_1(AUTH)

PRINT_ARGS("ccreds")

/* ---- contruct module object ---- */
DECLARE_BOOL_OPTS_1( is_enabled );
DECLARE_STRING_OPTS_0;
DECLARE_OPT_SETS;
/* at last construct the complete module object */
pam_module_t mod_pam_ccreds = { "pam_ccreds.so", opt_sets,
				&def_parse_config,
				&def_print_module,
				&write_config_ccreds,
				&get_opt_set,
				&getopt,
				&print_args};
