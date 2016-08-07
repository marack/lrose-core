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
 * cindex_test_tdrp.c
 *
 * TDRP C code file 'cindex_test' module.
 *
 * Code for program cindex_test
 *
 * This file has been automatically
 * generated by TDRP, do not modify.
 *
 *******************************************/

#include "cindex_test_tdrp.h"
#include <string.h>

/*
 * file scope variables
 */

static TDRPtable Table[10];
static cindex_test_tdrp_struct *Params;
static char *Module = "cindex_test";

/*************************************************************
 * cindex_test_tdrp_load_from_args()
 *
 * Loads up TDRP using the command line args.
 *
 * Check TDRP_usage() for command line actions associated with
 * this function.
 *
 *   argc, argv: command line args
 *
 *   cindex_test_tdrp_struct *params: loads up this struct
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

int cindex_test_tdrp_load_from_args(int argc, char **argv,
                         cindex_test_tdrp_struct *params,
                         char **override_list,
                         char **params_path_p)
{
  Params = params;
  cindex_test_tdrp_init(Params);
  if (tdrpLoadFromArgs(argc, argv,
                       Table, Params,
                       override_list, params_path_p)) {
    return (-1);
  } else {
    return (0);
  }
}

/*************************************************************
 * cindex_test_tdrp_load()
 *
 * Loads up TDRP for a given module.
 *
 * This version of load gives the programmer the option to load
 * up more than one module for a single application. It is a
 * lower-level routine than cindex_test_tdrp_load_from_args,
 * and hence more flexible, but the programmer must do more work.
 *
 *   char *param_file_path: the parameter file to be read in.
 *
 *   cindex_test_tdrp_struct *params: loads up this struct
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

int cindex_test_tdrp_load(char *param_file_path,
               cindex_test_tdrp_struct *params,
               char **override_list,
               int expand_env, int debug)
{
  Params = params;
  cindex_test_tdrp_init(Params);
  if (tdrpLoad(param_file_path, Table,
               params, override_list,
               expand_env, debug)) {
    return (-1);
  } else {
    return (0);
  }
}

/*************************************************************
 * cindex_test_tdrp_load_defaults()
 *
 * Loads up defaults for a given module.
 *
 * See cindex_test_tdrp_load() for more details.
 *
 *  Returns 0 on success, -1 on failure.
 */

int cindex_test_tdrp_load_defaults(cindex_test_tdrp_struct *params,
                        int expand_env)
{
  Params = params;
  cindex_test_tdrp_init(Params);
  if (tdrpLoad(NULL, Table,
               params, NULL,
               expand_env, FALSE)) {
    return (-1);
  } else {
    return (0);
  }
}

/*************************************************************
 * cindex_test_tdrp_sync()
 *
 * Syncs the user struct data back into the parameter table,
 * in preparation for printing.
 */

void cindex_test_tdrp_sync(void)
{
  tdrpUser2Table(Table, Params);
}

/*************************************************************
 * cindex_test_tdrp_print()
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

void cindex_test_tdrp_print(FILE *out, tdrp_print_mode_t mode)
{
  tdrpPrint(out, Table, Module, mode);
}

/*************************************************************
 * cindex_test_tdrp_check_all_set()
 *
 * Return TRUE if all set, FALSE if not.
 *
 * If out is non-NULL, prints out warning messages for those
 * parameters which are not set.
 */

int cindex_test_tdrp_check_all_set(FILE *out)
{
  return (tdrpCheckAllSet(out, Table, Params));
}

/*************************************************************
 * cindex_test_tdrp_check_is_set()
 *
 * Return TRUE if parameter is set, FALSE if not.
 *
 */

int cindex_test_tdrp_check_is_set(char *param_name)
{
  return (tdrpCheckIsSet(param_name, Table, Params));
}

/*************************************************************
 * cindex_test_tdrp_free_all()
 *
 * Frees up all TDRP dynamic memory.
 */

void cindex_test_tdrp_free_all(void)
{
  tdrpFreeAll(Table, Params);
}

/*************************************************************
 * cindex_test_tdrp_array_realloc()
 *
 * Realloc 1D array.
 *
 * If size is increased, the values from the last array entry is
 * copied into the new space.
 *
 * Returns 0 on success, -1 on error.
 */

int cindex_test_tdrp_array_realloc(char *param_name, int new_array_n)
{
  if (tdrpArrayRealloc(Table, Params, param_name, new_array_n)) {
    return (-1);
  } else {
    return (0);
  }
}

/*************************************************************
 * cindex_test_tdrp_array2D_realloc()
 *
 * Realloc 2D array.
 *
 * If size is increased, the values from the last array entry is
 * copied into the new space.
 *
 * Returns 0 on success, -1 on error.
 */

int cindex_test_tdrp_array2D_realloc(char *param_name,
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
 * cindex_test_tdrp_table()
 *
 * Returns pointer to static Table for this module.
 */

TDRPtable *cindex_test_tdrp_table(void)
{
  return (Table);
}

/*************************************************************
 * cindex_test_tdrp_init()
 *
 * Module table initialization function.
 *
 *
 * Returns pointer to static Table for this module.
 */

TDRPtable *cindex_test_tdrp_init(cindex_test_tdrp_struct *params)

{

  TDRPtable *tt = Table;

  cindex_test_tdrp_struct pp; /* for computing byte_offsets */

  /* zero out struct, and store size */

  memset(params, 0, sizeof(cindex_test_tdrp_struct));
  params->struct_size = sizeof(cindex_test_tdrp_struct);

  /* Parameter 'debug' */
  /* ctype is 'cindex_test_debug' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = ENUM_TYPE;
  tt->param_name = tdrpStrDup("debug");
  tt->descr = tdrpStrDup("Debug option");
  tt->help = tdrpStrDup("If set, debug messages will be printed appropriately.");
  tt->val_offset = (char *) &(pp.debug) - (char *) &pp;
  tt->enum_def.name = tdrpStrDup("debug");
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
  tt->help = tdrpStrDup("The instance of this process, used for reistration with procmap.");
  tt->val_offset = (char *) &(pp.instance) - (char *) &pp;
  tt->single_val.s = tdrpStrDup("Test");
  tt++;
  
  /* Parameter 'mode' */
  /* ctype is 'cindex_test_mode' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = ENUM_TYPE;
  tt->param_name = tdrpStrDup("mode");
  tt->descr = tdrpStrDup("Operating mode");
  tt->help = tdrpStrDup("If REALTIME, index time is based on current time. If ARCHIVE, index time starts at the given start_time, and increments from there.");
  tt->val_offset = (char *) &(pp.mode) - (char *) &pp;
  tt->enum_def.name = tdrpStrDup("mode");
  tt->enum_def.nfields = 2;
  tt->enum_def.fields = (enum_field_t *)
      tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
    tt->enum_def.fields[0].name = tdrpStrDup("REALTIME");
    tt->enum_def.fields[0].val = REALTIME;
    tt->enum_def.fields[1].name = tdrpStrDup("ARCHIVE");
    tt->enum_def.fields[1].val = ARCHIVE;
  tt->single_val.e = REALTIME;
  tt++;
  
  /* Parameter 'update_interval' */
  /* ctype is 'long' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = LONG_TYPE;
  tt->param_name = tdrpStrDup("update_interval");
  tt->descr = tdrpStrDup("Update interval (secs).");
  tt->help = tdrpStrDup("");
  tt->val_offset = (char *) &(pp.update_interval) - (char *) &pp;
  tt->has_min = TRUE;
  tt->min_val.l = 1;
  tt->single_val.l = 60;
  tt++;
  
  /* Parameter 'data_dir' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("data_dir");
  tt->descr = tdrpStrDup("Data directory");
  tt->help = tdrpStrDup("Directory to which index file will be written.");
  tt->val_offset = (char *) &(pp.data_dir) - (char *) &pp;
  tt->single_val.s = tdrpStrDup("null");
  tt++;
  
  /* Parameter 'file_extension' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("file_extension");
  tt->descr = tdrpStrDup("Extension for data files");
  tt->help = tdrpStrDup("In this test there are no data files, but we need the extension for filling the index.");
  tt->val_offset = (char *) &(pp.file_extension) - (char *) &pp;
  tt->single_val.s = tdrpStrDup("test");
  tt++;
  
  /* Parameter 'start_time' */
  /* ctype is 'cindex_test_grid' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRUCT_TYPE;
  tt->param_name = tdrpStrDup("start_time");
  tt->descr = tdrpStrDup("Start time");
  tt->help = tdrpStrDup("In ARCHIVE mode the time starts at this time and increments.");
  tt->val_offset = (char *) &(pp.start_time) - (char *) &pp;
  tt->struct_def.name = tdrpStrDup("grid");
  tt->struct_def.nfields = 6;
  tt->struct_def.fields = (struct_field_t *)
      tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
    tt->struct_def.fields[0].ftype = tdrpStrDup("long");
    tt->struct_def.fields[0].fname = tdrpStrDup("year");
    tt->struct_def.fields[0].ptype = LONG_TYPE;
    tt->struct_def.fields[0].rel_offset = 
      (char *) &(pp.start_time.year) - (char *) &(pp.start_time);
    tt->struct_def.fields[1].ftype = tdrpStrDup("long");
    tt->struct_def.fields[1].fname = tdrpStrDup("month");
    tt->struct_def.fields[1].ptype = LONG_TYPE;
    tt->struct_def.fields[1].rel_offset = 
      (char *) &(pp.start_time.month) - (char *) &(pp.start_time);
    tt->struct_def.fields[2].ftype = tdrpStrDup("long");
    tt->struct_def.fields[2].fname = tdrpStrDup("day");
    tt->struct_def.fields[2].ptype = LONG_TYPE;
    tt->struct_def.fields[2].rel_offset = 
      (char *) &(pp.start_time.day) - (char *) &(pp.start_time);
    tt->struct_def.fields[3].ftype = tdrpStrDup("long");
    tt->struct_def.fields[3].fname = tdrpStrDup("hour");
    tt->struct_def.fields[3].ptype = LONG_TYPE;
    tt->struct_def.fields[3].rel_offset = 
      (char *) &(pp.start_time.hour) - (char *) &(pp.start_time);
    tt->struct_def.fields[4].ftype = tdrpStrDup("long");
    tt->struct_def.fields[4].fname = tdrpStrDup("min");
    tt->struct_def.fields[4].ptype = LONG_TYPE;
    tt->struct_def.fields[4].rel_offset = 
      (char *) &(pp.start_time.min) - (char *) &(pp.start_time);
    tt->struct_def.fields[5].ftype = tdrpStrDup("long");
    tt->struct_def.fields[5].fname = tdrpStrDup("sec");
    tt->struct_def.fields[5].ptype = LONG_TYPE;
    tt->struct_def.fields[5].rel_offset = 
      (char *) &(pp.start_time.sec) - (char *) &(pp.start_time);
  tt->n_struct_vals = 6;
  tt->struct_vals = (tdrpVal_t *)
      tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
    tt->struct_vals[0].l = 0;
    tt->struct_vals[1].l = 0;
    tt->struct_vals[2].l = 0;
    tt->struct_vals[3].l = 0;
    tt->struct_vals[4].l = 0;
    tt->struct_vals[5].l = 0;
  tt++;
  
  /* Parameter 'num_times' */
  /* ctype is 'long' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = LONG_TYPE;
  tt->param_name = tdrpStrDup("num_times");
  tt->descr = tdrpStrDup("Number of times to write index file.");
  tt->help = tdrpStrDup("Set to -1 to write files forever.");
  tt->val_offset = (char *) &(pp.num_times) - (char *) &pp;
  tt->single_val.l = -1;
  tt++;
  
  /* trailing entry has param_name set to NULL */
  
  tt->param_name = NULL;
  
  return (Table);

}