/* *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* */
/* ** Copyright UCAR (c) 1990 - 2016                                         */
/* ** University Corporation for Atmospheric Research (UCAR)                 */
/* ** National Center for Atmospheric Research (NCAR)                        */
/* ** Boulder, Colorado, USA                                                 */
/* ** BSD licence applies - redistribution and use in source and binary      */
/* ** forms, with or without modification, are permitted provided that       */
/* ** the following conditions are met:                                      */
/* ** 1) If the software is modified to produce derivative works,            */
/* ** such modified software should be clearly marked, so as not             */
/* ** to confuse it with the version available from UCAR.                    */
/* ** 2) Redistributions of source code must retain the above copyright      */
/* ** notice, this list of conditions and the following disclaimer.          */
/* ** 3) Redistributions in binary form must reproduce the above copyright   */
/* ** notice, this list of conditions and the following disclaimer in the    */
/* ** documentation and/or other materials provided with the distribution.   */
/* ** 4) Neither the name of UCAR nor the names of its contributors,         */
/* ** if any, may be used to endorse or promote products derived from        */
/* ** this software without specific prior written permission.               */
/* ** DISCLAIMER: THIS SOFTWARE IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS  */
/* ** OR IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED      */
/* ** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.    */
/* *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* */
/***************************************************************
 * write_c_mode.c
 *
 * Routines to write to the C-mode output files
 *
 * Mike Dixon, RAP, NCAR, Boulder, CO, USA
 *
 * April 1998
 *
 ****************************************************************/

#include "tdrp_gen.h"
#include <time.h>
#include <limits.h>
#include <float.h>

#define BOOL_STR(a) ((a)? "TRUE" : "FALSE")

static char *EscapedStr = NULL;
static char *escape_quotes(const char *str);
static void free_escaped_str();
static char *print_val(int ptype, const enum_def_t *enum_def, const tdrpVal_t *val);
static void write_comments_load_from_args(const char *module, FILE *out);
static void write_comments_load(const char *module, FILE *out);
static void write_comments_load_defaults(const char *module, FILE *out);
static void write_comments_sync(const char *module, FILE *out);
static void write_comments_print(const char *module, FILE *out);
static void write_comments_check_all_set(const char *module, FILE *out);
static void write_comments_check_is_set(const char *module, FILE *out);
static void write_comments_free_all(const char *module, FILE *out);
static void write_comments_array_realloc(const char *module, FILE *out);
static void write_comments_array2D_realloc(const char *module, FILE *out);
static void write_comments_table(const char *module, FILE *out);
static void write_comments_init(const char *module, FILE *out);

/***********************************************
 * write_h_file()
 *
 * Write the header file
 *
 * Returns 0 on success, -1 on failure.
 */

int write_h_file(const char *module, const TDRPtable *t_entries,
		 int n_defs, const char *prog_name)

{

  char hname[4096];
  char struct_name[4096];
  char type_str[4096];
  FILE *hfile;
  int i, j;
  const TDRPtable *tt;

  /*
   * open file
   */
  
  sprintf(hname,"%s_tdrp.h", module);
  if ((hfile = fopen(hname, "w")) == NULL) {
    fprintf(stderr, "ERROR: tdrp_gen:write_h_file, opening file\n");
    perror(hname);
    return (-1);
  }

  /*
   * preamble
   */

  fprintf(hfile, "/*******************************************\n");
  fprintf(hfile, " * %s\n", hname);
  fprintf(hfile, " *\n");
  if (strlen(module) > 0) {
    fprintf(hfile, " * TDRP header file for '%s' module.\n", module);
  } else {
    fprintf(hfile, " * TDRP header file.\n");
  }
  fprintf(hfile, " *\n");
  if (strlen(prog_name) > 0) {
    fprintf(hfile, " * Code for program %s\n", prog_name);
    fprintf(hfile, " *\n");
  }
  fprintf(hfile, " * This header file has been automatically\n");
  fprintf(hfile, " * generated by TDRP, do not modify.\n");
  fprintf(hfile, " *\n");
  fprintf(hfile, " *******************************************/\n");
  fprintf(hfile, "\n");
  fprintf(hfile, "#ifndef _%s_tdrp_h\n", module);
  fprintf(hfile, "#define _%s_tdrp_h\n", module);
  fprintf(hfile, "\n");
  fprintf(hfile, "#ifdef __cplusplus\n");
  fprintf(hfile, "extern \"C\" {\n");
  fprintf(hfile, "#endif\n");
  fprintf(hfile, "\n");
  fprintf(hfile, "#include <tdrp/tdrp.h>\n");
  fprintf(hfile, "\n");

  fprintf(hfile,
	  "/*\n"
	  " * typedefs\n"
	  " */\n\n");

  /*
   * enum typedefs
   */

  for (i = 0; i < n_enum_defs(); i++) {
    enum_def_t *enm = enum_def_by_index(i);
    fprintf(hfile, "typedef enum {\n");
    for (j = 0; j < enm->nfields; j++) {
      fprintf(hfile, "  %s = %d",
	      enm->fields[j].name, enm->fields[j].val);
      if (j < enm->nfields - 1) {
	fprintf(hfile, ",\n");
      } else {
	fprintf(hfile, "\n");
      }
    } /* j */
    fprintf(hfile, "} %s_%s;\n", module, enm->name);
    fprintf(hfile, "\n");
  } /* i */

  /*
   * struct typedefs
   */
  
  for (i = 0; i < n_struct_defs(); i++) {
    struct_def_t *strct = struct_def_by_index(i);
    fprintf(hfile, "typedef struct {\n");
    for (j = 0; j < strct->nfields; j++) {
      fprintf(hfile, "  %s %s;\n",
	      ctype_cname_by_iname(strct->fields[j].ftype),
	      strct->fields[j].fname);
    } /* j */
    fprintf(hfile, "} %s_%s;\n", module, strct->name);
    fprintf(hfile, "\n");
  } /* i */

  /*
   * start of main tdrp struct
   */

  sprintf(struct_name, "%s_tdrp_struct", module);

  fprintf(hfile,
	  "/*\n"
	  " * typedef for main struct - %s\n"
	  " */\n\n", struct_name);

  fprintf(hfile, "typedef struct {\n");
  fprintf(hfile, "\n");
  fprintf(hfile, "  size_t struct_size;\n");

  /*
   * members of main struct
   */

  tt = t_entries;
  for (i = 0; i < n_defs; i++, tt++) {
    if (tt->ptype != COMMENT_TYPE) {
      tdrpEntryType2Str(module, tt, type_str);
      fprintf(hfile, "\n");
      fprintf(hfile, "  /***** %s *****/\n", tt->param_name);
      fprintf(hfile, "\n");
      if (tt->is_array) {
	fprintf(hfile, "  struct {\n");
	fprintf(hfile, "    %s *val;\n", type_str);
	fprintf(hfile, "    int len;\n");
	fprintf(hfile, "  } %s;\n", tt->param_name);
	tdrpEntryType2Str(module, tt, type_str);
	fprintf(hfile, "  %s *_%s;\n", type_str, tt->param_name);
	fprintf(hfile, "  int %s_n;\n", tt->param_name);
	if (tt->is_array2D) {
	  fprintf(hfile, "  %s **__%s;\n", type_str, tt->param_name);
	  fprintf(hfile, "  int %s_n1;\n", tt->param_name);
	  fprintf(hfile, "  int %s_n2;\n", tt->param_name);
	}
      } else {
	fprintf(hfile, "  %s %s;\n", type_str, tt->param_name);
      }
    } /* if (tt->ptype != COMMENT_TYPE) */
  } /* i */

  /*
   * end of main struct
   */

  fprintf(hfile, "\n");
  fprintf(hfile, "} %s;\n", struct_name);
  fprintf(hfile, "\n");

  /*
   * function prototypes
   */

  fprintf(hfile,
	  "/*\n"
	  " * function prototypes\n"
	  " */\n\n");

  /*
   * _tdrp_load_from_args()
   */

  write_comments_load_from_args(module, hfile);
  
  fprintf(hfile,
	  "extern int %s_tdrp_load_from_args(int argc, char **argv,\n"
	  "                                %s_tdrp_struct *params,\n"
	  "                                char **override_list,\n"
	  "                                char **params_path_p);\n\n",
	  module, module);

  /*
   * _tdrp_load()
   */

  write_comments_load(module, hfile);

  fprintf(hfile,
	  "extern int %s_tdrp_load(char *param_file_path,\n"
	  "                      %s_tdrp_struct *params,\n"
	  "                      char **override_list,\n"
	  "                      int expand_env, int debug);\n\n",
	  module, module);

  /*
   * _tdrp_load_defaults()
   */

  write_comments_load_defaults(module, hfile);

  fprintf(hfile,
	  "extern int %s_tdrp_load_defaults(%s_tdrp_struct *params,\n"
	  "                               int expand_env);\n\n",
	  module, module);

  /*
   * _tdrp_sync()
   */

  write_comments_sync(module, hfile);

  fprintf(hfile,
	  "extern void %s_tdrp_sync(void);\n\n",
	  module);

  /*
   * _tdrp_print()
   */

  write_comments_print(module, hfile);

  fprintf(hfile,
	  "extern void %s_tdrp_print(FILE *out, tdrp_print_mode_t mode);\n\n",
	  module);
     
  /*
   * _tdrp_free_all()
   */

  write_comments_free_all(module, hfile);

  fprintf(hfile,
	  "extern void %s_tdrp_free_all(void);\n\n",
	  module);

  /*
   * _tdrp_check_all_set()
   */

  write_comments_check_all_set(module, hfile);

  fprintf(hfile,
	  "extern int %s_tdrp_check_all_set(FILE *out);\n\n",
	  module);

  /*
   * _tdrp_check_is_set()
   */

  write_comments_check_is_set(module, hfile);

  fprintf(hfile,
          "extern int %s_tdrp_check_is_set(char *param_name);\n\n",
          module);

  /*
   * _tdrp_array_realloc()
   */

  write_comments_array_realloc(module, hfile);

  fprintf(hfile,
	  "extern int %s_tdrp_array_realloc(char *param_name,\n"
	  "                              int new_array_n);\n\n",
	  module);

  /*
   * _tdrp_array2D_realloc()
   */

  write_comments_array2D_realloc(module, hfile);

  fprintf(hfile,
	  "extern int %s_tdrp_array2D_realloc(char *param_name,\n"
	  "                                 int new_array_n1,\n"
	  "                                 int new_array_n2);\n\n",
	  module);

  /*
   * _tdrp_table()
   */

  write_comments_table(module, hfile);

  fprintf(hfile,
	  "extern TDRPtable *%s_tdrp_table(void);\n\n",
	  module);
  
  /*
   * _tdrp_init()
   */

  write_comments_init(module, hfile);

  fprintf(hfile,
	  "extern TDRPtable *%s_tdrp_init(%s *params);\n\n",
	  module, struct_name);

  /*
   * ending
   */

  fprintf(hfile, "#ifdef __cplusplus\n");
  fprintf(hfile, "}\n");
  fprintf(hfile, "#endif\n");
  fprintf(hfile, "\n");

  fprintf(hfile, "#endif\n");
  fprintf(hfile, "\n");

  fclose(hfile);
  return (0);

}

/***********************************************
 * write_c_file()
 *
 * Write the C code file
 *
 * Returns 0 on success, -1 on failure.
 */

int write_c_file(const char *module, const TDRPtable *t_entries,
		 int n_defs, const char *prog_name)

{

  char cname[4096];
  char struct_name[4096];
  FILE *cfile;
  int idef;
  const TDRPtable *tt;

  sprintf(struct_name, "%s_tdrp_struct", module);

  /*
   * open file
   */

  sprintf(cname,"%s_tdrp.c", module);

  if ((cfile = fopen(cname, "w")) == NULL) {
    fprintf(stderr, "ERROR: tdrp_gen:write_c_file, opening file\n");
    perror(cname);
    return (-1);
  }

  /*
   * preamble
   */

  fprintf(cfile,
	  "/*******************************************\n"
	  " * %s\n"
	  " *\n", cname);

  if (strlen(module) > 0) {
    fprintf(cfile, " * TDRP C code file '%s' module.\n", module);
  } else {
    fprintf(cfile, " * TDRP C code file.\n");
  }
  fprintf(cfile, " *\n");
  
  if (strlen(prog_name) > 0) {
    fprintf(cfile, " * Code for program %s\n", prog_name);
    fprintf(cfile, " *\n");
  }

  fprintf(cfile,
	  " * This file has been automatically\n"
	  " * generated by TDRP, do not modify.\n"
	  " *\n"
	  " *******************************************/\n"
	  "\n"
	  "#include \"%s_tdrp.h\"\n"
	  "#include <string.h>\n"
	  "\n",
	  module);
  
  /*
   * file scope variables
   */

  fprintf(cfile,
	  "/*\n"
	  " * file scope variables\n"
	  " */\n"
	  "\n"
	  "static TDRPtable Table[%d];\n",
	  n_defs + 1);

  fprintf(cfile,
	  "static %s_tdrp_struct *Params;\n"
	  "static char *Module = \"%s\";\n"
	  "\n",
	  module, module);
  
  /*
   * module access functions
   */

  /*
   * _tdrp_load_from_args()
   */

  write_comments_load_from_args(module, cfile);

  fprintf(cfile ,
	  "int %s_tdrp_load_from_args(int argc, char **argv,\n"
	  "                         %s_tdrp_struct *params,\n"
	  "                         char **override_list,\n"
	  "                         char **params_path_p)\n"
	  "{\n"
	  "  Params = params;\n"
	  "  %s_tdrp_init(Params);\n"
	  "  if (tdrpLoadFromArgs(argc, argv,\n"
	  "                       Table, Params,\n"
	  "                       override_list, params_path_p)) {\n"
	  "    return (-1);\n"
	  "  } else {\n"
	  "    return (0);\n"
	  "  }\n"
	  "}\n\n",
	  module, module, module);

  /*
   * _tdrp_load()
   */

  write_comments_load(module, cfile);

  fprintf(cfile,
	  "int %s_tdrp_load(char *param_file_path,\n"
	  "               %s_tdrp_struct *params,\n"
	  "               char **override_list,\n"
	  "               int expand_env, int debug)\n"
	  "{\n"
	  "  Params = params;\n"
	  "  %s_tdrp_init(Params);\n"
	  "  if (tdrpLoad(param_file_path, Table,\n"
	  "               params, override_list,\n"
	  "               expand_env, debug)) {\n"
	  "    return (-1);\n"
	  "  } else {\n"
	  "    return (0);\n"
	  "  }\n"
	  "}\n\n",
	  module, module, module);

  /*
   * _tdrp_load_defaults()
   */

  write_comments_load_defaults(module, cfile);

  fprintf(cfile,
	  "int %s_tdrp_load_defaults(%s_tdrp_struct *params,\n"
	  "                        int expand_env)\n"
	  "{\n"
	  "  Params = params;\n"
	  "  %s_tdrp_init(Params);\n"
	  "  if (tdrpLoad(NULL, Table,\n"
	  "               params, NULL,\n"
	  "               expand_env, FALSE)) {\n"
	  "    return (-1);\n"
	  "  } else {\n"
	  "    return (0);\n"
	  "  }\n"
	  "}\n\n",
	  module, module, module);

  /*
   * _tdrp_sync()
   */

  write_comments_sync(module, cfile);

  fprintf(cfile,
	  "void %s_tdrp_sync(void)\n"
	  "{\n"
	  "  tdrpUser2Table(Table, Params);\n"
	  "}\n\n",
	  module);

  /*
   * _tdrp_print()
   */

  write_comments_print(module, cfile);

  fprintf(cfile,
	  "void %s_tdrp_print(FILE *out, tdrp_print_mode_t mode)\n"
	  "{\n"
	  "  tdrpPrint(out, Table, Module, mode);\n"
	  "}\n\n",
	  module);
     
  /*
   * _tdrp_check_all_set()
   */

  write_comments_check_all_set(module, cfile);

  fprintf(cfile,
	  "int %s_tdrp_check_all_set(FILE *out)\n"
	  "{\n"
	  "  return (tdrpCheckAllSet(out, Table, Params));\n"
	  "}\n\n",
	  module);

  /*
   * _tdrp_check_is_set()
   */

  write_comments_check_is_set(module, cfile);

  fprintf(cfile,
          "int %s_tdrp_check_is_set(char *param_name)\n"
          "{\n"
          "  return (tdrpCheckIsSet(param_name, Table, Params));\n"
          "}\n\n",
          module);

  /*
   * _tdrp_free_all()
   */

  write_comments_free_all(module, cfile);

  fprintf(cfile,
	  "void %s_tdrp_free_all(void)\n"
	  "{\n"
	  "  tdrpFreeAll(Table, Params);\n"
	  "}\n\n",
	  module);

  /*
   * _tdrp_array_realloc()
   */

  write_comments_array_realloc(module, cfile);

  fprintf(cfile,
	  "int %s_tdrp_array_realloc(char *param_name, int new_array_n)\n"
	  "{\n"
	  "  if (tdrpArrayRealloc(Table, Params, param_name, new_array_n)) {\n"
	  "    return (-1);\n"
	  "  } else {\n"
	  "    return (0);\n"
	  "  }\n"
	  "}\n\n",
	  module);

  /*
   * _tdrp_array2D_realloc()
   */

  write_comments_array2D_realloc(module, cfile);

  fprintf(cfile,
	  "int %s_tdrp_array2D_realloc(char *param_name,\n"
	  "                          int new_array_n1,\n"
	  "                          int new_array_n2)\n"
	  "{\n"
	  "  if (tdrpArray2DRealloc(Table, Params, param_name,\n"
	  "			 new_array_n1, new_array_n2)) {\n"
	  "    return (-1);\n"
	  "  } else {\n"
	  "    return (0);\n"
	  "  }\n"
	  "}\n\n",
	  module);

  /*
   * _tdrp_table()
   */

  write_comments_table(module, cfile);

  fprintf(cfile,
	  "TDRPtable *%s_tdrp_table(void)\n"
	  "{\n"
	  "  return (Table);\n"
	  "}\n\n",
	  module);
  
  /*
   * _tdrp_init()
   */

  write_comments_init(module, cfile);

  fprintf(cfile,
	  "TDRPtable *%s_tdrp_init(%s *params)\n\n",
	  module, struct_name);

  fprintf(cfile,
	  "{\n"
	  "\n"
	  "  TDRPtable *tt = Table;\n"
	  "\n"
	  "  %s pp; /* for computing byte_offsets */\n"
	  "\n"
	  "  /* zero out struct, and store size */\n"
	  "\n"
	  "  memset(params, 0, sizeof(%s));\n"
	  "  params->struct_size = sizeof(%s);\n"
	  "\n",
	  struct_name, struct_name, struct_name);
  
  /*
   * members of main struct
   */

  tt = t_entries;
  for (idef = 0; idef < n_defs; idef++, tt++) {

    fprintf(cfile, "  /* Parameter '%s' */\n", tt->param_name);
    if (tt->ptype != COMMENT_TYPE) {
      fprintf(cfile, "  /* ctype is '%s' */\n",
	      ctype_cname_by_index(tt->ctype));
    }
    fprintf(cfile, "  \n");
    fprintf(cfile, "  memset(tt, 0, sizeof(TDRPtable));\n");
    fprintf(cfile, "  tt->ptype = %s;\n", tdrpTableEntry2Str(tt->ptype));
    fprintf(cfile, "  tt->param_name = tdrpStrDup(\"%s\");\n",
	    tt->param_name);
    
    if (tt->ptype == COMMENT_TYPE) {
      fprintf(cfile, "  tt->comment_hdr = tdrpStrDup(\"%s\");\n",
	      escape_quotes(tt->comment_hdr));
      fprintf(cfile, "  tt->comment_text = tdrpStrDup(\"%s\");\n",
	      escape_quotes(tt->comment_text));
      fprintf(cfile, "  tt++;\n");
      fprintf(cfile, "  \n");
      continue;
    }

    fprintf(cfile, "  tt->descr = tdrpStrDup(\"%s\");\n",
	    escape_quotes(tt->descr));
    fprintf(cfile, "  tt->help = tdrpStrDup(\"%s\");\n",
	    escape_quotes(tt->help));
    
    if (tt->is_array) {

      /*
       * old style array representation
       */
      
      fprintf(cfile,
	      "  tt->val_offset = (char *) &(pp.%s.val) - (char *) &pp;\n",
	      tt->param_name);
      fprintf(cfile,
	      "  tt->len_offset = (char *) &(pp.%s.len) - (char *) &pp;\n",
	      tt->param_name);

      /*
       * new style array representation
       */
      
      fprintf(cfile,
	      "  tt->array_offset = (char *) &(pp._%s) - (char *) &pp;\n",
	      tt->param_name);
      fprintf(cfile,
	      "  tt->array_n_offset = (char *) &(pp.%s_n) - (char *) &pp;\n",
	      tt->param_name);

      if (tt->is_array2D) {
	fprintf(cfile,
		"  tt->array2D_offset = "
		"(char *) &(pp.__%s) - (char *) &pp;\n",
		tt->param_name);
	fprintf(cfile,
		"  tt->array_n1_offset = (char *) &(pp.%s_n1) - "
		"(char *) &pp;\n",
		tt->param_name);
	fprintf(cfile,
		"  tt->array_n2_offset = "
		"(char *) &(pp.%s_n2) - (char *) &pp;\n",
		tt->param_name);
      }

    } else {

      fprintf(cfile,
	      "  tt->val_offset = (char *) &(pp.%s) - (char *) &pp;\n",
	      tt->param_name);

    } /* if (tt->is_array) */

    if (tt->is_private) {
      fprintf(cfile, "  tt->is_private = %s;\n", BOOL_STR(tt->is_private));
    }

    if (tt->ptype == INT_TYPE || tt->ptype == LONG_TYPE ||
	tt->ptype == FLOAT_TYPE || tt->ptype == DOUBLE_TYPE) {
      if (tt->has_min) {
	fprintf(cfile, "  tt->has_min = %s;\n", BOOL_STR(tt->has_min));
      }
      if (tt->has_max) {
	fprintf(cfile, "  tt->has_max = %s;\n", BOOL_STR(tt->has_max));
      }
    }

    if (tt->is_array) {
      fprintf(cfile, "  tt->is_array = %s;\n", BOOL_STR(tt->is_array));
    }
    if (tt->is_array2D) {
      fprintf(cfile, "  tt->is_array2D = %s;\n", BOOL_STR(tt->is_array2D));
    }
    
    if (tt->is_array) { /* if (tt->is_array2D) */
      fprintf(cfile, "  tt->array_len_fixed = %s;\n",
	      BOOL_STR(tt->array_len_fixed));
      fprintf(cfile, "  tt->array_elem_size = sizeof(%s);\n",
	      ctype_cname_by_index(tt->ctype));
      fprintf(cfile, "  tt->array_n = %d;\n", tt->array_n);
    } /* if (tt->is_array2D) */
    
    if (tt->is_array2D) {
      fprintf(cfile, "  tt->array_n1 = %d;\n", tt->array_n1);
      fprintf(cfile, "  tt->array_n2 = %d;\n", tt->array_n2);
    }
    
    /*
     * print out min and max values
     */
    
    if (tt->has_min) {
      fprintf(cfile, "  tt->min_val.%s;\n",
	      print_val(tt->ptype, &tt->enum_def, &tt->min_val));
    }
    if (tt->has_max) {
      fprintf(cfile, "  tt->max_val.%s;\n",
	      print_val(tt->ptype, &tt->enum_def, &tt->max_val));
    }

    /*
     * enum def
     */

    if (tt->ptype == ENUM_TYPE) {

      int i;

      fprintf(cfile, "  tt->enum_def.name = tdrpStrDup(\"%s\");\n",
	      tt->enum_def.name);
      fprintf(cfile, "  tt->enum_def.nfields = %d;\n",
	      tt->enum_def.nfields);
      fprintf(cfile,
	      "  tt->enum_def.fields = (enum_field_t *)\n"
	      "      tdrpMalloc(tt->enum_def.nfields * "
	      "sizeof(enum_field_t));\n");
      
      for (i = 0; i < tt->enum_def.nfields; i++) {
	fprintf(cfile,
		"    tt->enum_def.fields[%d].name = tdrpStrDup(\"%s\");\n",
		i, tt->enum_def.fields[i].name);
	fprintf(cfile,
		"    tt->enum_def.fields[%d].val = %s;\n",
		i, tt->enum_def.fields[i].name);
      } /* i */

    } else if (tt->ptype == STRUCT_TYPE) {

      int i;
      
      fprintf(cfile, "  tt->struct_def.name = tdrpStrDup(\"%s\");\n",
	      tt->struct_def.name);
      fprintf(cfile, "  tt->struct_def.nfields = %d;\n",
	      tt->struct_def.nfields);
      fprintf(cfile,
	      "  tt->struct_def.fields = (struct_field_t *)\n"
	      "      tdrpMalloc(tt->struct_def.nfields * "
	      "sizeof(struct_field_t));\n");

      /*
       * struct fields
       */
      
      for (i = 0; i < tt->struct_def.nfields; i++) {

	fprintf(cfile,
		"    tt->struct_def.fields[%d].ftype = tdrpStrDup(\"%s\");\n",
		i, tt->struct_def.fields[i].ftype);
	fprintf(cfile,
		"    tt->struct_def.fields[%d].fname = tdrpStrDup(\"%s\");\n",
		i, tt->struct_def.fields[i].fname);
	fprintf(cfile,
		"    tt->struct_def.fields[%d].ptype = %s;\n",
		i, tdrpTableEntry2Str(tt->struct_def.fields[i].ptype));
	if (tt->is_array) {
	  fprintf(cfile,
		  "    tt->struct_def.fields[%d].rel_offset = \n"
		  "      (char *) &(pp.%s.val->%s) - (char *) pp.%s.val;\n",
		  i, tt->param_name,
		  tt->struct_def.fields[i].fname, tt->param_name);
	} else {
	  fprintf(cfile,
		  "    tt->struct_def.fields[%d].rel_offset = \n"
		  "      (char *) &(pp.%s.%s) - (char *) &(pp.%s);\n",
		  i, tt->param_name,
		  tt->struct_def.fields[i].fname, tt->param_name);
	}

	/*
	 * extra output for enum-type struct fields
	 */

	if (tt->struct_def.fields[i].ptype == ENUM_TYPE) {

	  int j;

	  fprintf(cfile, "      tt->struct_def.fields[%d].enum_def.name "
		  "= tdrpStrDup(\"%s\");\n", i,
		  tt->struct_def.fields[i].enum_def.name);
	  fprintf(cfile, "      tt->struct_def.fields[%d].enum_def.nfields "
		  "= %d;\n", i,
		  tt->struct_def.fields[i].enum_def.nfields);
	  fprintf(cfile,
		  "      tt->struct_def.fields[%d].enum_def.fields = "
		  "(enum_field_t *) tdrpMalloc\n"
		  "        (tt->struct_def.fields[%d].enum_def.nfields * "
		  "sizeof(enum_field_t));\n", i, i);
	  for (j = 0; j < tt->struct_def.fields[i].enum_def.nfields; j++) {
	    fprintf(cfile,
		    "      tt->struct_def.fields[%d].enum_def.fields[%d].name"
		    " = tdrpStrDup(\"%s\");\n", i, j,
		    tt->struct_def.fields[i].enum_def.fields[j].name);
	    fprintf(cfile,
		    "      tt->struct_def.fields[%d].enum_def.fields[%d].val"
		    " = %s;\n", i, j,
		    tt->struct_def.fields[i].enum_def.fields[j].name);
	  } /* j */
	  
	} /* if (tt->struct_def.fields[i].ptype == ENUM_TYPE) */

      } /* i */

    } /* if (tt->ptype == ENUM_TYPE) */

    /*
     * default values
     */

    if (tt->ptype == STRUCT_TYPE) {

      int j;
      
      fprintf(cfile,
	      "  tt->n_struct_vals = %d;\n", tt->n_struct_vals);
      fprintf(cfile,
	      "  tt->struct_vals = (tdrpVal_t *)\n"
	      "      tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));\n");
      for (j = 0; j < tt->n_struct_vals; j++) {
	int ifield = j % tt->struct_def.nfields;
	fprintf(cfile, "    tt->struct_vals[%d].%s;\n", j,
		print_val(tt->struct_def.fields[ifield].ptype,
			    &tt->struct_def.fields[ifield].enum_def,
			    tt->struct_vals + j));
      }


    } else if (tt->is_array2D) {

      int nvals = tt->array_n1 * tt->array_n2;
      int j;

      fprintf(cfile,
	      "  tt->array_vals = (tdrpVal_t *)\n"
	      "      tdrpMalloc(tt->array_n1 * tt->array_n2 *\n"
	      "        sizeof(tdrpVal_t));\n");
      for (j = 0; j < nvals; j++) {
	fprintf(cfile, "    tt->array_vals[%d].%s;\n", j,
		print_val(tt->ptype, &tt->enum_def, tt->array_vals + j));
      }

    } else if (tt->is_array) {

      int j;

      fprintf(cfile,
	      "  tt->array_vals = (tdrpVal_t *)\n"
	      "      tdrpMalloc(tt->array_n * sizeof(tdrpVal_t));\n");
      for (j = 0; j < tt->array_n; j++) {
	fprintf(cfile, "    tt->array_vals[%d].%s;\n", j,
		print_val(tt->ptype, &tt->enum_def, tt->array_vals + j));
      }

    } else {

      /*
       * print out single values
       */
    
      fprintf(cfile, "  tt->single_val.%s;\n",
	      print_val(tt->ptype, &tt->enum_def, &tt->single_val));

    }
    
    /*
     * increment to next table entry
     */

    fprintf(cfile, "  tt++;\n");
    fprintf(cfile, "  \n");

  } /* idef */

  /*
   * trailing entry has param_name of NULL
   */

  fprintf(cfile, "  /* trailing entry has param_name set to NULL */\n");
  fprintf(cfile, "  \n");
  fprintf(cfile, "  tt->param_name = NULL;\n");
  fprintf(cfile, "  \n");

  /*
   * _tdrp_init() ending
   */

  fprintf(cfile, "  return (Table);\n");
  fprintf(cfile, "\n");
  fprintf(cfile, "}\n");

  /*
   * free up etc.
   */

  free_escaped_str();
  fclose(cfile);
  return (0);

}

/******************************************
 * escape_quotes()
 *
 * Returns a string with the quotes escaped
 */

static char *escape_quotes(const char *str)

{

  const char *ss;
  char *es;

  if (str == NULL) {
    return ("");
  }

  if (EscapedStr == NULL) {
    EscapedStr = (char *) tdrpMalloc(strlen(str) * 2 + 2);
  } else {
    EscapedStr = (char *) tdrpRealloc(EscapedStr, strlen(str) * 2 + 2);
  }

  ss = str;
  es = EscapedStr;

  while (*ss != '\0') {
    if (*ss == '\"') {
      *es = '\\';
      es++;
      *es = '\"';
    } else {
      *es = *ss;
    }
    es++;
    ss++;
  }
  *es = '\0';

  return (EscapedStr);

}

/******************************************
 * free_escaped_str()
 *
 * Frees the memory for the escaped string.
 */

static void free_escaped_str()

{
  tdrpFree(EscapedStr);
  EscapedStr = NULL;
}

/************************************************************
 * print_val
 *
 * sprintfs a value to a string.
 *
 * NOTE: the string is static, so use it before calling this
 * function again.
 */

static char *print_val(int ptype, const enum_def_t *enum_def, const tdrpVal_t *val)
     
{

  static char str[65536];
  int i;
  
  switch (ptype) {
    
  case BOOL_TYPE:
    sprintf(str, "b = %s", tdrpBool2Str(val->b));
    break;
    
  case ENUM_TYPE:
    sprintf(str, "e = UNKNOWN");
    for (i = 0; i < enum_def->nfields; i++) {
      if (val->e == enum_def->fields[i].val) {
	sprintf(str, "e = %s", enum_def->fields[i].name);
	break;
      }
    }
    break;
    
  case STRING_TYPE:
    sprintf(str, "s = tdrpStrDup(\"%s\")", val->s);
    break;
    
  case INT_TYPE:
    if ( val->i == INT_MIN )
      sprintf(str, "i = INT_MIN");
    else if ( val->i == INT_MAX )
      sprintf(str, "i = INT_MAX");
    else
      sprintf(str, "i = %d", val->i);
    break;
    
  case LONG_TYPE:
    if ( val->l == LONG_MIN )
      sprintf(str, "l = LONG_MIN");
    else if ( val->l == LONG_MAX )
      sprintf(str, "l = LONG_MAX");
    else
      sprintf(str, "l = %ld", val->l);
    break;
    
  case FLOAT_TYPE:
    if ( val->f == FLT_MIN )
      sprintf(str, "f = FLT_MIN");
    else if ( val->f == FLT_MAX )
      sprintf(str, "f = FLT_MAX");
    else
      sprintf(str, "f = %g", val->f);
    break;
    
  case DOUBLE_TYPE:
    if ( val->d == DBL_MIN )
      sprintf(str, "d = DBL_MIN");
    else if ( val->d == DBL_MAX )
      sprintf(str, "d = DBL_MAX");
    else
      sprintf(str, "d = %g", val->d);
    break;
    
  default:
    break;
    
  } /* switch */

  return (str);

}  

/*********************************
 * write_comments_load_from_args()
 */

static void write_comments_load_from_args(const char *module, FILE *out)

{

  fprintf(out,
	  "/*************************************************************\n"
	  " * %s_tdrp_load_from_args()\n"
	  " *\n"
	  " * Loads up TDRP using the command line args.\n"
	  " *\n"
	  " * Check TDRP_usage() for command line actions associated with\n"
	  " * this function.\n"
	  " *\n"
	  " *   argc, argv: command line args\n"
	  " *\n"
	  " *   %s_tdrp_struct *params: loads up this struct\n"
	  " * \n"
	  " *   char **override_list: A null-terminated list of overrides\n"
	  " *     to the parameter file.\n"
	  " *     An override string has exactly the format of an entry\n"
	  " *     in the parameter file itself.\n"
	  " *\n"
	  " *   char **params_path_p: if non-NULL, this is set to point to\n"
	  " *                         the path of the params file used.\n"
	  " *\n"
	  " *  Returns 0 on success, -1 on failure.\n"
	  " */\n\n",
	  module, module);

}

/********************************
 * write_comments_load_defaults()
 */

static void write_comments_load_defaults(const char *module, FILE *out)

{

  fprintf(out,
	  "/*************************************************************\n"
	  " * %s_tdrp_load_defaults()\n"
	  " *\n"
	  " * Loads up defaults for a given module.\n"
	  " *\n"
	  " * See %s_tdrp_load() for more details.\n"
	  " *\n"
	  " *  Returns 0 on success, -1 on failure.\n"
	  " */\n\n",
	  module, module);

}

/***********************
 * write_comments_load()
 */

static void write_comments_load(const char *module, FILE *out)

{

  fprintf(out,
	  "/*************************************************************\n"
	  " * %s_tdrp_load()\n"
	  " *\n"
	  " * Loads up TDRP for a given module.\n"
	  " *\n"
	  " * This version of load gives the programmer the option to load\n"
	  " * up more than one module for a single application. It is a\n"
	  " * lower-level routine than %s_tdrp_load_from_args,\n"
	  " * and hence more flexible, but the programmer must do more work.\n"
	  " *\n"
	  " *   char *param_file_path: the parameter file to be read in.\n"
	  " *\n"
	  " *   %s_tdrp_struct *params: loads up this struct\n"
	  " *\n"
	  " *   char **override_list: A null-terminated list of overrides\n"
	  " *     to the parameter file.\n"
	  " *     An override string has exactly the format of an entry\n"
	  " *     in the parameter file itself.\n"
	  " *\n"
	  " *  expand_env: flag to control environment variable\n"
	  " *                expansion during tokenization.\n"
	  " *              If TRUE, environment expansion is set on.\n"
	  " *              If FALSE, environment expansion is set off.\n"
	  " *\n"
	  " *  Returns 0 on success, -1 on failure.\n"
	  " */\n\n",
	  module, module, module);

}

/***********************
 * write_comments_sync()
 */

static void write_comments_sync(const char *module, FILE *out)
     
{
  
  fprintf(out,
	  "/*************************************************************\n"
	  " * %s_tdrp_sync()\n"
	  " *\n"
	  " * Syncs the user struct data back into the parameter table,\n"
	  " * in preparation for printing.\n"
	  " */\n\n",
	  module);

}

/************************
 * write_comments_print()
 */

static void write_comments_print(const char *module, FILE *out)
     
{
  
  fprintf(out,
	  "/*************************************************************\n"
	  " * %s_tdrp_print()\n"
	  " * \n"
	  " * Print params file\n"
	  " *\n"
	  " * The modes supported are:\n"
	  " *\n"
	  " *   PRINT_SHORT:   main comments only, no help or descriptions\n"
	  " *                  structs and arrays on a single line\n"
	  " *   PRINT_NORM:    short + descriptions and help\n"
	  " *   PRINT_LONG:    norm  + arrays and structs expanded\n"
	  " *   PRINT_VERBOSE: long  + private params included\n"
	  " */\n\n",
	  module);

}
     
/********************************
 * write_comments_check_all_set()
 */

static void write_comments_check_all_set(const char *module, FILE *out)
     
{
  
  fprintf(out,
	  "/*************************************************************\n"
	  " * %s_tdrp_check_all_set()\n"
	  " *\n"
	  " * Return TRUE if all set, FALSE if not.\n"
	  " *\n"
	  " * If out is non-NULL, prints out warning messages for those\n"
	  " * parameters which are not set.\n"
	  " */\n\n",
	  module);

}

/********************************
 * write_comments_check_is_set()
 */

static void write_comments_check_is_set(const char *module, FILE *out)

{
 
  fprintf(out,
          "/*************************************************************\n"
          " * %s_tdrp_check_is_set()\n"
          " *\n"
          " * Return TRUE if parameter is set, FALSE if not.\n"
          " *\n"
          " */\n\n",
          module);

}

/***************************
 * write_comments_free_all()
 */

static void write_comments_free_all(const char *module, FILE *out)
     
{
  
  fprintf(out,
	  "/*************************************************************\n"
	  " * %s_tdrp_free_all()\n"
	  " *\n"
	  " * Frees up all TDRP dynamic memory.\n"
	  " */\n\n",
	  module);

}

/********************************
 * write_comments_array_realloc()
 */

static void write_comments_array_realloc(const char *module, FILE *out)
     
{
  
  fprintf(out,
	  "/*************************************************************\n"
	  " * %s_tdrp_array_realloc()\n"
	  " *\n"
	  " * Realloc 1D array.\n"
	  " *\n"
	  " * If size is increased, the values from the last array entry is\n"
	  " * copied into the new space.\n"
	  " *\n"
	  " * Returns 0 on success, -1 on error.\n"
	  " */\n\n",
	  module);

}

/**********************************
 * write_comments_array2D_realloc()
 */

static void write_comments_array2D_realloc(const char *module, FILE *out)
     
{
  
  fprintf(out,
	  "/*************************************************************\n"
	  " * %s_tdrp_array2D_realloc()\n"
	  " *\n"
	  " * Realloc 2D array.\n"
	  " *\n"
	  " * If size is increased, the values from the last array entry is\n"
	  " * copied into the new space.\n"
	  " *\n"
	  " * Returns 0 on success, -1 on error.\n"
	  " */\n\n",
	  module);

}

/************************
 * write_comments_table()
 */

static void write_comments_table(const char *module, FILE *out)
     
{
  
  fprintf(out,
	  "/*************************************************************\n"
	  " * %s_tdrp_table()\n"
	  " *\n"
	  " * Returns pointer to static Table for this module.\n"
	  " */\n"
	  "\n",
	  module);

}


/***********************
 * write_comments_init()
 */

static void write_comments_init(const char *module, FILE *out)
     
{
  
  fprintf(out,
	  "/*************************************************************\n"
	  " * %s_tdrp_init()\n"
	  " *\n"
	  " * Module table initialization function.\n"
	  " *\n"
	  " *\n"
	  " * Returns pointer to static Table for this module.\n"
	  " */\n\n",
	  module);

}