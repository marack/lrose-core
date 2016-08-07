/*******************************************
 * chunk_spdb2symprod_tdrp.c
 *
 * TDRP C code file 'chunk_spdb2symprod' module.
 *
 * Code for program chunk_spdb2symprod
 *
 * This file has been automatically
 * generated by TDRP, do not modify.
 *
 *******************************************/

#include "chunk_spdb2symprod_tdrp.h"
#include <string.h>

/*
 * file scope variables
 */

static TDRPtable Table[15];
static chunk_spdb2symprod_tdrp_struct *Params;
static char *Module = "chunk_spdb2symprod";

/*************************************************************
 * chunk_spdb2symprod_tdrp_load_from_args()
 *
 * Loads up TDRP using the command line args.
 *
 * Check TDRP_usage() for command line actions associated with
 * this function.
 *
 *   argc, argv: command line args
 *
 *   chunk_spdb2symprod_tdrp_struct *params: loads up this struct
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

int chunk_spdb2symprod_tdrp_load_from_args(int argc, char **argv,
                         chunk_spdb2symprod_tdrp_struct *params,
                         char **override_list,
                         char **params_path_p)
{
  Params = params;
  chunk_spdb2symprod_tdrp_init(Params);
  if (tdrpLoadFromArgs(argc, argv,
                       Table, Params,
                       override_list, params_path_p)) {
    return (-1);
  } else {
    return (0);
  }
}

/*************************************************************
 * chunk_spdb2symprod_tdrp_load()
 *
 * Loads up TDRP for a given module.
 *
 * This version of load gives the programmer the option to load
 * up more than one module for a single application. It is a
 * lower-level routine than chunk_spdb2symprod_tdrp_load_from_args,
 * and hence more flexible, but the programmer must do more work.
 *
 *   char *param_file_path: the parameter file to be read in.
 *
 *   chunk_spdb2symprod_tdrp_struct *params: loads up this struct
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

int chunk_spdb2symprod_tdrp_load(char *param_file_path,
               chunk_spdb2symprod_tdrp_struct *params,
               char **override_list,
               int expand_env, int debug)
{
  Params = params;
  chunk_spdb2symprod_tdrp_init(Params);
  if (tdrpLoad(param_file_path, Table,
               params, override_list,
               expand_env, debug)) {
    return (-1);
  } else {
    return (0);
  }
}

/*************************************************************
 * chunk_spdb2symprod_tdrp_load_defaults()
 *
 * Loads up defaults for a given module.
 *
 * See chunk_spdb2symprod_tdrp_load() for more details.
 *
 *  Returns 0 on success, -1 on failure.
 */

int chunk_spdb2symprod_tdrp_load_defaults(chunk_spdb2symprod_tdrp_struct *params,
                        int expand_env)
{
  Params = params;
  chunk_spdb2symprod_tdrp_init(Params);
  if (tdrpLoad(NULL, Table,
               params, NULL,
               expand_env, FALSE)) {
    return (-1);
  } else {
    return (0);
  }
}

/*************************************************************
 * chunk_spdb2symprod_tdrp_sync()
 *
 * Syncs the user struct data back into the parameter table,
 * in preparation for printing.
 */

void chunk_spdb2symprod_tdrp_sync(void)
{
  tdrpUser2Table(Table, Params);
}

/*************************************************************
 * chunk_spdb2symprod_tdrp_print()
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

void chunk_spdb2symprod_tdrp_print(FILE *out, tdrp_print_mode_t mode)
{
  tdrpPrint(out, Table, Module, mode);
}

/*************************************************************
 * chunk_spdb2symprod_tdrp_check_all_set()
 *
 * Return TRUE if all set, FALSE if not.
 *
 * If out is non-NULL, prints out warning messages for those
 * parameters which are not set.
 */

int chunk_spdb2symprod_tdrp_check_all_set(FILE *out)
{
  return (tdrpCheckAllSet(out, Table, Params));
}

/*************************************************************
 * chunk_spdb2symprod_tdrp_check_is_set()
 *
 * Return TRUE if parameter is set, FALSE if not.
 *
 */

int chunk_spdb2symprod_tdrp_check_is_set(char *param_name)
{
  return (tdrpCheckIsSet(param_name, Table, Params));
}

/*************************************************************
 * chunk_spdb2symprod_tdrp_free_all()
 *
 * Frees up all TDRP dynamic memory.
 */

void chunk_spdb2symprod_tdrp_free_all(void)
{
  tdrpFreeAll(Table, Params);
}

/*************************************************************
 * chunk_spdb2symprod_tdrp_array_realloc()
 *
 * Realloc 1D array.
 *
 * If size is increased, the values from the last array entry is
 * copied into the new space.
 *
 * Returns 0 on success, -1 on error.
 */

int chunk_spdb2symprod_tdrp_array_realloc(char *param_name, int new_array_n)
{
  if (tdrpArrayRealloc(Table, Params, param_name, new_array_n)) {
    return (-1);
  } else {
    return (0);
  }
}

/*************************************************************
 * chunk_spdb2symprod_tdrp_array2D_realloc()
 *
 * Realloc 2D array.
 *
 * If size is increased, the values from the last array entry is
 * copied into the new space.
 *
 * Returns 0 on success, -1 on error.
 */

int chunk_spdb2symprod_tdrp_array2D_realloc(char *param_name,
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
 * chunk_spdb2symprod_tdrp_table()
 *
 * Returns pointer to static Table for this module.
 */

TDRPtable *chunk_spdb2symprod_tdrp_table(void)
{
  return (Table);
}

/*************************************************************
 * chunk_spdb2symprod_tdrp_init()
 *
 * Module table initialization function.
 *
 *
 * Returns pointer to static Table for this module.
 */

TDRPtable *chunk_spdb2symprod_tdrp_init(chunk_spdb2symprod_tdrp_struct *params)

{

  TDRPtable *tt = Table;

  chunk_spdb2symprod_tdrp_struct pp; /* for computing byte_offsets */

  /* zero out struct, and store size */

  memset(params, 0, sizeof(chunk_spdb2symprod_tdrp_struct));
  params->struct_size = sizeof(chunk_spdb2symprod_tdrp_struct);

  /* Parameter 'debug' */
  /* ctype is 'chunk_spdb2symprod_debug_t' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = ENUM_TYPE;
  tt->param_name = tdrpStrDup("debug");
  tt->descr = tdrpStrDup("debug level");
  tt->help = tdrpStrDup("Level of debug messages to print.");
  tt->val_offset = (char *) &(pp.debug) - (char *) &pp;
  tt->enum_def.name = tdrpStrDup("debug_t");
  tt->enum_def.nfields = 5;
  tt->enum_def.fields = (enum_field_t *)
      tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
    tt->enum_def.fields[0].name = tdrpStrDup("DEBUG_OFF");
    tt->enum_def.fields[0].val = DEBUG_OFF;
    tt->enum_def.fields[1].name = tdrpStrDup("DEBUG_ERRORS");
    tt->enum_def.fields[1].val = DEBUG_ERRORS;
    tt->enum_def.fields[2].name = tdrpStrDup("DEBUG_MSGS");
    tt->enum_def.fields[2].val = DEBUG_MSGS;
    tt->enum_def.fields[3].name = tdrpStrDup("DEBUG_ROUTINES");
    tt->enum_def.fields[3].val = DEBUG_ROUTINES;
    tt->enum_def.fields[4].name = tdrpStrDup("DEBUG_ALL");
    tt->enum_def.fields[4].val = DEBUG_ALL;
  tt->single_val.e = DEBUG_OFF;
  tt++;
  
  /* Parameter 'malloc_debug_level' */
  /* ctype is 'long' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = LONG_TYPE;
  tt->param_name = tdrpStrDup("malloc_debug_level");
  tt->descr = tdrpStrDup("malloc debug level");
  tt->help = tdrpStrDup("0 = none, 1 = corruption checking, 2 = record all malloc blocks and checks, 3 = printout of all mallocs, etc.");
  tt->val_offset = (char *) &(pp.malloc_debug_level) - (char *) &pp;
  tt->has_min = TRUE;
  tt->has_max = TRUE;
  tt->min_val.l = 0;
  tt->max_val.l = 3;
  tt->single_val.l = 0;
  tt++;
  
  /* Parameter 'wait_msecs' */
  /* ctype is 'long' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = LONG_TYPE;
  tt->param_name = tdrpStrDup("wait_msecs");
  tt->descr = tdrpStrDup("wait msecs");
  tt->help = tdrpStrDup("Number of milliseconds to wait before timing out socket operations.");
  tt->val_offset = (char *) &(pp.wait_msecs) - (char *) &pp;
  tt->single_val.l = 100;
  tt++;
  
  /* Parameter 'database_dir' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("database_dir");
  tt->descr = tdrpStrDup("database directory");
  tt->help = tdrpStrDup("Directory containing SPDB database.");
  tt->val_offset = (char *) &(pp.database_dir) - (char *) &pp;
  tt->single_val.s = tdrpStrDup(".");
  tt++;
  
  /* Parameter 'product_label' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("product_label");
  tt->descr = tdrpStrDup("product label");
  tt->help = tdrpStrDup("The product label used in the SPDB database to uniquely identify this product.");
  tt->val_offset = (char *) &(pp.product_label) - (char *) &pp;
  tt->single_val.s = tdrpStrDup("Chunk Data");
  tt++;
  
  /* Parameter 'product_id' */
  /* ctype is 'long' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = LONG_TYPE;
  tt->param_name = tdrpStrDup("product_id");
  tt->descr = tdrpStrDup("product id");
  tt->help = tdrpStrDup("Number which uniquely identifies this product in the SPDB database.");
  tt->val_offset = (char *) &(pp.product_id) - (char *) &pp;
  tt->single_val.l = 999;
  tt++;
  
  /* Parameter 'port' */
  /* ctype is 'long' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = LONG_TYPE;
  tt->param_name = tdrpStrDup("port");
  tt->descr = tdrpStrDup("port");
  tt->help = tdrpStrDup("Port number.");
  tt->val_offset = (char *) &(pp.port) - (char *) &pp;
  tt->single_val.l = 62000;
  tt++;
  
  /* Parameter 'servmap_type' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("servmap_type");
  tt->descr = tdrpStrDup("servmap type");
  tt->help = tdrpStrDup("Server mapper type for this server.");
  tt->val_offset = (char *) &(pp.servmap_type) - (char *) &pp;
  tt->single_val.s = tdrpStrDup("Spdb");
  tt++;
  
  /* Parameter 'servmap_subtype' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("servmap_subtype");
  tt->descr = tdrpStrDup("servmap subtype");
  tt->help = tdrpStrDup("Server mapper subtype for this server.  The type is always Spdb.");
  tt->val_offset = (char *) &(pp.servmap_subtype) - (char *) &pp;
  tt->single_val.s = tdrpStrDup("Symprod");
  tt++;
  
  /* Parameter 'servmap_instance' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("servmap_instance");
  tt->descr = tdrpStrDup("servmap instance");
  tt->help = tdrpStrDup("Server mapper instance for this server.  The type is always Spdb.");
  tt->val_offset = (char *) &(pp.servmap_instance) - (char *) &pp;
  tt->single_val.s = tdrpStrDup("Test");
  tt++;
  
  /* Parameter 'realtime_avail' */
  /* ctype is 'tdrp_bool_t' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = BOOL_TYPE;
  tt->param_name = tdrpStrDup("realtime_avail");
  tt->descr = tdrpStrDup("realtime available flag");
  tt->help = tdrpStrDup("Flag indicating if realtime data is available from this server.");
  tt->val_offset = (char *) &(pp.realtime_avail) - (char *) &pp;
  tt->single_val.b = pTRUE;
  tt++;
  
  /* Parameter 'latest_data_only_for_type' */
  /* ctype is 'tdrp_bool_t' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = BOOL_TYPE;
  tt->param_name = tdrpStrDup("latest_data_only_for_type");
  tt->descr = tdrpStrDup("latest data for data type flag");
  tt->help = tdrpStrDup("If TRUE, only the latest data for any data type will be returned by the server.");
  tt->val_offset = (char *) &(pp.latest_data_only_for_type) - (char *) &pp;
  tt->single_val.b = pFALSE;
  tt++;
  
  /* Parameter 'chunk_type' */
  /* ctype is 'long' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = LONG_TYPE;
  tt->param_name = tdrpStrDup("chunk_type");
  tt->descr = tdrpStrDup("chunk type");
  tt->help = tdrpStrDup("Value to be put in the chunk_type field of the chunk object to tell the display what type of chunk this is for rendering.");
  tt->val_offset = (char *) &(pp.chunk_type) - (char *) &pp;
  tt->single_val.l = 0;
  tt++;
  
  /* Parameter 'color' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("color");
  tt->descr = tdrpStrDup("object color");
  tt->help = tdrpStrDup("Name of color suggested for rendering the object.");
  tt->val_offset = (char *) &(pp.color) - (char *) &pp;
  tt->single_val.s = tdrpStrDup("green");
  tt++;
  
  /* trailing entry has param_name set to NULL */
  
  tt->param_name = NULL;
  
  return (Table);

}