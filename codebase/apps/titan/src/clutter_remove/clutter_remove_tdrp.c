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
/*******************************************
 * clutter_remove_tdrp.c
 *
 * TDRP C code file 'clutter_remove' module.
 *
 * Code for program clutter_remove
 *
 * This file has been automatically
 * generated by TDRP, do not modify.
 *
 *******************************************/

#include "clutter_remove_tdrp.h"
#include <string.h>

/*
 * file scope variables
 */

static TDRPtable Table[15];
static clutter_remove_tdrp_struct *Params;
static char *Module = "clutter_remove";

/*************************************************************
 * clutter_remove_tdrp_load_from_args()
 *
 * Loads up TDRP using the command line args.
 *
 * Check TDRP_usage() for command line actions associated with
 * this function.
 *
 *   argc, argv: command line args
 *
 *   clutter_remove_tdrp_struct *params: loads up this struct
 * 
 *   char **override_list: A null-terminated list of overrides
 *     to the parameter file.
 *     An override string has exactly the format of an entry
 *     in the parameter file itself.
 *
 *   char **params_path_p: if non-NULL, this is set to point to
 *                         the path of the params file used.
 *
 *  Returns 0 on success, -1 on failure.
 */

int clutter_remove_tdrp_load_from_args(int argc, char **argv,
                         clutter_remove_tdrp_struct *params,
                         char **override_list,
                         char **params_path_p)
{
  Params = params;
  clutter_remove_tdrp_init(Params);
  if (tdrpLoadFromArgs(argc, argv,
                       Table, Params,
                       override_list, params_path_p)) {
    return (-1);
  } else {
    return (0);
  }
}

/*************************************************************
 * clutter_remove_tdrp_load()
 *
 * Loads up TDRP for a given module.
 *
 * This version of load gives the programmer the option to load
 * up more than one module for a single application. It is a
 * lower-level routine than clutter_remove_tdrp_load_from_args,
 * and hence more flexible, but the programmer must do more work.
 *
 *   char *param_file_path: the parameter file to be read in.
 *
 *   clutter_remove_tdrp_struct *params: loads up this struct
 *
 *   char **override_list: A null-terminated list of overrides
 *     to the parameter file.
 *     An override string has exactly the format of an entry
 *     in the parameter file itself.
 *
 *  expand_env: flag to control environment variable
 *                expansion during tokenization.
 *              If TRUE, environment expansion is set on.
 *              If FALSE, environment expansion is set off.
 *
 *  Returns 0 on success, -1 on failure.
 */

int clutter_remove_tdrp_load(char *param_file_path,
               clutter_remove_tdrp_struct *params,
               char **override_list,
               int expand_env, int debug)
{
  Params = params;
  clutter_remove_tdrp_init(Params);
  if (tdrpLoad(param_file_path, Table,
               params, override_list,
               expand_env, debug)) {
    return (-1);
  } else {
    return (0);
  }
}

/*************************************************************
 * clutter_remove_tdrp_load_defaults()
 *
 * Loads up defaults for a given module.
 *
 * See clutter_remove_tdrp_load() for more details.
 *
 *  Returns 0 on success, -1 on failure.
 */

int clutter_remove_tdrp_load_defaults(clutter_remove_tdrp_struct *params,
                        int expand_env)
{
  Params = params;
  clutter_remove_tdrp_init(Params);
  if (tdrpLoad(NULL, Table,
               params, NULL,
               expand_env, FALSE)) {
    return (-1);
  } else {
    return (0);
  }
}

/*************************************************************
 * clutter_remove_tdrp_sync()
 *
 * Syncs the user struct data back into the parameter table,
 * in preparation for printing.
 */

void clutter_remove_tdrp_sync(void)
{
  tdrpUser2Table(Table, Params);
}

/*************************************************************
 * clutter_remove_tdrp_print()
 * 
 * Print params file
 *
 * The modes supported are:
 *
 *   PRINT_SHORT:   main comments only, no help or descriptions
 *                  structs and arrays on a single line
 *   PRINT_NORM:    short + descriptions and help
 *   PRINT_LONG:    norm  + arrays and structs expanded
 *   PRINT_VERBOSE: long  + private params included
 */

void clutter_remove_tdrp_print(FILE *out, tdrp_print_mode_t mode)
{
  tdrpPrint(out, Table, Module, mode);
}

/*************************************************************
 * clutter_remove_tdrp_check_all_set()
 *
 * Return TRUE if all set, FALSE if not.
 *
 * If out is non-NULL, prints out warning messages for those
 * parameters which are not set.
 */

int clutter_remove_tdrp_check_all_set(FILE *out)
{
  return (tdrpCheckAllSet(out, Table, Params));
}

/*************************************************************
 * clutter_remove_tdrp_check_is_set()
 *
 * Return TRUE if parameter is set, FALSE if not.
 *
 */

int clutter_remove_tdrp_check_is_set(char *param_name)
{
  return (tdrpCheckIsSet(param_name, Table, Params));
}

/*************************************************************
 * clutter_remove_tdrp_free_all()
 *
 * Frees up all TDRP dynamic memory.
 */

void clutter_remove_tdrp_free_all(void)
{
  tdrpFreeAll(Table, Params);
}

/*************************************************************
 * clutter_remove_tdrp_array_realloc()
 *
 * Realloc 1D array.
 *
 * If size is increased, the values from the last array entry is
 * copied into the new space.
 *
 * Returns 0 on success, -1 on error.
 */

int clutter_remove_tdrp_array_realloc(char *param_name, int new_array_n)
{
  if (tdrpArrayRealloc(Table, Params, param_name, new_array_n)) {
    return (-1);
  } else {
    return (0);
  }
}

/*************************************************************
 * clutter_remove_tdrp_array2D_realloc()
 *
 * Realloc 2D array.
 *
 * If size is increased, the values from the last array entry is
 * copied into the new space.
 *
 * Returns 0 on success, -1 on error.
 */

int clutter_remove_tdrp_array2D_realloc(char *param_name,
                          int new_array_n1,
                          int new_array_n2)
{
  if (tdrpArray2DRealloc(Table, Params, param_name,
			 new_array_n1, new_array_n2)) {
    return (-1);
  } else {
    return (0);
  }
}

/*************************************************************
 * clutter_remove_tdrp_table()
 *
 * Returns pointer to static Table for this module.
 */

TDRPtable *clutter_remove_tdrp_table(void)
{
  return (Table);
}

/*************************************************************
 * clutter_remove_tdrp_init()
 *
 * Module table initialization function.
 *
 *
 * Returns pointer to static Table for this module.
 */

TDRPtable *clutter_remove_tdrp_init(clutter_remove_tdrp_struct *params)

{

  TDRPtable *tt = Table;

  clutter_remove_tdrp_struct pp; /* for computing byte_offsets */

  /* zero out struct, and store size */

  memset(params, 0, sizeof(clutter_remove_tdrp_struct));
  params->struct_size = sizeof(clutter_remove_tdrp_struct);

  /* Parameter 'debug' */
  /* ctype is 'clutter_remove_debug_t' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = ENUM_TYPE;
  tt->param_name = tdrpStrDup("debug");
  tt->descr = tdrpStrDup("Debug option");
  tt->help = tdrpStrDup("If set, debug messages will be printed appropriately");
  tt->val_offset = (char *) &(pp.debug) - (char *) &pp;
  tt->enum_def.name = tdrpStrDup("debug_t");
  tt->enum_def.nfields = 4;
  tt->enum_def.fields = (enum_field_t *)
      tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
    tt->enum_def.fields[0].name = tdrpStrDup("DEBUG_OFF");
    tt->enum_def.fields[0].val = DEBUG_OFF;
    tt->enum_def.fields[1].name = tdrpStrDup("DEBUG_WARNINGS");
    tt->enum_def.fields[1].val = DEBUG_WARNINGS;
    tt->enum_def.fields[2].name = tdrpStrDup("DEBUG_NORM");
    tt->enum_def.fields[2].val = DEBUG_NORM;
    tt->enum_def.fields[3].name = tdrpStrDup("DEBUG_EXTRA");
    tt->enum_def.fields[3].val = DEBUG_EXTRA;
  tt->single_val.e = DEBUG_OFF;
  tt++;
  
  /* Parameter 'malloc_debug_level' */
  /* ctype is 'long' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = LONG_TYPE;
  tt->param_name = tdrpStrDup("malloc_debug_level");
  tt->descr = tdrpStrDup("Malloc debug level");
  tt->help = tdrpStrDup("0 - none, 1 - corruption checking, 2 - records all malloc blocks and checks, 3 - printout of all mallocs etc.");
  tt->val_offset = (char *) &(pp.malloc_debug_level) - (char *) &pp;
  tt->has_min = TRUE;
  tt->has_max = TRUE;
  tt->min_val.l = 0;
  tt->max_val.l = 3;
  tt->single_val.l = 0;
  tt++;
  
  /* Parameter 'instance' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("instance");
  tt->descr = tdrpStrDup("Process instance");
  tt->help = tdrpStrDup("Used for registration with procmap.");
  tt->val_offset = (char *) &(pp.instance) - (char *) &pp;
  tt->single_val.s = tdrpStrDup("Test");
  tt++;
  
  /* Parameter 'mode' */
  /* ctype is 'clutter_remove_mode_t' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = ENUM_TYPE;
  tt->param_name = tdrpStrDup("mode");
  tt->descr = tdrpStrDup("Operational mode");
  tt->help = tdrpStrDup("Realtime mode - waits for new data; archive mode runs on file list");
  tt->val_offset = (char *) &(pp.mode) - (char *) &pp;
  tt->enum_def.name = tdrpStrDup("mode_t");
  tt->enum_def.nfields = 2;
  tt->enum_def.fields = (enum_field_t *)
      tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
    tt->enum_def.fields[0].name = tdrpStrDup("REALTIME");
    tt->enum_def.fields[0].val = REALTIME;
    tt->enum_def.fields[1].name = tdrpStrDup("ARCHIVE");
    tt->enum_def.fields[1].val = ARCHIVE;
  tt->single_val.e = REALTIME;
  tt++;
  
  /* Parameter 'input_dir' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("input_dir");
  tt->descr = tdrpStrDup("Input directory");
  tt->help = tdrpStrDup("Path of input directory - realtime mode only");
  tt->val_offset = (char *) &(pp.input_dir) - (char *) &pp;
  tt->single_val.s = tdrpStrDup("null");
  tt++;
  
  /* Parameter 'output_file_ext' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("output_file_ext");
  tt->descr = tdrpStrDup("Output file extension");
  tt->help = tdrpStrDup("");
  tt->val_offset = (char *) &(pp.output_file_ext) - (char *) &pp;
  tt->single_val.s = tdrpStrDup("mdv");
  tt++;
  
  /* Parameter 'output_dir' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("output_dir");
  tt->descr = tdrpStrDup("Output directory");
  tt->help = tdrpStrDup("Path of output directory");
  tt->val_offset = (char *) &(pp.output_dir) - (char *) &pp;
  tt->single_val.s = tdrpStrDup("null");
  tt++;
  
  /* Parameter 'max_input_data_age' */
  /* ctype is 'long' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = LONG_TYPE;
  tt->param_name = tdrpStrDup("max_input_data_age");
  tt->descr = tdrpStrDup("Max age of input data");
  tt->help = tdrpStrDup("For realtime only - max age of input data for it to be valid");
  tt->val_offset = (char *) &(pp.max_input_data_age) - (char *) &pp;
  tt->has_min = TRUE;
  tt->min_val.l = 60;
  tt->single_val.l = 300;
  tt++;
  
  /* Parameter 'use_clutter_table' */
  /* ctype is 'tdrp_bool_t' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = BOOL_TYPE;
  tt->param_name = tdrpStrDup("use_clutter_table");
  tt->descr = tdrpStrDup("Flag to use clutter table. If FALSE, use clutter volume");
  tt->help = tdrpStrDup("");
  tt->val_offset = (char *) &(pp.use_clutter_table) - (char *) &pp;
  tt->single_val.b = pTRUE;
  tt++;
  
  /* Parameter 'clutter_table_file_path' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("clutter_table_file_path");
  tt->descr = tdrpStrDup("Clutter table file path");
  tt->help = tdrpStrDup("");
  tt->val_offset = (char *) &(pp.clutter_table_file_path) - (char *) &pp;
  tt->single_val.s = tdrpStrDup("none");
  tt++;
  
  /* Parameter 'clutter_volume_file_path' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("clutter_volume_file_path");
  tt->descr = tdrpStrDup("Cluter volume file path");
  tt->help = tdrpStrDup("");
  tt->val_offset = (char *) &(pp.clutter_volume_file_path) - (char *) &pp;
  tt->single_val.s = tdrpStrDup("none");
  tt++;
  
  /* Parameter 'dbz_field' */
  /* ctype is 'long' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = LONG_TYPE;
  tt->param_name = tdrpStrDup("dbz_field");
  tt->descr = tdrpStrDup("Dbz field");
  tt->help = tdrpStrDup("The field number of the dbz data in the file");
  tt->val_offset = (char *) &(pp.dbz_field) - (char *) &pp;
  tt->has_min = TRUE;
  tt->min_val.l = 0;
  tt->single_val.l = 0;
  tt++;
  
  /* Parameter 'dbz_threshold' */
  /* ctype is 'double' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = DOUBLE_TYPE;
  tt->param_name = tdrpStrDup("dbz_threshold");
  tt->descr = tdrpStrDup("Clutter dBZ threshold");
  tt->help = tdrpStrDup("Data is only considered a candidate for clutter if it exceeds this threshold. This is only needed if no clutter table is available");
  tt->val_offset = (char *) &(pp.dbz_threshold) - (char *) &pp;
  tt->has_min = TRUE;
  tt->has_max = TRUE;
  tt->min_val.d = -40;
  tt->max_val.d = 80;
  tt->single_val.d = 0;
  tt++;
  
  /* Parameter 'dbz_margin' */
  /* ctype is 'double' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = DOUBLE_TYPE;
  tt->param_name = tdrpStrDup("dbz_margin");
  tt->descr = tdrpStrDup("Clutter dBZ margin");
  tt->help = tdrpStrDup("Data which exceeds the clutter value by this margin is not condidered clutter. This is only needed if no clutter table is available");
  tt->val_offset = (char *) &(pp.dbz_margin) - (char *) &pp;
  tt->has_min = TRUE;
  tt->has_max = TRUE;
  tt->min_val.d = -20;
  tt->max_val.d = 20;
  tt->single_val.d = 0;
  tt++;
  
  /* trailing entry has param_name set to NULL */
  
  tt->param_name = NULL;
  
  return (Table);

}